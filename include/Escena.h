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
		GLdouble fov, asp;
		GLdouble zNear, zFar;
	} per;

	bool perspectiva;
	bool reVisualizar;

	virtual void dibujar() = 0;
	virtual void keyboard(unsigned char key, int mX, int mY) = 0;
	virtual void keyboardSP(int key, int mX, int mY) = 0;
	virtual void reshape(int w, int h) = 0;

	void setVisual(){
		glMatrixMode(GL_MODELVIEW); 
		glLoadIdentity();
		gluLookAt(cam.psX,cam.psY,cam.psZ, 
			cam.veX,cam.veY,cam.veZ, 
			cam.arX,cam.arY,cam.arZ);

		glMatrixMode(GL_PROJECTION); 
		glLoadIdentity();

		if(!perspectiva){
			glOrtho(vol.xLeft,vol.xRight, vol.yBot,vol.yTop, vol.zNear,vol.zFar);
		}else{
			gluPerspective(per.fov,per.asp,per.zNear,per.zFar);
		}

		reVisualizar = false;
	};

	Escena(void){ perspectiva = false; reVisualizar = true; }
	~Escena(void){}
};

