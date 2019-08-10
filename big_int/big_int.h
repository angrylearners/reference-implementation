//
// Created by 31838 on 8/10/2019.
//

#ifndef BIG_INT_BIG_INT_H
#define BIG_INT_BIG_INT_H

#include<string>
#include<vector>
#include<iostream>

class BigInt {

public:
  
  BigInt();
  
  explicit BigInt(const int);
  
  explicit BigInt(const char *);
  
  explicit BigInt(const std::string &);
  
  
  BigInt &operator+=(const BigInt &);
  
  BigInt &operator-=(const BigInt &);
  
  BigInt &operator*=(const BigInt &);
  
  BigInt &operator/=(const BigInt &);
  
  BigInt &operator%=(const BigInt &);
  
  BigInt &operator++();
  BigInt &operator--();
  
  const BigInt operator++(int);
  const BigInt operator--(int);
  
  BigInt &operator+();
  
  BigInt &operator-();//负号
  
  BigInt operator=(const BigInt &);
  
  BigInt operator=(const std::string &);
  
  friend BigInt pow(const BigInt &, const BigInt &);
  friend BigInt pow(const BigInt &, const int);
  
  friend std::istream &operator>>(std::istream &, BigInt &);
  
  friend std::ostream &operator<<(std::ostream &, const BigInt &);
  
  friend BigInt operator+(const BigInt &, const BigInt &);
  
  friend BigInt operator-(const BigInt &, const BigInt &);
  
  friend BigInt operator*(const BigInt &, const BigInt &);
  
  friend BigInt operator/(const BigInt &, const BigInt &);
  
  friend BigInt operator%(const BigInt &, const BigInt &);
  
  friend bool operator>(const BigInt &, const BigInt &);
  
  friend bool operator>=(const BigInt &, const BigInt &);
  
  friend bool operator<(const BigInt &, const BigInt &);
  
  friend bool operator<=(const BigInt &, const BigInt &);
  
  friend bool operator==(const BigInt &, const BigInt &);
  
  friend bool operator!=(const BigInt &, const BigInt &);

private:
  
  std::vector<int> vec;
  bool sign_;
  
  void trim();
  
  static BigInt ZERO;
  static BigInt ONE;
  static BigInt TWO;
  static BigInt TEN;
};

#endif //BIG_INT_BIG_INT_H
