#include "../src/source.h"
#include "gtest/gtest.h"
#include <string>

char pole[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                   {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                   {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                   {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                   {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

TEST(W_Peshka, Correct_P_forward1cell)
{
    int x1 = 6, y1 = 5, x2 = 5, y2 = 5;
    int result = move_check(0, x1, x2, y1, y2, pole);
    int expected = 1;
    EXPECT_EQ(expected, result);
}
TEST(W_Peshka, Correct_P_forward2cell)
{
    int x1 = 6, y1 = 5, x2 = 4, y2 = 5;
    int result = move_check(0, x1, x2, y1, y2, pole);
    int expected = 1;
    EXPECT_EQ(expected, result);
}
TEST(W_Peshka, Correct_P_attack)
{
    int x1 = 6, y1 = 4, x2 = 5, y2 = 5;
    pole[5][5] = 'r';
    int result = move_check(0, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[5][5] = ' ';
    EXPECT_EQ(expected, result);
}
TEST(B_Peshka, Correct_p_forward1cell)
{
    int x1 = 1, y1 = 5, x2 = 2, y2 = 5;
    int result = move_check(1, x1, x2, y1, y2, pole);
    int expected = 1;
    EXPECT_EQ(expected, result);
}
TEST(B_Peshka, Correct_p_forward2cell)
{
    int x1 = 1, y1 = 5, x2 = 3, y2 = 5;
    int result = move_check(1, x1, x2, y1, y2, pole);
    int expected = 1;
    EXPECT_EQ(expected, result);
}
TEST(B_Peshka, Correct_p_attack)
{
    int x1 = 1, y1 = 5, x2 = 2, y2 = 4;
    pole[2][4] = 'R';
    int result = move_check(1, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[2][4] = 'R';
    EXPECT_EQ(expected, result);
}
TEST(W_Rook, Correct_R_left)
{
    int x1 = 7, y1 = 1, x2 = 5, y2 = 1;
    pole[6][1] = ' ';
    int result = move_check(0, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[6][1] = 'P';
    EXPECT_EQ(expected, result);
}
TEST(W_Rook, Correct_R_right)
{
    int x1 = 7, y1 = 8, x2 = 5, y2 = 8;
    pole[6][8] = ' ';
    int result = move_check(0, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[6][8] = 'P';
    EXPECT_EQ(expected, result);
}
TEST(B_Rook, Correct_r_left)
{
    int x1 = 0, y1 = 1, x2 = 2, y2 = 1;
    pole[1][1] = ' ';
    int result = move_check(1, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[1][2] = 'p';
    EXPECT_EQ(expected, result);
}
TEST(B_Rook, Correct_r_right)
{
    int x1 = 0, y1 = 8, x2 = 2, y2 = 8;
    pole[1][8] = ' ';
    int result = move_check(1, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[1][8] = 'P';
    EXPECT_EQ(expected, result);
}
TEST(W_Horse, Correct_H_left)
{
    int x1 = 7, y1 = 2, x2 = 5, y2 = 3;
    int result = move_check(0, x1, x2, y1, y2, pole);
    int expected = 1;
    EXPECT_EQ(expected, result);
}
TEST(W_Horse, Correct_H_right)
{
    int x1 = 7, y1 = 7, x2 = 5, y2 = 6;
    int result = move_check(0, x1, x2, y1, y2, pole);
    int expected = 1;
    EXPECT_EQ(expected, result);
}
TEST(B_Horse, Correct_h_left)
{
    int x1 = 0, y1 = 2, x2 = 2, y2 = 3;
    int result = move_check(1, x1, x2, y1, y2, pole);
    int expected = 1;
    EXPECT_EQ(expected, result);
}
TEST(B_Horse, Correct_h_right)
{
    int x1 = 0, y1 = 7, x2 = 2, y2 = 6;
    int result = move_check(1, x1, x2, y1, y2, pole);
    int expected = 1;
    EXPECT_EQ(expected, result);
}
TEST(W_Bishop, Correct_B_left)
{
    pole[6][4] = ' ';
    int x1 = 7, y1 = 3, x2 = 5, y2 = 5;
    int result = move_check(0, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[6][4] = 'P';
    EXPECT_EQ(expected, result);
}
TEST(W_Bishop, Correct_B_right)
{
    pole[6][5] = ' ';
    int x1 = 7, y1 = 6, x2 = 5, y2 = 4;
    int result = move_check(0, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[6][5] = 'P';
    EXPECT_EQ(expected, result);
}
TEST(B_Bishop, Correct_b_left)
{
    pole[1][4] = ' ';
    int x1 = 0, y1 = 3, x2 = 2, y2 = 5;
    int result = move_check(1, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[1][4] = 'p';
    EXPECT_EQ(expected, result);
}
TEST(B_Bishop, Correct_b_right)
{
    pole[1][5] = ' ';
    int x1 = 0, y1 = 6, x2 = 2, y2 = 4;
    int result = move_check(1, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[1][5] = 'p';
    EXPECT_EQ(expected, result);
}
TEST(W_Queen, Correct_Q)
{
    pole[6][4] = ' ';
    int x1 = 7, y1 = 4, x2 = 5, y2 = 4;
    int result = move_check(0, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[6][4] = 'P';
    EXPECT_EQ(expected, result);
}
TEST(B_Queen, Correct_q)
{
    pole[1][4] = ' ';
    int x1 = 0, y1 = 4, x2 = 2, y2 = 4;
    int result = move_check(1, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[1][4] = 'p';
    EXPECT_EQ(expected, result);
}
TEST(W_King, Correct_K)
{
    pole[6][5] = ' ';
    int x1 = 7, y1 = 5, x2 = 6, y2 = 5;
    int result = move_check(0, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[6][5] = 'P';
    EXPECT_EQ(expected, result);
}
TEST(B_King, Correct_k)
{
    pole[1][5] = ' ';
    int x1 = 0, y1 = 5, x2 = 1, y2 = 5;
    int result = move_check(1, x1, x2, y1, y2, pole);
    int expected = 1;
    pole[1][5] = 'p';
    EXPECT_EQ(expected, result);
}
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
