//{///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////КЛАСС <<array_t>>///////////////////////////////////////////////////////
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

        DEBUG printf ("\nСоздан массив stt размера %d\n", sz);
        }

    stt (int);

    ~stt () {};

    T* Move (int);
    };

template <typename T, int Sz = 0>
struct dyn
    {
    public:

    T* data;
    int sz;

    dyn ();

    dyn (int szNew) :
        data ((T*) new T [szNew]),
        sz (szNew)
        {
        for (int number = 0; number < sz; number++)
            data [number] = T ();

        DEBUG printf ("\nСоздан массив dyn размера %d\n", sz);
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

        DEBUG printf ("\nУ массива dyn изменен размер с %d на %d", sz, szNew);

        sz = szNew;

        return data;
        }

    private:

    dyn (const dyn <T, Sz> &);
    dyn <T, Sz> & operator = (const dyn <T, Sz> &);
    };

template <template <typename, int> class Type, typename T, int Sz = 0>
class array_t : public Type <T, Sz>
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

//{///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////КЛАСС МАТРИЦЫ (МАССИВ МАССИВОВ)///////////////////////////////////////////////
//}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T, int Sz1, int Sz2>
class matrix_t : public array_t <stt, array_t <stt, T, Sz2>, Sz1>
    {
    int sz1, sz2;

    matrix_t () :
        array_t <stt, array_t <stt, T, Sz2>, Sz1> (),
        sz1 (Sz1),
        sz2 (Sz2)
        {}
    };

template <int Sz1, int Sz2>
bool PrintfMatrix (matrix_t <int, Sz1, Sz2> matr)
    {
    for (int number1 = 0; number1 < Sz1; number1++)
        for (int number2 = 0; number2 < Sz2; number2++, printf ("\n"))
            printf ("%d ", matr [number1][number2]);

    return true;
    }
















