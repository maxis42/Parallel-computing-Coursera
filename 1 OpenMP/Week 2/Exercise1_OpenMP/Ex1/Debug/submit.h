#ifdef DLL_TEST_EXPORTS
#define test_submit_API __declspec(dllexport) 
#else
#define test_submit_API __declspec(dllimport) 
#endif

void test_submit_API Submit_Part1(float*(*test_function)(int, bool));
void test_submit_API Submit_Part2(float*(*test_function)(int, bool));
void test_submit_API Submit_test();