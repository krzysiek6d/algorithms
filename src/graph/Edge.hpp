//
// Created by pawluch on 1/24/19.
//

#ifndef ALGORITHMS_EDGE_H
#define ALGORITHMS_EDGE_H
namespace alg
{
    namespace graph {
        class Edge {
        public:
            Edge(int src, int dst, int cost) : src{src}, dst{dst}, cost{cost} {

            }

            int src;
            int dst;
            int cost;
        };
    }
}
#endif //ALGORITHMS_EDGE_H
