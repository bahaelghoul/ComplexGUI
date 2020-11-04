#include "complex.h"
#include <cmath>
/*complex::complex()
{
    x1=new float; x2=new float; y1=new float; y2=new float;
    *x1=*real_1;
    *y1=*im_1;
    *x2=*real_2;
    *y2=*im_2;

}
complex::~complex()
{
    delete x1;
    delete x2;
    delete y1;
    delete y2;
}*/
float add(float a, float b)
{
    float result;
    result =a+b;
    return result;
}
float substract(float a,float b)
{
    float result;
    result = a-b;
    return result;
}
void forme_exponentielle(float &mod,float &arg, float x , float y) // conversion de la forme algébrique à la forme exponentielle
{
    mod=sqrt(powf(x,2)+powf(y,2));
    if(x>0)
        arg=atan(y/x);
    else if(x<0 && y>0)
        arg=atan(y/x) + atan(1)*4;
    else if(x<0 && y<0)
        arg=atan(y/x) - atan(1)*4;

    else if(x==0 && y>0)
        arg=atan(1)*2;
    else if(x==0 && y<0)
        arg=-atan(1)*2;
    arg=arg*180/(atan(1)*4);    //Conversion de l'argument du randian en degrés
}
void forme_algebrique(float mod,float arg, float &x , float &y) // conversion de la forme exponentielle à la forme algébrique
{
    arg=arg*((atan(1)*4)/180);    //Conversion de l'argument du randian en degrés
    x=mod*cos(arg);
    y=mod*sin(arg);
}

