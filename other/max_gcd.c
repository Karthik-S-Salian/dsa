#include <stdio.h>

int main()
{

        int no;
        scanf("%d", &no);
        int i = no / 2;
        int divisor = 3;

        while (i > 0)
        {
            if (no % i == 0)
            {
                printf("%d", i);
                break;
            }
            i = i - i / divisor;
            divisor++;
        }
}