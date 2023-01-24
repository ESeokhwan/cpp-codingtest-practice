CC=g++
CXXFLAGS = 
CFILES = $(CUR_PATH)/solution.cpp
TARGET = $(CUR_PATH)/solution.out

INPUT = $(CUR_PATH)/input.txt
TMP_INPUT = $(CUR_PATH)/tmp_input.txt

INPUT_COUNT := $(shell (read line; echo $$line) < $(INPUT))

IS_INPUT_COUNT_VALIDATE := $(shell [ $(INPUT_COUNT) -lt 100 -a $(INPUT_COUNT) -gt 0 ] && echo true)
 
ifeq ($(IS_INPUT_COUNT_VALIDATE), true)
  ALL = $(TARGET) $(TMP_INPUT) Execution
else
  ALL = INPUT_COUNT_ERROR
endif
  
all : $(ALL)

clean:
	@rm -f $(TMP_INPUT) $(TARGET)

$(TARGET): $(CFILES)
	@$(CC) $(CXXFLAGS) $(CFILES) -o $(TARGET)
	@echo COMPILE DONE

$(TMP_INPUT): $(INPUT)
	@sed -n "2, \$$p" $(INPUT) > $(TMP_INPUT)

Execution: $(TARGET)
	@for x in {1..$(INPUT_COUNT)} \
	;do \
		start_t=`gdate +%s%N` && \
		echo ====== TEST $$x Start ===== && \
		$(TARGET) && \
		end_t=`gdate +%s%N` && \
		echo ------------------------- && \
		time=`expr $$end_t - $$start_t` && \
		echo take `expr $$time / 1000000`ms && \
		echo =========================\\n \
	;done < $(TMP_INPUT)
	@rm -f $(TMP_INPUT)
	@echo TEST INPUT FILE  DONE

INPUT_COUNT_ERROR :
	@echo '[ERROR] There should be count of input on top line of input.txt.'
	@echo '        It should larger than 0 and smaller than 100.'
