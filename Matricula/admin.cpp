#include "admin.h"

admin::admin(string id, string nombre_usuario, string nombre_completo, string clave) : usuario(id, nombre_usuario, nombre_completo, clave)
{
	usuario::rol = "usuario-admin";
}

admin::~admin()
{
}

void admin::save(ofstream& outp)
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
	outp << getRol() << '\n';

}
