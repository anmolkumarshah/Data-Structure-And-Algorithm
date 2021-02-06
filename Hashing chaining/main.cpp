#include <iostream>
#include<vector>
#include<forward_list>

using namespace std;

class Hash{
public:
    int size;
    vector<forward_list<int>> hash_table;
    Hash(int size)
    {
        this->size = size;
        vector<forward_list<int>> temp(size);
        hash_table = temp;
    }

    int hash_index(int value)
    {
        return value%size;
    }

    void insert(int value)
    {
        int index = hash_index(value);
        hash_table[index].push_front(value);
        hash_table[index].sort();
    }

    void search(int value)
    {
        int index = hash_index(value);
        for(auto i = hash_table[index].begin();i!=hash_table[index].end();i++)
        {
            if(value == *i)
            {
                cout<<value<<" is found"<<endl;
                return;
            }
        }
        cout<<value<<" is Not found"<<endl;
        return;
    }

};


int main()
{
    Hash h(10);
    h.insert(12);
    h.insert(22);
    h.insert(5);
    h.search(22);
    return 0;
}
