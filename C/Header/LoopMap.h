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
1: head 부분을 가리키고 있는 상태의 인덱스의 값을 가져온다
2: head배열에서 해당 값이 저장되있는 곳의 인덱스 값을 가져온다
3: 가져온 인덱스 값으로 tail배열에서 값을 가져온다
4: 값 리턴

tail to head => 위의 반대로



*/