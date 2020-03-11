#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"

int main(int argc, char const *argv[]) {
  int config, mode, rows, columns, output, cycles;
  float density;
  string ifName, ofName;
  Simulation* game;

  do{
    cout << "\nChoose a board configuration type: \n\t1)Random configuration \n\t2)Flat file configuration\nChoice: ";
    cin >> config;
  } while(config != 1 && config !=2);

  if(config == 1){
    cout << "\nEnter amount of rows: ";
    cin >> rows;
    cout << "Enter amount of columns: ";
    cin >> columns;
    cout << "Enter population density(0-1): ";
    cin >> density;
  }else{
    cout << "\nEnter the name of the file: ";
    cin >> ifName;
  }

  do{
    cout << "\nChoose a game mode:\n\t1)Classic mode\n\t2)Doughnut mode\n\t3)Mirror mode \nChoice: ";
    cin >> mode;
  } while(mode != 1 && mode !=2 && mode !=3);

  if(config ==1){
    switch(mode){
      case 1: game = new ClassicMode(rows, columns,density);
        break;
      case 2: game = new DoughnutMode(rows, columns,density);
        break;
      case 3: game = new MirrorMode(rows, columns,density);
        break;
    }
  }else{
    switch(mode){
      case 1: game = new ClassicMode(ifName);
        break;
      case 2: game = new DoughnutMode(ifName);
        break;
      case 3: game = new MirrorMode(ifName);
        break;
    }
  }

  do{
    cout << "\nChoose an output option: \n\t1)Brief pauses \n\t2)Press enter key \n\t3)Output to file \nChoice: ";
    cin >> output;
  } while(output != 1 && output != 2 && output != 3);

  if(output == 3){
      cout << "Enter the output File: ";
      cin >> ofName;
      cout << "Enter maximum number of cycles: ";
      cin >> cycles;
      game->playGame(ofName, cycles);
  } else{
      game->playGame(output);
  }

  delete game;
  return 0;
}
