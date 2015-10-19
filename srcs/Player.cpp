#include "Player.hpp"

Player::Player(int x, int y, cardinal_e dir, type_e type, std::list<IGameObject*> list): _snake_head(SnakeHead(x, y, dir, type)), _score(0)
{
    return ;
}

Player::Player(Player const & src)
{
    *this = src;
    return ;
}

Player::~Player(void)
{
    return ;
}

Player &            Player::operator=(Player const & rhs)
{
    this->_snake_head = rhs._snake_head;
    this->_score =rhs._score;
    return *this;
}

void                Player::move()
{
    this->_snake_head.move();
}

void                Player::checkCollision(std::list<IGameObject*> object_list)
{
    this->_snake_head.checkCollision(object_list);
}

int                 Player::getScore() const
{
    return this->_score;
}
