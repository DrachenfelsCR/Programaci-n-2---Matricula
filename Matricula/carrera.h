#ifndef CARRERA_H
#define CARRERA_H
#include <iostream>
#include <sstream>
#include "plan_estudios.h"
#include "lista.h"
#include "estudiante.h"
#include "profesor.h"
using namespace std;

class carrera
{
private:
	int codigo_carrera;
	string nombre_carrera;
	string grado;
	bool estado;
	string facultad;
	plan_estudios* plan_carrera;
	lista<estudiante>* l1;
	string escuela;
	lista<profesor>* l2;
public:
	carrera(int, string, string, string,string);
	void setCodigo(int);
	void setGrado(string);
	void activarCarrera();
	void desactivarCarrera();
	void setFacultad(string);
	void setNombreCarrera(string);
	void setPlan(plan_estudios*);
	int getCodigo();
	string getNombre();
	string getGrado();
	bool getEstado();
	string getFacultad();
	plan_estudios* getPlan();
	lista<estudiante>* getPadron();
	lista<profesor>* getProfesores();
	~carrera();
	void setEscuela(string);
	string getEscuela();
	string toString();
	string toStringPlan();
	void saveC(ofstream&, ofstream&);
};



#endif // !CARRERA_H
