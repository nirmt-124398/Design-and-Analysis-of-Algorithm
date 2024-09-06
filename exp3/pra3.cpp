// 3. WRITE A PROGRAM TO SORT THE UNIVERSITY ROLL NUMBERS OF YOUR CLASS USING QUICK SORT METHOD AND DETERMINE THE TIME REQUIRED TO SORT THE ELEMENTS.

#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

string masterTheorem(int a, int b, string f_n)
{
    double log_b_a = log(a) / log(b);
    int n_power;
    if (f_n == "O(1)")
    {
        n_power = 0;
    }
    else if (f_n.find("O(n^") == 0)
    {
        n_power = stod(f_n.substr(4, f_n.size() - 5));
    }
    else
    {
        return "Unsupported f(n) format";
    }
    if (log_b_a < n_power)
    {
        return "O(n^" + to_string(n_power) + ")";
    }
    else if (log_b_a == n_power)
    {
        return "O(n^" + to_string(n_power) + " * log n)";
    }
    else
    {
        return "O(n^" + to_string(log_b_a) + ")";
    }
}

// FUNCTION TO SWAP TWO ELEMENTS
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// PARTITION FUNCTION
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // PIVOT ELEMENT
    int i = (low - 1);     // INDEX OF SMALLER ELEMENT

    for (int j = low; j < high; j++)
    {
        // IF CURRENT ELEMENT IS SMALLER THAN OR EQUAL TO PIVOT
        if (arr[j] <= pivot)
        {
            i++; // INCREMENT INDEX OF SMALLER ELEMENT
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// QUICKSORT FUNCTION
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        // PARTITIONING INDEX
        int pi = partition(arr, low, high);

        // RECURSIVELY SORT ELEMENTS BEFORE AND AFTER PARTITION
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// FUNCTION TO PRINT AN ARRAY
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    clock_t start_time = clock();

    cout << "NAME= NIRMIT RAMPAL\nCRN= 2302729\n";

    int arr[]={2302729,2302721,2302723,2302724,2302722,2302725,2302726,2302728,2302727,2302730};
    int n=10;
    // DISPLAY UNSORTED ARRAY
    cout << "UNSORTED ARRAY: \n";
    printArray(arr, n);

    // PERFORM QUICKSORT
    quicksort(arr, 0, n - 1);

    // DISPLAY SORTED ARRAY
    cout << "SORTED ARRAY: \n";
    printArray(arr, n);

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
//    - Recurrence relation: \( T(n) = 2T(n/2) + O(n) \)

    int a=2,b=2;
    cout << "(IT TOOK " << time_taken << " SECONDS TO EXECUTE)\n";
    string f_n = "O(n)";
    string time_complexity = masterTheorem(a, b, f_n);
    cout << "Time Complexity: " << time_complexity << endl;
    

    return 0;
}
