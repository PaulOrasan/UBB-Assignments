#include "MainWindowGUI.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <set>
MainWindow::MainWindow(Service& serv) :service{ serv } {
	initGUI();
	connectSignalsSlots();
	emit serialeModificate(service.getSeriale());
}

void MainWindow::initGUI() {
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QFormLayout* leftLayout = new QFormLayout(this);
	QVBoxLayout* rightLayout = new QVBoxLayout(this);

	numeLineEdit = new QLineEdit(this);
	genLineEdit = new QLineEdit(this);
	anLineEdit = new QLineEdit(this);
	nrEpVizLineEdit = new QLineEdit(this);
	numarEpisoadeSpinBox = new QSpinBox(this);
	adaugareButton = new QPushButton("Adaugare", this);
	nevizionatCheckBox = new QCheckBox("Nevizionat", this);
	recomandariLineEdit = new QLineEdit(this);
	recomandariPushButton = new QPushButton("Recomanda", this);
	listShow = new QListWidget(this);

	leftLayout->addRow("Numele serialului:", numeLineEdit);
	leftLayout->addRow("Genul serialului:", genLineEdit);
	leftLayout->addRow("Anul aparitiei serialului:", anLineEdit);
	leftLayout->addRow("Nr episoade vizionate:", nrEpVizLineEdit);
	leftLayout->addRow("Numarul de episoade:", numarEpisoadeSpinBox);
	leftLayout->addRow(adaugareButton);
	leftLayout->addRow(nevizionatCheckBox);
	leftLayout->addRow("Numar seriale", recomandariLineEdit);
	leftLayout->addRow(recomandariPushButton);

	rightLayout->addWidget(listShow);

	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	this->setLayout(mainLayout);

	numarEpisoadeSpinBox->setRange(1, 1000);
}

void MainWindow::connectSignalsSlots() {
	QObject::connect(this, &MainWindow::serialeModificate, this, &MainWindow::incarcaSeriale);
	QObject::connect(adaugareButton, &QPushButton::clicked, this, &MainWindow::adaugaSerial);
	QObject::connect(nevizionatCheckBox, &QCheckBox::stateChanged, this, &MainWindow::filtrareNevizionate);
	QObject::connect(recomandariPushButton, &QPushButton::clicked, this, &MainWindow::recomanda);
}

void MainWindow::incarcaSeriale(std::vector<SerialTV> lista) {
	listShow->clear();
	for (const auto& i : lista) {
		QString str = "";
		str += ("Nume serial: " + QString::fromStdString(i.getNume()) + "\n");
		str += ("Anul aparitiei: " + QString::number(i.getAnAparitie()) + "\n");
		str += ("Nr. episoade vizionate: " + QString::number(i.getNumarEpisoadeVizionate()) + "\n");
		str += ("Numar episoade total: " + QString::number(i.getNumarEpisoade()) + "\n");
		listShow->addItem(new QListWidgetItem(str));
	}
}

void MainWindow::adaugaSerial() {
	QString text{ genLineEdit->text() };
	if (!(text == "comedie" || text == "drama" || text == "thriller" || text == "documentar") || nrEpVizLineEdit->text().toInt() > numarEpisoadeSpinBox->value()) {
		QMessageBox::information(this, "Error", "Adaugarea nu se poate realiza deoarece genul este incorect sau numarul de episoade vizionate este prea mare");
		return;
	}
	else {
		service.adaugaSerial(numeLineEdit->text().toStdString(), genLineEdit->text().toStdString(), anLineEdit->text().toInt(), numarEpisoadeSpinBox->value(), nrEpVizLineEdit->text().toInt());
		if (!nevizionatCheckBox->isChecked())
			emit serialeModificate(service.getSeriale());
		else if (nrEpVizLineEdit->text().toInt() == 0) {
			filtrareNevizionate(0);
		}
	}
}

void MainWindow::filtrareNevizionate(int state) {
	if (nevizionatCheckBox->isChecked()) {
		std::vector<SerialTV> serialeNevizionate;
		for (const auto& i : service.getSeriale()) {
			if (i.getNumarEpisoadeVizionate() == 0) {
				serialeNevizionate.push_back(i);
			}
		}
		sort(serialeNevizionate.begin(), serialeNevizionate.end(), [](const SerialTV& a, const SerialTV& b) {
			return a.getAnAparitie() > b.getAnAparitie();
			});
		emit serialeModificate(serialeNevizionate);
	}
	else {
		emit serialeModificate(service.getSeriale());
	}
}

void MainWindow::recomanda() {
	std::ofstream fout("recomandari.csv");
	std::vector<SerialTV> listaVizionate;
	for (const auto& i : service.getSeriale()) {
		if (i.getNumarEpisoadeVizionate() > 0)
			listaVizionate.push_back(i);
	}
	std::srand(unsigned(time(0)));
	int nr = recomandariLineEdit->text().toInt();
	if (nr > listaVizionate.size()) {
		QMessageBox::information(this, "Error", "Prea multe seriale cerute");
		return;
	}
	std::set<int> folosit;
	for (int i = 0; i < nr; i++) {
		int index = rand() % listaVizionate.size();
		while (folosit.find(index) != folosit.end()) {
			index = rand() % listaVizionate.size();
		}
		folosit.insert(index);
		QString str = "";
		str += (QString::fromStdString(listaVizionate[index].getNume()) + ",");
		str += ( QString::fromStdString(listaVizionate[index].getGen()) + ",");
		str += (QString::number(listaVizionate[index].getAnAparitie()) + ",");
		str += (QString::number(listaVizionate[index].getNumarEpisoadeVizionate()) + ",");
		str += (QString::number(listaVizionate[index].getNumarEpisoade()));
		fout << str.toStdString() << '\n';
	}
	fout.close();
}