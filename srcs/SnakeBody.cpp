#include "SnakeBody.hpp"

SnakeBody::SnakeBody(void) : ASnake()
{
    return ;
}

SnakeBody::SnakeBody(int x, int y, cardinal_e dir, type_e type, ASnake * previous) : ASnake(x, y, dir, type), _previous(previous)
{
    return ;
}

SnakeBody::SnakeBody(SnakeBody const & src): ASnake(src)
{
    return ;
}

SnakeBody::~SnakeBody(void)
{
    ASnake::~ASnake();
    delete this->_previous;
}

SnakeBody &         SnakeBody::operator=(SnakeBody const & rhs)
{
    ASnake::operator=(rhs);
    this->_previous = rhs._previous;
    return *this;
}

Direction           SnakeBody::getCurrentDirection() const
{

    int             adir = static_cast<int>(this->getPrevious()->_dir.getCardinal());
    int             ndir = static_cast<int>(this->_dir.getCardinal());

    if (this->getPrevious()->_dir.getCardinal() == NORTH || this->getPrevious()->_dir.getCardinal() == )
}

bool                SnakeBody::move()
{
    if (ASnake::move())
    {
        this->_dir = this->getPrevious()->getCurrentDirection();
        return true;
    }
    return false;
}

bool                SnakeBody::grow(std::list<IGameObject*> list)
{
    type_e          tail_type;

    if (this->isTail())
    {
        Position tail_pos = this->_pos.move(this->_dir.opposite());
        this->_next = new SnakeBody(tail_pos.getX(), tail_pos.getY(), this->_dir.getCardinal(), this->_type, this);
        if (this->_type == SNAKE_TAIL_1)
            this->_type = SNAKE_BODY_1;
        else
            this->_type = SNAKE_BODY_2;
        return true ;
    }
    else
        this->getNext()->grow(list);
    return false;
}

ASnake *     SnakeBody::getPrevious() const
{
    return this->_previous;
}

ASnake *     SnakeBody::getNext() const
{
    return this->_next;
}
