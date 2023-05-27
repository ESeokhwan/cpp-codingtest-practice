CC=g++
CXXFLAGS = -std=c++11
CFILES = $(CUR_PATH)/solution.cpp
TARGET = $(CUR_PATH)/solution.out

INPUT = $(CUR_PATH)/input.txt
TMP_INPUT = $(CUR_PATH)/tmp_input.txt
OUTPUT = $(CUR_PATH)/output.txt

INPUT_COUNT := $(shell (read line; echo $$line) < $(INPUT))

IS_INPUT_COUNT_VALIDATE := $(shell [ $(INPUT_COUNT) -lt 100 -a $(INPUT_COUNT) -gt 0 ] && echo true)
 
ifeq ($(IS_INPUT_COUNT_VALIDATE), true)
  ALL = $(TARGET) $(TMP_INPUT) $(OUTPUT)
else
  ALL = INPUT_COUNT_ERROR
endif
  
all : $(ALL)

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

INPUT_COUNT_ERROR :
	@echo '[ERROR] There should be count of input on top line of input.txt.'
	@echo '        It should larger than 0 and smaller than 100.'
