/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
    int xmax = 600;
    int ymax = 600;

    int x_origo = xmax/2;
    int y_origo = ymax/2;
    Point origo(x_origo,y_origo);

    int r_min = -10;
    int r_max = 11;

    int n_points = 400;

    int x_scale = 20;
    int y_scale = 20;

    Point tl(600,50);
    Simple_window win(tl,xmax,ymax,"Function graphs");

    int xlength = xmax - 200;
    int ylength = ymax - 200;

    Axis x(Axis::x,Point(100,y_origo),xlength,xlength/x_scale,"1 == 20 pixels");
    x.set_color(Color::red);
    
    Axis y(Axis::y,Point(x_origo,500),ylength,ylength/y_scale,"1 == 20 pixels");
    y.set_color(Color::red);
   

    win.attach(x);
    win.attach(y);
    win.wait_for_button();


    Function v1(one,r_min,r_max,origo,n_points/*,x_scale,y_scale*/);

    win.attach(v1);
    win.wait_for_button();
    win.detach(v1);
	win.wait_for_button();

	Function v1s(one,r_min,r_max,origo,n_points,x_scale,y_scale);

    win.attach(v1s);
    win.wait_for_button();


    Function v2(slope,r_min,r_max,origo,n_points,x_scale,y_scale);

    win.attach(v2);
    win.wait_for_button();


    Text t(Point(100,y_origo+4*y_scale),"x/2");

    win.attach(t);
    win.wait_for_button();


    Function n(square,r_min,r_max,origo,n_points,x_scale,y_scale);

    win.attach(n);
    win.wait_for_button();


    Function c1(cos,r_min,r_max,origo,n_points,x_scale,y_scale);
    c1.set_color(Color::blue);

    win.attach(c1);
    win.wait_for_button();


    Function c2(sloping_cos,r_min,r_max,origo,n_points,x_scale,y_scale);

    win.attach(c2);
    win.wait_for_button();


    

}

