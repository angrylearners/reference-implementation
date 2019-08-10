#include "big_int.h"

#include<vector>
#include<cstring>

BigInt BigInt::Zero_ = BigInt(0);
BigInt BigInt::One_ = BigInt(1);
BigInt BigInt::Two_ = BigInt(2);
BigInt BigInt::Ten_ = BigInt(10);

BigInt::BigInt() {
  vec_.clear();
  sign_ = true;
}

BigInt::BigInt(int i_val) {
  vec_.clear();
  if (i_val >= 0)
    sign_ = true;
  else {
    sign_ = false;
    i_val = -i_val;
  }
  if (i_val == 0) {
    vec_.push_back(0);
  }
  while (i_val > 0) {
    vec_.push_back(i_val % 10);
    i_val /= 10;
  }
}

BigInt::BigInt(const char *i_val) {
  vec_.clear();
  sign_ = true;
  int tmp = 0;
  if (i_val[0] == '-') {
    sign_ = false;
    tmp = 1;
  }
  int len = strlen(i_val);
  for (int i = len - 1; i > 0 + tmp; --i) {
    vec_.push_back(i_val[i] - '0');
  }
  vec_.push_back(i_val[0 + tmp] - '0');
}

BigInt::BigInt(const std::string &i_val) {
  vec_.clear();
  sign_ = true;
  int tmp = 0;
  if (i_val[0] == '-') {
    sign_ = false;
    tmp = 1;
  }
  for (std::string::size_type i = i_val.size() - 1; i > 0 + tmp; --i) {
    vec_.push_back(i_val[i] - '0');
  }
  vec_.push_back(i_val[0 + tmp] - '0');
}

BigInt BigInt::operator=(const BigInt &i_val) {
  vec_.clear();
  sign_ = i_val.sign_;
  for (std::vector<int>::size_type i = 0; i < i_val.vec_.size(); ++i) {
    vec_.push_back(i_val.vec_[i]);
  }
  return *this;
}

BigInt BigInt::operator=(const std::string &i_val) {
  vec_.clear();
  sign_ = true;
  int tmp = 0;
  if (i_val[0] == '-') {
    sign_ = false;
    tmp = 1;
  }
  for (std::string::size_type i = i_val.size() - 1; i > 0 + tmp; --i) {
    vec_.push_back(i_val[i] - '0');
  }
  vec_.push_back(i_val[0 + tmp] - '0');
  return *this;
}

BigInt operator+(const BigInt &lhs, const BigInt &rhs) {
  BigInt ret(lhs);
  ret += rhs;
  return ret;
}

BigInt operator-(const BigInt &lhs, const BigInt &rhs) {
  BigInt ret(lhs);
  ret -= rhs;
  return ret;
}

BigInt operator*(const BigInt &lhs, const BigInt &rhs) {
  BigInt ret(lhs);
  ret *= rhs;
  return ret;
}

BigInt operator/(const BigInt &lhs, const BigInt &rhs) {
  BigInt ret(lhs);
  ret /= rhs;
  return ret;
}

BigInt operator%(const BigInt &lhs, const BigInt &rhs) {
  BigInt ret(lhs);
  ret %= rhs;
  return ret;
}

BigInt &BigInt::operator+=(const BigInt &i_val) {
  if (sign_ == i_val.sign_) {
    while (vec_.size() <= i_val.vec_.size()) {
      vec_.push_back(0);
    }
    int carry = 0;
    std::vector<int>::size_type i;
    for (i = 0; i < i_val.vec_.size(); ++i) {
      vec_.at(i) += carry + i_val.vec_.at(i);
      if (vec_[i] >= 10) {
        carry = 1;
        vec_[i] -= 10;
      } else
        carry = 0;
    }
    for (; i < vec_.size(); ++i) {
      vec_.at(i) += carry + 0;
      if (vec_[i] >= 10) {
        carry = 1;
        vec_[i] -= 10;
      } else
        carry = 0;
    }
  } else {
    if (sign_ == true && i_val.sign_ == false) {
      BigInt tmp(i_val);
      tmp.sign_ = true;
      *this -= tmp;
    } else {
      BigInt tmp(*this);
      tmp.sign_ = true;
      *this = i_val - tmp;
    }
  }
  Trim();
  return *this;
}

BigInt &BigInt::operator-=(const BigInt &i_val) {
  BigInt tmp;
  if (*this < i_val) {
    tmp = *this;
    *this = i_val;
    this->sign_ = false;
  } else {
    tmp = i_val;
  }
  int bor = 0;
  std::vector<int>::size_type i;
  for (i = 0; i < tmp.vec_.size(); ++i) {
    vec_[i] -= bor + tmp.vec_[i];
    if (vec_[i] < 0) {
      bor = 1;
      vec_[i] += 10;
    } else
      bor = 0;
  }
  for (; i < vec_.size(); ++i) {
    vec_[i] -= bor;
    if (vec_[i] < 0) {
      bor = 1;
      vec_[i] += 10;
    } else
      bor = 0;
  }
  Trim();
  return *this;
}

BigInt &BigInt::operator*=(const BigInt &i_val) {
  BigInt ret;
  if (this->sign_ == i_val.sign_)
    ret.sign_ = true;
  else
    ret.sign_ = false;
  for (std::vector<int>::size_type i = 0; i < vec_.size(); ++i) {
    for (std::vector<int>::size_type j = 0; j < i_val.vec_.size(); ++j) {
      if (i + j < ret.vec_.size()) {
        ret.vec_[i + j] += vec_[i] * i_val.vec_[j];
      } else {
        ret.vec_.push_back(vec_[i] * i_val.vec_[j]);
      }
    }
  }
  for (std::vector<int>::size_type i = 0; i < ret.vec_.size(); ++i) {
    if (i + 1 < ret.vec_.size()) {
      ret.vec_[i + 1] += ret.vec_[i] / 10;
    } else if (ret.vec_[i] >= 10) {
      ret.vec_.push_back(ret.vec_[i] / 10);
    } else {
      break;
    }
    ret.vec_[i] %= 10;
  }
  ret.Trim();
  *this = ret;
  return *this;
}

