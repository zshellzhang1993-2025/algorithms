package cn.edu.njnu.algorithms;

public class SCCs {
    public static void main(String[] args) {
        Graph g = new Graph();
        g.Linearize();
        Graph.StrongConnectedComponent scc = g.getSCC();
        scc.nextComponent();
    }
}