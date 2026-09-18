#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
    public:
        Array(void);
        Array(unsigned int n);
        Array(Array const &src);
        ~Array(void);

        Array &operator=(Array const &rhs);

        T &operator[](unsigned int index);
        T const &operator[](unsigned int index) const;

        unsigned int size(void) const;

        class SizeExceedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    private:
        T *array;
        unsigned int len;
};

# include "Array.tpp"

#endif
