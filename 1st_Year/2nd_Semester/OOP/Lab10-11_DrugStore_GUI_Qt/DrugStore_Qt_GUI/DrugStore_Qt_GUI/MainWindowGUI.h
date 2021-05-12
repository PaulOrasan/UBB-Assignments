#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include "Service.h"
#include <QtWidgets/QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QFormLayout>
#include <QPushButton>
#include <vector>
#include <QSpinBox>
class MainWindow : public QWidget 
{
    Q_OBJECT
private:
    Service& serv;
    QHBoxLayout* mainLayout;
    QVBoxLayout* leftLayout;
    QVBoxLayout* rightLayout;
    QListWidget* showScreen;
    QFormLayout* inputFormLayout;
    QSpinBox* idSpinBox;
    QLineEdit* nameLineEdit;
    QLineEdit* producerLineEdit;
    QLineEdit* substanceLineEdit;
    QLineEdit* priceLineEdit;
    QHBoxLayout* buttonLayout1;
    QPushButton* addButton;
    QPushButton* updateButton;
    QPushButton* deleteButton;
    QPushButton* searchButton;
    QPushButton* exitButton;
    QPushButton* showButton;
    QPushButton* countProdButton;
    QPushButton* sortButton;
    QPushButton* filterButton;
    QPushButton* prescriptionButton;
    void initGUI();
    void connectSignalsSlots();
    void addDrug();
    void updateDrug();
    void deleteDrug();
    void showDrugs();
    void findDrug();
    void countProducer();
    void getSortDrugsDetails();
    void sortDrugs(QString, QString);
    void getFilterDrugsDetails();
    void filterDrugs(QString, QVariant);
    void prescriptionOptions();
    QString convertDrug(const Drug&);
    void loadList(const std::vector<Drug>&);

public:
    MainWindow(Service& service);
};
#endif