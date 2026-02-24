#ifndef DISK_H
#define DISK_H

class Disk {
private:
double x, y, radius;
public:
Disk(double x, double y, double r) ;

void move(double dx, double dy) ;
double distance(const Disk& d) const;
double getX() const {return x;}
double getY() const {return y;}
double getRadius() const {return radius;}
};

#endif // !DISK_H