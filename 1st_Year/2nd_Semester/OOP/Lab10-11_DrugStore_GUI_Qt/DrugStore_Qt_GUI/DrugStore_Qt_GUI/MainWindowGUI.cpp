#include "MainWindowGUI.h"
#include "Validation.h"
#include <string>
#include "Error.h"
#include <QMessageBox>
#include <QTableWidget>
#include <map>
#include "SortWindowGUI.h"
#include "FilterWindowGUI.h"
#include "PrescriptionWindowGUI.h"
MainWindow::MainWindow(Service& service) : serv{ service } {
	initGUI();
	connectSignalsSlots();
}
void MainWindow::initGUI() {
	mainLayout = new QHBoxLayout(this);
	leftLayout = new QVBoxLayout(this);
	showScreen = new QListWidget(this);
	showScreen->setSelectionMode(QAbstractItemView::SingleSelection);
	inputFormLayout = new QFormLayout(this);
	rightLayout = new QVBoxLayout(this);
	idSpinBox = new QSpinBox(this);					// line edits
	idSpinBox->setMaximum(2000000000);
	nameLineEdit = new QLineEdit(this);
	producerLineEdit = new QLineEdit(this);
	substanceLineEdit = new QLineEdit(this);
	priceLineEdit = new QLineEdit(this);
	inputFormLayout->addRow("ID:", idSpinBox);
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
	sortButton = new QPushButton("Sort drugs", this);
	filterButton = new QPushButton("Filter drugs", this);
	prescriptionButton = new QPushButton("Prescription option", this);
	/*buttonLayout1->addWidget(addButton);
	buttonLayout1->addWidget(updateButton);
	buttonLayout1->addWidget(deleteButton);
	buttonLayout1->addWidget(searchButton);
	buttonLayout1->addWidget(showButton);
	buttonLayout1->addWidget(exitButton);
	inputFormLayout->addRow(buttonLayout1);*/
	/*inputFormLayout->addRow(addButton);
	inputFormLayout->addRow(updateButton);
	inputFormLayout->addRow(deleteButton);
	inputFormLayout->addRow(searchButton);
	inputFormLayout->addRow(showButton);
	inputFormLayout->addRow(exitButton);*/
	this->setLayout(mainLayout);		// layout set
	leftLayout->addWidget(showScreen);
	leftLayout->addWidget(countProdButton);
	leftLayout->addWidget(sortButton);
	leftLayout->addWidget(filterButton);
	leftLayout->addWidget(prescriptionButton);
	rightLayout->addLayout(inputFormLayout);
	rightLayout->addWidget(addButton);
	rightLayout->addWidget(updateButton);
	rightLayout->addWidget(deleteButton);
	rightLayout->addWidget(searchButton);
	rightLayout->addWidget(showButton);
	rightLayout->addWidget(exitButton);
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
}

void MainWindow::connectSignalsSlots() {
	QObject::connect(addButton, &QPushButton::clicked, this, &MainWindow::addDrug);
	QObject::connect(updateButton, &QPushButton::clicked, this, &MainWindow::updateDrug);
	QObject::connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteDrug);
	QObject::connect(searchButton, &QPushButton::clicked, this, &MainWindow::findDrug);
	QObject::connect(showButton, &QPushButton::clicked, this, &MainWindow::showDrugs);
	QObject::connect(exitButton, &QPushButton::clicked, this, &QWidget::close);
	QObject::connect(countProdButton, &QPushButton::clicked, this, &MainWindow::countProducer);
	QObject::connect(sortButton, &QPushButton::clicked, this, &MainWindow::getSortDrugsDetails);
	QObject::connect(filterButton, &QPushButton::clicked, this, &MainWindow::getFilterDrugsDetails);
	QObject::connect(prescriptionButton, &QPushButton::clicked, this, &MainWindow::prescriptionOptions);
}

void MainWindow::addDrug() {
	try {
		serv.addDrug(idSpinBox->text().toInt() , nameLineEdit->text().toStdString(), producerLineEdit->text().toStdString(),
			substanceLineEdit->text().toStdString(), stod(priceLineEdit->text().toStdString()));
		QMessageBox::information(this, "Success", "The new drug was added successfully.");
	}
	catch (const Error& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}
void MainWindow::updateDrug() {
	try {
		serv.updateDrug(idSpinBox->text().toInt(), stod(priceLineEdit->text().toStdString()));
		QMessageBox::information(this, "Success", "The drug was updated successfully.");
	}
	catch (const Error& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}
void MainWindow::deleteDrug() {
	try {
		serv.deleteDrug(idSpinBox->text().toInt());
		QMessageBox::information(this, "Success", "The drug was deleted successfully.");
	}
	catch (const Error& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}

QString MainWindow::convertDrug(const Drug& d) {
	QString result;
	result += ("ID: " + QString::number(d.getID()) + "\n");
	result += ("Name: " + QString::fromStdString(d.getName()) + "\n");
	result += ("Producer: " + QString::fromStdString(d.getProducer()) + "\n");
	result += ("Active substance: " + QString::fromStdString(d.getSubstance()) + "\n");
	result += ("Price: " + QString::number(d.getPrice()) + "\n");
	return result;
}
void MainWindow::loadList(const std::vector<Drug>& v) {
	showScreen->clear();
	for (const auto& i : v) {
		auto item{ new QListWidgetItem(convertDrug(i), showScreen) };
	}
}
void MainWindow::showDrugs() {
	loadList(serv.getDrugs());
}
void MainWindow::findDrug() {
	try {
		const Drug& d{ serv.findDrug(idSpinBox->text().toInt()) };
		std::vector<Drug> v;
		v.push_back(d);
		loadList(v);
		QMessageBox::information(this, "Success", "The drug was found successfully.");
	}
	catch (const Error& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMessage()));
	}
}

void MainWindow::countProducer() {
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

void MainWindow::getSortDrugsDetails() {
	SortWindow* sortWindow = new SortWindow();
	sortWindow->show();
	QObject::connect(sortWindow, &SortWindow::sortDetailsSelected, this, &MainWindow::sortDrugs);
}

void MainWindow::sortDrugs(QString sortType, QString sortWay) {
	std::string type, way;
	if (sortType == "Name")
		type = "name";
	else if (sortType == "Producer")
		type = "producer";
	else if (sortType == "Active substance and price")
		type = "substance&price";
	loadList(serv.sort(type, sortWay.toStdString()));
}

void MainWindow::getFilterDrugsDetails() {
	FilterWindow* filterWindow = new FilterWindow();
	filterWindow->show();
	QObject::connect(filterWindow, &FilterWindow::filterDetailsSelected, this, &MainWindow::filterDrugs);
}

void MainWindow::filterDrugs(QString type, QVariant condition) {
	if (type == "Price") {
		auto v{ serv.filterPrice(condition.toDouble()) };
		loadList(v);
	}
	else {
		auto v{ serv.filterSubstance(condition.toString().toStdString()) };
		loadList(v);
	}
}

void MainWindow::prescriptionOptions() {
	PrescriptionWindow* window = new PrescriptionWindow(serv);
	window->show();
}