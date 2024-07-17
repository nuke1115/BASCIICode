#ifndef UNSIGNED_INT_STACK_HEADER
#define UNSIGNED_INT_STACK_HEADER

#include <stdlib.h>

void Push(struct UnsignedIntStack* stack, unsigned int item);
void Pop(struct UnsignedIntStack* stack);
unsigned int Peek(struct UnsignedIntStack* stack);

int UnsignedIntStackConstructor(struct UnsignedIntStack* stack, unsigned int size);
void UnsignedIntStackDestructor(struct UnsignedIntStack* stack);

struct UnsignedIntStack
{
	unsigned int* _InternalArray;
	void (*func_Push)(struct UnsignedIntStack* stack, unsigned int item);
	void (*func_Pop)(struct UnsignedIntStack* stack);
	void (*func_Destructor)(struct UnsignedIntStack* stack);
	unsigned int (*func_Peek)(struct UnsignedIntStack* stack);
	unsigned int _Index;
};
#endif // !UNSIGEND_INTSTACK_HEADER
