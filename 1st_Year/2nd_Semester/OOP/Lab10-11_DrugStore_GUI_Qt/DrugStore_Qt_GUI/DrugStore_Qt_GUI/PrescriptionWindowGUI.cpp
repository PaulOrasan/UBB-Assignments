#include "PrescriptionWindowGUI.h"
#include <QMessageBox>
#include "Validation.h"

PrescriptionWindow::PrescriptionWindow(Service& serv) : service{ serv } {
	initGUI();
	connectSignalsSlots();
}

void PrescriptionWindow::initGUI() {
	layout = new QFormLayout(this);
	inputLineEdit = new QLineEdit(this);
	addButton = new QPushButton("Add drug to recipe", this);
	emptyButton = new QPushButton("Empty recipe", this);
	generateButton = new QPushButton("Generate recipe", this);
	exportButton = new QPushButton("Export recipe", this);
	exitButton = new QPushButton("Exit", this);
	layout->addRow("Input:", inputLineEdit);
	layout->addRow(addButton);
	layout->addRow(emptyButton);
	layout->addRow(generateButton);
	layout->addRow(exportButton);
	layout->addRow(exitButton);
}
void PrescriptionWindow::connectSignalsSlots() {
	QObject::connect(addButton, &QPushButton::clicked, this, &PrescriptionWindow::addDrugRecipe);
	QObject::connect(emptyButton, &QPushButton::clicked, this, &PrescriptionWindow::emptyRecipe);
	QObject::connect(generateButton, &QPushButton::clicked, this, &PrescriptionWindow::generateRecipe);
	QObject::connect(exportButton, &QPushButton::clicked, this, &PrescriptionWindow::exportRecipe);
	QObject::connect(exitButton, &QPushButton::clicked, this, &QWidget::close);
}
void PrescriptionWindow::addDrugRecipe() {
	try {
		service.addDrugRecipe(inputLineEdit->text().toStdString());
		QMessageBox::information(this, "Success", "The drug was added to recipe.");
	}
	catch(const Error& e){
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}
void PrescriptionWindow::emptyRecipe() {
	service.emptyRecipe();
	QMessageBox::information(this, "Success", "The recipe was emptied.");
}
void PrescriptionWindow::generateRecipe() {
	try {
		Validation::validateID(inputLineEdit->text().toStdString());
		service.generateRecipe(inputLineEdit->text().toInt());
		QMessageBox::information(this, "Success", "The recipe was generated successfully.");
	}
	catch (const Error& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}
void PrescriptionWindow::exportRecipe() {
	try {
		service.servExport(inputLineEdit->text().toStdString());
		QMessageBox::information(this, "Success", "The recipe was generated successfully.");
	}
	catch (const Error& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}