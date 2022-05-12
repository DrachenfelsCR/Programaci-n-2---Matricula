#ifndef PROFESOR_H
#define PROFESOR_H
#include "usuario.h"
#include "grupo.h"
#include "lista.h"
class profesor : public usuario
{
protected:
	int telefono;
	string escuela;
	string gradoAcademico;
	string carrera;
	lista<grupo>* group;
public:
	profesor(string, string, string, string);
	void setTelefono(int);
	void setEscuela(string);
	void setGradoA(string);
	void setCarrera(string);
	int getTelefono();
	lista<grupo>*getGrupo();
	string getEscuela();
	string getGradoA();
	string toString();
	string getCarrera();
	~profesor();
	void save(ofstream&);


};



#endif // !PROFESOR_H
