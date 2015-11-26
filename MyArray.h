//{///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////����� <<array_t>>///////////////////////////////////////////////////////
//}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T, int Sz = 0>
class stt
    {
    T data [Sz];
    int sz;

    stt () :
        data (),
        sz (Sz)
        {
        for (int number = 0; number < sz; number++)
            data [number] = T ();
        }

    stt (int);

    ~stt ();

    Move (int);
    };

template <typename T, int Sz = 0>
class dyn
    {
    T* data;

    dyn ();

    dyn (int szNew) :
        data ((T*) new T [szNew]),
        sz (szNew)
        {
        for (int number = 0; number < sz; number++)
            data [number] = T ();
        }

    ~stt ()
        {
        delete (data);
        }

    Move (int szNew)
        {
        data = (T*) realloc (data, (T*) * szNew);
        for (int number = sz; number < szNew; number++)
            data [number] = T ();

        sz = szNew;
        }
    };

template <class Type, typename T, int Sz = 0>
class array_t : Type <T, Sz>
    {
    array_t () :
        Type ()
        {}

    array_t (int szNew) :
        Type (szNew)
        {}

    ~array_t () :
        ~Type ()
        {}

    T& operator [] (int num)
        {
        if (((num < 0) || (num >= sz)))
            AllGoneBad ("You made a mistake in array using");

        return data [num];
        }
    };