/*
(c) 2022 Петров Михаил Вадимович группа 212
*/

#include "headers.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <cmath>
#include <ctime>
#include <iterator>
#include <algorithm>

#define MAXDST 100
#define EPS 1e-5
#define NEIGHBORS 5

void Interface::start() {   
    Controller controller;
    Field field;

    std::ifstream input;
    std::ofstream log;

    std::time_t timing = 0;

    std::string buff;

    int amount = 100;
    int i = 0;
    int method;
    double opt;
    int id;
    int cloud_number;
    bool logging = false;
    bool started = false;
    double center_x = 0;
    double center_y = 0;
    double deviation_x = 1;
    double deviation_y = 1;

    int transform_type;
    double transform_center_x;
    double transform_center_y;
    double transform_phi;
    double transform_lambda;
    double transform_vector_x;
    double transform_vector_y;

    input.open("./INPUT.txt");

    while(true) {
        if (input.eof()) {
            break;
        }
        input >> buff;
        if (buff == "LOG") {
            input >> logging;
            if (logging) {
                log.open("LOG.txt");
                time(&timing);
                log << "Started " << std::asctime(std::localtime(&timing)) << std::endl;
            }
        } else if (buff == "AMOUNT") {
                input >> amount;
        } else if (buff == "BEGIN") {
            started = true;
            if (logging) {
                time(&timing);
                log << "Starting clusterization " << std::asctime(std::localtime(&timing)) << std::endl;
            }
            controller.clusterize(field, i, method, opt);
            if (logging) {
                time(&timing);
                log << "Ended clusterization " << std::asctime(std::localtime(&timing)) << std::endl;
            }
        } else if (buff == "GENERATE") {
            if (!started) {
                controller.generate(field, amount, center_x, center_y, deviation_x, deviation_y);
                if (logging) {
                    time(&timing);
                    log << "Generated cloud " << std::asctime(std::localtime(&timing)) << std::endl;
                }
            } else {
            if (logging) {
                    time(&timing);
                    log << "Prevented post-processing generation " << std::asctime(std::localtime(&timing)) << std::endl;
                }
            }
        } else if (buff == "SAVE") {
            input >> id;
            controller.save(id);
            if (logging) {
                time(&timing);
                log << "Saved process with id " << id << " " << std::asctime(std::localtime(&timing)) << std::endl;
            }
        } else if (buff == "TRANSFORM") {
            input >> cloud_number;
            input >> buff;
            if (buff == "ROTATE") {
                transform_type = 0;
                input >> transform_center_x;
                input >> transform_center_y;
                input >> transform_phi;
                controller.transform(field, cloud_number, transform_type, transform_center_x, transform_center_y, transform_phi, 0);
                if (logging) {
                    time(&timing);
                    log << "Rotated cloud " << cloud_number << " " << std::asctime(std::localtime(&timing)) << std::endl;
                }
            } else if (buff == "TRANSLATE") {
                transform_type = 1;
                input >> transform_vector_x;
                input >> transform_vector_y;
                controller.transform(field, cloud_number, transform_type, transform_vector_x, transform_vector_y, 0, 0);
                if (logging) {
                    time(&timing);
                    log << "Translated cloud " << cloud_number << " " << std::asctime(std::localtime(&timing)) << std::endl;
                }
            } else if (buff == "SCALE") {
                transform_type = 2;
                input >> transform_center_x;
                input >> transform_center_y;
                input >> transform_lambda;
                controller.transform(field, cloud_number, transform_type, transform_center_x, transform_center_y, transform_lambda, 0);
                if (logging) {
                    time(&timing);
                    log << "Scaled cloud " << cloud_number << " " << std::asctime(std::localtime(&timing)) << std::endl;
                }
            }
        } else if (buff == "DEVX") {
            input >> deviation_x;
        } else if (buff == "DEVY") {
            input >> deviation_y;
        } else if (buff == "CENTX") {
            input >> center_x;
        } else if (buff == "CENTY") {
            input >> center_y;
        } else if (buff == "END") {
            break;
        } else if (buff == "MODE") {
            input >> buff;
            if (buff == "KMEANS") {
                method = 1;
                input >> opt;
            } else if (buff == "WAVE") {
                method = 2;
                input >> opt;
            } else if (buff == "DBSCAN") {
                method = 3;
                input >> opt;
            } else {
                if (logging) {
                    time(&timing);
                    log << "Wrong mode " << method << " " << std::asctime(std::localtime(&timing)) << std::endl;
                }
            }
        } else {
            if (logging) {
                time(&timing);
                log << "Wrong parameter " << buff << " " << std::asctime(std::localtime(&timing)) << std::endl;
            }
        }
        
    }
    input.close();
    log.close();
}

