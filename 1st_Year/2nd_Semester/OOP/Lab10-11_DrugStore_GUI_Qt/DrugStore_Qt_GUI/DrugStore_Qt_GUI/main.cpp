#include "MainGUI.h"
#include <QtWidgets/QApplication>
#include "Prescription.h"
#include "MemoryRepository.h"
#include "Service.h"
#include "Tester.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MemoryRepository repo;
    Prescription pres;
    Service serv{ repo, pres };
    MainGUI w{ serv };
    w.show();
    return a.exec();
}
