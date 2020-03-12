#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"

int main(int argc, char const *argv[]) {
  int config, mode, rows, columns, output, cycles;
  float density;
  string ifName, ofName;
  ifstream inFS;
  Simulation* game;

  //Getting configuration type and repeating if invalid entry
  do{
    cout << "\nChoose a board configuration type: \n\t1)Random configuration \n\t2)Flat file configuration\nChoice: ";
    cin >> config;
  } while(config != 1 && config !=2);

  if(config == 1){
    //Getting neccessary variables for random configuration
    cout << "Enter amount of rows: ";
    cin >> rows;
    cout << "Enter amount of columns: ";
    cin >> columns;
    cout << "Enter population density(0-1): ";
    cin >> density;
  }else{
    //Getting file path and repeating until its valid
    while(true){
      cout << "Enter the path of the file: ";
      cin >> ifName;

      inFS.open(ifName);
      if(inFS.is_open()){
        break;
      } else{
        cout << ifName << " is invalid file path. Try Again" << endl;
      }
    }
  }

  //Getting game mode and repeating if invalid entry
  do{
    cout << "\nChoose a game mode:\n\t1)Classic mode\n\t2)Doughnut mode\n\t3)Mirror mode \nChoice: ";
    cin >> mode;
  } while(mode != 1 && mode !=2 && mode !=3);

//Creating game based on configurartion and game mode entries.
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
      case 1: game = new ClassicMode(inFS);
        break;
      case 2: game = new DoughnutMode(inFS);
        break;
      case 3: game = new MirrorMode(inFS);
        break;
    }
  }

  //Getting choice for output and repeating if invalid entry
  do{
    cout << "\nChoose an output option: \n\t1)Brief pauses \n\t2)Press enter key \n\t3)Output to file \nChoice: ";
    cin >> output;
  } while(output != 1 && output != 2 && output != 3);

  //Entering different game modes depending on output option
  if(output == 3){
      cout << "Enter the output file name: ";
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
