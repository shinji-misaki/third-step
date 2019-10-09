#include<stdio.h>
#include"math.h"

int main()
{
	int i,j,tmp;
	double wa1 = 0.0,wa2=0.0;

	int Sci[20] = {
		65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70
	};
	int Eng[20] = {
		44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84
	};
	
	double sumS = 0.0;
	double sumE = 0.0;
	double aveS = 0.0;
	double aveE = 0.0;
	double heS = 0.0;
	double heE = 0.0;
	double HENS[20] = { 0 }, HENE[20] = { 0 };


	for (i = 0; i < 20; i++) {
		sumS += Sci[i];
		sumE += Eng[i];

	}
	aveS = sumS / 20;
	aveE = sumE / 20;

	for (i=0; i < 20; i++) {
	
		wa1 += (Sci[i] - aveS)*(Sci[i] - aveS);
		wa2 += (Eng[i] - aveE)*(Eng[i] - aveE);
	}
	heS = sqrt( wa1/ 20);
	heE = sqrt( wa2/ 20);

	for (i = 0; i < 20; i++) {
		HENS[i] = (Sci[i] - aveS) / heS * 10 + 50;
		HENE[i] = (Eng[i] - aveE) / heE * 10 + 50;

	}
	for (i = 0; i < 20; i++) {
		for (j = i + 1; j < 20; j++) {
			if (Sci[i] > Sci[j]) {
				tmp = Sci[i];
				Sci[i] = Sci[j];
				Sci[j] = tmp;
			}
		}
	}
	for (i = 0; i < 20; i++) {
		for (j = i + 1; j < 20; j++) {
			if (Eng[i] > Eng[j]) {
				tmp = Eng[i];
				Eng[i] = Eng[j];
				Eng[j] = tmp;
			}
		}
	}
	printf("理科の平均点は%.2f,英語の平均点は%.2f\n", aveS, aveE);
	printf("理科の標準偏差は%.2f,英語の標準偏差は%.2f\n", heS, heE);
	printf("理科の合計点は%.2f,英語の合計点は%.2f\n", sumS, sumE);
	printf("偏差値\n");
	for (i = 0; i < 20; i++) {
		printf("生徒(%d):理科=%.2f,英語=%.2f\n",i + 1, HENS[i], HENE[i]);
	}
	printf("理科の得点順\n");
	for (i = 19; i >= 0; i--) {
		printf("%d  ,",Sci[i]);
	}
	printf("\n\n");
	printf("英語の得点順\n");
	for (i = 19; i >= 0; i--) {
		printf("%d  ,", Eng[i]);
	}
	return 0;
}
