#include <stdio.h>
#include <time.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch1(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid + 1;
    else if (x > v[mid])
      low = mid + 1;
    else /* found match */
      return mid;
  }
  return -1; /* no match */
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch2(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high && x != v[mid]) {
    if (x < v[mid])
      high = mid + 1;
    else
      low = mid + 1;
    mid = (low + high) / 2;
  }
  if (x == v[mid]) {
    return mid;
  }
  return -1; /* no match */
}

#define SIZE 50000

int main() {
  int v[SIZE];
  for (int i = 0; i < SIZE; i++) {
    v[i] = i;
  }

  int search = SIZE / 3;

  clock_t start, end;
  double time;
  start = clock();
  int x = binsearch1(search, v, SIZE);
  end = clock();
  time = ((double)end - start) / CLOCKS_PER_SEC;
  printf("binsearch1 time: %f\n", time);

  start = clock();
  int y = binsearch2(search, v, SIZE);
  end = clock();
  time = ((double)end - start) / CLOCKS_PER_SEC;
  printf("binsearch2 time: %f\n", time);

  return 0;
}