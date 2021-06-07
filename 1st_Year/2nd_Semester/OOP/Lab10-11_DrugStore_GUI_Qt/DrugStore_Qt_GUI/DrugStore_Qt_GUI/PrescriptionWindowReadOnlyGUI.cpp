#include "PrescriptionWindowReadOnlyGUI.h"
#include <QPainter>
#include <QRandomGenerator>
PrescriptionWindowReadOnly::PrescriptionWindowReadOnly(Service& serv) : service{ serv } {
	serv.getPrescription().addObserver(this);
}
void PrescriptionWindowReadOnly::paintEvent(QPaintEvent* ev) {
	QPainter painter{ this };
	QRandomGenerator gen;
	gen.seed(time(0));
	for (int i = 0; i<service.getRecipe().size(); i++)
		painter.drawRect(gen.generate() % this->width(), gen.generate() % this->height(), gen.generate() % 500, gen.generate() % 500);
}
void PrescriptionWindowReadOnly::update() {
	repaint();
}