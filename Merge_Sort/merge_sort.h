#pragma once

void Merge(int *array, int low, int high, int mid)
{
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;

    // Merge the two parts into temp[].
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            temp[k] = array[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = array[j];
            k++;
            j++;
        }
    }

    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid)
    {
        temp[k] = array[i];
        k++;
        i++;
    }

    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = array[j];
        k++;
        j++;
    }

    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
        array[i] = temp[i-low];
}

void merge_sort(int* unsorted, int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = (left + right)/2;
        merge_sort(unsorted, left, mid);
        merge_sort(unsorted, mid+1, right);
        Merge(unsorted, left, right, mid);
    }

}

//
// Created by atrivedi on 8/20/18.
//
