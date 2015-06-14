/**
 *  @author Barry Gackle
 */

// Local Headers
#include "object_list.hpp"
#include "object.hpp"

// C++ Standard Headers
#include <list>

using std::list;

namespace walls {

ObjectList::ObjectList() {}

ObjectList::~ObjectList() {}

void ObjectList::update(int time)
{
    list<Object*>::iterator iter = m_list.begin();
    while (iter != m_list.end()) {
        (*iter)->update(time);

        if ((*iter)->getIsDead()) {
            iter = m_list.erase(iter); // erase() returns iter++
        }
        else {
            ++iter;
        }
    }
}

const list<Object*>& ObjectList::getObjects() const
{
    return m_list;
}

Object* ObjectList::getFirstObject()
{
    return m_list.front();
}

int ObjectList::getCount() const
{
    return m_list.size();
}

void ObjectList::addObject(Object* object)
{
    m_list.push_back(object);
}

void ObjectList::removeObject(Object* object)
{
    m_list.remove(object);
}

} // namespace walls
