//{///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////ÊËÀÑÑ <<array_t>>///////////////////////////////////////////////////////
//}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T, int Sz = 0>
struct stt
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

    T* Move (int);
    };

template <typename T, int Sz = 0>
struct dyn
    {
    T* data;
    int sz;

    dyn ();

    dyn (int szNew) :
        data ((T*) new T [szNew]),
        sz (szNew)
        {
        for (int number = 0; number < sz; number++)
            data [number] = T ();
        }

    ~dyn ()
        {
        delete (data);
        }

    T* Move (int szNew)
        {
        data = (T*) realloc (data, sizeof (*data) * szNew);
        for (int number = sz; number < szNew; number++)
            data [number] = T ();

        sz = szNew;

        return data;
        }

    private:

    dyn (const dyn <T, Sz> &);
    dyn <T, Sz> & operator = (const dyn <T, Sz> &);
    };

template <template <typename, int> class Type, typename T, int Sz = 0>
class array_t : private Type <T, Sz>
    {
    public:

    array_t () :
        Type <T, Sz> ()
        {}

    array_t (int szNew) :
        Type <T, Sz> (szNew)
        {}

    T& operator [] (int num)
        {
        if (((num < 0) || (num >= this->sz)))
            AllGoneBad ("You made a mistake in array using");

        return this->data [num];
        }
    };
