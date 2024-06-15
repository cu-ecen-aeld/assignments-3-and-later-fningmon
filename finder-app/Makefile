# Define compiler based on CROSS_COMPILE existence
CC  = $(if $(CROSS_COMPILE), $(CROSS_COMPILE)gcc, gcc)

# Define flags
CFLAGS  = -Wall -g

SRC := writer.c
TARGET = writer
OBJS := $(SRC:.c=.o)

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LDFLAGS)

clean:
	-rm -f *.o $(TARGET) *.elf *.map
