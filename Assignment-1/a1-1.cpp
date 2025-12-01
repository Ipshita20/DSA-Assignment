#include<iostream>
using namespace std;

#define MAX 100

int arr[MAX];    
int n = 0;       

void createArray()
 {
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
	{
        cin >> arr[i];
    }
}

void displayArray() 
{
    if (n == 0)
	{
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) 
	{
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement()
 {
    if (n == MAX) 
	{
        cout << "Array is full! Cannot insert.\n";
        return;
    }
    int pos, val;
    cout << "Enter position to insert: ";
    cin >> pos;
    if (pos < 1 || pos > n + 1) 
	{
        cout << "Invalid position!\n";
        return;
    }
    cout << "Enter value: ";
    cin >> val;
    for (int i = n; i >= pos; i--)
		{
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
    cout << "Element inserted.\n";
}

void deleteElement()
 {
    if (n == 0) 
	{
        cout << "Array is empty! Cannot delete.\n";
        return;
    }
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    if (pos < 1 || pos > n) 
	{
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) 
	{
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted.\n";
}

void linearSearch()
 {
    if (n == 0) 
	{
        cout << "Array is empty!\n";
        return;
    }
    int k;
    cout << "Enter element to search: ";
    cin >> k;
    for (int i = 0; i < n; i++) 
	{
        if (arr[i] == k)
		{
            cout << "Element found at position " << i + 1 << ".\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

int main()
{
    int choice;
    while (true) 
	{
        cout << "\nMENU\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1: createArray(); 
			break;
            case 2: displayArray(); 
			break;
            case 3: insertElement();
			 break;
            case 4: deleteElement(); 
			break;
            case 5: linearSearch(); 
			break;
            case 6: cout << "Exiting program.\n"; 
			return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}


