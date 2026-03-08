#include <iostream>
using namespace std;

// функция, удаляющая элементы массива, заполненные нулями
int zero_zeros(int arr[], int size) {
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

    return size;
    
}

int main()
{
    // создаём массив
    char text[] = "Hello World!!!!Hello World";

    // массив для подсчёта
    int count[256] = {0};

    cout << text << endl;

    for (int i = 0; text[i] != '\0'; i++)
    {
        unsigned char c = text[i];
        count[c]++;
    }

    int size = zero_zeros(count, 256);
    int *char_count = new int[size]; // массив, который хранит количество элементов каждого символа
    int j = 0;

    for (int i = 0; i < 256; i++)
    {
        if (count[i] > 0)
        {
            if (i >= 32 && i <= 126) // печатные символы
            {
                char_count[j] = count[i];
                cout << char(i) << ": " << char_count[j] << endl;
                j++;
            }
            else
            
            { // управляющие символы
                cout << "[" << i << "]: " << count[i] << endl;
            }
        } else {

        }
    }

    delete[] char_count;

    return 0;
}