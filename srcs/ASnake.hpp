#ifndef ASNAKE_HPP
# define ASNAKE_HPP
#include "AGameObject.hpp"

class ASnake : public AGameObject
{
    public:
        ASnake(void);
        ASnake(int x, int y, cardinal_e dir, type_e type);
        ASnake(ASnake const & src);
        virtual ~ASnake(void);
        ASnake &    operator=(ASnake const & rhs);

        virtual Direction const &   getOldDirection() const;
        virtual bool                lethalCollision() const;

        virtual bool                move();
        virtual bool                grow() = 0;

        virtual bool                isTail() const;
        virtual ASnake *            getNext() const;
    protected:
        type_e      _type;
        ASnake *    _next;

};

#endif
