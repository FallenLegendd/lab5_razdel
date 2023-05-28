
class Coordinates{

    int x, y, z;
    double lat, lon, alt;
public:
    Coordinates(int x1, int y1);
    Coordinates(double lat, double lon, double alt);
    int get_x();
    int get_y();
    void set_x(int x1);
    void set_y(int y1);
    double get_lat();
    double get_lon();
    double get_alt();
    void set_lat(double lat);
    void set_lon(double lon);
    
};  

int dist_point(Coordinates *XY1, Coordinates *XY2);
double distance_points_lat_lon(double lat1, double lon1, double lat2, double lon2);
