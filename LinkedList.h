#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

template <class ELEMENT>
class Node{
	public:
		ELEMENT data;
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node *link;
		Node(ELEMENT element){
		  data = element;
		  link = 0;
		}
	};

template <class ELEMENT>
class LinkedList{
	protected:
		Node<ELEMENT>* first;
		int current_size;
	public:
		 
		LinkedList(){
			first = 0'
			current_size = 0;
		};

		
		int GetSize(){
			return current_size;
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(ELEMENT element);
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(ELEMENT &element);

		//리스트 출력
		void Print();
};

template <class ELEMENT>
void LinkedList<ELEMENT>::Insert(ELEMENT element) {
	Node<ELEMENT>* newnode = new Node<ELEMENT>(element);
	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first;
	first = newnode;
	current_size++;
}

template <class ELEMENT>
bool LinkedList<ELEMENT>::Delete(ELEMENT& element) {

	if (first == 0)
		return false;
	
	Node<ELEMENT>* current = first, * previous = 0;
	
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //마지막 노드를 찾는것
			if (previous)
				previous -> link = current -> link;
			else
				first = first -> link;
			break;
		}
		previous = current;
		current = current -> link;
	}
	element = current -> data;
	delete current;
	current_size--;

	return true;
}

template <class ELEMENT>
void LinkedList<ELEMENT>::Print() {
	Node<ELEMENT> *i;
	int index = 1;

	if (current_size != 0){
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){
				cout << "[" << index << "|";
				cout << i -> data <<"]->";
			}
			
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}


#endif
