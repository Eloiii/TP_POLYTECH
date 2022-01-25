/* fonctions définies en assembleur */
void _writec(char c);
char _readc(void);

int main(void)
{
    char c = 'H';

    while(1) {
        c = _readc();
        _writec(c);
    }

    return 0;
}

