#define _CRT_SECURE_NO_WARNINGS // ��� ���������� ������ scanf()
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#pragma comment(linker, "/STACK:1468006400")


void qs(int �[], int left, int right)
{
	
  int pivot; // ����������� �������
  int l_hold = left; //����� �������
  int r_hold = right; // ������ �������
  pivot = �[left];

  while (left < right) // ���� ������� �� ���������
  {
    while ((�[right] >= pivot) && (left < right))
      right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
    if (left != right) // ���� ������� �� ����������
    {
      �[left] = �[right]; // ���������� ������� [right] �� ����� ������������
      left++; // �������� ����� ������� ������
    }
    while ((�[left] <= pivot) && (left < right))
      left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
    if (left != right) // ���� ������� �� ����������
    {
      �[right] = �[left]; // ���������� ������� [left] �� ����� [right]
      right--; // �������� ������ ������� �����
    }
  }
  �[left] = pivot; // ������ ����������� ������� �� �����
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
    qs(�, left, pivot - 1);
  if (right > pivot)
    qs(�, pivot + 1, right);
  
 
}
  
// ������� ���������� �����
void ShellSort(int n, int �[])
{
    int i, j, step;
    int tmp;
	
    for (step = n / 2; step > 0; step /= 2) //���� ��� ������ ���� ����� ����������� ��� ����
        for (i = step; i < n; i++) //������� �������� ���� ������������ � i, ���� i< �������� ������� ����� ����������� ��� ����
        {
            tmp = �[i]; //� tmp ������������ ������ �������� �������
			//���������� ��������, ��������� �� j
            for (j = i; j >= step; j=j-step) // ������� �������� i ������������ � j, ���� j ������ ��� ����� step ����������� ��� ���� 
            {
                if (tmp < �[j - step]) //���� ������ ������� ������� ������, ��� ���������, �� ����������� ��� ����
                    �[j] = �[j - step];//��������� � ���������� ���������� ��������
                else
                    break;
            }
            �[j] = tmp;//���� �������� ����������� �������
        }
	
}
int main()
{
	srand(time(NULL)); //������� ��� ��������� ��������� �����
	setlocale(LC_ALL, "Rus");//������� ����������� 
	FILE *F = fopen ( "vafla.txt", "wt" );//�������� ����� ��� ������
	FILE *Ff = fopen ( "vafla1.txt", "wt" );//�������� ����� ��� ������
	FILE *Fff = fopen ( "vafla11.txt", "wt" );//�������� ����� ��� ������
	FILE *Ffff = fopen ( "vafla111.txt", "wt" );//�������� ����� ��� ������
	FILE *Fffff = fopen ( "vafla1111.txt", "wt" );//�������� ����� ��� ������
	FILE *Ffffff = fopen ( "vafla11111.txt", "wt" );//�������� ����� ��� ������
	FILE *Fffffff = fopen ( "vafla111111.txt", "wt" );//�������� ����� ��� ������
	int numb, i, j, n, b, k, d, numb1, numb2;
	//���� ���������� �������� �������
	printf("������� numb: ");
    scanf_s("%d", &numb);
	printf("\n");
	numb1 = numb/2;
	numb2 = numb/2;
	//�������� �������
	int* A;
    A = (int *)malloc(numb1 * sizeof(int));//��������� ������ ��� ������
	int* B;
    B = (int *)malloc(numb2 * sizeof(int));//��������� ������ ��� ������
	int* C;
    C = (int *)malloc(numb * sizeof(int));//��������� ������ ��� ������
	int* D;
	D = (int *)malloc(numb * sizeof(int));//��������� ������ ��� ������
	fprintf(F, "����������� � ������������� � ���������� ���������� ������:\n");//������ ����� � ����
	printf("����������� ������ � ������������� � ���������� ���������� ��������� � ����� vafla.txt:\n");
	//���������� ������� ������������� � ���������� ����������
	for (int i = 0; i <= numb1; i++) {	
		for(i = numb1; i != 0; i--) {
			A[i] = i - 1;
			fprintf(F, "%d\t", A[i]);
		}
		for(i = 0; i != numb2; i++) {
			B[i] = i + 1;
			fprintf(F, "%d\t", B[i]);
		}	
	}
	k = -1; i = 0; j = 0; 
	for(int i = 0; i <= numb1; i++) {
		C[k++] = A[i];
	}
	for(int i = 0; i <= numb2 ; i++) {
		C[k++] = B[i];
		
	}
	for(int i = 0; i <= numb1+numb2-1; i++) {
		fprintf(Fffff, "%d\t", C[i]);
	}

	printf("\n");
	fprintf(Ffff, "����������� � ���������� ���������� ������:\n");//������ ����� � ����
	printf("����������� ������ � ���������� ���������� ��������� � ����� vafla111.txt:\n");
	srand(time(NULL));
    for (i = 0; i < numb; i++){
        D[i] = rand() % 100;
		fprintf(Ffff, "%d\t", D[i]);
    }
	printf("\n��������������� � ������������� � ���������� ���������� �������� ����� ������ ��������� � ����� vafla1.txt:\n");
	printf("\n��������������� � ������������� � ���������� ���������� ������� �������� ������ ��������� � ����� vafla11.txt:\n");
	printf("\n");
	fprintf(Fff, "\n��������������� ������ ������� �������� � ������������� � ���������� ���������� :\n");//������ ����� � ����

	double time_potr = 0.0; // ��� �������� ������� ���������� ����
    clock_t nach = clock();
	qs(C, 0, numb-1);
	clock_t konec = clock();
	for (int i = 0; i < numb; i++){
        fprintf(Fff, "%d\t ", C[i]);
	}
	time_potr += (double)(konec - nach) / CLOCKS_PER_SEC;
	//printf("���������� ����� � �������� �� quick sort %f ", time_potr);
    printf("\n");

	//���������� ������� ����� ��� ������������� � ����������
	fprintf(Ff, "\n��������������� ������ �������� ����� � ������������� � ���������� ���������� :\n");//������ ����� � ����
	double time_spent = 0.0; // ��� �������� ������� ���������� ����
    clock_t begin = clock();
    ShellSort(numb-1, C);//����� ������� ������ �����
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;// ���������� ��������� �����, ����� ������� (end - begin) � ������� ������� �� CLOCKS_PER_SEC ��� �������� � �������
	//printf("���������� ����� � �������� �� Shell's sort %f ", time_spent);
    //����� ���������������� ������� �� �����
    for (int i = 0; i < numb; i++){
        fprintf(Ff, "%d\t ", C[i]);
	}

	printf("\n��������������� � ���������� ���������� �������� ����� ������ ��������� � ����� vafla111111.txt:\n");
	printf("\n��������������� � ���������� ���������� ������� �������� ������ ��������� � ����� vafla11111.txt:\n");
	printf("\n");
	fprintf(Ffffff, "��������������� � ���������� ���������� ������� �������� ������:\n");//������ ����� � ����
	
    double time_p = 0.0; // ��� �������� ������� ���������� ����
	clock_t na = clock();
	qs(D, 0, numb-1);
	clock_t ko = clock();
	for (int i = 0; i < numb; i++){
        fprintf(Ffffff, "%d\t ", D[i]);
	}
	time_p += (double)(ko- na) / CLOCKS_PER_SEC;
	//printf("���������� ����� � �������� �� quick sort %f ", time_p);
    printf("\n");
	
	//���������� ������� ����� ��� ���������� �������
	fprintf(Fffffff, "��������������� � ���������� ���������� �������� ����� ������:\n");//������ ����� � ����
	double time_s = 0.0; // ��� �������� ������� ���������� ����
    clock_t be = clock();
    ShellSort(numb-1, D);//����� ������� ������ �����
	clock_t en = clock();
	time_s += (double)(en - be) / CLOCKS_PER_SEC;// ���������� ��������� �����, ����� ������� (end - begin) � ������� ������� �� CLOCKS_PER_SEC ��� �������� � �������
	//printf("���������� ����� � �������� �� Shell's sort %f ", time_s);
	printf("\n");
    //����� ���������������� ������� � ������������ � ��������� �������������������� �� �����
    for (int i = 0; i < numb; i++){
        fprintf(Fffffff, "%d\t ", D[i]);
	}

	printf("*----------------------------------------------------------*");
	printf("\n");
	printf("*������������������ * QuickSort%f",time_potr);
	printf(" * Shellsort%f", time_spent);
	printf("*");
	printf("\n");
	printf("*----------------------------------------------------------*");
	printf("\n");
	printf("*���������          * QuickSort%f", time_p);
	printf(" * Shellsort%f", time_s);
	printf("*");
	printf("\n");
	printf("*----------------------------------------------------------*");
	printf("\n");
	getchar();getchar();
}



