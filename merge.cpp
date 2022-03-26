#include <stdio.h>
void merge(int a[], int l, int mid, int h)
{

    int i = l;
    int j = mid + 1;
    int k = l;
    int b[50];
    while (j >= mid && j <= h)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= h)
        {
            b[k] = a[j];
            j++, k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++, k++;
        }
    }
    for (k = l; k <= h; k++)
    {
        a[k] = b[k];
    }
}
void merge_sort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}
int main()
{
    int a[] = {10, 65, 44, 11, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    merge_sort(a, 0, n - 1);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}