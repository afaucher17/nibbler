#ifndef SNAKEHEAD_HPP
# define SNAKEHEAD_HPP
# include "AGameObject.hpp"
# include "ISnakeObject.interface.hpp"

class SnakeHead : public ISnakeObject, public AGameObject
{
    public:
        SnakeHead(void);
        SnakeHead(int x, int y, cardinal_e dir, type_e type);
        SnakeHead(SnakeHead const & src);
        virtual ~SnakeHead(void);
        SnakeHead &    operator=(SnakeHead const & rhs);

        void            move();

        ISnakeObject *  getPrevious() const;
        ISnakeObject *  getNext() const;

        void            setDirection(Direction const & dir);

    private:
        ISnakeObject *  _previous;
        type_e          _type;
};

#endif
