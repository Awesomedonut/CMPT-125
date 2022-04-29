#include "tspsolver.hpp"

#include <vector>
#include <list>

using namespace std;

TSPSolver::TSPSolver(ListOfPoints &list) {
  m_list = list;
  m_solution = TSPCycle(list);
}

void TSPSolver::solve() {
  int size = m_list.getSize();
  for(int i = 3; i < size; i++){
   // cout << "i " << i << "\n";
    int bestIndex = 0;
    Point newPoint = m_list.getPoint(i);
    TSPCycle defaultCycle = m_solution.insertPointAndCreateNewList(newPoint, bestIndex);
    int defaultLength = defaultCycle.getLength();
    //cout << "deflen " << defaultLength << "\n";
    for(int j = 1; j < m_solution.getSize(); j++){
      TSPCycle newCycle = m_solution.insertPointAndCreateNewList(newPoint, j);
      int newLength = newCycle.getLength();
      //cout << "newlen " << newLength << "\n";
      if(newLength < defaultLength){
        bestIndex = j;
        defaultLength = newLength;
      }
    }
    //    cout << "i(2) " << i << "\n";

    m_solution = m_solution.insertPointAndCreateNewList(newPoint, bestIndex);
    
  }
}


TSPCycle& TSPSolver::getSolution() {
  return m_solution;
}