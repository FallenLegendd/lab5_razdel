
#include <stdlib.h>

#include "coordinates.hpp"
#include "Object.hpp"



Object::Object(int id, int x, int y){
    this->id = id;
    posxy = new Coordinates(x, y);
    coordinates.push_back(posxy);
    
}
Object::Object(int id){
    this->id = id;
    posxy = new Coordinates(0.0, 0.0);
    coordinates.push_back(posxy);
    
}
Coordinates *Object::get_position(){
    return posxy;
}
int Object::get_id(){
    return id;
}
int Object::get_path(){
    return path;
}
int Object::get_speed(){
    return speed;
}
void Object::set_sum(double path){
    this->path += path;
}
int Object::get_count_point(){
    return coordinates.size();
}
void Object::randomwalk(int mapx, int mapy){
    int nap = rand() % 8;//направление
    int x = 0, y = 0;
    //Coordinates *newposxy = new Coordinates(posxy->get_x(), posxy->get_y());
    if(nap == 0 ){
        if(posxy->get_x() + speed <= mapx)
            x = posxy->get_x() + speed;
    }
    else if(nap == 1){
        if(posxy->get_x() - speed >= 0)
            x = posxy->get_x() - speed;
    }
    else if(nap == 2){
        if(posxy->get_y() + speed <= mapy)
            y = posxy->get_y() + speed;
    }
    else if(nap == 3){
        if(posxy->get_y() - speed >= 0)
            y = posxy->get_y() - speed;
    }
    if(x != 0 || y != 0){
        Coordinates *newposxy = new Coordinates(x, y);
        coordinates.push_back(newposxy);
        path += dist_point(newposxy, posxy);
        posxy = newposxy;
    }
    
} 
int Object::get_path_coord(Coordinates *point){
    return dist_point(posxy, point);
}
void Object::set_lat_lon(double lat, double lon){
    posxy->set_lat(lat);
    posxy->set_lon(lon);
}
void Object::set_pos(Coordinates *newp){
    posxy = newp;
}






