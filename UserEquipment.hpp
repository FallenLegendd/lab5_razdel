
//#include "Object.hpp"
class Object;

class UserEquipment : public Object{

public:
    UserEquipment(int id, double lat, double lon, double scale);
    void randomwalk(int mapx, int mapy);

private:
    double scale;

};
