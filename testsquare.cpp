/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// Standard Headers
#include <stddef.h>

// Internal Headers
#include "ut.h"
#include "square.h"

using walls::Square;

int main()
{
    Square* c = new Square;
    Square* n = new Square;
    Square* s = new Square;
    Square* e = new Square;
    Square* w = new Square;

    // Check initial values
    nextTest("Default values");
    result(c->getNorth() == NULL);
    result(c->getSouth() == NULL);
    result(c->getEast() == NULL);
    result(c->getWest() == NULL);
    result(c->getX() == 0);
    result(c->getY() == 0);
    result(c->isWall() == false);
    result(c->isOutside() == false);

    nextTest("Getter/Setter");
    c->setNorth(n); result(c->getNorth() == n);
    c->setSouth(s); result(c->getSouth() == s);
    c->setEast(e); result(c->getEast() == e);
    c->setWest(w); result(c->getWest() == w);
    c->setX(10); result(c->getX() == 10);
    c->setY(15); result(c->getY() == 15);
    c->setOutside(true); result(c->isOutside() == true);
    c->setWall(true); result(c->isWall() == true);

    nextTest("checkNeighbors()");
    result(n->checkNeighbors() == true);
    result(s->checkNeighbors() == true);
    result(e->checkNeighbors() == true);
    result(w->checkNeighbors() == true);
    result(c->checkNeighbors() == false);

    return done();
}
