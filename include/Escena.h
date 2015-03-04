#pragma once
#include <Gl/glut.h>

class Escena
{
public:

	struct camara{
		GLdouble psX,psY,psZ;
		GLdouble veX,veY,veZ;
		GLdouble arX,arY,arZ;
	} cam;

	struct proOrto{
		GLdouble xRight, xLeft;
		GLdouble yTop, yBot;
		GLdouble zNear, zFar;
	} vol;

	struct proPers{
		GLdouble xRight, xLeft;
		GLdouble yTop, yBot;
		GLdouble zNear, zFar;
	} per;

	virtual void dibujar() = 0;
	virtual void keyboard(unsigned char key, int mX, int mY) = 0;
	virtual void keyboardSP(int key, int mX, int mY) = 0;

	void setVisual(){

		glMatrixMode(GL_MODELVIEW);   // VIEW
		glLoadIdentity();
		gluLookAt(cam.psX,cam.psY,cam.psZ, 
			cam.veX,cam.veY,cam.veZ, 
			cam.arX,cam.arY,cam.arZ);

		glMatrixMode(GL_PROJECTION);  // Pr
		glLoadIdentity();
		glOrtho(vol.xLeft,vol.xRight, vol.yBot,vol.yTop, vol.zNear,vol.zFar);
	};

	Escena(void){}
	~Escena(void){}
};

