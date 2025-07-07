#include <iostream>
#include <string>
#include <cmath>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8000);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        return -1;
    }

    // Listen
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        return -1;
    }

    cout << "Calculator server running on port 8000...\n";

    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            return -1;
        }

        // Read input from client (for simplicity)
        int valread = read(new_socket, buffer, 1024);
        string input(buffer, valread);

        // Here parse input and perform calculation (you can extend this)
        string response = "You said: " + input + "\n";

        send(new_socket, response.c_str(), response.size(), 0);
        close(new_socket);
    }

    return 0;
}


