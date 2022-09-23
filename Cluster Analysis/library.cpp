/*
(c) 2022 Петров Михаил Вадимович группа 212
*/

#include "headers.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <cmath>
#include <iterator>
#include <algorithm>

#define MAXDST 100
#define EPS 1e-5

void Interface::start() {   
    Controller controller; // Создаем контроллер и поле
    Field field;

    std::ifstream input; // Входной файл с конфигурацией

    std::string buff; // Буффер для распознавания команды конфигурации

    int amount = 100; // Параметры облака
    int i = 0;
    int method; // Метод кластеризации
    int kmeans; // k для k-средних
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
        } else if (buff == "MODE") {
            input >> buff;
            if (buff == "KMEANS") {
                method = 1;
                input >> kmeans;
            } else {
                std::cout << "Wrong mode " << method << std::endl;
            }
        } else {
            std::cout << "Wrong parameter " << buff << std::endl;
        }
        
    }
    std::cout << "Got parameters"  << std::endl;
    input.close();

    controller.process(field, i, amount, center_x, center_x, deviation_x, deviation_y, method, kmeans); // Запускаем работу с полем

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

void Controller::process(Field &field, int process_id, int amount, double center_x, double center_y, double deviation_x, double deviation_y, int method, int opt) {
    field.generate(amount, center_x, center_y, deviation_x, deviation_y); // Генерируем облако на amount элементов с соответствующими параметрами
    // std::cout << "Generated cloud with " << field.points.size() << " points" << std::endl;
    Exec process(process_id, field); // Создаем новый процесс
    switch (method) { // В зависимости от метода кластеризации выполняем её
        default:
            std::cout << "Clusterization started" << std::endl;
            process.k_means(opt);
            break;
    }
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
    points_amount++;
}

Point Field::yield_point(int num) { // Вернуть точку по ее номеру
    return points[num];
}

std::vector<Point> Field::get_points() {
    // std::cout << points.size() << std::endl;
    return points; // Возвращаем (копию?) вектора точек
}

void Exec::save() { // Сохранение слепка поля
    std::string filename; 
    std::ofstream out;

    std::cout << "Saving points" << std::endl;
    // std::cout << points.size() << std::endl;
    for (int i = 0; i < clusters.size(); i++) {
        filename = "OUT_" + std::to_string(id) + "_" + std::to_string(i) + ".txt"; // Открываем файл по id процесса и кластера
        out.open(filename);
        out << "bruh" << std::endl;
        for (Point point : clusters[i]) {
            out << point.x << " " << point.y << std::endl;
        }
        out.close();
    }
}

void Exec::k_means(int k) {
    srand(time(0));
    std::vector<Point> centers; // Будущие центры
    std::vector<Point> points = id_field.get_points();
    std::vector<int> numbers; // Уже включенные точки
    bool new_point = true; // Чтобы центры не повторялись
    bool changed = false; // Для остановки
    int number;
    int cluster_number;
    int cluster_weight;
    double cluster_sum_x;
    double cluster_sum_y;
    double cluster_mean_x;
    double cluster_mean_y;
    double dst;
    double min_distance;
    Point center;

    while (centers.size() < k) { // Генерируем изначальные k центров
        new_point = true;
        number = rand() % k;
        for (int num : numbers) {
            if (num == number) {
                new_point = false;
                break;
            }
        }
        if (new_point) {
            numbers.push_back(number);
            centers.push_back(id_field.yield_point(number));
        }
    }
    std::cout << "Centers generated" << std::endl;

    while (true) {
        changed = false;
        for (int i = 0; i < k; i++) { // Очищаем кластеры, оставляя только центры
            // ! clusters[i].clear(); - ошибка сегментации здесь
            clusters[i].push_back(centers[i]);
        }

        for (Point point : points) { // Определяем принадлежность точек кластерам
            min_distance = MAXDST;
            for (int i = 0; i < k; i++) {
                center = centers[i];
                dst = id_field.distance(point, center); // Замеряем расстояние до центров
                if (dst < min_distance) {
                    min_distance = dst;
                    cluster_number = i;
                }
            }
            clusters[cluster_number].push_back(point);
        }
        // std::cout << "Divided points" << std::endl;
        // Пересчет центров
        for (int i = 0; i < k; i++) {
            std::vector<Point> cluster = clusters[i]; 
            cluster_weight = 0;
            cluster_sum_x = 0;
            cluster_sum_y = 0;
            for (Point point : cluster) { // Считаем центр тяжести кластера
                cluster_sum_x += point.x;
                cluster_sum_y += point.y;
                cluster_weight++;
            }
            std::cout << "Cluster reforged" << std::endl;
            cluster_mean_x = cluster_sum_x/cluster_weight;
            cluster_mean_y = cluster_sum_y/cluster_weight;
            center.x = cluster_mean_x; 
            center.y = cluster_mean_y;

            // Если центр отличается от прошлого
            if (centers[i].x - cluster_mean_x > EPS || centers[i].y - cluster_mean_y > EPS) {
                changed = true; // Запоминаем это и меняем центр 
                centers[i] = center;
            }
        }
        // std::cout << "Iteration complete" << std::endl;
        // Пока кластеры не стабилизируются
        if (!changed) {
            break;
        }
    }
    std::cout << "Clusterization complete" << std::endl;
}

int Field::get_amount() {
    return points_amount;
}

double Field::distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}