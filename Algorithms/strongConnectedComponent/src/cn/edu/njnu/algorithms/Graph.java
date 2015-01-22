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

    public Graph() {
    }

    public Graph(int[][] arc, Vertex[] vertex, int n) {
        this.connector = 0;
        this.clock = 0;
        this.num = n;
        this.vertex = new Vertex[n];
        for (int i = 0; i < num; i++)
            this.vertex[i].setName(vertex[i].getName());
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

    public void DFS(boolean printVertex) {                //depth first search
        for (int i = 0; i < num; i++) {
            if (!visited[i])
                connector++;
            explore(i, printVertex);
        }
        if (printVertex)
            System.out.println();
    }

    public void Linearize() {
        Reset();
        DFS(false);
        Vertex[] t_vertex = new Vertex[num];
        for (int i = 0; i < num; i++) {
            t_vertex[i].setClock(vertex[i].getClock());
            t_vertex[i].setName(vertex[i].getName());
        }
        Arrays.sort(t_vertex);
        for (int i = 0; i < num; i++)
            System.out.print(' ' + t_vertex[i].getName());
    }

    public void Reset() {
        this.clock = 0;
        this.connector = 0;
        for (int i = 0; i < num; i++)
            visited[i] = false;
    }

    private void explore(int v, boolean printVertex) {
        if (printVertex)
            System.out.print(' ' + vertex[v].getName());
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

    public StrongConnectedComponent getSCC() {
        return new StrongConnectedComponent();
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
            HashSet<Integer> set = new HashSet<Integer>();
            for (int i = 0; i < num; i++)
                visited[i] = false;
            if (!explore(Linearize(), set))
                return null;
            Object[] temp = set.toArray();
            for (int element : set) {
                int k = (Integer) temp[element];
                deleted[k] = true;                      //delete the vertex of the SCC to be output
                for (int i = 0; i < num; i++)
                    arc[element][i] = 0;                //delete the edges which belong to the SCC
            }
            return set;
        }

        private boolean explore(int v, HashSet<Integer> set) {
            if (v == -1)
                return false;
            visited[v] = true;
            set.add(v);
            for (int i = 0; i < num; i++) {
                if (arc[v][i] == 1 && !visited[i])
                    explore(i, set);
            }
            return true;
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
            Graph.this.connector = 0;
            System.arraycopy(visited, 0, deleted, 0, num);
            DFS(false);
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
            int temp = array[0];
            while (i++ < num) {
                if (temp < array[i])
                    temp = array[i];
            }
            return temp;
        }
    }
}