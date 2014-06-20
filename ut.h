/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

#ifndef UT_H
#define UT_H

extern bool g_passed;

void nextTest(const char* message);
void result(bool result);
int done();

#endif // UT_H
