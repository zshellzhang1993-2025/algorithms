package cn.edu.njnu.algorithms;

public class Vertex implements Comparable<Object> {

    private int postClock;
    private int connector;
    private char name;

    @Override
    public int compareTo(Object o) {
        if (o != null && o instanceof Vertex) {
            Vertex v = (Vertex) o;
            if (postClock <= v.postClock) {
                return 1;
            } else {
                return -1;
            }
        } else
            return -1;
    }

    @Override
    public String toString() {
        return "" + name;
    }

    public Vertex(){

    }

    public Vertex(char name) {
        this.name = name;
    }

    public char getName() {
        return name;
    }

    public void setName(char name) {
        this.name = name;
    }

    public void setClock(int clock) {
        this.postClock = clock;
    }

    public int getClock() {
        return postClock;
    }

    public void setConnector(int connector) {
        this.connector = connector;
    }

    public int getConnector() {
        return connector;
    }
}