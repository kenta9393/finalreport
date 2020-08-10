#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class MoneyBook {
protected:
    string date;
    string item;
    int price;
public:
    void setDate(const string& newDate) { date = newDate; }
    string getDate() { return date; }
    void setItem(const string& newItem) { item = newItem; }
    string getItem() { return item; }
    void setPrice(int newPrice) { price = newPrice; }
    int getPrice() { return price; }

    MoneyBook() {
        date = {};
        item = {};
        price = 0;
    }
};

int main(){
    vector<MoneyBook>July;
    string date = {};
    string item = {};
    int price = 0;;
    MoneyBook tmp = {};
    int income = 0;
    int expenditure = 0;

    ifstream datafile("k.kenta.txt");
    if (datafile.fail()) {
        std::cerr << "Failed to open file." << endl;
        return -1;
    }
    while (datafile >> date >> item >> price) {
        tmp.setDate(date);
        tmp.setItem(item);
        tmp.setPrice(price);
        July.push_back(tmp);
    }
    cout << "Money record : July 2020" << endl << endl;
    cout.setf(std::ios::left, std::ios::adjustfield);
    for (auto x = July.begin(); x != July.end(); ++x) {
        if (x-> getPrice() < 0) {
            expenditure += x->getPrice();
        }
        else {
            income += x->getPrice();
        }
        cout << x->getDate() << " ";
        cout.setf(std::ios::left, std::ios::adjustfield);
        cout << setw(10) << x->getItem() << " ";
        cout.setf(std::ios::right, std::ios::adjustfield);
        cout << setw(10) << x->getPrice() << endl;
    }
    cout << endl;
    cout << "[Monthly Report]" << endl;
    cout << "Income :" << income << endl;
    cout << "Expenditure :" << abs(expenditure) << endl;

    if (income < abs(expenditure)) {
        cout << "This month is deficit." << endl;
    }
    else {
        cout << "This month is surplus." << endl;
    }
    cout << endl;
    datafile.close();
    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
