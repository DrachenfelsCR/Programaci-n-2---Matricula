#ifndef CURSO_ESTUDIANTE_H
#define CURSO_ESTUDIANTE_H
#include <iostream>
#include "ciclo_lectivo.h"
#include <iomanip>
using namespace std;
class curso_estudiante
{
private:
	string codigo_curso;
	string nombre_curso;
	int creditos;
	float nota;
	ciclo_lectivo* cicloDeCurso;
	int NRC;
	int grupo;
	string profesor;
	int cupo;
	int cantidad;
	string horarioInicio;
	string horarioFinalizacion;
	string dias;
	bool aprobado;
public:
	void setCodigo(string);
	void setNombre(string);
	void setCreditos(int);
	void setNota(float);
	void setCiclo(ciclo_lectivo*);
	ciclo_lectivo* getCicloCurso();
	string getCodigo();
	string getNombre();
	string toString();
	int getCreditos();
	int getNRC();
	float getNota();
	bool getAprobado();
	curso_estudiante(string, string, int, float, int, int, string , int ,int, string, string, string);
	~curso_estudiante();
	//
};



#endif // !CURSO_ESTUDIANTE_H
