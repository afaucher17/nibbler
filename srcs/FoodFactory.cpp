#include "FoodFactory.hpp"

bool                    FoodFactory::randomSpawn(std::list<IGameObject*> & list, int height, int width)
{
    std::random_device  rd;
    std::mt19937        gen(rd());
    std::uniform_int_distribution<> randomh(0, height);
    std::uniform_int_distribution<> randomw(0, width);
    Food                            food(randomw(gen), randomh(gen));

    for (int i = 0; i < 10000; i++)
    {
        <`4:/* code */`>
    }
}
