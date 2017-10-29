/**
 * @file	main.cpp
 * @brief	Arquivo corpo para a verificacao se uma palavra
 			e um palindromo ou nao
 * @author	LaelRodrigues (laelrodrigues7@gmail.com)
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

#include "pilha.h"


/** @brief Funcao principal */
int main(){

	string palindromo, direita, esquerda;

	cout << "Digite uma palavra: ";
	getline(cin, palindromo);

	Pilha <char> pilha(palindromo.size());

	string aux = palindromo;

	int cont;

	string acento = "âÂàÀáÁãÃêÊèÈéÉẽẼîÎìÌíÍõÕôÔòÒóÓüÜûÛúÚùÙçÇ";
    string s_acento = "aaaaaaaaeeeeeeeeiiiiiioooooooouuuuuuuucc";

    //remove acentos da string
	for(int i = 0; i < (int)palindromo.size(); i++) {
		cont = 0;
		for(int j = 0; j < (int)acento.size(); j += 2) {
			if(palindromo[i] == acento[j] && palindromo[i+1] == acento[j+1]) {
				cout << "ola" << endl;
				palindromo[i] = s_acento[cont];
				palindromo.erase((i+1), 1);
				break;
			}		
			cont++;
		}
	}

	//string que armazena os caracteres validos
	string caracteres = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};

	//descarta da string palindromo qualquer caractere que nao estaja no string acima 
	for(int i = 0; i < (int)palindromo.size(); i++) {
		cont = 0;
		for(int j = 0; j < 62; j++) {
			if(palindromo[i] == caracteres[j]) {
				cont++;
			}
		}
		if(cont == 0){
			palindromo.erase(i, 1);
			i--;
		}
	}

	//converter para minusculo os caracteres da string
	for(int i = 0; i < (int)palindromo.size(); i++) {
		palindromo[i] = tolower(palindromo[i]);
		pilha.push(palindromo[i]);
	}
	
	for(int i = 0; i < (int)palindromo.size()/2; i++) {
		direita[i] = palindromo[i];
		esquerda[i] = pilha.top();
		pilha.pop();
	}

	int contador = 0;
	for(int i = 0; i < (int)palindromo.size()/2; i++) {
		if(direita[i] == esquerda[i]) {
			contador++;
		}
	} 

	if(contador == (int)palindromo.size()/2) {
		cout << "A palavra(ou frase) '" << aux <<"' e um palindromo" << endl;
	}
	else {
		cout << "A palavra(ou frase) '" << aux << "' nao e palindromo" << endl;

	}
	return 0;
}
