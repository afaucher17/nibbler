#ifndef SNAKEHEAD_HPP
# define SNAKEHEAD_HPP
# include <list>
# include "AGameObject.hpp"
# include "SnakeBody.hpp"

class SnakeHead : public AGameObject
{
    public:
        SnakeHead(void);
        SnakeHead(int x, int y, cardinal_e dir, type_e type);
        SnakeHead(SnakeHead const & src);
        virtual ~SnakeHead(void);
        SnakeHead &    operator=(SnakeHead const & rhs);

        bool            move(std::list<AGameObject*> list);
        bool            checkCollision(std::list<AGameObject*> list);
        void            grow();

        SnakeBody *     getNext() const;
        bool            isDead() const;

        void            setDirection(Direction const & dir);

    private:
        SnakeBody *     _next;
        type_e          _type;
        bool            _dead;
};

#endif
