#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // ファイル名
    std::string filename = "test_b.csv";

    // CSVファイルを開く
    std::ifstream file(filename);

    // ファイルが正しく開けたかを確認
    if (!file.is_open()) {
        std::cerr << "ファイルを開けませんでした: " << filename << std::endl;
        return 1;
    }

    std::string line;
    std::vector<int> column2_values;
    std::vector<int> column3_values;

    //1行ごとに2列目と3列目の値だけを読み込む
    while (std::getline(file, line)) {
        // ストリングストリームを使用してCSVの各列を分割
        std::istringstream ss(line);
        std::string token;

        // カンマで区切られた各列を処理
        for (int i = 0; std::getline(ss, token, ','); ++i) {
            // 2列目の値を取得（0から数えて1列目）
            if (i == 1) {
                // 文字列から整数に変換してベクトルに追加
                column2_values.push_back(std::stoi(token));
            }
            if(i == 2) {
                column3_values.push_back(std::stoi(token));
            }
        }
    }

    // ファイルを閉じる
    file.close();
    
    for (size_t i = 0; i < column2_values.size(); i++)
    {
        std::cout << column2_values[i] << " " << column3_values[i] << std::endl;
    }

    //先頭からi番目をpass[i]とする（64まででいいけどセグフォしたくないから幅広くとる）
    //読み取った結果が0の時はpass[i][0]を、1の時はpass[i][1]をインクリメント
    int pass[256][2] = {0};

    
    for (size_t i = 0; i < column2_values.size(); i++)
    {
        pass[column2_values[i]][column3_values[i]]++;
    }
    
    for (size_t i = 0; i < 256; i++)
    {
        if(pass[i][0] == 0 && pass[i][1] == 0)
            cout << 2;
        else if(pass[i][0] >= pass[i][1])
            cout << 0;
        else
            cout << 1;
    }

    std::cout << std::endl;
    

    return 0;
}
