int parties(int p, int q)
{
    if(p == 0) {
        return 1;
    }
    else if(q == 0) {
        return 0;
    }
    else if(q > p) {
        return parties(p, p);
    }
    else {
        return parties(p-q, q) + parties(p, q-1);
    }
}

int main(void)
{
    int y = parties(5, 3);

    while(y);
    return 0;
}

