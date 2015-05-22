/**
 *  @author Barry Gackle
 */

#ifndef OBJECT_LIST_HPP
#define OBJECT_LIST_HPP

// Local Headers
#include "maplocation.hpp"

// C++ Standard Headers
#include <vector>

namespace walls {
class Object;

class ObjectList {
 public:
    void update(int time);

    const std::vector<Object*>& getObjects() const;
    const Object& getFirstObject() const;
    Object* getFirstObject();
    int getCount() const;

    void addObject(Object* object);
    void removeObject(Object* object);

 private:
    std::vector<Object*> m_list;
};

} // namespace walls

#endif // OBJECT_LIST_HPP
