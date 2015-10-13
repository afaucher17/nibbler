#ifndef AGAMEOBJECT_HPP
# define AGAMEOBJECT_HPP
# include "IGameObject.interface.hpp"

class AGameObject: public IGameObject
{
    public:

        Position const &        getPosition() const;
        Direction const &       getCurrentDirection() const;
        Direction const &       getOldDirection() const;

        void                    move() = 0;
        bool                    isToBeDeleted();

    private:
        AGameObject(void);
        AGameObject(AGameObject const & src);
        virtual ~AGameObject(void);
        AGameObject &           operator=(AGameObject const & rhs);

    protected:
        Position                _pos;
        Direction               _dir;
        type_e                  _type;
        bool                    _to_be_deleted;
};

std::ostream &                  operator<<(std::ostream & o, AGameObject const & rhs);
#endif
