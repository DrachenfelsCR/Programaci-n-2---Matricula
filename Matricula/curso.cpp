#include "curso.h"

curso::curso()
{
	this->codigo_curso = "";
	this->tipo_curso = "";
	this->creditos = 0;
	this->horas_semanales = 0;
	this->estado = true;
	cantidad = 0;
	for (int i = 0; i < 20; i++)
	{
		vec[i] = "";
	}
}

curso::curso(string codigo_curso, string nombre_curso, string tipo_curso, int creditos, int horas)
{
	this->codigo_curso = codigo_curso;
	this->nombre_curso = nombre_curso;
	this->tipo_curso = tipo_curso;
	this->creditos = creditos;
	this->horas_semanales = horas;
	this->estado = true;
	cantidad = 0;
	for (int i = 0; i < 20; i++)
	{
		vec[i] = "";
	}
}
void curso::setCodigo(string codigo_curso)
{
	this->codigo_curso = codigo_curso;
}
void curso::setNombre(string nombre_curso)
{
	this->nombre_curso = nombre_curso;
}
void curso::setTipo(string tipo_curso)
{
	this->tipo_curso = tipo_curso;
}
void curso::setCreditos(int creditos)
{
	this->creditos = creditos;
}
void curso::setHoras(int horas)
{
	this->horas_semanales = horas;
}
void curso::setEstado(bool estado)
{
	this->estado = estado;
}
string curso::getCodigo()
{
	return this->codigo_curso;
}

int curso::getCantidad()
{
	return this->cantidad;
}
string curso::getNombre()
{
	return this->nombre_curso;
}
string curso::getTipo()
{
	return this->tipo_curso;
}

int curso::getCreditos()
{
	return this->creditos;
}

int curso::getHoras()
{
	return this->horas_semanales;
}

bool curso::getEstado()
{
	return this->estado;
}
void curso::insertarRequisito(string req)
{
	vec[cantidad++] = req;
}

string curso::toString()
{
	stringstream s;
	s <<"Codigo curso: "<< codigo_curso << endl;
	s <<"Nombre de curso: "<< nombre_curso << endl;
	s << "Horas semanales: " << horas_semanales << endl;
	s << "Creditos: " <<creditos << endl;
	s << "Tipo de curso: "<< tipo_curso << endl;
	return s.str();
}
string curso::toString2()
{
	stringstream s;
	s <<"Codigos requisitos: " << codigo_curso << endl;;
	for (int i = 0; i < cantidad; i++)
	{
		s << "   " << vec[i] << endl;
	}
	return s.str();
}

void curso::save(ofstream& outp)
{
	outp << this->codigo_curso << '\t';
	outp << this->nombre_curso << '\t';
	outp << this->tipo_curso << '\t';
	outp << this->creditos << '\t';
	outp << this->horas_semanales << '\t';
	outp << cantidad << '\t';
	for (int i = 0; i < cantidad; i++)
	{
		outp << vec[i] << '\t';
	}
	//-------------
	if (this->estado == false)
	{
		outp << "false" << '\n';
	}
	else
	{
		outp << "true" << '\n';
	}
}

curso::~curso()
{

}

