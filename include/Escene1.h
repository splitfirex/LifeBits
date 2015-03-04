#pragma once
#include "Escena.h"
class Escene1 : public Escena
{
public:
	void dibujar();
	void keyboard(unsigned char key, int mX, int mY);
	void keyboardSP(int key, int mX, int mY);

	Escene1(void);
	~Escene1(void);
};

