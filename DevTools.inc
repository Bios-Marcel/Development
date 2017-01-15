#define BENCHMARK(%0,%1,%2); \
	{\
	new startTick = GetTickCount();\
	for(new count = 0; count < %1; count++) %0;\
	new endTick = GetTickCount();\
	printf("%s: %dms in %d iterations", %2, endTick - startTick, %1);\
	}
	
// #define ASSERT(%0,%1); assertThat(#%0,%0,%1);

stock assertThat(title[], condition, expectedResult, bool:sendDefaultMessage = true)
{
	if(condition == expectedResult)
	{
		return true;
	}

	if(sendDefaultMessage)
	{
		printf("%s: Expected: %d Result: %d", title, expectedResult, condition);	
	}

	return false;
}

stock assertTrue(title[], condition, bool:sendDefaultMessage = true)
{
	if(condition)
	{
		return true;
	}

	if(sendDefaultMessage)
	{
		printf("%s: Expected: true Result: %d", title, boolToString(condition));
	}

	return false;
}

stock assertFalse(title[], condition, bool:sendDefaultMessage = true)
{
	if(!condition)
	{
		return true;
	}

	if(sendDefaultMessage)
	{
		printf("%s: Expected: false Result: %d", title, booLToString(condition);)	
	}

	return false;
}

stock boolToString(boolean)
{
	new string[6];
	string = boolean ? "true" : "false";
	return string;
}