/**
 * @file	rpn.cpp
 * @brief	codigo fonte com a implementacao da funcao que  
 * 			calcula o valor de um derminada expressao
 *			escrita na notacao polonesa inversa 
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	29/10/2017
 * @date	29/10/2017
 */

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::atoi;
using std::exit;

#include "pilha.h"

#include <cstring>
using std::strlen;

#include "rpn.h"


/**
 * @brief Funcao que calcula o valor de um determinada 
 *		  expressao escrita na notacao polonesa inversa
 * @param expressao Expressao a ser calculada
 * @return o valor do calculo da expressao
 */
int calcValorExpressao(string expressao) {

	Pilha <int> pilha(3);

	int operador1;
	int operador2;
	int cont;

	char num[] = {'0','1','2','3','4','5','6','7','8','9'};

	for(int i = 0; i < (int)expressao.size(); i++) {
		cont = 0;
		if(expressao[i] == '+') {
			if(pilha.size() < 2) {
				cout << "Erro: A ordem dos paramentros e invalida." << endl;
				exit(1);
			}
			operador2 = pilha.top();
			pilha.pop();
			operador1 = pilha.top();
			pilha.pop();
			pilha.push(operador1 + operador2);
		}
		else if(expressao[i] == '-') {
			if(pilha.size() < 2) {
				cout << "Erro: A ordem dos paramentros e invalida." << endl;
				exit(1);
			}
			operador2 = pilha.top();
			pilha.pop();
			operador1 = pilha.top();
			pilha.pop();
			pilha.push(operador1 - operador2);
		}
		else if(expressao[i] == '*') {
			if(pilha.size() < 2) {
				cout << "Erro: A ordem dos paramentros e invalida." << endl;
				exit(1);
			}
			operador2 = pilha.top();
			pilha.pop();
			operador1 = pilha.top();
			pilha.pop();
			pilha.push(operador1 * operador2);
		}
		else if(expressao[i] == '/') {
			if(pilha.size() < 2) {
				cout << "Erro: A ordem dos paramentros e invalida." << endl;
				exit(1);
			}
			operador2 = pilha.top ();
			if(operador2 == 0) {
				cout << "Erro: na expressao existe uma divisao por 0(nao e possivel dividir por 0)." << endl;
				exit(1);
			}
			pilha.pop();
			operador1 = pilha.top();
			pilha.pop();
			pilha.push(operador1 / operador2);
		}
		else if(expressao[i] == ' ') {

		}
		else {
			for(int k = 0; k < 10; k++){
				char aux1 = expressao[i];
				char aux2 = num[k]; 
				if(aux1  == aux2) {
					cont++;
					break;
				}
			}
			
			if(cont != 1) {
				cout << "Erro: 1 ou mais paramentros invalidos." << endl;
				cout << "Programa finalizado." << endl;
				exit(1);
			}
			int valor = (int)expressao[i] - 48;
			pilha.push(valor);
		}
	}

	return pilha.top();
}