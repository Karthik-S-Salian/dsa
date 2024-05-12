#include<stdio.h>

int main(){
    int c,n,z,prvs;

    scanf("%d",&z);

    for(int i=0;i<z;i++){
        scanf("%d",&n);
        scanf("%d",&prvs);
        int found=0;
        for(int j=1;j<n;j++){
            scanf("%d",&c);
            if(!found && prvs!=c){
                found=1;
                printf("%d",j);
            }
            prvs=c;
        }
    }
}