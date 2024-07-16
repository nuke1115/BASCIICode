#ifndef UNSIGNED_INT_LOOPMAP_IMPLEMENT
#define UNSIGNED_INT_LOOPMAP_IMPLEMENT
#include "..\LoopMap.h"


void SetIndexOfHeadPoint(struct unsignedIntLoopMap* map, unsigned int commandIndex)
{
	map->_ArrayOfHeadPoint[map->_Index] = commandIndex;

	if (map->_ArrayOfHeadPoint[map->_Index] != UINT_MAX && map->_ArrayOfTailPoint[map->_Index] != 0)
	{
		map->_Index++;
	}
}

void SetIndexOfTailPoint(struct unsignedIntLoopMap* map, unsigned int commandIndex)
{
	map->_ArrayOfTailPoint[map->_Index] = commandIndex;

	if (map->_ArrayOfHeadPoint[map->_Index] != UINT_MAX && map->_ArrayOfTailPoint[map->_Index] != 0)
	{
		map->_Index++;
	}
}


unsigned int GetTailPointThroughHead(struct unsignedIntLoopMap* map, unsigned int headPoint)
{
	unsigned int index;
	for (index = 0; map->_ArrayOfHeadPoint[index] != headPoint; index++) {}

	return map->_ArrayOfTailPoint[index];

}

unsigned int GetHeadPointThroughTail(struct unsignedIntLoopMap* map, unsigned int tailPoint)
{
	unsigned int index;
	for (index = 0; map->_ArrayOfTailPoint[index] != tailPoint; index++){}

	return map->_ArrayOfHeadPoint[index];

}

void UnsingedIntLoopMapDestructor(struct unsignedIntLoopMap* map)
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

int UnsignedIntLoopMapConstructor(struct unsignedIntLoopMap* map , unsigned int size)
{
	map->func_SetIndexOfHeadPoint = SetIndexOfHeadPoint;
	map->func_SetIndexOfTailPoint = SetIndexOfTailPoint;

	map->func_GetHeadPointThroughTail = GetHeadPointThroughTail;
	map->func_GetTailPointThroughHead = GetTailPointThroughHead;
	map->func_UnsingedIntLoopMapDestructor = UnsingedIntLoopMapDestructor;
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
head to tail =>
1: head 부분을 가리키고 있는 상태의 인덱스의 값을 가져온다
2: head배열에서 해당 값이 저장되있는 곳의 인덱스 값을 가져온다
3: 가져온 인덱스 값으로 tail배열에서 값을 가져온다
4: 값 리턴

tail to head => 위의 반대로



*/
