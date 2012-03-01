// dll_a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <conio.h>
#include "dlltest.h"
using namespace std;
void invert(stack_ptr,int);
int main() {
	stack_ptr stackPtr = NULL; /*Вказівник на вершину*/
	int choice, value;
	int n=0;
	instructions();
	cout<<"? ";
	cin>>choice;
	while (choice !=6) {
		switch (choice) {
		case 1: /*Занесення значення в стек*/ 
			cout<<"Enter an integer: ";
			cin>> value;
			push (&stackPtr, value);
			n++;
			printStack (stackPtr);
			break;
		case 2: /*Видалення значення із стеку*/
			if (!isEmpty(stackPtr))
				cout<<"The popped value is "<< pop(&stackPtr)<<endl; 
			n--;
			printStack(stackPtr);
			break;
		case 3: /*Видалення значення із стеку*/
			if (!isEmpty(stackPtr))
				cout<<"The peak "<< peak(&stackPtr)<<endl; ;
			printStack(stackPtr);
			break;
		case 4: /*Видалення значення із стеку*/
			del(&stackPtr);
			printStack(stackPtr);
			break;
		case 5:
			invert(stackPtr,n);
			//printStack(stackPtr);
			break;



		default:
		cout<<"Invalid choice."<<endl<<endl; instructions(); break; }
		cout<<"?"; 
		cin>> choice; }
		cout<<"End of run."<<endl;
return 0;
}
void invert(stack_ptr topPtr,int n){
	int *a=new int[n];
	for(int i=0;i<n;i++){
		a[i]=peak(&topPtr);
			pop(&topPtr);
	}
	for(int i=0;i<n;i++){
		push(&topPtr,a[i]);
		

	}
	printStack(topPtr);
	
}

