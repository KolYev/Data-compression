#include <iostream>
using namespace std;


int main()
{
    //создаём лист
    int arr[5]{6, 4, 2, 9, 7};
    //создаём указатель на нулевой элемент массива
    int *ptr = arr;


    for (int i = 0; i < 5; i++)
    {
        cout<<ptr[i]<<endl;
    }
    
    return 0;
}