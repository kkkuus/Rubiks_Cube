#include <iostream>
#include <vector>
#include <string>
#include "cubik.cpp"

class cube_algorithm
{
public:
    //----------Блок для собирания белого креста---------//
    static void yellow_to_up(Rubik_Cube& cube)
    {
        if (cube.get_up()[1][1] == yellow)
            return;
        else if (cube.get_down()[1][1] == yellow)
        {
            cube.x();
            cube.x();
            std::cout << " x2";
        }
        else if (cube.get_front()[1][1] == yellow)
        {
            cube.x();
            std::cout << " x";
        }
        else if (cube.get_back()[1][1] == yellow)
        {
            cube.x_();
            std::cout << " x";
        }
        else if (cube.get_right()[1][1] == yellow)
        {
            cube.y();
            cube.x();
            std::cout << " y x";
        }
        else if (cube.get_left()[1][1] == yellow)
        {
            cube.y_();
            cube.x();
            std::cout << " y_ x";
        }
    }

    static void checking_second_layer(Rubik_Cube& cube, int &flag) //поиск белого ребра на среднем уровне
    {
        int i = 0;
        while (i < 4 && flag < 4)
        {
            if (cube.get_front()[1][0] == white)
            {
                while (cube.get_up()[1][0] == white)
                {
                    cube.U();
                    std::cout << " U";
                }
                cube.L_();
                std::cout << " L_";
                ++flag;
                if (flag == 4)
                    return;
            }
            if (cube.get_front()[1][2] == white)
            {
                while (cube.get_up()[1][2] == white)
                {
                    cube.U();
                    std::cout << " U";
                }
                cube.R();
                std::cout << " R";
                ++flag;
                if (flag == 4)
                    return;
            }
            cube.y();
            std::cout << " y";
            ++i;
        }
    }

    static void checking_first_layer(Rubik_Cube& cube, int &flag)  //поиск белого ребра на верхнем уровне
    {
        int i = 0;
        while (i < 4 && flag < 4)
        {
            if (cube.get_front()[0][1] == white)
            {
                cube.F();
                std::cout << " F";
                while (cube.get_up()[1][2] == white)
                {
                    cube.U();
                    std::cout << " U";
                }
                cube.R();
                std::cout << " R";
                ++flag;
                if (flag == 4)
                    return;
            }
            cube.y();
            std::cout << " y";
            ++i;
        }
    }

    static void checking_third_layer(Rubik_Cube& cube, int &flag)   //поиск белого ребра на третьем уровне
    {
        int i = 0;
        while (i < 4 && flag < 4)
        {
            if (cube.get_front()[2][1] == white)
            {
                cube.F();
                std::cout << " F";
                while (cube.get_up()[1][0] == white)
                {
                    cube.U();
                    std::cout << " U";
                }
                cube.L_();
                std::cout << " L_";
                ++flag;
                if (flag == 4)
                    return;
            }
            cube.y();
            std::cout << " y";
            ++i;
        }
    }

    static void checking_down_layer(Rubik_Cube& cube, int &flag)   //поиск белого ребра внизу
    {
        int i = 0;
        while (i < 4 && flag < 4)
        {
            if (cube.get_down()[0][1] == white)
            {
                while (cube.get_up()[2][1] == white)
                {
                    cube.U();
                    std::cout << " U";
                }
                cube.F_();
                cube.F_();
                std::cout << " F_2";
                ++flag;
                if (flag == 4)
                    return;
            }
            cube.y();
            std::cout << " y";
            ++i;
        }
    }

    static void chamomile(Rubik_Cube& cube)
    {
        int flag = 0;
        if (cube.get_up()[0][1] == white)
            ++flag;
        if (cube.get_up()[1][0] == white)
            ++flag;
        if (cube.get_up()[1][2] == white)
            ++flag;
        if (cube.get_up()[2][1] == white)
            ++flag;
        while (flag < 4)
        {
            checking_second_layer(cube, flag);
            checking_first_layer(cube, flag);
            checking_third_layer(cube, flag);
            checking_down_layer(cube, flag);
        }
    }

    static void from_chamomile_to_cross(Rubik_Cube& cube)
    {
        int i = 0;
        while (i < 4)
        {
            while (cube.get_up()[2][1] != white)
            {
                cube.U_();
                std::cout << " U_";
            }
            color temp = cube.get_front()[0][1];
            if (cube.get_front()[1][1] == temp)
            {
                cube.F();
                cube.F();
                std::cout << " F2";
            }
            else if (cube.get_right()[1][1] == temp)
            {
                cube.U_();
                cube.R();
                cube.R();
                std::cout << " U_ R2";
            }
            else if (cube.get_back()[1][1] == temp)
            {
                cube.U_();
                cube.U_();
                cube.B_();
                cube.B_();
                std::cout << " U_2 B_2";
            }
            else if (cube.get_left()[1][1] == temp)
            {
                cube.U();
                cube.L();
                cube.L();
                std::cout << " U L2";
            }
            ++i;
        }
    }

