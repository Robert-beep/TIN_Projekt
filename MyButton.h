
//--- MyButton.h --
#pragma once
#include <QPushButton>

enum ownerTyp { LAMA_1_, LAMA_2_, LAMA_3,LAMA_4 };
enum status {WHS, LAMA};

class MyButton : public QPushButton
{
public:
	MyButton(const int i, const int j, QWidget* parent);
	~MyButton();
	//Position des Buttons im Array
	int btnReihe;
	int btnSpalte;
	int owner;
	status status;
};