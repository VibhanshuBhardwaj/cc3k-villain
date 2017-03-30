#include <string>
#include "Elf.h"

using namespace std;

Elf::Elf(int atk, int def, int hp): Enemy(atk, def, hp, 'E', true) {}
