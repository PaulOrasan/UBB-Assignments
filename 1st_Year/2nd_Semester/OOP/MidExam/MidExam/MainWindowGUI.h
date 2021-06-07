#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include "Service.h"
class MainWindow : public QWidget
{
	Q_OBJECT
private:
	Service& service;
	QLineEdit* numeLineEdit;
	QLineEdit* genLineEdit;
	QLineEdit* anLineEdit;
	QLineEdit* nrEpVizLineEdit;
	QSpinBox* numarEpisoadeSpinBox;
	QPushButton* adaugareButton;
	QCheckBox* nevizionatCheckBox;
	QLineEdit* recomandariLineEdit;
	QPushButton* recomandariPushButton;
	QListWidget* listShow;

	/*
	* Functie de initializare fereastra
	*/
	void initGUI();

	/*
	* Functie de conectare semnale/sloturi
	*/
	void connectSignalsSlots();

	/*
	* Functie care incarca serialele in lista de afisat
	*/
	void incarcaSeriale(std::vector<SerialTV> lista);

	/*
	* Functie care preia inputul pentru a adauga serialul in lista
	*/
	void adaugaSerial();

	/*
	* Functie care realizeaza afisarea in lista in functie de bifarea/nebifarea checkboxului pt vizionat
	*/
	void filtrareNevizionate(int state);

	/*
	* Functie care genereaza raportul de recomandari
	*/
	void recomanda();
public:

	/*
	* Constructor pentru fereastra
	*/
	MainWindow(Service& serv);
signals:

	/*
	* Semnal emis cand se modifica serialele
	*/
	void serialeModificate(std::vector<SerialTV> lista);
};
#endif
