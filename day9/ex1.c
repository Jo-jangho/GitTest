#include <stdio.h>

#define PI 3.14

int main(void)
{
	const double pi = 3.14;
	double _pi = 3.14;

	//pi = 2.14;
	//_pi = 2.14;

	int a = 10, b = 20;
	const int* ap;
	
	ap = &a;
	ap = &b;

	b = 21;
	//*ap = 21;

	printf("%f \r\n", pi);

	return 0;
}
