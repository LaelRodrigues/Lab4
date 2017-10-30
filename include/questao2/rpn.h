/**
 * @file	rpn.h
 * @brief	Declaracao dos prototipo da funcao que  
 * 			calcular o valor de um derminada expressao
 *			escrita na notacao polonesa inversa 
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	29/10/2017
 * @date	29/10/2017
 */

#ifndef RPN_H
#define RPN_H

#include <string>
using std::string;


/**
 * @brief Funcao que calcula o valor de um determinada 
 *		  expressao escrita na notacao polonesa inversa
 * @param tam quantidade de argumentos da expressao
 * @param argumentos elementos que compoem a expressao
 * @return o valor do calculo da expressao
 */
int calcValorExpressao(string expressao);

#endif