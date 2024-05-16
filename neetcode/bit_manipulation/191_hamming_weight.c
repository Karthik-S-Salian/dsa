int hammingWeight(int n) {
    int count = n&1;

    while(n){
        n=n>>1;
        count +=n&1;
    }
    return count;
}