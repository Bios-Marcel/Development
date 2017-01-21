#define BENCHMARK(%0,%1,%2) \
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
	format(actualTest, sizeof(actualTest), "%s", #%0), print(" ");\
	if(!skipTest && printf("Running test suite: %s", #%0) == 0)\
	{

#define TEST_SUITE_END \
	}\
	else\
	{\
	if(strlen(actualTest) >= 1)\
	{\
	printf("Skipping test suite: %s", actualTest);\
	print(" ");\
	skipTest = 0;\
	}\
	}

#define ASSERT_NO_PARAM(%0,%1) assertThat(#%0,%0,%1)  
#define ASSERT(%0(%1),%2) assertThat(#%0,%0(%1),%2)  
#define ASSERT_STRING(%0(%1),%2) assertString(#%0,%0(%1),#%2)  
#define ASSERT_TRUE(%0(%1)) assertTrue(#%0,%0(%1))  
#define ASSERT_FALSE(%0(%1)) assertFalse(#%0,%0(%1))  

stock assertThat(title[], result, expectedResult)
{
	if(result == expectedResult)
	{
		printf("%s: Pass", title);
		return true;
	}

	printf("%s: Fail | Expected: %d | Result: %d", title, expectedResult, result);	

	return false;
}

stock assertString(title[], result[], expectedResult[])
{
	if(!strcmp(result, expectedResult))
	{
		printf("%s: Pass", title);
		return true;
	}

	printf("%s: Fail | Expected: %s | Result: %s", title, expectedResult, result);	

	return false;
}


stock assertTrue(title[], result)
{
	if(result)
	{
		printf("%s: Pass", title);
		return true;
	}

	printf("%s: Fail | Expected: true | Result: false", title);

	return false;
}

stock assertFalse(title[], result)
{
	if(!result)
	{
		printf("%s: Pass", title);
		return true;
	}

	printf("%s: Fail |Expected: false | Result: true", title);	

	return false;
}