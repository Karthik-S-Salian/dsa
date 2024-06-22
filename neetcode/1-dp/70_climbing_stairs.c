int climbStairs(int n){
    int one_step = 1;
    int two_step = 1;
    int temp;

    for(int i=0;i<n-1;i++){
        temp = one_step;
        one_step = two_step + one_step;
        two_step = temp;
    }
    return one_step;
}