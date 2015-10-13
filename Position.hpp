#ifndef POSITION_HPP
# define POSITION_HPP
# include "Direction.hpp"

class Direction;
class Position
{
    public:
        Position(void);
        Position(Position const & src);
        virtual ~Position(void);
        Position &          operator=(Position const & rhs);

        int                 getX() const;
        int                 getY() const;
        Position &          move(Direction const & dir) const;
        Position &          operator+(Position const & rhs);

    private:
        int const           _x;
        int const           _y;
};

std::ostream &              operator<<(std::ostream & o, Position const & rhs);
#endif
