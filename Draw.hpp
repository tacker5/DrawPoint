#ifndef DRAW_HPP_INCLUDE
#define DRAW_HPP_INCLUDE

#include <iostream>
#include <vector>

typedef std::pair<int, int> point ;
typedef std::vector<point> vpoint;

vpoint input();
int maxs(vpoint p);
void sort(vpoint &p);
int *hashs(vpoint p, int maxf);
void draw(vpoint p);

#endif
