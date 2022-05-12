#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include <fstream>
template<class T>
class lista
{
protected:
	int size;
	ifstream input;
	ofstream foutput;
	ofstream foutput2;
public:
	nodo<T>* primero;
	lista();
	bool esVacia();
	void insertarInicio(T*);
	void insertarFinal(T*);
	void insertarFinal(T);
	T* getUltimo();
	string toString();
	T* buscarCredenciales(string,string);
	bool buscar(T* aux);
	bool buscarElemento(int);
	void eliminarInicio();
	bool buscarCicloElectivo(int,int);
	bool buscarAprobado(string);
	bool buscarMatriculado(string);
	T* buscarCicloElectivo2(int, int);
	bool eliminarEspecifico(T*);
	bool buscarID(string);
	bool buscarNRCD(int);
	bool buscarCodigoCurso(string);
	bool buscarNombreCurso(string);
	T* buscaElCodigoCurso(string);
	T* buscarCodigoCarrera(int );
	bool buscarNombreCarrera(string);
	T* buscarId(string);
	T* buscarNRC(int);
	T* buscarGrupo(int,int,int);
	string buscarGrupoString(int, int, int);
	string toStringGrupo();
	string toStringIterador();
	string toStringProfesorCursos(int,int,string);
	string toStringIteradorCiclo(int,int);
	string toStringMateriasPorCiclo(int,int);
	string toStringSoloProfes();
	void save(string);
	void saveC(string,string);
	T* buscarT(T* aux);
	void cargarLista(lista<T>*, string);
	~lista();
};
//------------------------------------

template <class T>
lista<T>::lista() {
	primero = NULL;
	size = 0;
}

