CC=g++
CXXFLAGS = -std=c++11
CFILES = $(CUR_PATH)/solution.cpp
TARGET = $(CUR_PATH)/solution.out
 
all : $(TARGET)

clean:
	@rm -f $(TARGET)
	@echo CLEAN DONE

$(TARGET): $(CFILES)
	@$(CC) $(CXXFLAGS) $(CFILES) -o $(TARGET)
	@echo COMPILE DONE
