
#include <stdlib.h>
#include "Object.hpp"
#include "UserEquipment.hpp"

#include "coordinates.hpp"



UserEquipment::UserEquipment(int id, double lat, double lon, double scale) : Object(id){
    
    set_lat_lon(lat, lon);
    this->scale = scale;
    
}
void UserEquipment::randomwalk(int mapx, int mapy){
    int nap = rand() % 8;//направление
    int x = 0, y = 0;
    //Coordinates *newposxy = new Coordinates(posxy->get_x(), posxy->get_y());
    Coordinates *posxy = get_position();
    int speed = get_speed();
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
        double lat, lon;
        lat = posxy->get_lat() + (double)x * scale;
        lon = posxy->get_lon() + (double)y * scale;
        
        Coordinates *newposxy = new Coordinates(lat, lon, 0.0);

        coordinates.push_back(newposxy);
        //path += dist_point(newposxy, posxy);
        double D = distance_points_lat_lon(posxy->get_lat(), posxy->get_lon(), lat, lon);
        set_sum(D);
        set_pos(newposxy);
        //posxy = newposxy;
    }
    
} 








