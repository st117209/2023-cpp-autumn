#include<iostream>

struct SEdge {
	int a;
	int b;
	int w;
	SEdge(int a = 0, int b = 0, int w = 1) : a(a), b(b), w(w) {}
	SEdge(const SEdge& src) : a(src.a), b(src.b), w(src.w) {}
	~SEdge() {}
	void set(int a, int b, int w)
	{
		this->a = a;
		this->b = b;
		this->w = w;
	}
	friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
};

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();

	///выводит матрицу смежности графа
	void PrintMatrix();
	///выводит дуги графа
	void PrintEdges();
	///считывает матрицу смежности графа
	void ReadMatrix(int vertexes, std::istream& stream);
	///считывает дуги графа
	void ReadEdges(int edges, std::istream& stream, bool haveweight = false);
	///количество дуг
	int EdgesCnt();
	///количество путей 
	int RoadsCnt();
	///количество вершин
	int VertexCnt();

	void ReadColor(int vertexes, std::istream& stream);
	void task(int vertexes);


private:
	///создает матрицу смежности n*n и матрицу с дугами размера m
	void init();
	///создает матрицу смежности _vertexes*_vertexes
	void initMatrix();
	///создает матрицу с дугами размера _edges
	void initEdges();
	void initMatrixFromEdges();
	void initEdgesFromMatrix();
	int getVertexesCountFromEdges();
	int getEdgesCountFromMatrix();
	///удаляет матрицу смежности и матрицу с дугами
	void dispose();
	///удаляет матрицу смежности
	void disposeMatrix();
	///удаляет матрицу с дугами
	void disposeEdges();
	///удаляет множество цветов
	void disposeColor();



	int _vertexes;
	int _edges;
	int** _matrix;
	SEdge* _edge;
	int* _color;
};

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	CGraph g(n, n);
	g.ReadMatrix(n, std::cin);
	g.ReadColor(n, std::cin);
	g.task(n);
	return EXIT_SUCCESS;
}


///Конструкторы 
CGraph::CGraph()
	: _vertexes(0), _edges(0), _matrix(nullptr), _edge(nullptr) {}

CGraph::CGraph(int vertexes, int edges)
	: _vertexes(vertexes), _edges(edges), _matrix(nullptr), _edge(nullptr)
{
	init();
}

CGraph::~CGraph()
{
	dispose();
}

///Деструкторы
void CGraph::dispose()
{
	disposeMatrix();
	disposeEdges();
	disposeColor();
}

void CGraph::disposeMatrix()
{
	if (_matrix != nullptr)
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			delete[] _matrix[i];
		}
		delete[] _matrix;
		_matrix = nullptr;
	}
}

void CGraph::disposeEdges()
{
	if (_edge != nullptr)
	{
		delete[] _edge;
		_edge = nullptr;
	}
}

void CGraph::disposeColor()
{
	if (_color != nullptr)
	{
		delete[] _color;
		_color = nullptr;
	}
}

///Фукнкции
void CGraph::init()
{
	dispose();
	initMatrix();
	initEdges();
}

void CGraph::PrintMatrix()
{
	if (_matrix == nullptr)
	{
		if (_edge == nullptr)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initMatrixFromEdges();
	}
	for (int i = 1; i < _vertexes; ++i)
	{
		for (int j = 1; j < _vertexes; ++j)
		{
			std::cout << _matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CGraph::initMatrix()
{
	if (_vertexes == 0)
	{
		return;
	}
	_matrix = new int* [_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_matrix[i] = new int[_vertexes] { 0 };
	}
}

void CGraph::initMatrixFromEdges()
{
	disposeMatrix();
	_vertexes = getVertexesCountFromEdges();
	initMatrix();
	for (int i = 0; i < _edges; ++i)
	{
		_matrix[_edge[i].a][_edge[i].b] = _edge[i].w;
	}
}

int CGraph::getVertexesCountFromEdges()
{
	int res = 0;
	for (int i = 0; i < _edges; ++i)
	{
		res = (res > _edge[i].a ? res : _edge[i].a);
		res = (res > _edge[i].b ? res : _edge[i].b);
	}
	return res + 1;
}

void CGraph::PrintEdges()
{
	if (_edge == nullptr)
	{
		if (_matrix == nullptr)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initEdgesFromMatrix();
	}
	for (int i = 0; i < _edges; ++i)
	{
		std::cout << _edge[i] << std::endl;
	}
}

void CGraph::initEdgesFromMatrix()
{
	disposeEdges();
	_edges = getEdgesCountFromMatrix();
	initEdges();
	for (int i = 0, k = 0; i < _vertexes && k < _edges; ++i)
	{
		for (int j = 0; j < _vertexes && k < _edges; ++j)
		{
			if (_matrix[i][j] != 0)
			{
				_edge[k++].set(i + 1, j + 1, _matrix[i][j]);
			}
		}
	}
}

int CGraph::getEdgesCountFromMatrix()
{
	int count = 0;
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			count += (_matrix[i][j] != 0);
		}
	}
	return count;
}

void CGraph::initEdges()
{
	if (_edges == 0)
	{
		return;
	}
	_edge = new SEdge[_edges];
}

void CGraph::ReadMatrix(int vertexes, std::istream& stream)
{
	_vertexes = vertexes;
	initMatrix();
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			stream >> _matrix[i][j];
		}
	}
	initEdgesFromMatrix();
}

void CGraph::ReadEdges(int edges, std::istream& stream, bool haveweight)
{
	_edges = edges;
	initEdges();
	for (int i = 0; i < _edges; ++i)
	{
		stream >> _edge[i].a >> _edge[i].b;
		if (haveweight)
		{
			stream >> _edge[i].w;
		}
	}
	initMatrixFromEdges();
}

std::ostream& operator<<(std::ostream& stream, const SEdge& edge)
{
	stream << edge.a << " " << edge.b;
	if (edge.w > 1)
	{
		stream << " " << edge.w;
	}
	return stream;
}

int CGraph::EdgesCnt() {
	if (_edge == nullptr)
	{
		initEdgesFromMatrix();
	}
	return _edges;
}

int CGraph::RoadsCnt()
{
	return EdgesCnt() / 2;
}

int CGraph::VertexCnt()
{
	if (_matrix == nullptr)
	{
		initMatrixFromEdges();
	}
	return _vertexes;
}

void CGraph::ReadColor(int vertexes, std::istream& stream)
{
	_color = new int[vertexes];
	for (int i = 0; i < vertexes; ++i)
	{
		stream >> _color[i];
	}

}

void CGraph::task(int vertexes)
{

	int c = 0;

	for (int i = 0; i < vertexes; i++)
	{
		for (int j = 0; j < vertexes; j++)
		{
			if (i < j) 
			{ 
				break; 
			}
			else
			{
				if (_color[i] != _color[j])
				{
					if (_matrix[i][j] == 1)
					{
						c++;
					}
				}
			}
		}
	}

	std::cout << c ;
}