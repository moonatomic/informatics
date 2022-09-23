/*
(c) 2022 Петров Михаил Вадимович группа 212
*/

#include <iostream>
#include <vector>
#include <fstream>

class Point
{
private:

public:
    Point() {};
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
    double x;
    double y;
    int number;
    int color;
};

class Field
{
private:
    double center_x; // Центр облака
    double center_y;
    int points_amount; // Количество точек в облаке

    void add_point(Point &point);
    std::vector<Point> points;
public:
    Field() {};
    // Field(const Field &field) {}; Конструктор копирования поля field
    std::vector<Point> get_points(); // Функция получения точек из поля
    int get_amount(); // Возвращает количество точек
    Point yield_point(int number); // Возвращает точку по номеру
    double distance(Point a, Point b);
    void generate(int amount, double center_x, double center_y, double deviation_x, double deviation_y); 
    // Функция генерации облака точек: принимает количество точек, матожидание и стандартное отклонение (по Гауссу)
};

class Interface
{
public:
    Interface() {};
    void start(); // Фактическое начало исполнения программы
};

class Controller
{
public:
    Controller() {};
    void process(Field &field, int process_id, int amount, double center_x, double center_y, double deviation_x, double deviation_y, int method, int opt); 
    // Функция генерации облака точек: принимает количество точек, матожидание и стандартное отклонение (по Гауссу), 
    // метод кластеризации и дополнительную информацию (k для k-средних)
};

class Exec
{
private:
    int id;
    Field id_field;
    std::vector< std::vector<Point> > clusters; // Набор кластеров как результат работы
public:
    Exec(int process_id, Field field) { // Конструктор - принимает id процесса и ссылку на поле
        id = process_id;
        id_field = field;
    };
    void k_means(int k);
    void save();
};