/**
 * @file	listaordenada.h
 * @brief	Definicao de uma uma classe ListaOrdenada para
 * 			representar uma lista duplamente encadeada ordenada generica			
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	29/10/2017
 * @date	29/10/2017
 */

#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "lista.h"

template <typename T> class ListaOrdenada; 
template <typename T> 
std::ostream& operator<<( std::ostream&, ListaLigada<T> const & );

/* @class 	ListaOrdenada lista.h
 * @brief 	Classe que representa um lista duplamente encadeada ordenada
 * @details Os atributos da lista ordenada: cabeca e cauda, que sao ponteiros
 *			genericos do tipo Node que apontam para a cabeca e cauda 
 * 			da lista respectivamente		
 */

template <typename T>
class ListaOrdenada : public ListaLigada<T> {
	public:
		/** @brief Construtor padrao */
		ListaOrdenada();

		/** @brief Destrutor padrao */
		~ListaOrdenada();

		/** @brief Insere ordenado na lista */
		bool InsereOrdenado(T _valor);
	};

template <typename T>
ListaOrdenada<T>::ListaOrdenada() {
}

//Destrutor padrao
template <typename T>
ListaOrdenada<T>::~ListaOrdenada() {}

template <typename T>
bool ListaOrdenada<T>::InsereOrdenado(T _valor) {

	auto iterador = this->cabeca;
	auto novoNode = make_shared<Node<T>>(_valor);
	if (!novoNode) return false;

	if(this->cabeca == NULL && this->cauda == NULL){
		this->cabeca = novoNode;
		this->cauda = novoNode;
		novoNode->setProximo(nullptr);
		novoNode->setAnterior(nullptr);
		this->tamanho++;
	}

	else {

		while(iterador && _valor > iterador->getValor() && iterador->getProximo()) {
			iterador = iterador->getProximo();
		}
		if(iterador == this->cabeca && _valor < iterador->getValor()) {

			iterador->setAnterior(novoNode);
			novoNode->setProximo(iterador);
			novoNode->setAnterior(nullptr);
			this->cabeca = novoNode;
			this->tamanho++;
		}

		else if(iterador == this->cauda && _valor > this->cauda->getValor()) {
			(this->cauda)->setProximo(novoNode);
			((this->cauda)->getProximo())->setAnterior(this->cauda);
			this->cauda = (this->cauda)->getProximo();
			(this->cauda)->setProximo(nullptr);
			this->tamanho++;
		}

		else {
			novoNode->setProximo(iterador);
			(iterador->getAnterior())->setProximo(novoNode);
			novoNode->setAnterior(iterador->getAnterior());
			iterador->setAnterior(novoNode);
			this->tamanho++;
		}
	} 
	return true;
}

#endif