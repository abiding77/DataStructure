#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct vertex {
	int vertexId;
	int matrixId;
	vertex* prev;
	vertex* next;

	vertex() {
		vertexId = matrixId = -1;
		prev = next = NULL;
	}
	vertex(int vertexId) {
		this->vertexId = vertexId;
		matrixId = -1;
		prev = next = NULL;
	}
};

struct edge {
	vertex* src;
	vertex* dst;
	edge* prev;
	edge* next;
	edge() {
		src = dst = NULL;
		prev = next = NULL;
	}
	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
		prev = next = NULL;
	}
};

class vertexList {
private:
	vertex* header;
	vertex* trailer;
public:
	vertexList() {
		header = new vertex();
		trailer = new vertex();
		header->next = trailer;
		header->matrixId = -1;
		trailer->prev = header;
	}
	void insertVertex(vertex* newVertex) {
		newVertex->prev = trailer->prev;
		newVertex->next = trailer;
		newVertex->matrixId = trailer->prev->matrixId + 1;
		trailer->prev->next = newVertex;
		trailer->prev = newVertex;
	}
	void eraseVertex(vertex* delVertex) {
		for (vertex* cur = delVertex; cur != trailer; cur = cur->next) {
			cur->matrixId--;
		}
		delVertex->prev->next = delVertex->next;
		delVertex->next->prev = delVertex->prev;
		delete delVertex;
	}
	vertex* findVertex(int vertexId) {
		for (vertex* cur = header->next; cur != trailer; cur = cur->next) {
			if (cur->vertexId == vertexId) {
				return cur;
			}
		}
		return NULL;
	}

};

class edgeList {
private:
	edge* header;
	edge* trailer;
public:
	edgeList() {
		header = new edge();
		trailer = new edge();
		header->next = trailer;
		trailer->prev = header;
	}
	void insertEdge(edge* newEdge) {
		newEdge->prev = trailer->prev;
		newEdge->next = trailer;
		trailer->prev->next = newEdge;
		trailer->prev = newEdge;
	}
	void eraseEdge(edge* delEdge) {
		delEdge->prev->next = delEdge->next;
		delEdge->next->prev = delEdge->prev;
		delete delEdge;
	}
};

class graph {
private:
	vector<vector<edge*>> edgeMatrix;
	vertexList vList;
	edgeList eList;
public:
	void insertVertex(int vertexId) {
		if (vList.findVertex(vertexId) != NULL) {
			return;
		}
		vertex* newVertex = new vertex(vertexId);
		for (int i = 0; i < edgeMatrix.size(); i++) {
			edgeMatrix[i].push_back(NULL);
		}
		edgeMatrix.push_back(vector<edge*>(edgeMatrix.size() + 1, NULL));
		vList.insertVertex(newVertex);
	}
	void eraseVertex(int vertexId) {
		vertex* delVertex = vList.findVertex(vertexId);
		if (delVertex == NULL) {
			return;
		}
		int matrixId = delVertex->matrixId;
		for (int i = 0; i < edgeMatrix.size(); i++) {
			if (i != matrixId) {
				if (edgeMatrix[i][matrixId] != NULL) {
					eList.eraseEdge(edgeMatrix[i][matrixId]);
				}
				edgeMatrix[i].erase(edgeMatrix[i].begin() + matrixId);
			}
		}
		edgeMatrix.erase(edgeMatrix.begin() + matrixId);
		vList.eraseVertex(delVertex);
	}
	void insertEdge(int srcVertexId, int dstVertexId) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);
		if (src == NULL || dst == NULL) {
			return;
		}
		int srcMatrixId = src->matrixId;
		int dstMatrixId = dst->matrixId;

		if (edgeMatrix[srcMatrixId][dstMatrixId] != NULL || edgeMatrix[dstMatrixId][srcMatrixId] != NULL) {
			cout << "Exist" << endl;
			return;
		}
		edge* newEdge = new edge(src, dst);
		eList.insertEdge(newEdge);
		edgeMatrix[srcMatrixId][dstMatrixId] = edgeMatrix[dstMatrixId][srcMatrixId] = newEdge;
	}
	void eraseEdge(int srcVertexId, int dstVertexId) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);
		if (src == NULL || dst == NULL) {
			return;
		}
		int srcMatrixId = src->matrixId;
		int dstMatrixId = dst->matrixId;

		if (edgeMatrix[srcMatrixId][dstMatrixId] == NULL || edgeMatrix[dstMatrixId][srcMatrixId] == NULL) {
			cout << "None" << endl;
			return;
		}
		eList.eraseEdge(edgeMatrix[srcMatrixId][dstMatrixId]);
		edgeMatrix[srcMatrixId][dstMatrixId] = edgeMatrix[dstMatrixId][srcMatrixId] = NULL;
	}
	/*void sumAdjacentNode(int vertexId) {
		int sumVertexId = 0;
		for (int i = 0; i < edgeMatrix.size(); i++) {
			if (vList.findVertex(vertexId) == NULL) {
				cout << "None" << endl;
				return;
			}
			sumVertexId += vList.findVertex(vertexId)->vertexId;
		}
		cout << sumVertexId << endl;
	}*/
};

int main() {
	int testcase = 0;
	int vertexNum = 0;
	cin >> testcase >> vertexNum;
	graph g;
	for (int i = 0; i < vertexNum; i++) {
		int a;
		cin >> a;
		g.insertVertex(a);
	}
	for (int k = 0; k < testcase; k++) {
		string s;
		cin >> s;
		if (s == "insertEdge") {
			int num1, num2;
			cin >> num1 >> num2;
			g.insertEdge(num1, num2);
		}
		if (s == "eraseEdge") {
			int num1, num2;
			cin >> num1 >> num2;
			g.eraseEdge(num1, num2);
		}
		/*if (s == "SumAdjacentNode") {
			int num1;
			cin >> num1;
			g.sumAdjacentNode(num1);
		}*/
	}
	return 0;
}