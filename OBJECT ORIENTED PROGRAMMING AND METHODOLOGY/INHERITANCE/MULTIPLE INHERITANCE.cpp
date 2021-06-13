#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class StudentDetails
{
protected:
    ll roll_number;
public:
    void set_roll(ll);
    void display_roll();
};
class SubjectMarks
{         
protected:
    ll sub1;
    ll sub2;
public:
    void set_marks(ll,ll);
    void display_marks();
};
class Result : public SubjectMarks, public StudentDetails       // NOTE
{
    ll total;
public:
    void display_result();
};
void StudentDetails :: set_roll(ll a)
{
    roll_number=a;
}
void StudentDetails :: display_roll()
{
    cout<<"Roll Number = "<<roll_number<<endl;
}
void SubjectMarks :: set_marks(ll a,ll b)
{
    sub1=a;
    sub2=b;
}
void SubjectMarks :: display_marks()
{
    cout<<"SUB1 = "<<sub1<<endl;
    cout<<"SUB2 = "<<sub2<<endl;
}
void Result :: display_result()
{
    display_roll();
    display_marks();
    total = sub1+sub2;
    cout<<"Total = "<<total<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Result a;
    a.set_roll(1);
    a.set_marks(90,88);
    a.display_result();
    return 0;
}
// HERE IN RESULT.....
/* PRIVATE:
    TOTAL               FROM RESULT CLASS
   PROTECTED:
    ROLL_NUMBER,        FROM STUDENTDETAILS
    SUB1,               FROM SUBJECT MARKS
    SUB2                FROM SUBJECT MARKS
   PUBLIC:
    SET_ROLL,           FROM STUDENTDETAILS
    DISPLAY_ROLL,       FROM STUDENT DETAILS
    SET_MARKS,          FROM SUBJECT MARKS
    DISPLAY_MARKS,      FROM SUBJECT MARKS
    DISPLAY_RESULT      FROM RESULT
*/ 

