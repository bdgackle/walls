/**
 *  @author Barry Gackle
 */

// Internal Headers
#include "update_map.h"

namespace walls {

UpdateMap::UpdateMap(int size) :
    m_size(size) {
    m_values = new bool[m_size];
    reset();
}

UpdateMap::~UpdateMap() { delete [] m_values; }

int UpdateMap::get(int index) const { 
    if ((index < m_size) && (index > 0))
        return m_values[index];
    else
        return true;
}

int UpdateMap::getFast(int index) const { return m_values[index]; }

void UpdateMap::set(int index) {
    if ((index < m_size) && (index > 0))
        m_values[index] = true;
}

void UpdateMap::setFast(int index) { m_values[index] = true; }

void UpdateMap::reset() {
    for (int i = 0; i < m_size; i++) {
        m_values[i] = false;
    }
}

} // walls
