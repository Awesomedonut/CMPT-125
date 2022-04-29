#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;

void testPoint() {
  Point origin(2,2,"A");
  Point sec(2,6,"B");

  Point hello(5,6,"C");
  Point hello2(5,9,"D");
  
  ListOfPoints test;
  test.addPoint(origin);
    test.addPoint(sec);

  test.addPoint(hello);
  test.addPoint(hello2);
  for(int i = 0; i < test.getSize(); i++){
    cout << "point " << test.getPoint(i);
  }

  test.draw();
cout << "hello test 27" << endl;
TSPSolver testingsolve(test);
  testingsolve.solve();


  

  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;

  
  

  Point q(3,4,"Q");
  //distance should be 5
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;

}


// gets a list of points and runs the solver on this list
// used in test1 and test2 below
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  solver.solve();
  TSPCycle solution = solver.getSolution();


  cout << "Solution found is: " << endl;
  solution.printList();
  cout << "the length of the solution is: " << solution.getLength() << endl;
}

void test1() {
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    string s;
    s = 'A'+i;
    p = Point(i,0,s);
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<50;i++) {
    p = Point(rand() % 1000, rand() % 1000,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  // some coordinates values more than 20, so we do not use draw here

  testSolver(inputTSP);
}

void test4() {
  Point p[5] = {Point(1,2,"A"),
                Point(2,3,"B"),
                Point(3,4,"C"),
                Point(4,5,"D"),
                Point(5,6,"E")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<5;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test5() {
  Point p[3] = {Point(5,5,"A"),
                Point(10,10,"B"),
                Point(7,7,"C")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<3;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test6() {
  Point p[10] = {Point(4,2,"A"),
                Point(6,3,"B"),
                Point(3,15,"C"),
                Point(4,5,"D"),
                Point(18,6,"E"),
                Point(5,17,"F"),
                Point(3,19,"G"),
                Point(15,6,"H"),
                Point(7,6,"I"),
                Point(11,4,"J")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<10;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test7() {
  Point p[8] = {Point(0,2,"A"),
                Point(2,6,"B"),
                Point(0,6,"C"),
                Point(5,0,"D"),
		            Point(17,6,"E"),
                Point(4,9,"F"),
                Point(3,7,"G"),
                Point(2,6,"H")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<8;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test8() {
ListOfPoints inputTSP;
  Point p(3,4,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<15;i++) {
    string s;
    s = 'A'+i;
    p = Point(0,i,s);
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test9() {
  Point p[9] = {Point(0,0,"A"),
                Point(0,6,"B"),
                Point(20,6,"C"),
                 Point(4,4,"D"),
                Point(18,6,"E"),
                Point(1,20,"F"),
                Point(3,13,"G"),
                Point(12,6,"H"),
                Point(8,6,"I")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<9;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test10() {
  Point p[8] = {Point(2,1,"A"),
                Point(10,3,"B"),
                 Point(2,15,"C"),
                Point(4,9,"D"),
                Point(18,6,"E"),
                Point(5,17,"F"),
                Point(11,19,"G"),
                Point(15,6,"H")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<8;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


int main() {

  cout << "****Test point**" << endl;
  testPoint();
  cout << "****End of test point**" << endl << endl;

  cout << "****test1**:" << endl;
  test1();
  cout << "****end of test1**:" << endl << endl;
 
  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;

 
  cout << "****test3**:" << endl;
  test3();
  cout << "****end of test3**:" << endl << endl;

  cout << "****test4**:" << endl;
  test4();
  cout << "****end of test4**:" << endl << endl;

  cout << "****test5**:" << endl;
  test5();
  cout << "****end of test5**:" << endl << endl;


  cout << "****test6**:" << endl;
  test6();
  cout << "****end of test6**:" << endl << endl;


cout << "****test7**:" << endl;
  test7();
  cout << "****end of test7**:" << endl << endl;


 cout << "****test8**:" << endl;
  test8();
  cout << "****end of test8**:" << endl << endl;


 cout << "****test9**:" << endl;
  test9();
  cout << "****end of test9**:" << endl << endl;


 cout << "****test10**:" << endl;
  test10();
  cout << "****end of test10**:" << endl << endl;

  return 0;
}
