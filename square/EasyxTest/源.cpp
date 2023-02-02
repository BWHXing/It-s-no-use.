#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
using namespace std;
const int width = 800;
const int height = 800;
const int speed = 2;
#define PI 3.1415926 / 180.0
class celle
{
public:
	double x = width / 2;
	double y = height / 2;
	int angle = 1;
	double radian = angle * PI;
	celle()
	{
		cout << "******" << endl;
		cout << "随机样本" << 0 + (int)360 * rand() / (RAND_MAX + 1) << endl;
		cout << "角度" << angle << endl;
		cout << "弧度" << radian << endl;
		cout << "******" << endl;
	}
	//int angle = rand() % 361;
	//angle状态表角度
};


void main0()
{
	srand(time(NULL));
	celle c1;
	double temp = speed / tan(c1.radian);
	if (c1.angle == 0 || c1.angle == 360)
	{
		c1.x += speed;
	}
	else if (c1.angle == 180)
	{
		c1.x -= speed;
	}
	else if (c1.angle == 90)
	{
		c1.y += speed;
	}
	else if (c1.angle == 270)
	{
		c1.y -= speed;
	}
	else if (0 < c1.angle && c1.angle < 90)
	{
		c1.x += temp;
		c1.y += temp * tan(c1.radian);
	}
	else if (90 < c1.angle && c1.angle < 180)
	{
		c1.x -= temp;
		c1.y += temp * tan(c1.radian);
	}
	else if (180 < c1.angle && c1.angle < 270)
	{
		c1.x -= temp;
		c1.y -= temp * tan(c1.radian);
	}
	else if (270 < c1.angle && c1.angle < 360)
	{
		c1.x += temp;
		c1.y -= temp * tan(c1.radian);
	}
	cout << "随机样本" << 0 + (int)360 * rand() / (RAND_MAX + 1) << endl;
	cout << "x:" << c1.x << "\ty:" << c1.y << endl;
	cout << "x:" << temp << "\ty:" << temp * tan(c1.radian) << endl;
	cout << "angle:" << c1.angle << "\ttan:" << tan(c1.radian) << endl;
}
