//Eric Lin

#include <iostream>
#include <cstdlib>

using namespace std;

bool sort_three_numbers(float & num_1, float & num_2, float & num_3);

int main()
{
  cout << "Please enter three numbers: ";
  float num1 = 0, num2 = 0, num3 = 0;
  cin >> num1 >> num2 >> num3;

  bool isSorted = sort_three_numbers(num1, num2, num3);

  cout << num1 << " " << num2 << " " << num3 << endl;
  if (isSorted)
    cout << "The numbers were already sorted in descending order." << endl;
  else
    cout << "The numbers were not already sorted in descending order." << endl;

  return EXIT_SUCCESS;
}

bool sort_three_numbers(float & num_1, float & num_2, float & num_3)
{
  if (num_1 > num_2 && num_2 > num_3)
    return true;
  else
  {
    if (num_1 < num_2)
    {
      float temp = num_1;
      num_1 = num_2;
      num_2 = temp;
    }
    if (num_1 < num_3)
    {
      float temp = num_1;
      num_1 = num_3;
      num_3 = temp;
    }
    if (num_2 < num_3)
    {
      float temp = num_2;
      num_2 = num_3;
      num_3 = temp;
    }
    return false;
  }
}

/* Sample Outputs

Please enter three numbers: 1.2 7.3 3.5
7.3 3.5 1.2
The numbers were not already sorted in descending order.
--------------------------------
Process exited after 4.864 seconds with return value 0

Please enter three numbers: 3 5 23
23 5 3
The numbers were not already sorted in descending order.
--------------------------------
Process exited after 5.012 seconds with return value 0

Please enter three numbers: 99 43 12
99 43 12
The numbers were already sorted in descending order.
--------------------------------
Process exited after 4.932 seconds with return value 0

*/
