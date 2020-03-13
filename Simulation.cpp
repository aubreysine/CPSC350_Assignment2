#include "Simulation.h"

Simulation::Simulation(){}

//Overload constructor - creates game boards from given rows, columns and density
Simulation::Simulation(int rows, int columns, float density){
  m_gameBoard = new Board(rows, columns, density);
  m_nextBoard = new Board(rows, columns);
  m_prevBoard = new Board(rows, columns);
}

//Overload constructor - creates game boards from file input
Simulation::Simulation(ifstream &inFS){
  m_gameBoard = new Board(inFS);
  int rows = m_gameBoard->getRows();
  int columns = m_gameBoard->getColumns();

  m_nextBoard = new Board(rows,columns);
  m_prevBoard = new Board(rows,columns);
}

Simulation::~Simulation(){
  delete m_gameBoard;
  delete m_nextBoard;
  delete m_prevBoard;
}

//Gameplay instructions for output to console
void Simulation::playGame(int output){
  int genCount = 0; //Number of generations
  int repeatCount = 0; //Number of boards repeated every other generation

  cin.get(); //Making cin input blank

  //Run simulation while the generation repeat count is less than 2
  do{
    //Print board to console
    m_gameBoard->printBoard(genCount);
    if(output == 1){
      usleep(1500000); //Pause before generation
    } else{
      cin.get(); //User presses enter before next generation
    }

    calcGen(); //Calculates next game board

    //Exit if game board is repeated
    if(m_gameBoard->isEqual(m_nextBoard)){
      break;
    }

    /**Adds to repeat count if board before current generation and after current
    generation are equa, if not sets repeat count to start again*/
    if(m_nextBoard->isEqual(m_prevBoard)){
      repeatCount++;
    }else if(repeatCount > 0){
      repeatCount = 0;
    }

    //Updating boards
    m_prevBoard->setBoard(m_gameBoard);
    m_gameBoard->setBoard(m_nextBoard);
    genCount++;
  } while(repeatCount < 2);

  cout << "Simulation over. Press \"Enter\" to exit the program. " << endl;
  cin.get();
}

//Gameplay instructions for output to file
void Simulation::playGame(string fName, int cycles){
  int genCount = 0; //Number of generations
  int repeatCount = 0; //Number of boards repeated every other generation

  //Opening output file
  ofstream outFS;
  outFS.open(fName);

  /**Run simulation while the generation repeat count is less than 2 or generation
  count is more than user specified generation limit*/
  do{
    m_gameBoard->printBoard(genCount, outFS);
    calcGen(); //Calculates next game board

    //Exit if game board is repeated
    if(m_gameBoard->isEqual(m_nextBoard)){
      break;
    }

    /**Adds to repeat count if board before current generation and after current
    generation are equa, if not sets repeat count to start again*/
    if(m_nextBoard->isEqual(m_prevBoard)){
      repeatCount++;
    }else if(repeatCount > 0){
      repeatCount = 0;
    }
    //Updating game boards
    m_prevBoard->setBoard(m_gameBoard);
    m_gameBoard->setBoard(m_nextBoard);
    genCount++;
  }while(repeatCount < 2 && genCount <= cycles);
  outFS.close();

  cout << "Simulation over. Press \"Enter\" to exit the program. " << endl;
  cin.get();
  cin.get();
}

void Simulation::calcGen(){}
