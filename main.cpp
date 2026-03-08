#include <iostream>
using namespace std;

// структура узла
struct Node
{
    int a;
    char c;
    Node *left, *right;
};

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

// сортировка двух массивов по убыванию
void arrays_sort(int arr1[], char arr2[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr1[j] < arr1[j+1])
            {
                arr1[j] = arr1[j] + arr1[j+1];
                arr2[j] = arr2[j] + arr2[j+1];
                arr1[j+1] = arr1[j] - arr1[j+1];
                arr2[j+1] = arr2[j] - arr2[j+1];
                arr1[j] = arr1[j] - arr1[j+1];
                arr2[j] = arr2[j] - arr2[j+1];
            }
            
        }
        
    }
    
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
    char *char_el = new char[size]; // массив, который хранит каждый символ, который присутствовал в тексте
    int j = 0;

    for (int i = 0; i < 256; i++)
    {
        if (count[i] > 0)
        {
            if (i >= 32 && i <= 126) // печатные символы
            {
                char_count[j] = count[i];
                char_el[j] = char(i);
                cout << char_el[j] << ": " << char_count[j] << endl;
                j++;
            }
            else
            { // управляющие символы
                cout << "[" << i << "]: " << count[i] << endl;
            }
        } else {

        }
    }

    arrays_sort(char_count, char_el, size);
    

    delete[] char_count;
    delete[] char_el;

    return 0;
}