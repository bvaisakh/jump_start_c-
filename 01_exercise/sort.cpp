#include <iostream>
using namespace std;

void printCharArray(int size, char **argv);
double *createDoubleArrayFromArgv(int size, char **argv);
void printDoubleArray(int size, double *doublePtr);
int compare(const void *x, const void *y);

int main(int argc, char **argv)
{
  double *doubleArray;
  int size = argc - 1;

  cout << endl
       << "Printing Input" << endl;
  cout << "--------------" << endl;
  printCharArray(size, argv);

  doubleArray = createDoubleArrayFromArgv(size, argv);

  cout << endl
       << "Printing Unsorted Array" << endl;
  cout << "---------------------" << endl;
  printDoubleArray(size, doubleArray);

  qsort(doubleArray, size, sizeof(double), compare);

  cout << endl
       << "Printing Sorted Array" << endl;
  cout << "---------------------" << endl;
  printDoubleArray(size, doubleArray);

  free(doubleArray);
  return 0;
}

void printCharArray(int size, char **argv)
{
  cout << "You have entered " << size << " arguments"
       << endl;

  for (int i = 0; i < size; i++)
    cout << argv[i + 1] << endl;
}

double *createDoubleArrayFromArgv(int size, char **argv)
{
  double *doublePtr = (double *)malloc(size * sizeof(double));

  for (int i = 0; i < size; i++)
    *(doublePtr + i) = stod(argv[(i + 1)]);

  return doublePtr;
}

void printDoubleArray(int size, double *doublePtr)
{
  for (int i = 0; i < size; i++)
    cout << doublePtr[i] << endl;
}

int compare(const void *x, const void *y)
{
  return (*(double *)x - *(double *)y);
}