//Floyds tortoise hare algorithm
int findDuplicate(int *nums, int numsSize)
{
    int i = 0, j = 0;
    while (1)
    {
        i = nums[i];
        j = nums[nums[j]];
        if (i == j)
            break;
    }

    j = 0;
    while (1)
    {
        i = nums[i];
        j = nums[j];
        if (i == j)
            return i;
    }
}