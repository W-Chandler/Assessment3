#include "disk.h"
#include <cmath>

Disk::Disk(double x, double y, double r){
    this->x = x;
    this->y = y;
    this->radius = r;
}

void Disk::move(double dx, double dy){
    this->x += dx;
    this->y += dy;
}

double Disk::distance(Disk& other){
    // Used distance formula to find the distance between two disks
    return sqrt((x - other.x)*(x - other.x) + (y - other.y)*(y - other.y));

}