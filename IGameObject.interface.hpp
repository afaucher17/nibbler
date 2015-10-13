#ifndef IGAMEOBJECT_INTERFACE_HPP
# define IGAMEOBJECT_INTERFACE_HPP
# include "Position.hpp"
# include "Direction.hpp"

enum type_e { SNAKE_HEAD_1, SNAKE_BODY_1, SNAKE_TAIL_1, SNAKE_HEAD_2, SNAKE_BODY_2, SNAKE_TAIL_2, OBSTACLE, FOOD };
class IGameObject
{
    public:
        IGameObject(void);
        virtual ~IGameObject(void) {};
        Position const &        getPosition() const = 0;
        Direction const &       getCurrentDirection() const = 0;
        Direction const &       getOldDirection() const = 0;
        type_e const            getType() const = 0;

};
#endif
