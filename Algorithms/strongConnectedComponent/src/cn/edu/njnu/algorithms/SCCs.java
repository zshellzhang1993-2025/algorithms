package cn.edu.njnu.algorithms;

import java.util.HashSet;

public class SCCs {
    public static void main(String[] args) {
        int num = 6;
        Vertex[] vertex = new Vertex[num];
        for (int i = 0; i < num; i++)
            vertex[i] = new Vertex((char) (i + 65));
        int[][] arc = new int[][]{
                new int[]{0, 1, 0, 0, 0, 0},
                new int[]{0, 0, 1, 1, 1, 0},
                new int[]{0, 0, 0, 0, 0, 1},
                new int[]{0, 0, 0, 0, 0, 0},
                new int[]{0, 1, 0, 0, 0, 1},
                new int[]{0, 0, 1, 0, 0, 0}
        };
        Graph g = new Graph(arc, vertex, num);
        g.depthFirstSearch(true);
        g.Linearize();
        g.outputConnector();
        int offset = 0;
        Graph.StrongConnectedComponent scc = g.getSCC();
        HashSet<Vertex> hs;
        while ((hs = scc.nextComponent()) != null) {
            offset++;
            System.out.println("Component" + offset + ":" + hs);
        }
        scc.Reset();
        while ((hs = scc.nextComponent()) != null) {
            offset++;
            System.out.println("Component" + offset + ":" + hs);
        }
    }
}