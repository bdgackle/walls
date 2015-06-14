/*
 *  @author Barry Gackle
 */

#ifndef OBJECT_LIST_HPP
#define OBJECT_LIST_HPP

// Local Headers
#include "maplocation.hpp"

// C++ Standard Headers
#include <list>

namespace walls {
class Object;

class ObjectList {
 public:
    ObjectList();

    void update(int time);

    const std::list<Object*>& getObjects() const;
    Object* getFirstObject();
    int getCount() const;

    void addObject(Object* object);
    void removeObject(Object* object);

 private:
    std::list<Object*> m_list;
};

} // namespace walls

#endif // OBJECT_LIST_HPP
