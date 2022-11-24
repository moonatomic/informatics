#include <iostream>
#include <vector>
#include <fstream>

class Point
{
private:

public:
    Point() {};
    ~Point() {};
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
    double x;
    double y;
    int number;
    int color;
};

class Cloud
{
private:
    std::vector<Point *> points;
public:
    int size = 0;
    void add_point(Point * point);
    std::vector<double> factors;
};

class Buffer
{
private:
    int points_amount;
    std::vector<Point *> points;
public:
    void copy_cloud(Cloud cloud);
    void rotate(Point center);
    void scale(Point center, int lambda);
    void translate(std::vector<double> vec);
};

class Field
{
private:
    int points_amount;
    void add_point(Point &point);
    std::vector<Cloud *> clouds;
    std::vector<Point> points;
public:
    //Point vPoint;
    //Cloud vCloud;
    //Buffer vBuffer;
    Field() {
        points_amount = 0;
    };
    ~Field() {};
    std::vector<Point>* get_points();
    int get_amount();
    Point* yield_point(int number);
    double distance(Point a, Point b);
    void generate(int amount, double center_x, double center_y, double deviation_x, double deviation_y); 
};

class Interface
{
public:
    //Controller vController;
    //Field vField;
    Interface() {};
    ~Interface() {};
    void start();
};

class Exec
{
private:
    int id;
    int size;
    Field id_field;
    std::vector< std::vector <bool> > rclusters; 
public:
    Exec(int _process_id, Field &_field) { 
        id = _process_id;
        id_field = _field;
        size = _field.get_amount();
    };
    ~Exec() {};
    void k_means(int k);
    void wave(double delta);
    void DBSCAN(double delta, int k);
    void save();
};

class Controller
{
private:
    std::vector<Exec> processes;
public:
    //Field vField;
    //Exec vExec;
    Controller() {};
    ~Controller() {};
    void save(int process_id);
    void clusterize(Field &field, int process_id, int method, double opt); 
    void generate(Field &field, int amount, double center_x, double center_y, double deviation_x, double deviation_y); 
};
