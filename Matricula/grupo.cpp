#include "grupo.h"

grupo::grupo(int NRC, string codigo_curso, string nombre_curso, int creditos, string id_profesor, int cupo, int numeroGrupo, string horaIncio, string horaFinal,int codigo)
{
	this->lista_E = new lista<estudiante>;
	this->lista_N = new lista<nota>;
	this->ciclo = nullptr;
	this->NRC = NRC;
	this->horaInicio = horaIncio;
	this->horaFinal = horaFinal;
	this->cupo = cupo;
	this->numeroGrupo = numeroGrupo;
	this->codigo_curso = codigo_curso;
	this->nombre_curso = nombre_curso;
	this->id_profesor = id_profesor;
	this->creditos = creditos;
	this->codigo_carrera = codigo;
	this->cantidad = 0;
}

grupo::~grupo()
{ 
}
void grupo::setCupo(int cupo)
{
	this->cupo = cupo;
}
void grupo::setNRC(int NRC)
{
	this->NRC = NRC;
}
void grupo::setCodigo(string codigo_curso)
{
	this->codigo_curso = codigo_curso;
}
void grupo::setNumeroGrupo(int numeroGrupo)
{
	this->numeroGrupo = numeroGrupo;
}
void grupo::setNombre(string nombre_curso)
{
	this->nombre_curso = nombre_curso;
}
void grupo::setHoraInicio(string horaInicio)
{
	this->horaInicio = horaInicio;
}
void grupo::setHoraFinal(string horaFinal)
{
	this->horaFinal = horaFinal;
}
void grupo::setCreditos(int creditos)
{
	this->creditos = creditos;
}
void grupo::setID(string id_profesor)
{
	this->id_profesor = id_profesor;
}
void grupo::setCiclo(ciclo_lectivo* ciclo)
{
	this->ciclo = ciclo;
}

void grupo::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
}

int grupo::getCupo() {
	return cupo;
}
string grupo::getHoraInicio()
{
	return horaInicio;
}
string grupo::getHoraFinal()
{
	return horaFinal;
}
int grupo::getNumeroGrupo()
{
	return numeroGrupo;
}
int grupo::getNRC()
{
	return this->NRC;
}
string grupo::getCodigo()
{
	return this->codigo_curso;
}
int grupo::getCodCarrera()
{
	return this->codigo_carrera;
}

string grupo::toString()
{
	stringstream s;
		s << setw(5) << " Curso " << setw(10) << " NCR " << setw(8) << " Grupo " << setw(5) << " Cupo " << setw(13) << " Horario " <<endl;
		s <<  setw(5) <<nombre_curso << setw(5) << NRC << setw(5) << numeroGrupo << setw(8) << cupo << setw(8) << horaInicio << "-" << horaFinal << endl;
		return s.str();
}

string grupo::getNombre()
{
	return this->nombre_curso;
}
int grupo::getCreditos()
{
	return this->creditos;
}
string grupo::getID()
{
	return this->id_profesor;
}
ciclo_lectivo* grupo::getCiclo()
{
	return this->ciclo;
}

string grupo::toStringEstudiantes()
{
	stringstream s;
	s << this->lista_E->toStringGrupo() << endl;
	return s.str();
}

string grupo::toStringPorCiclo(ciclo_lectivo*)
{
	stringstream s;
	s << this->lista_E->toStringGrupo() << endl;
	return s.str();
}

string grupo::toStringProfesorCurso()
{
	stringstream s;
	s << NRC <<"       "<< codigo_curso <<"     "<< nombre_curso << endl;
	return s.str();
}

lista<nota>* grupo::getListaNotas()
{
	return this->lista_N;
}

lista<estudiante>* grupo::getEstudiantes()
{
	return this->lista_E;
}

void grupo::aumentar()
{
	this->cantidad++;
	this->cupo--;
}

int grupo::getCantidad()
{
	return this->cantidad;
}

string grupo::getDias()
{
	return this->horarioDia;
}


void  grupo::save(ofstream& outp)
{
	outp << this->NRC << '\t';
	outp << this->numeroGrupo << '\t';
	outp << this->codigo_curso << '\t';
	outp << this->nombre_curso << '\t';
	outp << this->creditos << '\t';
	outp << this->horaInicio << '\t';
	outp << this->horaFinal << '\t';
	outp << this->id_profesor << '\t';
	outp << this->ciclo->getAnio() << '\t';
	outp << this->ciclo->getCiclo() << '\t';
	outp << this->cupo << '\t';
	outp << this->codigo_carrera << '\t';
	outp << this->cantidad << '\n';
}
