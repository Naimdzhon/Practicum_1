#include <iostream>
#include <vector>
#include <string>
#include <stack>


//cтрктура регулярных выражений
struct RegExp {
    std::string str; //ОПЗ регу-го выр-я
    std::vector<int> length; //вектор из мин. длин для каждого остатка
    RegExp(const std::string& str, std::vector<int>& v) : str(str), length(v) {
    }
};

std::string s; // исходное рег-ое выр-е
int k;
std::stack<RegExp> exps; // стэк распоз. рег. выр-е в ОБЗ

// проверка на праивльность записания в ОБЗ
bool Is_RPN()
{
    int balance = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+' || s[i] == '.') {
            --balance;
        }
        else if (('a' <= s[i] && s[i] <= 'c') || s[i] == '1') {
            ++balance;
        }
        if(balance < 1) {
            return false;
        }
    }
    return (balance == 1);
}
// операция суммирования
void Plus()
{
    RegExp right = exps.top();
    exps.pop();
    RegExp left = exps.top();
    exps.pop();
    std::vector<int> v(k, -1);
    for (int i = 0; i < k; ++i) {
        int l = left.length[i];
        int r = right.length[i];
        if (l == -1) {
            v[i] = r;
        }
        else if (r == -1) {
            v[i] = l;
        }
        else {
            v[i] = std::min(l, r);
        }
    }
    exps.push(RegExp(left.str + right.str + '+', v));
}
// операция конкатенации
void Concatenation()
{
    RegExp right = exps.top();
    exps.pop();
    RegExp left = exps.top();
    exps.pop();
    std::vector<int> v(k, -1);
    for (int i = 0; i < k; ++i) {
        int ans = -1;
        for (int j = 0; j < k; ++j) {
            int l = left.length[j];
            int r = right.length[(i - j + k) % k];
            if (l != -1 && r != -1) {
                if (ans == -1) {
                    ans = l + r;
                }
                else if (ans > l + r) {
                    ans = l + r;
                }
            }
        }
        v[i] = ans;
    }
    exps.push(RegExp(left.str + right.str + '.', v));
}
//Замыкание Клини
void Kleene_Star(int& z)
{
    s[z] = '1';
    s.insert(z + 1, "+");
    std::string new_str = "";
    std::string mult = "";
    for (int i = 1; i < k; ++i) {
        new_str += exps.top().str + "1+";
        mult += '.';
    }
    new_str += mult;
    s.insert(z + 2, new_str);
    --z;
}

void Build_Reg_Expr()
{
    for (int z = 0; z < s.size(); ++z) {
        if (s[z] == '+') {
            Plus();
        }
        else if (s[z] == '.') {
            Concatenation();
        }
        else if (s[z] == '*') {
            Kleene_Star(z);
        }
        else {
            std::vector<int> v(k, -1);
            if (s[z] == '1') {
                v[0] = 0;
            }
            else {
                v[!(k == 1)] = 1;
            }
            std::string str;
            str += s[z];
            exps.push(RegExp(str, v));
        }
    }
}

int main()
{
    int l;
    std::cin >> s >> k >> l;
    if (Is_RPN()) {
        Build_Reg_Expr();
        int n = exps.top().length[l];
        if (n != -1) {
            std::cout << n;
        }
        else {
            std::cout << "INF";
        }
    }
    else {
        std::cout << "ERROR";
    }
    return 0;
}
