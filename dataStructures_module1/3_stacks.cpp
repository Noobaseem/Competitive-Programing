/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 	 Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct Stack{
	
	int capacity;
	int top;
	int *array;
};

Stack *createStack(int size){
	
	Stack *s = new Stack();
	s->capacity = size;
	s->top = -1;
	s->array = (int *)malloc(size*sizeof(int));
	
	if(s)
		return s;
		
	return NULL;
	
}

bool isStackFull(Stack *s){
	
	return (s->top == s->capacity - 1);
	
}

bool isStackEmpty(Stack *s){
	
		return (s->top == -1);
	
}
void push(Stack *s, int data){
	
	if(isStackFull(s)){
		
		cout<<"Stack full";
		return;
	}else{
			s->array[++(s->top)] =data;
	}
	
}

int pop(Stack *s){
	int data = 0 ;
	if(isStackEmpty(s)){
		cout<<"Stack Empty"<<endl;
		return 0;
	}else{
		
		data = (s)->array[(s)->top--];
		
	}
	return data;
}

int top(Stack *s){
	
	if(isStackEmpty(s))
		return -1;
	return (s->array[s->top]);
}

void printStack(Stack *s){
	
	int x = s->top;
	while(!isStackEmpty(s) && x >= 0){
		cout<<s->array[x--]<<endl;
	}
}
int main(){
	
	Stack *s = createStack(10);
	printStack(s);
	push(s,10);
	push(s,11);
	//printStack(s);
	push(s,91);
	printStack(s);
	pop(s);
	cout<<s->top;
	return 0;
}
