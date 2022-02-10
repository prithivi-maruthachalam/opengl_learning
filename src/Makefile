phony: run

run: app
	./app

app: app.cpp
	g++ -pthread -o app $^ -lglfw -lGL -lXrandr -lX11 -lrt -lGL -lglut -lGLEW