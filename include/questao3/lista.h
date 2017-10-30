/**
 * @file	lista.h
 * @brief	Definicao de uma Classe Node e uma classe ListaLigada
 * 			para representar uma lista duplamente encadeada generica			
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	29/10/2017
 * @date	29/10/2017
 */

#ifndef LISTA_H
#define LISTA_H


#include <iostream>
#include <memory>

using namespace std;

template <typename T> class Node; 
template <typename T> 
std::ostream& operator<<( std::ostream&, Node<T> const & );

/**
 * @class   Node lista.h
 * @brief   Classe que representa um Node
 * @details Os atributos de um Node: valor, ponteiro para
 *			o proximo node e ponteiro para o node anterior
 */  
template <typename T>
class Node
{
private:
	T valor;						/**< Valor do node */
	shared_ptr<Node<T>> proximo;	/**< Ponteiro para o proximo node */
	shared_ptr<Node<T>> anterior;	/**< Ponteiro para o node anterior */
public:

	/** @brief Construtor padrao */
	Node();

	/** @brief Construtor parametrizado */
	Node(T _valor);

	/** @brief Destrutor padrao */
	~Node();

	/** @brief Construtor parametrizado com os ponteiros proximo e anterior */ 
	Node(T num, shared_ptr<Node> _proximo, shared_ptr<Node> _anterior);

	/** @brief Funcao que retorna o valor no node */
	T getValor();

	/** @brief Retorna o ponteiro para o proximo node */
	shared_ptr<Node<T>> getProximo();

	/** @brief Retorna o ponteiro para o node anterior */
	shared_ptr<Node<T>> getAnterior();

	/** @brief Modifica o ponteiro para o proximo node */
	void setProximo(shared_ptr<Node<T>> _proximo);

	/** @brief Modifica o ponteiro para o node anterior */
	void setAnterior(shared_ptr<Node<T>> _anterior);

	/** @brief Sobrecarga do operador de insercao em stream */
	friend std::ostream& operator<< <T>(std::ostream &o, Node<T> const &n);
};

template <typename T>

Node<T>::Node() : valor(), proximo(nullptr) {}

template <typename T>
/**
 * @param _valor elemento do node
 */
Node<T>::Node(T _valor) : valor(_valor), proximo(nullptr) {}

template <typename T>
Node<T>::~Node() {
	cout << "Node(" << valor << ") removido." << endl;
}

/**
 * @param _valor elemento do node
 * @param _proximo ponteiro para o proximo node
 * @param _anterior ponteiro para o node anterior
 */
template <typename T>
Node<T>::Node(T _valor, shared_ptr<Node<T>> _proximo, shared_ptr<Node<T>> _anterior )
 		: valor(_valor), proximo(_proximo), anterior(_anterior) {}

/** @return Retorna o valor do node */
template <typename T>
T Node<T>::getValor() {
	return valor;
}

/** @return Retorna o ponteiro para o proximo node */
template <typename T>
shared_ptr<Node<T>> Node<T>::getProximo() {
	return proximo;
}

/** @return Retorna o ponteiro para o node anterior */
template <typename T>
shared_ptr<Node<T>> Node<T>::getAnterior() {
	return anterior;
}

/** @param _proximo ponteiro para o proximo node */
template <typename T>
void Node<T>::setProximo(shared_ptr<Node<T>> _proximo) {
	proximo = _proximo;
}

/** @param _anterior ponteiro para o node anterior */
template <typename T>
void Node<T>::setAnterior(shared_ptr<Node<T>> _anterior) {
	anterior = _anterior;
}

/** 
 * @param o Referencia para stream de saida
 * @param n Referencia para um objeto Node
 * @return Referencia para stream de saida
 */
template <typename T>
std::ostream& operator<< (std::ostream &o, Node<T> const &n) {
	o << n.valor;
	return o;
}


template <typename T> class ListaLigada; 
template <typename T> 
std::ostream& operator<<( std::ostream&, ListaLigada<T> const & );


/* @class 	ListaLigada lista.h
 * @brief 	Classe que representa um lista duplamente encadeada
 * @details Os atributos da lista ligada: cabeca e cauda, que sao ponteiros
 *			genericos do tipo Node que apontam para a cabeca e cauda 
 * 			da lista respectivamente		
 */
template <typename T>
class ListaLigada {
	protected:
		shared_ptr<Node<T>> cabeca;		/**< Cabeca da lista  */
		shared_ptr<Node<T>> cauda;		/**< Cauda da lista */
		int tamanho;					/**< Tamanho da lista */

	public:
		/** @brief Construtor padrao */
		ListaLigada();
		/** @brief Destrutor padrao */
		~ListaLigada();

		/** @brief Insere no inicio da lista */
		bool InsereNoInicio(T _valor);

		/** @brief Insere no fim da lista */
		bool InsereNoFinal(T _valor);

		/** @brief Insere na posicao */
		bool InsereNaPosicao(int pos, T _valor);

		/** @brief Remove no inicio da lista */
		bool RemoveNoInicio();

		/** @brief Remove no fim da lista */
		bool RemoveNoFinal();

