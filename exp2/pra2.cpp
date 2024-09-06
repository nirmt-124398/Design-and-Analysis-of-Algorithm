// 2. WRITE A PROGRAM TO SORT THE CLASS ROLL NUMBERS OF YOUR CLASS USING MERGE SORT ALGORITHM AND DETERMINE THE TIME REQUIRED TO SORT THE ELEMENTS.

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
/* Function to merge the subarrays of a[] */
void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int LeftArray[n1], RightArray[n2]; // temporary arrays
    /* copy data to temp arrays */
    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];
    i = 0;   /* initial index of first sub-array */
    j = 0;   /* initial index of second sub-array */
    k = beg; /* initial index of merged sub-array */
    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}
/* Function to print the array */
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    clock_t start_time = clock();
    int l = 2;
    int b = 2;
    int size;
    cout << "Name= Nirmit Rampal\nURN= 2302729\n";
    cout << "Enter the size of the students database: ";
    cin >> size;
    int a[size];
    cout << "Enter the Student roll no.\n";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    int n = size;
    cout << "Before sorting Students roll no. are - \n";
    printArray(a, n);
    mergeSort(a, 0, n - 1);
    cout << "\nAfter sorting Students roll no. are - \n";
    printArray(a, n);
    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "\n(It took " << time_taken << " seconds to execute)\n";
    string f_n = "O(n^1)";
    string time_complexity = masterTheorem(l, b, f_n);
    cout << "Time Complexity: " << time_complexity << endl;
    return 0;
}