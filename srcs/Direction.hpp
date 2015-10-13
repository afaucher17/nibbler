#ifndef DIRECTION_HPP
# define DIRECTION_HPP
# include "Position.hpp"

enum orientation_e { NORTH, EAST, WEST, SOUTH }
class Position;
class Direction
{
    public:
        Direction(void);
        Direction(orientation_e const orientation);
        Direction(Direction const & src);
        virtual ~Direction(void);
        Direction &    operator=(Direction const & rhs);

        Position const &    toPosition() const;

    private:
        orientation_e const       _dir;
};

std::ostream &          operator<<(std::ostream & o, Direction const & rhs);
#endif
