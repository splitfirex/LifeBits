#pragma once
#include <map>
#include <string>
#include <iostream>


class Bit
{
public:

	typedef struct punto{
		int x,y,z;
	};

	punto pos;
	punto nextPos;
	punto obj;

	std::map<std::string,std::string> con;
	int id;

	void conversar(Bit *amigo);
	void dibujar();
	void darPaso();
	void posicionar(int x, int y, int z);
	void darObjetivo(int x, int y, int z);
	void darConocimiento(std::string clave, std::string valor);


	Bit(int id);
	~Bit(void);
};

