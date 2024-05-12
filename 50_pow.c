double myPow(double x, int n) {
    if(x==1 || x==0)
        return x;
    if(n==0)
        return 1;
    double response = myPow(x,n/2);
    double result = response*response;
        if(n&1)
            if(n<0)
                result/=x;
            else
                result*=x;
    return result;
}