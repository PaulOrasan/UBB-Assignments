#include <QtWidgets/QApplication>
#include "Tester.h"
#include "MainWindowGUI.h"
#include "Repository.h"
#include "Service.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo{ "database.txt" };
    Service serv{ repo };
    MainWindow w{ serv };
    w.show();
    return a.exec();
}
