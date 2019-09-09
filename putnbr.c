#include <stdio.h>
#include <unistd.h>

void putnbr(int n)
{
	char	s[11];
	int	l;
	unsigned int	nn;
	char	signe;
	int	size;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	l = 0;
	signe = n >= 0 ? 1 : -1;
	nn = signe == 1 ? n : -n;
	while (nn != 0)
	{
		nn /= 10;
		l++;
	}
	l++;
	size = l;
	s[l] = '\0';
	nn = signe == 1 ? n : -n;
	while (l--)
	{
		s[l] = nn % 10 + '0';
		nn /= 10;
		
	}
	s[0] = signe == 1 ? '+' : '-';
	write(1, s, size + 1);
}

int main()
{
	putnbr(-194453221);
}
