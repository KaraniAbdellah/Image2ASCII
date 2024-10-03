CC = gcc
TARGET = main
SRCS = main.c


all: clean $(TARGET)


$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) -lm


clean:
	rm -f $(TARGET)
