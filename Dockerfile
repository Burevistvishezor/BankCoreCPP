# --- Этап 1: Сборка приложения (Multi-stage build) ---
FROM ubuntu:22.04 AS builder

# Отключаем интерактивные диалоги при установке пакетов
ENV DEBIAN_FRONTEND=noninteractive

# Устанавливаем необходимые инструменты и библиотеки
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libpqxx-dev \
    libpq-dev \
    && rm -rf /var/lib/apt/lists/*

# Копируем исходный код проекта в контейнер
WORKDIR /app
COPY . .

# Собираем проект через CMake
RUN mkdir build && cd build && \
    cmake -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build .

# --- Этап 2: Финальный легковесный контейнер для запуска ---
FROM ubuntu:22.04

# Устанавливаем только runtime-зависимости (библиотеку для работы с Postgres)
RUN apt-get update && apt-get install -y \
    libpqxx-4.0v5 \
    libpq5 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /root/

# Копируем скомпилированный бинарник из первого этапа
# ПРИМЕЧАНИЕ: Замените 'BankCore' на точное имя вашего исполняемого файла, если оно другое
COPY --from=builder /app/build/BankCore .

# Запуск приложения
CMD ["./BankCore"]
