#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include "disk.h"

class System {
private:
std::vector<Disk> disks;
const double boxSize;
const double displacement;
std::mt19937 gen;
bool overlap(int i) const;
void enforceBoundaries(Disk & disk);

public:
System(int N, double displacement,double radius, double box_size, int seed);

void step() ;
void save(const std::string &filename) const;
double uniform(double min, double max);
};
#endif // !SYSTEM_H