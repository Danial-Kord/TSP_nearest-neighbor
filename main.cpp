#include <iostream>
#include <sys/time.h>
#include <time.h>
using namespace std;
#include <math.h>
#include <chrono>
using namespace std::chrono;
typedef struct point{
    long double x;
    long double y;
    bool check;
    long double des(point in){
        long double output = pow(pow(x-in.x,2) + pow(y-in.y,2),0.5);
        return output ;
    }
    void build(){
        x = 0;
        y = 0;
        check = false;
    }
}Point;
class Stopwatch
{
private:
    steady_clock::time_point start;

public:
    Stopwatch(){
        reset();
    }

    ~Stopwatch(){}

    // Start the clock
    void reset(){ start = steady_clock::now(); }

    // Read time elapsed in nanoseconds
    double getTime(){
        return std::chrono::nanoseconds (steady_clock::now() - start).count();
    }
};
int main() {
    int n = 0;
    cin >> n;
    Point points[n];
    for (int i = 0; i < n; ++i) {
//        cin >> points[i].x;
//        cin >> points[i].y;
        points[i].x = rand() % 20000;
        points[i].y = rand() % 20000;
        points[i].check = false;
    }
        timespec ts;
        // clock_gettime(CLOCK_MONOTONIC, &ts); // Works on FreeBSD

        Point *first_point = &points[rand() % n];
        (*first_point).check = true;
        Point *min;
        long double final_res = 0;
        Point *curent;
    Stopwatch sw;
        curent = first_point;
        cout << "points : [ x : " << first_point->x << " y : " << first_point->y << ",";
        for (int k = 0; k < n; k++) {  //O(n+1)
            if (!points[k].check) { //O(n)
                min = &points[k]; //O(n)
                long double min_des = (*curent).des((*min)); //O(n)
                for (int j = k + 1; j < n; j++) { //O(n^2 + n*(n-1) + .... + n) = O(n^2))
                    if (!points[j].check) { //O(n^2 + n*(n-1) + .... + 0) = O(n^2))
                        double new_des = (*curent).des(points[j]);//O(n^2 + n*(n-1) + .... + 0) = O(n^2))
                        if (min_des > new_des) {//O(n^2 + n*(n-1) + .... + 0) = O(n^2))
                            min_des = new_des;//O(n^2 + n*(n-1) + .... + 0) = O(n^2))
                            min = &points[j];//O(n^2 + n*(n-1) + .... + 0) = O(n^2))
                        }
                    }
                }
                final_res += min_des;
                (*min).check = true;
                curent = min;
                cout << "x : " << curent->x << " y : " << curent->y << ",";
                k = -1;
            }
        }
        cout << " x : " << first_point->x << " y : " << first_point->y << "]";
        final_res += (*first_point).des((*curent));
        cout << endl << "final result : " << final_res;
    cout<<endl<< "#####Execution time: " <<sw.getTime() <<" nanoseconds" <<endl;
        return 0;
    }