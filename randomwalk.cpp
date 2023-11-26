#include <iostream>
#include <cmath>
using namespace std;

int random_walk(int steps){
    int position = 0;
    int num_crosses = 0;
    for(int i=0; i<steps; i++){
        int direction = rand() % 2 == 0 ? 1 : -1;
        position+=direction;
        if(position == 0){
            num_crosses+=1;
        }
    }
    return num_crosses;
}

int main() {
    int runs = 50;

    int steps[] = {static_cast<int>(4*pow(10,4)), static_cast<int>(9*pow(10,4)), static_cast<int>(16*pow(10,4))};
    for (int j=0;j<sizeof(steps) / sizeof(steps[0]);j++){
        int average_crosses = 0;
        for(int i=0; i<runs; i++){
            int num_crosses = random_walk(steps[j]);
            average_crosses += num_crosses;
        }
        double avg = average_crosses/runs;
        printf("For t = %d: Average number of crossings = %f\n", steps[j], avg);
    }
    return 0;
}