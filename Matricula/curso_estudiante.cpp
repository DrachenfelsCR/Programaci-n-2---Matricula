#include "curso_estudiante.h"

curso_estudiante::curso_estudiante(string codigo_curso, string nombre_curso, int creditos, float nota, int NRC, int grupo, string profesor, int cupo, int cantidad, string horarioInicio, string horarioFinalizacion, string dias)
{
	this->codigo_curso = codigo_curso;
	this->nombre_curso = nombre_curso;
	this->creditos = creditos;
	this->nota = nota;
	this->cicloDeCurso = nullptr;
	this->NRC = NRC;
	this->grupo = grupo;
	this->profesor = profesor;
	this->cupo = cupo;
	this->cantidad = cantidad;
	this->horarioInicio = horarioInicio;
	this->horarioFinalizacion = horarioFinalizacion;
	this->dias = dias;
	this->aprobado = false;
}
void curso_estudiante::setCodigo(string codigo_curso)
{
	this->codigo_curso = codigo_curso;
}
void curso_estudiante::setNombre(string nombre_curso)
{
	this->nombre_curso = nombre_curso;
}
void curso_estudiante::setCreditos(int creditos)
{
	this->creditos = creditos;
}
void curso_estudiante::setNota(float nota)
{
	this->nota = nota;
	if (nota >= 70)
	{
		this->aprobado = true;
	}
}

void curso_estudiante::setCiclo(ciclo_lectivo* cicloCurso)
{
	this->cicloDeCurso = cicloCurso;
}
ciclo_lectivo* curso_estudiante::getCicloCurso()
{
	return this->cicloDeCurso;
}
string curso_estudiante::getCodigo()
{
	return this->codigo_curso;
}
string curso_estudiante::getNombre() 
{
	return this->nombre_curso;
}
int curso_estudiante::getCreditos()
{
	return this->creditos;
}
float curso_estudiante::getNota()
{
	return this->nota;
}
int curso_estudiante::getNRC()
{
	return this->NRC;
}

bool curso_estudiante::getAprobado()
{
	return this->aprobado;
}

curso_estudiante::~curso_estudiante()
{
}

string curso_estudiante::toString()
{
	stringstream s;
	s << "NCR  " << " Grupo " << "  Curso  " << "  Profesor  " << "  Cupo  " << "  Can  " << "  Horario  " << " Nota "<< endl;
	s << this->NRC << setw(5) << this->grupo << setw(11) << this->nombre_curso << "     " << this->profesor << setw(5) << this->cupo << setw(5) << this->cantidad << setw(5) << this->dias << " " << this->horarioInicio << "-" <<this->horarioFinalizacion <<"  "<<this->nota;
	if (this->aprobado == true)
	{
		s << "	" << "Aprobado";
	}
	else
	{
		s << "	" << "Reprobado";
	}
	return s.str();
}
