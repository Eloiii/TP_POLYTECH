int fold2(int a, int b)
{
    return a + b;
}

int fold3(int a, int b, int c)
{
    return fold2(a, b) * c;
}

int fold6(int a, int b, int c, int d, int e, int f)
{
    return fold3(a, b, c) - fold3(d, e, f);
}

int main(void)
{
    int y = fold6(5, 3, 12, 43, 23, 21);

    while(y);
    return 0;
}

