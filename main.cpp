#include <iostream>
using namespace std;

// структура узла
struct Node
{
    int a;
    char c;
    Node *left, *right;
};

// функция создания узла
Node *createNode(int value, char ch)
{
    Node *newNode = new Node;
    newNode->a = value;
    newNode->c = ch;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// рекурсивная функция построения дерева
Node *Tree(int arr1[], char arr2[], int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    int mid = (left + right) / 2;
    Node *node = createNode(arr1[mid], arr2[mid]);
    node->left = Tree(arr1, arr2, left, mid - 1);
    node->right = Tree(arr1, arr2, mid + 1, right);

    return node;
}

// void printTreeDetailed(Node *root, std::string prefix = "", bool isLeft = true)
// {
//     if (root == nullptr)
//     {
//         std::cout << prefix << "+- null" << std::endl;
//         return;
//     }

//     std::cout << prefix;
//     std::cout << (isLeft ? "+-- " : "+-- ");

//     std::cout << "[" << root->a << ", " << root->c << "]" << std::endl;

//     std::string newPrefix = prefix + (isLeft ? "|  " : "    ");

//     printTreeDetailed(root->left, newPrefix, true);
//     printTreeDetailed(root->right, newPrefix, false);
// }

// функция, удаляющая элементы массива, заполненные нулями
int zero_zeros(int arr[], int size)
{
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
            if (arr1[j] < arr1[j + 1])
            {
                arr1[j] = arr1[j] + arr1[j + 1];
                arr2[j] = arr2[j] + arr2[j + 1];
                arr1[j + 1] = arr1[j] - arr1[j + 1];
                arr2[j + 1] = arr2[j] - arr2[j + 1];
                arr1[j] = arr1[j] - arr1[j + 1];
                arr2[j] = arr2[j] - arr2[j + 1];
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
    char *char_el = new char[size];  // массив, который хранит каждый символ, который присутствовал в тексте
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
        }
        else
        {
        }
    }

    arrays_sort(char_count, char_el, size);

    Node *root = Tree(char_count, char_el, 0, size - 1);
    // std::cout << "Tree Structure:" << std::endl;
    // printTreeDetailed(root);

    delete[] char_count;
    delete[] char_el;

    return 0;
}