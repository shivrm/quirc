run: build
	./build/lexer examples/bell.qc

build: lexer
	mkdir -p build
	g++ src/lexer.cpp -o build/lexer

lexer:
	flex -o src/lexer.cpp src/lexer.l
	
clean:
	rm src/lexer.cpp build/lexer
