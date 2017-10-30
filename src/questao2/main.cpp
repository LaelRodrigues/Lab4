/**
 * @file	main3.cpp
 * @brief	Codigo fonte de teste da funcao que calcula o
 *			valor de uma determinada expressao escrita na 
 *			notacao polonesa inversa
 * @author	LaelRodrigues (laelRodrigues7@gmail.com)
 * @since	29/10/2017
 * @date	29/10/2017
 */


#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;
using std::getline;

#include "rpn.h"

/** @brief Funcao principal */
int main() {

	string expressao;
	cout << "Digite a expressao: ";
	getline(cin,expressao);

	int result = calcValorExpressao(expressao);
	cout << "O valor resultante da expressao e: " << result << endl;
	return EXIT_SUCCESS;


	return 0;
}