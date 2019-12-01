#include "MyButton.h"
#include <QPushButton>




MyButton::MyButton(const int i, const int j, QWidget* parent) : QPushButton(parent)
{
	btnReihe = i;
	btnSpalte = j;
	owner = BLUE;
}


MyButton::~MyButton()
{
}


