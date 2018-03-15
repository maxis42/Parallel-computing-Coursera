#ifdef SUBMIT_EXPORTS
#define test_submit_API __declspec(dllexport) 
#else
#define test_submit_API __declspec(dllimport) 
#endif

void test_submit_API Submit_Part1(int N, double eps, int(*test_function)(double**, double**, int, double));
void test_submit_API Submit_Part2(int(*test_function)(double** , double** , int , double ));
void test_submit_API Submit_test();