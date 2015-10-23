#ifndef GAME_CPP
# define GAME_CPP
# include "AGameObject.hpp"
# include "Player.hpp"

class Game
{
    public:
        Game(Game const & src);
        Game(int height, int width);
        virtual ~Game(void);
        Game &    operator=(Game const & rhs);

        void init();
        void move();
        void checkCollision();

        std::list<IGameObject*> &   getObjectList();
        int                         getWidth() const;
        int                         getHeight() const;
        std::list<int>              getScores() const;


    private:
        Game(void);
        std::list<IGameObject*>     _object_list;
        std::list<Player>           _players;
        int                         _height;
        int                         _width;
};
#endif
