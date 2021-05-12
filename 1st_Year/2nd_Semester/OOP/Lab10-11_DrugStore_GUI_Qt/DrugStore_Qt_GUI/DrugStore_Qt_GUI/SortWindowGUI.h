#ifndef SORT_GUI_H
#define SORT_GUI_H
#include <QtWidgets/QWidget>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
class SortWindow : public QWidget
{
	Q_OBJECT
private:
	QHBoxLayout* layout;
	QGroupBox* box1;
	QVBoxLayout* layoutBox1;
	QGroupBox* box2;
	QVBoxLayout* layoutBox2;
	QRadioButton* increasingButton;
	QRadioButton* decreasingButton;
	QRadioButton* nameButton;
	QRadioButton* producerButton;
	QRadioButton* substancePriceButton;
	QPushButton* confirmButton;
	void initGUI();
	void connectSignalsSlots();
	void finishWindow();
public:
	SortWindow();
signals:
	void sortDetailsSelected(QString, QString);
};
#endif

