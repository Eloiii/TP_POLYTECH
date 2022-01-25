int main() {
    int comparaisons = 0;
    double x, y ;
    scanf ("%f %f", &x, &y) ;
    while (x != 0) {
        if ((g(x)>0) && (x != y)) {
            x = g1(x) ;
        }
        else { 
            y = g2(y) ; 
        }
        comparaisons++;
    } ;
    printf ("%d\n",x);
    return 0;
}