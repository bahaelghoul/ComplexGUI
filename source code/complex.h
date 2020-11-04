#ifndef COMPLEX_H
#define COMPLEX_H

class complex
{
public:
    complex();
    ~complex();

private:
    float *x1;
    float *y1;
    float *x2;
    float *y2;
};
float add(float a, float b);
float substract(float a,float b);
void forme_exponentielle(float &mod,float &arg, float x , float y);
void forme_algebrique(float mod,float arg, float &x , float &y);
#endif // COMPLEX_H
