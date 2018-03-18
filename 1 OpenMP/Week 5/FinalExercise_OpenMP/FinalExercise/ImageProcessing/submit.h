#ifdef DLL_TEST_EXPORTS
#define test_submit_API __declspec(dllexport) 
#else
#define test_submit_API __declspec(dllimport) 
#endif
#include "EasyBMP.h"

int test_submit_API test_submit(int n, int(*f)(double** , double** , double** , int ));
void test_submit_API Debug_mod(bool db);
void test_submit_API Submit_Part1();
void test_submit_API Submit_Part2(BMP* test_image);
void test_submit_API Submit_Part3(BMP* test_image);
void test_submit_API Submit_Part4(BMP* test_image);
void test_submit_API Compiler_param(bool db);