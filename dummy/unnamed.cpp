#pragma once
#include "..\unnamed.h"
int EndsWith(string& target, string& suffix)
{
	size_t targetLength = target.length(), suffixLength = suffix.length();

	if (suffixLength <= 0)
	{
		return 2;
	}

	if (targetLength < suffixLength)
	{
		return 1;
	}

	for (int targetIndex = targetLength - suffixLength, suffixIndex = 0; targetIndex < targetLength; targetIndex++, suffixIndex++)
	{
		if (target[targetIndex] != suffix[suffixIndex])
		{
			return 3;
		}
	}

	return 0;
}