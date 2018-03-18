#include "EasyBMP.h"
#include <iostream>
#include "math.h"
#include "locale.h"
#include "image_proc.h"
#include "omp.h"
#include "submit.h"

#define InpitImage "Image\\test_image_large2.bmp"

using namespace std;

int main( int argc, char* argv[] )
{
	double time = omp_get_wtime(); 
	BMP InputImage;
	InputImage.ReadFromFile(InpitImage); // Считывание обрабатываемого изображения 

	cout << "Gaussian blur" << endl;
	InputImage.gaussian_blur(3);  // Применение гаусового развытия к изображению
	cout << "Writing 8 bit depth image" << endl;
	InputImage.SetBitDepth(8);  // Задаем глубину цыета для записываемого изображения
	InputImage.WriteToFile("Image\\output_image8bpp.bmp"); // Запись изображения в файл
	cout << "Time=" << omp_get_wtime() - time << endl;

	// Проверка выполненных заданий
	BMP test_image;

	// Submit_Part1(); // Проверка первого задания
	// Submit_Part2(&test_image); // Проверка второго задания
	// Submit_Part3(&test_image); // Проверка третьего задания
	// Submit_Part4(&test_image); // Проверка четвертого задания
 return 0;
}
