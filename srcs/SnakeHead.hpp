#ifndef SNAKEHEAD_HPP
# define SNAKEHEAD_HPP

class SnakeHead : public ISnakeObject, public IGameObject
{
    public:
        SnakeHead(void);
        SnakeHead(Position const pos, Direction const pos, e_type type);
        SnakeHead(SnakeHead const & src);
        virtual ~SnakeHead(void);
        SnakeHead &    operator=(SnakeHead const & rhs);

        void            move();

        ISnakeObject *  getPrevious() const;
        ISnakeObject *  getNext() const;

        void            setDirection(Direction const & dir);

    private:
        ISnakeObject *  _previous;
};

#endif
