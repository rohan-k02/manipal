#include<stdio.h>

int binary(int item, int a[], int low, int high)
{
	int mid;
	if(low > high)
		return -1;
	mid=(low+high)/2;
	if(item==a[mid])
		return mid;
	else if(item<a[mid])
	{
		high=mid-1;
		return binary(item, a, low, high);
	}
	else
	{
		low=mid+1;
		return binary(item, a, low, high);
	} 
}

void main()
{
    int arr[5], target, found;

    for(int i = 0; i < 5; i++)
    {
        arr[i] = i+1;
    }

    printf("Enter the number to search for: ");
    scanf("%d", &target);

    found = binary(target, arr, 1, 5);

    if(found == -1)
        printf("Number not found");

    else
        printf("Number found at index %d!", found);
}


