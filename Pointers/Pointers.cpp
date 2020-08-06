// Pointers.cpp : Defines the entry point for the application.
//

#include "Pointers.h"

//using namespace std;

int main()
{
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
	const int x = *A+3;
	printf("%d\n", x);
	
	int counter = 10;

	printf("%d\n", *A);
	while (counter)
	{
		printf("%d\n", reinterpret_cast<int>(&A[counter - 1]));
		printf("%d\n", A[counter - 1]);
		--counter;

	}
	
	printf("%d\n", static_cast<int>(sizeof(int)));
	
	getchar();
	
	return 0;
}
