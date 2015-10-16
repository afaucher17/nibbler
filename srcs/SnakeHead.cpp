#include "SnakeHead.hpp"

SnakeHead::SnakeHead(void) : ASnake()
{
    return ;
}

SnakeHead::SnakeHead(int x, int y, cardinal_e dir, type_e type) : ASnake(x, y, dir, type)
{
    return ;
}

SnakeHead::SnakeHead(SnakeHead const & src) : ASnake(src)
{
    return ;
}

SnakeHead::~SnakeHead(void)
{
    return ;
}

SnakeHead &         SnakeHead::operator=(SnakeHead const & rhs)
{
    ASnake::operator=(rhs);
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

bool                SnakeHead::grow()
{
    type_e tail_type;
    if (this->isTail())
    {
        Position tail_pos = this->_pos.move(this->_dir.opposite());
        if (this->_type == SNAKE_HEAD_1)
            type_e tail_type = SNAKE_TAIL_1;
        else
            type_e tail_type = SNAKE_TAIL_2;
        this->_next = new SnakeBody(tail_pos.getX(), tail_pos.getY(), this->_dir.getCardinal(), tail_type, this);
        return true ;
    }
    else
        this->getNext()->grow();
    return false;
}

bool                SnakeHead::isDead() const
{
    return this->_dead;
}

void                SnakeHead::setDirection(Direction const & dir)
{
    this->_dir = dir;
}
