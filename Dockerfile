FROM alpine:latest

RUN apk add --no-cache gcc g++ cmake make cunit-dev

WORKDIR /app

COPY . .

RUN mkdir -p build && cd build && cmake .. && make

WORKDIR /app/build

CMD ["ctest"]