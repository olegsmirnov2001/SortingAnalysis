#include "TXLib.h"
#include "MyLib.h"

int main ()
    {
    CreateMyWindow ();

    while (!Exit ())
        {
        matrix_t <int, 10, 15> matr;

        txSleep (10);
        }

    _txExit = true;
    return 0;
    }
