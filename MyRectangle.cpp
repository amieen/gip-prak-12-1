#include "MyRectangle.h"
#include "MyCanvas.h"

unsigned int MyRectangle::get_x1(){
    return x1;
}
unsigned int MyRectangle::get_x2(){
    return x2;
}
void MyRectangle::set_x1(unsigned int  x1){
    this->x1=x1;
}
void MyRectangle::set_x2(unsigned int  x2){
    this->x2=x2;
}
void MyRectangle::set_y1(unsigned int  y1){
    this->y1=y1;
}
void MyRectangle::set_y2(unsigned int  y2){
    this->y2=y2;
    
}
unsigned int MyRectangle::get_y1(){
    return y1;
}
unsigned int MyRectangle::get_y2(){
    return y2;
}

void MyRectangle:: set_canvas_ptr(MyCanvas* a){
    this->canvas_ptr=a;
}
MyCanvas* MyRectangle::get_canvas_ptr() {
    return canvas_ptr;
}

// constructor
MyRectangle::MyRectangle(MyCanvas& canvas, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
    this->x1 = x1; // Should be 3
    this->y1 = y1; // Should be 4
    this->x2 = x2; // Should be 16
    this->y2 = y2; // Should be 9
    this->canvas_ptr = &canvas;
}


void MyRectangle::draw() {
    if (this->canvas_ptr != nullptr) {
        // Double check the order of variables here!
        this->canvas_ptr->draw_rectangle(x1, y1, x2, y2);
    }
}