#include "Direction.hpp"

Direction::Direction(void) : _dir(NORTH)
{
    return ;
}

Direction::Direction(cardinal_e const cardinal) : _dir(cardinal)
{
    return ;
}

Direction::Direction(Direction const & src)
{
    *this = src;
    return ;
}

Direction::~Direction(void)
{
    return ;
}

Direction &         Direction::operator=(Direction const & rhs)
{
    this->_dir = rhs._dir;
    return *this;
}

Position            Direction::toPosition() const
{
    Position pos_array[4] = { Position(0, 1), Position(1, 0), Position(-1, 0), Position(0, -1) };

    return pos_array[static_cast<int>(this->_dir)];
}
