#include "Spawner.hpp"

Position                Spawner::_randomSpawn(std::vector<Position> av_positions, type_e type)
{
    std::random_device  rd;
    std::mt19937        gen(rd());
    std::uniform_int_distribution<>     random_pos(0, av_positions.size() - 1);

    return (av_positions[random_pos(gen)]);
}

Food                    Spawner::createRandomFood(std::vector<Position> av_positions)
{
    return Food(Spawner::_randomSpawn(av_positions));
}

Food                    Spawner::createFood(Position pos)
{
    return Food(pos);
}

Obstacle                Spawner::createRandomObstacle(std::vector<Position> av_positions)
{
    return Obstacle(Spawner::_randomSpawn(av_positions));
}

Obstacle                Spawner::createObstacle(Position pos)
{
    return Obstacle(pos);
}

SnakeHead               Spawner::createRandomSnakeHead(std::vector<Position> av_positions)
{
    return SnakeHead(Spawner::_randomSpawn(av_positions));
}

SnakeHead               Spawner::createSnakeHead(Position pos, cardinal_e dir)
{
    return SnakeHead(pos, dir);
}

SnakeBody               Spawner::createSnakeBody(Position pos, cardinal_e dir, type_e type, ASnake * previous)
{
    return SnakeBody(pos, dir, type, previous);
}
