#include "Simulation.h"

Simulation::Simulation(){}

Simulation::Simulation(int rows, int columns, float density){
  m_gameBoard = new Board(rows, columns, density);
  m_nextBoard = new Board(rows, columns);
  m_prevBoard = new Board(rows, columns);
}

Simulation::Simulation(string fName){
  m_gameBoard = new Board(fName);
  m_nextBoard = new Board(fName);
  m_prevBoard = new Board(fName);
}


Simulation::~Simulation(){
  delete m_gameBoard;
  delete m_nextBoard;
  delete m_prevBoard;
}

void Simulation::playGame(int output){
  int repeatCount = 0;
  int genCount = 0;

  cin.get();
  do{
    calcGen();
    if(m_gameBoard->isEqual(m_nextBoard)){
      break;
    }

    m_gameBoard->printBoard(genCount);
    if(output == 1){
      usleep(1500000);
    } else{
      cin.get();
    }

    if(m_nextBoard->isEqual(m_prevBoard)){
      repeatCount++;
    }else if(repeatCount > 0){
      repeatCount = 0;
    }

    m_prevBoard->setBoard(m_gameBoard);
    m_gameBoard->setBoard(m_nextBoard);
    genCount++;
  } while(repeatCount < 2);

  cout << "Simulation over. Press \"Enter\" to exit the program. " << endl;
  cin.get();
}

void Simulation::playGame(string fName, int cycles){
  int repeatCount = 0;
  int genCount = 0;

  do{
    m_gameBoard->printBoard(genCount);
    calcGen();

    if(m_gameBoard->isEqual(m_nextBoard)){
      break;
    }

    if(m_nextBoard->isEqual(m_prevBoard)){
      repeatCount++;
    }else if(repeatCount > 0){
      repeatCount = 0;
    }

    m_prevBoard->setBoard(m_gameBoard);
    m_gameBoard->setBoard(m_nextBoard);
    genCount++;
  }while(repeatCount < 2 && genCount <= cycles);
}

void Simulation::calcGen(){}
