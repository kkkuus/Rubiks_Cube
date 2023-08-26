#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "algorithm.cpp"

std::ifstream fin("input.txt");

void init_cube(Rubik_Cube& cube)
{
    std::vector<std::vector<color>> temp_arr(3, std::vector<color> (3, black));

    int sides = 0;
    while (sides < 6)
    {
        std::vector<std::vector<char>> temp_side(3, std::vector<char> (3));
        std::string temp;
        fin >> temp;
        switch (temp[0])
        {
        case 'f':
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    fin >> temp_side[i][j];
            Rubik_Cube::init_side(temp_arr, temp_side);
            cube.init_front(temp_arr);
            break;
        case 'b':
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    fin >> temp_side[i][j];
            Rubik_Cube::init_side(temp_arr, temp_side);
            cube.init_back(temp_arr);
            break;
        case 'r':
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    fin >> temp_side[i][j];
            Rubik_Cube::init_side(temp_arr, temp_side);
            cube.init_right(temp_arr);
            break;
        case 'l':
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    fin >> temp_side[i][j];
            Rubik_Cube::init_side(temp_arr, temp_side);
            cube.init_left(temp_arr);
            break;
        case 'u':
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    fin >> temp_side[i][j];
            Rubik_Cube::init_side(temp_arr, temp_side);
            cube.init_up(temp_arr);
            break;
        case 'd':
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    fin >> temp_side[i][j];
            Rubik_Cube::init_side(temp_arr, temp_side);
            cube.init_down(temp_arr);
            break;
        }
        ++sides;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "read - чтение кубика из файла" << std::endl;
    std::cout << "rand - вывод рандомного кубика" << std::endl;
    std::cout << "solve - сборка кубика" << std::endl;
    std::cout << "save - сохранение текущего кубика в файл" << std::endl;
    std::cout << "print - вывод текущего кубика в консоль " << std::endl;
    std::cout << "Для совершения поворота, введите нужный вам поворот" << std::endl;
    std::cout << "Для завершения работы с кубиком введите end" << std::endl;
    Rubik_Cube cube;
    Rubik_Cube rand_cube;
    std::string command;
    int flag = 0;
    while(flag != -1)
    {
        std::cin >> command;
        if (command == "read")
        {
            init_cube(cube);
            cube.print();
        }
        else if (command == "print")
        {
            cube.print();
        }
        else if (command == "rand")
        {
            rand_cube.rand_cube();
            rand_cube.print();
        }
        else if (command == "solve")
        {
            int counter = 0;
            cube_algorithm::solve_cube(cube, counter);
            cube.print();
        }
        else if (command == "save")
        {
            freopen("output.txt", "w", stdout);
            cube.print();
            fclose(stdout);
        }
        else if (command == "check")
        {
            if (cube_algorithm::check_cube(cube) == true)
                std::cout << "Хороший куб!";
            else
                std::cout << "Не очень хороший куб!";
        }
        else if (command == "solve_rand")
        {
            int counter = 0;
            cube_algorithm::solve_cube(rand_cube, counter);
            rand_cube.print();
        }
        else if (command == "R")
        {
            cube.R();
        }
        else if (command == "R_")
        {
            cube.R_();
        }
        else if (command == "R2")
        {
            cube.R();
            cube.R();
        }
        else if (command == "U")
        {
            cube.U();
        }
        else if (command == "U_")
        {
            cube.U_();
        }
        else if (command == "U2")
        {
            cube.U();
            cube.U();
        }
        else if (command == "F")
        {
            cube.F();
        }
        else if (command == "F_")
        {
            cube.F_();
        }
        else if (command == "F2")
        {
            cube.F();
            cube.F();
        }
        else if (command == "L")
        {
            cube.L();
        }
        else if (command == "L_")
        {
            cube.L_();
        }
        else if (command == "L2")
        {
            cube.L();
            cube.L();
        }
        else if (command == "D")
        {
            cube.D();
        }
        else if (command == "D_")
        {
            cube.D_();
        }
        else if (command == "D2")
        {
            cube.D();
            cube.D();
        }
        else if (command == "B")
        {
            cube.B();
        }
        else if (command == "B_")
        {
            cube.B_();
        }
        else if (command == "B2")
        {
            cube.B();
            cube.B();
        }
        else if (command == "x")
        {
            cube.x();
        }
        else if (command == "x_")
        {
            cube.x_();
        }
        else if (command == "y")
        {
            cube.y();
        }
        else if (command == "y_")
        {
            cube.y_();
        }
        else if (command == "end")
            flag = -1;
    }
    std::cout << "Приходите еще!";
    return 0;
}
