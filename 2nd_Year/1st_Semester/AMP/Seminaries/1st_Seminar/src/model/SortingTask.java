package model;

import sorter.BubbleSort;
import sorter.QuickSort;

public class SortingTask extends Task {

    private SortingStrategy strategy;

    private int[] nums;

    public SortingTask(String taskID, String descriere, int[] nums) {
        super(taskID, descriere);
        this.nums = nums;
        strategy = SortingStrategy.QuickSort;
    }

    public SortingStrategy getStrategy() {
        return strategy;
    }

    public void setStrategy(SortingStrategy strategy) {
        this.strategy = strategy;
    }

    @Override
    public void execute() {
        if (strategy == SortingStrategy.BubbleSort)
            BubbleSort.sort(nums);
        else if (strategy == SortingStrategy.QuickSort)
            QuickSort.sort(nums, 0, nums.length - 1);
        for (int i : nums)
            System.out.print(String.valueOf(i) + " ");
        System.out.println();
    }
}
