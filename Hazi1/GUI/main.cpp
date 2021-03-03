/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"



int main()
{
    using namespace Graph_lib;

    Point tl (300,100);
	Simple_window win (tl,600,400,"My window");


	Axis xa (Axis::x,Point(20,500),350,15,"x axis"); 


    Axis ya (Axis::y,Point(20,500),350,15,"y axis");  
    ya.set_color(Color:: dark_magenta );
	ya.label.set_color(Color::green);


	Function sine(sin,0,90,Point(20,200),1000,60,60);
	sine.set_color(Color:: red);


	Polygon poly;
	poly.add(Point(400,210));
	poly.add(Point(350,160));
	poly.add(Point(400,300));
	poly.set_color(Color:: green);
	//poly.set_style(Line_style::dash);
	poly.set_style(Line_style(Line_style::dashdot,3));


	Rectangle r(Point(300,300),110,60);
	r.set_fill_color(Color::blue);


	Closed_polyline poly_rect;
	poly_rect.add(Point(100,60));
	poly_rect.add(Point(200,50));
	poly_rect.add(Point(200,110));
	poly_rect.add(Point(120,100));
	poly_rect.add(Point(50,75));
	poly_rect.set_style(Line_style(Line_style::dash,4));


	Text t(Point(200,400),"Hello graph world!");
	t.set_font(Font::times_bold_italic);
	t.set_font_size(15);


	Image ii(Point(100,60),"badge.jpg");


	Circle c(Point(150,200),60);

	/*Ellipse e(Point(100,200),75,25);  könyvben így szerepel de itt nem működik
	e.set_color(Color:: dark_red);*/

	Mark m(Point(150,200),'o');


	ostringstream oss;
	oss << "screen size: " << x_max() << "." << y_max()
	    <<"; window size: " << win.x_max() << "." << win.y_max();

	Text sizes(Point(50,40),oss.str());
	


    win.attach(ii);
	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(c);
	//win.attach(e);
	win.attach(m);
	win.attach(sizes);



    win.wait_for_button();

}
