#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <fstream>

class Board{
  public:
    Board();
    Board(int rows, int columns);
    Board(int rows, int columns, float density);
    Board(string fName);

    ~Board();

    void setBoard(Board* arr);
    int getRows();
    int getColumns();
    Cell getCell(int x, int y);
    void setCell(int x, int y, Cell c);

    bool isEqual(Board* arr);
    void printBoard(int x);
    void printBoard(int x, string fName);
  private:
    Cell **m_arr;
    int m_rows;
    int m_columns;
};
#endif
