#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::stack<std::vector<int>> exps; // стэк распоз. рег. выр-е в ОБЗ

// проверка на праивльность записания в ОБЗ
bool Is_RPN(const std::string &s) {
  int balance = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '+' || s[i] == '.') {
      --balance;
    } else if (('a' <= s[i] && s[i] <= 'c') || s[i] == '1') {
      ++balance;
    }
    if (balance < 1) {
      return false;
    }
  }
  return (balance == 1);
}
// операция суммирования
void Plus(int k) {
  std::vector<int> right = exps.top();
  exps.pop();
  std::vector<int> left = exps.top();
  exps.pop();
  std::vector<int> v(k, -1);
  for (int i = 0; i < k; ++i) {
    int l = left[i];
    int r = right[i];
    if (l == -1) {
      v[i] = r;
    } else if (r == -1) {
      v[i] = l;
    } else {
      v[i] = std::min(l, r);
    }
  }
  exps.push(v);
}
// операция конкатенации
std::vector<int> Concatenation(const std::vector<int>& right, const std::vector<int>& left, int k) {
  std::vector<int> v(k, -1);
  for (int i = 0; i < k; ++i) {
    int ans = -1;
    for (int j = 0; j < k; ++j) {
      int l = left[j];
      int r = right[(i - j + k) % k];
      if (l != -1 && r != -1) {
        if (ans == -1) {
          ans = l + r;
        } else if (ans > l + r) {
          ans = l + r;
        }
      }
    }
    v[i] = ans;
  }
  return v;
}

std::vector<int> Concat_by_Power(const std::vector<int>& v, int power, int k) {
    if(power == 1) {
        return v;
    }
    if(power  % 2 == 1) {
        return Concatenation(Concat_by_Power(v,power - 1,k),v,k);
    } else {
        std::vector<int> u =  Concat_by_Power(v,power/2,k);
        return Concatenation(u,u,k);
    }
}

//Замыкание Клини
void Kleene_Star(int k, int &z) {
    std::vector<int> v = exps.top();
    exps.pop();
    v[0] = 0;
    exps.push(Concat_by_Power(v,k,k));
}

void Build_Reg_Expr(std::string &s, int k, int l) {
  for (int z = 0; z < s.size(); ++z) {
    if (s[z] == '+') {
      Plus(k);
    } else if (s[z] == '.') {
        std::vector<int> right = exps.top();
        exps.pop();
        std::vector<int> left = exps.top();
        exps.pop();
        exps.push(Concatenation(right,left,k));
    } else if (s[z] == '*') {
      Kleene_Star(k, z);
    } else {
      std::vector<int> v(k, -1);
      if (s[z] == '1') {
        v[0] = 0;
      } else {
        v[!(k == 1)] = 1;
      }
      exps.push(v);
    }
  }
}

void Get_Minimal_String(std::string &s, int k, int l) {
  if (Is_RPN(s)) {
    Build_Reg_Expr(s, k, l);
    int n = exps.top()[l];
    if (n != -1) {
      std::cout << n;
    } else {
      std::cout << "INF";
    }
  } else {
    std::cout << "ERROR";
  }
  std::cout << '\n';
}
