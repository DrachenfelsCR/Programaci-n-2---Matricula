#ifndef REGISTRO_H
#define REGISTRO_H
#include "usuario.h"

class registro : public usuario
{
public:
	registro(string, string, string, string);
	~registro();

};

#endif // !REGISTRO_H
