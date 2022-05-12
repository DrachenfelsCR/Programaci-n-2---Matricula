#include "estudiante.h"

estudiante::estudiante(string id, string nombre_usuario, string nombre_completo, string clave,int telefono,int codigo_carrera,string carrera,string escuela) : usuario(id, nombre_usuario, nombre_completo, clave)
{
	usuario::rol = "usuario-estudiante";
	this->telefono = telefono;
	this->codigo_carrera = codigo_carrera;
	this->l1 = new lista<curso_estudiante>;
	this->carrera = carrera;
	this->escuela = escuela;
}

estudiante::~estudiante()
{
}

void estudiante::setTelefono(int tel)
{
	this->telefono = tel;
}
void estudiante::setEscuela(string escuela)
{
	this->escuela = escuela;
}
void estudiante::setCodigo(int codigo)
{
	this->codigo_carrera = codigo;
}
void estudiante::setCarrera(string carrera)
{
	this->carrera = carrera;
}
int estudiante::getTelefono()
{
	return this->telefono;
}
string estudiante::getEscuela()
{
	return this->escuela;
}
int estudiante::getCodigo()
{
	return this->codigo_carrera;
}

lista<curso_estudiante>* estudiante::getListaCursos()
{
	return this->l1;
}

string estudiante::toString()
{
	stringstream s;
	s << usuario::toString();
	s << "\nTelefono: " << this->telefono << endl;
	s << "Escuela: " << this->escuela << endl;
	s << "Carrera: " << this->carrera << endl;
	s << "Codigo de la carrera: " << this->codigo_carrera << endl;
	return s.str();

}

string estudiante::toString2()
{
	stringstream s;
	s << "El Estudiante  " << getNombreCompleto() << " fue empadronado en : " << endl;
	return s.str();
}
string estudiante::toString3()
{
	stringstream s;
	s << getId() << "  " <<getNombreCompleto()<< endl;
	return s.str();
}

void estudiante::save(ofstream& outp)
{
	outp << getId() << '\t';
	outp << getNombreUsuario() << '\t';
	outp << getNombreCompleto() << '\t';
	outp << getClave() << '\t';
	if (getEstado() == false)
	{
		outp << "false" << '\t';
	}
	else
	{
		outp << "true" << '\t';
	}
	outp << getRol() << '\t';
	outp << getTelefono()<<'\t';
	outp << getEscuela() << '\t';
	outp << getCodigo() << '\t';
	outp << getCarrera() << '\n';

}

string estudiante::getCarrera()
{
	return this->carrera;
}
