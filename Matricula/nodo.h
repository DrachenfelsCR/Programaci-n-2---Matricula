#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<class T>
class nodo
{
	T* info;
	nodo<T>* sig;
public:
	nodo(T*);
	nodo<T>* getSig();
	T* getInfo();
	void setSig(nodo<T>* info);
};

template<class T>
nodo<T>::nodo(T* info)
{
	this->info = info;
	sig = NULL;
}

template<class T>
T* nodo<T>::getInfo() { return info; }

template<class T>
nodo<T>* nodo<T>::getSig()
{
	return sig;
}

template<class T>
void nodo<T>::setSig(nodo<T>* info) { sig = info; }
