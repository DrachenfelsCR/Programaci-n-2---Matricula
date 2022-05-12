#ifndef ITERADOR_H
#define ITERADOR_H
#include <iostream>
#include "lista.h"
#include "estudiante.h"
#include "admin.h"
#include "curso.h"
#include "mantenimiento.h"
#include "profesor.h"
#include "utiles.h"
#include "registro.h"
#include "carrera.h"

using namespace std;
template <class T>
class  iterador : public lista<T>
{
private:
	//nodo<T>* primero;
public:
	iterador();
	void recuperarUser(lista<usuario>*, string);
	void recuperarEst(lista<estudiante>*, string);
	void recuperarMan(lista<mantenimiento>*, string);
	void recuperarPro(lista<profesor>*, string);
	void recuperarRegis(lista<registro>*, string);
	void recuperarAdmin(lista<admin>*, string);
	void recuperaCiclos(lista<ciclo_lectivo>*, string);
	void recuperaCarrera(lista<carrera>*, lista<estudiante>*, lista<profesor>*, lista<curso>*, string, string);
	void recuperaCursos(lista<curso>*, string);
	void recuperarPlan(carrera*, string);
	void recuperarGrupo(lista<grupo>*, string);
};

template <class T>
iterador<T>::iterador()
{
	
}

template<class T>
void iterador<T>::recuperarUser(lista<usuario>* list1, string archivo)
{
	ifstream input;
	string id;
	string nombre_usuario;
	string nombre_completo;
	string clave;
	string estado;
	string rol;
	
	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, id, '\t');
		getline(input, nombre_usuario, '\t');
		getline(input, nombre_completo, '\t');
		getline(input, clave, '\t');
		getline(input, estado, '\t');
		getline(input, rol, '\n');
		if (!input.eof())
		{
			usuario* usuarioRecuperado = new usuario(id, nombre_usuario, nombre_completo, clave);
			usuarioRecuperado->setRol(rol);
			list1->insertarFinal(usuarioRecuperado);
		}
	}
	input.close();
}

template<class T>
void iterador<T>::recuperarAdmin(lista<admin>* list1, string archivo)
{
	ifstream input;
	string id;
	string nombre_usuario;
	string nombre_completo;
	string clave;
	string estado;
	string rol;

	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, id, '\t');
		getline(input, nombre_usuario, '\t');
		getline(input, nombre_completo, '\t');
		getline(input, clave, '\t');
		getline(input, estado, '\t');
		getline(input, rol, '\n');
		if (!input.eof())
		{
			admin* adminRecuperado = new admin(id, nombre_usuario, nombre_completo, clave);
			list1->insertarFinal(adminRecuperado);
		}
	}
	input.close();
}

template<class T>
void iterador<T>::recuperarPro(lista<profesor>* list1, string archivo)
{
	ifstream input;
	string id;
	string nombre_usuario;
	string nombre_completo;
	string clave;
	string estado;
	string rol;
	//----
	string telefono;
	string escuela;
	string gradoAcademico;
	string carrera;
	int telefonoR;
	
	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, id, '\t');
		getline(input, nombre_usuario, '\t');
		getline(input, nombre_completo, '\t');
		getline(input, clave, '\t');
		getline(input, estado, '\t');
		getline(input, rol, '\t');
		getline(input, telefono, '\t');
		getline(input, escuela, '\t');
		getline(input, gradoAcademico, '\t');
		getline(input, carrera, '\n');
		telefonoR = convertirInt(telefono);
		if (!input.eof())
		{
			profesor* profeRecuperado = new profesor(id, nombre_usuario, nombre_completo, clave);
			profeRecuperado->setTelefono(telefonoR);
			profeRecuperado->setEscuela(escuela);
			profeRecuperado->setGradoA(gradoAcademico);
			profeRecuperado->setCarrera(carrera);
			list1->insertarFinal(profeRecuperado);
		}
	}
	input.close();
}


template<class T>
void iterador<T>::recuperarRegis(lista<registro>* list1, string archivo)
{
	ifstream input;
	string id;
	string nombre_usuario;
	string nombre_completo;
	string clave;
	string estado;
	string rol;

	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, id, '\t');
		getline(input, nombre_usuario, '\t');
		getline(input, nombre_completo, '\t');
		getline(input, clave, '\t');
		getline(input, estado, '\t');
		getline(input, rol, '\n');
		if (!input.eof())
		{
			registro* regisRecuperado = new registro(id, nombre_usuario, nombre_completo, clave);
			list1->insertarFinal(regisRecuperado);
		}
	}
	input.close();
}

