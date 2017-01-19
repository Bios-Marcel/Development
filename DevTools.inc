#define BENCHMARK(%0,%1,%2); \
	{\
	new startTick = GetTickCount();\
	for(new count = 0; count < %1; count++) %0;\
	new endTick = GetTickCount();\
	printf("%s: %dms in %d iterations", %2, endTick - startTick, %1);\
	}



new skipTest = 0;
#pragma unused skipTest
new actualTest[100] = "";
#pragma unused actualTest

#define SKIP_TEST skipTest = 1;

#define TEST_SUITE_START TEST_SUITE_START_EX()

#define TEST_SUITE_START_EX(%0) \
	format(actualTest, sizeof(actualTest), "%s", #%0); \
	if(!skipTest && printf("Running test suite: %s", #%0) == 0)\
	{

#define TEST_SUITE_END \
	}\
	else\
	{\
	if(strlen(actualTest) >= 1)\
	{\
	printf("Skipping test suite: %s", actualTest);\
	skipTest = 0;\
	}\
	}

#define ASSERT(%0(%1),%2) assertThat(#%0,%0(%1),%2)  

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