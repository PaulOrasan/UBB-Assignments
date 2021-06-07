#include "MainWindowGUI.h"
#include <QFormLayout>
#include <QMessageBox>
#include <set>
#include <QColor>
#include <QDebug>
MainWindow::MainWindow(Service& serv) : service{ serv } {
	initGUI();
	connectSignalsSlots();
	emit tripsChanged();
}
void MainWindow::initGUI() {
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QFormLayout* leftLayout = new QFormLayout(this);
	QVBoxLayout* rightLayout = new QVBoxLayout(this);
	
	idSpinBox = new QSpinBox(this);
	destinationLineEdit = new QLineEdit(this);
	priceSpinBox = new QDoubleSpinBox(this);
	filterComboBox = new QComboBox(this);
	addTripButton = new QPushButton("Add a new trip", this);
	deleteTripButton = new QPushButton("Delete a trip", this);
	deleteDestinationButton = new QPushButton("Delete all trips by destination", this);
	showTable = new QTableWidget(this);
	slider = new QSlider(Qt::Horizontal, this);
	modifyPrice = new QPushButton("Lower price", this);
	rateLabel = new QLabel("0%", this);

	leftLayout->addRow("Trip ID:", idSpinBox);
	leftLayout->addRow("Trip destination:", destinationLineEdit);
	leftLayout->addRow("Trip price:", priceSpinBox);
	leftLayout->addRow("Highlight destination:", filterComboBox);
	leftLayout->addRow(addTripButton);
	leftLayout->addRow(deleteDestinationButton);
	leftLayout->addRow("Update price", slider);
	leftLayout->addRow(modifyPrice);

	rightLayout->addWidget(showTable);
	rightLayout->addWidget(deleteTripButton);
	rightLayout->addWidget(rateLabel);

	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	this->setLayout(mainLayout);

	idSpinBox->setRange(1, INT_MAX);
	priceSpinBox->setRange(0, 10000000);
	slider->setMinimum(0);
	slider->setMaximum(100);
	destinationLineEdit->setValidator(new QDoubleValidator());
}

void MainWindow::connectSignalsSlots() {
	QObject::connect(addTripButton, &QPushButton::clicked, this, &MainWindow::addTrip);
	QObject::connect(deleteTripButton, &QPushButton::clicked, this, &MainWindow::deleteTrip);
	QObject::connect(this, &MainWindow::tripsChanged, this, [&]() {
		filterComboBox->clear();
		filterComboBox->addItem("---");
		std::set<std::string> exists;
		for (const auto& i : service.getTrips()) {
			if (exists.find(i.getDestination()) == exists.end()) {
				exists.insert(i.getDestination());
			}
		}
		for (const auto& i : exists) {
			filterComboBox->addItem(QString::fromStdString(i));
		}
		});
	QObject::connect(this, &MainWindow::tripsChanged, this, [&]() {
		loadTrips(service.getTrips());
		});
	QObject::connect(filterComboBox, &QComboBox::textActivated, this, &MainWindow::filterTrips);
	QObject::connect(showTable, &QTableWidget::cellClicked, this, [&](int row, int column) {
		filterTrips("---");
		showTable->item(row, 0)->setBackgroundColor(QColor(0, 255, 0));
		showTable->item(row, 1)->setBackgroundColor(QColor(0, 255, 0));
		showTable->item(row, 2)->setBackgroundColor(QColor(0, 255, 0));
		idSpinBox->setValue(showTable->item(row, 0)->text().toInt());
		destinationLineEdit->setText(showTable->item(row, 1)->text());
		priceSpinBox->setValue(showTable->item(row, 2)->text().toDouble());
		});
	QObject::connect(deleteDestinationButton, &QPushButton::clicked, this, &MainWindow::deleteDestinationTrips);
	QObject::connect(slider, &QSlider::sliderReleased, this, [&]() {
		priceSpinBox->setValue(priceSpinBox->value() * slider->value() / 100);
		QMessageBox::information(this, "Success", "You've lowered the price to " + QString::number(slider->value()) + "%!");
		});
	QObject::connect(slider, &QSlider::valueChanged, this, [&]() {
		rateLabel->setText(QString::number(slider->value()) + "%");
		});
	QObject::connect(modifyPrice, &QPushButton::clicked, this, [&]() {
		QDoubleValidator validator;
		int x = 0;
		if (validator.validate(destinationLineEdit->text(), x) != QDoubleValidator::Acceptable) {
			QMessageBox::information(this, "Error", "Text invalid");
		}
		else {
			QMessageBox::information(this, "Success", "The value is " + QString::number(destinationLineEdit->text().toDouble()));
		}
		});
}
void MainWindow::loadTrips(const std::vector<Trip>& trips) {
	showTable->clear();
	showTable->setRowCount(trips.size());
	showTable->setColumnCount(3);
	for (int i = 0; i < trips.size(); i++) {
		showTable->setItem(i, 0, new QTableWidgetItem(QString::number(trips[i].getID())));
		showTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(trips[i].getDestination())));
		showTable->setItem(i, 2, new QTableWidgetItem(QString::number(trips[i].getPrice())));
	}
}

void MainWindow::addTrip() {
	if (destinationLineEdit->text().isEmpty()) {
		QMessageBox::information(this, "Error", "You haven't set the trip destination!");
		return;
	}
	try {
		
		service.addTrip(idSpinBox->text().toInt(), destinationLineEdit->text().toStdString(), priceSpinBox->value());
		emit tripsChanged();
	}
	catch (const RepositoryError& error) {
		QMessageBox::information(this, "Error", QString::fromStdString(error.getMessage()));
	}
}

void MainWindow::deleteTrip() {
	try {
		service.deleteTrip(idSpinBox->text().toInt());
		emit tripsChanged();
	}
	catch (const RepositoryError& error) {
		QMessageBox::information(this, "Error", QString::fromStdString(error.getMessage()));
	}
}

void MainWindow::filterTrips(const QString& text) {
	for (int i = 0; i < showTable->rowCount(); i++) {
		if (showTable->item(i, 1)->text() == text && text != "---") {
			showTable->item(i, 0)->setBackgroundColor(QColor(255, 0, 0));
			showTable->item(i, 1)->setBackgroundColor(QColor(255, 0, 0));
			showTable->item(i, 2)->setBackgroundColor(QColor(255, 0, 0));
		}
		else {
			showTable->item(i, 0)->setBackgroundColor(QColor(255, 255, 255));
			showTable->item(i, 1)->setBackgroundColor(QColor(255, 255, 255));
			showTable->item(i, 2)->setBackgroundColor(QColor(255, 255, 255));
		}
	}
}

void MainWindow::deleteDestinationTrips() {
	if (filterComboBox->count() == 1) {
		QMessageBox::information(this, "Error", "No trips stored!");
		return;
	}
	QWidget* window = new QWidget(this, Qt::Window);
	QVBoxLayout* layout = new QVBoxLayout(window);
	std::vector<QPushButton*> buttons;
	for (int i = 1; i < filterComboBox->count(); i++) {
		QPushButton* button = new QPushButton(filterComboBox->itemText(i), window);
		layout->addWidget(button);
		QObject::connect(button, &QPushButton::clicked, this, [=]() {
			service.deleteDestinationTrips(button->text().toStdString());
			emit tripsChanged();
			button->setVisible(false);
			layout->removeWidget(button);
			if (layout->count() == 0) {
				layout->parentWidget()->close();
			}
			});
	}
	window->setLayout(layout);
	window->show();
}