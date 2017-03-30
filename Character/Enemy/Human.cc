#include <string>
#include "Human.h"

using namespace std;

Human::Human(int atk, int def, int hp): Enemy(atk, def, hp, 'H', true) {}
