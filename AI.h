#include<stdio.h>

typedef  struct record {
	int x, y;
	int mark[15][15] = { 0 };
	struct record* next;
}record;

/*�����̿�λ���д�֣�ѡ��AI���ӵ���ѿ�λ*/
void AI(const int status[15][15],/* int olds[15][15], */int* s);
void evaluate(const int V[15][15], record* m, int n/*int mark*//*,int *s*/);

int simulate(int V[15][15], int len, /*int* set,*/record* p,int*s);
