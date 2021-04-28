#ifndef MainGUI_H
#define MainGUI_H
#include "Service.h"
#include <QtWidgets/QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QFormLayout>
#include <QPushButton>
#include <vector>
class MainGUI : public QWidget 
{
    Q_OBJECT
private:
    Service& serv;
    QHBoxLayout* mainLayout;
    QVBoxLayout* leftLayout;
    QListWidget* showScreen;
    QFormLayout* inputFormLayout;
    QLineEdit* idLineEdit;
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
    void initGUI();
    void connectSignalsSlots();
    void addDrug();
    void updateDrug();
    void deleteDrug();
    void showDrugs();
    void findDrug();
    void countProducer();
    QString convertDrug(const Drug&);
    void loadList(const std::vector<Drug>&);

public:
    MainGUI(Service& service);
};
#endif