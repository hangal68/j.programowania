#include "prosta.hpp"

void Prosta::info()
{
    if ( b > 0)
        std::cout << "Prosta " << a << "x + " << b << endl;
    else if ( b < 0)
        st::cout << "Prosta " << a << "x - " << b << endl;
}

void Prosta::policz_styczna(Point point, Parabola parabola)
{
    a = 2 * parabola.A * point.x + parabola.B;
    b = point.y - a;
}