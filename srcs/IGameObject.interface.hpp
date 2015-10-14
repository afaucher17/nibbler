#ifndef IGAMEOBJECT_INTERFACE_HPP
# define IGAMEOBJECT_INTERFACE_HPP
# include "Position.hpp"
# include "Direction.hpp"
# include <iostream>
# include <sstream>

enum type_e { SNAKE_HEAD_1 = 0, SNAKE_BODY_1, SNAKE_TAIL_1, SNAKE_HEAD_2, SNAKE_BODY_2, SNAKE_TAIL_2, OBSTACLE, FOOD, UNKNOWN };
class IGameObject
{
    public:
        IGameObject(void);
        virtual ~IGameObject(void) {};
        virtual Position const &        getPosition() const = 0;
        virtual Direction const &       getCurrentDirection() const = 0;
        virtual Direction const &       getOldDirection() const = 0;
        virtual type_e const            getType() const = 0;

};
#endif
