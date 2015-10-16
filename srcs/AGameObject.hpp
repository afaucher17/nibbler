#ifndef AGAMEOBJECT_HPP
# define AGAMEOBJECT_HPP
# include "IGameObject.interface.hpp"


class AGameObject: public IGameObject
{
    public:
        AGameObject(AGameObject const & src);
        AGameObject(int x, int y, cardinal_e dir);
        virtual ~AGameObject(void);
        AGameObject &           operator=(AGameObject const & rhs);

        Position const &        getPosition() const;
        Direction const &       getCurrentDirection() const;
        bool                    isToBeDeleted() const;

        virtual bool            lethalCollision() const = 0;

        std::string             toString() const;

    private:
        std::string             _typeToString(type_e const type) const;

    protected:
        AGameObject(void);
        Position                _pos;
        Direction               _dir;
        type_e                  _type;
        bool                    _to_be_deleted;
};

std::ostream &                  operator<<(std::ostream & o, AGameObject const & rhs);
#endif
