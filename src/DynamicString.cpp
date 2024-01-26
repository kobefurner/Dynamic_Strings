#include "DynamicString.h"
#include <cctype>
#include <stdexcept>

using std::out_of_range;
using std::tolower;
using std::toupper;
using std::ostream;

DynamicString::DynamicString(){
   cstr = new char[1];
   cstr[0] = '\0';
}

DynamicString::DynamicString(const char* str){
   int length = 0;
   while (str[length] != '\0'){
      length++;
   }
   
   cstr = new char[length];
   for (int i = 0; i <= length; i++){
      cstr[i] = str[i];
   }
}

DynamicString::DynamicString(const DynamicString& other){
   int length = 0;
   while (other.cstr[length] != '\0'){
      length++;
   }
   cstr = new char[length + 1];
   for (int i = 0; i <= length; i++){
      cstr[i] = other.cstr[i];
   }
}

DynamicString& DynamicString::operator=(const DynamicString& other){
   if (this != &other){
      delete[] cstr;

      int length = 0;
      while (other.cstr[length] != '\0'){
      length++;
      }

      cstr = new char[length + 1];
      for (int i = 0; i < length; i++){
         cstr[i] = other.cstr[i];
      }
      cstr[length] = '\0';
   }
   return *this;
}

DynamicString::~DynamicString(){
   delete[] cstr;
}

int DynamicString::len() const{
   int length = 0;
   while (cstr[length] != '\0'){
      length++;
      }
   return length;
}

const char* DynamicString::c_str() const{
   return cstr;
}

char DynamicString::char_at(int position) const{
   int length = len();

    if (position < 0 || position >= length) {
        throw std::out_of_range("Out of range");
    }
   return cstr[position];
}

char& DynamicString::operator[](int position){
   int length = len();

    if (position < 0 || position >= length) {
        throw std::out_of_range("Out of range");
    }
   return cstr[position];
}

bool DynamicString::startsWith(const DynamicString& other) const{
   int otherLen = other.len();
   int length = len();

   if (otherLen > length){
      return false;
   }
   for (int i = 0; i < otherLen; i++){
      if (cstr[i] != other.cstr[i]){
         return false;
      }
   }
   return true;
}

bool DynamicString::endsWith(const DynamicString& other) const{
   int otherLen = other.len();
   int length = len();

   if (otherLen > length) {
      return false;
   }

   for (int i = 0; i < otherLen; i++) {
      if (cstr[length - otherLen + i] != other.char_at(i)){
         return false;
      }
   }
   return true;
}

int DynamicString::compare(const DynamicString& other) const{
   int lenThis = len();
    int lenOther = other.len();
    int minLength = std::min(lenThis, lenOther);

     for (int i = 0; i < minLength; ++i) {
        if (cstr[i] < other.cstr[i]) {
            return -1;
        } else if (cstr[i] > other.cstr[i]) {
            return 1;
        }
    }

    if (lenThis < lenOther) {
        return -1;
    } else if (lenThis > lenOther) {
        return 1;
    }

    return 0;
}

DynamicString& DynamicString::toLower(){
   int length = len();
   for (int i = 0; i < length; i++){
      cstr[i] = std::tolower(this->cstr[i]);
   }
   return *this;
}

DynamicString& DynamicString::toUpper(){
   int length = len();
   for (int i = 0; i < length; i++){
      cstr[i] = std::toupper(this->cstr[i]);
   }
   return *this;
}

DynamicString& DynamicString::replace(char old, char newCh){
   int length = len();

   for (int i = 0; i < length; i++) {
      if (cstr[i] == old) {
         cstr[i] = newCh;
      }
   }

   return *this;
}

int DynamicString::find(char c, int start) const{
   int length = len();
   for (int i = start; i < length; i++){
      if (cstr[i] == c){
         return i;
      }
   }
   return -1;
}

ostream& operator<<(ostream& out, const DynamicString& str){
   out << str.c_str();
   return out;
}
