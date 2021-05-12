#include "FilterWindowGUI.h"
#include <QDoubleValidator>
#include <QDebug>
#include <QMessageBox>
FilterWindow::FilterWindow() {
	initGUI();
	connectSignalsSlots();
}
void FilterWindow::initGUI() {

	layout = new QVBoxLayout(this);
	this->setLayout(layout);

	layoutBox = new QVBoxLayout(this);
	priceButton = new QRadioButton("Price", this);
	substanceButton = new QRadioButton("Active substance:", this);
	inputSpinBox = new QDoubleSpinBox(this);
	inputLineEdit = new QLineEdit(this);

	QHBoxLayout* row1 = new QHBoxLayout(this);
	row1->addWidget(priceButton);
	row1->addWidget(inputSpinBox);
	
	QHBoxLayout* row2 = new QHBoxLayout(this);
	row2->addWidget(substanceButton);
	row2->addWidget(inputLineEdit);
	
	layoutBox->addLayout(row1);
	layoutBox->addLayout(row2);
	box = new QGroupBox("Filter type:", this);
	box->setLayout(layoutBox);

	confirmButton = new QPushButton("Confirm filter details", this);

	layout->addWidget(box);
	layout->addWidget(confirmButton);

	inputSpinBox->setDisabled(true);
	inputLineEdit->setDisabled(true);
}

void FilterWindow::connectSignalsSlots() {
	QObject::connect(confirmButton, &QPushButton::clicked, this, &FilterWindow::finishWindow);
	QObject::connect(priceButton, &QRadioButton::toggled, this, [&]() {
			if (priceButton->isChecked()) {
				inputSpinBox->setEnabled(true);
				inputLineEdit->setDisabled(true);
			}
			else {
				inputSpinBox->setDisabled(true);
				inputLineEdit->setEnabled(true);
			}
		});
	QObject::connect(priceButton, &QRadioButton::toggled, this, [&]() {
		if (priceButton->isChecked()) {
			inputSpinBox->setEnabled(true);
			inputLineEdit->setDisabled(true);
		}
		else {
			inputSpinBox->setDisabled(true);
			inputLineEdit->setEnabled(true);
		}
		});
	QObject::connect(substanceButton, &QRadioButton::toggled, this, [&]() {
		if (substanceButton->isChecked()) {
			inputLineEdit->setEnabled(true);
			inputSpinBox->setDisabled(true);
		}
		else {
			inputLineEdit->setDisabled(true);
			inputSpinBox->setEnabled(true);
		}
		});
}

void FilterWindow::finishWindow() {
	QString filterType = "none";
	QList<QRadioButton*> buttons{ box->findChildren<QRadioButton*>() };
	for (const auto& i : buttons) {
		if (i->isChecked()) {
			filterType = i->text();
		}
	}
	if (filterType == "none") {
		QMessageBox::critical(this, "Error", "You did not select all details for the filter.");
		return;
	}
	qDebug() << inputLineEdit->text().toDouble();
	if (filterType == "Price") {
		emit filterDetailsSelected(filterType, inputSpinBox->value());
	}
	else {
		emit filterDetailsSelected(filterType, inputLineEdit->text());
	}
	QWidget::close();
}