void Controller::clusterize(Field &field, int process_id, int method, double opt) {
    Exec process(process_id, field);
    switch (method) {
        case 1:
            process.k_means(int(opt));
            break;
        case 2:
            process.wave(opt);
            break;
        case 3:
            process.DBSCAN(opt, NEIGHBORS);
            break;
    }
    processes.push_back(process);
}

void Controller::generate(Field &field, int amount, double center_x, double center_y, double deviation_x, double deviation_y) {
    field.generate(amount, center_x, center_y, deviation_x, deviation_y);
}

void Field::generate(int amount, double center_x, double center_y, double deviation_x, double deviation_y) {
    Cloud * cloud = new Cloud(clouds_amount);

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<double> x_distribution(center_x, deviation_x);
    std::normal_distribution<double> y_distribution(center_y, deviation_y);

    for (int i = 0; i < amount; i++) {
        Point * point = new Point;
        (*point).number = points_amount;
        (*point).x = x_distribution(rd);
        (*point).y = y_distribution(rd);
        add_point(point);
        (*cloud).add_point(point);
        (*cloud).size++;
    }
    clouds.push_back(cloud);
    clouds_amount++;
}

void Field::transform(int cloud_number, int transform_type, double parameter1, double parameter2, double parameter3, double parameter4) {
    Buffer * buffer = new Buffer();
    (*buffer).copy_cloud(clouds[cloud_number]);
    if (transform_type == 0) {
        Point center(parameter1, parameter2);
        (*buffer).rotate(center, parameter3);
    } else if (transform_type == 1) {
        std::vector<double> vec;
        vec.push_back(parameter1);
        vec.push_back(parameter2);
        (*buffer).translate(vec);
    } else if (transform_type == 2) {
        Point center(parameter1, parameter2);
        (*buffer).scale(center, parameter3);
    }
}

int Field::get_amount() {
    return points_amount;
}

double Field::distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void Field::add_point(Point * point) {
    points.push_back(point);
    points_amount++;
}

Point* Field::yield_point(int num) {
    return points[num];
}

std::vector<Point *> Field::get_points() {
    return points;
}

void Cloud::add_point(Point * point) {
    points.push_back(point);
}

void Controller::save(int process_id) {
    processes[process_id].save();
}

void Controller::transform(Field &field, int cloud_number, int transform_type, double parameter1, double parameter2, double parameter3, double parameter4) {
    field.transform(cloud_number, transform_type, parameter1, parameter2, parameter3, parameter4);
}

void Exec::save() {
    std::string filename; 
    std::ofstream out;

    std::vector<Point *> points = id_field.get_points();    
    for (long unsigned int i = 0; i < rclusters.size(); i++) {
        filename = "OUT_" + std::to_string(id) + "_" + std::to_string(i) + ".txt";
        out.open(filename); 
        for (Point * point : points) { 
            int num = (*point).number;
            if(rclusters[i][num]) {
                out << (*point).x << " " << (*point).y << std::endl;
            }
        }
        out.close();
    }
}

