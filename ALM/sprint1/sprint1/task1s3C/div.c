/************************************************************
  Division de a par b, le quotient est dans res, le reste dans a */

int main ()
{
    int a, b, res;

    a=15;
    b=4;
    res=0;
   while(a >= b) {
    a = a - b;
    res = res + 1;
   }

    while(1){}
}

