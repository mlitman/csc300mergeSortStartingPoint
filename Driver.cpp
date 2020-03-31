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
        int length = end - begin + 1;
        int temp[length];
        for(int i = 0; i < length; i++)
        {
            if(begin1 > end1)
            {
                //begin2 is the winner by default
                temp[i] = ar[begin2];
                begin2++;
            }
            else if(begin2 > end2)
            {
                //begin1 is the winner by default
                temp[i] = ar[begin1];
                begin1++;
            }
            else if(ar[begin1] < ar[begin2])
            {
                temp[i] = ar[begin1];
                begin1++;
            }
            else
            {
                temp[i] = ar[begin2];
                begin2++;
            }  
        }

        //now temp has the 2 halves of the list merged
        //we now have to copy those values back into ar
        for(int arPos = begin, tempPos = 0; tempPos < length; tempPos++, arPos++)
        {
            ar[arPos] = temp[tempPos];
        }
    }
}

int main()
{
    int ar[5] = {7,2,1,4,3};
    mergeSort(ar, 0, 4);
    printArray(ar, 0, 4);
    return 0;
}