#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/*void ff(int a, int b, int c)
{
	void *p = &a;

	(void)b;
	(void)c;
	printf("%d\n", *(int *)((char *)p - sizeof(int)));
}
*/
int main()
{
	//int a = 1090536001;
	//void *p = &a;
	printf("int %zd\n", sizeof(int));
	printf("un int %zd\n", sizeof(unsigned int));
	printf("long int %zd\n", sizeof(long int));
	printf("intmax_t %zd\n", sizeof(__intmax_t));
	printf("long long int %zd\n", sizeof(long long int));
	printf("long %zd\n", sizeof(long));
	printf("long long %zd\n", sizeof(long long));
	printf("short int %zd\n", sizeof(short int));
	printf("short un int %zd\n", sizeof(short unsigned int));
	printf("char %zd\n", sizeof(char));
	printf("float %zd\n", sizeof(float));
	printf("un char%zd\n", sizeof(unsigned char));
	printf("signed char%zd\n", sizeof(signed char));
	printf("double %zd\n", sizeof(double));
	//write(1, p, 1);
	return (0);
}
