
@echo off
 
::检测时间间隔，单位：秒
set _interval=5
 
::需要守护的进程名称
set _processName=QtMyDaemon
 
::需要守护的进程启动命令
set _processCmd=QtMyDaemon.exe
::set _processCmd=socket服务端.exe
::需要守护的进程预估启动完毕所需时间，单位：秒
set _processTimeout=1
 
::进程用户名，一般是Administrator 
set _username=adminstrator
 
:LOOP
set /a isAlive=false
::tasklist /FI "username eq %_username%" | find /C "%_processName%" > temp.txt 
tasklist | find /C "%_processName%" > temp.txt
set /p num= < temp.txt
del /F temp.txt
 
if "%num%" == "0" ( 
start %_processCmd% | echo start %_processName% at %time% 
choice /D y /t %_processTimeout% > nul
)
 
if "%num%" NEQ "0" echo %_processName% is running 
choice /D y /t %_interval% >nul
goto LOOP