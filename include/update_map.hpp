/*
 *  @author Barry Gackle
 */

#ifndef UPDATE_MAP_HPP
#define UPDATE_MAP_HPP

namespace walls {

class UpdateMap {
 public:
    UpdateMap(int size);
    virtual ~UpdateMap();

    int get(int index) const;
    int getFast(int index) const;

    void set(int index);
    void setFast(int index);

    void reset();

 private:
    bool* m_values;
    int m_size;
};

} // namespace walls

#endif // UPDATE_MAP_HPP
