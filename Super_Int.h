#ifndef Super_int_H  /*        Those are           */
#define Super_int_H  /*    Implementation Guard    */
#include <iostream>
#include <vector>

class Super_int
{
public:
    Super_int();
    Super_int(int chifre);
    ~Super_int();
    /*******Operator_Methods******/
    Super_int&  operator=  (Super_int & b);
    Super_int&  operator=  (int chifre);
    Super_int&  operator+= (int chifre);
    Super_int&  operator+= (Super_int & a);
    Super_int&  operator-= (int chifre);
    Super_int&  operator-= (Super_int & a);
    /***********Methods**********/
    int Size_l();
    int Get_Value(unsigned int i);
    bool Get_Signe();
    bool Is_it_perfect();
private:
    void Set_Value(int i,int c);
    void Push_Value(int c);
    void Set_Signe(int s);
    std::vector<int> Number; // Note to self Remember that the digits are stored from Less Significant Digit (LSD) to Most Significant Digit (MSD)
    int signe=1;// -1 -> negative / 1 -> positive
};

//Super_int  operator% (Super_int &a,Super_int &b);
Super_int  operator* (Super_int & a,Super_int & b);
Super_int  operator* (Super_int & a,int chifre);
//Super_int  operator/ (Super_int &a,Super_int &b);
Super_int  operator- (Super_int &a,Super_int &b);
Super_int  operator- (Super_int &a,int chifre);
Super_int  operator+ (Super_int & a,Super_int & b);
Super_int  operator+ (Super_int & a,int chifre);

////////////////// Comparative operators  ///////////////////////

bool operator== (Super_int & b,Super_int & a);
bool operator== (Super_int & b,int chifre);
bool operator!= (Super_int & b,Super_int & a);
bool operator!= (Super_int & b,int chifre);
bool operator<  (Super_int & b,Super_int & a);
bool operator<  (Super_int & b,int chifre);
bool operator>  (Super_int & b,Super_int & a);
bool operator>  (Super_int & b,int chifre);
bool operator>= (Super_int & b,Super_int & a);
bool operator>= (Super_int & b,int chifre);
bool operator<= (Super_int & b,Super_int & a);
bool operator<= (Super_int & b,int chifre);
std::ostream& operator<< (std::ostream &flux,Super_int & a);
#endif // Super_int_H
