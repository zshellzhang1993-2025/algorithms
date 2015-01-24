package cn.edu.njnu.algorithms;

import java.util.Arrays;
import java.util.HashSet;

public class Graph {

    private Vertex[] vertex;
    private boolean[] visited;
    private int[][] arc;
    private int clock;
    private int connector;
    private int num;

    public Graph(int[][] arc, Vertex[] vertex, int n) {
        this.connector = 0;
        this.clock = 0;
        this.num = n;
        this.vertex = new Vertex[n];
        for (int i = 0; i < num; i++)
            this.vertex[i] = new Vertex(vertex[i].getName());
        this.visited = new boolean[n];
        for (int i = 0; i < num; i++) {
            visited[i] = false;
        }
        this.arc = new int[num][];
        for (int i = 0; i < num; i++)
            this.arc[i] = new int[num];
        for (int i = 0; i < num; i++)
            for (int j = 0; j < num; j++) {
                this.arc[i][j] = arc[i][j];
            }
    }

    public void depthFirstSearch(boolean printVertex) {
        Reset();
        DFS(printVertex);
    }

    public void Linearize() {               //Linearization of directed acyclic graphs
        Reset();
        DFS(false);
        Vertex[] t_vertex = new Vertex[num];
        for (int i = 0; i < num; i++) {
            t_vertex[i] = new Vertex();
            t_vertex[i].setClock(vertex[i].getClock());
            t_vertex[i].setName(vertex[i].getName());
        }
        Arrays.sort(t_vertex);
        System.out.print("Linearize:");
        for (int i = 0; i < num; i++)
            System.out.print(" " + t_vertex[i].getName());
        System.out.println();
    }

    public void outputConnector() {
        HashSet<Vertex>[] set = new HashSet[connector];
        for (int i = 0; i < set.length; i++)
            set[i] = new HashSet<Vertex>();
        for (Vertex v : vertex)
            set[v.getConnector() - 1].add(v);
        int offset = 0;
        for (HashSet<Vertex> hs : set) {
            offset++;
            System.out.println("Connector" + offset + ":" + hs);
        }
    }

    public StrongConnectedComponent getSCC() {
        return new StrongConnectedComponent();
    }

    private void Reset() {
        this.clock = 0;
        this.connector = 0;
        for (int i = 0; i < num; i++)
            visited[i] = false;
        for (int i = 0; i < num; i++) {
            vertex[i].setClock(0);
            vertex[i].setConnector(0);
        }
    }

    private void DFS(boolean printVertex) {
        if (printVertex)
            System.out.print("DFS:");
        for (int i = 0; i < num; i++) {
            if (!visited[i]) {
                connector++;
                explore(i, printVertex);
            }
        }
        if (printVertex)
            System.out.println();
    }

    private void explore(int v, boolean printVertex) {
        if (printVertex)
            System.out.print(" " + vertex[v].getName());
        visited[v] = true;
        vertex[v].setConnector(connector);
        clock++;
        for (int i = 0; i < num; i++) {
            if (arc[v][i] == 1 && !visited[i])
                explore(i, printVertex);
        }
        clock++;
        postVisit(v);
    }

    private void postVisit(int v) {
        vertex[v].setClock(clock);
    }

    public class StrongConnectedComponent {

        private int[][] arc;
        private boolean[] deleted;

        public StrongConnectedComponent() {
            deleted = new boolean[num];
            for (boolean d : deleted)
                d = false;
            this.arc = new int[num][];
            for (int i = 0; i < num; i++)
                this.arc[i] = new int[num];
            for (int i = 0; i < num; i++)
                for (int j = 0; j < num; j++) {
                    this.arc[j][i] = Graph.this.arc[i][j];
                }
        }

        public HashSet nextComponent() {
            HashSet<Vertex> set = new HashSet<Vertex>();
            int v = Linearize();
            if (v == -1)
                return null;
            System.arraycopy(deleted, 0, visited, 0, num);
            explore(v, set);
            Object[] temp = set.toArray();
            for (int i = 0; i < temp.length; i++) {
                Vertex vt = (Vertex) temp[i];
                int k = (int) (vt.getName()) - 65;
                deleted[k] = true;                      //delete the vertex of the SCC to be output
            }
            return set;
        }

        private void DFS() {
            for (int i = 0; i < num; i++) {
                if (!visited[i])
                    explore(i);
            }
        }

        private void explore(int v) {
            visited[v] = true;
            clock++;
            for (int i = 0; i < num; i++) {
                if (arc[v][i] == 1 && !visited[i])
                    explore(i);
            }
            clock++;
            postVisit(v);
        }

        private void explore(int v, HashSet<Vertex> set) {
            visited[v] = true;
            set.add(vertex[v]);
            for (int i = 0; i < num; i++) {
                if (Graph.this.arc[v][i] == 1 && !visited[i])
                    explore(i, set);
            }
        }

        public void Reset() {
            for (int i = 0; i < num; i++)
                deleted[i] = false;
            for (int i = 0; i < num; i++)
                for (int j = 0; j < num; j++) {
                    this.arc[j][i] = Graph.this.arc[i][j];
                }
        }

        private int Linearize() {
            Graph.this.clock = 0;
            for (int i = 0; i < num; i++)
                Graph.this.vertex[i].setClock(0);
            System.arraycopy(deleted, 0, visited, 0, num);
            DFS();
            return Order();
        }

        private int Order() {
            int[] array = new int[num];
            boolean flag = false;
            for (int i = 0; i < num; i++) {
                if (deleted[i])
                    array[i] = 0;
                else {
                    array[i] = vertex[i].getClock();
                    flag = true;
                }
            }
            if (!flag)
                return -1;
            int i = 0;
            int temp = 0;
            while (++i < num) {
                if (array[temp] < array[i])
                    temp = i;
            }
            return temp;
        }
    }
}