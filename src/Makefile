phony: run run_dev

run: app
	./builds/app

run_dev: app_dev
	./builds/app
	
app: Application.cpp buildsDir
	g++ -pthread -o builds/app Application.cpp -lglfw -lGL -lXrandr -lX11 -lrt -lGL -lglut -lGLEW

app_dev: Application.cpp buildsDir
	g++ -pthread -o builds/app Application.cpp -DWINDOW_DEV=test -lglfw -lGL -lXrandr -lX11 -lrt -lGL -lglut -lGLEW

buildsDir:
	mkdir -p builds
