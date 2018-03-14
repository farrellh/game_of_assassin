#include "lliststr.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main (int argc, char* argv[])
{

	// Error statement if not enough input
	
  if(argc < 2)
  {
    std::cout << "Not enough input" << std::endl;
    return 0;
  }

  ifstream input(argv[1]);

  // Error statement if filename is wrong
  if(input.fail())
  {
  	std::cout << "Invalid filename" << std::endl;
  }

  // Initialize variables
  string action = "";
  int position = 0;
  string name = "";

  // Create playerlist
  LListStr *playerlist = new LListStr();

  // While the input doesn't reach end of file
  while(!input.eof())
  {

  // Take in the action and position from file
  input >> action;
  input >> position;

  // If the action is add, insert the name into the list
  if(action == "ADD")
  {
  	 input >> name;

  	 // Check to make sure add has a name with it
  	 if (name == "ADD" || name == "REPLACE" || name == "ACT")
  	 {
  	 	break;
  	 }

  	playerlist -> insert(position, name);

  }

  // If the action is replace, set the position to the new name
  else if (action == "REPLACE")
  {
  	input >> name;
  	
  	if (name == "ADD" || name == "REPLACE" || name == "ACT")
  	 {
  	 	break;
  	 }

  	playerlist -> set(position, name);
  }

  // If the action is act
  else if(action == "ACT")
  {

  	// Make sure there is more than one person and position is in bounds
  	if(playerlist -> size() != 1 && position < playerlist -> size())
  	{
  		// If the position is the last person in the list, go to the head
  		if(position == playerlist -> size() - 1)
  		{
  			position = 0;
  		}

  		else
  		{
  			position++;
  		}

  		// Assassinate the player
  		std::cout << "Assassinated: " << playerlist -> get(position) 
  		<< std::endl;

  		// Remove the player from the list
  		playerlist -> remove(position);

  	}
 
  }

  }
	
  // If there is only one player, output as the winner
  if(playerlist -> size() == 1)
  {
  	std::cout << "Winner: " << playerlist -> get(0) << std::endl;
  	
  }

  else
  {
  	// Output the size of the list and the names in the list
  	std::cout << "Remaining Players: " << playerlist -> size() << std::endl;

  	for(int i = 0; i < playerlist -> size(); i++)
  	{
  		std::cout << playerlist -> get(i) << std::endl;

  	}
  	
  }

  delete playerlist;

}


