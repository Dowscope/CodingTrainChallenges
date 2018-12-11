/***********************************
 * Star.h
 * Created by: Tim Dowling
 * Date: Dec 8, 2018
 ***********************************/

#ifndef STAR_H
#define STAR_H


class Star
{
private:
    int _x, _y, _z;
public:
    Star(int x, int y, int z);
    ~Star();

    void update();
    int getX() { return _x; }
    int getY() { return _y; }
};

Star::Star(int x, int y, int z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Star::~Star()
{
}

void Star::update(){

}

#endif