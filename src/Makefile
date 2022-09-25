phony: run

run: app
	./app

app: Application.cpp
	g++ -pthread -o app $^ -lglfw -lGL -lXrandr -lX11 -lrt -lGL -lglut -lGLEW
