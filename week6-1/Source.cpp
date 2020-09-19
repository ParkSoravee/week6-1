#include<stdio.h>
void getType(int*);
void getPrice(double*,int*);
double disSumPrice(int*, double*);

int main() 
{
	int type;
	int *pType = &type;
	double fruit[100][2];
	double tPrice = 0;
	double *pFruit = fruit[0];
	
	getType(pType);
	getPrice(pFruit, pType);
	tPrice = disSumPrice(pType, pFruit);

	printf("%.2lf", tPrice);
	return 0;
}

void getType(int* pType)
{
	scanf_s("%d", &*pType);
}
void getPrice(double *pFruit, int *pType) 
{
	for (int i = 0; i < *pType*2; i+=2) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%lf", &*(pFruit+i+j));
		}
	}
}
double disSumPrice(int *pType, double *pFruit)
{
	double tPrice = 0;
	for (int i = 0; i < *pType*2; i+=2) 
	{
		tPrice += *(pFruit+i) * *(pFruit+1+i);
	}
	if (tPrice > 400) 
	{
		double discount = tPrice * 10 / 100;
		if (discount > 200) 
		{
			tPrice -= 200;
		}
		else 
		{
			tPrice -= discount;
		}
	}
	else if (tPrice > 200) 
	{
		tPrice *= 95.0 / 100.0;
	}
		return tPrice;
}