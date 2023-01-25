#define M5STACK_MPU6886

#include <M5Stack.h>
#include <vector>

constexpr std::size_t acc_data_size = 100;

std::vector<std::vector<float>> acc_data(acc_data_size, {0, 0, 0});

void setup(){
    M5.begin();
    M5.Power.begin();
    M5.IMU.Init();
    M5.Lcd.setTextSize(2);
}

void loop(){
    update_acc_data();
    print_data();
    delay(1);
}

void update_acc_data(){
    std::vector<float> temp(3);
    M5.IMU.getAccelData(&temp[0], &temp[1], &temp[2]);
    acc_data.erase(acc_data.begin());
    acc_data.push_back(temp);
}

void mean_vec(std::vector<std::vector<float>, float &x, float &y, float &z){
    std::vector<float> res(3, 0);
    for(int i=0;i<3;i++){
        for(int j=0;j<vec.size();j++){
            res[i] += vec[j][i];
        }
        res[i] /= vec.size();
    }
    x = res[0];
    y = res[1];
    z = res[3];
}

void print_data(){
    M5.Lcd.setCursor(0, 65);
    M5.Lcd.printf("acc(%5.2f,%5.2f,%5.2f)\n", temp[0], temp[1], temp[2]);
}