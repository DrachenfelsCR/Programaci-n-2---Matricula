#include "ciclo_lectivo.h"

ciclo_lectivo::ciclo_lectivo(int anio, int ciclo)
{
	this->anio = anio;
	this->ciclo = ciclo;
	this->fechaFinal = "00/00/00";
	this->fechaInicio = "00/00/00";
}

void ciclo_lectivo::setAnio(int anio)
{
	this->anio = anio;
}
void ciclo_lectivo::setCiclo(int ciclo)
{
	this->ciclo = ciclo;
}
void ciclo_lectivo::setFechaInicio(int dia, int mes, int anio)
{
	stringstream s;
	s << dia << "/" << mes << "/" << anio;
	this->fechaInicio = s.str();
}
void ciclo_lectivo::setFechaFinal(int dia, int mes, int anio)
{
	stringstream s;
	s << dia << "/" << mes << "/" << anio;
	this->fechaFinal = s.str();
}

void ciclo_lectivo::setFechaInicioStr(string fechaInicial)
{
	this->fechaInicio = fechaInicial;
}


void ciclo_lectivo::setFechaFinalStr(string fechaFinal)
{
	this->fechaFinal = fechaFinal;
}



int ciclo_lectivo::getAnio()
{
	return this->anio;
}
int ciclo_lectivo::getCiclo()
{
	return this->ciclo;
}
string  ciclo_lectivo::getFechaInicio()
{
	return this->fechaInicio;
}
string  ciclo_lectivo::getFechaFinal()
{
	return this->fechaFinal;
}

string  ciclo_lectivo::toString()
{
	stringstream s;
	s << "Fecha de inicio: " << this->fechaInicio << endl;
	s << "Fecha de finalizacion: " << this->fechaFinal << endl;
	s << "Ciclo: " << this->ciclo << endl;
	s << "Anio: " << this->anio << endl;
	return s.str();
}
bool ciclo_lectivo::operator ==(ciclo_lectivo* ciclo)
{
	if ((this->anio == ciclo->getAnio()) && (this->ciclo == ciclo->getAnio()) && (this->fechaFinal == ciclo->getFechaFinal()) && (this->fechaInicio == ciclo->getFechaInicio()))
	{
		return true;
	}
	return false;
}

void  ciclo_lectivo::save(ofstream& outp)
{
	outp << this->anio << '\t';
	outp << this->ciclo << '\t';
	outp << this->fechaInicio << '\t';
	outp << this->fechaFinal << '\n';
}


ciclo_lectivo::~ciclo_lectivo()
{
}
