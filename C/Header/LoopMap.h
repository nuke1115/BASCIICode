#ifndef UNSIGNED_INT_LOOPMAP_HEADER
#define UNSIGNED_INT_LOOPMAP_HEADER
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


void SetIndexOfHeadPoint(struct UnsignedIntLoopMap* map , unsigned int commandIndex);
void SetIndexOfTailPoint(struct UnsignedIntLoopMap* map , unsigned int commandIndex);

unsigned int GetTailPointThroughHead(struct UnsignedIntLoopMap* map,unsigned int headPoint);
unsigned int GetHeadPointThroughTail(struct UnsignedIntLoopMap* map,unsigned int tailPoint);

int UnsignedIntLoopMapConstructor(struct UnsignedIntLoopMap* map, unsigned int size);
void UnsignedIntLoopMapDestructor(struct UnsignedIntLoopMap* map);

struct UnsignedIntLoopMap
{
	unsigned int* _ArrayOfHeadPoint;
	unsigned int* _ArrayOfTailPoint;
	unsigned int (*func_GetTailPointThroughHead)(struct UnsignedIntLoopMap* map, unsigned int headPoint);
	unsigned int (*func_GetHeadPointThroughTail)(struct UnsignedIntLoopMap* map, unsigned int tailPoint);
	void (*func_SetIndexOfHeadPoint)(struct UnsignedIntLoopMap* map, unsigned int commandIndex);
	void (*func_SetIndexOfTailPoint)(struct UnsignedIntLoopMap* map, unsigned int commandIndex);
	void (*func_UnsignedIntLoopMapDestructor)(struct UnsignedIntLoopMap* map);
	unsigned int _Index;
};

#endif // !UNSIGNED_INT_LOOPMAP_HEADER