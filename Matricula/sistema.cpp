#include "sistema.h"

sistema::sistema()
{
	opc = 0;
	//----------AGREGADO ADMIN ESTANDAR---------------------
	//LISTO!
	lista_global = new lista<usuario>;
	//------------------
	this->usuarioLogeado = nullptr;
	//------------------------------------------
	this->logged_user = nullptr;
	this->global_ciclos = new lista<ciclo_lectivo>;
	this->global_carrera = new lista<carrera>;
	this->global_cursos=new lista<curso>;
	this->global_estudiantes = new lista<estudiante>;
	this->global_profesores = new lista<profesor>;
	this->global_Grupos = new lista<grupo>;
	this->global_admin = new lista<admin>;
	this->global_planes = new lista<plan_estudios>;
	//-----------------------------------------
	recuperar();
}

void sistema::Principal()
{
	if (logged_user == nullptr)
	{
		ManejoLogeo();
		limpiaPantalla();
	}
	else
	limpiaPantalla();
	opc = 0;
	int can = 1;
	imprimirCadena(menuInicio());
	cout << "	[ Logeado como: " << *logged_user << " ] " << endl << endl;;
	imprimirCadena("	Digite el numero de la opcion que desea acceder:");
	do {
		opc = leerSeleccion(6);
		switch (opc)
		{
		case 1:
			if (this->usuarioLogeado->getRol() == "usuario-admin")
			{
				ManejoSeguridadYAdministracion();
			}
			else
			{
				imprimirCadena("Esta opcion solo la pueden acceder los admin");		
			}
			break;
		case 2:
			if (this->usuarioLogeado->getRol() == "usuario-admin" || this->usuarioLogeado->getRol() == "usuario-registro")
			{
				ManejoDeMantenimiento();
			}
			else
			{
				imprimirCadena("Esta opcion solo la pueden acceder los admin o usuarios de registro");
			}	
			break;
		case 3:
			if (this->usuarioLogeado->getRol() == "usuario-admin" || this->usuarioLogeado->getRol() == "usuario-mantenimiento")
			{
				ManejoDeEscuelas();
			}
			else
			{
				imprimirCadena("Esta opcion solo la pueden acceder los admin o usuarios de mantenimiento");
			}
			break;
		case 4:
			if (this->usuarioLogeado->getRol() == "usuario-admin" || this->usuarioLogeado->getRol() == "usuario-estudiante")
			{
				ManejoDeMatricula();
			}
			else
			{
				imprimirCadena("Esta opcion solo la pueden acceder los admin o usuarios estudiante");
			}
			break;
		case 5:
			if (this->usuarioLogeado->getRol() == "usuario-admin" || this->usuarioLogeado->getRol() == "usuario-profesor")
			{
				ManejoDeRegistro();
				
			}
			else
			{
				imprimirCadena("Esta opcion solo la pueden acceder los admin o usuarios profesor");
			}
			break;
		case 6:
			guardar();
			exit(0);
			break;
		}
	
	} while (can == 1);
}

void sistema::controlSistema()
{
	opc = 0;
	Principal();
}
void sistema::ManejoLogeo()
{
	string user_aux;
	string password;
	imprimirCadena(LoginMenu());
	imprimirCadena("	Digite el nombre de su usuario");
	user_aux = leerCadena();
	imprimirCadena("	Digite su contrasena");
	password = leerCadena();
	usuarioLogeado = lista_global->buscarCredenciales(user_aux, password);
	try
	{
		if (usuarioLogeado == nullptr)
		{
			throw 0;
		}
		else
		{
			this->logged_user = new string(user_aux);
		}
	}
	catch (...)
	{
		imprimirCadena("	Credenciales invalidos..");
		cin.get();
		limpiaPantalla();
		Principal();
	}
}

void sistema::ManejoSeguridadYAdministracion()
{
	limpiaPantalla();
	opc = 0;
	int cont = 1;
	do
	{
		imprimirCadena(menuSeguridad());
		opc = leerSeleccion(3);
		switch (opc)
		{
		case 1:
			agregarUsuario(lista_global);
			break;
		case 2:
			limpiaPantalla();
			imprimirCadena(lista_global->toString());
			break;
		case 3:
			Principal();
			break;
		}
		imprimirCadena("\t [Digite 1 para seguir en manejo de seguridad y admistracion] o [2 para volver al menu principal]: ");
		cont = leerSeleccion(2);
		limpiaPantalla();
		if (cont == 2) { Principal(); }
		
	} while (cont == 1);
}

void sistema::ManejoDeMantenimiento()
{

	limpiaPantalla();
	opc = 0;
	int cont = 1;
	do
	{
		imprimirCadena(menuMantenimiento());
		opc = leerSeleccion(7);
		switch (opc)
		{
		case 1:
			imprimirCadena(this->global_ciclos->toString());	
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 2:
			agregarCiclo();
			imprimirCadena("<Enter>");
			break;
		case 3:
			agregarCarrera();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 4:
			limpiaPantalla();
			agregarCurso();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 5:
			limpiaPantalla();
			imprimirCadena(this->global_carrera->toString());
			agregarEstudiante();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 6:
			limpiaPantalla();
			MostrarEmpadronados();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 7:
			Principal();
			break;

		}
		imprimirCadena("\t [Digite 1 para seguir en manejo de Mantenimiento General] o [2 para volver al menu principal]: ");
		cont = leerSeleccion(2);
		limpiaPantalla();
		if (cont == 2) { Principal(); }

	} while (cont == 1);
}

void sistema::ManejoDeEscuelas()
{
	limpiaPantalla();
	opc = 0;
	int cont = 1;
	do
	{
		imprimirCadena(menuEscuelas());
		opc = leerSeleccion(6);
		switch (opc)
		{
		case 1:
			limpiaPantalla();
			consultaPlan();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 2:
			limpiaPantalla();
			agregarGrupo();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 3:
			limpiaPantalla();
			consultaGeneralMatricula();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 4:
			limpiaPantalla();
			agregarProfesores();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 5:
			limpiaPantalla();
			MostrarProfesores();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 6:
			Principal();
			break;

		}
		imprimirCadena("\t[Digite 1 para seguir en manejo de Mantenimiento Por Escuelas] o [2 para volver al menu principal]: ");
		cont = leerSeleccion(2);
		limpiaPantalla();
		if (cont == 2) { Principal(); }

	} while (cont == 1);
}

