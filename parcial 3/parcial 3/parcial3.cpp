#include <iostream>

class XVector
{
public:
    XVector(int size_map, int size_vec);
    ~XVector();
    void push_back(int);
    void push_front(int);
    int& operator[](int index);
    int** map = nullptr;
    int size_map, size_vec;
    int size = 0;
};

XVector::XVector(int sm, int sv)
{
    size_map = sm;
    size_vec = sv;
}

XVector::~XVector()
{
    
}

void XVector::push_back(int value)
{
    if (map == nullptr)
    {
        map = new int*[size_map];
        *map = new int[size_vec];
        **map = value;
        size++;
        return;
    }
    if (size == (size_map * size_vec))
    {
		int** new_map = new int*[size_map*2];
        for (int i = 0; i < size_map; i++)
        {
			new_map[i] = map[i];
		}
		delete[] map;
		map = new_map;
		size_map = size_map*2;
	}   
    if (size%size_vec == 0)
    {
        map[size / size_vec] = new int[size_vec];
    }
    map[size / size_vec][size % size_vec] = value;
    size++;

}

void XVector::push_front(int value)
{
    if (size == (size_map * size_vec))
    {
        int** new_map = new int* [size_map * 2];
        for (int i = 0; i < size_map; i++)
        {
            new_map[i] = map[i];
        }
        delete[] map;
        map = new_map;
        size_map = size_map * 2;
    }
    if (size % size_vec == 0)
    {
        map[size / size_vec] = new int[size_vec];
    }
    for (int pass = size; pass > 0; pass--)
    {
        map[pass / size_vec][pass % size_vec] = map[(pass - 1) / size_vec][(pass - 1) % size_vec];
    }
    map[0][0] = value;
    size++;
}

int& XVector::operator[](int index)
{
    return map[index / size_vec][index % size_vec];
}

void print(XVector* p)
{
    for (int i = 0; i < p->size; i++)
        std::cout << (*p)[i] << " ";
    std::cout << "\n";
}

int main()
{
    XVector v(4, 3);
    v.push_back(3); v.push_back(8); v.push_back(1);
    v.push_back(4); v.push_back(9); v.push_back(6);
    v.push_back(7);
    print(&v);
    v.push_front(5); v.push_front(2);
    print(&v);
    v.push_front(11); v.push_front(17);
    v.push_back(22);
    print(&v);
    v.push_front(33); v.push_back(77);
    print(&v);
}