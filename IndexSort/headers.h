/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

int compare(const void * a, const void * b); // Функция сравнения для qsort()
void selectionSort(int *mass, int len, int * index); // Функция сортировки перестановками
int isSorted(int *mass, int len, int * index); // Функция проверки успешности сортировки
void fillData(int * mass1, int * mass2, int size); // Функция заполнения массива случайными числами
void output(double * timing, int N); // Функция вывода результата 
int power(int a, int b); // Функция возведения в степень 
void measureTime(int * mass1, int * mass2, int N, double * timing, int * index); // Функция замера времени