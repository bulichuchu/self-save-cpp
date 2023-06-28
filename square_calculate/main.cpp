#include <iostream>
#include<cmath>
#include<cstdlib>
#define pi 3.14159265358979323846

using namespace std;

class point{
public:
    double x;
    double y;
    point(double x, double y){//constructor
        this->x = x;
        this->y = y;
    }

    point(const point& p){//copy constructor
        this->x = p.x;
        this->y = p.y;
    }

    point() {//default constructor
        this->x = 0;
        this->y = 0;}

    double distance(const point& p) const{
        return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
    }

    void show() const{
        cout << "(" << this->x << ", " << this->y << ")" << endl;
    }

    point& operator=(const point& p){
        this->x = p.x;
        this->y = p.y;
        return *this;
    }
};

class Circle{
public:
    double radius;
    point center;
    Circle(double radius, const point& center){
        this->radius = radius;
        this->center = center;
    }
    Circle(const Circle& c){
        this->radius = c.radius;
        this->center = c.center;
    }
    double calculateArea() const{
        return pi * pow(this->radius, 2);
    }
    double calculatePerimeter() const{
        return 2 * pi * this->radius;
    }
    bool isIntersection(const Circle& c) const{
        return this->center.distance(c.center) <= this->radius + c.radius;
        //distance between two centers <= sum of two radius
    }
    void show() const{
        cout << "Radius: " << this->radius << endl;
        cout << "Center: ";
        this->center.show();
        cout << "Area: " << this->calculateArea() << endl;
        cout << "Perimeter: " << this->calculatePerimeter() << endl;
    }
};

class Rectangle{
public:
    double length;
    double width;
    point leftup;
    Rectangle(double length, double width, const point& leftup){
        this->length = length;
        this->width = width;
        this->leftup = leftup;
    }
    Rectangle(const Rectangle& r){
        this->length = r.length;
        this->width = r.width;
        this->leftup = r.leftup;
    }
    double calculateArea() const{
        return this->length * this->width;
    }
    double calculatePerimeter() const{
        return 2 * (this->length + this->width);
    }
    bool isIntersection(const Rectangle& r) const{
        return
        this->leftup.x <= r.leftup.x + r.length//左上角点的x是否小于等于传入的右边界的x
        && this->leftup.x + this->length >= r.leftup.x//右边界的x坐标是否大于等于传入的左上角点的x坐标
        &&this->leftup.y <= r.leftup.y + r.width//左上角点的y是否小于等于传入的下边界的y坐标
        && this->leftup.y + this->width >= r.leftup.y;//下边界的y是否大于等于传入的左上角点的y坐标

    }
    void show() const{
        cout << "Length: " << this->length << endl;
        cout << "Width: " << this->width << endl;
        cout << "Leftup: ";
        this->leftup.show();
        cout << "Area: " << this->calculateArea() << endl;
        cout << "Perimeter: " << this->calculatePerimeter() << endl;
    }

};

class Triangle{
public:
    point p1;
    point p2;
    point p3;
    double calculateArea() const{
        double a = p1.distance(p2);
        double b = p2.distance(p3);
        double c = p3.distance(p1);
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    double calculatePerimeter() const{
        return p1.distance(p2) + p2.distance(p3) + p3.distance(p1);
    }
    Triangle(const point& p1, const point& p2, const point& p3){
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
    }
    Triangle(const Triangle& t){
        this->p1 = t.p1;
        this->p2 = t.p2;
        this->p3 = t.p3;
    }
    bool isTrangle() const{
        double a = p1.distance(p2);
        double b = p2.distance(p3);
        double c = p3.distance(p1);
        return a + b > c && a + c > b && b + c > a;
    }
    bool isIntersection(const Triangle& t) const{
        return
        this->p1.x <= t.p1.x && this->p1.x <= t.p2.x && this->p1.x <= t.p3.x
        && this->p2.x <= t.p1.x && this->p2.x <= t.p2.x && this->p2.x <= t.p3.x
        && this->p3.x <= t.p1.x && this->p3.x <= t.p2.x && this->p3.x <= t.p3.x
        && this->p1.y <= t.p1.y && this->p1.y <= t.p2.y && this->p1.y <= t.p3.y
        && this->p2.y <= t.p1.y && this->p2.y <= t.p2.y && this->p2.y <= t.p3.y
        && this->p3.y <= t.p1.y && this->p3.y <= t.p2.y && this->p3.y <= t.p3.y;
    }
    void show() const
    {
        cout << "P1: ";
        this->p1.show();
        cout << "P2: ";
        this->p2.show();
        cout << "P3: ";
        this->p3.show();
        cout << "Area: " << this->calculateArea() << endl;
        cout << "Perimeter: " << this->calculatePerimeter() << endl;}
};

double getrand(double min, double max){
    return min + (max - min) * rand() / RAND_MAX;//加上min到max之间的数
}

int main(){
    Circle c(5, point(0, 0));
    cout<<c.calculateArea()<<endl<<c.calculatePerimeter()<<endl;
    
    Rectangle r(4, 6, point(0, 0));
    cout<<r.calculateArea()<<endl<<r.calculatePerimeter()<<endl;
    
    Triangle t(point(0, 0), point(2, 2), point(1, 2));
    cout<<t.calculateArea()<<endl<<t.calculatePerimeter()<<endl;


    Circle c1(getrand(0,1000), point(getrand(0,1000), getrand(0,1000)));
    c1.show();
    Circle c2(getrand(0,1000), point(getrand(0,1000), getrand(0,1000)));
    c2.show();
    if(c1.isIntersection(c2)){
        cout<<"Intersection"<<endl;
    }
    else{
        cout<<"No Intersection"<<endl;
    }


    Rectangle r1(getrand(0,1000), getrand(0,1000), point(getrand(0,1000), getrand(0,1000)));
    r1.show();
    Rectangle r2(getrand(0,1000), getrand(0,1000), point(getrand(0,1000), getrand(0,1000)));
    r2.show();
    if(r1.isIntersection(r2)){
        cout<<"Intersection"<<endl;
    }
    else{
        cout<<"No Intersection"<<endl;
    }

    Triangle t1(point(getrand(0,1000), getrand(0,1000)), point(getrand(0,1000), getrand(0,1000)), point(getrand(0,1000), getrand(0,1000)));
    t1.show();
    Triangle t2(point(getrand(0,1000), getrand(0,1000)), point(getrand(0,1000), getrand(0,1000)), point(getrand(0,1000), getrand(0,1000)));
    t2.show();
    if(t1.isIntersection(t2)){
        cout<<"Intersection"<<endl;
    }
    else{
        cout<<"No Intersection"<<endl;
    }
}