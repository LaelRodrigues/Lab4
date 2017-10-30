#include <iostream>
#include "lista.h"
#include "listaordenada.h"

using std::string;
using std::cout;
using std::endl;


int main(int argc, char const *argv[])
{

	cout << "Testando a lista..." << endl;

	ListaOrdenada<int> lista1;
	cout << "Tamanho: " << lista1.size() << endl;
	lista1.InsereOrdenado(2);
	lista1.InsereOrdenado(10);
	lista1.InsereOrdenado(5);
	lista1.InsereOrdenado(6);
	lista1.InsereOrdenado(7);
	lista1.InsereOrdenado(9);
	lista1.InsereOrdenado(20);
	lista1.InsereOrdenado(13);
	lista1.InsereOrdenado(8);
	lista1.InsereOrdenado(19);

	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNaPosicao(3);
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNoInicio();
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNoFinal();
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	return 0;
}