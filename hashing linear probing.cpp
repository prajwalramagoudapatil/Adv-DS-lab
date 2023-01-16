#include <iostream>
#include <strings.h>
using namespace std;
class hashtable
{
	int size = 7;
	int arr[7];
	int count = 0;

public:
	void initialArray()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = -9999;
		}
	}
	int hashFunction(int k)
	{
		return k % size;
	}
	void add(int v)
	{
		int x = hashFunction(v);
		cout << "The x value:" << x << endl;
		if (arr[x] != -9999)
		{
			// Linear Probing due to collision
			int i = x + 1;
			while (arr[i] != -9999)
			{
				i += 1;
				continue;
			}
			cout << i;
			arr[i] = v;
			count++;
		}

		else if (arr[x] == -9999)
		{
			arr[x] = v;
			count++;
		}
	}
	void Search(int k)
	{
		int x = hashFunction(k);
		if (arr[x] != -9999)
		{
			// Value Found
			cout << "The value is : " << arr[x] << endl;
		}
		else
		{
			// Value Not Found Exception
			cout << "No value Found" << endl;
		}
	}
	void print()
	{
		cout << "Key"
			 << "  Value " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i << "  :  " << arr[i] << "\n";
		}
	}
	void deleteElement(int k)
	{
		int x = hashFunction(k);
		if (arr[x] == -9999)
		{
			cout << "The space is Already Empty . Nothing found ." << endl;
		}
		else
		{
			int y = arr[x];
			arr[x] = -9999;
			cout << "The element \"" << y << "\" is successfully deleted." << endl;
			count--;
		}
	}
};
int main()
{
	hashtable ht;
    int ele, n;
	ht.initialArray();
	// Adding key value Pair
	cout<<"Enter number of elements:";
	cin>>n;
	for(int i=0; i < n ; i++ ){
        cin>>ele;
        ht.add(ele);
	}
/*	ht.add(4);
	ht.add(6);
	ht.add(12);
	ht.add(22);
	ht.add(16);
	ht.add(9);
*/
	ht.print();

	cout<<"Enter element to search : ";
	cin>>ele;
	ht.Search(ele);
	return 0;
}
