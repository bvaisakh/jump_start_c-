#include <iostream>
using namespace std;

void print_char_array(int size, char **argv);
double *create_double_array(int size, char **argv);
void print_double_array(int size, double *double_array);
int compare(const void *x, const void *y);
void bubble_sort(void * const base, int total_elems, unsigned long elem_size, int (*compare)(const void *, const void *));
void swap(const void *_x, const void *_y, unsigned long item_size);

// const void *, const void *

int main(int argc, char **argv)
{
  double *double_array;
  int size = argc - 1;

  cout << endl
       << "Input" << endl;
  cout << "-----" << endl;
  print_char_array(size, argv);

  double_array = create_double_array(size, argv);

  cout << endl
       << "Unsorted Array" << endl;
  cout << "--------------" << endl;
  print_double_array(size, double_array);

  // qsort(double_array, size, sizeof(double), compare);
  bubble_sort(double_array, size, sizeof(double), compare);

  cout << endl
       << "Sorted Array" << endl;
  cout << "------------" << endl;
  print_double_array(size, double_array);

  free(double_array);
  return 0;
}

/*****************************************************************************/
// display
/*****************************************************************************/

void print_char_array(int size, char **argv)
{
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

void bubble_sort(void * const base, int total_elems, unsigned long elem_size, int (*compare)(const void *, const void *))
{
  char *base_ptr = (char *) base;

  for (int i = 0; i < (total_elems - 1); i++)
  {
    for (int j = 0; j < (total_elems - 1); j++)
    {
      char *f_elem = base_ptr + (elem_size * j);
      char *s_elem = base_ptr + (elem_size * (j + 1));
      
      if (compare(f_elem, s_elem) > 0)
      {
        swap(f_elem, s_elem, elem_size);
      }
    }
  }
}

void swap(const void *_x, const void *_y, unsigned long item_size)
{
  char *x = (char *)_x;
  char *y = (char *)(_y);
  do
  {
    char temp = *x;
    *x++ = *y;
    *y++ = temp;
  } while (--item_size > 0);
}