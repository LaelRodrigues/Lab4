/**
 * @file	pilha.h
 * @brief	Definicao e implementacao da classe pilha para
 *			representa uma pilha
 * @author	LaelRodrigues (laelrodrigues7@gmail.com)
 * @since	29/10/2017
 * @date	29/10/2017
 */	


#ifndef PILHA_H
#define PILHA_H	


/**
 * @class   Pilha pilha.h
 * @brief   Classe que representa um pilha
 * @details Os atributos de uma pilha sao: o vetor, o tamanho maximo
 *			e o tamanho corrente que aumenta a medida que os elementos 
 *			sao inseridos na pilha  
 */  
template <typename T>
class Pilha {
	private:

		/**< Representa o tamanho atual a medida que os elemento sao adicionados */
		int tam;

		/**< Vetor que armazena os elementos da pilha */
		T *vetor; 

		/**< Tamanho maximo que a pilha pode ter */
		int tamMax;

	public:

		/**< Construtor parametrizado */
		Pilha(int maximo);

		/**< Verifica se a pilha esta vazia */
		bool empty();

		/**< Verifica se a pilha esta cheia */
		bool full();

		/**< Adicionar elementos a pilha*/
		int push(T elemento);

		/**< Remove elementos do topo da pilha */
		int pop();

		/**< Retorna o topo da pilha */
		T top();

		/**< Retorna o tamanho da pilha */
		int size();	

		/**< Destrutor */	
		~Pilha();
};


/**
 * @param maximo Tamanho maximo da pilha 
 */
template <typename T>
Pilha <T>:: Pilha(int maximo) {
	vetor = new T[maximo];
	tam = 0;
	tamMax = maximo;
}


template <typename T>
bool Pilha <T>::empty(){ 
	if(tam == 0) {
		return true;
	}
	else {
		return false;
	}
}


template <typename T>
bool Pilha <T>::full(){ 
	if(tam == tamMax) {
		return true;
	}
	else {
		return false;
	}
}


/**
 * @details Caso o indice corrente seja igual ou maior ao tamanho
 *			maximo nao podera mais ser adicionado elementos
 * @param elemento Elemento a ser adicionado a pilha 
 * return O proximo indice onde o proximo elemento sera adicionado
 */
template<typename T>
int Pilha <T>:: push(T elemento) {
	if(full()){
		cout << "Erro ao inserir, pilha cheia." << endl;
		return tam;
	}
	vetor[tam] = elemento;
	return tam++;	
}


/**
 * @details Caso o indice corrente seja igual ou menor que zero
 *			nao podera mais ser removidos elementos 
 * @return O indice anterior que representa a posicao da pilha 
 *		   a ser removida
 */
template<typename T>
int Pilha <T>:: pop(){
	if(empty()){
		cout << "Erro ao remover , pilha vazia." << endl;
		return 0;
	}
	return tam--;
}


/**
 *@return O ultimo elemento da pilha 
 */
template<typename T>
T Pilha <T>:: top() {
	if(empty()) {
		cout << "Erro, acesso invalido ao elemento no topo, programa sera finalizado." << endl;
		exit(EXIT_FAILURE);
	}
	return vetor[tam-1];
}


/** @return O tamanho da pilha */
template <typename T>
int Pilha<T>::size() {
	return tam;
}


/** Destrutor da pilha */
template <typename T>
Pilha <T>:: ~Pilha(){
	delete [] vetor;
}

#endif

