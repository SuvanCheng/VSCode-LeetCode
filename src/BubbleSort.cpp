#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}


int main()
{
    int b[7]={5,2,3,7,1,6,4};

    BubbleSort(b, 7);
    for(int i = 0; i < 7 ; ++i){
        cout << b[i] << " ";
    }
    cout << endl;

}