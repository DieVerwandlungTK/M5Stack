#define M5STACK_MPU6886

#include <vector>
#include <queue>
#include <M5Stack.h>


std::vector<float> get_acc(){
    std::vector<float> acc(3);
    M5.IMU.getAccelData(&acc[0], &acc[1], &acc[2]);
    return acc;
}

void print_acc(const std::vector<float> &acc){
    M5.Lcd.setCursor(0,0);
    M5.Lcd.printf("a_x:%6.2f\na_y:%6.2f\na_z:%6.2f", acc[0], acc[1], acc[2]);
}

std::vector<float> q_mean(std::queue<std::vector<float>> q){

    int q_size = q.size();
    int v_size = q.front().size();

    std::vector<float> mean(v_size, 0), tmp(v_size);

    for(int i=0;i<q_size;i++){
        tmp = q.front();
        q.pop();
        for(int j=0;j<v_size;j++) mean[j] += tmp[j];
    }

    for(int i=0;i<v_size;i++) mean[i] /= q_size;

    return mean;
}

void update_q(std::queue<std::vector<float>> &q){
    q.pop();
    q.push(get_acc());
}

std::queue<std::vector<float>> accq;

void setup(){
    M5.begin();
    M5.Power.begin();
    M5.IMU.Init();
    M5.Lcd.setTextSize(2);
    for(int i=0;i<10;i++) accq.push(get_acc());
}

void loop(){
    update_q(accq);
    print_acc(q_mean(accq));
    delay(1);
}