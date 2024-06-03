/* Authors:
Evan Olds / Senior Content Developer / zyBooks
Roman Lysecky / Professor of Electrical and Computer Engineering / Univ.of Arizona
Frank Vahid / Professor of Computer Science and Engineering / Univ.of California, Riverside

February 2024
*/

/*
 * Camden Harris
 * Spring 2024, CS212, William Iverson
 * 06/02/2024
 * Program 10
 * Adjacency List Graph Data Structure
 */

#ifndef ADJACENCYLISTGRAPH_H
#define ADJACENCYLISTGRAPH_H

#include "DirectedGraph.h"
#include "AdjacencyListVertex.h"

class AdjacencyListGraph : public DirectedGraph {
protected:
   std::vector<AdjacencyListVertex*> vertices;
   
public:    
   virtual ~AdjacencyListGraph() {
      for (AdjacencyListVertex* vertex : vertices) {
         delete vertex;
      }
   }

   // simple conversion function to find the ALV equivalent for a given passed in vertex
   AdjacencyListVertex* findEquivalentAdjacencyListVertex(Vertex* baseVertex) {
      for(AdjacencyListVertex* ALVertex : vertices)
         if (baseVertex->GetLabel() == ALVertex->GetLabel()) return ALVertex;
      
      return nullptr;
   }

   // Creates and adds a new vertex to the graph, provided a vertex with the
   // same label doesn't already exist in the graph. Returns the new vertex on
   // success, nullptr on failure.
   virtual Vertex* AddVertex(std::string newVertexLabel) override {
      for(AdjacencyListVertex* vertex : vertices) 
         if (vertex->GetLabel() == newVertexLabel) return nullptr;
      
      vertices.push_back(new AdjacencyListVertex(newVertexLabel));
      return vertices.back();
   }
    
   // Adds a directed edge from the first to the second vertex. If the edge
   // already exists in the graph, no change is made and false is returned.
   // Otherwise the new edge is added and true is returned.
   virtual bool AddDirectedEdge(Vertex* fromVertex, Vertex* toVertex) override {
      AdjacencyListVertex* adjFromVertex = findEquivalentAdjacencyListVertex(fromVertex);
      if(!adjFromVertex) return false;

      AdjacencyListVertex* adjToVertex = findEquivalentAdjacencyListVertex(toVertex);
      if(!adjToVertex) return false;

      for (Vertex* vertex : adjFromVertex->adjacent)
         if (vertex == adjToVertex) return false;

      adjFromVertex->adjacent.push_back(adjToVertex);
      return true;
   }
    
   // Returns a vector of edges with the specified fromVertex.
   virtual std::vector<Edge> GetEdgesFrom(Vertex* fromVertex) override {
      std::vector<Edge> edges;

      AdjacencyListVertex* adjFromVertex = findEquivalentAdjacencyListVertex(fromVertex);
      if(!adjFromVertex) return edges;

      for (Vertex* vertex : adjFromVertex->adjacent) 
         edges.push_back(Edge(adjFromVertex, vertex));

      return edges;
   }
    
   // Returns a vector of edges with the specified toVertex.
   virtual std::vector<Edge> GetEdgesTo(Vertex* toVertex) override {
      std::vector<Edge> edges;

      AdjacencyListVertex* adjToVertex = findEquivalentAdjacencyListVertex(toVertex);
      if(!adjToVertex) return edges;

      for (AdjacencyListVertex* vertex : vertices)
         for (Vertex* adjVertex : vertex->adjacent)
            if (adjVertex->GetLabel() == adjToVertex->GetLabel())
               edges.push_back(Edge(vertex, adjToVertex));

      return edges;
   }
    
   // Returns a vertex with a matching label, or nullptr if no such vertex
   // exists
   virtual Vertex* GetVertex(std::string vertexLabel) override {
      for(AdjacencyListVertex* vertex : vertices ) 
         if (vertex->GetLabel() == vertexLabel) return vertex;
      return nullptr;
   }
    
   // Returns true if this graph has an edge from fromVertex to toVertex
   virtual bool HasEdge(Vertex* fromVertex, Vertex* toVertex) override {
      AdjacencyListVertex* adjFromVertex = findEquivalentAdjacencyListVertex(fromVertex);
      if(!adjFromVertex) return false;

      AdjacencyListVertex* adjToVertex = findEquivalentAdjacencyListVertex(toVertex);
      if(!adjToVertex) return false;

      for(Vertex* vertex : adjFromVertex->adjacent)
         if (vertex->GetLabel() == adjToVertex->GetLabel()) return true;

      return false;
   }
};

#endif