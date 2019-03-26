#include <QCoreApplication>
#include <iostream>
#include <QTime>
#include <QSharedMemory>

#if defined(_WIN32)
    #include <windows.h>
    //隐藏DOS黑窗口
    #pragma comment(linker,"/subsystem:\"windows\"  /entry:\"mainCRTStartup\"" )
    //定义路径最大程度
    #define MAX_PATH_NUM 4096
    //定义守护进程名称
    #define PROCCESS_NAME "MyDaemonProgram.exe"
    //定义写入的注册表路径
    #define SELFSTART_REGEDIT_PATH "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\"
    //设置本身开机自启动
    BOOL SetSelfStart()
    {
        //获取程序完整名称
        char pName[MAX_PATH_NUM] = { 0 };
        GetModuleFileNameA(NULL, pName, MAX_PATH_NUM);

        //在注册表中写入启动信息
        HKEY hKey = NULL;
        LONG lRet = 0;
        lRet = RegOpenKeyExA(HKEY_CURRENT_USER, SELFSTART_REGEDIT_PATH, 0, KEY_ALL_ACCESS, &hKey);

        //判断是否成功
        if (lRet != ERROR_SUCCESS)
        {
            return FALSE;
        }
        //MyDaemonProgram表示本程序名称
        lRet = RegSetValueExA(hKey, "MyDaemonProgram", 0, REG_SZ, (const unsigned char*)pName, strlen(pName) + sizeof(char));

        //判断是否成功
        if (lRet != ERROR_SUCCESS)
        {
            return FALSE;
        }

        //关闭注册表
        RegCloseKey(hKey);
        return TRUE;
    }
#else  //linux
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <sys/wait.h>
    /*linux中文件描述符的最大值是16位表示的65535*/
    #define MAXFILE 65535
    void SetDaemon()
    {
        pid_t pid;
            int i,fd,len;
            char *buf = "This is daemon log!\n";

            len = strlen(buf);
            if( (pid=fork()) < 0 )
            {
                perror("Fork");
                exit(1);
            }
        /*将父进程结束，实现终端脱离第一步*/
            else if( pid > 0 )
                exit(0);
        /*这一步有三个功能
         * 1.让进程摆脱原会话的控制
         * 2.让进程摆脱原进程组的控制
         * 3.让进程摆脱原控制终端的控制*/
            setsid();
        /*改变当前目录为根目录*/
            chdir("/");
        /*重新设置文件权限掩码*/
            umask(0);
        /*关闭文件描述符*/
            for(i=0;i<MAXFILE;i++)
            {
                close(i);
            }
        /*守护进程的服务部分
         * 他的功能是每隔一秒向/tmp/daemon.log文件中输入字符串*/
            if( (fd=open("/tmp/daemon.log",O_CREAT | O_WRONLY | O_APPEND,0600)) < 0 )
            {
                perror("open");
                exit(1);
            }
            while(1)
            {
                write(fd,buf,len);
                sleep(1);
            }
            close(fd);
    }
#endif

void sleep(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //保证此应用只启动一次
    QSharedMemory shared("QtMyDaemon");
    if(shared.attach())
    {
        return 0;
    }
    shared.create(1);

    #if defined(_WIN32)
        //设置程序开机自启动
//        if (!SetSelfStart())
//        {
//            std::cout << "守护进程开机自启动失败" << std::endl;
//            return -1;
//        }
    #else   //linux

    #endif
    while(true)
    {
        sleep(5000);
        std::cout << "Hello World!" << std::endl;
    }
    return a.exec();
}
