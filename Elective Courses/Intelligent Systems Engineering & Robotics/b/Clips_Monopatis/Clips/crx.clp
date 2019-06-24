;; July 2017
;; Monopatis Dimitrios, mail: monopatis+clips@ceid.upatras.gr

;; In order to execute the program, type:
; (clear)
; (reset)
; Then oad crx.BAT batch file, then type:
; (load crx.clp)
; and then (run)

; Ypologismos ton metrikon a3iologisis
(defrule results
=>
  (printout t "Accuracy " (/ (+ ?*a* ?*d*) (+ ?*a* ?*b* ?*c* ?*d*)) crlf)
  (printout t "Sensitivity " (/ ?*a* (+ ?*a* ?*b*)) crlf)
  (printout t "Specificity " (/ ?*d* (+ ?*c* ?*d*)) crlf)
  (printout t "Precision " (/ ?*a* (+ ?*a* ?*c*))) crlf)

; Kanones simfona me to dentro apofasis

(defrule r13
  (credit-approval (A9 f) (A3 ?a3) (A13 s) (class ?x))
  (test (> ?a3 0.165))
  ?c <- (credit-approval (A9 f) (A3 ?a3) (A13 s) (class ?x))
=>
  (if (eq ?x -)
   then
      (bind ?*d* (+ ?*d* 1))
   else
      (bind ?*c* (+ ?*c* 1)))
  (retract ?c)
)

(defrule r12
  (credit-approval (A9 f) (A3 ?a3) (A13 p) (class ?x))
  (test (> ?a3 0.165))
  ?c <- (credit-approval (A9 f) (A3 ?a3) (A13 p) (class ?x))
=>
  (if (eq ?x +)
   then
      (bind ?*a* (+ ?*a* 1))
   else
      (bind ?*b* (+ ?*b* 1)))
  (retract ?c)
)

(defrule r11
  (credit-approval (A9 f) (A3 ?a3) (A13 g) (class ?x))
  (test (> ?a3 0.165))
  ?c <- (credit-approval (A9 f) (A3 ?a3) (A13 g) (class ?x))
=>
  (if (eq ?x -)
   then
      (bind ?*d* (+ ?*d* 1))
   else
      (bind ?*c* (+ ?*c* 1)))
  (retract ?c)
)

(defrule r10
  (credit-approval (A9 f) (A3 ?a3) (class ?x))
  (test (<= ?a3 0.165))
  ?c <- (credit-approval (A9 f) (A3 ?a3) (class ?x))
=>
  (if (eq ?x -)
   then
      (bind ?*d* (+ ?*d* 1))
   else
      (bind ?*c* (+ ?*c* 1)))
  (retract ?c)
)

(defrule r9
  (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (class ?x))
  (test (> ?a14 70))
  (test (> ?a15 109))
  ?c <- (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (class ?x))
=>
  (if (eq ?x +)
   then
      (bind ?*a* (+ ?*a* 1))
   else
      (bind ?*b* (+ ?*b* 1)))
  (retract ?c)
)


(defrule r8
  (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 t) (class ?x))
  (test (> ?a14 70))
  (test (<= ?a15 109))
  ?c <- (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 t) (class ?x))
=>
  (if (eq ?x -)
   then
      (bind ?*d* (+ ?*d* 1))
   else
      (bind ?*c* (+ ?*c* 1)))
  (retract ?c)
)

(defrule r7
  (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 l) (class ?x))
  (test (> ?a14 70))
  (test (<= ?a15 109))
  ?c <- (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 l) (class ?x))
=>
  (if (eq ?x -)
   then
      (bind ?*d* (+ ?*d* 1))
   else
      (bind ?*c* (+ ?*c* 1)))
  (retract ?c)
)

(defrule r6
  (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 y) (class ?x))
  (test (> ?a14 70))
  (test (<= ?a15 109))
  ?c <- (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 y) (class ?x))
=>
  (if (eq ?x -)
   then
      (bind ?*d* (+ ?*d* 1))
   else
      (bind ?*c* (+ ?*c* 1)))
  (retract ?c)
)

(defrule r5
  (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 u) (A3 ?a3) (A12 f) (class ?x))
  (test (> ?a14 70))
  (test (<= ?a15 109))
  (test (> ?a3 2.665))
  ?c <- (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 u) (A3 ?a3) (A12 f) (class ?x))
=>
  (if (eq ?x +)
   then
      (bind ?*a* (+ ?*a* 1))
   else
      (bind ?*b* (+ ?*b* 1)))
  (retract ?c)
)

(defrule r4
  (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 u) (A3 ?a3) (A12 t) (class ?x))
  (test (> ?a14 70))
  (test (<= ?a15 109))
  (test (> ?a3 2.665))
  ?c <- (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 u) (A3 ?a3) (A12 t) (class ?x))
=>
  (if (eq ?x -)
   then
      (bind ?*d* (+ ?*d* 1))
   else
      (bind ?*c* (+ ?*c* 1)))
  (retract ?c)
)

(defrule r3
  (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 u) (A3 ?a3) (class ?x))
  (test (> ?a14 70))
  (test (<= ?a15 109))
  (test (<= ?a3 2.665))
  ?c <- (credit-approval (A9 t) (A10 f) (A14 ?a14) (A15 ?a15) (A4 u) (A3 ?a3) (class ?x))
=>
  (if (eq ?x -)
   then
      (bind ?*d* (+ ?*d* 1))
   else
      (bind ?*c* (+ ?*c* 1)))
  (retract ?c)
)

(defrule r2
  (credit-approval (A9 t) (A10 t) (A14 ?a14) (class ?x))
  (test (<= ?a14 70))
  ?c <- (credit-approval (A9 t) (A10 t) (A14 ?a14) (class ?x))
=>
  (if (eq ?x +)
   then
      (bind ?*a* (+ ?*a* 1))
   else
      (bind ?*b* (+ ?*b* 1)))
  (retract ?c)
)

(defrule r1
  (credit-approval (A9 t) (A10 t) (class ?x))
  ?c <- (credit-approval (A9 t) (A10 t) (class ?x))
=>
  (if (eq ?x +)
   then
      (bind ?*a* (+ ?*a* 1))
   else
      (bind ?*b* (+ ?*b* 1)))
  (retract ?c)
)

; Gia na min emfanizetai proidopoiisi diairesis me miden
(defrule minus
=>
(bind ?*a* (- ?*a* 1))
(bind ?*b* (- ?*b* 1))
(bind ?*c* (- ?*c* 1))
(bind ?*d* (- ?*d* 1))
)