void sistema::ManejoDeMatricula()
{
	limpiaPantalla();
	opc = 0;
	int cont = 1;
	do
	{
		imprimirCadena(menuMatricula());
		opc = leerSeleccion(4);
		switch (opc)
		{
		case 1:
			limpiaPantalla();
			procesoMatricula();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 2:
			limpiaPantalla();
			consultaMatriculaPorEstudiante();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 3:
			visualizarHistorial();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 4:
			Principal();
			break;

		}
		imprimirCadena("\t [Digite 1 para seguir en manejo de Matricula] o [2 para volver al menu principal]:");
		cont = leerSeleccion(2);
		limpiaPantalla();
		if (cont == 2) { Principal(); }

	} while (cont == 1);
}

void sistema::ManejoDeRegistro()
{
	string id;
	opc = 0;
	int cont = 1;
	do
	{
		limpiaPantalla();
		imprimirCadena(menuRegistro());
		opc = leerSeleccion(3);
		switch (opc)
		{
		case 1:
			limpiaPantalla();
			ingresoNotitas();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 2:
			limpiaPantalla();
			visualizarNotitas();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 3:
			Principal();
			break;

		}
		imprimirCadena("\t Digite 1 para seguir en manejo de Registro o 2 para volver al menu principal: ");
		cont = leerSeleccion(2);
		limpiaPantalla();
		if (cont == 2) { Principal(); }

	} while (cont == 1);
}

void sistema::agregarUsuario(lista<usuario>* list)
{
	string id, nombre_usuario, nombre_completo, clave;
	int opc;
	imprimirCadena("Ingrese ID del usuario: ");
	id = leerCadena();
	imprimirCadena("Ingrese nombre completo del usuario: ");
	nombre_completo = leerCadena();
	imprimirCadena("Ingrese nickname o nombre de usuario: ");
	nombre_usuario = leerCadena();
	if (lista_global->buscarID(id))
	{
		imprimirCadena("Ya existe un usuario con ese ID ");
	}
	else
	{
		imprimirCadena("Digite la clave de acceso para el nuevo usuario: ");
		clave = leerCadena();
		while ((stringSix(clave) == false) || (stringUpperCase(clave) == false))
		{
			imprimirCadena("Por favor, utilice una combinacion de al menos una mayuscula y sea de un largo de 6 caracteres minimos");
			clave = leerCadena();
		}
		limpiaPantalla();
		imprimirCadena("Elija el rol del usuario");
		imprimirCadena("1-Usuario-Administrador");
		imprimirCadena("2-Usuario-Mantenimiento");
		imprimirCadena("3-Usuario-Registro");
		imprimirCadena("4-Usuario-Estudiante");
		imprimirCadena("5-Usuario-Profesor");
		opc = leerSeleccion(5);
		if (opc == 1)
		{
			admin* n_admin = new admin(id, nombre_usuario, nombre_completo, clave);
			list->insertarInicio(n_admin);
			imprimirCadena("Nuevo administrador creado..");
		}
		else if (opc == 2)
		{
			mantenimiento* n_mantenimiento = new mantenimiento(id, nombre_usuario, nombre_completo, clave);
			list->insertarInicio(n_mantenimiento);
			imprimirCadena("Nuevo usuario de mantenimiento creado..");
		}
		else if (opc == 3)
		{
			registro* n_registro = new registro(id, nombre_usuario, nombre_completo, clave);
			list->insertarInicio(n_registro);
			imprimirCadena("Nuevo usuario de registro creado..");
		}
		else if (opc == 4)
		{
			estudiante* n_estudiante = new estudiante(id, nombre_usuario, nombre_completo, clave, 0, 0, "", "");
			list->insertarInicio(n_estudiante);
			imprimirCadena("Nuevo estudiante creado..");
		}
		else if (opc == 5)
		{
			profesor* n_profesor = new profesor(id, nombre_usuario, nombre_completo, clave);
			list->insertarInicio(n_profesor);
			imprimirCadena("Nuevo profesor creado..");
		}
	}	
}

void sistema::agregarCiclo()
{
	int anio, numCiclo, dia, mes;
	imprimirCadena("Digite el anio del ciclo: ");
	anio = leerEntero();
	imprimirCadena("Digite numeracion( 1. I ciclo, 2. II Ciclo, 3. III Ciclo )");
	numCiclo = leerSeleccion(3);
	ciclo_lectivo* cicloAct = new ciclo_lectivo(anio, numCiclo);
	ciclo_lectivo* cicloAnterior = global_ciclos->getUltimo();
	if (cicloAnterior == nullptr)
	{
		imprimirCadena("Ingrese la fecha de inicio: ");
		imprimirCadena(" Digite dia de inicio(numero entero): ");
		dia = leerEntero();
		imprimirCadena(" Digite mes de inicio(numero entero): ");
		mes = leerSeleccion(12);
		cicloAct->setFechaInicio(dia, mes, anio);
		//-------------------------------------------------------
		imprimirCadena("-------------------------------------------------");
		imprimirCadena("Ingrese la fecha de finalizacion: ");
		imprimirCadena(" Digite dia de finalizacion(numero entero): ");
		dia = leerEntero();
		imprimirCadena(" Digite mes de finalizacion(numero entero): ");
		mes = leerSeleccion(12);
		cicloAct->setFechaFinal(dia, mes, anio);
		this->global_ciclos->insertarFinal(cicloAct);
		imprimirCadena("<Enter>");
	}
	else if (global_ciclos->buscarCicloElectivo(anio,numCiclo))
	{
		imprimirCadena("Ya existe un ciclo lectivo igual a este [Enter]");
	}
	else if (cicloAnterior->getAnio() == anio && cicloAnterior->getCiclo() > numCiclo)
	{
			imprimirCadena("Si ingresa un ciclo nuevo en el mismo anio que el ciclo anterior, el ciclo debe ser mayor");
	}
	else if (cicloAnterior->getAnio() > anio)
	{
		imprimirCadena("Debe ingresar un anio que concuerde cronologicamente con los ciclos");
	}
	else
	{
		imprimirCadena("Ingrese la fecha de inicio: ");
		imprimirCadena(" Digite dia de inicio(numero entero): ");
		dia = leerEntero();
		imprimirCadena(" Digite mes de inicio(numero entero): ");
		mes = leerSeleccion(12);
		cicloAct->setFechaInicio(dia, mes, anio);
		//-------------------------------------------------------
		imprimirCadena("-------------------------------------------------");
		imprimirCadena("Ingrese la fecha de finalizacion: ");
		imprimirCadena(" Digite dia de finalizacion(numero entero): ");
		dia = leerEntero();
		imprimirCadena(" Digite mes de finalizacion(numero entero): ");
		mes = leerSeleccion(12);
		cicloAct->setFechaFinal(dia, mes, anio);
		this->global_ciclos->insertarFinal(cicloAct);
		imprimirCadena("<Enter>");
	}
	
	cin.get();
}