template<class T>
void iterador<T>::recuperarMan(lista<mantenimiento>* list1, string archivo)
{
	ifstream input;
	string id;
	string nombre_usuario;
	string nombre_completo;
	string clave;
	string estado;
	string rol;

	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, id, '\t');
		getline(input, nombre_usuario, '\t');
		getline(input, nombre_completo, '\t');
		getline(input, clave, '\t');
		getline(input, estado, '\t');
		getline(input, rol, '\n');
		if (!input.eof())
		{
			mantenimiento* manRecuperado = new mantenimiento(id, nombre_usuario, nombre_completo, clave);
			list1->insertarFinal(manRecuperado);
		}
	}
	input.close();
}


template<class T>
void iterador<T>::recuperarEst(lista<estudiante>* list1, string archivo)
{
	ifstream input;
	string id;
	string nombre_usuario;
	string nombre_completo;
	string clave;
	string estado;
	string rol;
	string telefono;
	int telefonoR;
	string escuela;
	string codigo_carrera;
	int codigo_carreraR;
	string carrera;

	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, id, '\t');
		getline(input, nombre_usuario, '\t');
		getline(input, nombre_completo, '\t');
		getline(input, clave, '\t');
		getline(input, estado, '\t');
		getline(input, rol, '\t');
		getline(input, telefono, '\t');
		getline(input, escuela, '\t');
		getline(input, codigo_carrera, '\t');
		getline(input, carrera, '\n');
		telefonoR = convertirInt(telefono);
		codigo_carreraR = convertirInt(codigo_carrera);
		bool state = true;
		if (estado == "false")
		{
			state = false;
		}
		else
		{
			state = true;
		}
		if (!input.eof())
		{
			estudiante* estudianteRecuperado = new estudiante(id, nombre_usuario, nombre_completo, clave, telefonoR, codigo_carreraR, carrera, escuela);
			list1->insertarFinal(estudianteRecuperado);
		}
	}
	input.close();
}

//-----------------------------------------------------------------------------------------------------------------



template<class T>
void iterador<T>::recuperaCiclos(lista<ciclo_lectivo>* list1, string archivo)
{
	ifstream input;
	string anio;
	string ciclo;
	string fechaInicio;
	string fechaFinal;
	int anioR;
	int cicloR;

	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, anio, '\t');
		getline(input, ciclo, '\t');
		getline(input, fechaInicio, '\t');
		getline(input, fechaFinal, '\n');
		anioR = convertirInt(anio);
		cicloR = convertirInt(ciclo);
		if (!input.eof())
		{
			ciclo_lectivo* cicloRecuperado = new ciclo_lectivo(anioR, cicloR);
			cicloRecuperado->setFechaInicioStr(fechaInicio);
			cicloRecuperado->setFechaFinalStr(fechaFinal);
			list1->insertarFinal(cicloRecuperado);
		}
	}
	input.close();
}

template<class T>
void iterador<T>::recuperaCarrera(lista<carrera>* list1, lista<estudiante>* list2, lista<profesor>* list3, lista<curso>* list4, string archivo, string archivo2)
{
	ifstream input;
	string id;
	string nombre_usuario;
	string nombre_completo;
	string clave;
	string estado;
	string rol;
	//---------------
	string codigo_carrera;
	int codigo_carreraR;
	string nombre_carrera;
	string grado;
	bool estado2;
	string facultad;
	plan_estudios plan_carrera;
	string escuela;
	//---------------

	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, codigo_carrera,'\t');
		getline(input, nombre_carrera, '\t');
		getline(input, grado, '\t');
		getline(input, estado, '\t');
		getline(input, facultad, '\t');
		getline(input, escuela, '\n');
		//----
		codigo_carreraR = convertirInt(codigo_carrera);
		if (!input.eof())
		{
			carrera* carreraRecuperado = new carrera(codigo_carreraR, grado, nombre_carrera,  facultad, escuela);
			nodo<estudiante>* actual = list2->primero;
			nodo<profesor>* actual2 = list3->primero;
			while (actual != nullptr)
			{
				if (actual->getInfo()->getCodigo() == codigo_carreraR)
				{
					carreraRecuperado->getPadron()->insertarFinal(actual->getInfo());
				}	
				actual = actual->getSig();
			}
			while (actual2 != nullptr)
			{
				if (actual2->getInfo()->getCarrera() == nombre_carrera)
				{
					carreraRecuperado->getProfesores()->insertarFinal(actual2->getInfo());
				}
				actual2 = actual2->getSig();
			}
			carreraRecuperado->getPlan()->setNombreCarrera(nombre_carrera);
			recuperarPlan(carreraRecuperado,archivo2);
			list1->insertarFinal(carreraRecuperado);
		}
	}
	input.close();
}





