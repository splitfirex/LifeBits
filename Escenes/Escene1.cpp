#include "../include/Escene1.h"
#include "../include/Bit.h"
#include "../include/Formas.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iostream>
#include <math.h> 
#include <cmath> 
#include <map>
#include <String>
#include <GL\freeglut.h>

int mallaTam = 100;
std::map<std::string, int> malla;
std::map<int, Bit*> bits;

int tiempo;

Escene1::Escene1(void)
{
	// Establecemos la camara
	cam.psX = 300 ; cam.psY = 300; cam.psZ = 300;
	cam.veX = cam.veY = cam.veZ = 0;
	cam.arX = cam.arZ = 0.0; cam.arY = 1.0;
	// Establecemos la longitud de visual
	vol.xRight =60 ; vol.xLeft = -60;
	vol.yBot = -60; vol.yTop = 60;
	vol.zNear =1 ; vol.zFar = 1000;

	reVisualizar = true;
	tiempo = 0;
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


	inicializarBits();
	
}



void Escene1::dibujarBits(){
	for (std::map<int, Bit*>::iterator it = bits.begin(); it != bits.end(); ++it)
	{

		it->second->calcularMovimiento(malla);
		if(it->second->hasObjetive ==  false){
			int x = rand() % 100;
			int z = rand() % 100;
			it->second->darObjetivo(x,0,z);
			//std::cout << "x " << x << "z "<< z << std::endl; 
		}
		malla.erase(it->second->getPos());
		it->second->darPaso();
		malla[it->second->getPos()] = it->second->id;
		it->second->dibujar();
	}
}



void Escene1::inicializarBits(){
	srand (time(NULL));
	for(int i=1 ; i< 25 ; i++){
		Bit *nbit = new Bit(i);
		int x,z = 0;
		while(true){
			x = rand() % 100 ;
			z = rand() % 100 ;
			std::string valpos = std::to_string(x) + "|0|"+ std::to_string(z);
			if(!malla[valpos]){
				break;
				malla[valpos] = i;
			}
		}
		nbit->posicionar(x,0,z);
		bits[i] = nbit;
	}
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


void timerCB(int millisec)
{
	glutTimerFunc(millisec, timerCB, millisec);
	glutPostRedisplay();
}

void Escene1::dibujar(){
	tiempo++;
	//if(tiempo % 100 == 0){

	glMatrixMode(GL_MODELVIEW);  // MODEL
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glTranslated(-mallaTam/2,0,-mallaTam/2);
	//axis();
	glPushMatrix();
	glColor3f(1.0,1.0,0);
	glTranslated(mallaTam/2,0,mallaTam/2);
	Formas::glMalla(mallaTam);
	glPopMatrix();

	glPushMatrix();
	glTranslated(99,0,99);
	glColor3f(1.0,0.0,1);
	Formas::glCubo(1);
	glPopMatrix();
	
	glPushMatrix();
	dibujarBits();
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
	glutPostRedisplay();
	
	//}
}

void Escene1::reshape(int w, int h){


}

Escene1::~Escene1(void)
{
}
