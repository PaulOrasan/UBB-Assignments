#include "MainGUI.h"
#include "Validation.h"
#include <string>
#include "Error.h"
#include <QMessageBox>
#include <QTableWidget>
#include <map>
MainGUI::MainGUI(Service& service) : serv{ service } {
	initGUI();
	connectSignalsSlots();
}
void MainGUI::initGUI() {
	mainLayout = new QHBoxLayout(this);
	leftLayout = new QVBoxLayout(this);
	showScreen = new QListWidget(this);
	showScreen->setSelectionMode(QAbstractItemView::SingleSelection);
	inputFormLayout = new QFormLayout(this);
	idLineEdit = new QLineEdit(this);					// line edits
	nameLineEdit = new QLineEdit(this);
	producerLineEdit = new QLineEdit(this);
	substanceLineEdit = new QLineEdit(this);
	priceLineEdit = new QLineEdit(this);
	inputFormLayout->addRow("ID:", idLineEdit);
	inputFormLayout->addRow("Name:", nameLineEdit);
	inputFormLayout->addRow("Producer:", producerLineEdit);
	inputFormLayout->addRow("Active substance:", substanceLineEdit);
	inputFormLayout->addRow("Price:", priceLineEdit);
	buttonLayout1 = new QHBoxLayout(this);
	addButton = new QPushButton("Add new drug", this);					// buttons
	updateButton = new QPushButton("Update existent drug", this);
	deleteButton = new QPushButton("Delete drug", this);
	searchButton = new QPushButton("Search drug", this);
	showButton = new QPushButton("Show all drugs", this);
	exitButton = new QPushButton("Exit", this);
	countProdButton = new QPushButton("Count producers", this);
	buttonLayout1->addWidget(addButton);
	buttonLayout1->addWidget(updateButton);
	buttonLayout1->addWidget(deleteButton);
	buttonLayout1->addWidget(searchButton);
	buttonLayout1->addWidget(showButton);
	buttonLayout1->addWidget(exitButton);
	inputFormLayout->addRow(buttonLayout1);
	this->setLayout(mainLayout);		// layout set
	leftLayout->addWidget(showScreen);
	leftLayout->addWidget(countProdButton);
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(inputFormLayout);
}

void MainGUI::addDrug() {
	try {
		Validation::validateID(idLineEdit->text().toStdString());
		Validation::validatePrice(priceLineEdit->text().toStdString());
		serv.addDrug(stoi(idLineEdit->text().toStdString()), nameLineEdit->text().toStdString(), producerLineEdit->text().toStdString(),
			substanceLineEdit->text().toStdString(), stod(priceLineEdit->text().toStdString()));
		QMessageBox::information(this, "Success", "The new drug was added successfully.");
	}
	catch (const Error& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}
void MainGUI::updateDrug() {
	try {
		Validation::validateID(idLineEdit->text().toStdString());
		Validation::validatePrice(priceLineEdit->text().toStdString());
		serv.updateDrug(stoi(idLineEdit->text().toStdString()), stod(priceLineEdit->text().toStdString()));
		QMessageBox::information(this, "Success", "The drug was updated successfully.");
	}
	catch (const Error& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}
void MainGUI::deleteDrug() {
	try {
		Validation::validateID(idLineEdit->text().toStdString());
		serv.deleteDrug(stoi(idLineEdit->text().toStdString()));
		QMessageBox::information(this, "Success", "The drug was deleted successfully.");
	}
	catch (const Error& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}
void MainGUI::connectSignalsSlots() {
	QObject::connect(addButton, &QPushButton::clicked, this, &MainGUI::addDrug); 
	QObject::connect(updateButton, &QPushButton::clicked, this, &MainGUI::updateDrug);
	QObject::connect(deleteButton, &QPushButton::clicked, this, &MainGUI::deleteDrug);
	QObject::connect(searchButton, &QPushButton::clicked, this, &MainGUI::findDrug);
	QObject::connect(showButton, &QPushButton::clicked, this, &MainGUI::showDrugs);
	QObject::connect(exitButton, &QPushButton::clicked, this, &QWidget::close);
	QObject::connect(countProdButton, &QPushButton::clicked, this, &MainGUI::countProducer);
}

QString MainGUI::convertDrug(const Drug& d) {
	QString result;
	result += ("ID: " + QString::number(d.getID()) + "\n");
	result += ("Name: " + QString::fromStdString(d.getName()) + "\n");
	result += ("Producer: " + QString::fromStdString(d.getProducer()) + "\n");
	result += ("Active substance: " + QString::fromStdString(d.getSubstance()) + "\n");
	result += ("Price: " + QString::number(d.getPrice()) + "\n");
	return result;
}
void MainGUI::loadList(const std::vector<Drug>& v) {
	showScreen->clear();
	for (const auto& i : v) {
		auto item{ new QListWidgetItem(convertDrug(i), showScreen) };
	}
}
void MainGUI::showDrugs() {
	loadList(serv.getDrugs());
}
void MainGUI::findDrug() {
	try {
		Validation::validateID(idLineEdit->text().toStdString());
		const Drug& d{ serv.findDrug(stoi(idLineEdit->text().toStdString())) };
		std::vector<Drug> v;
		v.push_back(d);
		loadList(v);
		QMessageBox::information(this, "Success", "The drug was found successfully.");
	}
	catch (const Error& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}

void MainGUI::countProducer() {
	auto m{ serv.countProducer() };
	if (m.size() == 0) {
		QMessageBox::critical(this, "Error", "There are no drugs stored.");
		return;
	}
	QWidget* countWidget = new QWidget(this);
	QHBoxLayout* layout = new QHBoxLayout(countWidget);
	QTableWidget* table = new QTableWidget(m.size(), 2, countWidget);
	int row = -1;
	for (const auto& i : m) {
		row++;
		QTableWidgetItem* it = new QTableWidgetItem(QString::fromStdString(i.first));
		table->setItem(row, 0, it);
		it = new QTableWidgetItem(QString::number(i.second.getCount()));
		table->setItem(row, 1, it);
	}
	layout->addWidget(table);
	countWidget->setLayout(layout);
	countWidget->setWindowTitle("Producers count");
	countWidget->resize(countWidget->sizeHint());
	countWidget->setWindowFlag(Qt::Window);
	countWidget->show();
	
}