#ifndef BASE_HPP
#define BASE_HPP

/*
** Base only strictly needs a public VIRTUAL destructor.
** "virtual" is the important word: it's what makes
** "delete basePtr;" correctly run the destructor of whichever derived
** class (A, B or C) the object actually is, instead of running only
** Base's destructor and leaking the rest of the derived object.
**
** The default constructor is added here just so we can print a
** message and see when a Base (or Base-derived) object comes to life.
*/
class Base
{
    public:
        Base();
        virtual ~Base();
};

#endif
