#makefile for Final Project by Darwin Yee
#Adapted from Lecture: Makefiles module
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = AppleStore.o Casino.o ClothesStore.o DepartmentStore.o DoublyLinkedList.o FlowerStore.o FoodCourt.o Game.o InputValidation2.o JewelryStore.o MainCharacter.o Menu.o Node.o Restroom.o SiteMap.o Space.o ToyStore.o Final_main.o

SRCS = AppleStore.cpp Casino.cpp ClothesStore.cpp DepartmentStore.cpp DoublyLinkedList.cpp FlowerStore.cpp FoodCourt.cpp Game.cpp InputValidation2.cpp JewelryStore.cpp MainCharacter.cpp Menu.cpp Node.cpp Restroom.cpp SiteMap.cpp Space.cpp ToyStore.cpp Final_main.cpp

HEADERS = AppleStore.hpp Casino.hpp ClothesStore.hpp DepartmentStore.hpp DoublyLinkedList.hpp FlowerStore.hpp FoodCourt.hpp Game.hpp InputValidation2.hpp JewelryStore.hpp MainCharacter.hpp Menu.hpp Node.hpp Restroom.hpp SiteMap.hpp Space.hpp ToyStore.hpp

OUTPUT = FinalProject

ZIPNAME = FinalProject_Yee_Darwin.zip

ZIPADDFILE = makefile FinalProject_Design_and_Reflection.pdf

#target: dependencies
#	rule to build
#

${OUTPUT}: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${OUTPUT}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o ${OUTPUT}

zip:
	zip -D ${ZIPNAME} ${SRCS} ${HEADERS} ${ZIPADDFILE}