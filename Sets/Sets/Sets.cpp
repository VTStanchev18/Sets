#include <iostream>
using namespace std;

class Set
{
	int size = 0;
	int DEFAULTSIZE = 10;
	int* elements = new int[size];
public:
    Set(int s);
	~Set();

	bool contains(int n);
	Set* unionWith(Set& Y);
	Set* intersectWith(Set& Y);
	Set* complementWith(Set& Y);
	Set* complimentSimetric(Set& X, Set& Y);

	void sort();
	int calcDegree();
	int enterFromKeyboard();
	void display();
};

//Set::Set()
//{
//    size = DEFAULTSIZE;
//     elements = new [size];
//}

Set::Set(int s)
{
    size = s;
    elements = new [size];

    for (int i = 0; i < size; i++)
    {
        elements[i] = enterFromKeyboard();
    }
}

Set::~Set()
{
    delete this;
}

bool Set::contains(int n)
{
    for (int i = 0; i < size; i++)
    {
        if (elements[i] == n)
        {
            return true;
        }
    }
}

Set* Set::unionWith(Set& y)
{
    Set* newSet = new Set();
    int count = 0;
    newSet->size = this->size + y.size;
    newSet->elements = new [size];
    for (int i = 0; i < this->size; i++)
    {
        newSet->elements[count++] = this->elements[i];
    }
    for (int i = 0; i < y.size; i++)
    {
        newSet->elements[count++] = y.elements[i];
    }
    return newSet;
}

Set* Set::intersectWith(Set& y)
{
    Set* newSet = new Set();
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (y.contains(elements[i]))
        {
            newSet->elements[count++] = elements[i];
        }
    }

    return newSet;
}

Set* Set::complementWith(Set& y)
{

}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Set::sort()
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (elements[j] > elements[j + 1])
            {
                swap(&elements[j], &elements[j + 1]);
            }
        }
    }
}

int enterFromKeyboard()
{
    int n;
    cin >> n;
    return n;
}

void Set::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << elements[i] << " ";
    }
}

int main()
{
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
