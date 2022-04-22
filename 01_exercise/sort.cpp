#include <iostream>
using namespace std;

void print_char_array(int size, char **argv);
double *create_double_array(int size, char **argv);
void print_double_array(int size, double *double_array);
int compare(const void *x, const void *y);
void bubble_sort(int size, double *double_array);

int main(int argc, char **argv)
{
  double *double_array;
  int size = argc - 1;

  cout << endl
       << "Printing Input" << endl;
  cout << "--------------" << endl;
  print_char_array(size, argv);

  double_array = create_double_array(size, argv);

  cout << endl
       << "Printing Unsorted Array" << endl;
  cout << "---------------------" << endl;
  print_double_array(size, double_array);

  // qsort(double_array, size, sizeof(double), compare);
  bubble_sort(size, double_array);

  cout << endl
       << "Printing Sorted Array" << endl;
  cout << "---------------------" << endl;
  print_double_array(size, double_array);

  free(double_array);
  return 0;
}

/*****************************************************************************/
// display
/*****************************************************************************/

void print_char_array(int size, char **argv)
{
  cout << "You have entered " << size << " arguments"
       << endl;

  for (int i = 0; i < size; i++)
    cout << argv[i + 1] << endl;
}

void print_double_array(int size, double *double_array)
{
  for (int i = 0; i < size; i++)
    cout << double_array[i] << endl;
}

/*****************************************************************************/
// memory allocation
/*****************************************************************************/

double *create_double_array(int size, char **argv)
{
  double *double_array = (double *)malloc(size * sizeof(double));

  for (int i = 0; i < size; i++)
    *(double_array + i) = stod(argv[(i + 1)]);

  return double_array;
}

/*****************************************************************************/
// std::qsort
/*****************************************************************************/

int compare(const void *x, const void *y)
{
  return (*(double *)x - *(double *)y);
}

/*****************************************************************************/
// custom bubble sort
/*****************************************************************************/

void bubble_sort(int size, double *double_array)
{
  for (int i = 0; i < (size - 1); i++)
  {
    for (int j = 0; j < (size - i - 1); j++)
    {
      if (double_array[j] > double_array[j + 1])
        swap(double_array[j], double_array[j + 1]);
    }
  }
}