#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;


int main()
{
    vector<int> x;

    x.push_back(72);
    x.push_back(954);
    x.push_back(3000);
    x.push_back(123);

    for (int i = 0; i < x.size(); i++)
    {
        cout<<x[i]<<endl;
    }
    
    return 0;
}