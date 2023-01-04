CC=g++
CXXFLAGS = 
CFILES = $(CUR_PATH)/solution.cpp
TARGET = $(CUR_PATH)/solution.out

INPUT = $(CUR_PATH)/input.txt
TMP_INPUT = $(CUR_PATH)/tmp_input.txt
OUTPUT = $(CUR_PATH)/output.txt

INPUT_COUNT := $(shell (read line; echo $$line) < $(INPUT))
 
all: $(TARGET) $(TMP_INPUT) $(OUTPUT)
  
clean:
	@rm -f $(TARGET) $(TMP_INPUT) $(OUTPUT)
	@echo CLEAN DONE

$(TARGET): $(CFILES)
	@$(CC) $(CXXFLAGS) $(CFILES) -o $(TARGET)
	@echo COMPILE DONE

$(TMP_INPUT): $(INPUT)
	@sed -n "2, \$$p" $(INPUT) > $(TMP_INPUT)

$(OUTPUT): $(TARGET)
	@for x in {1..$(INPUT_COUNT)}; do $(TARGET); done < $(TMP_INPUT) > $(OUTPUT)
	@rm -f $(TMP_INPUT)
	@echo TEST INPUT FILE  DONE
