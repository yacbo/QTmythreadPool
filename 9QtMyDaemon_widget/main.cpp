#include "widget.h"
#include <QApplication>
#include <string>
#include <sstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    //w.hide();

    char* charValue = argv[1];
    std::stringstream ss;
    ss<<charValue;
    int value = 0;
    ss>>value;
    w.SetValue(value);

    return a.exec();
}
