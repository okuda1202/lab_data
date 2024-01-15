//多数決でPSKを推定するプログラム

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string test[2];

    //クライアント5台のPSKを入力する．
    for (size_t i = 0; i < 2; i++)
    {
        cout << i + 1 << "つ目のPSKを入力してください" << endl;
        cin >> test[i];
    }

    

    

    //先頭からi番目のビット値の２（読み取れていないビット）の数（最大5）
    int cnt_two[256] = {0};
    int cnt_one[256] = {0};
    int cnt_zero[256] = {0};


    for (size_t i = 0; i < test[0].size(); i++)
    {
        
        //i番目のビット値を調べる
        for (size_t j = 0; j < 2; j++)
        {
            //2だった場合は加算
            if(test[j][i]=='2'){ //[j][i]←jとiの位置に注意
                cnt_two[i]++;
            }
            else if(test[j][i]=='1'){
                cnt_one[i]++;
            }
            else{
                cnt_zero[i]++;
            }
        }
        
    }

    //iビット目の2の数を記録
    int ans[6] = {0};
    for (size_t i = 0; i < 256; i++)
    {
        ans[cnt_two[i]]++;
    }
    
    for (size_t i = 0; i < 2; i++)
    {
        cout << 5 - i << "台のクライアントで読み取ったビット位置：" << ans[i]  << "個"<< endl;
    }
    

    //0,1,2で一番多いやつを正解とする．
    int check[3][256] = {0};
    int psk_estimation[256];

    for (size_t i = 0; i < 256; i++)
    {
        check[0][i] = cnt_zero[i];
        check[1][i] = cnt_one[i];
        check[2][i] = cnt_two[i];
    }
    
    for (size_t i = 0; i < 256; i++)
    {
        //0,1,2の数を比較して一番多いものをPSKとする
        //数が同じときは0にする
        int tmp = 0;
        int val_bit = 2;
        for (size_t j = 0; j < 3; j++)
        {
            if(check[j][i]>=tmp){
                tmp = check[j][i];
                val_bit = j;
            }
        }
        psk_estimation[i] = val_bit;
    }
    
    cout << "暫定的なPSK" << endl;
    for (size_t i = 0; i < 256; i++)
    {
        cout << psk_estimation[i];
    }
    cout << endl;
    

    return 0;
}
