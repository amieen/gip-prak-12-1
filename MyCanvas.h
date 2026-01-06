// Datei: MyCanvas.h

#pragma once

#include "gip_mini_catch_heap_delete.h"

// In dieser Headerdatei:
// Deklaration der Klasse MyCanvas

class MyCanvas
{
private:
    /* data */
    unsigned int size_x,size_y;
    char * canvas_array_ptr;
public:
    void init();
    void set(unsigned int x, unsigned int y, char c);
    char get(unsigned int x, unsigned int y) const;
char* get_canvas_array_ptr() const;
    std::string to_string() const;
    void print() const;
    MyCanvas(unsigned int x,unsigned int y);
    MyCanvas(const MyCanvas& orig) ;

    MyCanvas& operator=(const MyCanvas& orig);
    ~MyCanvas();
    unsigned int get_size_x();
    unsigned int get_size_y();
    void draw_rectangle(unsigned int x1, unsigned int y1,
 unsigned int x2, unsigned int y2);
};


// Zu Uebungszwecken dieses Mal ausnahmsweise alle (!) Methodenruempfe
// in der .cpp Datei definieren.
// Auch fuer die Methoden mit kurzen Ruempfen 
// (kurze Konstruktoren, Setter, Getter, ...),
// die man normalerweise komplett in der Headerdatei 
// definieren wuerde ...

