/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include <typeinfo>
#include "polygon.h"

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
  
  std::vector<Point> lhsLimits = lhs;
  std::vector<Point> rhsLimits = rhs;
  std::vector<Point> lhsLimitsAux = lhs;
  std::vector<Point> rhsLimitsAux = rhs;
  
  bool t_lhs = typeid(lhs) == typeid(Point);
  bool t_rhs = typeid(rhs) == typeid(Point);
  if(t_lhs && t_rhs){
    if(lhsLimits[0].contains(rhsLimits[0]))
      return true;
  } else if (t_lhs || t_rhs){
    return false;
  }

  //remove repeated points
  auto aux = lhsLimits.begin();
  lhsLimitsAux.push_back(*aux);
  for(auto i = lhsLimits.begin() + 1; i != lhsLimits.end(); i++){
    if(!(i->contains(*aux))){
      lhsLimitsAux.push_back(*i);
    }
    aux++;
  }
  aux = rhsLimits.begin();
  rhsLimitsAux.push_back(*aux);
  for(auto i = rhsLimits.begin() + 1; i != rhsLimits.end(); i++){
    if(!(i->contains(*aux))){
      rhsLimitsAux.push_back(*i);
    }
    aux++;
  }
  
  Point lhsp0(lhsLimitsAux[0].x,lhsLimitsAux[0].y);
  Point lhsp1(lhsLimitsAux[1].x,lhsLimitsAux[1].y);
  Point lhsp2(lhsLimitsAux[0].x,lhsLimitsAux[1].y);
  Point lhsp3(lhsLimitsAux[1].x,lhsLimitsAux[0].y);
  std::vector<Point> lhsPoints;
  lhsPoints.push_back(lhsp0);
  lhsPoints.push_back(lhsp2);
  lhsPoints.push_back(lhsp1);
  lhsPoints.push_back(lhsp3);

  Point rhsp0(rhsLimitsAux[0].x,rhsLimitsAux[0].y);
  Point rhsp1(rhsLimitsAux[1].x,rhsLimitsAux[1].y);
  Point rhsp2(rhsLimitsAux[0].x,rhsLimitsAux[1].y);
  Point rhsp3(rhsLimitsAux[1].x,rhsLimitsAux[0].y);
  std::vector<Point> rhsPoints;
  rhsPoints.push_back(rhsp0);
  rhsPoints.push_back(rhsp2);
  rhsPoints.push_back(rhsp1);
  rhsPoints.push_back(rhsp3);

  // for(auto i = lhsPoints.begin(); i!= lhsPoints.end(); i++){
  //   std::cout << *i << " - ";
  // }
  // std::cout << std::endl;
  // for(auto i = rhsPoints.begin(); i!= rhsPoints.end(); i++){
  //   std::cout << *i << " - ";
  // }
  // std::cout << std::endl << "-------------" << std::endl;

  if(lhsPoints[0].contains(lhsPoints[1]) && !(rhsPoints[0].contains(rhsPoints[1])))
    return false;

  int count = 0;
  for (auto i = lhsPoints.begin(); i != lhsPoints.end(); i++){
    for(auto j = rhsPoints.begin(); j != rhsPoints.end(); j++){
      if(j->contains(*i))
        count++;
    }
  }
  if(count >= 4)
    return true;

  return false;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
  std::vector<Point> limits = this->limits;

  if((limits[0].x >= p.x && limits[0].y >= p.y) && (limits[1].x <= p.x && limits[1].y <= p.y))
    return true;
  else if ((limits[0].x <= p.x && limits[0].y <= p.y) && (limits[1].x >= p.x && limits[1].y >= p.y))
    return true;
  else
    return false;
}

Point::Point(int xx, int yy): x(xx), y(yy) {
  this->limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  Point* p0 = new Point(x0, y0);
  Point* p1 = new Point(x1, y1);
  this->limits.push_back(*p0);
  this->limits.push_back(*p1);
}