void sistema::agregarCarrera()
{
	limpiaPantalla();
	int codigo_carrera;
	string grado;
	string nombre_carrera;
	string facultad;
	string escuela;
//------------------------------------------------------------
	imprimirCadena("Ingrese codigo de carrera: ");
	codigo_carrera = leerEntero();
	while (global_carrera->buscarCodigoCarrera(codigo_carrera) != NULL)
	{
		imprimirCadena("El codigo de carrera ingresado ya existe, por favor ingrese otro:");
		codigo_carrera = leerEntero();
	}
	imprimirCadena("Ingrese nombre de carrera: ");
	nombre_carrera = leerCadena();
	while (global_carrera->buscarNombreCarrera(nombre_carrera) != NULL)
	{
		imprimirCadena("El nombre de carrera ingresado ya existe, por favor ingrese otro:");
		nombre_carrera = leerCadena();
	}
	imprimirCadena("Grado: ");
	grado = leerCadena();
	imprimirCadena("Ingrese Escuela: ");
	escuela = leerCadena();
	imprimirCadena("Ingrese Facultad: ");
	facultad = leerCadena();
	carrera* career = new carrera(codigo_carrera, grado, nombre_carrera, facultad,escuela);
//------------------------------------------------------------
	global_carrera->insertarInicio(career);
}

void sistema::agregarCurso()
{
	imprimirCadena(global_carrera->toString());
	string codigo;
	string nombre;
	string tipocurso;
	bool correcto = true;
	int creditos;
	int horasSemanales;
	int canReqs = 0;
	carrera* ca;
	imprimirCadena("Ingrese el codigo de la carrera");
	int a = leerEntero();
	if (global_carrera->buscarElemento(a))
	{
		carrera* aux = global_carrera->buscarCodigoCarrera(a);
		imprimirCadena(aux->toString());
		imprimirCadena("Ingrese el codigo que se le asignara al curso");
		codigo = leerCadena();
		while ((global_cursos->buscarCodigoCurso(codigo)))
		{
			imprimirCadena("El codigo del curso ya existe, intente con otro codigo:");
			codigo = leerCadena();
		}
		imprimirCadena("Ingrese el nombre que se le asignara al Curso");
		nombre = leerCadena();
		while ((global_cursos->buscarNombreCurso(nombre)))
		{
			imprimirCadena("El nombre del curso ya existe, intente con otro nombre:");
			nombre = leerCadena();
		}
		imprimirCadena("Ingrese el Tipo de Curso(LAB,CUR,SEM,PRA,TEST)");
		tipocurso = leerCadena();
		imprimirCadena("Ingrese la Cantidad de Creditos");
		creditos = leerSeleccion(4);
		imprimirCadena("Ingrese las Horas Lectivas Semanales");
		horasSemanales = leerSeleccion(10);
		curso* Cursos = new curso(codigo,nombre,tipocurso,creditos,horasSemanales);
		imprimirCadena("Cuantos cursos requisitos tiene: ");
		canReqs = leerEntero();
		imprimirCadena("-------------Cursos de la carrera---------------");
		if (canReqs > 0)
		{
			for (int i = 0; i < canReqs; i++)
			{
				imprimirCadena(aux->getPlan()->toString());
				imprimirCadena("Digite el codigo del curso que desea agregar como requisito");
				string codigoReq = leerCadena();
				if (aux->getPlan()->getListaCurso()->buscarCodigoCurso(codigoReq) == false)
				{
					imprimirCadena("Este codigo no existe en el plan de estudios de esta carrera");
					cout << "Se continuara con el requisito " << i + 1;
					correcto = false;
				}
				else
				{
					Cursos->insertarRequisito(codigoReq);
					imprimirCadena("Requisito agregado exitosamente!");
					correcto = true;
				}
			}
		}
		
//-----------------------------------------------------------------------------------------
		if (correcto == true)
		{
			global_cursos->insertarInicio(Cursos);
			aux->getPlan()->getListaCurso()->insertarFinal(Cursos);
			aux->getPlan()->setNombreCarrera(aux->getNombre());
		}
		
		
	
	}
	else {
		imprimirCadena("Error al digitar carrera o el numero de carrera no existe");
	}
}

void sistema::agregarEstudiante() {
	string id;
	int a;
	string nombre;
	
	int telefono;
	imprimirCadena("Digite el numero cedula del Estudiante:");
	id = leerCadena();
	imprimirCadena("Digite el numero de telefono:");
	telefono = leerEntero();
	imprimirCadena("Digite el numero de carrera:");
	a = leerEntero();
	if (global_carrera->buscarElemento(a))
	{
			string carrera = global_carrera->buscarCodigoCarrera(a)->getNombre();
			string escuela = global_carrera->buscarCodigoCarrera(a)->getEscuela();
			usuario* userAux = lista_global->buscarId(id);
			while (userAux == nullptr)
			{
				imprimirCadena("\nDigito de  manera incorrecta el numero cedula o el numero de cedula no existe en el sistema");
				imprimirCadena("\nDigite el numero cedula");
				id = leerCadena();
				userAux = lista_global->buscarId(id);
			}
			if (userAux->getRol() != "usuario-estudiante")
			{
				imprimirCadena("\nDigito un usuario que no es un estudiante, intente de nuevo");
			}
			else
			{
				estudiante* estedu = new estudiante(lista_global->buscarId(id)->getId(), lista_global->buscarId(id)->getNombreUsuario(), lista_global->buscarId(id)->getNombreCompleto(), "", telefono, a, carrera, escuela);
				global_estudiantes->insertarInicio(estedu);
				global_carrera->buscarCodigoCarrera(a)->getPadron()->insertarInicio(estedu);
				imprimirCadena(estedu->toString2());
				imprimirCadena(global_carrera->buscarCodigoCarrera(a)->toString());
			}	
	}
	else
	{
		imprimirCadena("Ingreso incorrectamente el numero de carrera o numero ingresado no existe");
	}
}

