

#include "MyCanvas.h"
unsigned int MyCanvas::get_size_x(){
    return size_x;
}
unsigned int MyCanvas::get_size_y(){
    return size_y;
}
void MyCanvas::init(){
    unsigned int total_size = size_x * size_y;
    for (unsigned int i = 0; i < total_size; ++i) {
        canvas_array_ptr[i] = '.';
    }
}
// MyCanvas.cpp
MyCanvas::MyCanvas(const MyCanvas& orig) 
    : size_x{orig.size_x}, size_y{orig.size_y} // Initialisation des dimensions [cite: 190, 201]
{
    // 1. Allouer une nouvelle mémoire indépendante sur le Heap [cite: 166, 200]
    canvas_array_ptr = new char[size_x * size_y];

    // 2. Copier les données pixel par pixel [cite: 167, 171]
    unsigned int total_size = size_x * size_y;
    for (unsigned int i = 0; i < total_size; ++i) {
        canvas_array_ptr[i] = orig.canvas_array_ptr[i];
    }
}
MyCanvas::MyCanvas(unsigned int x,unsigned int y):size_x{x},size_y{y},canvas_array_ptr{new char [x*y]}{//er hat keinen Ruckgabewert

        init();
    }
MyCanvas::~MyCanvas(){
    delete [] canvas_array_ptr;
}
MyCanvas& MyCanvas::operator=(const MyCanvas& orig){//er hat ein Ruckgabewert deswegen Mycanvas& 
    if (this == &orig) return *this;
    delete [] canvas_array_ptr;
    size_x=orig.size_x;
    size_y=orig.size_y;
    canvas_array_ptr=new char[(size_x*size_y)];
    unsigned int total_size = size_x * size_y;
    for (unsigned int i = 0; i < total_size; ++i) {
        canvas_array_ptr[i] = orig.canvas_array_ptr[i];
    }
    return *this;
}
void MyCanvas::set(unsigned int x, unsigned int y, char c){
    if (x < size_x && y < size_y) {
        canvas_array_ptr[y * size_x + x] = c;
    }
}
char MyCanvas::get(unsigned int x, unsigned int y)const{
    return canvas_array_ptr[y * size_x + x];
}
char* MyCanvas::get_canvas_array_ptr() const {
    return canvas_array_ptr; 
}
std::string MyCanvas::to_string() const {//const ici indique qu'elle ne modiferiera pas les attributs de l'objet
    std::string ch="";
    
    unsigned int total_size = size_x * size_y;
for (unsigned int i = 0; i < total_size; ++i) {
    ch += canvas_array_ptr[i];
    // On ajoute \n seulement APRES avoir ajouté le dernier caractère de la ligne
    if ((i + 1) % size_x == 0) {
        ch += '\n';
    }
}
    return ch;
}
void MyCanvas::print() const {
    std::cout << to_string() << std::endl;
}
void MyCanvas::draw_rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
    for (unsigned int y = y1; y <= y2; ++y) { // Row first
        for (unsigned int x = x1; x <= x2; ++x) { // Then Column
            this->set(x, y, '#'); 
        }
    }
}