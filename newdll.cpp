// newdll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#define MAXMODULE 50
struct stackNode {/*структура, що посилається на себе*/
int data;//дані що заносяться у стек, *nextPtr вказівник на наступний елемент списку
struct stackNode *nextPtr;
	};
typedef struct stackNode node;
typedef node *stack_ptr;
using namespace std;
void invert(stack_ptr topPtr,int n);
void main() 
{
   HINSTANCE hLib=LoadLibrary("Dll_pruclad.dll");
    if(hLib==NULL) 
    {
       cout << "Unable to load library!" << endl;
       _getch();
       return;
    }

	char mod[MAXMODULE];
	 void (*p)(stack_ptr *, int);
	 void (*print)(stack_ptr );
	 int (*empty)(stack_ptr );
	 int (*pop)(stack_ptr *);
	  int (*peak)(stack_ptr *);
	  void (*instructions)(void);
	  void (*del)(stack_ptr *);
	GetModuleFileName((HMODULE)hLib,(LPTSTR)mod,MAXMODULE);
	cout<<"Library loaded: "<<mod<<endl;
	
	p= (void(*) (stack_ptr *, int))GetProcAddress(hLib,"push");
	print= (void(*) (stack_ptr ))GetProcAddress(hLib,"printStack");
	
	peak= (int(*) (stack_ptr *))GetProcAddress(hLib,"peak");
	pop= (int(*) (stack_ptr *))GetProcAddress(hLib,"pop");
	empty = (int(*) (stack_ptr ))GetProcAddress(hLib,"isEmpty");
	del = (void(*) (stack_ptr* ))GetProcAddress(hLib,"del");
	
	instructions = (void(*) (void ))GetProcAddress(hLib,"instructions");

	if((p == NULL)||(pop == NULL)||(peak == NULL)||(empty == NULL)||(print == NULL)||(instructions == NULL)||(del == NULL))
	{
		cout<<"Unable to load function(s)."<<endl;
		FreeLibrary((HMODULE)hLib);
		return;
	}
	stack_ptr stackPtr = NULL; /*Вказівник на вершину*/
	int choice, value;
	instructions();
	cout<<"? ";
	cin>>choice;
	int n=0;
	while (choice !=6) {
		switch (choice) {
		case 1: /*Занесення значення в стек*/ 
			cout<<"Enter an integer: ";
			cin>> value;
			p (&stackPtr, value);
			print (stackPtr);
			n++;
			break;
		case 2: /*Видалення значення із стеку*/
			if (!empty(stackPtr))
				cout<<"The popped value is "<< pop(&stackPtr)<<endl; ;
			print(stackPtr);
			n--;
			break;
		case 3: 
			if (!empty(stackPtr))
				cout<<"The peak "<< peak(&stackPtr)<<endl; ;
			break;
			case 4: /*Видалення значення із стеку*/
			del(&stackPtr);
			print(stackPtr);
			break;
		case 5:{
			invert(stackPtr,n);
			break;}

		default:
		cout<<"Invalid choice."<<endl<<endl; instructions(); break; }
		cout<<"?"; 
		cin>> choice; }
		cout<<"End of run."<<endl;
	FreeLibrary((HMODULE)hLib);
	_getch();
}
void invert(stack_ptr topPtr,int n){
	 HINSTANCE hLib=LoadLibrary("Dll_pruclad.dll");
	 int (*peak)(stack_ptr *);
	 peak= (int(*) (stack_ptr *))GetProcAddress(hLib,"peak");
	  int (*pop)(stack_ptr *);
	 pop= (int(*) (stack_ptr *))GetProcAddress(hLib,"pop");
	  void (*p)(stack_ptr *, int);
		p= (void(*) (stack_ptr *, int))GetProcAddress(hLib,"push");
	void (*print)(stack_ptr );
	print= (void(*) (stack_ptr ))GetProcAddress(hLib,"printStack");
	
	int *a=new int[n];
	for(int i=0;i<n;i++){
		a[i]=peak(&topPtr);
			pop(&topPtr);
	}
	for(int i=0;i<n;i++){
		p(&topPtr,a[i]);
		

	}
	print(topPtr);
	
}
