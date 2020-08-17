/***********************************
 * Cell.h
 * Created by: Tim Dowling
 * Date: Aug 16, 2020
 ***********************************/

#ifndef CELL_H
#define CELL_H


class Cell
{
private:
    int _index, _x, _y;
public:
    Cell(int x, int y, int index);
    ~Cell();

    void update();
    int getIndex() { return _index; }
};

Cell::Cell(int x, int y, int index)
{
    this->_x = x;
    this->_y = y;
    this->_index = index;
}

Cell::~Cell()
{
}

void Cell::update(){

}

#endif