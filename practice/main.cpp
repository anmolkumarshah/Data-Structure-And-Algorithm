#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node *prev;
};

class DoubleLinkedList{
	private:
		Node *first;
		Node *last;
	public:
		DoubleLinkedLIst(){
			this->first = NULL;
			this->last = NULL;
		}
		void insert(int key);
		void display();
};

void DoubleLinkedList::insert(int key){
	Node *temp = new Node;
	temp->data = key;
	temp->next = temp->prev = NULL;
	
	this->last = this->first->next;
	
	if(this->first == NULL){
		this->first = temp;
		temp->next = temp->prev = temp;
	}		
	else
	{
		while(last->next != first)
			last = last->next;
		temp->next = last->next;
		last->next = temp;
		temp->prev = last;
		this->first->prev = temp;	
	}
}

void DoubleLinkedList::display(){
	Node *p = this->last;
	do
	{
		cout<<p->data<<"\t";
		p = p->prev;
	}while(p != this->first && p->next);
}

int main(int argc, char** argv) {
	DoubleLinkedList list;
	list.insert(10);
//	list.insert(20);
//	list.insert(30);
//	list.insert(400);
//	list.insert(40);
	list.display();
	
	return 0;
}
