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
/*��������� ������ �������� � �������� �����*/
extern "C" __declspec(dllexport) void push (stack_ptr *topPtr, int info)
{	
	stack_ptr newPtr;
	newPtr =new node;//��������� ���'�� ��� �����
	if (newPtr != NULL) {
		newPtr->data = info;// ���� �������� ������� �� ������� �����
		newPtr->nextPtr = *topPtr;//newPtr ������ �� �������� ��������
		*topPtr = newPtr;// ����� *topPtr ������ �� ���� ��������
	} else
			cout<<info<<" not inserted. No memory available."<<endl; 
}
/*��������� ����� �� ������ �����*/
extern "C" __declspec(dllexport) int pop(stack_ptr *topPtr)
{
	stack_ptr tempPtr;
	int popValue;
	tempPtr = *topPtr;//��� ��� ����� �� ����� ��������(��������, ������)
	popValue = (*topPtr)->data;// �������� �� ������� ��������
	*topPtr = (*topPtr)->nextPtr;// ������� ���������� � �������� ��������
	delete tempPtr; //��������� �������
	tempPtr=NULL;
	return popValue; 
}
/*���� �����*/
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
/*�������� �� ������ ����*/
extern "C" __declspec(dllexport) int isEmpty(stack_ptr topPtr)
{	
	return topPtr == NULL;//���� ������� ������ �� 0 ������� ���� ������
}
extern "C" __declspec(dllexport)int peak(stack_ptr *topPtr){
	stack_ptr tempPtr;
	int peak;
	tempPtr = *topPtr;//��� ��� ����� �� ����� ��������(��������, ������)
	peak = (*topPtr)->data;
	return peak;
}
extern "C" __declspec(dllexport)void del(stack_ptr *topPtr)
{
	stack_ptr tempPtr;
	int popValue;
	while(*topPtr!=NULL){
	tempPtr = *topPtr;//��� ��� ����� �� ����� ��������(��������, ������)
	popValue = (*topPtr)->data;// �������� �� ������� ��������
	*topPtr = (*topPtr)->nextPtr;// ������� ���������� � �������� ��������
	free(tempPtr); 
	}//

}