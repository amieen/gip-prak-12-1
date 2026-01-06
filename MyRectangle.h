#pragma once
#include "MyCanvas.h"





class MyRectangle
{
protected:
    /* data */
    unsigned int x1,x2,y1,y2;
    MyCanvas* canvas_ptr;
public:

    unsigned  int get_x1();
    unsigned  int get_x2();
    void set_x1( unsigned  int a);
    void set_x2( unsigned  int a);
    unsigned  int get_y1();
    unsigned  int get_y2();
    void set_y1(unsigned  int a);
    void set_y2(unsigned  int a);
    MyCanvas* get_canvas_ptr();
    void set_canvas_ptr(MyCanvas* a);
    MyRectangle(MyCanvas& canvas, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
    void draw();

};

