void f() {
    int operations = 0;
    int comparaions = 0;
    int x, i, s;
    float m;
    i = 0 ; s = 0 ;
    while (i<N) {
        i = i+1 ;
        operations++;
        comparaions++;
        x = T[i] ; 
        if (x != -1) { s = s + x ;  operations++;}
        comparaions++;
    } ;
    m = s/i ;
    printf ("%f\n",m);
}