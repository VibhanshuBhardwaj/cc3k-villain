CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k
MAINOBJ = main.o
FLOOROBJ = Cell.o Chamber.o  Game.o Floor.o
PLAYEROBJ = Character/Player.o Character/Shade.o Character/Drow.o Character/Vampire.o Character/Troll.o Character/Goblin.o Character/PlayerFactory.o

ENEMYOBJ = Character/Enemy.o
CHAROBJ = Character/Character.o
OBJECTS = ${MAINOBJ} ${FLOOROBJ} ${CHAROBJ} ${PLAYEROBJ} ${ENEMYOBJ} ${ITEMOBJ}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -g ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
