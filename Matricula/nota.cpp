#include "nota.h"

nota::nota(float nota, string id, string nombre)
{
	this->calificacion = nota;
	this->id = id;
	this->nombre = nombre;
}

void nota::setNota(float nota)
{
	this->calificacion = nota;
}

void nota::setID(string id)
{
	this->id = id;
}

string nota::toString()
{
	stringstream s;
	s<< id << "      " << nombre << "    " << calificacion << "    " << endl;
	return s.str();
}

float nota::getNota()
{
	return this->calificacion;
}

string nota::getId()
{
	return this->id;
}

nota::~nota()
{
}