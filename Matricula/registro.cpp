#include "registro.h"

registro::registro(string id, string nombre_usuario,string nombre_completo, string clave) : usuario(id, nombre_usuario, nombre_completo, clave)
{
	usuario::rol = "usuario-registro";
}

registro::~registro()
{
}
