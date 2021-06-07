#include "MainWindowGUI.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Service.h"
#include "Tester.h"
int main(int argc, char *argv[])
{
    /*Tester tester;
    tester.runTests();
    return 0;*/
    QApplication a(argc, argv);
    Repository repo;
    Service serv{ repo };
    MainWindow w{ serv };
    w.show();
    return a.exec();
}
