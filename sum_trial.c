/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result;
    for (int i=0 ; i<numsSize ; i++)
    {
        for (int j=i+1 ; j<numsSize ; j++)
        {
            if (nums[i]+nums[j]==target)
            {
                result = (int *)malloc(2*sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL; 
}

int main()
{
    int *nums, numsSize, target, returnSize;
    printf("Enter length of array: ");
    scanf("%d" ,&numsSize);

    nums = (int *)malloc(numsSize*(sizeof(int)));

    printf("Enter %d elements of the array: \n",numsSize);
    for (int i=0 ; i<numsSize ; i++)
    {
        scanf("%d" ,&nums[i]);
    }

    printf("Enter target: ");
    scanf("%d" ,&target);

    int *result = twoSum(nums, numsSize, target, &returnSize);
    
    if(result!=NULL)
    {
        for (int i=0 ; i<returnSize ; i++)
        {
            printf("%d" ,&result[i]);
            free(result);
        }
    }

    else
    {
        printf("No solution found");
    }
    free(nums);
    return 0;
}