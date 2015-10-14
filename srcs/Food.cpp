#include "Food.hpp"

Food::Food(void) : AGameObject(), _type(FOOD)
{
    return ;
}

Food::Food(int x, int y, cardinal_e dir) : AGameObject(x, y, dir), _type(FOOD)
{
    return ;
}

Food::Food(Food const & src) : AGameObject(src)
{
    *this = src;
    return ;
}

Food::~Food(void)
{
    return ;
}

std::ostream &          operator<<(std::ostream & o, Food const & rhs)
{
    o << rhs.toString();
    return o;
}
