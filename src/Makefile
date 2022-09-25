BUILD_FOLDER = build
MACROS_DEV=-DWINDOW_DEV

phony: run run_dev

run: app
	./${BUILD_FOLDER}/app

run_dev: app_dev
	./${BUILD_FOLDER}/app
	
app: Application.cpp buildsDir
	g++ `pkg-config --cflags glfw3 gl glew` -o ${BUILD_FOLDER}/app Application.cpp ${MACROS} `pkg-config --static --libs glfw3 gl glew`

app_dev: Application.cpp buildsDir
	g++ `pkg-config --cflags glfw3 gl glew` -o ${BUILD_FOLDER}/app Application.cpp ${MACROS_DEV} `pkg-config --static --libs glfw3 gl glew`

buildsDir:
	mkdir -p ${BUILD_FOLDER}
