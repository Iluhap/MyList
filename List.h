#pragma once
#include <iostream>
using namespace std;
template <typename T>
class List
{
public:
	List();
	~List();

	int Size() { return size; }

	void push_back(T data);
	void push_front(T data);
	void push_by_index(T data, int index);

	void show_list();// Вывод списка на экран

	T& operator[](int index);

private:
	template <typename T>
	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;

		Node(T value, Node* next = nullptr, Node* prev= nullptr)
		{
			this->value = value;
			this->next = next;
			this->prev = prev;
		}
		~Node()
		{
		}

	};

	int size;
	Node<T>* head;
	Node<T>* tail;

};

/* 
	Реализация методов класса 
*/

template <typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}//Конструктор класса

template <typename T>
List<T>::~List()
{

}//Деструктор класса

template<typename T>
inline void List<T>::push_back(T data) // Добавление элемента в конец списка
{
	if (head == nullptr)//Если список пуст создаем новый Элемент
	{
		this->head = new Node<T>(data);
		this->tail = this->head;
	}
	else 
	{
		Node<T>* current = this->head;
		Node<T>* previous = nullptr;

		while (current->next != nullptr) // Доходим до конца списка и добавляем элемент в конце 
		{
			previous = current;
			current = current->next;
		}
		current->next = new Node<T>(data);

	}
	size++;
}

template<typename T>
inline void List<T>::push_front(T data) //Добавление в начало списка
{
	if (head == nullptr)//Если список пуст создаем новый Элемент
	{
		this->head = new Node<T>(data);
		this->tail = this->head;
	}
	else {
		Node<T>* pHead = this->head; // Создаем ссылку на прежнюю голову списка

		this->head = new Node<T>(data); //Создаем новый элемент списка
		this->head->next = pHead;
		pHead->prev = this->head;
	}
}

template<typename T>
inline void List<T>::push_by_index(T data, int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current->next != nullptr)
	{
		if(counter == index - 1)
		{
			Node<T>* tmp = new Node<T>(data);
			tmp->next = current->next;
			tmp->prev = current;
			current->next = tmp;
		}
		current = current->next;
		counter++;
	}
}

template<typename T>
inline void List<T>::show_list()
{
	Node<T>* current = this->head;

	while (current->next != nullptr)
	{
		cout << current->value << " -> ";
		current = current->next;
	}
	cout << current->value << ";" << endl;
}


template<typename T>
T& List<T>::operator[](int index) // Перегрузка оператора []
{
	Node<T>* current = this->head; 

	int counter = 0; // Счетчик для отслеживания элемента 

	while (current->next != nullptr)// Итерация с провекой на конец списка
	{
		if (counter == index)
		{
			return current->value;
		}
		current = current->next;
		counter++;
	}
}
