
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Memory.h"
#include "MyButton.h"
#include <QPushButton>
#include <QLabel>
#include <stdlib.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#define N 4 //Spielfeldgröße N x N
#define BUTTON_BREITE 200
#define BUTTON_HOEHE 200

#define POS_LABEL_X (N+1)*BUTTON_BREITE 
#define POS_LABEL_Y 10
//enum Spielmodus;


class Memory : public QMainWindow
{
	Q_OBJECT

public:
	Memory(QWidget *parent = Q_NULLPTR);
	

private:
	Ui::MemoryClass ui;

private:
	//QPushButton *myButton;
	MyButton* spielFeld[N][N]; // Array für die Widgets
	QLabel* spielzugLabel;
	QLabel* test;
	int counter = 0;


	//--- Funktionen der Klasse
	bool checkGameOver();
	bool turned();
	void toggleButton(int, int);
	bool samecard(ownerTyp, ownerTyp);
	void connectcard();
	void initIcon();
	bool compare();
	void initList();
	int cards[(N * N)];

private slots:
	// Beschreibt, was beim Clicken passiert
	void myButtonClicked();
};