void sistema::agregarGrupo()
{
	int NRC;
	int cupo;
	string dia;
	string horaInicio;
	string horaFinal;
	int numeroGrupo;
	int salir = 2;
	imprimirCadena(global_carrera->toString());
	imprimirCadena("Digite el numero De carrera");
	int a = leerEntero();
	carrera* auxCarrera = global_carrera->buscarCodigoCarrera(a);
	ciclo_lectivo* cicl = global_ciclos->getUltimo();
	//while (!(global_carrera->buscarElemento(a)))
		if (global_profesores->esVacia())
		{
			imprimirCadena("No puede crear grupos si no existen profesores asignados a una carrera");
		}
		else if (global_cursos->esVacia())
		{
			imprimirCadena("No existen cursos creados!");
		}
		else if (global_ciclos->esVacia())
		{
			imprimirCadena("No existen ciclos creados!");
		}
		else
		{
			while (auxCarrera == nullptr)
			{
				imprimirCadena("Ingreso incorrectamente el numero de carrera o numero ingresado no existe");
				imprimirCadena("Digite el numero De carrera");
				a = leerEntero();
				auxCarrera = global_carrera->buscarCodigoCarrera(a);
			}
			imprimirCadena("Digite El  Anio");
			int anno = leerEntero();
			imprimirCadena("Digite El ciclo( 1. I ciclo, 2. II Ciclo, 3. III Ciclo )");
			int ciclo = leerEntero();
			ciclo_lectivo* cicloAux = global_ciclos->buscarCicloElectivo2(anno, ciclo);
			if (cicl != nullptr)
			{
				while (cicloAux == nullptr )
				{
					imprimirCadena("Ingreso incorrectamente el ciclo y annio lectivo o el ciclo ingresado no existe");
					imprimirCadena("Digite El  Anio");
					int anno = leerEntero();
					imprimirCadena("Digite El ciclo( 1. I ciclo, 2. II Ciclo, 3. III Ciclo )");
					int ciclo = leerEntero();
					cicloAux = global_ciclos->buscarCicloElectivo2(anno, ciclo);
				}
			}
			
			imprimirCadena(auxCarrera->getPlan()->toString());
			imprimirCadena("Digite Codigo del Curso");
			string codigo = leerCadena();

			while (!(global_cursos->buscarCodigoCurso(codigo)))
			{
				imprimirCadena("Ingreso incorrectamente el numero del curso o el codigo ingresado no existe");
				codigo = leerCadena();
			}

			imprimirCadena("Digite El NRC");
			NRC = leerEntero();
			while (global_Grupos->buscarNRCD(NRC) == true)
			{
				imprimirCadena("Este NRC ya existe!, trate con otro numero: ");
				NRC = leerEntero();
			}
			imprimirCadena("Digite el numero del Grupo");
			numeroGrupo = leerEntero();
			imprimirCadena("\n--------------------------------");
			imprimirCadena(global_profesores->toString());
			imprimirCadena("Digite el numero de Cedula del profesor");
			string id = leerCadena();
			while (!(global_profesores->buscarID(id)))
			{
				imprimirCadena("Ingreso incorrectamente el numero de cedula del profesor o el profesor ingresado no existe");
				imprimirCadena("Digite el numero de Cedula del profesor");
				id = leerCadena();

			}
			imprimirCadena("Digite el Numero de Cupos");
			cupo = leerEntero();
			imprimirCadena("Digite el Dia(ejmeplo:M-V)");
			dia = leerCadena();
			imprimirCadena("Digite la hora Inicio(ejemplo= 8:00 Formato 24hrs)");
			horaInicio = leerCadena();
			imprimirCadena("Digite la hora finalizacion(ejemplo= 10:00 Formato 24hrs)");
			horaFinal = leerCadena();
			string nombre = global_cursos->buscaElCodigoCurso(codigo)->getNombre();
			curso* cursoAux = global_cursos->buscaElCodigoCurso(codigo);
			grupo* Grupote = new grupo(NRC, codigo, nombre, cursoAux->getCreditos(), id, cupo, numeroGrupo, horaInicio, horaFinal, a);
			Grupote->setCiclo(cicloAux);
			global_Grupos->insertarInicio(Grupote);
			global_profesores->buscarId(id)->getGrupo()->insertarInicio(Grupote);
			imprimirCadena("Grupo Creado Existosamente");
		}
}



void sistema::MostrarEmpadronados()
{
	imprimirCadena(global_carrera->toString());
	imprimirCadena("Ingrese codigo de carrera ");
	int a = leerEntero();
	if (global_carrera->buscarElemento(a))
	{
		imprimirCadena(global_carrera->buscarCodigoCarrera(a)->getPadron()->toString());
	}
	else
	{
		imprimirCadena("Ingreso incorrectamente el numero de carrera o numero ingresado no existe");
	}
}



