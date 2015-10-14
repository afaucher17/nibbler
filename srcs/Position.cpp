#include "Position.hpp"

Position::Position(void) : _x(0), _y(0)
{
    return ;
}

Position::Position(int const x, int const y) : _x(x), _y(y)
{
    return ;
}

Position::Position(Position const & src)
{
    *this = src;
    return ;
}

Position::~Position(void)
{
    return ;
}

Position &      Position::operator=(Position const & rhs)
{
    this->_x = rhs._x;
    this->_y = rhs._y;
    return *this;
}

int             Position::getX() const
{
    return this->_x;
}

int             Position::getY() const
{
    return this->_y;
}

Position        Position::move(Direction const & dir) const
{
    return ((*this) + dir.toPosition());
}

Position        Position::operator+(Position const & rhs) const
{
    return Position(this->_x + rhs._x, this->_y + rhs._y);
}

std::string     Position::toString() const
{
    std::stringstream ss;

    ss << "Position (" << this->_x << "; " << this->_y << ")";
    return ss.str();
}
