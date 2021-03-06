/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

int compare(const void * a, const void * b); // Функция сравнения для qsort()
void selectionSort(int * mass, int len); // Функция сортировки перестановками
int isSorted(int * mass, int len); // Функция проверки успешности сортировки
void fillData(int * mass1, int * mass2, int * mass3, int size); // Функция заполнения массива случайными числами
void output(double * timing, int N); // Функция вывода результата 
int power(int a, int b); // Функция возведения в степень 
void measureTime(int * mass1, int * mass2, int * mass3, int N, double * timing); // Функция замера времени
void heapSort(int * mass, int len); // Пирамидальная сортировка 
void buildHeap(int * mass, int len); // Постройка бинарного дерева сортировки