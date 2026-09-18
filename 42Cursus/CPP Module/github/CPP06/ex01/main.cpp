#include "Serializer.hpp"

/*
** A pointer can be turned into a plain integer
** (uintptr_t) and back into a pointer again, without losing any
** information: it changes only how we LABEL the address, never the
** address itself, and never touches the memory it points to.
**
**   Data*  ---- serialize() ---->  uintptr_t
**   uintptr_t  -- deserialize() -->  Data*
*/
int main()
{
    std::cout << "Creating Data objects..." << std::endl;

    Data blank;
    Data student(42, "Afzal");
    Data studentCopy(student);

    blank = student;

    std::cout << std::endl << "Testing serialization:" << std::endl;

    Data* original = &student;

    uintptr_t raw = Serializer::serialize(original);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer  : " << original << std::endl;
    std::cout << "Serialized value  : " << raw << std::endl;
    std::cout << "Restored pointer  : " << restored << std::endl;

    if (original == restored)
        std::cout << "Pointers are identical." << std::endl;
    else
        std::cout << "Pointers are different." << std::endl;

    std::cout << "Restored id       : " << restored->id << std::endl;
    std::cout << "Restored name     : " << restored->name << std::endl;

    return 0;
}