#ifndef GRUPO_H
#define GRUPO_H
#include "lista.h"
#include "ciclo_lectivo.h"
#include "estudiante.h"
#include "nota.h"
#include <iomanip>

class grupo
{
private:
	lista<estudiante>* lista_E;
	lista<nota>* lista_N;
	int NRC;
	int numeroGrupo;
	string codigo_curso;
	string nombre_curso;
	int creditos;
	string horaInicio;
	string horaFinal;
	string id_profesor;
	ciclo_lectivo* ciclo;
	int cupo;
	string horarioDia;
	int codigo_carrera;
	int cantidad;
public:
	grupo(int, string, string, int, string,int,int,string,string,int);
	//LISTA
	void setNRC(int);
	void setCupo(int);
	void setCodigo(string);
	void setNumeroGrupo(int);
	void setNombre(string);
	void setHoraInicio(string);
	void setHoraFinal(string);
	void setCreditos(int);
	void setID(string);
	void setCiclo(ciclo_lectivo*);
	void setCantidad(int);
	int getNRC();
	int getCupo();
	string getHoraInicio();
	string getHoraFinal();
	int getNumeroGrupo();
	string getCodigo();
	string toString();
	string toStringEstudiantes();
	string toStringPorCiclo(ciclo_lectivo*);
	string toStringProfesorCurso();
	string getNombre();
	string getDias();
	int getCodCarrera();
	int getCreditos();
	string getID();
	ciclo_lectivo* getCiclo();
	lista<estudiante>* getEstudiantes();
	lista<nota>* getListaNotas();
	int getCantidad();
	void aumentar();
	void save(ofstream&);
	~grupo();


};



#endif // !GRUPO_H
