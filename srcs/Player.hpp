#ifndef PLAYER_CPP
# define PLAYER_CPP
# include "SnakeHead.hpp"
# include "Game.hpp"

class Game;
class Player
{
    public:
        Player(void);
        Player(Player const & src);
        virtual ~Player(void);
        Player &    operator=(Player const & rhs);

        int         getScore() const;
        void        move(std::list<IGameObject*> object_list);
        void        checkCollisions(std::list<IGameObject*> object_list);

    private:
        SnakeHead   _snakehead;
        int         score;
};

#endif
