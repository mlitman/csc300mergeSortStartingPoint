#include <iostream>

using namespace std;

void printArray(int* ar, int begin, int end)
{
    for(int i = begin; i <= end; i++)
    {
        cout << ar[i] << " ";
    }
    cout << "\n";
}

//which portion of the array am I mergeSorting....
void mergeSort(int* ar, int begin, int end)
{
    cout << "Merge Sorting: ";
    printArray(ar, begin, end);

    //if it is not a 1 list (not trivially sorted)
    if(begin != end)
    {
        //divide in half and call mergeSort on each half
        int begin1 = begin;
        int end1 = (end + begin) / 2;
        int begin2 = end1 + 1;
        int end2 = end;

        //call mergesort on the first half
        mergeSort(ar, begin1, end1);

        //call mergesort on the second half
        //this will not fire until the entire 
        //first half is dealt with
        mergeSort(ar, begin2, end2);

        //now perform the merge step
        cout << "Now we have to merge!!!!\n Start to cry Clancy!!!\n";
    }
    else
    {
        cout << "One List! Do nothing\n";
    }
    
}

int main()
{
    int ar[5] = {7,2,1,4,3};
    mergeSort(ar, 0, 4);
    printArray(ar, 0, 4);
    return 0;
}