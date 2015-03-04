#include <GL\freeglut.h>


void glTriangulo(double base, double altura){
		glPushMatrix();
		glScalef(base,altura,0);
		glBegin(GL_TRIANGLES); 
		glVertex3f(-0.5, 0, 0);
		glVertex3f(0.5, 0, 0);
		glVertex3f(0, 1, 0);
		glEnd();
		glPopMatrix();
	}

void glCubo(double lado){
		glPushMatrix();
		glScalef(lado,lado,lado);
		glutSolidCube(1);
		glPopMatrix();
}

void glCuadrado(double lado){
		glPushMatrix();
		glScalef(lado,lado,0);
		glBegin(GL_QUADS); 
		glVertex3f(-0.5, 0, 0);
		glVertex3f(0.5, 0, 0);
		glVertex3f(0.5, 1, 0);
		glVertex3f(-0.5, 1, 0);
		glEnd();
		glPopMatrix();
}

void glPiramide( double base){
	
	glPushMatrix();
	glTranslated(0,0,-base/4); 
	glRotatef(30,1,0,0);
	glTriangulo(base/2,base/2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,000,base/4);  
	glRotatef(-30,1,0,0);
	glTriangulo(base/2,base/2);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(base/4,0,0);  
	glRotatef(90,0,1,0);
	glRotatef(-30,1,0,0);
	glTriangulo(base/2,base/2);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-base/4,0,0);  
	glRotatef(90,0,1,0);
	glRotatef(30,1,0,0);
	glTriangulo(base/2,base/2);
	glPopMatrix();
}

void glSatelite(){

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
}

void glPlaneta(double radio, double radioExteno){

	glPushMatrix();
	glColor3f(1,1,1.0);
	glutSolidSphere(radio,12,10);
	glPopMatrix();

	glPushMatrix();
	gluDisk(gluNewQuadric(),radio+radioExteno,radio+radioExteno+1, 100, 1);
	glPopMatrix();
}