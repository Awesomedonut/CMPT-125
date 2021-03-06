#include "point.hpp"

float Point::getDistance(const Point &other) const { 
  float x = m_x - other.m_x;
  float y = m_y - other.m_y;

  if(x < 0){
    x = 0 - x;
  }

  if(y < 0){
    y = 0 - y;
  }

  return sqrt(x*x + y*y);
}

string Point::toString() const {
  string str(m_name);
  str += " = (";
  str += std::to_string(m_x);
  str.append(",").append(std::to_string(m_y)).append(")");
  return str;
}


void Point::printPoint() const {
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}