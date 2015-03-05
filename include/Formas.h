#include <GL\freeglut.h>

class Formas 
{
public:
static void glTriangulo(double base, double altura){
		glPushMatrix();
		glScalef(base,altura,0);
		glBegin(GL_TRIANGLES); 
		glVertex3f(-0.5, 0, 0);
		glVertex3f(0.5, 0, 0);
		glVertex3f(0, 1, 0);
		glEnd();
		glPopMatrix();
	}

static void glCubo(double lado){
		glPushMatrix();
		glScalef(lado,lado,lado);
		glutSolidCube(1);
		glPopMatrix();
}

static void glMalla(double tam){
	glPushMatrix();
	glLineWidth(1); 
	glScaled(tam,1,1);
	glTranslated(0,0,-tam/2);
	glBegin(GL_LINES);
			glVertex3f(-0.5, 0.0, 0.0);
			glVertex3f(0.5, 0.0, 0.0);
	glEnd();
	for(int i=0 ; i < tam ; i++){
		glTranslated(0,0,1);
		glBegin(GL_LINES);
			glVertex3f(-0.5, 0.0, 0.0);
			glVertex3f(0.5, 0.0, 0.0);
		glEnd();
		
	}
	glPopMatrix();

	glPushMatrix();
	glLineWidth(1); 
	glScaled(1,1,tam);
	glTranslated(-tam/2,0,0);
	glBegin(GL_LINES);
			glVertex3f(0, 0.0, -0.5);
			glVertex3f(0, 0.0, 0.5);
	glEnd();
	for(int i=0 ; i < tam ; i++){
		glTranslated(1,0,0);
		glBegin(GL_LINES);
			glVertex3f(0, 0.0, -0.5);
			glVertex3f(0, 0.0, 0.5);
		glEnd();
		
	}
	glPopMatrix();

}

static void glCuadrado(double lado){
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

static void glPiramide( double base){
	
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

static void glSatelite(){

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

static void glPlaneta(double radio, double radioExteno){

	glPushMatrix();
	glColor3f(1,1,1.0);
	glutSolidSphere(radio,12,10);
	glPopMatrix();

	glPushMatrix();
	gluDisk(gluNewQuadric(),radio+radioExteno,radio+radioExteno+1, 100, 1);
	glPopMatrix();
}
};