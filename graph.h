/*
* A C++ Graph Library by devzhxpr
*/
#include <vector>
#include <map>
#include <stdexcept>

template<typename _t>
class vertex {
public:
	vertex() {
		value = _t();
		num = 0;
	}
	_t value;
	int num;
	std::vector<int> connected;
	void operator>>(vertex<_t> other) {
		connected.push_back(other.num);
	}
	void operator>>(int other) {
		connected.push_back(other);
	}
	void operator^(vertex<_t>& other) {
		connected.push_back(other.num);
		other.connected.push_back(this->num);
	}
	bool operator>>=(vertex<_t> other) {
		for (auto e : connected) {
			if (other.num == e) {
				return true;
			}
		}
		return false;
	}
	bool operator>>=(int other) {
		for (auto e : connected) {
			if (other == e) {
				return true;
			}
		}
		return false;
	}
};

template<typename _Ty>
class graph {
	std::map<int, vertex<_Ty>> _vertexes;
public:
	graph() {

	}
	void create_vertex(_Ty _value) {

	}
	void create_vertex(int _vertexIdx, _Ty _value) {
		if (_vertexes.find(_vertexIdx) == _vertexes.end()) {
			vertex<_Ty> tmpVertex;
			tmpVertex.value = _value;
			tmpVertex.num = _vertexIdx;
			_vertexes[_vertexIdx] = tmpVertex;
		}
	}
	void single_connect_vertex(int _fVertexIdx, int _sVertexIdx) {
		if (!_vertexes.count(_fVertexIdx) || !_vertexes.count(_sVertexIdx)) {
			throw std::exception();
		}
		_vertexes[_fVertexIdx].connected.push_back(_sVertexIdx);
	}
	void double_connect_vertex(int _fVertexIdx, int _sVertexIdx) {
		if (!_vertexes.count(_fVertexIdx) || !_vertexes.count(_sVertexIdx)) {
			throw std::exception();
		}
		_vertexes[_fVertexIdx].connected.push_back(_sVertexIdx);
		_vertexes[_sVertexIdx].connected.push_back(_fVertexIdx);
	}
	vertex<_Ty>& get_vertex(int _vertexIdx) {
		return _vertexes[_vertexIdx];
	}

	~graph() {

	}
};