#include <vector>
#include <math.h>
#include <string>
#include "TMath.h"
#include <stack>
#include <stdlib.h>

using namespace std;

class Cluster{
  vector<pair <int,int> > pixels;
  vector<double> particle_phis;
  vector<double> particle_etas;
 public:
  void add_pixel(pair <int,int>);
  int n_pixels(){ return pixels.size(); }
  vector<pair <int,int> > my_pixels(){ return pixels; }
  vector<double> my_phis(){ return particle_phis; }
  vector<double> my_etas(){ return particle_etas; }
  int n_particles(){ return particle_phis.size(); } 
  void add_eta(double eta){particle_etas.push_back(eta);}
  void add_phi(double phi){particle_phis.push_back(phi);}
};

void Cluster::add_pixel(pair <int,int> pixel){
  bool found = false;
  for (unsigned int i=0; i<pixels.size(); i++){
    if (pixels[i].first == pixel.first && pixels[i].second == pixel.second) found = true;
  }
  if (!found) pixels.push_back(pixel);
}

bool should_add(Cluster cluster, double particle_phi, double particle_eta){
  bool out = true;
  for (unsigned int i=0; i<cluster.my_phis().size(); i++){
    if (fabs(cluster.my_phis()[i]-particle_phi) < 0.0001 && fabs(cluster.my_etas()[i]-particle_eta) < 0.0001) out = false;
  }
  return out;
}

bool should_cluster(Cluster cluster, pair <int,int> pixel){
  bool out = false;
  for (unsigned int i=0; i<cluster.my_pixels().size(); i++){
    if (fabs(cluster.my_pixels()[i].first - pixel.first) <= 1 && fabs(cluster.my_pixels()[i].second - pixel.second) <= 1){
      out = true;
    }
  }
  return out;
}

//Let's also add some functions to compute the area of the convex hull of a set of points.
//Graham's algorithm from http://www.sanfoundry.com/cpp-program-implement-graham-scan-algorithm-find-convex-hull/

struct Point{
  double x,y;
};

Point p0;

Point nextToTop(stack<Point> &S){
  Point p = S.top();
  S.pop();
  Point res = S.top();
  S.push(p);
  return res;
};

void swap(Point &p1, Point &p2){
  Point temp = p1;
  p1 = p2;
  p2 = temp;
};

double dist(Point p1, Point p2){
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point p, Point q, Point r){
  double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val==0) return 0; //colinear
  return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2){
  Point *p1 = (Point *) vp1;
  Point *p2 = (Point *) vp2;

  // Find orientation
  int o = orientation(p0, *p1, *p2);
  if (o == 0)
    return (dist(p0, *p2) >= dist(p0, *p1)) ? -1 : 1;
  return (o == 2) ? -1 : 1;
}

vector<Point> convexHull(Point points[], int n){

  // Find the bottommost point
  double ymin = points[0].y;
  int min = 0;
  for (int i = 1; i < n; i++){
    double y = points[i].y;
    // Pick the bottom-most or chose the left most point in case of tie
    if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) ymin = points[i].y, min = i;
  }

  // Place the bottom-most point at first position
  swap(points[0], points[min]);

  // Sort n-1 points with respect to the first point.  A point p1 comes
  // before p2 in sorted ouput if p2 has larger polar angle (in
  // counterclockwise direction) than p1
  
  p0 = points[0];
  qsort(&points[1], n - 1, sizeof(Point), compare);

  // Create an empty stack and push first three points to it.
  stack<Point> S;
  S.push(points[0]);
  S.push(points[1]);
  S.push(points[2]);

  // Process remaining n-3 points
  for (int i = 3; i < n; i++){
    // Keep removing top while the angle formed by points next-to-top,
    // top, and points[i] makes a non-left turn
    while (orientation(nextToTop(S), S.top(), points[i]) != 2)
      S.pop();
    S.push(points[i]);
  }

  vector<Point> out;
  // Now stack has the output points, print contents of stack
  while (!S.empty()){
    Point p = S.top();
    //cout << "(" << p.x << ", " << p.y << ")" << endl;
    out.push_back(p);
    S.pop();
  }
  return out;
}

double ConvexArea(vector<Point> mypoints){
  //see http://mathworld.wolfram.com/PolygonArea.html 

  double Area = 0.;
  for (int i=0; i<mypoints.size(); i++){
    int j = ((i+1) % mypoints.size()); //this trick from http://xoax.net/forum/index.php?topic=1224.0
    double temp = (mypoints[i].x*mypoints[j].y) - (mypoints[j].x*mypoints[i].y);
    Area+=0.5*temp;
  }
  return Area;
}
  
