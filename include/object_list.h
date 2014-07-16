/*
 *  @author Barry Gackle
 */

#ifndef OBJECT_LIST_H
#define OBJECT_LIST_H

// Internal Headers
#include "maplocation.h"

// C++ Standard Headers
#include <list>

// Forward Declarations
namespace walls {
    class Object;
}

using std::list;

namespace walls {

class ObjectList {
 public:
    ObjectList();
    virtual ~ObjectList();

    void update(int time);

    const list<Object*>& getObjects() const;
    int getCount() const;

    void addObject(Object* object);
    void removeObject(Object* object);

 private:
    list<Object*> m_list;
};

} // walls

#endif // OBJECT_LIST_H