		/** @brief Remove no posicao */
		bool RemoveNaPosicao(int pos);

		/** @brief Retorna o tamanho da lista */
		int size();

		/** @brief Sobrecarga do operador de insercao em stream */
		friend std::ostream& operator<< <T>( std::ostream&, ListaLigada<T> const &l);
	};

//Construtor padrao
template <typename T>
ListaLigada<T>::ListaLigada(): cabeca(nullptr), cauda(nullptr), tamanho(0) {}

//Destrutor padrao
template <typename T>
ListaLigada<T>::~ListaLigada() {}

/**
 * @param _valor Valor do elemento da lista
 * @return true se o elemento foi adicionado com sucesso ou 
 		   false caso contrario
 */
template <typename T>
bool ListaLigada<T>::InsereNoInicio(T _valor) {
	auto novo = make_shared<Node<T>>(_valor);
	if (!novo) return false;

	if(cabeca == nullptr) {
		this->cabeca = novo;
		this->cauda = novo;	
		this->tamanho++;
	}
	else {
		novo->setAnterior(nullptr);
		novo->setProximo(this->cabeca);
		auto aux = novo->getProximo();
		aux->setAnterior(novo);
		this->cabeca = novo;
		this->tamanho++;
	}
	return true;
}

/**
 * @param _valor Valor do elemento da lista
 * @return true se o elemento foi adicionado com sucesso ou 
 		   false caso contrario
 */
template <typename T>
bool ListaLigada<T>::InsereNoFinal(T _valor) {
	if (this->cabeca == nullptr) {
		return InsereNoInicio(_valor);
	} else {
		auto atual = this->cabeca;
		while (atual->getProximo() != this->cauda && atual->getProximo() != nullptr)
			atual = atual->getProximo();
		
		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;

		novo->setAnterior(this->cauda);
		cauda->setProximo(novo);		
		novo->setProximo(nullptr);
		this->cauda = novo;
		this->tamanho++;
	}
	return true;
}

/**
 * @param pos Posicao onde o elemento sera adicionado
 * @param _valor Valor do elemento da lista
 * @return true se o elemento foi adicionado com sucesso ou 
 		   false caso contrario
 */
template <typename T>
bool ListaLigada<T>::InsereNaPosicao(int pos, T _valor) {
	
	if (pos<0) return false;
	if (pos==0)	return InsereNoInicio(_valor);

	auto atual = this->cabeca;
	int posAtual = 0;
	while (atual->getProximo() != this->cauda && posAtual < pos-1) {
		atual = atual->getProximo();
		posAtual++;
	}
	
	auto novo = make_shared<Node<T>>(_valor);
	if (!novo) return false;

	novo->setProximo(atual->getProximo());
	novo->setAnterior(atual);
	auto aux = atual->getProximo();
	aux->setAnterior(novo);
	atual->setProximo(novo);
	this->tamanho++;
	
	return true;
}

/**
 * @return true se o elemento foi removido com sucesso ou 
 		   false caso contrario
 */
template <typename T>
bool ListaLigada<T>::RemoveNoInicio() {
	if (this->cabeca==nullptr) return false;

	if(this->cabeca == this->cauda) {
		this->cabeca = nullptr;
		this->cauda = nullptr;
		this->tamanho--;
		return true;
	}
	cabeca = cabeca->getProximo();
	this->tamanho--;
	return true;
}

/**
 * @return true se o elemento foi removido com sucesso ou 
 		   false caso contrario
 */
template <typename T>
bool ListaLigada<T>::RemoveNoFinal() {

	if (this->cabeca==nullptr) return false;

	if (this->cabeca == this->cauda) {
		this->cabeca = nullptr;
		this->cauda = nullptr;
		this->tamanho--;
		return true;
	}

	auto atual = this->cabeca;
	while (atual->getProximo() != this->cauda)
		atual = atual->getProximo();
	this->cauda = atual;
	this->tamanho--;

	return true;
}

/**
 * @param pos Posicao do elemento que sera removido
 * @return true se o elemento foi removido com sucesso ou 
 		   false caso contrario
 */
template <typename T>
bool ListaLigada<T>::RemoveNaPosicao(int pos) {
	if (pos<0) return false;
	if (pos==0)	return RemoveNoInicio();

	auto atual = this->cabeca;
	int posAtual = 0;
	while (atual->getProximo()->getProximo() != this->cauda && posAtual < (pos-1)) {
		atual = atual->getProximo();
		posAtual++;
	}

	auto aux = atual->getProximo()->getProximo();
	aux->setAnterior(atual);
	atual->setProximo(aux);
	this->tamanho--;

	return true;
}

/** @return Retorna o tamanho da lista */
template <typename T>
int ListaLigada<T>::size() {
	return this->tamanho;
}

/** 
 * @param o Referencia para stream de saida
 * @param l Referencia para um objeto ListaLigada
 * @return Referencia para stream de saida
 */
template <typename T>
std::ostream& operator<< ( std::ostream& o, ListaLigada<T> const &l) {
	auto atual = l.cabeca;
	while (atual != nullptr) {
		o << atual->getValor() << " ";
		atual = atual->getProximo();
	}
	return o;
}

#endif