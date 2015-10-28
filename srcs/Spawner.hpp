#ifndef SPAWNER_HPP
#define SPAWNER_HPP
# include <vector>
# include <random>
# include "IGameObject.interface.hpp"

class GameObjectFactory
{
    public:
        static Food                 createRandomFood(std::vector<Position> av_positions);
        static Food                 createFood(Position pos);
        static Obstacle             createRandomObstacle(std::vector<Position> av_positions);
        static Obstacle             createObstacle(Position pos);
        static SnakeHead            createRandomSnakeHead(std::vector<Position> av_positions);
        static SnakeHead            createSnakeHead(Position pos, cardinal_e dir);
        static SnakeBody            createSnakeBody(Position pos, cardinal_e dir, type_e type, ASnake * previous)

    private:
        Spawner();
        Spawner(Spawner const & src);
        virtual ~Spawner(void);
        Spawner &    operator=(Spawner const & rhs);

        static Position             _randomSpawn(std::vector<Position> av_positions);
};

#endif
