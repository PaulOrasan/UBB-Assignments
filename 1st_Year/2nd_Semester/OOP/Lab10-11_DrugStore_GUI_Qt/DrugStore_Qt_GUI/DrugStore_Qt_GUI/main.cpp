#include "MainWindowGUI.h"
#include <QtWidgets/QApplication>
#include "Prescription.h"
#include "MemoryRepository.h"
#include "Service.h"
#include "Tester.h"
#include "FilterWindowGUI.h"
#include "PrescriptionWindowGUI.h"
int main(int argc, char *argv[])
{
    /*Tester tester;
    tester.runTests();
    return 0;*/
    QApplication a(argc, argv);
    MemoryRepository repo;
    Prescription pres;
    Service serv{ repo, pres };
    MainWindow w{ serv };
    w.show();
    return a.exec();
}
