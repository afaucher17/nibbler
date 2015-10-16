#include "SnakeHead.hpp"

SnakeHead::SnakeHead(void) : AGameObject()
{
    return ;
}

SnakeHead::SnakeHead(int x, int y, cardinal_e dir, type_e type) : AGameObject(x, y, dir), _type(type), _next(NULL)
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
    this->_next = rhs._next;
    return *this;
}


bool                SnakeHead::checkCollision(std::list<AGameObject*> list)
{
        for (std::list<AGameObject*>::iterator it = list.begin(); it != list.end(); ++it)
            if ((this->_pos == (*it)->getPosition()))
            {
                if ((*it)->lethalCollision())
                    this->_dead = true;
                else if ((*it)->getType() == FOOD)
                    this->grow();
                return true ;
            }
        return false ;
}

bool                SnakeHead::move(std::list<AGameObject*> list)
{
    if (this->_pos.move(this->_dir) != this->getNext()->getPosition())
    {
        this->_pos = this->_pos.move(this->_dir);
        return true ;
    }
    return false ;
}

SnakeBody *         SnakeHead::getNext() const
{
    return this->_next;
}

void                SnakeHead::setDirection(Direction const & dir)
{
    this->_dir = dir;
}
