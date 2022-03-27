#include <stdio.h>
int binarysearch(int a[], int key, int low, int high)
{
    if (low >= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {

            return binarysearch(a, key, mid + 1, high);
        }
        else if (a[mid] > key)
        {

            return binarysearch(a, key, low, mid - 1);
        }
    }
    return -1;
}

int main()
{
    int a[] = {5, 8, 10, 12, 15, 20, 25, 30, 35, 40};
    int n = sizeof(a) / sizeof(a[0]);
    int key = 55;
    int b = binarysearch(a, key, 0, n - 1);
    if (b == -1)
    {
        printf("element not found\n");
    }
    else
    {
        printf("element found at %d\n", b + 1);
    }

    return 0;
}