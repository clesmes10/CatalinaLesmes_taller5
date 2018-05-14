placas.pdf: grafica.py placas.txt
	python grafica.py
placas.txt: placas.x
	./placas.x
placas.x: placas.cpp
	c++ placas.cpp -o placas.x
