#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <ctime>

#include "coordinates.hpp"
#include "Object.hpp"
#include "UserEquipment.hpp"

using namespace std;

//double R = 6371.0;


vector <Object*> Create_UserEquipment(int mapx, int mapy, double latA, double lonA, double scale){
    int count;
    cout<<"Input count objects(1 - 100): ";
    cin>>count;
    vector <Object*> obj;
    Object *newobj;
    int i, i2;
    int id;
    int create_id;
    double pos_lat, pos_lon;
    for(i = 0; i < count; ++i){
        create_id = 0;
        while(create_id != 1){
            create_id = 1;
            id = 99 + (rand() % 10000);
            for(i2 = 0; i2 < i; ++i2){
                if(id == obj[i2]->get_id()){
                    create_id = 0;
                    break;
                }
            }
        }
        cout<<"id = "<<id<<endl;
        pos_lat = latA + (rand() % mapx) * scale;
        pos_lon = lonA + (rand() % mapy) * scale;
        newobj = new UserEquipment(id, pos_lat, pos_lon, scale);
        obj.push_back(newobj);
    }
    return obj;
}

void randomwalk_objs(vector <Object*> *objs, int mapx, int mapy){
    int count;
    cout<<"Input count iteration move(1 - 1000): ";
    cin>>count;
    int i, i2;
    for(i = 0; i < count; ++i){
        cout<<"iteration: "<<i<<"\n";
        for(i2 = 0; i2 < objs->size(); ++i2){
            objs->at(i2)->randomwalk(mapx, mapy);
            cout<<"\tid = "<<objs->at(i2)->get_id()<<"\tlat = "<<objs->at(i2)->get_position()->get_lat()<<"\tlon = "<< objs->at(i2)->get_position()->get_lon()<<"\n";
        }
    }
    Object *ptr, *ptr2;
    for(i2 = 0; i2 < objs->size(); ++i2){
        ptr = objs->at(i2);
        cout<<"id - "<<ptr->get_id()<<"\n";
        cout<<"\tpath = "<<ptr->get_path()<<"\n";
        cout<<"\tcount point = "<<ptr->get_count_point()<<"\n";
        cout<<"\tpath to \n";
        for(i = 0; i < objs->size(); ++i){
            if(i != i2){
                ptr2 = objs->at(i);
                cout<<"\t\t[id - "<<ptr2->get_id()<<"] = "<<ptr->get_path_coord(ptr2->get_position())<<"\n";
            }
        }
    }
    cout<<"End iteratrion move\n";
}

int main(){
    srand(time(NULL));
    int size_x = 1000, size_y = 1000;
    double latA = 55.084656, lonA = 82.4626;
    double latB = 54.874631, lonB = 82.8410;
    vector <Object*> objs;
    double scale = (lonB - lonA)/(double)size_x;
    objs = Create_UserEquipment(size_x, size_y, latA, latB, scale);
    randomwalk_objs(&objs, size_x, size_y);

    cout<<"End program\n";
    
}
