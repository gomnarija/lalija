CC:=g++
CFLAGS:=
NAME:=lalija

SRC_DIR:=src
OBJ_DIR:=obj

SRC:=$(wildcard $(SRC_DIR)/*.cpp)
OBJ:=$(wildcard $(OBJ_DIR)/*.o)


install: build
	$(CC) -o $(NAME) $(OBJ)

build: obj_dir
	$(CC) -c $(CFLAGS) $(SRC)
	mv *.o $(OBJ_DIR)
		
obj_dir:
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(NAME)
	rm -f -r $(OBJ_DIR)
