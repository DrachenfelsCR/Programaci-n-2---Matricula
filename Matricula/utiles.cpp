#include "utiles.h"
#include <string>
#include <cctype>
#include <algorithm>

void imprimirCadena(string cadena) {
	cout << cadena << endl;;
}
string leerCadena() {
	string x;
	cout << "\t";
	getline(cin, x);
	return x;
}

string leerCadenaNoVacia() {
	string x;
	cout << "\t";
	getline(cin, x);
	while (x.empty() || (x[0] == ' ')) {
		cout << "Ingrese algo.." << endl;
		getline(cin, x);
	}
	return x;
}

string leerCadenaNoGetLine() {
	string x;
	cout << "\t";
	cin >> x;
	cin.clear();
	cin.ignore(1024, '\n');
	while (x.empty() || (x[0] == ' ')) {
		cout << "Ingrese algo.." << endl;
		cin >> x;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	return x;
}


int leerEntero() {
	int n;
	while (true) {
		cout << "\t";
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cerr << "\t Valor incorrecto.. " << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

float leerFlotante() {
	float n;
	while (true) {
		cout << "\t";
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cerr << "\t Valor incorrecto.. " << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

char leerCaracter() {
	string line;
	char x;
	while (getline(cin, line) && (line.length() == 0 || line.length() > 1))
		cout << "Ingrese solo un caracter..." << endl;
	x = line[0];

	while ((isalpha(x) == 0)) {
		cout << "Dato invalido" << endl;
		while (getline(cin, line) && (line.length() == 0 || line.length() > 1))
			cout << "Ingrese solo un caracter..." << endl;
		x = line[0];
	}
	return x;
}

int leerSeleccion(int mayor) {
	int entrada = 0;
	while (true) {
		cout << "\t";
		if (cin >> entrada) {

			if (entrada <= mayor && entrada != 0) {
				cin.clear();
				cin.ignore(1024, '\n');
				return entrada;
			}
			else {
				cerr << "\t Valor incorrecto.. digite un numero entre 1 y " << mayor << endl;
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
		else {
			cerr << "\t Valor incorrecto.. digite un numero entre 1 y " << mayor << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

int numeroCodigo(string codigo) {
	string numero = "";
	int n = 0;
	int i;
	char caracter = ' ';
	int limite = (codigo.length());
	for (i = 2; i < limite; i++) {
		caracter = codigo[i];
		numero = numero + caracter;
		caracter = ' ';

	}

	n = stoi(numero);
	return n;
}

bool stringSix(string text)
{
	if (text.length() < 6)
	{
		return false;
	}
	return true;
}
bool stringUpperCase(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		if (isupper(text[i]))
		{
			return true;
		}
	}
	return false;
}
void limpiaPantalla() {
	system("cls");
}
string menuInicio() {
	stringstream s;
	s << endl;
	s << "\t ______________________________________________________________" << endl;
	s << "\t|                    Menu Principal                            |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	s << "\t|1.Seguridad y administracion de roles                         |" << endl;
	s << "\t|2.Mantenimiento General a Nivel de Registro                   |" << endl;
	s << "\t|3.Mantenimiento por Escuela                                   |" << endl;
	s << "\t|4.Matricula e Historiales                                     |" << endl;
	s << "\t|5.Registro de Actas                                           |" << endl;
	s << "\t|6.Salir                                                       |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	return s.str();
}

string menuSeguridad()
{
	stringstream s;
	s << endl;
	s << "\t ______________________________________________________________" << endl;
	s << "\t|             Seguridad y Adminstracion Roles                  |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	s << "\t|1.Crear Usuario                                               |" << endl;
	s << "\t|2.Mostrar Usuarios                                            |" << endl;
	s << "\t|3.Regresar al Menu Principal                                  |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	return s.str();
}

string menuEscuelas()
{
	stringstream s;
	s << endl;
	s << "\t ______________________________________________________________" << endl;
	s << "\t|                Mantenimiento por Escuelas                    |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	s << "\t|1.Consulta de Plan de Estudios Vigente por Carrera           |" << endl;
	s << "\t|2.Creacion de Grupos                                          |" << endl;
	s << "\t|3.Consulta General de Matricula                               |" << endl;
	s << "\t|4.Ingreso de Profesores                                       |" << endl;
	s << "\t|5.Mostrar Profesores                                          |" << endl;
	s << "\t|6.Regresar al Menu Principal                                  |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	return s.str();
}

string menuMatricula()
{
	stringstream s;
	s << endl;
	s << "\t ______________________________________________________________" << endl;
	s << "\t|                Matricula e Historiales                       |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	s << "\t|1.Proceso de Matricula                                        |" << endl;
	s << "\t|2.Consulta de matricula por Estudiante                        |" << endl;
	s << "\t|3.Historial Academico por Estudiante                          |" << endl;
	s << "\t|4.Regresar al Menu Principal                                  |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	return s.str();
}

string menuMantenimiento()
{
	stringstream s;
	s << endl;
	s << "\t ______________________________________________________________" << endl;
	s << "\t|         Menu Mantenimiento General a Nivel de Registro       |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	s << "\t|1.Ver Ciclos Lectivos                                         |" << endl;
	s << "\t|2.Ingresar Ciclos Lectivos                                    |" << endl;
	s << "\t|3.Ingreso de Nuevas Carreras                                  |" << endl;
	s << "\t|4.Ingresar Cursos                                             |" << endl;
	s << "\t|5.Empadronamiento de Estudiantes                              |" << endl;
	s << "\t|6.Mostrar Estudiantes Empadronados por Carrera                |" << endl;
	s << "\t|7.Regresar al Menu Principal                                  |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	return s.str();
}

string menuRegistro()
{
	stringstream s;
	s << endl;
	s << "\t ______________________________________________________________" << endl;
	s << "\t|                  Registro de Actas                           |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	s << "\t|1.Ingresar Notas                                              |" << endl;
	s << "\t|2.Visualizar Notas                                            |" << endl;
	s << "\t|3.Regresar al Menu Principal                                  |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	return s.str();
}

string LoginMenu() {
	stringstream s;
	s << endl;
	s << "\t ______________________________________________________________" << endl;
	s << "\t|                    Login de usuario al sistema               |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	
	return s.str();
}

int convertirInt(string s) {
	stringstream r(s);
	int v;
	r >> v;
	return v;
}