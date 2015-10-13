#ifndef FOOD_HPP
# define FOOD_HPP
# include "AGameObject.hpp"

class Food : public AGameObject
{
    public:
        Food(void);
        Food(Position const & _pos, Direction const & _dir);
        Food(Food const & src);
        virtual ~Food(void);
        Food &      operator=(Food const & rhs);

        void        move() {};

};
std::ostream & operator<<(std::ostream & o, Food const & rhs);
#endif
