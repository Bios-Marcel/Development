#define BENCHMARK(%0,%1,%2); \
	{\
	new start = GetTickCount();\
	for(new count = 0; count < %1; count++)\
	{\
		%0;\
	}\
	printf("%s: %dms in %d iterations", %2, GetTickCount() - start, %1);\
	}

assertThat(title[], condition, expectedResult)
{
	if(condition == expectedResult)
	{
		return true;
	}

	printf("%s: Expected: %d Result: %d", title, expectedResult, condition);	
	return false;
}