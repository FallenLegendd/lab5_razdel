
#include <vector>

using namespace std;

class Coordinates;


class Object{
private:
    int id;
    int path = 0;
    Coordinates *posxy;

    int speed = 26;
protected:
    vector<Coordinates*> coordinates;

public:
    Object(int id, int x, int y);
    Object(int id);
    Coordinates *get_position();
    int get_id();
    int get_path();
    int get_speed();
    void set_sum(double path);
    int get_count_point();
    virtual void randomwalk(int mapx, int mapy);
       
    int get_path_coord(Coordinates *point);
    void set_lat_lon(double lat, double lon);
    void set_pos(Coordinates *newp);


};