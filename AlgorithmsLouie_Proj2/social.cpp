// Algorithms Project 2, Social Network Analysis
// Author: Louie Bertoncin

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string GRAPHFILENAME = "graph.txt";

struct Edge {
  string source;
  string target;
  int weight;
};
struct UnVertex {
  vector<Edge> edges;
  string name;
};
struct DVertex {
  vector<Edge> outgoingEdges;
  vector<Edge> incomingEdges;
  string name;
};
struct UnGraph {
  vector<UnVertex> vertices;
};
struct DGraph {
  vector<DVertex> vertices;
};

int makeGraphFromFile(string filename, vector<Edge> &list, UnGraph &unGraph, DGraph &dGraph);
int unweightInDeg(DVertex v, DGraph &dgraph);
int unweightOutDeg(DVertex v);
int weightedInDeg(DVertex v, DGraph &dgraph);
int weightedOutDeg(DVertex v);

void directedDegreeDistribution(DGraph &dgraph, int maxWeight);


int main() {
  UnGraph undirectedGraph;
  DGraph directedGraph;
  vector<Edge> edgeList;
  int maxWeight = makeGraphFromFile(GRAPHFILENAME, edgeList, undirectedGraph, directedGraph);

  directedDegreeDistribution(directedGraph, maxWeight);

  return 0;
}

int makeGraphFromFile(string filename, vector<Edge> &list, UnGraph &unGraph, DGraph &dGraph) {
  int maxWeight = 0;
  ifstream in;
  in.open(filename.c_str());
  string tempSource, tempTarget, tempWeightStr;
  getline(in, tempSource, ',');
  while (!in.eof()){
    getline(in, tempTarget, ',');
    getline(in, tempWeightStr, '\n');
    int tempWeight = atoi(tempWeightStr.c_str());
    if (tempWeight > maxWeight)
      maxWeight = tempWeight;
    Edge tempEdge = {tempSource, tempTarget, tempWeight};
    list.push_back(tempEdge);
    getline(in, tempSource, ',');
  }

  for (int i = 0; i < list.size(); ++i){
    bool sourceExists = false;
    bool targetExists = false;
    for (int j = 0; j < unGraph.vertices.size(); ++j){
      if (list[i].source == unGraph.vertices[j].name)
        sourceExists = true;
      if (list[i].target == unGraph.vertices[j].name)
        targetExists = true;
    }
    if (!sourceExists) {
      UnVertex tempUnVert;
      tempUnVert.edges.push_back(list[i]);
      tempUnVert.name = list[i].source;
      unGraph.vertices.push_back(tempUnVert);
      DVertex tempDVert;
      tempDVert.outgoingEdges.push_back(list[i]);
      tempDVert.name = list[i].source;
      dGraph.vertices.push_back(tempDVert);
    }
    else if (!targetExists) {
      UnVertex tempUnVert;
      tempUnVert.edges.push_back(list[i]);
      tempUnVert.name = list[i].target;
      unGraph.vertices.push_back(tempUnVert);
      DVertex tempDVert;
      tempDVert.incomingEdges.push_back(list[i]);
      tempDVert.name = list[i].source;
      dGraph.vertices.push_back(tempDVert);
    }
  }

  return maxWeight;
}

