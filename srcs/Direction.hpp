#ifndef DIRECTION_HPP
# define DIRECTION_HPP
# include "Position.hpp"
# include <iostream>

enum cardinal_e { NORTH = 0, EAST, WEST, SOUTH, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST};
class Position;
class Direction
{
    public:
        Direction(void);
        Direction(cardinal_e const cardinal);
        Direction(Direction const & src);
        virtual ~Direction(void);
        Direction &    operator=(Direction const & rhs);

        Position        toPosition() const;

        std::string     toString() const;

    private:
        cardinal_e          _dir;
};

std::ostream &          operator<<(std::ostream & o, Direction const & rhs);
#endif
