#include "Super_Int.h"

using namespace std;

static int power(int num, unsigned int pow);
static int int_lenght(int n);

Super_int::Super_int()
{
    Number.push_back(0);
    signe = true;
}

Super_int::Super_int(int chifre)
{
    int i;
    if (chifre < 0)
    {
        signe = false;
        chifre *= -1;
    }
    else
        signe = true;
    Number.clear();
    for (i = 0; i <= int_lenght(chifre) - 1; i++)
    {
        Number.push_back((chifre % power(10, i + 1) - chifre % power(10, i)) / power(10, i));
    }
}

Super_int::~Super_int()
{
    // there is nothing to do in here none dynamic allocation have been made
}

ostream &operator<<(ostream &flux,Super_int &a)
{
    int i = 0;
    if (a.Get_Signe() == false)
    {
        flux << "-";
    }
    for (i = a.Size_l() - 1; i >= 0; i--)
    {
        flux << a.Get_Value(i);
    }
    return flux;
}

Super_int &Super_int::operator=(int chifre)
{
    int i;
    if (chifre < 0)
    {
        signe = false;
        chifre *= -1;
    }
    Number.clear();
    for (i = 0; i <= int_lenght(chifre) - 1; i++)
    {
        Number.push_back((chifre % power(10, i + 1) - chifre % power(10, i)) / power(10, i));
    }
    return *this;
}

Super_int &Super_int::operator=(Super_int &b)
{
    int i;
    Number.clear();
    for (i = 0; i <= b.Number.size() - 1; i++)
    {
        Number.push_back(b.Number[i]);
    }
    return *this;
}

bool operator==(Super_int &b, Super_int &a)
{
    int unsigned i = 0;
    bool tf = 0;

    if (a.Size_l() == b.Size_l())
    {
        for (i = 0; i <= a.Size_l() - 1; i++)
        {
            if (b.Get_Value(i) != a.Get_Value(i))
            {
                goto dif_end;
            }
        }
        tf = 1;
    }
dif_end:
    return tf;
}

bool operator==(Super_int &b, int chifre)
{
    int unsigned i = 0, n;
    bool tf = 0;
    if (b.Size_l() == int_lenght(chifre))
    {
        for (i = 0; i <= b.Size_l() - 1; i++)
        {
            if (i == 0)
                n = chifre % 10;
            else
                n = (chifre % power(10, i + 1) - chifre % power(10, i)) / power(10, i);
            if (b.Get_Value(i) != n)
                goto dif_end;
        }
        tf = 1;
    }
dif_end:
    return tf;
}

bool operator!=(Super_int &b, Super_int &a)
{
    int unsigned i = 0;
    bool tf = 1;
    if (a.Size_l() == b.Size_l())
    {
        for (i = 0; i < a.Size_l() - 1; i++)
        {
            if (b.Get_Value(i) != a.Get_Value(i))
            {
                goto dif_end;
            }
        }
        tf = 0;
    }
dif_end:
    return tf;
}

bool operator!=(Super_int &b, int chifre)
{
    Super_int C = chifre;
    return b != C;
}

bool operator<(Super_int &b, Super_int &a)
{
    int i;
    bool tf = 0;
    if (a == b)
    {
        return false;
    }
    if (a.Size_l() > b.Size_l())
    {
        return true;
    }
    if (a.Size_l() < b.Size_l())
    {
        return false;
    }
    if (a.Size_l() == b.Size_l())
    {
        for (i = a.Size_l() - 1; i >= 0; i--)
        {
            if (b.Get_Value(i) > a.Get_Value(i))
            {
                goto dif_end;
            }
            else if (b.Get_Value(i) < a.Get_Value(i))
            {
                tf = 1;
                goto dif_end;
            }
        }
    }
dif_end:
    return tf;
}

bool operator<(Super_int &b, int chifre)
{
    Super_int C = chifre;
    return b < C;
}

bool operator>(Super_int &b, Super_int &a)
{
    int i;
    bool tf = 0;
    if (a == b)
    {
        return false;
    }
    if (a.Size_l() < b.Size_l())
    {
        return true;
    }
    if (a.Size_l() > b.Size_l())
    {
        return false;
    }
    if (a.Size_l() == b.Size_l())
    {
        for (i = a.Size_l() - 1; i >= 0; i--)
        {
            if (b.Get_Value(i) < a.Get_Value(i))
            {
                goto dif_end;
            }
            else if (b.Get_Value(i) > a.Get_Value(i))
            {
                tf = 1;
                goto dif_end;
            }
        }
    }
dif_end:
    return tf;
}

