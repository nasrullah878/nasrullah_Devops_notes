FROM ubuntu:22.04

RUN apt update && apt install -y g++ build-essential

COPY simple_tcp_calculator.cpp /app/
WORKDIR /app

RUN g++ -o calculator_server simple_tcp_calculator.cpp

EXPOSE 8000

CMD ["./calculator_server"]