void sistema::agregarProfesores()
{
	profesor* docente;
	usuario* docentito;
	string id;
	carrera* aux = nullptr;
	try
	{
		imprimirCadena(global_carrera->toString());
		imprimirCadena("--------------");
		imprimirCadena("Digite el codigo carrera: ");
		int a = leerEntero();
		aux = global_carrera->buscarCodigoCarrera(a);
		if (aux == nullptr)
		{
			throw a;
		}
		else
		{
			imprimirCadena(aux->toString());
			imprimirCadena("------------------------------");
			imprimirCadena(lista_global->toString());
			imprimirCadena("Digite el id del profesor que desea asignar a una carrera: ");
			id = leerCadena();
			docentito = lista_global->buscarId(id);
		}
		if (docentito == nullptr || (docentito->getRol() != "usuario-profesor"))
		{
			throw id;
		}
		else
		{
			if (aux->getProfesores()->buscarId(id) != nullptr)
			{
				imprimirCadena("Este profesor ya se ingreso a esta carrera");
			}
			else
			{
				docente = new profesor(docentito->getId(), docentito->getNombreUsuario(), docentito->getNombreCompleto(), docentito->getClave());
				docente->setCarrera(aux->getNombre());
				global_carrera->buscarCodigoCarrera(a)->getProfesores()->insertarFinal(docente);
				imprimirCadena("Digite el grado academico del profesor: ");
				imprimirCadena("(1-Lic, 2-Maestria, 3-Doctorado)");
				int seleccion = leerSeleccion(4);
				switch (seleccion)
				{
				case 1:
					docente->setGradoA("Licenciatura");
					docente->setEscuela(aux->getEscuela());
					break;
				case 2:
					docente->setGradoA("Maestria");
					docente->setEscuela(aux->getEscuela());
					break;
				case 3:
					docente->setGradoA("Doctorado");
					docente->setEscuela(aux->getEscuela());
					break;
				default:
					break;
				}
				global_profesores->insertarFinal(docente);
				imprimirCadena("Profesor asignado correctamente a carrera");
			}
		}
	}
	catch (...)
	{
		cout << "La cedula " << id << "no existe en el sistema o ingreso una cedula que no es de un profesor, intente de nuevo.." << endl;
	}
	

}

void sistema::MostrarProfesores()
{
	imprimirCadena(global_carrera->toString());
	imprimirCadena("Digite el codigo de la carrera que desea mostrar");
	int code = leerEntero();
	carrera* nier = global_carrera->buscarCodigoCarrera(code);
	if (nier == NULL)
	{
		imprimirCadena("El codigo ingresado es incorrecto");
	}
	else
	{
		imprimirCadena(nier->toString());
		imprimirCadena(nier->getProfesores()->toString());
	}
}