bool operator>(Super_int &b, int chifre)
{
    Super_int C = chifre;
    return b > C;
}

bool operator>=(Super_int &b, Super_int &a)
{
    if ((a == b) | (b > a))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>=(Super_int &b, int chifre)
{
    Super_int C = chifre;
    return b >= C;
}

bool operator<=(Super_int &b, Super_int &a)
{
    if ((a == b) | (b < a))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<=(Super_int &b, int chifre)
{
    Super_int C = chifre;
    return b <= C;
}

Super_int operator+(Super_int &a, int chifre) 
{
    Super_int temp = a;
    temp += chifre;
    return temp;
}

Super_int operator+(Super_int &a, Super_int &b)
{
    Super_int temp = a;
    temp += b;
    return temp;
}

Super_int operator-(Super_int &a, int chifre) 
{
    Super_int temp = a;
    temp -= chifre;
    return temp;
}

Super_int operator-(Super_int &a, Super_int &b)
{
    Super_int temp = a;
    temp -= b;
    return temp;
}

Super_int operator*(Super_int &a, Super_int &b)
{
    Super_int temp = a, B = b, i;
    for (i = 1; i < B; i += 1)
    {
        temp += a;
    }
    return temp;
}

Super_int operator*(Super_int &a, int chifre) // i used an exception for a negative int chifre because a Super int is always positive for now
{
    Super_int temp(0);
    int i = 0;
    try
    {
        if (chifre == 0)
        {
            return temp;
        }
        else if (chifre > 0)
        {
            for (i = 1; i <= chifre; i++)
            {
                temp += a;
            }
        }
        else
            throw string(" Wrong multiplication Param ! \n");
    }
    catch (string &Error)
    {
        cerr << Error;
    }
    return temp;
}

Super_int &Super_int::operator+=(int chifre)
{
    
    if (chifre < 0) // If the input is negative then we substact it from the operand
    {
        return *this-=chifre*(-1);
    }


    int i = 0, j, temp;
    if (Number.size() < int_lenght(chifre))
    {
        temp = int_lenght(chifre) - Number.size();
        for (i = 1; i <= temp; i++)
        {
            Number.push_back(0);
        }
    }
    if (Number.size() == int_lenght(chifre))
    {
        if ((Number[Number.size() - 1] + (chifre - chifre % power(10, int_lenght(chifre) - 1)) / power(10, int_lenght(chifre) - 1)) >= 10)
        {
            Number.push_back(0);
        }
    }
    int in = int_lenght(chifre);
    for (i = 0; i <= in - 1; i++)
    {

        temp = (chifre % power(10, i + 1) - chifre % power(10, i)) / power(10, i); // this equation give every digit of a number from MSD to LSD
        Number[i] += temp;
        j = i;
        while (Number[j] >= 10)
        {
            if (j + 1 >= Number.size())
            {
                Number.push_back((Number[j] - Number[j] % 10) / 10);
            }
            else
            {
                Number[j + 1] += (Number[j] - Number[j] % 10) / 10;
            }
            Number[j] = Number[j] % 10;
            j++;
        }
    }
    return *this;
}

Super_int &Super_int::operator+=(Super_int &a)
{
     if (a.signe==-1) // If the input is negative then we substact it from the operand
    {
        
        return *this-=a;
    }
    int i = 0, j = 0;

    if (Number.size() < a.Number.size())
    {
        j = a.Number.size() - Number.size();
        for (i = 1; i <= j; i++)
        {
            Number.push_back(0);
        }
    }
    if (Number.size() == a.Number.size())
    {
        if (Number[Number.size() - 1] + a.Number[a.Number.size() - 1] > 9)
        {
            Number.push_back(0);
        }
    }

    for (i = 0; i <= a.Number.size() - 1; i++)
    {

        Number[i] += a.Number[i];
        if (i != Number.size() - 1)
        {
            if (Number[i] > 9)
            {
                Number[i + 1] += (Number[i] - Number[i] % 10) / 10;
                Number[i] = Number[i] % 10;
            }
        }
        else
        {
            if (Number[i] > 9)
            {
                Number.push_back((Number[i] - Number[i] % 10) / 10);
                Number[i] = Number[i] % 10;
            }
        }
    }
    return *this;
}

Super_int &Super_int::operator-=(int chifre)
{
    if(chifre<0) {chifre=chifre*(-1); return *this+=chifre;} // If the input is negative then -x-=+

    int i = 0, j = 0, temp = 0;
    int int_l = int_lenght(chifre);

    if (Number.size() < int_l)
    {
        for (i = 0; i <= int_l - Number.size(); i++)
        {
            Number.push_back(0);
        }
    }

    for (i = 0; i < int_l; i++)
    {
        temp = ((chifre % power(10, i+1) - chifre % power(10, i)) / power(10, i)); // this equation give every digit of a number from LSD to MSD
        Number[i] -= temp;
        if (Number[i] < 0)
        {
            j = i + 1;
            Number[i] += 10;
            Number[j]--;
            while (Number[j] < 0 && j <= int_l)
            {
                Number[j] += 10;
                Number[j + 1]--;
                j++;
            }
        }
    }

    i = Number.size() - 1;
    while (Number[i] == 0)
    {
        Number.pop_back();
        i--;
        if (i==0){break;}
    }
    return *this;
}

Super_int &Super_int::operator-=(Super_int &a) // not done yet a lot of stuff need to be done.
{
    // I'll asume that a is positive for now
    
    int i = 0, j = 0;

    if (Number.size() < a.Number.size())
    {
        signe=false;
        return a-=*this;
    }
    
    if (Number.size() == a.Number.size())
    {
        if (Number[Number.size() - 1] + a.Number[a.Number.size() - 1] > 9)
        {
            Number.push_back(0);
        }
    }

    for (i = 0; i <= a.Number.size() - 1; i++)
    {

        Number[i] += a.Number[i];
        if (i != Number.size() - 1)
        {
            if (Number[i] > 9)
            {
                Number[i + 1] += (Number[i] - Number[i] % 10) / 10;
                Number[i] = Number[i] % 10;
            }
        }
        else
        {
            if (Number[i] > 9)
            {
                Number.push_back((Number[i] - Number[i] % 10) / 10);
                Number[i] = Number[i] % 10;
            }
        }
    }
    return *this;
}

int Super_int::Size_l()
{
    return Number.size();
}

bool Super_int::Get_Signe()
{
    return signe;
}

int Super_int::Get_Value(unsigned int i)
{
    try
    {
        if (i > Number.size() + 1)
        {
            throw string("Index Error");
        }
        else
        {
            return Number[i];
        }
    }
    catch (string const &Error)
    {
        cerr << " " << Error << endl;
    }
}

void Super_int::Set_Value(int i, int c)
{
    try
    {
        if (i < 0)
        {
            throw string("Index Error");
        }
        else if (i > Number.size() + 1)
        {
            throw string("Index Error");
        }
        else if (c < 0)
        {
            throw string("Value Error : Set_V=Too small");
        }
        else if (c >= 10)
        {
            throw string("Value Error : Set_V=Too big");
        }
        else
        {
            Number[i] = c;
        }
    }
    catch (string const &Error)
    {
        cerr << " " << Error << endl;
    }
}

 void Super_int::Set_Signe(int s)
 {
     try
     {
         if(s==-1){signe=-1;}
         else if(s==1){signe=1;}
         else {throw string("Wrong param");}
     }
     catch(const std::exception& e)
     {
         std::cerr << e.what() << '\n';
     }
     
 }

void Super_int::Push_Value(int c)
{
    try
    {

        if (c < 0)
        {
            throw string("Value Error : PV");
        }
        Number.push_back(c);
    }
    catch (string const &Error)
    {
        cerr << " " << Error << endl;
    }
}

bool Super_int::Is_it_perfect() // it does not work make it do the job
{
    int i(0);
    Super_int cptn1(0), cptn2(0);

    for (i = 0; i <= Number.size() - 1; i++)
    {
        cptn1 += Number[i];
    }
    while (cptn1.Size_l() > 1)
    {
        for (i = 0; i <= cptn1.Size_l() - 1; i++)
        {
            cptn2 += cptn1.Get_Value(i);
        }
        cptn1 = cptn2;
        cptn2 = 0;
    }
    if (cptn1 == 1)
        return true;
    else
        return false;
}

static int power(int num, unsigned int pow)
{
    unsigned int i;
    int P = 1;
    for (i = 1; i <= pow; i++)
    {
        P = P * num;
    }
    return P;
}

static int int_lenght(int n)
{
    int cptn(0);
    while (n / 10 > 0)
    {
        n = n / 10;
        cptn++;
    }
    return cptn + 1;
}
