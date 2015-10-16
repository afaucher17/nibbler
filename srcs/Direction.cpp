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

cardinal_e          Direction::getCardinal() const
{
    return this->_dir;
}

Position            Direction::toPosition() const
{
    Position pos_array[4] = { Position(0, 1), Position(1, 0), Position(-1, 0), Position(0, -1) };

    return pos_array[static_cast<int>(this->_dir)];
}

Direction           Direction::opposite() const
{
    return Direction(static_cast<cardinal_e>(3 - static_cast<int>(this->_dir)));
}

std::string         Direction::toString() const
{
    std::stringstream ss;
    std::string tab[4] = { "North", "East", "West", "South" };

    ss << "Direction (" << tab[static_cast<int>(this->_dir)] << ")";
    return ss.str();
}

std::ostream &      operator<<(std::ostream & o, Direction const & rhs)
{
    o << rhs.toString();
    return o;
}