template<class T>
void iterador<T>::recuperaCursos(lista<curso>* list1, string archivo)
{
	ifstream input;
	ifstream input2;
	string codigo_curso;
	string nombre_curso;
	string tipo_curso;
	string creditos;
	string horas_semanales;
	string estado;
	string cantidad;
	string vector[20];
	
	//---------------------
	int cantidadR;
	int creditosR;
	int horas_semanalesR;
	bool estadoR = true;

	input.open(archivo.c_str());
	while (input.good())
	{
		for (int i = 0; i < 20; i++)
		{
			vector[i] = "";
		}
		getline(input, codigo_curso, '\t');
		getline(input, nombre_curso, '\t');
		getline(input, tipo_curso, '\t');
		getline(input, creditos, '\t');
		getline(input, horas_semanales, '\t');
		getline(input, cantidad, '\t');
		cantidadR = convertirInt(cantidad);
		for (int i = 0; i < cantidadR; i++)
		{
			getline(input, vector[i], '\t');
		}
		getline(input, estado, '\n');
		creditosR = convertirInt(creditos);
		horas_semanalesR = convertirInt(horas_semanales);
		if (estado == "false")
		{
			estadoR = false;
		}
		if (!input.eof())
		{
			curso* cursoRecuperado = new curso(codigo_curso, nombre_curso, tipo_curso, creditosR, horas_semanalesR);
			for (int i = 0; i < cantidadR; i++)
			{
				cursoRecuperado->insertarRequisito(vector[i]);
			}
			list1->insertarFinal(cursoRecuperado);
		}
	}
	input.close();
}


template<class T>
void iterador<T>::recuperarPlan(carrera* car, string archivo)
{
	ifstream input;
	string nomCarrera;
	string codigo;
	string nombre;
	string tipo;
	string creditos;
	string horas;
	string estado;
	//----
	int creditosR;
	int horas_semanalesR;
	bool estadoR = true;
	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, nomCarrera, '\t');
		getline(input, codigo, '\t');
		getline(input, nombre, '\t');
		getline(input, tipo, '\t');
		getline(input, creditos, '\t');
		getline(input, horas, '\t');
		getline(input, estado, '\n');
		creditosR = convertirInt(creditos);
		horas_semanalesR = convertirInt(horas);
		if (estado == "false")
		{
			estadoR = false;
		}
		if (!input.eof())
		{
			if (nomCarrera == car->getNombre())
			{
				curso* cursoRecuperado = new curso(codigo, nombre, tipo, creditosR, horas_semanalesR);
				cursoRecuperado->setEstado(estadoR);
				car->getPlan()->getListaCurso()->insertarFinal(cursoRecuperado);
			}
			
		}
	}
	input.close();
}

template<class T>
void iterador<T>::recuperarGrupo(lista<grupo>* list1, string archivo)
{
	ifstream input;
	int NRC;
	int numeroGrupo;
	int creditos;
	int cupo;
	int codigo_carrera;
	int cantidad;
	int anio;
	int ciclo;
	string NRCf;
	string numeroGrupoF;
	string codigo_curso;
	string nombre_curso;
	string creditosF;
	string horaInicio;
	string horaFinal;
	string id_profesor;
	string anioF;
	string cicloF;
	string cupoF;
	string horarioDia;
	string codigo_carreraFl;
	string cantidadF;

	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, NRCf, '\t');
		getline(input, numeroGrupoF, '\t');
		getline(input, codigo_curso, '\t');
		getline(input, nombre_curso, '\t');
		getline(input, creditosF, '\t');
		getline(input, horaInicio, '\t');
		getline(input, horaFinal, '\t');
		getline(input, id_profesor, '\t');
		getline(input, anioF, '\t');
		getline(input, cicloF, '\t');
		getline(input, cupoF, '\t');
		getline(input, codigo_carreraFl, '\t');
		getline(input, cantidadF, '\n');
		NRC = convertirInt(NRCf);
		numeroGrupo = convertirInt(numeroGrupoF);
		creditos = convertirInt(creditosF);
		cupo = convertirInt(cupoF);
		codigo_carrera = convertirInt(codigo_carreraFl);
		cantidad = convertirInt(cantidadF);
		anio = convertirInt(anioF);
		ciclo = convertirInt(cicloF);
		if (!input.eof())
		{
			grupo* grupoRecuperado = new grupo(NRC, codigo_curso, nombre_curso, creditos, id_profesor, cupo, numeroGrupo, horaInicio, horaFinal, codigo_carrera);
			grupoRecuperado->setCantidad(cantidad);
			ciclo_lectivo* cicloR = new ciclo_lectivo(anio,ciclo);
			grupoRecuperado->setCiclo(cicloR);
			list1->insertarFinal(grupoRecuperado);
		}
	}
	input.close();
}

#endif // !ITERADOR_H

