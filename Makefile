all:
	g++ -std=c++11 \
		src/main.cpp \
		src/game.cpp \
		src/core/resource_mgr.cpp \
		src/map/map.cpp \
		src/map/level.cpp \
	-lsfml-graphics -lsfml-window -lsfml-system
