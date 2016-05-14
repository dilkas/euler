import java.math.BigInteger;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class Euler146 {

    private static final int FIRST_N = 10;
    private static final int N_LIMIT = 150000000;
    private static final int[] NUMBERS = {1, 3, 7, 9, 13, 27};

    // guaranteed to be enough according to Wikipedia
    private static final String[] A = {"2", "3", "5", "7", "11", "13", "17",
                                       "19", "23"};

    // an arbitrary choice
    private static final int N_PRIMES = 10;

    // just to make the code cleaner
    private static final BigInteger ZERO = new BigInteger("0");
    private static final BigInteger ONE = new BigInteger("1");
    private static final BigInteger TWO = new BigInteger("2");

    private static Map<Integer, Set<Integer>> remainders;

    /** A deterministic variant of the Miller-Rabin primality test. */
    private static boolean prime(BigInteger n) {
        if (n.mod(TWO).equals(ZERO))
            return n.equals(TWO);
        BigInteger d = n.subtract(ONE);
        int s = 0;
        while (d.mod(TWO).equals(ZERO)) {
            s++;
            d = d.divide(TWO);
        }
        for (int i = 0; i < A.length; i++) {
            BigInteger a = new BigInteger(A[i]);
            if (a.compareTo(n) >= 0)
                break;
            BigInteger p = a.modPow(d, n);
            if (!p.equals(ONE)) {
                boolean composite = true;
                for (int r = 0; r < s; r++, p = p.modPow(TWO, n)) {
                    if (p.equals(n.subtract(ONE))) {
                        composite = false;
                        break;
                    }
                }
                if (composite)
                    return false;
            }
        }
        return true;
    }

    /** Returns true if n can have remainder r modulus p. */
    private static boolean validRemainder(int r, int p) {
        for (int k : NUMBERS) {
            if ((r * r + k) % p == 0)
                return false;
        }
        return true;
    }

    /** Returns true if n has a valid remainder for each of the first N_PRIMES
        prime numbers. Used to reject impossible n values faster. */
    private static boolean validRemainders(int n) {
        for (Entry<Integer, Set<Integer>> entry : remainders.entrySet()) {
            if (!entry.getValue().contains(n % entry.getKey()))
                return false;
        }
        return true;
    }

    /** Returns true if n satisfies the conditions of the problem. */
    private static boolean valid(int n) {
        BigInteger bigN = new BigInteger(Integer.toString(n));
        BigInteger nSquared = bigN.multiply(bigN);
        for (int k : NUMBERS) {
            if (!prime(nSquared.add(new BigInteger(Integer.toString(k)))))
                return false;
        }
        return !prime(nSquared.add(new BigInteger("19"))) &&
            !prime(nSquared.add(new BigInteger("21")));
    }

    public static void main(String[] args) {
        // generate all possible remainders that n could have modulus the
        // first N_PRIMES prime numbers
        remainders = new HashMap<>();
        for (int p = 2; remainders.size() < N_PRIMES; p++) {
            if (prime(new BigInteger(Integer.toString(p)))) {
                remainders.put(p, new HashSet<Integer>());
                for (int r = 0; r < p; r++) {
                    if (validRemainder(r, p))
                        remainders.get(p).add(r);
                }
            }
        }

        int sum = 0;
        for (int n = FIRST_N; n < N_LIMIT; n++) {
            if (validRemainders(n) && valid(n))
                sum += n;
        }
        System.out.println(sum);
    }
}
