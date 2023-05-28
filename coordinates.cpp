

#include <cmath>

#include "coordinates.hpp"
double R = 6371.0;



int dist_point(Coordinates *XY1, Coordinates *XY2){
    return sqrt(pow((XY2->get_x() - XY1->get_x()), 2) + pow((XY2->get_y() - XY1->get_y()), 2));
}
double distance_points_lat_lon(double lat1, double lon1, double lat2, double lon2){
    double sin1 = sin( (lat1-lat2) / 2.0 );
    double sin2 = sin( (lon1-lon2) / 2.0 );
    return 2.0 * R * asin( sqrt( sin1 * sin1 + sin2 * sin2 * cos(lat1) * cos(lat2) ) );
}





Coordinates::Coordinates(int x1, int y1){
        x = x1;
        y = y1;
}
Coordinates::Coordinates(double lat, double lon, double alt = 0){
        this->lat = lat;
        this->lon = lon;
        x = R * cos(lat) * cos(lon);
        y = R * cos(lat) * sin(lon);
        z = R * sin(lat);
        this->alt = alt;
}
int Coordinates::get_x(){
        return x;
}
int Coordinates::get_y(){
        return y;
}
void Coordinates::set_x(int x1){
        x = x1;
}
void Coordinates::set_y(int y1){
        y = y1;
}
double Coordinates::get_lat(){
        return lat;
}
double Coordinates::get_lon(){
        return lon;
}
double Coordinates::get_alt(){
        return alt;
}
void Coordinates::set_lat(double lat){
        this->lat = lat;
        z = R * sin(this->lat);
}
void Coordinates::set_lon(double lon){
        this->lon = lon;
        x = R * cos(this->lat) * cos(this->lon);
        y = R * cos(this->lat) * sin(this->lon);
}





