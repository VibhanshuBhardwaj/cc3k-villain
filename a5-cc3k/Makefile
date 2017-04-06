CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k
MAINOBJ = main.o
FLOOROBJ = Cell.o Chamber.o  Game.o Floor.o
PLAYEROBJ = Character/Player/Player.o Character/Player/Shade.o Character/Player/Drow.o Character/Player/Vampire.o Character/Player/Troll.o Character/Player/Goblin.o Character/Player/Rut.o  Character/Player/PlayerFactory.o
ITEMOBJ = Item/Item.o Item/Potion/Potion.o Item/Potion/PotionFactory.o Item/Gold/Gold.o Item/Gold/GoldFactory.o

ENEMYOBJ = Character/Enemy/Enemy.o Character/Enemy/Human.o Character/Enemy/Dwarf.o Character/Enemy/Elf.o Character/Enemy/EnemyFactory.o Character/Enemy/Halfling.o Character/Enemy/Orc.o Character/Enemy/Dragon.o Character/Enemy/Merchant.o Character/Enemy/Vib.o

CHAROBJ = Character/Character.o
OBJECTS = ${MAINOBJ} ${FLOOROBJ} ${CHAROBJ} ${PLAYEROBJ} ${ENEMYOBJ} ${ITEMOBJ}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -g ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

