#ifndef _TSP_SOLVER_HPP
#define _TSP_SOLVER_HPP

#include <iostream>

#include "listofpoints.hpp"
#include "tspcycle.hpp"

class TSPSolver {
  private:  
    ListOfPoints m_list;
    TSPCycle m_solution;
  public:
    TSPSolver(ListOfPoints &list);
    void solve();
    TSPCycle& getSolution();
};

#endif