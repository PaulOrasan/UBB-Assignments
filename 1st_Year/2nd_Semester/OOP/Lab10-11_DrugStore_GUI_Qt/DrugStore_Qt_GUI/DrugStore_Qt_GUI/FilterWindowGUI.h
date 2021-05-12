#ifndef FILTER_WIND0W_GUI_H
#define FILTER_WINDOW_GUI_H
#include <QtWidgets/QWidget>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDoubleSpinBox>
#include <QVariant>
class FilterWindow : public QWidget
{
	Q_OBJECT
private:
	QVBoxLayout* layout;
	QGroupBox* box;
	QVBoxLayout* layoutBox;
	QRadioButton* priceButton;
	QRadioButton* substanceButton;
	QDoubleSpinBox* inputSpinBox;
	QPushButton* confirmButton;
	QLineEdit* inputLineEdit;
	void initGUI();
	void connectSignalsSlots();
	void finishWindow();
public:
	FilterWindow();
signals:
	void filterDetailsSelected(QString, QVariant);
};
#endif
