#include <fstream>
// Added headers for system and disk
#include "system.h"
#include "disk.h"

System::System(int N, double displacement,double radius, double boxSize, int seed)

        : boxSize(boxSize),
        displacement(displacement),
        gen(seed){
        
        int nSide = static_cast<int>(boxSize/ (2*radius));

        for (int i = 0; i < nSide && disks.size() < N; ++i) {
            for (int j = 0; j < nSide && disks.size() < N; ++j) {
                disks.push_back(Disk(i * 2*radius, j * 2*radius, radius));
            }
        }
    }   

bool System::overlap(int i) const{
    for (int j = 0; j < disks.size(); ++j) {
        if (i!=j && disks[i].distance(disks[j]) < (disks[i].getRadius() + disks[j].getRadius()) ) {
            return true;
        }
    }
    return false;
}

void System::step() {
    for (size_t i = 0; i<disks.size(); ++i) 
    {
        int selected_disk = std::rand() % disks.size();
        double oldx = disks[selected_disk].getX();
        double oldy = disks[selected_disk].getY();
        double dx = uniform(-displacement, displacement);
        double dy = uniform(-displacement, displacement);
        this->disks[selected_disk].move(dx, dy);
        
        enforceBoundaries(disks[selected_disk]);

        if (overlap(selected_disk)){
            disks[selected_disk].move(oldx - disks[selected_disk].getX(), oldy - disks[selected_disk].getY());
        }
    }
}
void System::enforceBoundaries(Disk & disk) {
    double x = disk.getX();
    double y = disk.getY();
    double r = disk.getRadius();

    if (x < r){
        disk.move(r - x, 0);
    }
    else if (x > boxSize - r){
        disk.move(boxSize - r - x, 0);
    }
    if (y < r){
        disk.move(0, r - y); 
    }
    else if (y > boxSize - r){
        disk.move(0, boxSize - r - y);
        }
}
// Created uniform function to generate random numbers between min and max  
double System::uniform(double min, double max)
{
    // Uses C++ random library to generate a number
    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}


void System::save(const std::string &filename) const{
    // save state of disks to file
    std::ofstream outFile(filename);
    outFile<<disks.size()<<std::endl;
    outFile<<"Comment"<<std::endl;
    for (const Disk& disk : disks) {
      outFile<<"A "<<disk.getX()<<" "<<disk.getY()<<" "<<disk.getRadius()<<std::endl;

    }
    outFile.close();
    
}