    static void white_cross(Rubik_Cube& cube)
    {
        yellow_to_up(cube);
        chamomile(cube);
        from_chamomile_to_cross(cube);
    }

    //-------Конец блока собирания белого креста--------//

    static void pif_paf(Rubik_Cube& cube)
    {
        cube.R();
        cube.U();
        cube.R_();
        cube.U_();
        std::cout << " R U R_ U_";
    }

    //-------Блок собирания первого слоя---------//

    static bool check_up_to_white(Rubik_Cube& cube)
    {
        if (cube.get_up()[0][0] == white || cube.get_up()[0][2] == white ||
            cube.get_up()[2][0] == white || cube.get_up()[2][2] == white)
            return true;
        else
            return false;
    }
    static void white_looks_up(Rubik_Cube& cube)
    {
        while (cube.get_up()[2][2] != white)
        {
            cube.U_();
            std::cout << " U_";
        }
        color temp1 = cube.get_front()[0][2];
        color temp2 = cube.get_right()[0][0];
        if ((cube.get_front()[1][1] == temp1 || cube.get_front()[1][1] == temp2)
            && (cube.get_right()[1][1] == temp1 || cube.get_right()[1][1] == temp2))
        {
            for (int i = 0; i < 3; ++i)
                pif_paf(cube);
        }
        else if ((cube.get_back()[1][1] == temp1 || cube.get_back()[1][1] == temp2)
                && (cube.get_right()[1][1] == temp1 || cube.get_right()[1][1] == temp2))
        {
            cube.U_();
            cube.y();
            std::cout << " U_ y";
            for (int i = 0; i < 3; ++i)
                pif_paf(cube);
        }
        else if ((cube.get_back()[1][1] == temp1 || cube.get_back()[1][1] == temp2)
                && (cube.get_left()[1][1] == temp1 || cube.get_left()[1][1] == temp2))
        {
            cube.U_();
            cube.U_();
            cube.y();
            cube.y();
            std::cout << " U_2 y2";
            for (int i = 0; i < 3; ++i)
                pif_paf(cube);
        }
        else if ((cube.get_front()[1][1] == temp1 || cube.get_front()[1][1] == temp2)
                && (cube.get_left()[1][1] == temp1 || cube.get_left()[1][1] == temp2))
        {
            cube.U();
            cube.y_();
            std::cout << " U y_";
            for (int i = 0; i < 3; ++i)
                pif_paf(cube);
        }
    }
    static bool check_right_to_white(Rubik_Cube& cube)
    {
        if (cube.get_front()[0][0] == white || cube.get_right()[0][0] == white ||
            cube.get_left()[0][0] == white || cube.get_back()[0][0] == white)
            return true;
        else
            return false;
    }
    static void white_looks_right(Rubik_Cube& cube)
    {
        while (cube.get_right()[0][0] != white)
        {
            cube.U_();
            std::cout << " U_";
        }
        color temp1 = cube.get_front()[0][2];
        color temp2 = cube.get_up()[2][2];
        if ((cube.get_front()[1][1] == temp1 || cube.get_front()[1][1] == temp2)
            && (cube.get_right()[1][1] == temp1 || cube.get_right()[1][1] == temp2))
            pif_paf(cube);
        else if ((cube.get_back()[1][1] == temp1 || cube.get_back()[1][1] == temp2)
                && (cube.get_right()[1][1] == temp1 || cube.get_right()[1][1] == temp2))
        {
            cube.U_();
            cube.y();
            std::cout << " U_ y";
            pif_paf(cube);
        }
        else if ((cube.get_back()[1][1] == temp1 || cube.get_back()[1][1] == temp2)
                && (cube.get_left()[1][1] == temp1 || cube.get_left()[1][1] == temp2))
        {
            cube.U_();
            cube.U_();
            cube.y();
            cube.y();
            std::cout << " U_2 y2";
            pif_paf(cube);
        }
        else if ((cube.get_front()[1][1] == temp1 || cube.get_front()[1][1] == temp2)
                && (cube.get_left()[1][1] == temp1 || cube.get_left()[1][1] == temp2))
        {
            cube.U();
            cube.y_();
            std::cout << " U y_";
            pif_paf(cube);
        }
    }

