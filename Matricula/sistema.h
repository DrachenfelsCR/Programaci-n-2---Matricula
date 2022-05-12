#ifndef SISTEMA_H
#define SISTEMA_H
#include "utiles.h"
#include <iostream>
#include "usuario.h"
#include "admin.h"
#include "mantenimiento.h"
#include "profesor.h"
#include "estudiante.h"
#include "registro.h"
#include "ciclo_lectivo.h"
#include "carrera.h"
#include "grupo.h"
#include "iterador.h"
using namespace std;

class sistema {


private:
	int opc;
	string* logged_user;
	usuario* usuarioLogeado;
	lista<ciclo_lectivo>* global_ciclos;
	lista<carrera>* global_carrera;
	lista<estudiante>* global_estudiantes;
	lista<curso>* global_cursos;
	lista<profesor>* global_profesores;
	lista<grupo>* global_Grupos;
	lista<admin>* global_admin;
	lista<plan_estudios>* global_planes;
public:
	//--------------------------------------
	sistema();
	void Principal();
	void controlSistema();
	void ManejoSeguridadYAdministracion();
	void ManejoDeMantenimiento();
	void ManejoDeEscuelas();
	void ManejoDeMatricula();
	void ManejoDeRegistro();
	void ManejoLogeo();
	//------Funciones secundarias-----------
	lista<usuario>* lista_global;
	void agregarUsuario(lista<usuario>*);
	void agregarCiclo();
	void agregarCarrera();
	void agregarCurso();
	void agregarEstudiante();
	void agregarGrupo();
	void consultaGeneralMatricula();
	void MostrarEmpadronados();
	void agregarProfesores();
	void MostrarProfesores();
	void ingresoNotitas();
	void consultaPlan();
	void consultaMatriculaPorEstudiante();
	void procesoMatricula();
	void visualizarNotitas();
	void visualizarHistorial();
	void guardar();
	void recuperar();
};



























#endif