#pragma once

void swap(int *r, int *s)
{
    int temp = *r;
    *r = *s;
    *s = temp;
}

void heapify(int arr[], int total_elements, int index)
{
    int largest = index, left_Child = 2 * index + 1, right_Child = 2 * index + 2;

    if(left_Child < total_elements && arr[largest] < arr[left_Child])
        largest = left_Child;

    if(right_Child < total_elements && arr[largest] < arr[right_Child])
        largest = right_Child;

    if(largest != index)
    {
        swap(&arr[index], &arr[largest]);
        heapify(arr, total_elements, largest);
    }
}

void build_max_heap(int arr[], int total_elements)
{
    for(int i = (total_elements/2) -1; i >= 0; i--)
        heapify(arr, total_elements, i);
}

void heapsort(int arr[], int total_elements)
{
    build_max_heap(arr, total_elements);
    for(int i = total_elements-1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
