#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Метод восходящего слияния
void mergeSort(int *a, int l, int r)
{
  if (l == r) return; // границы сомкнулись
  int mid = (l + r) / 2; // определяем середину последовательности
  // и рекурсивно вызываем функцию сортировки для каждой половины
  mergeSort(a, l, mid);
  mergeSort(a, mid + 1, r);
  int i = l;  // начало первого пути
  int j = mid + 1; // начало второго пути
  int *tmp = (int*)malloc((r - l + 1) * sizeof(int)); // дополнительный массив
  if(tmp == NULL) {
    printf("Error");
    exit(1);
  }
  for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
  {
    // записываем в формируемую последовательность меньший из элементов двух путей
    // или остаток первого пути если j > r
    if ((j > r) || ((i <= mid) && (a[i] < a[j])))
    {
      tmp[step] = a[i];
      i++;
    }
    else
    {
      tmp[step] = a[j];
      j++;
    }
  }
  // переписываем сформированную последовательность в исходный массив
  for (int step = 0; step < r - l + 1; step++)
    a[l + step] = tmp[step];
}
int main(void)
{
  //int N;
  //printf("Input N: ");
  //scanf("%d", &N);
  int* a;
  int step = 10;
  for(int N = 10; N <= 5000; N = N + step) {
    a = (int *)malloc(N * sizeof(int));
    if(a == NULL) {
      printf("Error");
      return 1;
    }
    //printf("Input the array elements:\n");
    for (int i = 0; i < N; i++)
      a[i] = rand()% 6000;
    //scanf("%d", &a[i]);
    // Заполняем элементы массива
    clock_t begin = clock();
    mergeSort(a, 0, N - 1); // вызываем функцию сортировки
    clock_t end = clock();
    int time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000000;
    printf("%d\n", time_spent);
    // Выводим отсортированный массив
    /*for (int i = 0; i < N; i++)
      printf("%d ", a[i]);*/
    //printf("\n");
    free(a);
    switch (N) {
      case 100:
        step = 25;
        break;
      case 1000:
        step = 100;
        break;
    }
  }
  return 0;
}
