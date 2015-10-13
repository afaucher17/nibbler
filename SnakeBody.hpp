#ifndef SNAKEBODY_HPP
# define SNAKEBODY_HPP

class SnakeBody: public ISnakeObject, public IGameObject
{
    public:
        SnakeBody(void);
        SnakeHead(Position const pos, Direction const pos, e_type type);
        SnakeBody(SnakeBody const & src);
        virtual ~SnakeBody(void);
        SnakeBody &    operator=(SnakeBody const & rhs);

        void            move();

        ISnakeObject *  getPrevious() const;
        ISnakeObject *  getNext() const;

    private:
        ISnakeObject *  _previous;
        ISnakeObject *  _next;
};

#endif
