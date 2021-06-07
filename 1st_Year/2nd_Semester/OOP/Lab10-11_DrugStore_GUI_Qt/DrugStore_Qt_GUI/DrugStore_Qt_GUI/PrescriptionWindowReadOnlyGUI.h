#ifndef PRESCRIPTION_PAINT_H
#define PRESCRIPTION_PAINT_H
#include <QWidget>
#include "Observer.h"
#include "Service.h"
class PrescriptionWindowReadOnly : public QWidget, public Observer
{
	Q_OBJECT
private:
	Service& service;
	void update() override;
public:
	PrescriptionWindowReadOnly(Service& serv);
	void paintEvent(QPaintEvent* ev) override;
};
#endif
