# Nome do compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -std=c++23 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Arquivos fonte e o nome do executável
SRCS = main.cpp player.cpp ball.cpp game_controller.cpp
TARGET = prog

# Geração de arquivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regra padrão
all: $(TARGET)



# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(CXXFLAGS)

# Regra para criar arquivos objeto
%.o: %.cpp
	$(CXX) -c $< -o $@

# Regra para limpar arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)
