#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string test_a, test_b;
    cin >> test_a >> test_b;

    double ans = 0; //aもbもビット値が2じゃなかった場合
    double cnt = 0; //aとbが同じだった数
    int num_zero = 0, num_one = 0; //各ビット値の数
    int num_bit = 0; //64bitのうち何ビット回復できているか

    for (size_t i = 0; i < test_a.size(); i++)
    {
        if(test_a[i] != '2' && test_b[i] != '2'){
            ans++;
            if(test_a[i] == test_b[i]){
                cnt++;
                if(test_a[i] == '1')
                    num_one++;
                else
                    num_zero++;
            }
        }
        else{
            num_bit++;
        }  
    }

    cout << "parcentage: " << cnt/ans  << endl;
    cout << "一致した0の数：" << num_zero << endl;
    cout << "一致した1の数：" << num_one << endl; 
    cout << "得られたビット位置の数：" << num_bit << endl;

    return 0;
}
