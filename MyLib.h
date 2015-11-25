//{///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////���������� �������� �����////////////////////////////////////////////////////////////
//}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <AllColors.h>

//{///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////DEFINES////////////////////////////////////////////////////////////////////
//}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define KEY char

//{///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////������////////////////////////////////////////////////////////////////////
//}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    vect_t (vect_t vect) :
        x (vect.x),
        y (vect.y)
        {}

    vect_t (POINT vect) :
        x (vect.x),
        y (vect.y)
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

    rect_ty (RECT rect) :
        x1 (rect.left),
        y1 (rect.top),
        x2 (rect.right),
        y2 (rect.bottom)
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

//{///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////���������//////////////////////////////////////////////////////////////////
//}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const vect_t Window (GetSystemMetrics (SM_CXSCREEN), GetSystemMetrics (SM_CYSCREEN));

const int LengthText = 200;
const int LengthBigText = 2000;
const int LengthBigBigText = 20000;

const double PI = 3.1415926535;

const int Nothing = -666;

//

const KEY KeyEndWork = VK_ESCAPE;

//{///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////�������////////////////////////////////////////////////////////////////////
//}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CreateMyWindow (vect_t window)
    {
    _txWindowStyle &= ~ WS_CAPTION;
    txTextCursor (false);

    txCreateWindow (window.x, window.y);
    }

bool Clear (COLORREF color = _BLACK)
    {
    txSetFillColor (color);
    txClear ();

    if (color == _RED)
        txSleep (127);

    return true;
    }

double Dist (vect_t point1, vect_t point2)
    {
    return (sqrt (pow (point2.x - point1.x, 2) + pow (point2.y - point1.y, 2)));
    }

double Dist (double x1, double x2, double y1, double y2)
    {
    return (Dist (vect_t (x1, y1), vect_t (x2, y2)));
    }

bool Inside (rect_t area, vect_t point)
    {
    return ((point.x >= area.x1) && (point.x < area.y1) && (point.y >= area.y1) && (point.y < area.y2))
    }

bool Inside (rect_t area, POINT point)
    {
    return (Inside (area, vect_t (point)));
    }

bool SetColors (COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (color);

    return true;
    }

bool SetColors (COLORREF colorLines, COLORREF colorFill)
    {
    txSetColor (colorLines);
    txSetFillColor (colorFill);

    return true;
    }

bool SetColors (double thinknessLines, COLORREF colorLines, COLORREF colorFill)
    {
    txSetColor (colorLines, thinknessLines);
    txSetFillColor (colorFill);

    return true;
    }

bool DrawRect (rect_t rect)
    {
    txRectangle (rect.x1, rect.y1, rect.x2, rect.y2);
    }

bool DrawRect (double x1, double y1, double x2, double y2)
    {
    return DrawRect (rect_t (x1, y1, x2, y2));
    }

bool Exit (vect_t window)
    {
    const double sizeCross = 25;
    const double thinknessCross = 5;

    SetColors (thinknessCross, _RED, _NULL);
    rect_t cross (window.x - sizeCross - thinknessCross / 2,
                                         thinknessCross / 2,
                  window.x             - thinknessCross / 2,
                  sizeCross            + thinknessCross / 2);

    DrawRect (cross);

    return (((Inside (cross, txMousePos ())) && (txMouseButtons () % 2 == 1)) || (GetAsyncKeyState (KeyEndWork)));
    }

bool AllGoneBad (char* text)
    {
    const char LetterBreak = '\a';
    const char LetterPrint = '\b'

    bool breakProgramm = false;

    if (text [0] == LetterBreak)
        {
        breakProgram = true;

        text += 1;
        }

    bool printMessage = false;

    if (text [0] == LetterPrint)
        {
        printMessage = true;

        text += 1;
        }

    char sorrying [LengthText] = "";
    sprintf (sorrying, "System error (%s).\nWe're really sorry for making you buy a new computer", text);

    if (printMessage) printf (sorrying);
    else              txMessageBox (sorrying, "Windows");

    if (breakProgram)
        _txExit = true;
    }

template <typename T>
int sgn (T a)
    {
    return ((a >= 0) - (a <= 0));
    }

COLORREF MulColor (COLORREF color, double gradient)
    {
    return (RGB(((color      ) & 0xFF) * gradient,
                ((color >> 8 ) & 0xFF) * gradient,
                ((color >> 16) & 0xFF) * gradient));
    }

COLORREF RandColor ()
    {
    return (RGB (random (256), random (256), random (256)));
    }

xy_t TurnVect (xy_t vect, double alpha)
    {
    double r = sqrt (vect.x * vect.x + vect.y * vect.y);

    xy_t vectNew = {(vect.x * cos (alpha) - vect.y * sin (alpha)), (vect.x * sin (alpha) + vect.y * cos (alpha))};

    return vectNew;
    }

xy_t TurnVect (xy_t vect, double sinus, double cosinus)
    {
    double r = sqrt (vect.x * vect.x + vect.y * vect.y);

    return xy_t vectNew (vect.x * cosinus - vect.y * sinus), (vect.x * sinus + vect.y * cosinus);
    }

double LengthVect (xy_t vect)
    {
    return sqrt (vect.x * vect.x + vect.y * vect.y);
    }

