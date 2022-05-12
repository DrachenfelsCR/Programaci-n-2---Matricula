#ifndef ADMIN_H
#define ADMIN_H
#include "usuario.h"

class admin: public usuario
{
public:
	admin(string, string, string, string);
	~admin();
	void save(ofstream&);
};



#endif // !ADMIN_H
