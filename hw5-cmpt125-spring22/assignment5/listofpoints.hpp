#ifndef _LIST_OF_POINT_HPP
#define _LIST_OF_POINT_HPP

#include <iostream>
#include <vector>

#include "point.hpp"

#define MAX_X 20
#define MAX_Y 20

using namespace std;

// the class stores an ordered list of points
// used to store the input to the problem
// may be also used to store a partial solution to the TSP problem
class ListOfPoints
{
  protected: //  children of the class can access the protected data fields
    // currently m_points stores the points in a vector 
    // but you may decide to use a different container. Up to you
    std::vector<Point> points;

  public:

    ListOfPoints();
    void addAfter(Point& newPt, string name);


    void addPoint(Point &newPt);
    // ListOfPoints insertPointAndCreateNewList(Point &newPt, int index);

    Point& getPointAt(unsigned int i);
    void removePoint();
    void swapPoint(int first, int second);
    void printList() const;
    void draw() const;
    vector<Point> getPoints();
    int getSize() const;
    Point getPoint(int num) const;

};

#endif
