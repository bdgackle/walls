/**
 *  @author Barry Gackle
 */

// Local Headers
#include "object_list.hpp"
#include "object.hpp"

// C++ Standard Headers
#include <vector>

using std::vector;

namespace walls {

void ObjectList::update(int time)
{
    vector<Object*>::iterator iter = m_list.begin();
    while (iter != m_list.end()) {
        (*iter)->update(time);

        if ((*iter)->getIsDead()) {
            iter = m_list.erase(iter); // Erase returns next valid element
        }
        else {
            ++iter;
        }
    }
}

const vector<Object*>& ObjectList::getObjects() const
{
    return m_list;
}

const Object& ObjectList::getFirstObject() const
{
    return *(m_list.front());
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
    vector<Object*>::iterator iter = m_list.begin();
    while (iter != m_list.end()) {
        if ((*iter) == object) {
            m_list.erase(iter);
            break;
        }
        iter++;
    }
}

} // namespace walls
