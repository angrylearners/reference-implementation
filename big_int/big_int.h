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
  
  explicit BigInt(int);
  
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
  
  friend BigInt Pow(const BigInt &, const BigInt &);
  
  friend BigInt Pow(const BigInt &, const int);
  
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
  
  std::vector<int> vec_;
  bool sign_;
  
  void Trim();
  
  static BigInt Zero_;
  static BigInt One_;
  static BigInt Two_;
  static BigInt Ten_;
};

#endif //BIG_INT_BIG_INT_H
