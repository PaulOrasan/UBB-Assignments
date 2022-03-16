package sorter;

public class BubbleSort {

    private BubbleSort() {}

    public static void sort(int[] nums) {
        boolean ok;
        do {
            ok = true;
            for (int i = 0; i < nums.length - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    int aux = nums[i];
                    nums[i] = nums[i + 1];
                    nums[i + 1] = aux;
                    ok = false;
                }
            }
        } while(!ok);
    }
}
