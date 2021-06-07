#ifndef PRESCRIPTION_WINDOW_GUI_H
#define PRESCRIPTION_WINDOW_GUI_H
#include <QtWidgets/QWidget>
#include <QFormLayout>
#include "Service.h"
#include <QPushButton>
#include <QLineEdit>
#include "Observer.h"
#include <QListWidget>
class PrescriptionWindow : public QWidget, public Observer
{
	Q_OBJECT
private:
	Service& service;
	QFormLayout* layout;
	QLineEdit* inputLineEdit;
	QPushButton* addButton;
	QPushButton* emptyButton;
	QPushButton* generateButton;
	QPushButton* exportButton;
	QPushButton* exitButton;
	QListWidget* drugList;
	void initGUI();
	void connectSignalsSlots();
	void addDrugRecipe();
	void emptyRecipe();
	void generateRecipe();
	void exportRecipe();
	void update() override;
	void loadList();
public:
	PrescriptionWindow(Service& serv);
};
#endif