void sistema::procesoMatricula()
{
	int NRC;
	bool requisitos = true;
	bool datosCorrectos = false;
	int opc = 1;
	string id;
	estudiante* aux = nullptr;
	ciclo_lectivo* actual = global_ciclos->getUltimo();
	curso* cursoAux = nullptr;
	string carr;
	//------------------------------------------------------------------
	if (this->usuarioLogeado->getRol() == "usuario-estudiante")
	{
		id = this->usuarioLogeado->getId();
		aux = global_estudiantes->buscarId(id);
		carr = aux->getCarrera();
		if (aux == nullptr)
		{
			datosCorrectos = false;
		}
		else
		{
			imprimirCadena("El periodo lectivo actual es: ");
			if (actual == nullptr)
			{
				imprimirCadena("No hay ciclos lectivos agregados por lo cual no se puede matricular ningun curso..");
			}
			else
			{
				cout << "Ciclo: " << actual->getCiclo() << endl;
				cout << "Annio: " << actual->getAnio() << endl;
				imprimirCadena("----------------------------------------------------------------");
				imprimirCadena("	Informe Matricula	");
				cout << "Carrera: " << carr << endl;
				cout << "Estudiante: " << aux->getNombreCompleto() << endl;
				if (global_Grupos->esVacia())
				{
					imprimirCadena("\nNo existen grupos creados");
				}
				else
				{
					imprimirCadena(global_Grupos->toStringIteradorCiclo(actual->getCiclo(), actual->getAnio()));
					imprimirCadena("\nDigite el NRC del grupo en el que desea matricularse: ");
					NRC = leerEntero();
					grupo* gAux = global_Grupos->buscarNRC(NRC);
					if (gAux == nullptr)
					{
						imprimirCadena("No existe un grupo con el NRC ingresado");
					}
					else if ((gAux->getCiclo()->getAnio() != actual->getAnio()) || (gAux->getCiclo()->getCiclo() != actual->getCiclo()))
					{
						imprimirCadena("Esta intentado matricular en un grupo de un ciclo que no es el actual");
					}
					else
					{
						string nomProfesor = global_profesores->buscarId(gAux->getID())->getNombreCompleto();
						cursoAux = global_cursos->buscaElCodigoCurso(gAux->getCodigo());
						if (cursoAux->getCantidad() > 0)
						{
							for (int i = 0; i < (cursoAux->getCantidad()); i++)
							{
								if (aux->getListaCursos()->buscarCodigoCurso(cursoAux->vec[i]) == false)
								{
									imprimirCadena("El estudiante no cuenta con los curso requisito de esta materia");
									requisitos = false;
									break;
								}
								else if (aux->getListaCursos()->buscaElCodigoCurso(cursoAux->vec[i])->getAprobado() == false)
								{
									imprimirCadena("El estudiante no ha los requisitos para esta materia");
									requisitos = false;
									break;
								}
								else
								{
									requisitos = true;
								}
							}

						}
						else if (aux->getListaCursos()->buscarAprobado(gAux->getCodigo()))
						{
							imprimirCadena("El estudiante ya aprobo este curso");
							requisitos = false;
						}
						else if (aux->getListaCursos()->buscarMatriculado(gAux->getCodigo()))
						{
							imprimirCadena("El estudiante ya matriculo este curso");
							requisitos = false;
						}
						if (requisitos == true)
						{
							gAux->getEstudiantes()->insertarFinal(aux);
							gAux->aumentar();
							curso_estudiante* nCurso = new curso_estudiante(gAux->getCodigo(), gAux->getNombre(), gAux->getCreditos(), 0, gAux->getNRC(), gAux->getNumeroGrupo(), nomProfesor, gAux->getCupo(), gAux->getCantidad(), gAux->getHoraInicio(), gAux->getHoraFinal(), gAux->getDias());
							nCurso->setCiclo(actual);
							aux->getListaCursos()->insertarFinal(nCurso);
							imprimirCadena("Matriculado exitosamente, informacion de la matricula: ");
							imprimirCadena(gAux->toString());
						}
					}
				}
			}
		}
	}
	else if (this->usuarioLogeado->getRol() == "usuario-registro" || this->usuarioLogeado->getRol() == "usuario-admin")
	{
		while (opc == 1)
		{
			imprimirCadena("Digite el ID del usuario al que se matriculara: ");
			id = leerCadena();
			aux = global_estudiantes->buscarId(id);
			if (aux == nullptr)
			{
				imprimirCadena("El id digitado no se encuentra registrado");
				imprimirCadena("Desea intentar ingresar de nuevo el id?");
				imprimirCadena("1.Si / 2.No");
				opc = leerSeleccion(3);
			}
			else
			{
				carr = aux->getCarrera();
				opc = 2;
				imprimirCadena("El periodo lectivo actual es: ");
				if (actual == nullptr)
				{
					imprimirCadena("No hay ciclos lectivos agregados por lo cual no se puede matricular ningun curso..");
				}
				else
				{
					cout << "Ciclo: " << actual->getCiclo() << endl;
					cout << "Annio: " << actual->getAnio() << endl;
					imprimirCadena("----------------------------------------------------------------");
					imprimirCadena("	Informe Matricula	");
					cout << "Carrera: " << carr << endl;
					cout << "Estudiante: " << aux->getNombreCompleto() << endl;
					if (global_Grupos->esVacia())
					{
						imprimirCadena("\nNo existen grupos creados");
					}
					else
					{
						imprimirCadena(global_Grupos->toStringIteradorCiclo(actual->getCiclo(), actual->getAnio()));
						imprimirCadena("\nDigite el NRC del grupo en el que desea matricularse: ");
						NRC = leerEntero();
						grupo* gAux = global_Grupos->buscarNRC(NRC);
						if (gAux == nullptr)
						{
							imprimirCadena("No existe un grupo con el NRC ingresado");
						}
						else if ( (gAux->getCiclo()->getAnio() != actual->getAnio()) || (gAux->getCiclo()->getCiclo() != actual->getCiclo()) )
						{
							imprimirCadena("Esta intentado matricular en un grupo de un ciclo que no es el actual");
						}
						else
						{
							string nomProfesor = global_profesores->buscarId(gAux->getID())->getNombreCompleto();
							cursoAux = global_cursos->buscaElCodigoCurso(gAux->getCodigo());
							if (cursoAux->getCantidad() > 0)
							{
								for (int i = 0; i < (cursoAux->getCantidad()); i++)
								{
									if (aux->getListaCursos()->buscarCodigoCurso(cursoAux->vec[i]) == false)
									{
										imprimirCadena("El estudiante no cuenta con los curso requisito de esta materia");
										requisitos = false;
										break;
									}
									else if (aux->getListaCursos()->buscaElCodigoCurso(cursoAux->vec[i])->getAprobado() == false)
									{
										imprimirCadena("El estudiante no ha los requisitos para esta materia");
										requisitos = false;
										break;
									}
									else
									{
										requisitos = true;
									}
								}

							}
							else if (aux->getListaCursos()->buscarAprobado(gAux->getCodigo()))
							{
								imprimirCadena("El estudiante ya aprobo este curso");
								requisitos = false;
							}
							else if (aux->getListaCursos()->buscarMatriculado(gAux->getCodigo()))
							{
								imprimirCadena("El estudiante ya matriculo este curso");
								requisitos = false;
							}
							if (requisitos == true)
							{
								gAux->getEstudiantes()->insertarFinal(aux);
								gAux->aumentar();
								curso_estudiante* nCurso = new curso_estudiante(gAux->getCodigo(), gAux->getNombre(), gAux->getCreditos(), 0, gAux->getNRC(), gAux->getNumeroGrupo(), nomProfesor, gAux->getCupo(), gAux->getCantidad(), gAux->getHoraInicio(), gAux->getHoraFinal(), gAux->getDias());
								nCurso->setCiclo(actual);
								aux->getListaCursos()->insertarFinal(nCurso);
								imprimirCadena("Matriculado exitosamente, informacion de la matricula: ");
								imprimirCadena(gAux->toString());
							}							
						}
					}
				}

			}
		}
	}
	else
	{
		imprimirCadena("No tiene el rol adecuado para acceder a esta opcion");
	}
	//---------------------------------------------------------

}

void sistema::visualizarNotitas()
{
	int NRC;
	int opc = 0;
	string id;
	if (usuarioLogeado->getRol()== "Usuario-Profesor")
	{
		string id = usuarioLogeado->getId();
		profesor* docente = global_profesores->buscarId(id);
		grupo* elgrupo = nullptr;
		imprimirCadena(global_Grupos->toString());
		imprimirCadena("----------------------------------");
		imprimirCadena("Digite el numero de NRC");
		NRC = leerEntero();
		while (!(docente->getGrupo()->buscarNRCD(NRC)))
		{
			imprimirCadena("Escribio de manera incorrecta el numero de NRC");
			int opc;
			imprimirCadena("Desea salir?");
			opc = leerEntero();
			if (opc == 1)
			{
				break;
			}
			imprimirCadena("Digite el numero de NRC");
			NRC = leerEntero();
		}
		if (opc != 1)
		{
			imprimirCadena("Notas del grupo:");
			if (docente->getGrupo() == nullptr)
			{
				imprimirCadena("Grupo Vacio");
			}
			else if (docente->getGrupo()->buscarNRC(NRC) == nullptr)
			{
				imprimirCadena("Grupo Vacio");
			}
			else
			{
				imprimirCadena(docente->getGrupo()->buscarNRC(NRC)->getListaNotas()->toString());
			}
		}
	}
	else
	{
		imprimirCadena(global_profesores->toString());
		imprimirCadena("----------------------------------");
		imprimirCadena("Digite el numero de cedula del profesor");
		id = leerCadena();
		profesor* docente = global_profesores->buscarId(id);
		while (!(global_profesores->buscarID(id)))
		{
			imprimirCadena("Escribio de manera incorrecta el numero de cedula profesor ");
			id = leerCadena();
		}
		imprimirCadena("----------------------------------");
		if (global_Grupos->esVacia())
		{
			imprimirCadena("No hay grupos");
		}
		else
		{
			imprimirCadena(global_Grupos->toString());
			imprimirCadena("----------------------------------");
			imprimirCadena("Digite el numero de NRC");
			NRC = leerEntero();
			while (!(docente->getGrupo()->buscarNRCD(NRC)))
			{

				imprimirCadena("Escribio de manera incorrecta el numero de NRC");
				imprimirCadena("Digite el numero de NRC");
				NRC = leerEntero();
			}
			imprimirCadena("Notas del grupo:");
			if (docente->getGrupo() == nullptr )
			{
				imprimirCadena("Grupo Vacio");
			}
			else if (docente->getGrupo()->buscarNRC(NRC) == nullptr)
			{
				imprimirCadena("Grupo Vacio");
			}
			else
			{
				imprimirCadena(docente->getGrupo()->buscarNRC(NRC)->getListaNotas()->toString());
			}
			
		}	
	}
	
}

