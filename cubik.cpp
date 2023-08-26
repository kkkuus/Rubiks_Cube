#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

enum color
{
    red,
    orange,
    yellow,
    green,
    blue,
    white,
    black
};

class Rubik_Cube
{
private:
    std::vector<std::vector<color>> front;
    std::vector<std::vector<color>> back;
    std::vector<std::vector<color>> left;
    std::vector<std::vector<color>> right;
    std::vector<std::vector<color>> down;
    std::vector<std::vector<color>> up;
public:
    Rubik_Cube() :
    front(std::vector<std::vector<color>>(3, std::vector<color>(3, red))),
    left(std::vector<std::vector<color>>(3, std::vector<color>(3, green))),
    back(std::vector<std::vector<color>>(3, std::vector<color>(3, orange))),
    right(std::vector<std::vector<color>>(3, std::vector<color>(3, blue))),
    down(std::vector<std::vector<color>>(3, std::vector<color>(3, yellow))),
    up(std::vector<std::vector<color>>(3, std::vector<color>(3, white)))
    {}
    ~Rubik_Cube()
    {}

    static void rotate_to_right(std::vector<std::vector<color>>& data)
    {
        std::vector<std::vector<color>> temp(3, std::vector<color>(3, black));
        temp = data;
        temp[0][0] = data[2][0];
        temp[0][1] = data[1][0];
        temp[0][2] = data[0][0];
        temp[1][0] = data[2][1];
        temp[1][1] = data[1][1];
        temp[1][2] = data[0][1];
        temp[2][0] = data[2][2];
        temp[2][1] = data[1][2];
        temp[2][2] = data[0][2];
        data = temp;
    }
    static void rotate_to_left(std::vector<std::vector<color>>& data)
    {
        std::vector<std::vector<color>> temp(3, std::vector<color>(3, black));
        temp = data;
        temp[0][0] = data[0][2];
        temp[0][1] = data[1][2];
        temp[0][2] = data[2][2];
        temp[1][0] = data[0][1];
        temp[1][1] = data[1][1];
        temp[1][2] = data[2][1];
        temp[2][0] = data[0][0];
        temp[2][1] = data[1][0];
        temp[2][2] = data[2][0];
        data = temp;
    }

