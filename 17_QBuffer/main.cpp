#include <QCoreApplication>
#include <QBuffer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer memFile;  //创建内存文件
    memFile.open(QIODevice::WriteOnly);

    memFile.write("11111111222222222");
    memFile.write("333333333333");
    memFile.close();

    qDebug() << memFile.buffer();

    return a.exec();
}
