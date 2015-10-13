#ifndef ISNAKEOBJECT_INTERFACE_HPP
# define ISNAKEOBJECT_INTERFACE_HPP

class ISnakeObject
{
    public:
        ISnakeObject(void);
        virtual ~ISnakeObject(void) {};

        ISnakeObject *      getPrevious() const = 0;
        ISnakeObject *      getNext() const = 0;
};

#endif
