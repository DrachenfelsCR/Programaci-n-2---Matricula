#include <iostream>
#include <sstream>
#include <fstream>
#ifndef USUARIO_H
#define USUARIO_H

using namespace std;
class usuario
{
protected:
	string id;
	string nombre_usuario;
	string nombre_completo;
	string clave;
	bool estado;
	string rol;

public:
	usuario();
	usuario(string, string, string, string);
	void setId(string);
	void setUserName(string);
	void setNombreCompleto(string);
	void setClave(string);
	string getId();
	string getNombreCompleto();
	string getNombreUsuario();
	string getClave();
	bool getEstado();
	string getRol();
	string toString();
	void save(ofstream&);
	void setRol(string);
	//bool operator == (usuario&);
	~usuario();


};
#endif // !USUARIO_H



