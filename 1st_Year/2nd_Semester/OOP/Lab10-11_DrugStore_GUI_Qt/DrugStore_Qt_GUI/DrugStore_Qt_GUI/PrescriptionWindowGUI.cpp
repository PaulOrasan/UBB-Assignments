#include "PrescriptionWindowGUI.h"
#include <QMessageBox>
#include "Validation.h"

PrescriptionWindow::PrescriptionWindow(Service& serv) : service{ serv } {
	initGUI();
	connectSignalsSlots();
	loadList();
}

void PrescriptionWindow::initGUI() {
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
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
	mainLayout->addLayout(layout);
	drugList = new QListWidget(this);
	mainLayout->addWidget(drugList);
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
		loadList();
	}
	catch(const Error& e){
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}
void PrescriptionWindow::emptyRecipe() {
	service.emptyRecipe();
	loadList();
	QMessageBox::information(this, "Success", "The recipe was emptied.");
}
void PrescriptionWindow::generateRecipe() {
	try {
		Validation::validateID(inputLineEdit->text().toStdString());
		service.generateRecipe(inputLineEdit->text().toInt());
		loadList();
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

void PrescriptionWindow::update() {
	loadList();
}

void PrescriptionWindow::loadList() {
	drugList->clear();
	for (const auto& i : service.getRecipe()) {
		QString result;
		result += ("ID: " + QString::number(i.getID()) + "\n");
		result += ("Name: " + QString::fromStdString(i.getName()) + "\n");
		result += ("Producer: " + QString::fromStdString(i.getProducer()) + "\n");
		result += ("Active substance: " + QString::fromStdString(i.getSubstance()) + "\n");
		result += ("Price: " + QString::number(i.getPrice()) + "\n");
		auto item{ new QListWidgetItem(result) };
		drugList->addItem(item);
	}
}