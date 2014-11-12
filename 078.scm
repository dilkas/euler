(define M 1000000)

(define q (make-hash))

(define (qsum n k i)
  (if (= i (+ (- n k) 1))
      0
      (mod (+ (hash-ref q '((- n i) (- k 1)))
	      (qsum n k (+ i 1)))
	   M)))

(define (p n k)
  (if (> k n)
      0
      (+ (hash-ref q '(n k))
	 (p n (+ k 1)))))

(define (generate-line n k)
  (if (> k n)
      '()
      (begin (hash-set! q '(n k) (qsum n k (quotient n k)))
	     (generate-line n (+ k 1)))))

(define (magic n)
  (generate-line n 1)
  (if (= (p n 1) 0)
      n
      (magic (+ n 1))))

(define (euler78)
  (magic 1))
