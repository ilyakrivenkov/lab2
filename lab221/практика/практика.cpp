#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#pragma comment(linker, "/STACK:1468006400")


void qs(int С[], int left, int right)
{
	
  int pivot; // разрешающий элемент
  int l_hold = left; //левая граница
  int r_hold = right; // правая граница
  pivot = С[left];

  while (left < right) // пока границы не сомкнутся
  {
    while ((С[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      С[left] = С[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо
    }
    while ((С[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      С[right] = С[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу влево
    }
  }
  С[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    qs(С, left, pivot - 1);
  if (right > pivot)
    qs(С, pivot + 1, right);
  
 
}
  
// Функция сортировки Шелла
void ShellSort(int n, int С[])
{
    int i, j, step;
    int tmp;
	
    for (step = n / 2; step > 0; step /= 2) //пока шаг больше нуля будет выполняться код ниже
        for (i = step; i < n; i++) //текущее значение шага записывается в i, пока i< значений массива будет выполняться код ниже
        {
            tmp = С[i]; //в tmp записывается первое значение массива
			//перебираем элементы, отстоящие от j
            for (j = i; j >= step; j=j-step) // текущее значение i записывается в j, пока j больше или равно step выполняется код ниже 
            {
                if (tmp < С[j - step]) //Если первый элемент массива меньше, чем отстоящий, то выполняется код ниже
                    С[j] = С[j - step];//переходим к следующему отстающему элементу
                else
                    break;
            }
            С[j] = tmp;//сюда помещаем сохраненный элемент
        }
	
}
int main()
{
	srand(time(NULL)); //функция для генерации рандомных чисел
	setlocale(LC_ALL, "Rus");//русская локализация 
	FILE *F = fopen ( "vafla.txt", "wt" );//открытие файла для записи
	FILE *Ff = fopen ( "vafla1.txt", "wt" );//открытие файла для записи
	FILE *Fff = fopen ( "vafla11.txt", "wt" );//открытие файла для записи
	FILE *Ffff = fopen ( "vafla111.txt", "wt" );//открытие файла для записи
	FILE *Fffff = fopen ( "vafla1111.txt", "wt" );//открытие файла для записи
	FILE *Ffffff = fopen ( "vafla11111.txt", "wt" );//открытие файла для записи
	FILE *Fffffff = fopen ( "vafla111111.txt", "wt" );//открытие файла для записи
	int numb, i, j, n, b, k, d, numb1, numb2;
	//ввод количества значений массива
	printf("Введите numb: ");
    scanf_s("%d", &numb);
	printf("\n");
	numb1 = numb/2;
	numb2 = numb/2;
	//создание массива
	int* A;
    A = (int *)malloc(numb1 * sizeof(int));//выделение памяти под массив
	int* B;
    B = (int *)malloc(numb2 * sizeof(int));//выделение памяти под массив
	int* C;
    C = (int *)malloc(numb * sizeof(int));//выделение памяти под массив
	int* D;
	D = (int *)malloc(numb * sizeof(int));//выделение памяти под массив
	fprintf(F, "Первородный с возрастающими и убывающими значениями массив:\n");//запись фразы в файл
	printf("Первородный массив с возрастающими и убывающими значениями находится в файле vafla.txt:\n");
	//заполнение массива возрастающими и убывающими значениями
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
	fprintf(Ffff, "Первородный с рандомными значениями массив:\n");//запись фразы в файл
	printf("Первородный массив с рандомными значениями находится в файле vafla111.txt:\n");
	srand(time(NULL));
    for (i = 0; i < numb; i++){
        D[i] = rand() % 100;
		fprintf(Ffff, "%d\t", D[i]);
    }
	printf("\nОтсортированный с возрастающими и убывающими значениями способом Шелла массив находится в файле vafla1.txt:\n");
	printf("\nОтсортированный с возрастающими и убывающими значениями быстрым способом массив находится в файле vafla11.txt:\n");
	printf("\n");
	fprintf(Fff, "\nОтсортированный массив быстрым способом с возрастающими и убывающими значениями :\n");//запись фразы в файл

	double time_potr = 0.0; // для хранения времени выполнения кода
    clock_t nach = clock();
	qs(C, 0, numb-1);
	clock_t konec = clock();
	for (int i = 0; i < numb; i++){
        fprintf(Fff, "%d\t ", C[i]);
	}
	time_potr += (double)(konec - nach) / CLOCKS_PER_SEC;
	//printf("Затраченно время в секундах на quick sort %f ", time_potr);
    printf("\n");

	//сортировка методом Шелла для возрастающего и убывающего
	fprintf(Ff, "\nОтсортированный массив способом Шелла с возрастающими и убывающими значениями :\n");//запись фразы в файл
	double time_spent = 0.0; // для хранения времени выполнения кода
    clock_t begin = clock();
    ShellSort(numb-1, C);//вызов функции метода шелла
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;// рассчитать прошедшее время, найдя разницу (end - begin) и деление разницы на CLOCKS_PER_SEC для перевода в секунды
	//printf("Затраченно время в секундах на Shell's sort %f ", time_spent);
    //вывод отсортированного массива на экран
    for (int i = 0; i < numb; i++){
        fprintf(Ff, "%d\t ", C[i]);
	}

	printf("\nОтсортированный с рандомными значениями способом Шелла массив находится в файле vafla111111.txt:\n");
	printf("\nОтсортированный с рандомными значениями быстрым способом массив находится в файле vafla11111.txt:\n");
	printf("\n");
	fprintf(Ffffff, "Отсортированный с рандомными значениями быстрым способом массив:\n");//запись фразы в файл
	
    double time_p = 0.0; // для хранения времени выполнения кода
	clock_t na = clock();
	qs(D, 0, numb-1);
	clock_t ko = clock();
	for (int i = 0; i < numb; i++){
        fprintf(Ffffff, "%d\t ", D[i]);
	}
	time_p += (double)(ko- na) / CLOCKS_PER_SEC;
	//printf("Затраченно время в секундах на quick sort %f ", time_p);
    printf("\n");
	
	//сортировка методом Шелла для рандомного массива
	fprintf(Fffffff, "Отсортированный с рандомными значениями способом Шелла массив:\n");//запись фразы в файл
	double time_s = 0.0; // для хранения времени выполнения кода
    clock_t be = clock();
    ShellSort(numb-1, D);//вызов функции метода шелла
	clock_t en = clock();
	time_s += (double)(en - be) / CLOCKS_PER_SEC;// рассчитать прошедшее время, найдя разницу (end - begin) и деление разницы на CLOCKS_PER_SEC для перевода в секунды
	//printf("Затраченно время в секундах на Shell's sort %f ", time_s);
	printf("\n");
    //вывод отсортированного массива с возрастающей и убывающей последовательностями на экран
    for (int i = 0; i < numb; i++){
        fprintf(Fffffff, "%d\t ", D[i]);
	}

	printf("*----------------------------------------------------------*");
	printf("\n");
	printf("*Последовательность * QuickSort%f",time_potr);
	printf(" * Shellsort%f", time_spent);
	printf("*");
	printf("\n");
	printf("*----------------------------------------------------------*");
	printf("\n");
	printf("*Рандомный          * QuickSort%f", time_p);
	printf(" * Shellsort%f", time_s);
	printf("*");
	printf("\n");
	printf("*----------------------------------------------------------*");
	printf("\n");
	getchar();getchar();
}