/* ���������� ����������

//{/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////��� �������//////////////////////////////////////////////////////////////////////
//}/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double Dist (xy_t xy1, xy_t xy2)           //+
    {
    return sqrt ((xy1.x - xy2.x) * (xy1.x - xy2.x) + (xy1.y - xy2.y) * (xy1.y - xy2.y));
    }

double Dist (double x1, double y1, double x2, double y2)          //+
    {
    return sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

void CreateMyWindow (xy_t window)           //+
    {
    _txWindowStyle &= ~ WS_CAPTION;
    txTextCursor (false);

    txCreateWindow (window.x, window.y);
    }

void DrawGrid (rect_t area, int amountGor, int amountVer)         //don't want
    {
    double betweenGor = (area.y2 - area.y1) / amountGor;
    double betweenVer = (area.x2 - area.x1) / amountVer;

    for (int number = 0; number <= amountGor; number++)
        txLine (area.x1, area.y1 + betweenGor * number, area.x2, area.y1 + betweenGor * number);

    for (int number = 0; number <= amountVer; number++)
        txLine (area.x1 + betweenVer * number, area.y1, area.x1 + betweenVer * number, area.y2);
    }

void DrawGrid (rect_t area, const int amountGor, const int amountVer, char text [][LongText])        //don't want
    {
    DrawGrid (area, amountGor, amountVer);

    double betweenGor = (area.y2 - area.y1) / amountGor;
    double betweenVer = (area.x2 - area.x1) / amountVer;

    for (int number = 0; number < amountGor * amountVer; number++)
        {
        double y1 = area.y1 + (number % amountGor) * betweenGor;
        double y2 = y1 + betweenGor;

        double x1 = area.x1 + (number / amountGor) * betweenVer;
        double x2 = x1 + betweenVer;

        txDrawText (x1, y1, x2, y2, text [number]);
        }
    }

bool Inside (rect_t rect, xy_t point)        //+
    {
    if ((point.x >= rect.x1) && (point.x <= rect.x2) && (point.y >= rect.y1) && (point.y <= rect.y1))
        return true;

    return false;
    }

bool Krest (xy_t window)                     //+
    {
    txSetColor (_RED, 3);

    txLine (window.x - 25, 0, window.x - 25, 25);
    txLine (window.x - 25, 25, window.x, 25);
    txLine (window.x, 25, window.x, 0);
    txLine (window.x, 0, window.x - 25, 0);

    txLine (window.x - 21, 4, window.x - 4, 21);
    txLine (window.x - 4, 4, window.x - 21, 21);

    RECT krest = {window.x - 25, 0, window.x, 25};
    if ((In (txMousePos (), krest)) && (txMouseButtons () == 1))
        {
        txSetFillColor (_BLACK);
        txClear ();

        return false;
        }

    return true;
    }

void Clear (COLORREF color = _BLACK)           //+
    {
    txSetFillColor (color);
    txClear ();

    if (color == _RED)
        txSleep (100);
    }

void AllGoneBad (char text [], bool breakProgram = true)       //+
    {
    char sorrying [LongText] = "";
    sprintf (sorrying, "��������� ������ (%s). �������� ��������� �� ��������� ���������� ���������", text);

    txMessageBox (sorrying, "Windows");

    if (breakProgram)
        _txExit = true;
    }

COLORREF MulColor (COLORREF color, double gradient)
    {
    return (RGB(((color      ) & 0xFF) * gradient,
                ((color >> 8 ) & 0xFF) * gradient,
                ((color >> 16) & 0xFF) * gradient));
    }

COLORREF RandColor ()
    {
    return (RGB (random (256), random (256), random (256)));
    }

double sgn (double a)
    {
    if (a == 0)
        return 0;

    return a / abs (a);
    }

void DrawBackground (HDC background, xy_t window)
    {
    txBitBlt (txDC (), 0, 0, window.x, window.y, background, 0, 0);
    }

void txPolygon (xy_t points [], const int number)
    {
    POINT myPoints [number];
    for (int num = 0; num < number; num++)
        myPoints [num] = {points [num].x, points [num].y};

    txPolygon (myPoints, number);
    }

double MaxArray (double a [], int sizeOfArray)
    {
    double aMax = a [0];

    for (int number = 0; number < sizeOfArray; number++)
        {
        if (a [number] > aMax)
            aMax = a [number];
        }

    return aMax;
    }

xy_t TurnVect (xy_t vect, double alpha)
    {
    double r = sqrt (vect.x * vect.x + vect.y * vect.y);

    xy_t vectNew = {(vect.x * cos (alpha) - vect.y * sin (alpha)), (vect.x * sin (alpha) + vect.y * cos (alpha))};

    return vectNew;
    }

xy_t TurnVect (xy_t vect, double sinus, double cosinus)
    {
    double r = sqrt (vect.x * vect.x + vect.y * vect.y);

    xy_t vectNew = {(vect.x * cosinus - vect.y * sinus), (vect.x * sinus + vect.y * cosinus)};

    return vectNew;
    }

double LengthVect (xy_t vect)
    {
    return sqrt (vect.x * vect.x + vect.y * vect.y);
    }

//{/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////� ���///////////////////////////////////////////////////////////////////////
//}//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

*/













