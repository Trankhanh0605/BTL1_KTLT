#include <iostream>
#include <climits> // Để sử dụng INT_MAX

using namespace std;

int resupply(int shortfall, int supply[5][5]) {
    int arr[25];
    int a = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[a] = supply[i][j];
            a++;
        }
    }

    int count = 1;
    while (count != 0) {
        count = 0;
        for (int i = 0; i < 24; i++) { // Giới hạn i < 24 để tránh truy cập ngoài phạm vi
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                count++;
            }
        }
    }

    int num = 0, dem = 0, min = INT_MAX;
    for (int i = 0; i < 21; i++) {
        dem++;
        if (arr[i] + arr[21] + arr[22] + arr[23] + arr[24] < shortfall) break;
        for (int j = i + 1; j < 22; j++) { // Tránh trùng lặp giá trị
            dem++;
            if (arr[i] + arr[j] + arr[22] + arr[23] + arr[24] < shortfall) break;
            for (int k = j + 1; k < 23; k++) {
                dem++;
                if (arr[i] + arr[j] + arr[k] + arr[23] + arr[24] < shortfall) break;
                for (int m = k + 1; m < 24; m++) {
                    dem++;
                    if (arr[i] + arr[j] + arr[k] + arr[m] + arr[24] < shortfall) break;
                    for (int n = m + 1; n < 25; n++) {
                        dem++;
                        num = arr[i] + arr[j] + arr[k] + arr[m] + arr[n];
                        if (num == shortfall) {
                            cout << "Số lần thử: " << dem << endl;
                            return shortfall;
                        }
                        if (num < min && num > shortfall) {
                            min = num;
                        }
                    }
                }
            }
        }
    }

    cout << "Số lần thử: " << dem <<" " << endl;
    if (min == INT_MAX) return 0;
    return min;
}

int main() {
    int supply[5][5] = {
        {150, 200, 180, 90, 110},
        {70, 80, 120, 140, 160},
        {220, 240, 200, 190, 130},
        {100, 110, 300, 280, 320},
        {170, 210, 260, 230, 290}
    };    
    int shortfall;
    for(int i=0; i<10; i++) {
        cin >> shortfall;
        cout << resupply(shortfall,supply) << endl;
    }
    return 0;
}