void sistema::ingresoNotitas()
{
	limpiaPantalla();
	string idEst;
	int NRC;
	float notota;
	estudiante* estu = nullptr;
	string id;
	grupo* elgrupo = nullptr;
	profesor* docente = nullptr;
	if (this->usuarioLogeado->getRol() == "usuario-profesor")
	{
		docente = global_profesores->buscarId(this->usuarioLogeado->getId());
		if (docente == nullptr)
		{
			imprimirCadena("No se ha agregado este profesor a una carrera");
		}
		else
		{
			imprimirCadena("Sus cursos para este periodo son: ");
			imprimirCadena(lista_global->buscarId(id)->getNombreCompleto());
			imprimirCadena(global_Grupos->toStringProfesorCursos(global_ciclos->getUltimo()->getAnio(), global_ciclos->getUltimo()->getCiclo(), id));
			imprimirCadena("Ingrese NCR del grupo a ingresar notas: ");
			NRC = leerEntero();
			elgrupo = docente->getGrupo()->buscarNRC(NRC);
			if (elgrupo == nullptr)
			{
				imprimirCadena("Digito un NRC que no se encuentra en el sistema..");
				cin.get();
				limpiaPantalla();
				menuRegistro();

			}
			else
			{
				imprimirCadena(elgrupo->toStringEstudiantes());
				imprimirCadena("Digite el id del estudiante que desea ingresar su nota: ");
				idEst = leerCadena();

				if (!(elgrupo->getEstudiantes()->buscarID(idEst)))
				{
					imprimirCadena("Digito de manera incorrecta el numero de cedula");
				}
				else
				{
					imprimirCadena("Digite la nota que desea asignarle al Estudiante");
					notota = leerFlotante();
					nota* superNota = new nota(notota, idEst, lista_global->buscarId(idEst)->getNombreCompleto());
					elgrupo->getListaNotas()->insertarFinal(superNota);
					elgrupo->getEstudiantes()->buscarId(idEst)->getListaCursos()->buscarNRC(NRC)->setNota(notota);
					imprimirCadena(elgrupo->getListaNotas()->toString());
					imprimirCadena("Nota Ingresada Correctamente");
				}	
			}
		}
		
	}
	else
	{
		imprimirCadena("Digite el numero de cedula del profesor");
		id = leerCadena();
		profesor* docente = global_profesores->buscarId(id);
		if (docente == nullptr)
		{
			imprimirCadena("El profesor digitado no existe ");
		}
		else
		{
			imprimirCadena("Sus cursos para este periodo son: ");
			imprimirCadena(lista_global->buscarId(id)->getNombreCompleto());
			imprimirCadena(global_Grupos->toStringProfesorCursos(global_ciclos->getUltimo()->getAnio(), global_ciclos->getUltimo()->getCiclo(), id));
			imprimirCadena("Ingrese NCR del grupo a ingresar notas: ");
			NRC = leerEntero();
			elgrupo = docente->getGrupo()->buscarNRC(NRC);
			if (elgrupo == nullptr)
			{
				imprimirCadena("Digito un NRC que no se encuentra en el sistema..");
				cin.get();
				limpiaPantalla();
				menuRegistro();

			}
			else
			{
				imprimirCadena(elgrupo->toStringEstudiantes());
				imprimirCadena("Digite el id del estudiante que desea ingresar su nota: ");
				idEst = leerCadena();

				if (!(elgrupo->getEstudiantes()->buscarID(idEst)))
				{
					imprimirCadena("Digito de manera incorrecta el numero de cedula");
				}
				else
				{
					imprimirCadena("Digite la nota que desea asignarle al Estudiante");
					notota = leerFlotante();
					nota* superNota = new nota(notota, idEst, lista_global->buscarId(idEst)->getNombreCompleto());
					elgrupo->getListaNotas()->insertarFinal(superNota);
					elgrupo->getEstudiantes()->buscarId(idEst)->getListaCursos()->buscarNRC(NRC)->setNota(notota);
					imprimirCadena(elgrupo->getListaNotas()->toString());
					imprimirCadena("Nota Ingresada Correctamente");
				}
				
			}
		}
	}
}

void sistema::consultaPlan()
{
	carrera* ca;
	imprimirCadena(global_carrera->toString());
	imprimirCadena("Digite el codigo de la carrera: ");
	ca = global_carrera->buscarCodigoCarrera(leerEntero());
	if (ca != nullptr)
	{
		cout << "Carrera: " << ca->getNombre();
		cout << "| Tipo: " << ca->getGrado() << endl;;
		imprimirCadena("\nPlan de estudios: ");
		imprimirCadena(ca->getPlan()->toString());
	}
	else
	{
		cout << "No hay cursos agregados" << endl;
	}
	
}

