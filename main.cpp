#include <iostream>
#include <fstream>
using namespace std;

ofstream fout;

// структура узла
struct Node
{
    int a;
    char c;
    int direction;
    Node *left, *right;
};

class DataCompression
{
private:
    Node *root;                // корень дерева
    char codesTable[256][256]; // таблица кодов для символов
    char *compressedMessage;   // сжатое сообщение
    int compressedSize;        // размер сжатого сообщения

public:
    DataCompression() : root(nullptr), compressedMessage(nullptr), compressedSize(0)
    {
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
            {
                codesTable[i][j] = '\0';
            }
        }
    }

    ~DataCompression()
    {
        DeleteTree(root);
        delete[] compressedMessage;
    }

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
            return nullptr;

        if (left == right)
        {
            return createNode(arr1[left], arr2[left]);
        }

        Node *node = createNode(0, '\0');
        int mid = (left + right) / 2;

        // Рекурсивно делим массив, пока не дойдем до отдельных символов
        node->left = Tree(arr1, arr2, left, mid);
        node->right = Tree(arr1, arr2, mid + 1, right);

        return node;
    }

    void EncryptionMessage(Node *root, char path[], int depth, char codes_table[256][256])
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            for (int i = 0; i < depth; i++)
            {
                codes_table[(unsigned char)root->c][i] = path[i];
            }
            codes_table[(unsigned char)root->c][depth] = '\0';
            return;
        }

        // рекурсивный обход левого и правого поддерева
        path[depth] = '0';
        EncryptionMessage(root->left, path, depth + 1, codes_table);

        path[depth] = '1';
        EncryptionMessage(root->right, path, depth + 1, codes_table);
    }

    void Decompress(Node *root, const char *encodedMessage)
    {
        ifstream fin("CompressedFile.bin", ios::binary);
        fout.open("DecompressedFile.txt");
        if (!fin.is_open())
        {
            return;
        }

        Node *current = root;
        unsigned char byte;
        int bitPos = 7;
        while (fin.read((char *)&byte, 1))
        {
            for (int i = 7; i >= 0; i--)
            {
                bool bit = (byte >> i) & 1;
                current = bit ? current->right : current->left;
                if (!current->left && !current->right)
                {
                    fout << current->c;
                    current = root;
                }
            }
        }
        fin.close();
        fout.close();
    }
    
    // освобождаем память дерева
    void DeleteTree(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        DeleteTree(root->left);
        DeleteTree(root->right);

        delete root;
    }

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

    // запись сжатого сообщения в файл
    void ConciseMessage(const char *originalText, char codes_table[256][256])
    {
        fout.open("CompressedFile.bin", ios::binary);
        if (!fout.is_open())
        {
            return;
        }

        unsigned char buffer = 0;
        int bitCount = 0;
        for (int i = 0; originalText[i]; i++)
        {
            for (char *code = codes_table[(unsigned char)originalText[i]]; *code; code++)
            {
                buffer = (buffer << 1) | (*code - '0');
                if (++bitCount == 8)
                {
                    fout.write((char *)&buffer, 1);
                    buffer = 0;
                    bitCount = 0;
                }
            }
        }
        if (bitCount)
        {
            buffer <<= (8 - bitCount);
            fout.write((char *)&buffer, 1);
        }
        fout.close();
    }
};

int main()
{
    DataCompression data;
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

    int size = data.zero_zeros(count, 256);
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
        }
    }

    data.arrays_sort(char_count, char_el, size);

    Node *root = data.Tree(char_count, char_el, 0, size - 1);

    char codes_table[256][256] = {0};
    char path[256];
    data.EncryptionMessage(root, path, 0, codes_table);

    char compressed[1024] = "";
    int pos = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        char *code = codes_table[(unsigned char)text[i]];
        for (int k = 0; code[k] != '\0'; k++)
            compressed[pos++] = code[k];
    }
    compressed[pos] = '\0';

    cout << "1. Original: " << text << endl;
    cout << "2. Concise Message: ";
    data.ConciseMessage(text, codes_table);

    cout << "3. Decompressed: ";
    data.Decompress(root, compressed);

    delete[] char_count;
    delete[] char_el;

    return 0;
}