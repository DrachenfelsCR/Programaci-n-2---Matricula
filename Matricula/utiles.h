#ifndef UTILES_H
#define UTILES_H
#include<iostream>
#include<string>
#include<sstream>
#include <wchar.h>
#include <locale.h>
using namespace std;

void imprimirCadena(string);
void limpiaPantalla();
int leerEntero();
float leerFlotante();
char leerCaracter();
int leerSeleccion(int);
int letraCodigo(string);
void limpiaPantalla();
string leerCadena();
string leerCadenaNoVacia();
string leerCadenaNoGetLine();
string menuInicio();
string menuSeguridad();
string menuEscuelas();
string menuMatricula();
string menuMantenimiento();
string menuRegistro();
string LoginMenu();
bool stringSix(string);
bool stringUpperCase(string);
int convertirInt(string);
#endif // !UTILES_H