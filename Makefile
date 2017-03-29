CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k
MAINOBJ = main.o
FLOOROBJ = Cell.o Chamber.o  Game.o Floor.o
PLAYEROBJ = Player.o
ENEMYOBJ = Enemy.o
CHAROBJ = Character.o
OBJECTS = ${MAINOBJ} ${FLOOROBJ} ${CHAROBJ} ${PLAYEROBJ} ${ENEMYOBJ} ${ITEMOBJ}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -g ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}