#include <iostream>
#include <fstream>


void expand(int *&arr, int &capacity, int nrOfItems);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int capacity = 1, nrOfItems = 0;
	int *arr = new int[capacity];

	std::ifstream input;
	input.open("example.txt");

	if (input.is_open())
	{
		while (!input.eof())
		{
			if (nrOfItems == capacity)
			{
				expand(arr, capacity, nrOfItems);
			}

			input >> arr[nrOfItems];
			std::cout << arr[nrOfItems] << " ";
			nrOfItems++;
		}
	}
	else
	{
		std::cout << "File not open" << std::endl;
	}
	std::cout << std::endl;
	/*
	* Här har jag tillgång till alla värden som jag har fått från fil
	* i arrayen "arr"
	*/

	// Hitta tal som är större än average här

	delete[]arr;
	system("pause");
	return 0;
}

void expand(int *&arr, int &capacity, int nrOfItems)
{
	// Skapa en temporär array med dubbelt så stort kapacitet som den gamla (arr)
	int *tempArray = new int[capacity * 2];

	// Kopiera över alla items från den gamla arrayen till den temporära
	for (int i = 0; i < nrOfItems; i++)
	{
		tempArray[i] = arr[i];
	}

	// Ta bort den adressen som arr-pekaren pekar på
	delete[]arr;

	// Uppdatera capacity-variabeln så den nu har samma värde som den temporära arrayens kapacitet
	capacity = capacity * 2;

	// Peka arr-pekaren på minnesadressen som tempArray pekar på
	arr = tempArray;
}

