#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }z

    // Initialize server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept connection from client
    int client_address_length = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address_length);
    if (client_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected\n");

    // Receive data from client and echo back
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Client disconnected\n");
            break;
        } else {
            printf("Received from client: %s", buffer);
            send(client_socket, buffer, bytes_received, 0);
        }
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}
