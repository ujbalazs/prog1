/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"



int main()
{
    

    // 1. 800x1000 ablak

    const Point tl {100, 100};
    Simple_window win {tl, 800, 1000, "Simple_windows"};
    win.wait_for_button();

    // 2. 800x800as grid, 100as felosztással

    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});   
    for (int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point{0, y}, Point{x_size, y});

    
    win.attach(grid);
    win.wait_for_button();


    // 3. Bal felső sarokból jobbra le piros átló

    Vector_ref<Rectangle> rects;
    for (int i = 0; i < x_size; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }

    win.wait_for_button();

    // 4.  3db 200-as kép
	
    Image ketszaz1 {Point{0,300}, "ketszaz.jpg"};
    Image ketszaz2 {Point{300,600}, "ketszaz.jpg"};
    Image ketszaz3 {Point{500,100}, "ketszaz.jpg"};

    win.attach(ketszaz1);
    win.attach(ketszaz2);
    win.attach(ketszaz3);
    win.wait_for_button();

    // 5. 100-as kép ami végigmegy a kockákon

    Image szaz {Point{0,0}, "szaz.jpg"};
    win.attach(szaz);
    win.wait_for_button();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 7; ++j) {
            szaz.move(100, 0);
            win.wait_for_button();
        }
        szaz.move(-700, 100);         
        win.wait_for_button();
    }

}

