#include "Memory.h"



Memory::Memory(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this); //immer zuerst
	this->setGeometry(40, 40, ((N + 2) * BUTTON_BREITE), (N * BUTTON_HOEHE));
	//Zufallszahl: Zeit auf Systemzeit setzen
	srand(time(NULL));
	int zahl1 = ((rand() % 10));
	cout << zahl1 << endl;

	initList();
	

	// Die Memory-Karten erstellen 
	QPixmap whs_logo("WH_Logo200.jpg");
	QIcon ButtonIcon(whs_logo);
	
	int s_offset = 0;
	for (int reihe = 0; reihe < N; reihe++) {
		for (int spalte = 0; spalte < N; spalte++)
		{
			spielFeld[reihe][spalte] = new MyButton(reihe, spalte, this); //Instanzierung			
			// set size and location of the button
			spielFeld[reihe][spalte]->setGeometry((QRect(QPoint(BUTTON_BREITE * reihe, BUTTON_HOEHE * spalte), QSize(BUTTON_BREITE, BUTTON_HOEHE))));  //x,y,w,h
			spielFeld[reihe][spalte]->resize(BUTTON_BREITE, BUTTON_HOEHE); //Größe setzen
			spielFeld[reihe][spalte]->move(BUTTON_BREITE * spalte, BUTTON_HOEHE * reihe); //platzieren
			//WHSLogo auf Button platzieren
			spielFeld[reihe][spalte]->setIcon(ButtonIcon);
			spielFeld[reihe][spalte]->setIconSize(whs_logo.rect().size());
			spielFeld[reihe][spalte]->setFixedSize(whs_logo.rect().size());

			int sum = spalte + s_offset + reihe;
			spielFeld[reihe][spalte]->owner = static_cast <int> (cards[sum]);
			//cout << spielFeld[reihe][spalte]->status << " ";
			// Signale verbinden
			connect(spielFeld[reihe][spalte], SIGNAL(clicked()), this, SLOT(myButtonClicked()));
		}
		s_offset = (N-1)* reihe;
	}
	
	// Konfiguratiion eines Lables
	spielzugLabel = new QLabel(this);
	spielzugLabel->setText("Memory");
	spielzugLabel->setGeometry(POS_LABEL_X, POS_LABEL_Y, 160, 50); //x,y,w,h
												  // Größe der Schriftart auf dem Label setzen
	QFont labelFont;
	labelFont.setPixelSize(14);
	spielzugLabel->setFont(labelFont);


}

//void Memory::initIcon(int,int) {
//	
//	return;
//}

void Memory::initList() {
	int k = 0;
	//Füllen des Arrays
	/*if (N % 2 == 0) {*/
		for (int i = 0; i < N*N; i = i + 2) {
			cards[i] = k;
			cards[i + 1] = k;
			k++;
		}
	random_shuffle(cards, cards + (N * N));
	/*}
	else {
		for (int i = 0; i < 2 * ((N * N) / 2); i = i + 2) {
			cards[i] = k;
			cards[i + 1] = k;
			k++;
		}

	random_shuffle(cards, cards + 2 * ((N * N) / 2));
	}*/

	
	
}

void Memory::toggleButton(int r, int s) {
	QPixmap LAMA_0("Lama_0.png");
	QPixmap LAMA_1("Lama_1.png");
	QPixmap LAMA_2("Lama_2.png");
	QPixmap LAMA_3("Lama_3.png");
	QPixmap LAMA_4("Lama_4.png");


	switch (spielFeld[r][s]->owner) {

	case 0: spielFeld[r][s]->setIcon(LAMA_0); break;
	case 1:	spielFeld[r][s]->setIcon(LAMA_1); break;
	case 2:	spielFeld[r][s]->setIcon(LAMA_2); break;
	case 3:	spielFeld[r][s]->setIcon(LAMA_3); break;
	default:spielFeld[r][s]->setIcon(LAMA_4); break;
	}
	////ownerTyp selectIcon = spielFeld[r][s]->owner;
	
spielFeld[r][s]->repaint();
spielFeld[r][s]->status = LAMA;

	//if (turned()) 
	//{	//das Label kann beliebig eingefügt werden um zu überprüfen ob ein Schritt funktioniert
	//	test = new QLabel(this);
	//	test->setText("funktioniert");
	//	test->setGeometry(POS_LABEL_X, 30, 160, 50);

	//	QFont labelFont1;
	//	labelFont1.setPixelSize(14);
	//	test->setFont(labelFont1);
	//}
}

//bool Memory::turned(){
//	//Speichern von offenen Karten im Zug
//	bool save_turned[N][N]; //array muss noch vor Gebrauch zurückgesetzt werden
//	for (int reihe = 0; reihe < N; reihe++)
//		for (int spalte = 0; spalte < N; spalte++) {
//			save_turned[reihe][spalte] = false;
//		}
//
//	for ( int r = 0; r < N; r++)
//	{
//		for(int s = 0; s < N; s++)
//		{
//			if (spielFeld[r][s]->status == LAMA)
//			{
//				counter++;
//				save_turned[r][s]=true;
//			}
//		}
//	}
//	if (counter == 2) 
//	{
//		if (compare())
//		{
//			return true;
//		}
//		else return false;
//	}
//	
//}

bool Memory::compare()
{
	
	return true;
}

void Memory::myButtonClicked()
{
	// Wer hat des Event erzeugt?
	QObject* obj = sender();
	//Returns the meta-method index of the signal that called the currently executing slot,
	//which is a member of the class returned by sender(). 
	//If called outside of a slot activated by a signal, -1 is returned.

	//Casten des QObjects in ein QPushButton
	QPushButton* button = qobject_cast<QPushButton*>(sender());

	//Casten auf MyButton
	MyButton* btnClicked = static_cast<MyButton*>(button);
	int r = btnClicked->btnReihe;
	int s = btnClicked->btnSpalte;
	char str[20];
	sprintf(str, "%d %d gecklickt", r, s);
	spielzugLabel->setText(str);
	spielzugLabel->repaint();
	//Toggeln des angeklickten Buttons
	toggleButton(r, s);


	/*if (checkGameOver()) {
		spielzugLabel->setText("Gewonnen !!!");

		//QApplication::exit(); //Beendet Programm
	}*/

}
