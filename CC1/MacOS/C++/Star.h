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

    int _map(float value, int start1, int stop1, int start2, int stop2);
public:
    Star(int x, int y, int z);
    ~Star();

    void update();
    void resetStar();
    int getX() { return _x; }
    int getY() { return _y; }
    int getZ() { return _z; }
    void setX(int aNum) { _x = aNum; }
    void setY(int aNum) { _y = aNum; }
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
    this->_z += 1;
}

void Star::resetStar(){
    this->_x = 0;
    this->_y = 0;
    this->_z = 1;
}

// Private Functions



#endif