#ifndef FOOD_HPP
# define FOOD_HPP
# include "AGameObject.hpp"

class Food : public AGameObject
{
    public:
        Food(int x, int y);
        Food(Food const & src);
        virtual ~Food(void);
        Food &      operator=(Food const & rhs);

    private:
        Food(void);
        type_e      _type;

};
std::ostream & operator<<(std::ostream & o, Food const & rhs);
#endif
