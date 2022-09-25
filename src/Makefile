phony: run run_dev

run: app
	./app

run_dev: app_dev
	./app
	
app: Application.cpp
	g++ -pthread -o app $^ -lglfw -lGL -lXrandr -lX11 -lrt -lGL -lglut -lGLEW

app_dev: Application.cpp
	g++ -pthread -o app $^ -DWINDOW_DEV=test -lglfw -lGL -lXrandr -lX11 -lrt -lGL -lglut -lGLEW
