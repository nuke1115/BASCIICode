#ifndef UNSIGNED_INT_LOOPMAP_IMPLEMENT
#define UNSIGNED_INT_LOOPMAP_IMPLEMENT
#include "..\LoopMap.h"


void SetIndexOfHeadPoint(struct UnsignedIntLoopMap* map, unsigned int commandIndex)
{
	map->_ArrayOfHeadPoint[map->_Index] = commandIndex;

	if (map->_ArrayOfHeadPoint[map->_Index] != UINT_MAX && map->_ArrayOfTailPoint[map->_Index] != 0)
	{
		map->_Index++;
	}
}

void SetIndexOfTailPoint(struct UnsignedIntLoopMap* map, unsigned int commandIndex)
{
	map->_ArrayOfTailPoint[map->_Index] = commandIndex;

	if (map->_ArrayOfHeadPoint[map->_Index] != UINT_MAX && map->_ArrayOfTailPoint[map->_Index] != 0)
	{
		map->_Index++;
	}
}


unsigned int GetTailPointThroughHead(struct UnsignedIntLoopMap* map, unsigned int headPoint)
{
	unsigned int index = 0;
	for (; map->_ArrayOfHeadPoint[index] != headPoint; index++) {}

	return map->_ArrayOfTailPoint[index];
}

unsigned int GetHeadPointThroughTail(struct UnsignedIntLoopMap* map, unsigned int tailPoint)
{
	unsigned int index = 0;
	for (; map->_ArrayOfTailPoint[index] != tailPoint; index++) {}

	return map->_ArrayOfHeadPoint[index];
}

void UnsignedIntLoopMapDestructor(struct UnsignedIntLoopMap* map)
{
	if (map->_ArrayOfHeadPoint != NULL)
	{
		free(map->_ArrayOfHeadPoint);
	}

	if (map->_ArrayOfTailPoint != NULL)
	{
		free(map->_ArrayOfTailPoint);
	}
}

int UnsignedIntLoopMapConstructor(struct UnsignedIntLoopMap* map , unsigned int size)
{
	map->func_SetIndexOfHeadPoint = SetIndexOfHeadPoint;
	map->func_SetIndexOfTailPoint = SetIndexOfTailPoint;

	map->func_GetHeadPointThroughTail = GetHeadPointThroughTail;
	map->func_GetTailPointThroughHead = GetTailPointThroughHead;

	map->func_UnsignedIntLoopMapDestructor = UnsignedIntLoopMapDestructor;

	map->_Index = 0;

	map->_ArrayOfHeadPoint = NULL;
	map->_ArrayOfTailPoint = NULL;

	map->_ArrayOfHeadPoint = (unsigned int*)malloc(sizeof(unsigned int) * size);
	map->_ArrayOfTailPoint = (unsigned int*)malloc(sizeof(unsigned int) * size);

	if (map->_ArrayOfHeadPoint == NULL || map->_ArrayOfTailPoint == NULL)
	{
		puts("배열 할당 실패");
		return 1;
	}

	for (unsigned int i = 0; i < size; i++)
	{
		map->_ArrayOfHeadPoint[i] = UINT_MAX;
		map->_ArrayOfTailPoint[i] = 0;
	}

	return 0;
}


#endif // !UNSIGNED_INT_LOOPMAP_IMPLEMENT
/*
head값으로 tail의 값을 구하는법
1: 찾으려는 head값이 저장되있는 배열의 인덱스 번호를 가져온다
2: 그 인덱스 값으로 tail배열에서 값을 가져온다
3: 그 값을 리턴한다

tail to head => 위에서 head와 tail을 반대로



*/
