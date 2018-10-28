import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class CutRod {

  static int max(int a, int b) {
    return a > b ? a : b;
  }

  static int cutRod(int[] p, int n) {

    if (n == -1) {
      return 0;
    }

    int maxCut = Integer.MIN_VALUE;

    for (int i = 0; i <= n; i++) {
      maxCut = max(maxCut, p[i] + cutRod(p, n - i - 1));
    }

    return maxCut;
  }

  static int cutRodMemoized(int[] p, int n, Map<Integer, Integer> memo) {

    if (memo.containsKey(n))
      return memo.get(n);

    int maxCut = Integer.MIN_VALUE;

    if (n == -1) {
      maxCut = 0;
    } else {
      for (int i = 0; i <= n; i++) {
        maxCut = max(maxCut, p[i] + cutRodMemoized(p, n - i - 1, memo));
      }
    }
    memo.put(n, maxCut);
    return maxCut;
  }

  static int cutRodBottomUp(int[] p, int n) {
    int arr_size = n + 2;
    int[] r = new int[arr_size];
    r[0] = 0;
    int max_int;
    for (int i = 0; i <= n; i++) {
      max_int = Integer.MIN_VALUE;
      for (int j = 0; j <= i; j++) {
        max_int = max(max_int, p[j] + r[i - j]);
      }
      r[i + 1] = max_int;
    }
    return r[arr_size - 1];
  }

  public static void main(String[] args) {

    int prices[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 1, 5, 8, 9, 10, 17, 17, 20,
        24, 30, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
    long startTime = System.currentTimeMillis();
    System.out.println("Max price: " + cutRod(prices, 31));
    System.out.println("Time taken: " + (System.currentTimeMillis() - startTime) / 1000.0);

    Map<Integer, Integer> memo = new HashMap<>();
    startTime = System.currentTimeMillis();
    System.out.println("Max price(Memoized): " + cutRodMemoized(prices, 31, memo));
    System.out.println("Time taken: " + (System.currentTimeMillis() - startTime) / 1000.0);

    startTime = System.currentTimeMillis();
    System.out.println("Max price(Bottom up): " + cutRodBottomUp(prices, 31));
    System.out.println("Time taken: " + (System.currentTimeMillis() - startTime) / 1000.0);

  }

}