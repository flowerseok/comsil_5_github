#include "LinkedList.h"


template <class ELEMENT>
class Stack :public LinkedList<ELEMENT> {
	public:
		virtual bool Delete (ELEMENT& element){
			
			if(this->first == 0) return false;

			Node<ELEMENT>* current = this->first;
			element = current->data;
			this->first = current->link;
			delete current;
			this->current_size--;
			


			return true;
			}
};
