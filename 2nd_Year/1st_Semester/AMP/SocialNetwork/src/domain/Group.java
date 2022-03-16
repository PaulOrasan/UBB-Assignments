package domain;

import java.util.*;

public class Group {

    private Map<Long, List<Long>> adj;
    private Set<Long> visited;

    public Group() {
        adj = new HashMap<>();
        visited = new HashSet<>();
    }

    /**
     * Adds a new node to the group
     * @param node - Long value which describes the node
     * @param neighbours - List which describes the neighbours
     */
    public void addNode(Long node, List<Long> neighbours) {
        adj.put(node, neighbours);
    }

    /**
     * Finds all nodes of this group
     * @return a list of all nodes
     */
    public Iterable<Long> getUsers() {
        return adj.keySet();
    }

    private int parseGroup(Long node) {
        int distance, maximum = 0;
        visited.add(node);
        for (Long neighbour : adj.get(node)) {
            if (!visited.contains(neighbour)){
                distance = 1 + parseGroup(neighbour);
                if (distance > maximum)
                    maximum = distance;
            }
        }
        visited.remove(node);
        return maximum;
    }

    /**
     * Finds the length of the longest path in the group
     * @return integer
     */
    public int getLongestLength() {
        int maximum = 0;
        for (Long node : adj.keySet()) {
            int distance = parseGroup(node);
            if (distance > maximum)
                maximum = distance;
        }
        return maximum;
    }
}
