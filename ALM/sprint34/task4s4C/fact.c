int fact(int a)
{
    if(a == 1) {
        return 1;
    }

    return fact(a-1) * a;
}

int main(void)
{
    int x = 5;
    int y = fact(x);

    while(y);
    return 0;
}

