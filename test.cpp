#include "Problem.h"
#include <iostream>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  {
    std::string s;
    int k, l;
    std::cin >> s >> k >> l;
    std::cout << "My_OWN_Test" << '\n'
              << "Input:" << '\t' << "String: " << s << '\t' << "Divider: " << k
              << '\t' << "Remainder: " << l << '\n';
    std::cout << "Output:" << '\t';
    Get_Minimal_String(s, k, l);
  }
  {
    std::string s = "ab+c.aba..bac.+.+";
    int k = 3;
    int l = 1;
    std::cout << "TEST_1" << '\n'
              << "Input:" << '\t' << "String: " << s << '\t' << "Divider: " << k
              << '\t' << "Remainder: " << l << '\n';
    std::cout << "Output:" << '\t';
    Get_Minimal_String(s, k, l);
  }
  {
    std::string s = "acb..bab.c.*.ab.ba.+.+*a.";
    int k = 3;
    int l = 0;
    std::cout << "TEST_2" << '\n'
              << "Input:" << '\t' << "String: " << s << '\t' << "Divider: " << k
              << '\t' << "Remainder: " << l << '\n';
    std::cout << "Output:" << '\t';
    Get_Minimal_String(s, k, l);
  }
  {
    std::string s = "ab+c.aba..bac.+.+";
    int k = 3;
    int l = 2;
    std::cout << "TEST_3" << '\n'
              << "Input:" << '\t' << "String: " << s << '\t' << "Divider: " << k
              << '\t' << "Remainder: " << l << '\n';
    std::cout << "Output:" << '\t';
    Get_Minimal_String(s, k, l);
  }
  {
    std::string s = "abcb...ab.+*";
    int k = 4;
    int l = 3;
    std::cout << "TEST_4" << '\n'
              << "Input:" << '\t' << "String: " << s << '\t' << "Divider: " << k
              << '\t' << "Remainder: " << l << '\n';
    std::cout << "Output:" << '\t';
    Get_Minimal_String(s, k, l);
  }
  {
    std::string s = "accb...1+";
    int k = 4;
    int l = 0;
    std::cout << "TEST_5" << '\n'
              << "Input:" << '\t' << "String: " << s << '\t' << "Divider: " << k
              << '\t' << "Remainder: " << l << '\n';
    std::cout << "Output:" << '\t';
    Get_Minimal_String(s, k, l);
  }
  {
    std::string s = "abcb...aab..+*";
    int k = 6;
    int l = 5;
    std::cout << "TEST_6" << '\n'
              << "Input:" << '\t' << "String: " << s << '\t' << "Divider: " << k
              << '\t' << "Remainder: " << l << '\n';
    std::cout << "Output:" << '\t';
    Get_Minimal_String(s, k, l);
  }
  {
    std::string s = "abc*.+bac.+.";
    int k = 1;
    int l = 0;
    std::cout << "TEST_7" << '\n'
              << "Input:" << '\t' << "String: " << s << '\t' << "Divider: " << k
              << '\t' << "Remainder: " << l << '\n';
    std::cout << "Output:" << '\t';
    Get_Minimal_String(s, k, l);
  }
  {
    std::string s = "acb..bab.c.*.ab.ba.+.+*a";
    int k = 4;
    int l = 3;
    std::cout << "TEST_8" << '\n'
              << "Input:" << '\t' << "String: " << s << '\t' << "Divider: " << k
              << '\t' << "Remainder: " << l << '\n';
    std::cout << "Output:" << '\t';
    Get_Minimal_String(s, k, l);
  }
  {
    std::string s = "aba.*.a.*ab1+..";
    int k = 5;
    int l = 4;
    std::cout << "TEST_9" << '\n'
              << "Input:" << '\t' << "String: " << s << '\t' << "Divider: " << k
              << '\t' << "Remainder: " << l << '\n';
    std::cout << "Output:" << '\t';
    Get_Minimal_String(s, k, l);
  }

  return 0;
}
