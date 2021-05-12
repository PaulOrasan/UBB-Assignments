#include "SortWindowGUI.h"
#include <QMessageBox>
void SortWindow::initGUI() {
	layout = new QHBoxLayout(this);
	box1 = new QGroupBox("Sort by:", this);
	layoutBox1 = new QVBoxLayout(this);
	nameButton = new QRadioButton("Name", this);
	producerButton = new QRadioButton("Producer", this);
	substancePriceButton = new QRadioButton("Active substance and price", this);
	layoutBox1->addWidget(nameButton);
	layoutBox1->addWidget(producerButton);
	layoutBox1->addWidget(substancePriceButton);
	box1->setLayout(layoutBox1);
	box2 = new QGroupBox("Sort type:", this);
	layoutBox2 = new QVBoxLayout(this);
	increasingButton = new QRadioButton("Increasing", this);
	decreasingButton = new QRadioButton("Decreasing", this);
	layoutBox2->addWidget(increasingButton);
	layoutBox2->addWidget(decreasingButton);
	box2->setLayout(layoutBox2);
	confirmButton = new QPushButton("Confirm sorting details", this);
	layout->addWidget(box1);
	layout->addWidget(box2);
	layout->addWidget(confirmButton);
}

void SortWindow::connectSignalsSlots() {
	QObject::connect(confirmButton, &QRadioButton::clicked, this, &SortWindow::finishWindow);
}

SortWindow::SortWindow() {
	initGUI();
	connectSignalsSlots();
}

void SortWindow::finishWindow() {
	QString sortType="none", sortWay="none";
	const QList<QRadioButton*>& listBox1{ box1->findChildren<QRadioButton*>() };
	for (const auto& i : listBox1) {
		if (i->isChecked()) {
			sortType = i->text();
		}
	}
	const QList<QRadioButton*>& listBox2{ box2->findChildren<QRadioButton*>() };
	for (const auto& i : listBox2) {
		if (i->isChecked()) {
			sortWay = i->text();
		}
	}
	if (sortType == "none" || sortWay == "none") {
		QMessageBox::critical(this, "Error", "You did not choose all the details for the sorting!");
		return;
	}
	emit sortDetailsSelected(sortType, sortWay);
	QWidget::close();
}
