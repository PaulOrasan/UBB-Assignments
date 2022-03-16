package domain;

import java.util.*;

public class Network {

    private Map<Long, List<Long>> adj;
    private List<Group> components;

    private Set<Long> visited;

    public Network() {
        adj = new HashMap<>();
        components = new ArrayList<>();
        visited = new HashSet<>();
    }

    /**
     * Adds a new node to the network
     * @param node - Long value which describes the node
     * @param neighbours - List which describes the neighbours
     */
    public void addNode(Long node, List<Long> neighbours) {
        adj.put(node, neighbours);
    }

    private void setComponents() {
        for (Long node : adj.keySet()) {
            if (!visited.contains(node)) {
                Group group = new Group();
                Queue<Long> q = new LinkedList<>();
                q.add(node);
                while (!q.isEmpty()) {
                    Long container = q.remove();
                    visited.add(container);
                    group.addNode(container, adj.get(container));
                    for (Long neighbour : adj.get(container)) {
                        if (!visited.contains(neighbour)) {
                            q.add(neighbour);
                        }
                    }
                }
                components.add(group);
            }
        }
    }

    /**
     * Finds the number of groups inside the network
     * @return integer which describes the number of groups
     */
    public int getNumberGroups() {
        setComponents();
        return components.size();
    }

    /**
     * Finds the most sociable community inside the network
     * @return Group object which represents the best group
     *          null if the network has no nodes
     */
    public Group getBestGroup() {
        setComponents();
        if (components.size() == 0)
            return null;
        int maximum = 0;
        Group maximumGroup = components.get(0);
        for (Group group : components) {
            int length = group.getLongestLength();
            if (length > maximum) {
                maximum = length;
                maximumGroup = group;
            }
        }
        return maximumGroup;
    }
}
