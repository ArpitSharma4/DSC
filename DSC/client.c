#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define SERVER_ADDRESS "127.0.0.1"
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_address.sin_addr);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Send data to server and receive response
    while (1) {
        printf("Enter message to send (type 'exit' to close connection): ");
        fgets(buffer, BUFFER_SIZE, stdin);

        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        send(client_socket, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Server disconnected\n");
            break;
        } else {
            printf("Received from server: %s", buffer);
        }
    }

    // Close socket
    close(client_socket);

    return 0;
}
