int fold2(int a, int b)
{
    return a + b;
}

int fold3(int a, int b, int c)
{
    return fold2(a, b) * c;
}

int main(void)
{
    int y = fold3(5, 3, 12);

    while(y);
    return 0;
}

