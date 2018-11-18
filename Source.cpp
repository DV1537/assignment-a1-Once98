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
	* H�r har jag tillg�ng till alla v�rden som jag har f�tt fr�n fil
	* i arrayen "arr"
	*/

	// Hitta tal som �r st�rre �n average h�r

	delete[]arr;
	system("pause");
	return 0;
}

void expand(int *&arr, int &capacity, int nrOfItems)
{
	// Skapa en tempor�r array med dubbelt s� stort kapacitet som den gamla (arr)
	int *tempArray = new int[capacity * 2];

	// Kopiera �ver alla items fr�n den gamla arrayen till den tempor�ra
	for (int i = 0; i < nrOfItems; i++)
	{
		tempArray[i] = arr[i];
	}

	// Ta bort den adressen som arr-pekaren pekar p�
	delete[]arr;

	// Uppdatera capacity-variabeln s� den nu har samma v�rde som den tempor�ra arrayens kapacitet
	capacity = capacity * 2;

	// Peka arr-pekaren p� minnesadressen som tempArray pekar p�
	arr = tempArray;
}

