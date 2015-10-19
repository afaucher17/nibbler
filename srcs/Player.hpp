#ifndef PLAYER_CPP
# define PLAYER_CPP
# include "SnakeHead.hpp"
# include "Game.hpp"

class Game;
class Player
{
    public:
        Player(int x, int y, cardinal_e dir, type_e type, std::list<IGameObject*> list);
        Player(Player const & src);
        virtual ~Player(void);
        Player &    operator=(Player const & rhs);

        void        move();
        void        checkCollision(std::list<IGameObject*> object_list);

        int         getScore() const;

    private:
        Player(void);
        SnakeHead   _snake_head;
        int         _score;
};

#endif
