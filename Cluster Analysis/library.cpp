/*
(c) 2022 Петров Михаил Вадимович группа 212
*/

#include "headers.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <cmath>

void Interface::start() {   
    Controller controller; // Создаем контроллер и поле
    Field field;

    std::ifstream input; // Входной файл с конфигурацией

    std::string buff; // Буффер для распознавания команды конфигурации

    int amount = 100; // Параметры облака
    int i = 0;
    bool logging = 0;
    double center_x = 0;
    double center_y = 0;
    double deviation_x = 1;
    double deviation_y = 1;

    std::cout << "Started" << std::endl;

    input.open("./INPUT.txt"); // Открываем входной файл

    while(true) {
        if (input.eof()) {
            break;
        }
        input >> buff;
        if (buff == "LOG") { // Если надо вести лог (TODO)
            input >> logging;
        } else if (buff == "AMOUNT") { // Принимаем основные параметры генерации
            input >> amount;
        } else if (buff == "DEVX") {
            input >> deviation_x;
        } else if (buff == "DEVY") {
            input >> deviation_y;
        } else if (buff == "CENTX") {
            input >> center_x;
        } else if (buff == "CENTY") {
            input >> center_y;
        } else {
            std::cout << "Wrong parameter " << buff << std::endl;
        }
        
    }
    std::cout << "Got parameters" << std::endl;
    input.close();

    controller.process(field, i, amount, center_x, center_x, deviation_x, deviation_y); // Запускаем работу с полем

     /*
    std::cout << "Hello! Enter center of cloud by X: "; // Спрашиваем параметры генерации облака
    std::cin >> center_x;
    std::cout << "Enter center of cloud by Y: ";
    std::cin >> center_y;
    std::cout << "Enter X deviation: ";
    std::cin >> deviation_x;
    std::cout << "Enter Y deviation ";
    std::cin >> deviation_y;

    std::cout << "Enter amount of points to generate: "; // Спрашиваем количество точек
    std::cin >> amount;
    */

   std::cout << "Processing finished" << std::endl;

}

void Controller::process(Field &field, int process_id, int amount, double center_x, double center_y, double deviation_x, double deviation_y) {
    field.generate(amount, center_x, center_y, deviation_x, deviation_y); // Генерируем облако на amount элементов с соответствующими параметрами
    std::cout << "Generated cloud with " << field.points.size() << " points" << std::endl;
    Exec process(process_id, field); // Создаем новый процесс
    process.save(); // Сохраняем слепок процесса
}

void Field::generate(int amount, double center_x, double center_y, double deviation_x, double deviation_y) {
    std::default_random_engine generator; // Настраиваем нормальное распределение
    std::normal_distribution<double> x_distribution(center_x, deviation_x);
    std::normal_distribution<double> y_distribution(center_y, deviation_y);

    for (int i = 0; i < amount; i++) { // Создаем amount точек с нормально распределенными координатами
        Point point;
        point.number = i;
        point.x = x_distribution(generator);
        point.y = y_distribution(generator);
        add_point(point);
    }
}

void Field::add_point(Point &point) { // Добавление точки в поле
    points.push_back(point); // Пушим точку в вектор точек поля
}

std::vector<Point> Field::get_points() {
    // std::cout << points.size() << std::endl;
    return points; // Возвращаем (копию?) вектора точек
}

void Exec::save() {
    std::string filename = "OUT_" + std::to_string(id) + ".txt"; // Открываем файл по id процесса
    std::ofstream out;
    out.open(filename);

    std::cout << "Saving points" << std::endl;

    std::vector<Point> points = id_field.get_points(); // Получаем точки поля
    std::cout << points.size() << std::endl;
    for (Point &point : points) { // И записываем их координаты в файл
        out << point.x << point.y << std::endl;
    }
    out.close();
}
