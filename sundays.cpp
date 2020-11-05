#include<bits/stdc++.h>
using namespace std;
unsigned int SUNDAY = 0;
bool date_over(long** datearr){
        if (datearr[0][0] > datearr[1][0]) return true;
        else if (datearr[0][0] == datearr[1][0]) {
            if (datearr[0][1] > datearr[1][1])   return true;
            else if (datearr[0][1] == datearr[1][1]){
                if (datearr[0][2] > datearr[1][2])  return true;
            }
        }
        return false;
}
void exchange(long** datearr) {
        swap(datearr[0],datearr[1]);
}
void adjust(long** datearr) {
        if (date_over(datearr))  exchange(datearr);
}
bool check(long year, long month, long day) {
        if (month < 3) {
            month += 12;
            year -= 1;
        }
        long c = year / 100;
        long y = year % 100;
        int w = (int) ((y + (y / 4) + (c / 4) - (2 * c) + ((26 * (month + 1)) / 10) + day - 1) % 7);
        bool t = w == SUNDAY;
        return t;
}

int main(){
    long** datearr = new long*[2];
    for(int i=0;i<2;i++) datearr[i] = new long[3];
    //input format if year month date
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) cin>>datearr[i][j];
    }
    adjust(datearr);
            long count= 0;
            while (true) {
                if (datearr[0][2] == 1) {
                    if (check(datearr[0][0], datearr[0][1], datearr[0][2])) {
                        count++;
                    }
                }
                datearr[0][2] = 1;
                datearr[0][1]++;
                if (datearr[0][1] > 12) {
                    datearr[0][1] = 1;
                    datearr[0][0]++;
                }
                if (date_over(datearr))
                    break;
            }
            cout<<count;
}
// tested it against the input or sample input provided 
// 1901 1 1
// 2000 12 31
// ===========
// output
// 171