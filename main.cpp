#include "TXLib.h"
#include "MyLib.h"

int main ()
    {
    CreateMyWindow ();

    while (!Exit ())
        {
        txSleep (1);

        Clear ();
        }

    _txExit = true;
    return 0;
    }