template<class T>
bool lista<T>::esVacia() {
	if (primero == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

template<class T>
void lista<T>::save(string fileName)
{
	foutput.open(fileName.c_str());
	if (foutput.good())
	{
		nodo<T>* actual = primero;
		while (actual != NULL)
		{
			(actual->getInfo())->save(foutput);
			actual = actual->getSig();
		}

	}
	foutput.close();
}

template<class T>
void lista<T>::saveC(string fileName, string fileName2)
{
	foutput.open(fileName.c_str());
	foutput2.open(fileName2.c_str());
	if (foutput.good())
	{
		nodo<T>* actual = primero;
		while (actual != NULL)
		{
			(actual->getInfo())->saveC(foutput, foutput2);
			actual = actual->getSig();
		}

	}
	foutput.close();
	foutput2.close();
}



template<class T>
void lista<T>::insertarInicio(T* dato) {
	nodo<T>* actual;
	actual = new nodo<T>(dato);
	actual->setSig(primero);
	primero = actual;
	size++;
}

template <class T>
void lista<T>::insertarFinal(T* dato) {
	nodo<T>* actual;
	actual = primero;
	if (esVacia()) {
		insertarInicio(dato);
	}
	else {
		while (actual->getSig() != NULL)
		{
			actual = actual->getSig();
		}
		actual->setSig(new nodo<T>(dato));
	}
}


template<class T>
void lista<T>::eliminarInicio() {
	nodo<T>* actual;
	actual = primero;
	if (primero == NULL)
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}

template<class T>
bool lista<T>::buscarCicloElectivo(int an, int ciclo)
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if ((actual->getInfo())->getAnio()== an && (actual->getInfo())->getCiclo()== ciclo)
		{
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
bool lista<T>::buscarAprobado(string codigo)
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if ((actual->getInfo())->getCodigo() == codigo && (actual->getInfo())->getAprobado())
		{
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
bool lista<T>::buscarMatriculado(string codigo)
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if ((actual->getInfo())->getCodigo() == codigo && (actual->getInfo())->getNota() == 0)
		{
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
T* lista<T>::buscarCicloElectivo2(int an, int ciclo)
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if ((actual->getInfo())->getAnio() == an && (actual->getInfo())->getCiclo() == ciclo)
		{
			return actual->getInfo();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

template<class T>
 bool lista<T>::buscarID(string ID)
{
	 nodo<T>* actual;
	 actual = primero;
	 while (actual)
	 {
		 if ((actual->getInfo())->getId() ==ID )
		 {
			 return true;
		 }
		 actual = actual->getSig();
	 }
	 return false;
}

 template<class T>
 inline bool lista<T>::buscarNRCD(int nrc)
 {
	 nodo<T>* actual;
	 actual = primero;
	 while (actual)
	 {
		 if ((actual->getInfo())->getNRC() == nrc)
		 {
			 return true;
		 }
		 actual = actual->getSig();
	 }
	 return false;
 }

 

template<class T>
 bool lista<T>::buscarCodigoCurso(string curso)
{
	 nodo<T>* actual;
	 actual = primero;
	 while (actual)
	 {
		 if ((actual->getInfo())->getCodigo() == curso)
		 {
			 return true;
		 }
		 actual = actual->getSig();
	 }
	 return false;
}

 template<class T>
 bool lista<T>::buscarNombreCurso(string nombre)
 {
	 nodo<T>* actual;
	 actual = primero;
	 while (actual)
	 {
		 if ((actual->getInfo())->getNombre() == nombre)
		 {
			 return true;
		 }
		 actual = actual->getSig();
	 }
	 return false;
 }

 template<class T>
 T* lista<T>::buscaElCodigoCurso(string cod)
	 {
		 nodo<T>* actual;
		 actual = primero;
		 while (actual)
		 {
			 if ((actual->getInfo())->getCodigo() == cod)
			 {
				 return actual->getInfo();
			 }
			 actual = actual->getSig();
		 }
		 return NULL;
	 }

template<class T>
T* lista<T>::buscarCodigoCarrera(int cod)
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if ((actual->getInfo())->getCodigo() == cod)
		{
			return actual->getInfo();
		}
		actual = actual->getSig();
	}
	return NULL;
}

template<class T>
bool lista<T>::buscarNombreCarrera(string nom)
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if ((actual->getInfo())->getNombre() == nom)
		{
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
bool lista<T>::buscar(T* aux)
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if ((*actual->getInfo()) == (*aux))
		{
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
T* lista<T>::buscarT(T* aux)
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if ((*actual->getInfo()) == (*aux))
		{
			return actual->getInfo();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

template<class T>
 bool lista<T>::buscarElemento(int dato)
{
	 nodo<T>* aux;
	 aux = primero;
	 while (aux)
	 {
		 if ((aux->getInfo())->getCodigo() == dato )
		 {
			 return true;

		 }
		 aux = aux->getSig();
	 }
	 return false;
}



template<class T>
T* lista<T>::buscarCredenciales(string usuario, string pass)
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if (((actual->getInfo())->getClave() == pass) && (actual->getInfo())->getNombreUsuario() == (usuario))
		{
			return actual->getInfo();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

template<class T>
string lista<T>::toString()
{
	stringstream s;
	if (primero != NULL)
	{
		nodo<T>* actual;
		actual = primero;
		while (actual != NULL)
		{
			s << actual->getInfo()->toString() << endl;
			s << "-------------------------" << endl;
			actual = actual->getSig();
		}
	}
	return s.str();
}

template<class T>
string lista<T>::toStringSoloProfes()
{
	stringstream s;
	if (primero != NULL)
	{
		nodo<T>* actual;
		actual = primero;
		while (actual != NULL)
		{
			if ((actual->getInfo())->getRol() == "usuario-profesor")
			{
				s << actual->getInfo()->toString() << endl;
				s << "-------------------------" << endl;
				actual = actual->getSig();
			}	
		}
	}
	return s.str();
}

template<class T>
string lista<T>::toStringMateriasPorCiclo(int anio, int ciclo)
{
	stringstream s;
	if (primero != NULL)
	{
		nodo<T>* actual;
		actual = primero;
		while (actual != NULL)
		{
			if (((actual->getInfo())->getCicloCurso()->getAnio() == anio) && ((actual->getInfo())->getCicloCurso()->getCiclo() == ciclo ))
			{
				s << actual->getInfo()->toString() << endl;
				s << "-------------------------" << endl;
			}
			actual = actual->getSig();
		}
	}
	return s.str();
}

template<class T>
T* lista<T>::buscarId(string id )
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if (((actual->getInfo())->getId() == id) )
		{
			return actual->getInfo();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

template <class T>
T* lista<T>::getUltimo() {
	nodo<T>* actual;
	actual = primero;
	if (esVacia()) {
		return nullptr;
	}
	else {
		while (actual->getSig() != NULL)
		{
			actual = actual->getSig();
		}
		return actual->getInfo();
	}
}

template<class T>
T* lista<T>::buscarNRC(int NRC)
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if ((actual->getInfo())->getNRC() == NRC)
		{
			return actual->getInfo();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

template<class T>
string lista<T>::toStringGrupo()
{
	stringstream s;
	nodo<T>* actual;
	actual = primero;	
		while (actual)
		{
			if (actual->getInfo() == nullptr)
			{
				s << "- - - - - - - - Vacio - - - - - - - - - -" << endl;
			}
			else
			{
				s << (actual->getInfo())->toString3() << endl;
				s << "-------------------------" << endl;
				actual = actual->getSig();
			}
		}
	return s.str();
}
template<class T>
string lista<T>::toStringIterador()
{
	stringstream s;
	nodo<T>* actual;
	actual = primero;
	while (actual->getSig() != nullptr)
	{
		if (actual->getInfo() != nullptr)
		{
			s << (actual->getInfo()) << endl;
		}
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
string lista<T>::toStringIteradorCiclo(int ciclo, int anio)
{
	stringstream s;
	nodo<T>* actual;
	actual = primero;
	while (actual != nullptr)
	{
		if ((actual->getInfo())->getCiclo()->getCiclo() == ciclo && (actual->getInfo())->getCiclo()->getAnio() == anio)
		{
			s << (actual->getInfo())->toString() << endl;
		}
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
T* lista<T>::buscarGrupo(int cod, int anio,int ciclo)
{
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if (((actual->getInfo())->getCodCarrera() == cod) && ((actual->getInfo())->getCiclo()->getAnio() == anio) && ((actual->getInfo())->getCiclo()->getCiclo() == ciclo))
		{
			return actual->getInfo();
		}
		actual = actual->getSig();
	}
	return NULL;
}

template<class T>
string lista<T>::buscarGrupoString(int cod, int anio, int ciclo)
{
	stringstream s;
	nodo<T>* actual;
	actual = primero;
	while (actual)
	{
		if (((actual->getInfo())->getCodCarrera() == cod) && ((actual->getInfo())->getCiclo()->getAnio() == anio) && ((actual->getInfo())->getCiclo()->getCiclo() == ciclo))
		{
			s << (actual->getInfo())->toString();
		}
		actual = actual->getSig();
	}
	return s.str();
}
template<class T>
string lista<T>::toStringProfesorCursos(int a, int c, string p)
{
	stringstream s;
	nodo<T>* actual = primero;
	actual = primero;
	while (actual)
	{
		s << "NRC" << "   " << "Codigo Curso" << "   " << "NombreCurso" << endl;
		if (actual->getInfo()->getCiclo()->getAnio() == a && actual->getInfo()->getCiclo()->getCiclo() == c && actual->getInfo()->getID() == p)
		{
			s << actual->getInfo()->toStringProfesorCurso() << endl;
		}
		actual = actual->getSig();
	}
	return s.str();
}

#endif // !LISTA_H
//