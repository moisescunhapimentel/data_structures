FROM alpine:latest

RUN apk add --no-cache gcc g++ cmake make cunit-dev

WORKDIR /app

COPY . .

RUN rm -rf /app/build/* && rm -rf /app/logs && mkdir -p build && cd build && cmake .. && make

WORKDIR /app/build

CMD ["ctest"]