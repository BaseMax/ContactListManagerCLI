CC = cc
CFLAGS = -Wall -Werror

all: contact_manager

contact_manager:
	@echo "[+] Building project..."
	$(CC) $(CFLAGS) -o contact_manager ./src/main.c

run: contact_manager
	./contact_manager

clean:
	@echo "[+] Cleaning..."
	rm -f contact_manager
