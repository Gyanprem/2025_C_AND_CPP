#include <stdio.h>
//#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <freertos/semphr.h>
#include <esp_system.h>
#include <esp_log.h>
#include <esp_wifi.h>
#include <mqtt_client.h>
#include <driver/uart.h>
#include <driver/gpio.h>

#define LED_GPIO GPIO_NUM_2 // GPIO for LED
#define UART_TX GPIO_NUM_17 // UART TX pin
#define UART_RX GPIO_NUM_16 // UART RX pin
#define UART_BAUD_RATE 9600
#define UART_BUF_SIZE 1024
#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASS "your_wifi_password"
#define MQTT_BROKER_URI "mqtt://broker.hivemq.com"

static const char *TAG = "ESP32_ASSIGNMENT";

QueueHandle_t uart_queue;
esp_mqtt_client_handle_t mqtt_client;

void wifi_init() {
    ESP_LOGI(TAG, "Connecting to WiFi...");
    // WiFi initialization code here
}

void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data) {
    esp_mqtt_event_handle_t event = event_data;
    switch (event_id) {
        case MQTT_EVENT_CONNECTED:
            ESP_LOGI(TAG, "MQTT connected");
            gpio_set_level(LED_GPIO, 1); // LED ON
            break;
        case MQTT_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "MQTT disconnected");
            gpio_set_level(LED_GPIO, 0); // LED OFF
            break;
        default:
            break;
    }
}

void mqtt_app_start() {
    esp_mqtt_client_config_t mqtt_cfg = {
        .uri = MQTT_BROKER_URI,
    };
    mqtt_client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(mqtt_client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
    esp_mqtt_client_start(mqtt_client);
}

void core0_task(void *pvParameters) {
    wifi_init();
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    mqtt_app_start();

    while (1) {
        gpio_set_level(LED_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(2000));
        gpio_set_level(LED_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void core1_task(void *pvParameters) {
    uart_config_t uart_config = {
        .baud_rate = UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };
    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_1, UART_TX, UART_RX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM_1, UART_BUF_SIZE, 0, 0, NULL, 0);

    ESP_LOGI(TAG, "UART Initialized");

    uint8_t data[UART_BUF_SIZE];

    while (1) {
        int len = uart_read_bytes(UART_NUM_1, data, UART_BUF_SIZE, pdMS_TO_TICKS(100));
        if (len > 0) {
            data[len] = '\0';
            ESP_LOGI(TAG, "Received: %s", data);
            esp_mqtt_client_publish(mqtt_client, "/esp32/data", (char *)data, 0, 1, 0);
        }
    }
}

void app_main() {
    xTaskCreatePinnedToCore(core0_task, "Core0_Task", 4096, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(core1_task, "Core1_Task", 4096, NULL, 1, NULL, 1);
}

