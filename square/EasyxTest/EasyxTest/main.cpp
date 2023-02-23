#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <iostream>
#include <string>
#include <random>
#include <windows.h>
#include <stdlib.h>
using namespace std;
const int cell_num = 2; //ϸ��������ϸ����С��cell����
void scr_size(int* x, int* y) //���ڴ�С��ȡ
{
	DEVMODE dm;
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm);
	*x = dm.dmPelsWidth;
	*y = dm.dmPelsHeight;

}
int width = 800;
int height = 550;
const int speed = 2;
#define PI 3.1415926 / 180.0  //tan�����󻡶���Ҫ������=�Ƕ�*pi/180
class cell
{
public:
	//double weightForward;
	void draw(COLORREF color)
	{
		setfillcolor(color);
		int left_m = x;
		int top_m = y;
		int right_m = x + size;
		int bottom_m = y + size;
		solidrectangle(left_m, top_m, right_m, bottom_m);
	}
	int size = 15;
	//double x = width / 2;
	//double y = height / 2;
	double x = 0 + (int)(width - size) * rand() / (RAND_MAX + 1);
	double y = 0 + (int)(height - size) * rand() / (RAND_MAX + 1);
	int angle = 0 + (int)360 * rand() / (RAND_MAX + 1);
	//int angle = random_ht();
	double radian = angle * PI;
	//int angle = rand() % 361;
	//angle״̬��Ƕ�
	/*
	����Ƕ�ԭ��
	y=kx��x=speed/k=speed/tan(n��)�������x��yӦ�ü�/������
	ֵ��һ�����2/tan(1*pi/180)=114.57992521
	*/
};
void go(cell&c1)
{
	//����Ƕ�
	double temp = speed / tan(c1.radian);
	if (c1.angle >= 330 && c1.angle <360 || c1.angle >= 0 && c1.angle <= 15)
	{
		c1.x += speed;
	}
	else if (c1.angle <= 195 && c1.angle >= 150)
	{
		c1.x -= speed;
	}
	else if (c1.angle <= 150 && c1.angle >= 60)
	{
		c1.y += speed;
	}
	else if (c1.angle>= 240 && c1.angle <= 300)
	{
		c1.y -= speed;
	}
	else if (15 <= c1.angle && c1.angle <= 60)
	{
		c1.x += temp;
		c1.y += temp * tan(c1.radian);
	}
	else if (105 <= c1.angle && c1.angle <= 150)
	{
		c1.x -= temp;
		c1.y += temp * tan(c1.radian);
	}
	else if (195 <= c1.angle && c1.angle <= 240)
	{
		c1.x -= temp;
		c1.y -= temp * tan(c1.radian);
	}
	else if (300 <= c1.angle && c1.angle <= 330)
	{
		c1.x += temp;
		c1.y -= temp * tan(c1.radian);
	}
	c1.draw(WHITE);
	//��ǽ��⣬��ǽ������Ƕ�
	if (c1.x <= 0) 
	{ 
		if (rand() % 2)
		{
			c1.angle = 270 + (int)360 * rand() / (RAND_MAX + 1);
		}
		else
		{
			c1.angle = 0 + (int)90 * rand() / (RAND_MAX + 1);
		}
	}
	else if (c1.x + c1.size >= width)
	{
		c1.angle = 90 + (int)270 * rand() / (RAND_MAX + 1);
	}
	else if (c1.y <= 0)
	{
		c1.angle = 0 + (int)180 * rand() / (RAND_MAX + 1);
	}
	else if (c1.y + c1.size >= height)
	{
		c1.angle = 180 + (int)360 * rand() / (RAND_MAX + 1);
	}
	c1.radian = c1.angle * PI;
}

int main()
{
	//scr_size(&width, &height); //���ڴ�С��ȡ
	//srand(rand());
	initgraph(width, height);	// ������ͼ����
	BeginBatchDraw();
	setbkcolor(LIGHTGRAY);
	cleardevice();
	cell c1[cell_num];
	while (1)
	{
		srand(rand());
		for (int num = 0; cell_num != num; num++)
		{
			go(c1[num]);
		}
		FlushBatchDraw();
		Sleep(1);
		cleardevice();
	}
	EndBatchDraw();
	closegraph();			// �رջ�ͼ����
	return 0;
}