; keys - numbers from 1 to 6, that represent different types - 2 (makes
; further calculations easier)
; values - lists (P, n) where:
; P - the first four-digit number of that type
; n - its index in the sequence (required for calculations)
(define starts (make-hash-table))

; for each number stores a list of numbers that can go after that number
(define following (make-hash-table))

; p - the first number (as int)
; n - its index
; type - its type-2
(define (generate-numbers-of-type p n type)
  (if (< p 10000)
      (cons (list p (+ type 2))
            (generate-numbers-of-type (+ p (* type n) 1) (+ n 1) type))
      '()))

; call with type = 1 to generate all considerable numbers
(define (generate-all-numbers type)
  (if (< type 7)
      (let ((start (hash-table-ref starts type)))
        (append (generate-numbers-of-type (car start) (cadr start) type)
                (generate-all-numbers (+ type 1))))
      '()))

(define (cycle? a b)
  (equal? (remainder (car a) 100) (quotient (car b) 100)))

(define (different-types? a b)
  (not (equal? (cadr a) (cadr b))))

(define (all-types-different? e l)
  (if (null? l)
      #t
      (and (different-types? e (car l))
           (all-types-different? e (cdr l)))))

(define (add-following a b)
  (if (and (cycle? a b)
           (different-types? a b))
      (hash-table-set! following a
                       (cons b (hash-table-ref following a list)))))

(define (add-to-following e l)
  (for-each (lambda (x)
              (add-following e x))
            l))

(define (consider candidates set)
  (let ((candidate (car candidates))
        (last (car set)))
    (if (and (cycle? last candidate)
             (all-types-different? candidate set))
        (let ((possibility (find-next-number
                            (hash-table-ref following candidate list)
                            (cons candidate set))))
          (if (null? possibility)
              (find-next-number (cdr candidates) set)
              possibility))
        (find-next-number (cdr candidates) set))))

(define (find-next-number candidates set)
  (cond ((and (equal? (length set) 6)
              (cycle? (car set) (last set)))
         set)
        ((null? candidates) '())
        (else (consider candidates set))))

; for each element e in list l:
;   if we find a set starting with e, return it
(define (consider-starting-numbers l)
  (if (null? l)
      '()
      (let* ((e (car l))
             (r (find-next-number (hash-table-ref following e) (list e))))
        (if (null? r)
            (consider-starting-numbers (cdr l))
            r))))

(define (euler61)
  (hash-table-set! starts 1 '(1035 45))
	(hash-table-set! starts 2 '(1024 32))
	(hash-table-set! starts 3 '(1001 26))
	(hash-table-set! starts 4 '(1035 23))
	(hash-table-set! starts 5 '(1071 21))
	(hash-table-set! starts 6 '(1045 19))
  (let ((numbers (generate-all-numbers 1)))
    (for-each (lambda (x)
                (add-to-following x numbers))
              numbers)
    (apply + (map car (consider-starting-numbers
                       (hash-table-keys following))))))