void Exec::k_means(int k) {
    std::vector<Point> centers;
    Point center;
    Point fcenter;

    double min_dist;
    double cluster_sum_x;
    double cluster_sum_y;
    int attr;
    int cluster_weight;
    bool differ = false;

    int iters = 0;
    centers.resize(k);

    std::vector<Point *> points = id_field.get_points();
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

        for (Point * point : points) {
            min_dist = MAXDST;
            for (int clust = 0; clust < k; clust++) {
                if (id_field.distance(*point, centers[clust]) < min_dist) {
                    min_dist = id_field.distance(*point, centers[clust]);
                    attr = clust;
                }
            }
            clusters[attr][(*point).number] = true;
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

void Exec::wave(double delta) {
    std::vector<Point *> points = id_field.get_points();
    std::vector<double> matrix;
    std::vector<int> burnt;
    std::vector<bool> cluster;

    std::string filename; 
    std::ofstream out;

    bool flag = false;
    int clust;
    int steps = 0;
    int cluster_amount = 0;
    int pamount = id_field.get_amount();

    for (int i = 0; i < pamount; i++) {
        burnt.push_back(0);
    }

    matrix.resize(pamount * pamount);
    for (int i = 0; i < pamount; i++) {
		for (int j = 0; j < pamount; j++) {
			matrix[i * pamount + j] = id_field.distance(*(points[i]), *(points[j]));
		}
	}
    
    while(true) {
        flag = true;
        for (int i = 0; i < pamount; i++) {
			if (burnt[i] == 0) {
				burnt[i] = 1;
				flag = 0;
				break;
			}
		}
        if (flag) {
            break;
        }

        clust = 0;
		flag = true;
		while (flag) {	
			clust++;
            steps++;
			flag = 0;
			for (int i = 0; i < pamount; i++) {	
				if (burnt[i] == clust) {
					for (int j = 0; j < pamount; j++) {	
						if (matrix[i * pamount + j] < delta) {
							if (burnt[j] == 0) {
								burnt[j] = burnt[i] + 1;
								flag = true;
							}
						}
					}
				}
			}
		}
        cluster_amount++;
		for (int i = 0; i < pamount; i++) {
			if (burnt[i] > 0) {
				burnt[i] = -cluster_amount;
			}
		}
    }

    // Для красивого вывода хода волны
    /*
    for (int i = 0; i < steps; i++) {
        filename = "WAV" + std::to_string(i) + ".txt"; // File for every fired number
        out.open(filename);
        for (int j = 0; j < pamount; j++) {				
            if (burnt[j] == burnt[i]+1) {
                out << (*points)[j].x << " " << (*points)[j].y << std::endl;
            }
        }
        out.close();
	}
    */

    for (int i = 0; i < cluster_amount; i++) {
        cluster.clear();
        for (int k = 0; k < pamount; k++) {
            cluster.push_back(false);
        }
        for (int j = 0; j < pamount; j++) {
            if (burnt[j] == -(i+1)) {
                cluster[j] = true;
            } else {
                cluster[j] = false;
            }
        }
        rclusters.push_back(cluster);
    }

    matrix.clear();
    burnt.clear();
}

void Exec::DBSCAN(double delta, int k) {
    std::vector<Point *> points = id_field.get_points();
    std::vector<double> matrix;
    std::vector<int> neighbors;
    std::vector<int> ncpoint;
    std::vector<int> burnt;
    std::vector<bool> cluster;
    std::vector<int> nncpoints;

    std::string filename; 
    std::ofstream out;

    bool flag = false;
    int clust;
    int steps = 0;
    int cluster_amount = 0;
    int pamount = id_field.get_amount();
    double dist;

    for (int i = 0; i < pamount; i++) {
        burnt.push_back(0);
    }

    matrix.resize(pamount * pamount);
    for (int i = 0; i < pamount; i++) {
        ncpoint.push_back(0);
        neighbors.push_back(0);
    }
    for (int i = 0; i < pamount; i++) {
        nncpoints.clear();
		for (int j = 0; j < pamount; j++) {
            dist = id_field.distance(*(points[i]), *(points[j]));
			matrix[i * pamount + j] = dist;
            if (dist < delta) {
                neighbors[i]++;
                neighbors[j]++;
                nncpoints.push_back(j);
                if (neighbors[i] >= k) {
                    ncpoint[i] = 2;
                    for (int point : nncpoints) {
                        if (ncpoint[point] != 2) {
                            ncpoint[point] = 1;
                        }
                    }
                }
            }
		}
	}
    
    while(true) {
        flag = true;
        for (int i = 0; i < pamount; i++) {
			if ((burnt[i] == 0) && (ncpoint[i] == 2)) {
				burnt[i] = 1;
				flag = 0;
				break;
			}
		}
        if (flag) {
            break;
        }

        clust = 0;
		flag = true;
		while (flag) {	
			clust++;
            steps++;
			flag = false;
			for (int i = 0; i < pamount; i++) {	
				if ((burnt[i] == clust) && (ncpoint[i] == 2)) {
					for (int j = 0; j < pamount; j++) {	
						if (matrix[i * pamount + j] < delta) {
							if (burnt[j] == 0) {
								burnt[j] = burnt[i] + 1;
								flag = true;
							}
						}
					}
				}
			}
		}
        cluster_amount++;
		for (int i = 0; i < pamount; i++) {
			if (burnt[i] > 0) {
				burnt[i] = -cluster_amount;
			}
		}
    }

    for (int i = 0; i < cluster_amount; i++) {
        cluster.clear();
        for (int k = 0; k < pamount; k++) {
            cluster.push_back(false);
        }
        for (int j = 0; j < pamount; j++) {
            if (burnt[j] == -(i+1)) {
                cluster[j] = true;
            } else {
                cluster[j] = false;
            }
        }
        rclusters.push_back(cluster);
    }

    // Для красивого вывода точек DBSCAN
    /*
    std::ofstream out;
    out.open("DB_CORE.txt");
    for (int i = 0; i < pamount; i++) {
        if (ncpoint[i] == 2) {
            out << (*points)[i].x << " " << (*points)[i].y << std::endl;
        }
    }
    out.close();
    out.open("DB_NEIGH.txt");
    for (int i = 0; i < pamount; i++) {
        if (ncpoint[i] == 1) {
            out << (*points)[i].x << " " << (*points)[i].y << std::endl;
        }
    }
    out.close();
    out.open("DB_NOISE.txt");
    for (int i = 0; i < pamount; i++) {
        if (ncpoint[i] == 0) {
            out << (*points)[i].x << " " << (*points)[i].y << std::endl;
        }
    }
    out.close();
    */

    matrix.clear();
    burnt.clear();
}

void Buffer::translate(std::vector<double> vec) {
    std::ofstream out;
    out.open("OUT_0_1.txt");
    for (Point * point : points) {
        (*point).x = (*point).x + vec[0];
        (*point).y = (*point).y + vec[1];
        out << (*point).x << " " << (*point).y<< std::endl;
    }
    out.close();
}

void Buffer::copy_cloud(Cloud * cloud) {
    points.clear();
    for (Point * point : (*cloud).points) {
        points.push_back(point);
        points_amount++;
    }
}

void Buffer::scale(Point center, double lambda) {
    std::vector<double> vec;
    vec.resize(2);
    vec[0] = -center.x;
    vec[1] = -center.y;
    translate(vec);
    for (Point * point : points) {
        (*point).x *= lambda;
        (*point).y *= lambda;
    }
    vec[0] = center.x;
    vec[1] = center.y;
    translate(vec);
}

void Buffer::rotate(Point center, double phi) {
    double _x, _y;
    double x, y;
    std::vector<double> vec;
    vec.resize(2);
    vec[0] = -center.x;
    vec[1] = -center.y;
    translate(vec);
    for (Point * point : points) {
        x = (*point).x;
        y = (*point).y;
        _x = x*cos(phi*M_PI/180) - y*sin(phi*M_PI/180);
        _y = x*sin(phi*M_PI/180) + y*cos(phi*M_PI/180);
        (*point).x = _x;
        (*point).y = _y;
    }
    vec[0] = center.x;
    vec[1] = center.y;
    translate(vec);
}