void sistema::consultaGeneralMatricula()
{
	int codigoBusqueda;
	int ciclo;
	int anio;
	char a;
	float error = 0.0;
	carrera* car;
	imprimirCadena("Digite el codigo de la carrera: ");
	codigoBusqueda = leerEntero();
	try
	{
		car = global_carrera->buscarCodigoCarrera(codigoBusqueda);
		if (car == nullptr)
		{
			throw codigoBusqueda;
		}
	imprimirCadena("Digite el numero de ciclo (1,2 o 3) ");
	ciclo = leerSeleccion(4);
	imprimirCadena("Digite el anio del ciclo (ejemplo: 2010, 2018..)");
	anio = leerEntero();
	grupo* grupoA = global_Grupos->buscarGrupo(codigoBusqueda, anio, ciclo);
	grupo* grupoB;
	if (grupoA == nullptr)
	{
		throw 'a';
	}
	imprimirCadena(global_Grupos->buscarGrupoString(codigoBusqueda, anio, ciclo));
	imprimirCadena("Desea visualizar algun grupo?(1.Si , 2.No)..");
	int selec = leerSeleccion(3);
	if (selec == 1)
	{
		imprimirCadena("Digite el NRC del grupo que desea ver: ");
		int NRC = leerEntero();
		grupoB = global_Grupos->buscarNRC(NRC);
		if (grupoB == nullptr)
		{
			error = NRC;
			throw error;
		}
		else
		{
			imprimirCadena(grupoB->toStringEstudiantes());
		}
		
	}
	}
	catch (int zcodigoBusqueda)
	{
		cout << "El codigo " << codigoBusqueda << " no se encuentra en el sistema ";
	}
	catch (char a)
	{
		cout << "No existen grupos creados";
	}
	catch (float NRC)
	{
		cout << "El NRC " << NRC << " no se encuentra registrado";
	}
	
}

void sistema::consultaMatriculaPorEstudiante()
{
	int opc = 1;
	string id;
	estudiante* aux = nullptr;
	ciclo_lectivo* actual = global_ciclos->getUltimo();
	string carr;
	if (this->usuarioLogeado->getRol() == "usuario-estudiante")
	{
		id = this->usuarioLogeado->getId();
		aux = global_estudiantes->buscarId(id);
		carr = aux->getCarrera();
		if (aux == nullptr)
		{
			imprimirCadena("Error estudiante no se encuentra..");
		}
	}
	else if (this->usuarioLogeado->getRol() == "usuario-registro" || this->usuarioLogeado->getRol() == "usuario-admin")
	{
		imprimirCadena("Digite el id del estudiante que quiere verificar");
		id = leerCadena();
		aux = global_estudiantes->buscarId(id);
		while (opc == 1)
		{
			if (aux == nullptr)
			{
				imprimirCadena("El ID no ha sido encontrado");
				imprimirCadena("Desea intentar ingresar de nuevo el id?");
				imprimirCadena("1.Si / 2.No");
				opc = leerSeleccion(3);
			}
			else
			{
				imprimirCadena("Digite el anio del periodo lectivo");
				int anio = leerEntero();
				imprimirCadena("Digite el ciclo del periodo lectivo(1,2 o 3)");
				int ciclo = leerSeleccion(4);
				ciclo_lectivo* ciclito = nullptr;
				ciclito = global_ciclos->buscarCicloElectivo2(anio, ciclo);
				if (ciclito == nullptr)
				{
					imprimirCadena("El ciclo ingreso no existe..");
					imprimirCadena("Desea intentar de nuevo?");
					imprimirCadena("1.Si / 2.No");
					opc = leerSeleccion(3);
				}
				else
				{
					imprimirCadena(aux->getListaCursos()->toStringMateriasPorCiclo(ciclito->getAnio(), ciclito->getCiclo()));
					opc = 2;
				}
			}
		}

	}
}

void sistema::visualizarHistorial()
{
	int opc = 1;
	string id;
	estudiante* aux = nullptr;
	if (this->usuarioLogeado->getRol() == "usuario-estudiante")
	{
		id = this->usuarioLogeado->getId();
		aux = global_estudiantes->buscarId(id);
		if (aux == nullptr)
		{
			imprimirCadena("Error estudiante no se encuentra..");
		}
	}
	else if (this->usuarioLogeado->getRol() == "usuario-registro" || this->usuarioLogeado->getRol() == "usuario-admin")
	{
		imprimirCadena("Digite el id del estudiante que quiere verificar");
		id = leerCadena();
		aux = global_estudiantes->buscarId(id);
		while (opc == 1)
		{
			if (aux == nullptr)
			{
				imprimirCadena("El ID no ha sido encontrado");
				imprimirCadena("Desea intentar ingresar de nuevo el id?");
				imprimirCadena("1.Si / 2.No");
				opc = leerSeleccion(3);
			}
			else
			{
				imprimirCadena(aux->getListaCursos()->toString());
				opc = 2;
			}
		}
	}
}

void sistema::guardar()
{
	lista_global->save("Usuarios.txt");
	global_estudiantes->save("Estudiantes.txt");
	global_profesores->save("Profesores.txt");
	global_ciclos->save("Ciclos.txt");
	global_carrera->saveC("Carreras.txt", "Plan_carreras.txt");
	global_admin->save("Admins.txt");
	global_cursos->save("Cursos.txt");
	global_Grupos->save("Grupos.txt");

}

void sistema::recuperar()
{
	iterador<usuario>* iterador1 = new iterador<usuario>();
	iterador1->recuperarUser(lista_global,"Usuarios.txt" );
	//-----------------
	iterador<estudiante>* iterador2 = new iterador<estudiante>();
	iterador2->recuperarEst(global_estudiantes, "Estudiantes.txt");
	//-----------------
	iterador<profesor>* iterador3 = new iterador<profesor>();
	iterador3->recuperarPro(global_profesores, "Profesores.txt");
	//-----------------
	iterador<ciclo_lectivo>* iterador4 = new iterador<ciclo_lectivo>();
	iterador4->recuperaCiclos(global_ciclos, "Ciclos.txt");
	//-----------------
	iterador<curso>* iterador5 = new iterador<curso>();
	iterador5->recuperaCursos(global_cursos, "Cursos.txt");
	//-----------------
	iterador<carrera>* iterador6 = new iterador<carrera>();
	iterador6->recuperaCarrera(global_carrera,global_estudiantes, global_profesores,global_cursos,"Carreras.txt", "Plan_carreras.txt");
	//-----------------
	iterador<grupo>* iterador7 = new iterador<grupo>();
	iterador7->recuperarGrupo(global_Grupos, "Grupos.txt");
}