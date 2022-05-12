#ifndef MANTENIMIENTO_H
#define MANTENIMIENTO_H
#include "usuario.h"
#include <fstream>

class mantenimiento : public usuario
{
public:
	mantenimiento(string, string, string, string);
	~mantenimiento();
	void save(ofstream&);
};



#endif // !MANTENIMIENTO_H
