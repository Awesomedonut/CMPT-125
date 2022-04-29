#ifndef _TSP_CYCLE_HPP
#define _TSP_CYCLE_HPP

#include <iostream>
#include "listofpoints.hpp"

// the class stores a cycle that traverses all points in some order
// it is used to store the solution to the problem
// it is a subclass of ListOfPoints
class TSPCycle : public ListOfPoints{
  // private:
  // ListOfPoints points;  
  public:
    TSPCycle(){}

    TSPCycle(ListOfPoints &list) {
      for(int i = 0; i < 3; i++){
        Point a = list.getPoint(i);
        TSPCycle::addPoint(a);
      }
}
TSPCycle insertPointAndCreateNewList(Point &newPt, int index){
  //points.insert(newPt,index);
  TSPCycle tmp;
  for(int i = 0; i < points.size(); i ++){
    tmp.addPoint(points[i]);
    if(i == index){
      tmp.addPoint(newPt);
    }
  }
  return tmp;
}

    float getLength() const {
      float length = 0;
      int size = TSPCycle::getSize();
      for (int i = 0; i < size-1; i++)
      {
        length += TSPCycle::getPoint(i).getDistance(TSPCycle::getPoint(i+1));
      }
      length += TSPCycle::getPoint(size-1).getDistance(TSPCycle::getPoint(0));
      return length;
    }
};

#endif
