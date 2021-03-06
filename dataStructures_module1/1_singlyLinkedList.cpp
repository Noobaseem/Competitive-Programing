/*
 *	@author : Aseem Rastogi
 */

 #include <iostream>
 #include <cstdio>
 #include <cstdlib>

 using namespace std;

 /*
 	Declaring structure of a node
 	Here info contains data, next is pointer to next node and start is global pointer to first node
 */
 struct node {
 	int info;
 	struct node* next;
 }* start;

 /*Class declaration to define member funtions*/
 class single_llist {
 	public:
 		node* create_node(int);
 		void insert_begin();
 		void insert_pos();
 		void insert_last();
 		void delete_pos();
 		void sort();
 		void search();
 		void update();
 		void reverse();
 		void display();
 		//Constructor function
 		single_llist() {
 			start = NULL;
 		}
 };

 /*Method to create new nodes in singly linked list*/
 node* single_llist::create_node(int value) {
 	struct node* temp, *s;
 	temp = new(struct node);
 	if( temp == NULL ) {
 		cout<<"Memory not allocated";
 		return 0;
 	}else {
 		temp->info = value;
 		temp->next = NULL;
 		return temp;
 	}
 }

 /*Inserting a node in the begining*/
 void single_llist::insert_begin() {
 	int value;
 	cout<<"Enter the valuee to be inserted : ";
 	cin>>value;
 	struct node* temp, *p;
 	temp = create_node(value);
 	if( start == NULL ) }{
 		start = temp;
 		start->next = NULL;
 	}else {
 		p = start;
 		start = temp;
 		start->next = p;
 	}
 }

 /*Inserting a node at last*/
 void single_llist::insert_last() {
 	int value;
 	cout<<"Enter the value to be inserted : ";
 	cin>>value;
 	struct node* temp, *s;
 	temp = create_node(value);
 	s = start;
 	while( s->next != NULL ) {
 		s = s->next;
 	}
 	temp->next = NULL;
 	s->next = temp;
 	cout<<"Element inserted at last"<<endl;
 }

 //TODO:WRITE REMAINING FUNCTIONS AND MAIN FUNCTION