#include <string>
#include <vector>
#include <iostream>
using namespace std;

double calc_hour(int h, int m, int s) {
    return (h % 12) * 30 + (double)m * 0.5 + (double)s / 120;
}
double calc_minute(int m, int s) {
    return m * 6 + (double)s * 0.1;
}
double calc_second(int s) {
    return s * 6;
}
void calc_time(int *h, int *m, int *s) {
    *s += 1;
    if (*s == 60){
        *s = 0;
        *m += 1;
        if (*m == 60){
            *m = 0;
            *h += 1;
        }
    }
}
int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = -1;

    int cnt = 0;
    double p_hour = calc_hour(h1, m1, s1), p_minute = calc_minute(m1, s1), p_sec = calc_second(s1);
    if (h1 % 12 == 0 && m1 == 0 && s1 == 0)
        cnt++;
    while(h1 != h2 || m1 != m2 || s1 != s2){
        calc_time(&h1, &m1, &s1);
        double n_hour = calc_hour(h1, m1, s1), n_minute = calc_minute(m1, s1), n_sec = calc_second(s1);
        bool h_check = false, m_check = false;
        if ((p_hour > p_sec && n_hour <= n_sec) || (p_sec == 354 && p_hour > 354)) {
            h_check = true;
        } if ((p_minute > p_sec && n_minute <= n_sec) || (p_sec == 354 && p_minute > 354)) {
            m_check = true;
        }
        p_hour = n_hour, p_minute = n_minute, p_sec = n_sec;
        if (h_check && m_check){
            if (p_hour == p_minute){
                cnt++;
            }
            else{
                cnt += 2;
            }
        } else if (h_check || m_check) {
            cnt++;
        }
    }
    return cnt;
}