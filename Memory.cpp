#include "Memory.h"

Memory::Memory(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this); //immer zuerst
	this->setGeometry(40, 40, ((N + 2) * BUTTON_BREITE), (N * BUTTON_HOEHE));

	// Die Memory-Karten erstellen 
	QPixmap whs_logo("WH_Logo.jpg");
	QIcon ButtonIcon(whs_logo);
	
	
	for (int reihe = 0; reihe < N; reihe++)
		for (int spalte = 0; spalte < N; spalte++)
		{
			spielFeld[reihe][spalte] = new MyButton(reihe, spalte, this); //Instanzierung			
																			// set size and location of the button
			spielFeld[reihe][spalte]->setGeometry((QRect(QPoint(BUTTON_BREITE * reihe, BUTTON_HOEHE * spalte), QSize(BUTTON_BREITE, BUTTON_HOEHE))));  //x,y,w,h
			spielFeld[reihe][spalte]->resize(BUTTON_BREITE, BUTTON_HOEHE); //Größe setzen
			spielFeld[reihe][spalte]->move(BUTTON_BREITE * spalte, BUTTON_HOEHE * reihe); //platzieren
			//Logo auf Button platzieren
			spielFeld[reihe][spalte]->setIcon(ButtonIcon);
			spielFeld[reihe][spalte]->setIconSize(whs_logo.rect().size());
			spielFeld[reihe][spalte]->setFixedSize(whs_logo.rect().size());
			//spielFeld[reihe][spalte]->setAutoFillBackground(true); //Farbe konfigurieren
			//spielFeld[reihe][spalte]->setStyleSheet("background-color: rgb(0, 0, 255)"); //Blau
																							 // Signale verbinden
			connect(spielFeld[reihe][spalte], SIGNAL(clicked()), this, SLOT(myButtonClicked()));
		}

}
MyButton::MyButton(const int i, const int j, QWidget* parent) : QPushButton(parent)
{
	btnReihe = i;
	btnSpalte = j;
	owner = BLUE;
}


MyButton::~MyButton()
{
}