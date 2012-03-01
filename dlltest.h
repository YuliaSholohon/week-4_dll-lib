#include "stdafx.h"
#ifndef _DLLTEST_H_
#define _DLLTEST_H_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

extern "C"{
	 struct stackNode {/*структура, що посилається на себе*/
int data;//дані що заносяться у стек, *nextPtr вказівник на наступний елемент списку
struct stackNode *nextPtr;
	};
}
 extern "C" __declspec(dllexport)typedef struct stackNode node;
 extern "C" __declspec(dllexport)typedef node *stack_ptr;

extern "C" __declspec(dllexport) void push(stack_ptr *, int);
extern "C" __declspec(dllexport) int pop(stack_ptr *);
extern "C" __declspec(dllexport) int peak(stack_ptr *);
extern "C" __declspec(dllexport) int isEmpty(stack_ptr);
extern "C" __declspec(dllexport) void printStack(stack_ptr);
extern "C" __declspec(dllexport) void instructions(void);
extern "C" __declspec(dllexport)void del(stack_ptr *);

#endif