
#include <memory>
#include "c.h"
namespace ups {
class Person {
public:
    Person() {}

    ~Person() {}

public:
    static std::shared_ptr<C> c_ptr;
    static int                x;
};
int ups::Person::x = 10;
}  // namespace ups