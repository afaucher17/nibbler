#ifndef FOODFACTORY_HPP
# define FOODFACTORY_HPP
# include "Food.hpp"

class FoodFactory
{
    public:
        static Food const &     randomSpawn();
        static Food const &  spawnAtPos(Position _pos);

    private:
        FoodFactory(void);
        FoodFactory(FoodFactory const & src);
        virtual ~FoodFactory(void);
        FoodFactory &    operator=(FoodFactory const & rhs);
};

#endif