    static bool check_front_to_white(Rubik_Cube& cube)
    {
        if (cube.get_front()[0][2] == white || cube.get_right()[0][2] == white ||
            cube.get_left()[0][2] == white || cube.get_back()[0][2] == white)
            return true;
        else
            return false;
    }
    static void white_looks_front(Rubik_Cube& cube)
    {
        while (cube.get_front()[0][2] != white)
        {
            cube.U_();
            std::cout << " U_";
        }
        color temp1 = cube.get_right()[0][0];
        color temp2 = cube.get_up()[2][2];
        if ((cube.get_front()[1][1] == temp1 || cube.get_front()[1][1] == temp2)
            && (cube.get_right()[1][1] == temp1 || cube.get_right()[1][1] == temp2))
        {
            for (int i = 0; i < 5; ++i)
                pif_paf(cube);
        }
        else if ((cube.get_back()[1][1] == temp1 || cube.get_back()[1][1] == temp2)
                && (cube.get_right()[1][1] == temp1 || cube.get_right()[1][1] == temp2))
        {
            cube.U_();
            cube.y();
            std::cout << " U_ y";
            for (int i = 0; i < 5; ++i)
                pif_paf(cube);
        }
        else if ((cube.get_back()[1][1] == temp1 || cube.get_back()[1][1] == temp2)
                && (cube.get_left()[1][1] == temp1 || cube.get_left()[1][1] == temp2))
        {
            cube.U_();
            cube.U_();
            cube.y();
            cube.y();
            std::cout << " U_2 y2";
            for (int i = 0; i < 5; ++i)
                pif_paf(cube);
        }
        else if ((cube.get_front()[1][1] == temp1 || cube.get_front()[1][1] == temp2)
                && (cube.get_left()[1][1] == temp1 || cube.get_left()[1][1] == temp2))
        {
            cube.U();
            cube.y_();
            std::cout << " U y_";
            for (int i = 0; i < 5; ++i)
                pif_paf(cube);
        }
    }

    static bool check_white_at_bottom_front(Rubik_Cube& cube)
    {
        if (cube.get_front()[2][2] == white || cube.get_right()[2][2] == white ||
            cube.get_left()[2][2] == white || cube.get_back()[2][2] == white)
            return true;
        else
            return false;
    }
    static bool check_white_at_bottom_right(Rubik_Cube& cube)
    {
        if (cube.get_front()[2][0] == white || cube.get_right()[2][0] == white ||
            cube.get_left()[2][0] == white || cube.get_back()[2][0] == white)
            return true;
        else
            return false;
    }
    static bool check_white_at_bottom_down(Rubik_Cube& cube)
    {
        if (cube.get_down()[0][0] == white && cube.get_front()[2][0] != cube.get_front()[2][1])
            return true;
        else if (cube.get_down()[0][2] == white && cube.get_front()[2][2] != cube.get_front()[2][1])
            return true;
        else if (cube.get_down()[2][0] == white && cube.get_left()[2][0] != cube.get_left()[2][1])
            return true;
        else if (cube.get_down()[2][2] == white && cube.get_right()[2][2] != cube.get_right()[2][1])
            return true;
        else
            return false;
    }

    static void white_looks_front_bottom(Rubik_Cube& cube)
    {
        while (cube.get_front()[2][2] != white)
        {
            cube.D();
            std::cout << " D";
        }
        white_looks_up(cube);
    }

    static void white_looks_right_bottom(Rubik_Cube& cube)
    {
        while (cube.get_right()[2][0] != white)
        {
            cube.D();
            std::cout << " D";
        }
        white_looks_right(cube);
    }

