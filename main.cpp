#include <iostream>
using namespace std;


int main()
{
    //создаём массив
    char text[] = "Hello World";
    //создаём указатель на нулевой элемент массива
    char *ptr = text;

    for (int i = 0; i < 5; i++)
    {
        cout<<ptr[i]<<endl;
    }
    
    return 0;
}