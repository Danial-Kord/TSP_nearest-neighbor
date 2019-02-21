#include <iostream>
using namespace std;
#include <math.h>
typedef struct point{
    long double x;
    long double y;
    bool check;
    long double des(point in){
        long double output = pow(pow(x-in.x,2) + pow(y-in.y,2),0.5);
        cout<<"output : "<<output<<endl;
        return output ;
    }
    void build(){
        x = 0;
        y = 0;
        check = false;
    }
}Point;

int main() {
    int n = 0;
    cin >> n;
    Point  points[n];
    for (int i = 0; i <n ; ++i) {
        cin >> points[i].x;
        cin >> points[i].y;
        points[i].check = false;
    }
    Point *first_point = &points[rand()%n];
    (*first_point).check = true;
    Point *min;
    long double final_res = 0;
    Point *curent;
    curent = first_point;
    for (int k = 0; k < n; k++) {
        if (!points[k].check) {
            min = &points[k];
            long double min_des = (*curent).des((*min));
            for (int j = k+1; j < n; j++) {
                if(!points[j].check){
                    double new_des = (*curent).des(points[j]);
                    if(min_des > new_des){
                        min_des = new_des;
                        (*min) = points[j];
                    }
                }
            }
            final_res += min_des;
            (*min).check = true;
            curent = min;
            k = 0;
        }
    }
    final_res += (*first_point).des((*curent));
    cout << final_res;
    return 0;
}