#include "../include/Bit.h"
#include <GL/freeglut.h>
#include "../include/Formas.h"

Bit::Bit(int iid)
{
	id = iid;
	hasObjetive = false;
}

void Bit::darObjetivo(int ax, int ay, int az){
	obj.x =  ax;obj.y =  ay;obj.z =  az;
	hasObjetive = true;
}

void Bit::posicionar(int ax, int ay, int az){
	pos.x = ax;pos.y = ay; pos.z = az;
	nextPos.x = ax; nextPos.y = ay; nextPos.z = az;
	obj.x =  ax;obj.y =  ay;obj.z =  az;
}

void Bit::darPaso(){
	pos.x = nextPos.x;
	pos.y = nextPos.y;
	pos.z = nextPos.z;
}

std::string Bit::getPos(){
	std::string valpos = std::to_string(pos.x) + "|" + std::to_string(pos.y) + "|"+ std::to_string(pos.z);
	return valpos;
}

void Bit::calcularMovimiento(std::map<std::string,int> malla){
	
	if(pos.x > obj.x){
		nextPos.x--;
	}
	if(pos.x < obj.x){
		nextPos.x++;
	}
	if(pos.z > obj.z){
		nextPos.z--;
	}
	if(pos.z < obj.z){
		nextPos.z++;
	}
	if(pos.y > obj.y){
		nextPos.y--;
	}
	if(pos.y < obj.y){
		nextPos.y++;
	}

	std::string valpos = std::to_string(nextPos.x) + "|" + std::to_string(nextPos.y) + "|"+ std::to_string(nextPos.z);
	
	if(malla[valpos]){
		nextPos.x = pos.x; nextPos.y = pos.y;nextPos.z = pos.z;
	}

	if(nextPos.x == obj.x && nextPos.y == obj.y  && nextPos.z == obj.z){
		hasObjetive =false;
	}

}

void Bit::dibujar(){
	glPushMatrix();
	glTranslated(pos.x,pos.y,pos.z);
	Formas::glCubo(1);
	glPopMatrix();
}

Bit::~Bit(void)
{
}
