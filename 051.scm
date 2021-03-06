; A constant, basically just a guess how many digits we'll need
(define number-of-digits 6)
; How many primes in a group we need (later change to 8)
(define value 8)
; Size of the vector so that every considerable prime could be an index
(define vector-size (expt 10 number-of-digits))
; Vector to check for primality
(define prime (make-vector vector-size #t))

; Marks off multiples of p, starting with n, doesn't return anything
(define (inner-sieve n p)
  (if (>= n vector-size)
      '()
      (begin (vector-set! prime n #f)
	     (inner-sieve (+ n p) p))))

; Finds the smallest prime >= p
(define (find-next-prime p)
  (cond ((>= p vector-size) '())
	((vector-ref prime p) p)
	(#t (find-next-prime (+ p 1)))))

; Performs Sieve of Eratosthenes on the prime vector, starts with prime p
(define (outer-sieve p)
  (if (null? p)
      '()
      (begin (inner-sieve (+ p p) p)
             (outer-sieve (find-next-prime (+ p 1))))))

; Converts a number into a list of digits
(define (number->list n)
  (map char->digit (string->list (number->string n))))

; Converts a list of digits into a number, n = 0
(define (list->number l n)
  (if (null? l)
      n
      (list->number (cdr l) (+ n (* (car l) (expt 10 (- (length l) 1)))))))

; Adds d as the first element to every list in l
(define (helper d l)
  (map (lambda (x) (cons d x)) l))

; Generates all possible masks based on n by
; replacing all subsets of d by -1
(define (main-generator n d)
  (let ((first (car n)))
    (if (= (length n) 1)
        (if (= first d)
            (list (list -1) (list d))
            (list n))
        (let* ((recursive-tail (main-generator (cdr n) d))
               (not-masked (helper first recursive-tail)))
          (if (= first d)
              (append not-masked (helper -1 recursive-tail))
              not-masked)))))

; Returns a list of all possible masks for n, d = 0
(define (generate-masks n d)
  (let ((l (main-generator n d)))
    (if (> d 9)
	'()
	(append l (generate-masks n (+ d 1))))))

; Returns a 1 instead of true
(define (prime? p)
  (if (vector-ref prime (list->number p 0))
      1
      0))

; Changes all -1's to d's in the list
(define (evaluate m d)
  (define (change-digit x)
    (if (= x -1)
	d
	x))
  (map change-digit m))

(define (not-a-mask? m)
  (not (find (lambda (x) (= x -1)) m)))

; A helper function for evaluate-mask
(define (count-primes m d)
  (cond ((not-a-mask? m) (prime? m))
        ((> d 9) 0)
        (#t (+ (count-primes m (+ d 1)) (prime? (evaluate m d))))))

; Returns the number of primes satisfying the mask
(define (evaluate-mask m)
  (if (= (car m) -1)
      (count-primes m 1)
      (count-primes m 0)))

; Returns the maximum number of primes that satisfy any one of the masks
(define (check-masks l)
  (apply max (map evaluate-mask l)))

; Returns the smallest number which has a group of 'value', n - starting value
(define (go-through-numbers n)
  (cond ((>= n vector-size) '())
	((and (vector-ref prime n)
	      (>= (check-masks (generate-masks (number->list n) 0)) value)) n)
	(#t (go-through-numbers (+ n 1)))))

(define (euler51)
  (outer-sieve 2)
  (go-through-numbers (expt 10 (- number-of-digits 1))))
