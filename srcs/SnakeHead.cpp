#include "SnakeHead.hpp"

SnakeHead::SnakeHead(void) : AGameObject()
{
    return ;
}

SnakeHead::SnakeHead(int x, int y, cardinal_e dir, type_e type) : AGameObject(x, y, dir), _type(type), _previous(NULL)
{
    return ;
}

SnakeHead::SnakeHead(SnakeHead const & src) : AGameObject(src)
{
    return ;
}

SnakeHead::~SnakeHead(void)
{
    return ;
}

SnakeHead &         SnakeHead::operator=(SnakeHead const & rhs)
{
    AGameObject::operator=(rhs);
    this->_previous = rhs._previous;
    return *this;
}

ISnakeObject *      SnakeHead::getPrevious() const
{
    return this->_previous;
}

ISnakeObject *      SnakeHead::getNext() const
{
    return NULL;
}

void                SnakeHead::setDirection(Direction const & dir)
{
    this->_dir = dir;
}


