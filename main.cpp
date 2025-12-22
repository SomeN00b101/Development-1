#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool game_title_display(){
  cout << "BUCKSHOT ROULETTE (an adapted console version by SomeN00b101)\n\n" << endl;
  cout << "Start(S)\n" << "Options(O)\n" << "Credits(C)\n" << "Exit(E)\n" << endl;

  char r;
  cin.get(r);
  
  switch(r){
  case 's':
  case 'S':
    break;
  case 'o':
  case 'O':
    // Display options
    game_title_display();
    break;
  case 'c':
  case 'C':
    // Display credits
    game_title_display();
    break;
  case 'e':
  case 'E':
    // Exit game
    return false;
  default:
    game_title_display();
  }
  return true;
}

string walkthrough(){
  cout << "You wake up in a dingy bathroom." << endl
       << "On one of the mirrors reads 'AFRAID?'" << endl
       << "You see a door in front of you." << endl
       << "Head through it? (enter any key)" << endl;
  char r1;
  cin.get(rl);
  if (r1){
    cout << "You walk to the door, and kick it open." << endl;
    cout << "Outside, the loud music pounds your ears." << endl;
    cout << "Upon the balcony, you can see a rowdy party happening" << endl;
    cout << "There is another door in front of you." << endl;
    cout << "Head through it? (any key)" << endl;
    char r2;
    cin.get(r2);
    if (r2){
      cout << "You walk to the door, and kick it open." << endl;
      cout << "You walk up to what seems to be a playing table." << endl;
      cout << "A masked figure watches as you enter." << endl;
      cout << "On the table, you see a 'General Release of Liability'" << endl;
      cout << "'Please sign the waiver' (any key)" << endl;
      char r3;
      cin.get(r3);
      if (r3){
	cout << "Enter Name (to start game):\n" << endl;
	string name;
	return getline(cin, name);
      }
    }
  }
}

void display_round(int round){
  cout << "Round " << static_cast<int>(round) << endl;
  cout << "Both you and the dealer get ";
  switch (round){
  case 1:
    cout << "2 lives." << endl
    break;
  case 2:
    cout << "'Let's make this a little more interesting...'" << endl;
    cout << "A small box pop up in front of you." << endl;
    cout << "'Two items each.'" << endl;
    cout << "'More items before every load.'" << endl;
    cout << "4 lives." << endl;
    break;
  case 3:
    cout << "'Long last, we arrive at the final showdown.'" << endl;
    cout << "'No more defibrillators. No more blood transfusions'" << endl;
    cout << "'Now, me and you, we are dancing on the edge of life and death'" << endl;
    cout << "With a whir, a gadget slides up, and two clamps extend, poised over the transfusers of you and the dealer." << endl;
    cout << "'Four items each.'" << endl;
    cout << "5 lives." << endl;
    cout << "You know the drill" << endl;
    break;
  }
}

void display_subround(int round, int subround){
  switch(round){
  case 1:
    switch(subround){
    case 1:
      cout << "'1 LIVE ROUND. 2 BLANKS.'" << endl;
      cout << "'I INSERT THE SHELLS IN AN UKNOWN ORDER.'" << endl;
      cout << "The dealer loads the shells, pumps the shotgun, and lays it on the table" << endl;
      break;
    case 2:
      cout << "'3 LIVE ROUNDS. 2 BLANKS.'" << endl;
      cout << "'THEY ENTER THE CHAMBER IN A HIDDEN SEQUENCE.'" << endl;
      cout << "The dealer loads the shells, and puts it on the table" << endl;
      break;
    }
    break;
    
  case 2:
    switch(subround){
    case 1:
      cout << "'1 LIVE ROUND. 1 BLANK.'" << endl;
      cout << "The dealer loads the shells." << endl;
      break;
    case 2:
      cout << "'3 LIVE ROUNDS. 2 BLANKS.'" << endl;
      cout << "The dealer loads the shells." << endl;
      break;
    case 3:
      cout << "'3 LIVE ROUNDS. 3 BLANKS.'" << endl;
      cout << "The dealer loads the shells." << endl;
    }
    break;

  case 3:
    switch(subround){
    case 1:
      // Display subround 1
      break;
    case 2:
      // Display subround 2
      break;
    case 3:
      // Display subround 3
      break;
    }
    break;
    cout << "The dealer loads the shells." << endl;
  }
}


// Round Class - for 3 rounds
// Player Class - for player and dealer
int main(){
  if (game_title_display())
    string name = walkthrough();

  bool round1 = true, round2 = true, round3 = true;
  display_round(1);
  while (round1){
    bool subround1 = true, subround2 = true;
    display_subround(1, 1); 
    while (subround1){
      // Execute subround1
    }

    display_subround(1, 2)
    while (subround2){
      // Execute subround2
    }
  }

  display_round(2);
  while (round2){
    bool subround1 = true, subround2 = true, subround3 = true;
    display_subround(2, 1);
    while (subround1){
      // Execute subround1
    }

    display_subround(2, 2);
    while (subround2){
      // Execute subround2
    }

    display_subround(2, 3);
    while (subround3){
      // Execute subround3
    }
  }

  display_round(3);
  while (round3){
    bool subround1 = true, subround2 = true, subround3 = true;
    display_subround(3, 1);
    while(subround1){
      // Execute subround1
    }

    display_subround(3, 2);
    while(subround2){
      // Execute subround2
    }

    display_subround(3, 3);
    while(subround3){
      // Execute subround3
    }
  }
  
  return 0;
}
