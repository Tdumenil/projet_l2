EXEC_NAME = bin/CloneWarsText
OBJ_FILES_T = obj/txtGame.o obj/winTxt.o obj/mainTxt.o

EXEC_TEST = bin/testCloneWars
OBJ_FILES_TEST = obj/mainTest.o

EXEC_SDL = bin/CloneWars
OBJ_FILES_SDL = obj/Image.o obj/sdlGame.o obj/mainSdl.o obj/Font.o obj/Sound.o

OBJ_FILES = obj/Bullet.o obj/Unit.o obj/Turret.o obj/SpecialWeapon.o obj/Level.o obj/Player.o obj/Map.o obj/Game.o obj/Bot.o

OBJ_FILES_ALL = $(OBJ_FILES) $(OBJ_FILES_TEST) $(OBJ_FILES_SDL) $(OBJ_FILES_T)

CC = g++
CFLAGS = -Wall -ggdb
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

all: $(EXEC_NAME) $(EXEC_TEST) $(EXEC_SDL)

$(EXEC_NAME): $(OBJ_FILES_T) $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES_T) $(OBJ_FILES) $(LIBS)

$(EXEC_TEST): $(OBJ_FILES_TEST) $(OBJ_FILES)
	$(CC) -o $(EXEC_TEST) $(OBJ_FILES_TEST) $(OBJ_FILES) $(LIBS)

$(EXEC_SDL): $(OBJ_FILES_SDL) $(OBJ_FILES)
	$(CC) -o $(EXEC_SDL) $(OBJ_FILES_SDL) $(OBJ_FILES) $(LIBS)

obj/%.o: src/core/sources/%.cpp
	$(CC) -std=c++0x $(CFLAGS) -o $@ -c $<

obj/%.o: src/txtGame/sources/%.cpp
	$(CC) -std=c++0x $(CFLAGS) -o $@ -c $<

obj/%.o: src/sdlGame/sources/%.cpp
	$(CC) -std=c++0x $(CFLAGS) -o $@ -c $<


clean:
	rm $(OBJ_FILES_ALL)