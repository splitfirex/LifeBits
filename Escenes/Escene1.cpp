#include "../Headers/Escene1.h"
#include <iostream>
#include <GL\freeglut.h>


Escene1::Escene1(void)
{
	// Establecemos la camara
	cam.psX = 100 ; cam.psY = 100.0; cam.psZ = 100.0;
	cam.veX = cam.veY = cam.veZ = 0.0;
	cam.arX = cam.arZ = 0.0; cam.arY = 1.0;
	// Establecemos la longitud de visual
	vol.xRight = 100 ; vol.xLeft = -100;
	vol.yBot = -100; vol.yTop = 100;
	vol.zNear =1 ; vol.zFar = 1000;

	// Establecemos la ilumunacion
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);   


	glEnable(GL_LIGHT0);
	GLfloat LuzDifusa[4]={1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_SPECULAR, LuzDifusa);
	GLfloat LuzAmbiente[4]={0.3f, 0.3f, 0.3f, 1.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, LuzAmbiente);
	GLfloat posLuz0[4]= {1000.0, 1000.0, 1000.0, 0.0}; 
	glLightfv(GL_LIGHT0, GL_POSITION, posLuz0); 

}

void Escene1::keyboard(unsigned char key, int mX, int mY){
	bool need_redisplay = true;
	if(key == 27)  /* Escape key */  //continue_in_main_loop = false; (**)
		glutLeaveMainLoop (); //Freeglut's sentence for stopping glut's main loop 
	else if(key == '+') {  cam.psX ++; }
	else if(key == '-') { cam.psX --;  }
	else need_redisplay = false;

	if (need_redisplay) glutPostRedisplay();
}

void Escene1::keyboardSP(int key, int mX, int mY){
	bool need_redisplay = true;
	if(key == GLUT_KEY_UP) cam.psX ++;  
	else if (key == GLUT_KEY_DOWN) cam.psX --;
	else need_redisplay = false;

	if (need_redisplay) glutPostRedisplay();
}

void axis(){

	glPushMatrix();
	// Drawing axes
	glBegin( GL_LINES );

	glColor3f(1.0, 0.0, 0.0); // red
	glVertex3f(0, 0, 0);      // origin
	glVertex3f(200, 0, 0);	  // x   

	glColor3f(0.0, 1.0, 0.0); // green
	glVertex3f(0, 0, 0);      // center
	glVertex3f(0, 200, 0);	  // y

	glColor3f(0.0, 0.0, 1.0); // blue
	glVertex3f(0, 0, 0);      // origin
	glVertex3f(0, 0, 200);	  // z   
	glRotated(0.1,1,1,0);
	glEnd(); 
	//scene

	glPolygonMode(GL_FRONT, GL_LINE);  
	//glShadeModel(GL_FLAT); 
	glScaled(100, 100, 100);
	glBegin(GL_TRIANGLES);  // triángulo: secuencia de tuplas
	glNormal3f(1.0, 1.0, 1.0);  // normal xyz
	glColor3f(1.0, 0.0, 0.0);   // red
	glVertex3f(1.0, 0.0, 0.0);  // vértice x
	glColor3f(0.0, 1.0, 0.0);   // green
	glVertex3f(0.0, 1.0, 0.0);  // vértice y
	glColor3f(0.0, 0.0, 1.0);   // blue
	glVertex3f(0.0, 0.0, 1.0);  // vértice z
	glEnd();
	glScaled(1.0/100, 1.0/100, 1.0/100);
	glPolygonMode(GL_FRONT, GL_FILL);
	glShadeModel(GL_SMOOTH);
	glPopMatrix();
}

void Escene1::dibujar(){


	glMatrixMode(GL_MODELVIEW);  // MODEL
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	axis();
	glPushMatrix();
//	 glSatelite();
	 glPopMatrix();
	/*
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glPiramide(100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,0.5,1.0);
	glTranslated(0,86.60,0);
	glScaled(1,-1,1);
	glPiramide(100);
	glPopMatrix();


	glPushMatrix();
	glColor3f(.5,0.5,1.0);
	glTranslated(0,43.30,-25);
	glRotated(90,1,0,0);
	glCuadrado(50);
	glPopMatrix();
	*/
	setVisual();

}


Escene1::~Escene1(void)
{
}
