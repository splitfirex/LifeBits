#include <stdio.h>
#include <iostream>
#include <GL/freeglut.h>
#include "../include/Escena.h"
#include "../include/Escene1.h"

void Display();
void reshape(int w, int h);
void initGL();
void keyFunc(unsigned char key, int mX, int mY);
void keySp(int key, int mX, int mY);

Escena *actual;

int main(int argc, char *argv[]){

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutInit(&argc,argv);
	glutCreateWindow("Hola mundo");
	actual = new Escene1();

	glutDisplayFunc(Display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyFunc);
	glutSpecialFunc(keySp);

	glutMainLoop();

	return 0;
}

void Display(){
	actual->dibujar();
	//glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w/2, w/2,-h/2,h/2,1,1000);
	//gluPerspective(45.0, (GLdouble)w/(GLdouble)h, 1.0, 200.0);
}

void keyFunc(unsigned char key, int mX, int mY){
	actual->keyboard(key,mX,mY);
}

void keySp(int key, int mX, int mY){
	actual->keyboardSP(key,mX, mY);
}