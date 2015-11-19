class vect_t
    {
    double x, y;

    vect_t () :
        x (0),
        y (0)
        {}

    vect_t (double Ax, double Ay) :
        x (Ax),
        y (Ay)
        {}

    vect_t (vect_t A) :
        x (A.x),
        y (A.y)
        {}

    vect_t& operator + (vect_t vect)
        {
        return vect_t (x + vect.x, y + vect.y);
        }

    vect_t& operator += (vect_t vect)
        {
        x += vect.x;
        y += vect.y;

        return this;
        }

    vect_t& operator - (vect_t vect)
        {
        return vect_t (x - vect.x, y - vect.y);
        }

    vect_t& operator -= (vect_t vect)
        {
        x -= vect.x;
        y -= vect.y;

        return this;
        }

    vect_t& operator * (double k)
        {
        return vect_t (x * k, y * k);
        }

    vect_t& operator *= (double k)
        {
        x *= k;
        y *= k;

        return this;
        }

    vect_t& operator / (double k)
        {
        return vect_t (x / k, y / k);
        }

    vect_t& operator /= (double k)
        {
        x /= k;
        y /= k;

        return this;
        }
    };

class rect_t
    {
    double x1, x2, y1, x2;

    rect_t () :
        x1 (0),
        y1 (0),
        x2 (0),
        y2 (0)
        {}

    rect_t (Ax1, Ax2, Ay1, Ay2) :
        x1 (Ax1),
        y1 (Ay1),
        x2 (Ax2),
        y2 (Ay2)
        {}

    rect_t (rect_t rect) :
        x1 (rect.x1),
        y1 (rect.y1),
        x2 (rect.x2),
        y2 (rect.y2)
        {}

    rect_t& operator + (double x, double y)
        {
        return rect_t (x1 + x, y1 + y, x2 + x, y2 + x);
        }

    rect_t& operator - (double x, double y)
        {
        return rect_t (x1 - x, y1 - y, x2 - x, y2 - x);
        }
    }
















