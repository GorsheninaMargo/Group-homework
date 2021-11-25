#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int N;
    //printf("Input N: ");
    //scanf("%d", &N);
    int* mass;
    int step = 10;
    for(N = 10; N <= 5000; N = N + step) {
      mass = (int *)malloc(N * sizeof(int));
      if(mass == NULL) {
        printf("Error");
        return 1;
      }
      //printf("Input the array elements:\n");
      for (int i = 0; i < N; i++)
        mass[i] = rand() % 6000;
      //scanf("%d", &mass[i]);
      //сортировка методом выбора
      int minPosition, tmp;

      clock_t begin = clock();

      for (int i = 0; i < N; i++)
      {
          minPosition = i;
          for (int j = i + 1; j < N; j++)
              if (mass[minPosition] > mass[j])
                  minPosition = j;
          tmp = mass[minPosition];
          mass[minPosition] = mass[i];
          mass[i] = tmp;
      }

      clock_t end = clock();
      int time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000000;
      printf("%d\n", time_spent);

      //printf("Время %f\n", time_spent);

      //printf("Sorted array:\n");
      /*for (int i = 0; i < N; i++)
          printf("%d ", mass[i]);
      printf("\n");*/
      free(mass);
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