BigInt &BigInt::operator/=(const BigInt &i_val) {
  if (*this == i_val) {
    *this = BigInt::One_;
    return *this;
  }
  std::cout << *this << std::endl;
  std::cout << i_val << std::endl;
  
  BigInt ret(0);
  if (sign_ == i_val.sign_)
    ret.sign_ = true;
  else
    ret.sign_ = false;
  
  BigInt divider(i_val);
  
  this->sign_ = true;
  divider.sign_ = true;
  
  if (*this < divider) {
    *this = BigInt::Zero_;
    return *this;
  }
  
  int cnt = 0;
  while (*this > BigInt::Zero_) {
    if (*this >= divider) {
      *this -= divider;
      ret += Pow(BigInt::Ten_, cnt);
      divider *= BigInt::Ten_;
      cnt++;
    } else {
      divider = i_val;
      cnt = 0;
      if (*this < divider) {
        ret.Trim();
        *this = ret;
        return *this;
      }
    }
    divider.sign_ = true;
  }
  
  ret.Trim();
  *this = ret;
  return *this;
}

BigInt &BigInt::operator%=(const BigInt &i_val) {
  *this = *this - (*this / i_val) * i_val;
  return *this;
}

BigInt &BigInt::operator++() {
  *this += BigInt::One_;
  return *this;
}//前置++

BigInt &BigInt::operator--() {
  *this -= BigInt::One_;
  return *this;
}

const BigInt BigInt::operator++(int) {
  BigInt temp = *this;
  ++(*this);
  return BigInt(temp);
}

const BigInt BigInt::operator--(int) {
  BigInt temp = *this;
  --(*this);
  return BigInt(temp);
}

BigInt &BigInt::operator+() {
  return *this;
}

BigInt &BigInt::operator-() {
  this->sign_ = !(this->sign_);
  return *this;
}

bool operator>(const BigInt &lhs, const BigInt &rhs) {
  return (lhs != rhs) && (rhs < lhs);
}

bool operator>=(const BigInt &lhs, const BigInt &rhs) {
  return !(lhs < rhs);
}

bool operator<(const BigInt &lhs, const BigInt &rhs) {
  if (lhs.sign_ == false && rhs.sign_ == true)
    return true;
  if (lhs.sign_ == true && rhs.sign_ == false)
    return false;
  if (lhs.sign_) {
    if (lhs.vec_.size() < rhs.vec_.size())
      return true;
    else if (lhs.vec_.size() > rhs.vec_.size())
      return false;
  } else {
    if (lhs.vec_.size() < rhs.vec_.size())
      return false;
    else if (lhs.vec_.size() > rhs.vec_.size())
      return true;
  }
  for (std::vector<int>::size_type i = lhs.vec_.size() - 1; i > 0; --i) {
    if (lhs.vec_[i] < rhs.vec_[i]) {
      if (lhs.sign_)
        return true;
      else
        return false;
    } else if (lhs.vec_[i] > rhs.vec_[i]) {
      if (lhs.sign_)
        return false;
      else
        return true;
    }
  }
  if (lhs.vec_[0] < rhs.vec_[0]) {
    if (lhs.sign_)
      return true;
    else
      return false;
  }
  return false;
}

bool operator<=(const BigInt &lhs, const BigInt &rhs) {
  return !(lhs > rhs);
}

bool operator==(const BigInt &lhs, const BigInt &rhs) {
  if (lhs.sign_ != rhs.sign_
      || lhs.vec_.size() != rhs.vec_.size())
    return false;
  for (std::vector<int>::size_type i = 0; i < lhs.vec_.size(); i++) {
    if (lhs.vec_.at(i) != rhs.vec_.at(i))
      return false;
  }
  return true;
}

bool operator!=(const BigInt &lhs, const BigInt &rhs) {
  return !(lhs == rhs);
}

std::istream &operator>>(std::istream &in, BigInt &o_val) {
  std::string tmp;
  in >> tmp;
  o_val = tmp;
  return in;
}

std::ostream &operator<<(std::ostream &out, const BigInt &i_val) {
  if (i_val.vec_.size() == 0) {
    out << "0";
  } else {
    if (i_val.sign_ == false)
      out << '-';
    for (std::vector<int>::size_type i = i_val.vec_.size() - 1; i > 0; --i) {
      out << i_val.vec_[i];
    }
    out << i_val.vec_[0];
  }
  return out;
}

BigInt Pow(const BigInt &i_val, const BigInt &i_exp) {
  if (i_exp == BigInt::Zero_ || i_val == BigInt::One_) {
    return BigInt::One_;
  }
  if (i_val == BigInt::Zero_) {
    return BigInt::Zero_;
  }
  
  BigInt i(0);
  BigInt ret(i_val);
  BigInt exp(i_exp);
  
  exp -= BigInt::One_;
  
  while (i < exp) {
    ret *= i_val;
    ++i;
  }
  
  return ret;
}

BigInt Pow(const BigInt &i_val, const int i_exp) {
  BigInt exp(i_exp);
  return Pow(i_val, exp);
}

void BigInt::Trim() {
  while (vec_.size() > 1 && vec_[vec_.size() - 1] == 0)
    vec_.pop_back();
}