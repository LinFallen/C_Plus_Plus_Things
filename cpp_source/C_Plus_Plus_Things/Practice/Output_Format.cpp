#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char s[20] = "This is a string.";
    double digits = -12345.6789;

    // setw() 函数用于设置字段的宽度, 默认填充的内容为空格
    // setfill() 函数用于设置字段的填充字符, left 使字符串左对齐, right 使字符串右对齐
    cout << setw(30) << left << setfill('*') << s << endl;

    // setprecision() 函数用于设置浮点数的精度, 默认精度为 6; 
    cout << dec << setprecision(4) << digits << endl;

    // dec 十进制, hex 十六进制, oct 八进制
    cout << dec << 15 << endl;
    
    // setbase(int x)设置进制后，后面所有操作都是按照这个进制来计算！
    cout << setbase(16) << 15 << endl;

    // 四舍五入,并保留2位有效数组
    float x = 3.1415926;
    cout << float(int(x * 100 + 0.5)) / 100.0 << endl;

    system("pause");

    return 0;
}