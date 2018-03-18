#include "EasyBMP.h"
#include <algorithm>

using namespace std;

int gaussian_blur(BMP InputImage,int r)
{
	BMP OutputImage;
	OutputImage.SetSize(InputImage.TellWidth(), InputImage.TellHeight());
	OutputImage.SetBitDepth(24);
	RGBApixel val;
	RGBApixel** tmp_image;
	tmp_image = new RGBApixel*[InputImage.TellWidth()];
	for (int i = 0; i < InputImage.TellWidth();i++)
		tmp_image[i]= new RGBApixel[InputImage.TellHeight()];
	int w = InputImage.TellWidth();
	int h = InputImage.TellHeight();
	float alpha, red, blue, green;
	float dsq, wght;
	int x, y;
	for (int i = 0; i<w; i++)
		for (int j = 0; j< h; j++)
		{
			alpha = 0;
			red = 0;
			blue = 0;
			green = 0;
			float wsum = 0;
			for (int ix = i - r; ix<i + r + 1; ix++)
				for (int iy = j - r; iy < j + r + 1; iy++)
				{
					x = min(w - 1, max(0, ix));
					y = min(h - 1, max(0, iy));
					dsq = (ix - i)*(ix - i) + (iy - j)*(iy - j);
					wght = exp(-dsq / (2 * r*r)) / (3.1415 * 2 * r*r);
					alpha += InputImage.GetPixel(x, y).Alpha * wght;
					blue += InputImage.GetPixel(x, y).Blue * wght;
					red += InputImage.GetPixel(x, y).Red * wght;
					green += InputImage.GetPixel(x, y).Green * wght;
					wsum += wght;
				}
			val.Alpha = round(alpha / wsum);
			val.Red = round(red / wsum);
			val.Blue = round(blue / wsum);
			val.Green = round(green / wsum);
			tmp_image[i][j]= val;
		}
	for (int i = 0; i<InputImage.TellWidth(); i++)
	{
		delete[] tmp_image[i];
	}
	delete[] tmp_image;
	return 0;
}