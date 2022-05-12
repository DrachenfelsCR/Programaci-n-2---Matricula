#include "usuario.h"

usuario::usuario()
{
	this->id = "";
	this->nombre_completo = "";
	this->nombre_usuario = "";
	this->clave = "";
	this->estado = true;
}

usuario::usuario(string id, string nombre_usuario, string nombre_completo,string clave)
{
	this->id = id;
	this->nombre_usuario = nombre_usuario;
	this->nombre_completo = nombre_completo;
	this->clave = clave;
	this->estado = true;
}


string usuario::getClave()
{
	return this->clave;
}

usuario::~usuario()
{

}

void usuario::setId(string id)
{
	this->id = id;
}
void usuario::setUserName(string nombre_usuario)
{
	this->nombre_usuario;
}

void usuario::setNombreCompleto(string nombre_completo)
{
	this->nombre_completo;
}
void usuario::setClave(string clave)
{
	this->clave = clave;
}

void usuario::setRol(string rol)
{
	this->rol = rol;
}

string usuario::getId()
{
	return this->id;
}
string usuario::getNombreCompleto()
{
	return this->nombre_completo;
}
string usuario::getNombreUsuario()
{
	return this->nombre_usuario;
}
bool usuario::getEstado()
{
	return this->estado;
}
string usuario::getRol()
{
	return this->rol;
}

string usuario::toString()
{
	stringstream s;
	s << "ID: " << this->id << "   ";
	s << "Nombre Completo: " << this->nombre_completo << "   ";
	s << "Nombre usuario: " << this->nombre_usuario << "   ";
	if (this->estado)
	{
		s << "Estado: " << "Activo" << "   ";
	}
	else
		s << "Estado: " << "Desactivado" << "   ";
	s << "Tipo de usuario: " << this->rol;
	return s.str();
}

void usuario::save(ofstream& outp)
{
	outp << getId() << '\t';
	outp << getNombreUsuario() << '\t';
	outp << getNombreCompleto() << '\t';
	outp << getClave() << '\t';
	if (getEstado()==false)
	{
		outp << "false" << '\t';
	}
	else
	{
		outp << "true" << '\t';
	}
	outp << getRol() << '\n';
		
}
