# Objetivo predeterminado
all: principal

# Objetivos que no son archivos.
.PHONY: all testing clean_bin clean_test clean

# directorios
HDIR = include
CPPDIR = cpp
ODIR = obj

TESTDIR = test

MODULOS = lista tabla cola grafos

# cadena de archivos, con directorio y extension
HS = $(MODULOS:%=$(HDIR)/%.hpp)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS = $(MODULOS:%=$(ODIR)/%.o)

PRINCIPAL = main
EJECUTABLE = main

# compilador
CC = g++
# opciones de compilacion
CFLAGS = -Wall -Werror -I$(HDIR) -g

# $@ nombre del archivo de salida u OBJETIVO (izq del :)
# $< primer item de la lista de dependencias
# $^ todas las dependencias (der del :)

$(ODIR)/$(PRINCIPAL).o: $(PRINCIPAL).cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# cada .o depende de su .cpp
$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.hpp
	$(CC) $(CCFLAGS) -c $< -o $@

$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@

# Ejecutables para pruebas parciales
test_grafo:test_grafo.cpp $(OS)
	$(CC) $(CCFLAGS) $^ -o $@

# obtener las salidas
$(TESTDIR)/test_grafo.sal:test_grafo
	./test_grafo > $@

# cada .diff depende de su .out y de su .sal
%.diff: %.out %.sal
	@diff $^ > $@;										\
	if [ $$? -ne 0 ];									\
	then												\
		echo ---- ERROR en TEST_GRAFO ----;				\
	fi
# Con $$? se obtiene el estado de salida del comando anterior. 
# En el caso de `diff', si los dos archivos comparados no son iguales, 
# el estado de la salida no es 0 y en ese caso se imprime el mensaje.   

testing:$(TESTDIR)/test_grafo.diff

# borra binarios
clean_bin:
	@rm -f $(EJECUTABLE) $(ODIR)/$(PRINCIPAL).o $(OS) test_grafo

# borra resultados de ejecución y comparación
clean_test:
		@rm -f $(TESTDIR)/*.sal $(TESTDIR)/*.diff

# borra binarios, resultados de ejecución y comparación, y copias de respaldo
clean: clean_bin clean_test
	@rm -f *~ $(HDIR)/*~ $(CPPDIR)/*~