    //----------Инициализация сторон------------//
    static void init_side(std::vector<std::vector<color>>& data, std::vector<std::vector<char>>& temp)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                switch (temp[i][j])
                {
                case 'w':
                    data[i][j] = white;
                    break;
                case 'y':
                    data[i][j] = yellow;
                    break;
                case 'g':
                    data[i][j] = green;
                    break;
                case 'b':
                    data[i][j] = blue;
                    break;
                case 'o':
                    data[i][j] = orange;
                    break;
                case 'r':
                    data[i][j] = red;
                    break;
                }
            }
        }
    }

    void init_front(const std::vector<std::vector<color>>& side)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
                front[i][j] = side[i][j];
        }
    }
    void init_back(const std::vector<std::vector<color>>& side)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
                back[i][j] = side[i][j];
        }
    }
    void init_left(const std::vector<std::vector<color>>& side)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
                left[i][j] = side[i][j];
        }
    }
    void init_right(const std::vector<std::vector<color>>& side)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
                right[i][j] = side[i][j];
        }
    }
    void init_up(const std::vector<std::vector<color>>& side)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
                up[i][j] = side[i][j];
        }
    }
    void init_down(const std::vector<std::vector<color>>& side)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
                down[i][j] = side[i][j];
        }
    }
    //-----------Повороты--------------//
    void R()
    {
        std::vector<color> temp1(3, black), temp2(black);
        for (int i = 0; i < 3; ++i)
            temp1[i] = up[i][2];
        for (int i = 0; i < 3; ++i)
            up[i][2] = front[i][2];
        for (int i = 0; i < 3; ++i)
            temp2[2 - i] = back[i][0];
        for (int i = 0; i < 3; ++i)
            back[2 - i][0] = temp1[i];
        for (int i = 0; i < 3; ++i)
            temp1[i] = down[i][2];
        for (int i = 0; i < 3; ++i)
            down[i][2] = temp2[i];
        for (int i = 0; i < 3; ++i)
            front[i][2] = temp1[i];
        rotate_to_right(right);
    }

    void R_()
    {
        std::vector<color> temp1(3, black), temp2(3, black);
        for (int i = 0; i < 3; ++i)
            temp1[i] = down[i][2];
        for (int i = 0; i < 3; ++i)
            down[i][2] = front[i][2];
        for (int i = 0; i < 3; ++i)
            temp2[2 - i] = back[i][0];
        for (int i = 0; i < 3; ++i)
            back[2 - i][0] = temp1[i];
        for (int i = 0; i < 3; ++i)
            temp1[i] = up[i][2];
        for (int i = 0; i < 3; ++i)
            up[i][2] = temp2[i];
        for (int i = 0; i < 3; ++i)
            front[i][2] = temp1[i];
        rotate_to_left(right);
    }

    void U()
    {
        swap(left[0], front[0]);
        swap(front[0], back[0]);
        swap(front[0], right[0]);
        rotate_to_right(up);
    }

    void U_()
    {
        swap(right[0], front[0]);
        swap(front[0], back[0]);
        swap(front[0], left[0]);
        rotate_to_left(up);
    }

    void F()
    {
        std::vector<color> temp1(3, black), temp2(3, black);
        for (int i = 0; i < 3; ++i)
            temp1[i] = right[2 - i][0];
        for (int i = 0; i < 3; ++i)
            right[i][0] = up[2][i];
        temp2 = down[0];
        down[0] = temp1;
        for (int i = 0; i < 3; ++i)
            temp1[i] = left[2 - i][2];
        for (int i = 0; i < 3; ++i)
            left[i][2] = temp2[i];
        up[2] = temp1;
        rotate_to_right(front);
    }

    void F_()
    {
        std::vector<color> temp1(3, black), temp2(3, black);
        for (int i = 0; i < 3; ++i)
            temp1[i] = left[i][2];
        for (int i = 0; i < 3; ++i)
            left[i][2] = up[2][2 - i];
        temp2 = down[0];
        down[0] = temp1;
        for (int i = 0; i < 3; ++i)
            temp1[i] = right[i][0];
        for (int i = 0; i < 3; ++i)
            right[i][0] = temp2[2 - i];
        up[2] = temp1;
        rotate_to_left(front);
    }

    void L()
    {
        std::vector<color> temp1(3, black), temp2(3, black);
        for (int i = 0; i < 3; ++i)
            temp1[i] = down[i][0];
        for (int i = 0; i < 3; ++i)
            down[i][0] = front[i][0];
        for (int i = 0; i < 3; ++i)
            temp2[2 - i] = back[i][2];
        for (int i = 0; i < 3; ++i)
            back[2 - i][2] = temp1[i];
        for (int i = 0; i < 3; ++i)
            temp1[i] = up[i][0];
        for (int i = 0; i < 3; ++i)
            up[i][0] = temp2[i];
        for (int i = 0; i < 3; ++i)
            front[i][0] = temp1[i];
        rotate_to_right(left);
    }

    void L_()
    {
        std::vector<color> temp1(3, black), temp2(black);
        for (int i = 0; i < 3; ++i)
            temp1[i] = up[i][0];
        for (int i = 0; i < 3; ++i)
            up[i][0] = front[i][0];
        for (int i = 0; i < 3; ++i)
            temp2[2 - i] = back[i][2];
        for (int i = 0; i < 3; ++i)
            back[2 - i][2] = temp1[i];
        for (int i = 0; i < 3; ++i)
            temp1[i] = down[i][0];
        for (int i = 0; i < 3; ++i)
            down[i][0] = temp2[i];
        for (int i = 0; i < 3; ++i)
            front[i][0] = temp1[i];
        rotate_to_left(left);
    }


    void D()
    {
        swap(right[2], front[2]);
        swap(front[2], back[2]);
        swap(front[2], left[2]);
        rotate_to_right(down);
    }

    void D_()
    {
        swap(left[2], front[2]);
        swap(front[2], back[2]);
        swap(front[2], right[2]);
        rotate_to_right(down);
    }

    void B()
    {
        std::vector<color> temp1(3, black), temp2(3, black);
        for (int i = 0; i < 3; ++i)
            temp1[i] = left[i][0];
        for (int i = 0; i < 3; ++i)
            left[i][0] = up[0][2 - i];
        temp2 = down[2];
        down[2] = temp1;
        for (int i = 0; i < 3; ++i)
            temp1[i] = right[i][2];
        for (int i = 0; i < 3; ++i)
            right[i][2] = temp2[2 - i];
        up[0] = temp1;
        rotate_to_left(back);
    }

    void B_()
    {
        std::vector<color> temp1(3, black), temp2(3, black);
        for (int i = 0; i < 3; ++i)
            temp1[i] = right[2 - i][2];
        for (int i = 0; i < 3; ++i)
            right[i][2] = up[0][i];
        temp2 = down[2];
        down[2] = temp1;
        for (int i = 0; i < 3; ++i)
            temp1[i] = left[2 - i][0];
        for (int i = 0; i < 3; ++i)
            left[i][0] = temp2[i];
        up[0] = temp1;
        rotate_to_right(back);
    }

    //---------Повороты куба--------//
    void y_() //поворот кубика вправо в горизонтальной плоскости
    {
        swap(left, front);
        swap(left, right);
        swap(left, back);
        rotate_to_left(up);
        rotate_to_right(down);
    }

    void y()
    {
        std::vector<std::vector<color>> temp1, temp2;
        swap(right, front);
        swap(right, left);
        swap(right, back);
        rotate_to_right(up);
        rotate_to_left(down);
    }

    void x_()  //поворот куба вниз
    {
        std::vector<std::vector<color>> temp1, temp2;
        temp1 = down;
        down = front;
        temp2 = back;
        back = temp1;
        rotate_to_left(back);
        rotate_to_left(back);
        temp1 = up;
        up = temp2;
        rotate_to_right(up);
        rotate_to_right(up);
        front = temp1;
        rotate_to_right(left);
        rotate_to_left(right);
    }

    void x() //поворот куба вверх
    {
        std::vector<std::vector<color>> temp1, temp2;
        temp1 = up;
        up = front;
        temp2 = back;
        back = temp1;
        rotate_to_left(back);
        rotate_to_left(back);
        temp1 = down;
        down = temp2;
        rotate_to_right(down);
        rotate_to_right(down);
        front = temp1;
        rotate_to_right(right);
        rotate_to_left(left);
    }

    std::vector<std::vector<color>>& get_up()
    {
        return up;
    }
    std::vector<std::vector<color>>& get_down()
    {
        return down;
    }
    std::vector<std::vector<color>>& get_front()
    {
        return front;
    }
    std::vector<std::vector<color>>& get_left()
    {
        return left;
    }
    std::vector<std::vector<color>>& get_back()
    {
        return back;
    }
    std::vector<std::vector<color>>& get_right()
    {
        return right;
    }

    void set_color(char& temp)
    {
        switch (temp)
        {
        case 'r':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            std::cout << 'r';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        case 'y':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << 'y';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        case 'o':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            std::cout << 'o';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        case 'g':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            std::cout << 'g';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        case 'b':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            std::cout << 'b';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        case 'w':
            std::cout << 'w';
            break;
        }
    }

    void print()
    {
        std::vector<char> colors = {'r', 'o', 'y', 'g', 'b', 'w'};
        std::cout << "        ---------\n";
        for (int i = 0; i < 3; ++i)
        {
            std::cout << "        | ";
            for (int j = 0; j < 3; ++j)
            {
                set_color(colors[up[i][j]]);
                std::cout << ' ';
            }
            std::cout << "|\n";
        }
        std::cout << "---------------------------------\n";
        for (int i = 0; i < 3; ++i)
        {
            std::cout << "| ";
            for (int j = 0; j < 3; ++j)
            {
                set_color(colors[left[i][j]]);
                std::cout << ' ';
            }
            std::cout << "| ";
            for (int j = 0; j < 3; ++j)
            {
                set_color(colors[front[i][j]]);
                std::cout << ' ';
            }
            std::cout << "| ";
            for (int j = 0; j < 3; ++j)
            {
                set_color(colors[right[i][j]]);
                std::cout << ' ';
            }
            std::cout << "| ";
            for (int j = 0; j < 3; ++j)
            {
                set_color(colors[back[i][j]]);
                std::cout << ' ';
            }
            std::cout << "| ";
            std::cout << std::endl;
        }
        std::cout << "---------------------------------\n";
        for (int i = 0; i < 3; ++i)
        {
            std::cout << "        | ";
            for (int j = 0; j < 3; ++j)
            {
                set_color(colors[down[i][j]]);
                std::cout << ' ';
            }
            std::cout << "|\n";
        }
        std::cout << "        ---------\n";
    }
    void rand_cube()
    {
        std::vector<std::vector<color>> temp_arr(3, std::vector<color> (3));
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp_arr[i][j] = red;
        init_front(temp_arr);

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp_arr[i][j] = orange;
        init_back(temp_arr);

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp_arr[i][j] = blue;
        init_right(temp_arr);

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp_arr[i][j] = green;
        init_left(temp_arr);

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp_arr[i][j] = white;
        init_up(temp_arr);

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp_arr[i][j] = yellow;
        init_down(temp_arr);
        int count_rotates = 1 + rand()%(20);
        int rotate;
        for (int i = 0; i < count_rotates; ++i)
        {
            rotate = 1 + rand()%(10);
            switch (rotate)
            {
            case 1:
                F();
                //std::cout << "F" << ' ';
                break;
            case 2:
                F_();
                //std::cout << "F_" << ' ';
                break;
            case 3:
                R();
                //std::cout << "R" << ' ';
                break;
            case 4:
                R_();
                //std::cout << "R_" << ' ';
                break;
            case 5:
                L();
                //std::cout << "L" << ' ';
                break;
            case 6:
                L_();
                //std::cout << "L_" << ' ';
                break;
            case 7:
                U();
                //std::cout << "U" << ' ';
                break;
            case 8:
                U_();
                //std::cout << "U_" << ' ';
                break;
            case 9:
                D();
                //std::cout << "D" << ' ';
                break;
            case 10:
                D_();
                //std::cout << "D_" << ' ';
                break;
            }
        }
    }
};

