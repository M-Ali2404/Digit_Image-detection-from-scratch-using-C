make:
	gcc main.c datasetloader.c matrix.c neural_network.c -o digit_nn
	./digit_nn