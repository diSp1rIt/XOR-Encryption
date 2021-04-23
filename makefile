CC=g++
CFLAGS=-Wall
LIBS=libs/xorcrypt.cpp libs/argparser.cpp
EXECUTABLE=crypt

default:
	$(CC) main.cpp $(CFLAGS) $(LIBS) -o $(EXECUTABLE)

test:
	echo "test test test" > in.txt
	echo "key key key" > xor.key
	./$(EXECUTABLE) -k xor.key -i in.txt -o out
	./$(EXECUTABLE) -k xor.key -i out -o decrypted.txt

clear:
	rm -rf in.txt xor.key out decrypted.txt
