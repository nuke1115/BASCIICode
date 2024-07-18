#ifndef UNSIGNED_INT_STACK_IMPLEMENT
#define UNSIGNED_INT_STACK_IMPLEMENT

#include "..\Stack.h"


void UnsignedIntStackDestructor(struct UnsignedIntStack* stack)
{
	if (stack->_InternalArray != NULL)
	{
		free(stack->_InternalArray);
	}
}

int UnsignedIntStackConstructor(struct UnsignedIntStack* stack, unsigned int size)
{

	stack->func_Peek = Peek;
	stack->func_Pop = Pop;
	stack->func_Push = Push;

	stack->func_Destructor = UnsignedIntStackDestructor;

	stack->_Index = 0;
	stack->_InternalArray = (unsigned int*)malloc(sizeof(unsigned int) * size);

	if (stack->_InternalArray == NULL)
	{
		puts("스텍 배열 할당 실패");
		return 1;
	}

	for (unsigned int i = 0; i < size; i++)
	{
		stack->_InternalArray[i] = 0;
	}

	return 0;
}

void Push(struct UnsignedIntStack* stack, unsigned int item)
{
	stack->_InternalArray[stack->_Index] = item;
	stack->_Index++;
}

void Pop(struct UnsignedIntStack* stack)
{
	stack->_Index--;
}

unsigned int Peek(struct UnsignedIntStack* stack)
{
	return stack->_InternalArray[stack->_Index - 1];
}
#endif // !UNSIGNED_INT_STACK_IMPLEMENT
