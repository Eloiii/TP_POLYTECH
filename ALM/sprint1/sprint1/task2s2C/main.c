int square(int a);
int max(int a ,int b , int c);
int puissance(int a,int b);
int puissanceBis(int a,int b);

int main(void)
{
    int quatre = 4;
    int res = 0;

    // Checkpoint 0

    res = square(quatre);

    // Checkpoint 1

    res = square(res);

    // Checkpoint 2
    int a , b ,c;
    a=2 ;
    b=3;
    c=6;
    res=max(a,b,c);
    res=puissance(a,b);
    res=puissanceBis(a,b);
    while(1);

    return res;

}
int max(int a ,int b , int c){

    int m;
    if (a>b){
        m=a;
    }
    else{
        m=b;
    }
    if (c>m){
        m=c;
    }
return m ;
}

int puissance(int a,int b){
    int m = 1;
    for (int i = 0; i < b; ++i)
    {
        m = m * a;
    }
    return m ; 

}

int puissanceBis(int a,int b){
    if(b==0) {
        return 1;
    }
    else {
        return a * puissanceBis(a, b-1);
    }
}
