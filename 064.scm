(define N 10000)

(define (iterate m d a i S table)
  (let ((tuple (list m d a)))
    (if (hash-table-exists? table tuple)
        (remainder (- i (hash-table-ref table tuple)) 2)
        (let* ((new-m (- (* d a) m))
               (new-d (/ (- S (expt new-m 2)) d))
               (new-a (floor (/ (+ (sqrt S) new-m) new-d))))
          (hash-table-set! table tuple i)
          (iterate new-m new-d new-a (+ i 1) S table)))))

(define (wrapper x)
  (let ((root (sqrt x))
        (table (make-hash-table)))
    (if (= (floor root) root)
        0
        (iterate 0 1 (floor root) 0 x table))))

(define (euler64)
  (apply + (map wrapper (iota N 1))))
