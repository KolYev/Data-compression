#include <iostream>
using namespace std;

// функция, удаляющая элементы массива, заполненные нулями
void zero_zeros(int arr[], int& size) {
    int new_size = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            arr[new_size] = arr[i];
            new_size++;
        } 
    }

    size = new_size;
    
}

int main()
{
    // создаём массив
    char text[] = "Hello World!!!!Hello World";
    // создаём указатель на нулевой элемент массива
    char *ptr = text;

    // массив для подсчёта
    int count[256] = {0};

    cout << text << endl;

    for (int i = 0; text[i] != '\0'; i++)
    {
        unsigned char c = text[i];
        count[c]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] > 0)
        {
            if (i >= 32 && i <= 126) // печатные символы
            {
                cout << char(i) << ": " << count[i] << endl;
            }
            else
            { // управляющие символы
                cout << "[" << i << "]: " << count[i] << endl;
            }
        } else {

        }
    }

    return 0;
}