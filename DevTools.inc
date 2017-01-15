#define BENCHMARK(%0,%1,%2); \
	{\
		new startTick = GetTickCount();\
		for(new count = 0; count < %1; count++) %0;\
		new endTick = GetTickCount();\
		printf("%s: %dms in %d iterations", %2, endTick - startTick, %1);\
	}  

#define ASSERT(%0,%1) assertThat("" # %0,%0,%1)

stock assertThat(title[], condition, expectedResult)
{
	if(condition == expectedResult)
	{
		return true;
	}

	printf("%s: Expected: %d Result: %d", title, expectedResult, condition);	
	return false;
}