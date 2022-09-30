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

    int am = 0;
    int amount = 100; // Параметры облака
    int i = 0;
    int method; // Метод кластеризации
    int kmeans; // k для k-средних
    bool logging = 0;
    double center_x = 0;
    double center_y = 0;
    double deviation_x = 1;
    double deviation_y = 1;

    input.open("./INPUT.txt"); // Открываем входной файл

    while(true) {
        if (input.eof()) {
            break;
        }
        input >> buff;
        if (buff == "LOG") { // Если надо вести лог (TODO)
            input >> logging;
        } else if (buff == "AMOUNT") { // Принимаем основные параметры генерации
            input >> am;
            amount += am;
        } else if (buff == "BEGIN") {
            std::cout << "Starting clusterization" << std::endl;
            controller.clusterize(field, i, amount, method, kmeans);
            std::cout << "Ended clusterization" << std::endl;
        } else if (buff == "GENERATE") {
            field.generate(amount, center_x, center_y, deviation_x, deviation_y);
            std::cout << "Generated cloud" << std::endl;
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
    input.close();

    controller.clusterize(field, i, amount, method, kmeans); // Запускаем работу с полем

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

}

void Controller::clusterize(Field &field, int process_id, int amount, int method, int opt) {
    // std::cout << "Generated cloud with " << field.points.size() << " points" << std::endl;
    Exec process(process_id, field); // Создаем новый процесс
    switch (method) { // В зависимости от метода кластеризации выполняем её
        default:
            process.k_means(opt);
            break;
    }
    process.save(); // Сохраняем слепок процесса
}

void Field::generate(int amount, double center_x, double center_y, double deviation_x, double deviation_y) {
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<double> x_distribution(center_x, deviation_x);
    std::normal_distribution<double> y_distribution(center_y, deviation_y);

    for (int i = 0; i < amount; i++) { // Создаем amount точек с нормально распределенными координатами
        Point point;
        point.number = points_amount;
        point.x = x_distribution(rd);
        point.y = y_distribution(rd);
        add_point(point);
    }
}

void Field::add_point(Point &point) { // Добавление точки в поле
    points.push_back(point); // Пушим точку в вектор точек поля
    points_amount++;
}

Point* Field::yield_point(int num) { // Вернуть точку по ее номеру
    return &points[num];
}

std::vector<Point>* Field::get_points() {
    // std::cout << points.size() << std::endl;
    return &points; // Возвращаем (копию?) вектора точек
}

void Exec::save() { // Сохранение слепка поля
    std::string filename; 
    std::ofstream out;

    std::vector<Point>* points = id_field.get_points();    
    // std::cout << points.size() << std::endl;
    for (int i = 0; i < rclusters.size(); i++) {
        filename = "OUT_" + std::to_string(id) + "_" + std::to_string(i) + ".txt"; // Открываем файл по id процесса и кластера
        out.open(filename); 
        for (Point point : *points) { 
            int num = point.number;
            if(rclusters[i][num]) {
                out << point.x << " " << point.y << std::endl;
            }
        }
        out.close();
    }
}

void Exec::k_means(int k) {
    Point centers[k];
    Point center;
    Point fcenter;

    double min_dist;
    double cluster_sum_x;
    double cluster_sum_y;
    int attr;
    int cluster_weight;
    bool differ = false;

    int iters = 0;

    std::vector<Point>* points = id_field.get_points();
    std::vector< std::vector<bool> > clusters; 

    for (int j = 0; j < k; j++) {
        std::vector<bool> cluster;
        for (int i = 0; i < size; i++) {
            cluster.push_back(false);
        }
        clusters.push_back(cluster);
    }

    for (int i = 0; i < k; i++) {
        centers[i] = *(id_field.yield_point(i));
    }

    while (true) {
        differ = false;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < size; j++) {
                clusters[i][j] = false;
            }
        }

        for (Point point : *points) {
            min_dist = MAXDST;
            for (int clust = 0; clust < k; clust++) {
                if (id_field.distance(point, centers[clust]) < min_dist) {
                    min_dist = id_field.distance(point, centers[clust]);
                    attr = clust;
                }
            }
            clusters[attr][point.number] = true;
        }

        int clust = 0;
        for (std::vector<bool> cluster : clusters) {
            cluster_weight = 0;
            cluster_sum_x = 0;
            cluster_sum_y = 0;
            for (int i = 0; i < id_field.get_amount(); i++) {
                if (cluster[i]) {
                    Point point = *(id_field.yield_point(i));
                    cluster_sum_x += point.x;
                    cluster_sum_y += point.y;
                    cluster_weight++;
                }
            }
            center = centers[clust];
            center.x = cluster_sum_x/cluster_weight;
            center.y = cluster_sum_y/cluster_weight; 
            if (id_field.distance(centers[clust], center) > EPS) {
                differ = true;
            }
            centers[clust] = center;
            clust++;
        }

        if (!differ || iters > 10000) break;
        iters++;
    }
    rclusters = clusters;
}

int Field::get_amount() {
    return points_amount;
}

double Field::distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}