#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main() {
    map<const char*, const char*> mp;
    map<const char*, const char*>::iterator iter;

    const char key[3][20] = {"img", "system", "ip"};
    const char value[3][20] = {"d:/a.img", "win11", "192.168.1.1"};

    // insertion of make_pair
    for (int i = 0; i < 2; i++) {
        mp.insert(make_pair(key[i], value[i]));
    }

    // insertion of pair<const char*, const char*>
    mp.insert(pair<const char*, const char*>(key[2], value[2]));

    // insertion of array
    mp["addr"] = "China";

    // 迭代器取出元素
    // 循环取出元素
    for (iter = mp.begin(); iter != mp.end(); iter++) {
        cout << iter->first << ":" << iter->second << endl;
    }
    cout << endl;

    char keyword[20];
    cout << "PLEASE INPUT KEYWORD TO SEARCH: ";
    cin.getline(keyword, 20);

    // 查找元素
    for (iter = mp.begin(); iter != mp.end(); iter++) {
        if (strcmp(iter->first, keyword) == 0) {
            cout << iter->first << " FIND IT!" << " IT IS: " << iter->second << endl;
        }
    }

    // 第一种删除方式
    // find只能用于查找数组建立的形式！并且不支持输入用cin等
    iter = mp.find("addr");
    if (iter != mp.end()) {
        cout << iter->first << " FIND IT!" << "IT IS: " << iter->second << endl;
        cout << "NOW DELETE!" << endl;
        mp.erase(iter);
    }

    // 第二种删除方式
    // 按照key删除
    char drop_key[20];
    // 按照value删除
    char drop_value[20];

    cout << "PLEASE INPUT KEY TO DELETE: ";
    cin.getline(drop_key, 20);
    
    cout << "PLEASE INPUT VALUE TO DELETE: ";
    cin.getline(drop_value, 20);

    for (iter = mp.begin(); iter != mp.end(); iter++) {
        if (strcmp(iter->first, drop_key) == 0) {
            cout << iter->first << " FIND IT!" << " IT IS: " << iter->second << endl;
            cout << "NOW DELETE!" << endl;
            mp.erase(iter);
            break;
        }
    }

    for (iter = mp.begin(); iter != mp.end(); iter++) {
        if (strcmp(iter->second, drop_value) == 0) {
            cout << iter->first << " FIND IT!" << " IT IS: " << iter->second << endl;
            cout << "NOW DELETE!" << endl;
            mp.erase(iter);
            break;
        }
    }

    cout << "--------AFTER DELETE-------" << endl;

    // 迭代器取出元素
    for (iter = mp.begin(); iter != mp.end(); iter++) {
        cout << iter->first << ":" << iter->second << endl;
    }

    system("pause");

    return 0;
}