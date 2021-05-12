#ifndef PRESCRIPTION_WINDOW_GUI_H
#define PRESCRIPTION_WINDOW_GUI_H
#include <QtWidgets/QWidget>
#include <QFormLayout>
#include "Service.h"
#include <QPushButton>
#include <QLineEdit>
class PrescriptionWindow : public QWidget
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
	void initGUI();
	void connectSignalsSlots();
	void addDrugRecipe();
	void emptyRecipe();
	void generateRecipe();
	void exportRecipe();
public:
	PrescriptionWindow(Service& serv);
};
#endif
