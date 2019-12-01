#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Memory.h"
#include "MyButton.h"
#include <QPushButton>
#include <QLabel>

#define N 4 //Spielfeldgröße N x N
#define BUTTON_BREITE 200
#define BUTTON_HOEHE 200

#define POS_LABEL_X (N+1)*BUTTON_BREITE 
#define POS_LABEL_Y 10

enum ownerTyp { BLUE, RED };

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


	//--- Funktionen der Klasse
	bool checkGameOver();
	void toggleButton(int, int);
	

private slots:
	// Beschreibt, was beim Clicken passiert
	void myButtonClicked();
};

class MyButton : public QPushButton
{
public:
	MyButton(const int i, const int j, QWidget* parent);
	~MyButton();
	//Position des Buttons im Array
	int btnReihe;
	int btnSpalte;
	ownerTyp owner;
};