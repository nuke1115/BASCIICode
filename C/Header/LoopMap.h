#ifndef UNSIGNED_INT_LOOPMAP_HEADER
#define UNSIGNED_INT_LOOPMAP_HEADER
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


void SetIndexOfHeadPoint(struct unsignedIntLoopMap* map , unsigned int commandIndex);
void SetIndexOfTailPoint(struct unsignedIntLoopMap* map , unsigned int commandIndex);

unsigned int GetTailPointThroughHead(struct unsignedIntLoopMap* map,unsigned int headPoint);
unsigned int GetHeadPointThroughTail(struct unsignedIntLoopMap* map,unsigned int tailPoint);

int UnsignedIntLoopMapConstructor(struct unsignedIntLoopMap* map, unsigned int size);
void UnsingedIntLoopMapDestructor(struct unsignedIntLoopMap* map);

struct unsignedIntLoopMap
{
	unsigned int* _ArrayOfHeadPoint;
	unsigned int* _ArrayOfTailPoint;
	void (*func_SetIndexOfHeadPoint)(struct unsignedIntLoopMap* map, unsigned int commandIndex);
	void (*func_SetIndexOfTailPoint)(struct unsignedIntLoopMap* map, unsigned int commandIndex);
	unsigned int (*func_GetTailPointThroughHead)(struct unsignedIntLoopMap* map,unsigned int headPoint);
	unsigned int (*func_GetHeadPointThroughTail)(struct unsignedIntLoopMap* map,unsigned int tailPoint);
	void (*func_UnsingedIntLoopMapDestructor)(struct unsignedIntLoopMap* map);
	unsigned int _Index;
};

#endif // !UNSIGNED_INT_LOOPMAP_HEADER
/*
head to tail => 
1: head �κ��� ����Ű�� �ִ� ������ �ε����� ���� �����´�
2: head�迭���� �ش� ���� ������ִ� ���� �ε��� ���� �����´�
3: ������ �ε��� ������ tail�迭���� ���� �����´�
4: �� ����

tail to head => ���� �ݴ��



*/