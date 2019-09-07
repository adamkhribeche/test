#include <stdio.h>

void ff(int n, int m, int n1, int m1)
{
	int *p4;
	char c2;
	int a1;
	int a4;
	char c1;
	int a2;
	void *p1;
	void *p2;
	int a3;
	int *p3;
	char buff[10000];
	char c3;
	
	printf("n = %p\n", &n);
	printf("m = %p\n", &m);
	printf("n1 = %p\n", &n1);
	printf("m1 = %p\n", &m1);
	printf("a1 = %p\n", &a1);
	printf("a2 = %p\n", &a2);
	printf("a3 = %p\n", &a3);
	printf("a4 = %p\n", &a4);
	printf("c1 = %p\n", &c1);
	printf("c2 = %p\n", &c2);
	printf("c3 = %p\n", &c3);
	printf("p1 = %p\n", &p1);
	printf("p2 = %p\n", &p2);
	printf("p2 = %p\n", &p3);
	printf("p2 = %p\n", &p4);
	printf("p3 = %p\n", &p3);
	printf("buff0 = %p\n", &buff[0]);
	printf("buff1 = %p\n", &buff[1]);
	printf("buff2 = %p\n", &buff[2]);

}

int main()
{
	ff(8, 9, 3, 3);
}
