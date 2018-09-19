#include <cstdlib>
#include <iostream>

using namespace std;

void print(int numbers[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << numbers[i] << " ";
  }
  cout << endl;
};

int findMax(int numbers[], int size)
{
  int max = 0;
  for (int i = 0; i < size; i++)
  {
    if (max < numbers[i]) max = numbers[i];
  }
  return max;
};

void countingSort(int numbers[], int size)
{
  int maxNumber = findMax(numbers, size) + 1;

  int tmp[maxNumber];

  for (int i = 0; i < maxNumber; i++)
  {
    tmp[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    tmp[numbers[i]] += 1;
  }

  for (int i = 0; i < maxNumber-1; i++) {
      tmp[i+1] += tmp[i];
  }

  int sorted[size];

  for (int i = 0; i < size; i++) {
    sorted[tmp[numbers[i]]-1] = numbers[i];
    tmp[numbers[i]]--;
  }

  for (int i = 0; i < size; i++) {
    numbers[i] = sorted[i];
  }
};

int main(int argc, char *argv[]) {
    int numbers[] = {1000000, 99999};
    int size = sizeof(numbers) / sizeof(*numbers);

    print(numbers, size);
    countingSort(numbers, size);
    print(numbers, size);

    system("read");
    return EXIT_SUCCESS;
}
