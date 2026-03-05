#include <iostream>
using namespace std;

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
        }
    }

    return 0;
}