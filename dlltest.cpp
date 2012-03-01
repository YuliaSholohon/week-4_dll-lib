#include "dlltest.h"
#include <string>

using namespace std;

extern "C" __declspec(dllexport) void instructions(void)
{
	cout<<"Enter choice:\n"
		"1 to push a value on the stack\n"
		"2 to pop a value off the stack\n"
		"3 peak of the stack\n"
		"4 delete all elements\n"
		"5 invert\n"
		"6 end of the program\n"; }
/*Занесення нового значення у вершинку стеку*/
extern "C" __declspec(dllexport) void push (stack_ptr *topPtr, int info)
{	
	stack_ptr newPtr;
	newPtr =new node;//виведення пам'яті для вузла
	if (newPtr != NULL) {
		newPtr->data = info;// нове значення поступає на вершину стеку
		newPtr->nextPtr = *topPtr;//newPtr показує на попереднє значення
		*topPtr = newPtr;// тепер *topPtr показує на нове значення
	} else
			cout<<info<<" not inserted. No memory available."<<endl; 
}
/*Видалення вузла на вершині стеку*/
extern "C" __declspec(dllexport) int pop(stack_ptr *topPtr)
{
	stack_ptr tempPtr;
	int popValue;
	tempPtr = *topPtr;//дані про зміннц що треба видалити(значення, адреса)
	popValue = (*topPtr)->data;// значення що потрібно видалити
	*topPtr = (*topPtr)->nextPtr;// вершина переходить у наступне значення
	delete tempPtr; //видалення вершини
	tempPtr=NULL;
	return popValue; 
}
/*Друк стеку*/
extern "C" __declspec(dllexport) void printStack(stack_ptr currentPtr)
{ 	
	if (currentPtr == NULL)
	cout<<"The stack is empty."<<endl<<endl;
	else {
		cout<<"The stack is:"<<endl;
		while (currentPtr != NULL)
		{
			cout<<currentPtr->data<<"-->";
			currentPtr = currentPtr->nextPtr;}
		cout<<"NULL"<<endl<<endl; 
	} 
}
/*Перевірка чи пустий стек*/
extern "C" __declspec(dllexport) int isEmpty(stack_ptr topPtr)
{	
	return topPtr == NULL;//якщо вершина показує на 0 значить стек пустий
}
extern "C" __declspec(dllexport)int peak(stack_ptr *topPtr){
	stack_ptr tempPtr;
	int peak;
	tempPtr = *topPtr;//дані про зміннц що треба видалити(значення, адреса)
	peak = (*topPtr)->data;
	return peak;
}
extern "C" __declspec(dllexport)void del(stack_ptr *topPtr)
{
	stack_ptr tempPtr;
	int popValue;
	while(*topPtr!=NULL){
	tempPtr = *topPtr;//дані про зміннц що треба видалити(значення, адреса)
	popValue = (*topPtr)->data;// значення що потрібно видалити
	*topPtr = (*topPtr)->nextPtr;// вершина переходить у наступне значення
	free(tempPtr); 
	}//

}