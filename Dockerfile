FROM gcc:13 AS build

RUN apt-get update && apt-get install -y cmake && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN mkdir build && cd build && cmake .. && cmake --build .

FROM debian:bookworm-slim

WORKDIR /app

COPY --from=build /app/build/Projet_CDataframe .
COPY --from=build /app/data.csv .

ENTRYPOINT ["./Projet_CDataframe"]