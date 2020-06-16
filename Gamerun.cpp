#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include"Draw.h"
#include"AI.h"
//#include"rule.h"
//#include"test.h"


/////*�������С*/
#define N 15
int status[N][N] = { 0 };
int ResultCheck(int x, int y, int i);


void GameRun()
{
	setbkcolor(GREEN);
	cleardevice();
	IMAGE img = NULL, IMG_WHITE = NULL, IMG_BLACK = NULL;    //���屣��ͼ���ָ��
	MOUSEMSG m;
	int x = 0, y = 0, xx = 0, yy = 0;
	//int xb = 0, yb = 0, xw = 0, yw = 0;
	int AIplay[2];
	//int olds[15][15] = { 0 };
	//int news[15][15] = { 0 };
	int i = 0, a = 0;      //������
	DrawBoard();      //��������

	while (1)
	{
		if (i % 2 == 0)
		{
			ShowMessage(i);
			if (MouseHit())
			{
				m = GetMouseMsg();      //��ȡ�������
				FlushMouseMsgBuffer();
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					i++;
					x = m.x / 40;       //�������ת����������
					y = m.y / 40;       //�������ת����������
					if ((x >= 0 && x < 15) && (y >= 0 && y < 15) && status[x][y] == 0)     //�������������̷�Χ��,�Ҳ��������Ѵ������ӵĵ���
					{
						//getimage(&IMG_BLACK, x * 40, y * 40, 80, 80);   //������ǰ��ͼ���ŵ�ָ�������ʱ�������ô�ͼ�������Ӹ��ǵ����ص�����ǰ��״̬
						//xb = x; yb = y;
						DrawCircle(x, y, BLACK);       //��������	
						//HeQi(i);                      //���ú��庯����
						status[x][y] = 1;                //������������������Ϊ1���ڼ����ʱʹ�ã�
						if (i == 225)                     //�ж������Ƿ���
							break;
						if (ResultCheck(x, y, i))      //����*�����*������ķ���ֵ��������
						{
							//loadimage(&img, _T("..\\HEI.jpg"));   //����*�����ʤ��*ͼƬ
							//putimage(120, 200, &img);
							printf("You are win.");
							break;
						}
					}
				}
			}
		}
		else{
					ShowMessage(i);
					i++;
					Sleep(1000);
					AI(status,/* olds,*/ AIplay);
					xx = AIplay[0];
					yy = AIplay[1];
					//getimage(&IMG_WHITE, xx * 40, yy * 40, 80, 80);      //������ǰ��ͼ���ŵ�ָ�������ʱ�������ô�ͼ�������Ӹ��ǵ����ص�����ǰ��״̬
					//xw = xx; yw = yy;
					DrawCircle(xx, yy, WHITE);        //��������
					//HeQi(i);                       //���ú��庯����
					status[xx][yy] = 2;                 //������������������Ϊ2���ڼ����ʱʹ�ã�
					if (i == 225)
						break;
					if (ResultCheck(xx, yy, i))        //����*�����*������ķ���ֵ��������
					{
						//loadimage(&img, _T("..\\BAI.jpg"));  //����*�����ʤ��*ͼƬ
						//putimage(120, 200, &img);
						printf("You are lost");
						break;
					}

				}
	}
}



/*�����*/
int ResultCheck(int x, int y, int i)
{
	int j, k, color;
	int n1, n2;  //�������������ۼ����Ӹ���


	if (i % 2 == 0)      //���ݼ�����i����ż�ԣ��л�����Ͱ���ļ��
		color = 2;
	else
		color = 1;

	while (1)
	{
		n1 = 0;
		n2 = 0;
		for (j = x, k = y; j >= 0; j--)                      //������
		{
			if (status[j][k] == color)                     //�ж��Ƿ�Ϊ����
				n1++;
			else
				break;
		}
		for (j = x, k = y; j < 15; j++)                            //���Ҽ��
		{
			if (status[j][k] == color)
				n2++;
			else
				break;
		}
		if (n1 + n2 - 1 >= 5)
		{
			return(1);
		}
		n1 = 0;
		n2 = 0;
		for (j = x, k = y; k >= 0; k--)                                //���ϼ��
		{
			if (status[j][k] == color)
				n1++;
			else
				break;
		}
		for (j = x, k = y; k < 15; k++)                               //���¼��
		{
			if (status[j][k] == color)
				n2++;
			else
				break;
		}
		if (n1 + n2 - 1 >= 5)
		{
			return(1);
		}
		n1 = 0;
		n2 = 0;
		for (j = x, k = y; (j >= 0) && (k >= 0); j--, k--)                    //�����ϼ��
		{
			if (status[j][k] == color)
				n1++;
			else
				break;
		}
		for (j = x, k = y; (j < 15) && (k < 15); j++, k++)                      //�����¼��
		{
			if (status[j][k] == color)
				n2++;
			else
				break;
		}
		if (n1 + n2 - 1 >= 5)
		{
			return(1);
		}
		n1 = 0;
		n2 = 0;
		for (j = x, k = y; (j < 15) && (k >= 0); j++, k--)                    //�����ϼ��
		{
			if (status[j][k] == color)
				n1++;
			else
				break;
		}
		for (j = x, k = y; (j >= 0) && (k < 15); j--, k++)                       //�����¼��
		{
			if (status[j][k] == color)
				n2++;
			else
				break;
		}
		if (n1 + n2 - 1 >= 5)
		{
			return(1);
		}
		return(0);
	}
}