void directedDegreeDistribution(DGraph &dgraph, int maxWeight) {
  vector<int> unweightedInDegree (maxWeight + 1, 0);
  vector<int> unweightedOutDegree (maxWeight + 1, 0);
  vector<int> weightedInDegree (maxWeight + 1, 0);
  vector<int> weightedOutDegree (maxWeight + 1, 0);

  int maxUnInDegree = 0;
  vector<DVertex> maxUnInDegrees;

  int maxUnOutDegree = 0;
  vector<DVertex> maxUnOutDegrees;

  int maxWeightInDegree = 0;
  vector<DVertex>maxWeightInDegrees;

  int maxWeightOutDegree = 0;
  vector<DVertex>maxWeightOutDegrees;

  for (int i = 0; i < dgraph.vertices.size(); ++i) {
    int tempUnIndegree = unweightInDeg(dgraph.vertices[i], dgraph);
    unweightedInDegree[tempUnIndegree] += 1;
    if (tempUnIndegree > maxUnInDegree) {
      maxUnInDegree = tempUnIndegree;
      maxUnInDegrees.clear();
    }
    if (tempUnIndegree == maxUnInDegree){
      bool found = false;
      for (int j = 0; j < maxUnInDegrees.size(); ++j) {
        if (maxUnInDegrees[j].name == dgraph.vertices[i].name)
          found = true;
      }
      if (!found)
        maxUnInDegrees.push_back(dgraph.vertices[i]);
    }

    int tempUnOutDegree = unweightOutDeg(dgraph.vertices[i]);
    unweightedOutDegree[tempUnOutDegree] += 1;
    if (tempUnOutDegree > maxUnOutDegree) {
      maxUnOutDegree = tempUnOutDegree;
      maxUnOutDegrees.clear();
    }
    if (tempUnOutDegree == maxUnOutDegree)
      maxUnOutDegrees.push_back(dgraph.vertices[i]);

    int tempWeightInDegree = weightedInDeg(dgraph.vertices[i], dgraph);
    weightedInDegree[tempWeightInDegree] += 1;
    if (tempWeightInDegree > maxWeightInDegree) {
      maxWeightInDegree = tempWeightInDegree;
      maxWeightInDegrees.clear();
    }
    if (tempWeightInDegree == maxWeightInDegree) {
      bool found = false;
      for (int j = 0; j < maxWeightInDegrees.size(); ++j) {
        if (maxWeightInDegrees[j].name == dgraph.vertices[i].name)
          found = true;
      }
      if (!found)
        maxWeightInDegrees.push_back(dgraph.vertices[i]);
    }

    int tempWeightOutDegree = weightedOutDeg(dgraph.vertices[i]);
    weightedOutDegree[tempWeightOutDegree] += 1;
    if (tempWeightOutDegree > maxWeightOutDegree) {
      maxWeightOutDegree = tempWeightOutDegree;
      maxWeightOutDegrees.clear();
    }
    if (tempWeightOutDegree == maxWeightOutDegree)
      maxWeightOutDegrees.push_back(dgraph.vertices[i]);
  }


  cout << "\nUnweighted In Degree:" << endl;
  cout << "\tMax: " << maxUnInDegree << endl;
  cout << "\tMax Vertices:" << endl;
  for (int i = 0; i < maxUnInDegrees.size(); ++i) {
    cout << "\t\t" << maxUnInDegrees[i].name << endl;
  }
  cout << "\tDegree Distributions:" << endl;
  for (int i = 0; i < unweightedInDegree.size(); ++i) {
    if (unweightedInDegree[i] > 0)
      cout << "\t\t" << i << ": " << unweightedInDegree[i] << endl;
  }

  cout << "\nUnweighted Out Degree:" << endl;
  cout << "\tMax: " << maxUnOutDegree << endl;
  cout << "\tMax Vertices:" << endl;
  for (int i = 0; i < maxUnOutDegrees.size(); ++i) {
    cout << "\t\t" << maxUnOutDegrees[i].name << endl;
  }
  cout << "\tDegree Distributions:" << endl;
  for (int i = 0; i < unweightedOutDegree.size(); ++i) {
    if (unweightedOutDegree[i] > 0)
      cout << "\t\t" << i << ": " << unweightedOutDegree[i] << endl;
  }

  cout << "\nWeighted In Degree:" << endl;
  cout << "\tMax: " << maxWeightInDegree << endl;
  cout << "\tMax Vertices:" << endl;
  for (int i = 0; i < maxWeightInDegrees.size(); ++i) {
    cout << "\t\t" << maxWeightInDegrees[i].name << endl;
  }
  cout << "\tDegree Distributions:" << endl;
  for (int i = 0; i < weightedInDegree.size(); ++i) {
    if (weightedInDegree[i] > 0)
      cout << "\t\t" << i << ": " << weightedInDegree[i] << endl;
  }

  cout << "\nWeighted Out Degree:" << endl;
  cout << "\tMax: " << maxWeightOutDegree << endl;
  cout << "\tMax Vertices:" << endl;
  for (int i = 0; i < maxWeightOutDegrees.size(); ++i) {
    cout << "\t\t" << maxWeightOutDegrees[i].name << endl;
  }
  cout << "\tDegree Distributions:" << endl;
  for (int i = 0; i < weightedOutDegree.size(); ++i) {
    if (weightedOutDegree[i] > 0)
      cout << "\t\t" << i << ": " << weightedOutDegree[i] << endl;
  }

}

int unweightInDeg(DVertex v, DGraph &dgraph) {
  int total = 0;
  for (int i = 0; i < dgraph.vertices.size(); ++i){
    if (v.name != dgraph.vertices[i].name) {
      for (int j = 0; j < dgraph.vertices[i].outgoingEdges.size(); ++j) {
        if (dgraph.vertices[i].outgoingEdges[j].target == v.name)
          ++total;
      }
    }
  }
  return total;
}

int unweightOutDeg(DVertex v) {
  return v.outgoingEdges.size();
}

int weightedInDeg(DVertex v, DGraph &dgraph) {
  int total = 0;
  for (int i = 0; i < dgraph.vertices.size(); ++i){
    if (v.name != dgraph.vertices[i].name) {
      for (int j = 0; j < dgraph.vertices[i].outgoingEdges.size(); ++j) {
        if (dgraph.vertices[i].outgoingEdges[j].target == v.name)
          total += dgraph.vertices[i].outgoingEdges[j].weight;
      }
    }
  }
  return total;
}

int weightedOutDeg(DVertex v) {
  int total = 0;
  for (int i = 0; i < v.outgoingEdges.size(); ++i)
    total += v.outgoingEdges[i].weight;
  return total;
}

