#ifndef FOODFACTORY_HPP
# define FOODFACTORY_HPP
# include <list>
# include <random>
# include "Food.hpp"

class FoodFactory
{
    public:
        static Food &           randomSpawn(std::list<IGameObject*> & list, int height, int width);
        static Food &           spawnAtPos(std::list<IGameObject*> list, int height, int width, Position pos);

    private:
        FoodFactory(void);
        FoodFactory(FoodFactory const & src);
        virtual ~FoodFactory(void);
        FoodFactory &    operator=(FoodFactory const & rhs);
};

#endif
