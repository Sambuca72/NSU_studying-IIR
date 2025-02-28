#include <stdlib.h>
#include <unistd.h>
#include <winsock2.h>

#define TOKEN "https://t.me/ImperativeProgrammingBot"
#define CHAT_ID "https://t.me/Cyberpsychoz"
#define BUFFER_SIZE 1024

void sendMessage(const char *message) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Создаем сокет
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    // Указываем адрес сервера
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Порт HTTP
    server_addr.sin_addr.s_addr = inet_addr("149.154.175.100"); // IP-адрес Telegram

    // Подключаемся к серверу
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return;
    }

    // Формируем HTTP-запрос
    snprintf(buffer, sizeof(buffer),
             "GET /bot%s/sendMessage?chat_id=%s&text=%s HTTP/1.1\r\n"
             "Host: api.telegram.org\r\n"
             "Connection: close\r\n\r\n",
             TOKEN, CHAT_ID, message);

    // Отправляем запрос
    send(sock, buffer, strlen(buffer), 0);

    // Получаем ответ
    while (recv(sock, buffer, sizeof(buffer) - 1, 0) > 0) {
        printf("%s", buffer); // Выводим ответ
    }

    // Закрываем сокет
    close(sock);
}

const char *testMessage = "Hello, this is a test message from my C program!";
    sendMessage(testMessage);