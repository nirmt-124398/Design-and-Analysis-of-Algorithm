// 1. Write a program to find out a roll number from college database using binary search algorithm.

#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int binarySearch(vector<int>& studentroll_num,int left,int right,int target)
{
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if (studentroll_num[mid] == target)
        {
            return mid;    
        }
        else if (studentroll_num[mid] < target)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    
    return -1; 
}

int main()
{
    vector<int> roll={2302721,2302722,2302723,2302724,2302725,2302726,2302727,2302728,2302729,2302730};
    int target=0;

do {
    cout << "Enter a student Roll Number: " << endl;
    cin >> target;
    if (cin.fail()) {
        cin.clear(); // clear the error flag
        cin.ignore(INT_MAX, '\n'); // ignore the rest of the line
    }
} while (cin.fail()); // repeat if the input was not an integer

    int result=binarySearch(roll,0,roll.size()-1,target);

    if (result!=-1)
    {
        cout<<"This Roll Number is present at "<<result<<". \n";
    }
    else
    {
        cout<<"This Roll Number is not present.";
    }
    
    return 0;
}
