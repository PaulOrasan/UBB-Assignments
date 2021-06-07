#pragma once
#include <QWidget>
#include "Service.h"
#include <QSpinBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QPushButton>
#include <QComboBox>
#include <QSlider>
#include <QLabel>
class MainWindow : public QWidget
{
	Q_OBJECT
private:
	Service& service;
	QSpinBox* idSpinBox;
	QLineEdit* destinationLineEdit;
	QDoubleSpinBox* priceSpinBox;
	QComboBox* filterComboBox;
	QTableWidget* showTable;
	QPushButton* addTripButton;
	QPushButton* deleteTripButton;
	QPushButton* deleteDestinationButton;
	QSlider* slider;
	QPushButton* modifyPrice;
	QLabel* rateLabel;

	void initGUI();
	void connectSignalsSlots();
	void loadTrips(const std::vector<Trip>& list);
	void addTrip();
	void deleteTrip();
	void filterTrips(const QString& text);
	void deleteDestinationTrips();
public:
	MainWindow(Service& serv);
signals:
	void tripsChanged();
};