    static void white_looks_down_bottom(Rubik_Cube& cube)
    {
        while (cube.get_down()[0][2] != white)
        {
            cube.D();
            std::cout << " D";
        }
        white_looks_front(cube);
    }
    static void second_step(Rubik_Cube& cube)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (check_front_to_white(cube) == true)
                white_looks_front(cube);
            else if (check_right_to_white(cube) == true)
                white_looks_right(cube);
            else if (check_up_to_white(cube) == true)
                white_looks_up(cube);
            else if (check_white_at_bottom_down(cube) == true)
                white_looks_down_bottom(cube);
            else if (check_white_at_bottom_front(cube) == true)
                white_looks_front_bottom(cube);
            else if (check_white_at_bottom_right(cube) == true)
                white_looks_right_bottom(cube);
        }
    }
    //---------Конец блока собирания первого слоя---------//

    static void left_pif_paf(Rubik_Cube& cube)
    {
        cube.L_();
        cube.U_();
        cube.L();
        cube.U();
        std::cout << " L_ U_ L U";
    }

    //--------Блок собирания второго слоя---------//

    static bool check_first_layer(Rubik_Cube& cube)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (cube.get_front()[0][1] == cube.get_front()[1][1] &&
                    (cube.get_up()[2][1] == cube.get_right()[1][1] || cube.get_up()[2][1] == cube.get_left()[1][1]))
                    return true;
                else
                {
                    cube.U_();
                    std::cout << " U_";
                }
            }
            cube.y();
            std::cout << " y";
        }
        return false;
    }
    static void first_layer(Rubik_Cube& cube)
    {
        if (cube.get_up()[2][1] == cube.get_left()[1][1])
        {
            cube.U_();
            std::cout << " U_";
            left_pif_paf(cube);
            cube.y_();
            std::cout << " y_";
            pif_paf(cube);
        }
        else if (cube.get_up()[2][1] == cube.get_right()[1][1])
        {
            cube.U();
            std::cout << " U";
            pif_paf(cube);
            cube.y();
            std::cout << " y";
            left_pif_paf(cube);
        }
    }
    static bool check_second_layer1(Rubik_Cube& cube)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (cube.get_front()[1][1] != cube.get_front()[1][2]/* &&
                cube.get_front()[1][2] == cube.get_right()[1][1]*/)
                return true;
            else
            {
                cube.y();
                std::cout << " y";
            }
        }
        return false;
    }
    static bool check_second_layer2(Rubik_Cube& cube)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (cube.get_front()[1][1] != cube.get_right()[1][0] &&
                cube.get_front()[1][2] == cube.get_right()[1][1])
                return true;
            else
            {
                cube.y();
                std::cout << " y";
            }
        }
        return false;
    }
    static void third_step(Rubik_Cube& cube)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (check_first_layer(cube) == true)
                first_layer(cube);
            else if (check_second_layer1(cube) == true/* || check_second_layer2(cube) == true*/)
            {
                pif_paf(cube);
                cube.y();
                std::cout << " y";
                left_pif_paf(cube);
                first_layer(cube);
            }
        }
    }
    //---------Конец блока собирания второго слоя--------//

    //---------Блок сборки желтого креста-----------//
    static void stick(Rubik_Cube& cube)
    {
        cube.F();
        std::cout << " F";
        pif_paf(cube);
        cube.F_();
        std::cout << " F_";
    }
    static void checkmark(Rubik_Cube& cube)
    {
        cube.F();
        std::cout << " F";
        pif_paf(cube);
        pif_paf(cube);
        cube.F_();
        std::cout << " F_";
    }
    static void dot(Rubik_Cube& cube)
    {
        stick(cube);
        cube.U();
        cube.U();
        std::cout << " U2";
        checkmark(cube);
    }
    static void yellow_cross(Rubik_Cube& cube)
    {
        while (cube.get_front()[1][1] != red)
        {
            cube.y();
            std::cout << " y";
        }
        if (cube.get_up()[1][0] == yellow && cube.get_up()[1][2] == yellow &&
            cube.get_up()[0][1] == yellow && cube.get_up()[2][1] == yellow)
            return;
        else if (cube.get_up()[1][0] == yellow && cube.get_up()[1][2] == yellow)
            stick(cube);
        else if (cube.get_up()[1][0] == yellow && cube.get_up()[0][1] == yellow)
            checkmark(cube);
        else
            dot(cube);
    }
    //---------Конец блока сборки желтого креста-------//

    //---------Блок сборки желтой стороны---------//
    static bool check_to_yellow(Rubik_Cube& cube)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (cube.get_left()[0][0] != yellow)
                return true;
            else
            {
                cube.L();
                std::cout << " L";
            }
        }
        return false;
    }
    static void fifth_step(Rubik_Cube& cube)
    {
        cube.x_();
        cube.y();
        std::cout << " x_ y";
        while (check_to_yellow(cube) == true)
        {
            if (cube.get_up()[0][0] == yellow)
            {
                for (int i = 0; i < 4; ++i)
                    pif_paf(cube);
            }
            else
            {
                for (int i = 0; i < 2; ++i)
                    pif_paf(cube);
            }
        }
        cube.y_();
        cube.x();
        std::cout << " y_ x";
    }
    //----------Конец блока сборки желтой стороны---------//

    //----------Расставляем верхние средние ребра на свои места----------//
    static bool check_two_nearby_yellow(Rubik_Cube& cube)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (cube.get_left()[1][1] == cube.get_left()[0][1] &&
                    cube.get_back()[1][1] == cube.get_back()[0][1] &&
                    cube.get_front()[1][1] != cube.get_front()[0][1])
                    return true;
                else
                {
                    cube.U();
                    std::cout << " U";
                }
            }
            cube.y();
            std::cout << " y";
        }
        return false;
    }
    static bool check_two_opposite_yellow(Rubik_Cube& cube)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (cube.get_front()[1][1] == cube.get_front()[0][1] &&
                    cube.get_back()[1][1] == cube.get_back()[0][1] &&
                    cube.get_right()[1][1] != cube.get_right()[0][1])
                    return true;
                else
                {
                    cube.U_();
                    std::cout << " U_";
                }
            }
            cube.y();
            std::cout << " y";
        }
        return false;
    }
    static void first_situation(Rubik_Cube& cube)
    {
        cube.R();
        cube.U();
        cube.R_();
        cube.F_();
        cube.R();
        cube.U();
        cube.R_();
        cube.U_();
        cube.R_();
        cube.F();
        cube.R();
        cube.R();
        cube.U_();
        cube.R_();
        cube.U_();
        std::cout << " R U R_ F_ R U R_ U_ R_ F R2 U_ R_ U_";
    }
    static void second_situation(Rubik_Cube& cube)
    {
        first_situation(cube);
        cube.U();
        cube.U();
        std::cout << " U2";
        first_situation(cube);
        cube.U_();
        std::cout << " U_";
    }
    static void sixth_step(Rubik_Cube& cube)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (cube.get_front()[1][1] == cube.get_front()[0][1] &&
                cube.get_back()[1][1] == cube.get_back()[0][1] &&
                cube.get_right()[1][1] == cube.get_right()[0][1])
                return;
            else
            {
                cube.U_();
                std::cout << " U_";
            }
        }
        if (check_two_nearby_yellow(cube) == true)
            first_situation(cube);
        else if (check_two_opposite_yellow(cube) == true)
            second_situation(cube);
    }
    //---------Средние верхние ребра собраны---------//

    //---------Последний этап: расставляем углы--------//
    static bool check_to_correct_corner(Rubik_Cube& cube)
    {
        for (int j = 0; j < 4; ++j)
        {
            if(cube.get_left()[0][0] == cube.get_left()[1][1] &&
                cube.get_down()[0][2] == cube.get_down()[1][1])
                return true;
            else
            {
                cube.y();
                std::cout << " y";
            }
        }
        return false;
    }
    static bool check_all_corners(Rubik_Cube& cube)
    {
        for (int i = 0; i < 4; ++i)
        {
            if(cube.get_front()[0][0] != cube.get_front()[1][1] &&
               cube.get_up()[2][0] != cube.get_up()[1][1])
                return true;
            else
            {
                cube.x_();
                std::cout << " x_";
            }
        }
        return false;
    }
    static void rearrangement_corners(Rubik_Cube& cube)
    {
        cube.U();
        cube.U();
        cube.R();
        cube.U();
        cube.U();
        cube.R_();
        cube.F();
        cube.F();
        cube.U();
        cube.U();
        cube.L_();
        cube.U();
        cube.U();
        cube.L();
        cube.F();
        cube.F();
        std::cout << " U2 R U2 R_ F2 U2 L_ U2 L F2";
    }
    static void seventh_step(Rubik_Cube& cube, int& counter)
    {
        if (check_to_correct_corner(cube) == false)
        {
            cube.x_();
            cube.y();
            std::cout << " x_ y";
            rearrangement_corners(cube);
            cube.y_();
            cube.x();
            std::cout << " y_ x";
        }
        if (check_to_correct_corner(cube) == true)
        {
            cube.x_();
            cube.y();
            cube.x();
            std::cout << " x_ y x";
            while (check_all_corners(cube) == true)
            {
                rearrangement_corners(cube);
                ++counter;
                if (counter > 1000)
                    break;
            }
            cube.y_();
            cube.x();
            std::cout << " y_ x";
        }
    }
    //---------Кубик как будто бы собран--------//
    static void solve_cube(Rubik_Cube& cube, int& counter)
    {

        std::cout << "-------Sequence of rotates-------" << std::endl;
        white_cross(cube);
        second_step(cube);
        third_step(cube);
        yellow_cross(cube);
        fifth_step(cube);
        sixth_step(cube);
        seventh_step(cube, counter);
        std::cout << std::endl;
    }

    static bool check_cube(Rubik_Cube& cube)
    {
        int counter = 0;
        solve_cube(cube, counter);
        if (counter <= 1000)
            return true;
        else
            return false;
    }
};
