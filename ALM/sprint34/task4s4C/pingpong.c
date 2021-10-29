int ping(int p1);
int pong(int p1);

int ping(int p1)
{
    return pong(p1 + 42);
}

int pong(int p1)
{
    int a = p1 + 42;
    int b = a * 3;

    return ping(a + b);
}

int main(void)
{
    return ping(3);
}

