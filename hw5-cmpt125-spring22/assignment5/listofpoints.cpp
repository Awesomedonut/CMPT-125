#include "listofpoints.hpp"
#include <vector>

ListOfPoints::ListOfPoints() {
}

void ListOfPoints::addAfter(Point& newPt, string name) {
  // implement me
}

void ListOfPoints::addPoint(Point &newPt){
  points.push_back(newPt);
  
}



//Point& ListOfPoints::getPointAt(unsigned int i) {
//  return m_points[i];
//}

void ListOfPoints::swapPoint(int first, int second){
  std::swap(points[first], points[second]);
}

void ListOfPoints::removePoint(){
  points.pop_back();
}

void ListOfPoints::printList() const{
  int size = points.size();
  for (int i = 0; i < size; i++)
  {
    cout << points[i].toString();
  }
}

void ListOfPoints::draw() const{
  string pointsDraw[21][21];
  int size = points.size();
  for (int j = 0; j < 21; j++)
  {
    for (int k = 0; k < 21; k++)
    {
      pointsDraw[j][k] = '-';
    }
  }

  for (int i = 0; i < size; i++)
  {
    pointsDraw[points[i].getX()][points[i].getY()] = points[i].getName();
  }

  cout << endl << "drawing the points..." << endl;
  for (int j = 20; j >= 0; j--)
  {
    for (int k = 0; k < 21; k++)
    {
      cout << pointsDraw[k][j] << ' ';
    }
    cout << endl;
  }
}
   vector<Point> ListOfPoints::getPoints()
    {
      return points;
    }
    int ListOfPoints::getSize() const
    {
      return points.size();
    }

    Point ListOfPoints::getPoint(int num) const
    {
      return points[num];
    }
