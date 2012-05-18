BIN_DIR=bin/Debug
OBJ_DIR=obj/Debug
BBLIB=$(BIN_DIR)/bblib
MAIN.O=$(OBJ_DIR)/main.o
BBIO.O=$(OBJ_DIR)/bbio.o
Gpp=arm-linux-gnueabi-g++
GCC=arm-linux-gnueabi-gcc

$(BBLIB): $(MAIN.O) $(BBIO.O)
	@echo Linking bblib...
	@$(Gpp) $(MAIN.O) $(BBIO.O) -o bin/Debug/bblib

$(MAIN.O): main.cpp bbio.h
	@echo Building main.o... 
	@$(Gpp) -Wall -c main.cpp -o $(MAIN.O)

$(BBIO.O): bbio.c bbio.h gperf_pinMap.h
	@echo Building bbio.o
	@$(GCC) -Wall -c bbio.c -o $(BBIO.O)
	
gperf_pinMap.h: pinMap.h
	@echo Generating pinmap...
	@gperf -C -p -a -n -D -t -o -j 1 -k 2,3 -N getPin pinMap.h > gperf_pinMap.h

clean:
	@echo cleaning...
	@rm $(MAIN.O) $(BBIO.O) $(BBLIB) gperf_pinMap.h

upload:
	@scp bin/Debug/bblib root@10.42.0.76:/home/root/
	
deploy: $(BBLIB)
	@scp bin/Debug/bblib root@10.42.0.76:/home/root/

