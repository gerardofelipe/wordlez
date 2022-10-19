.module utils
.optsdcc -mz80

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Function: get_highest_active_bit_position
;;
;;    Get the position of the highest active bit of a given byte
;;
;; C Definition:
;;    <u8> <get_highest_active_bit_position> (<u8> *byte*);
;;
;; Input Parameters (1 Bytes):
;;   (1B L) byte - An 8-bit value.
;; 
;; Assembly call (Input parameters on registers):
;;    > call cpct_isKeyPressed_asm
;;
;; Parameter Restrictions:
;;
;; Return value (for Assembly, L=position):
;;    u8 - A value between 0 and 7 inclusive [0-7].
;;
;; Flag status on return:
;;    sz-h-vnc
;;    01000101
;;
;; Details:
;;    e.g. 0x46 (0b01000110) would return 5
;;
;; Destroyed Register values: 
;;    A, L
;;
;; Required memory:
;;       10 bytes
;;
;; Time Measures:
;; (start code)
;; Case        | microSecs(us) | CPU Cycles
;; ------------------------------------------
;; Best  (0)   |        9      |     46
;; ------------------------------------------
;; Worst (255) |       65      |    233
;; ------------------------------------------
;; (end code)
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Using __z88dk_fastcall calling convention. Parameter is passed directly in HL
_get_highest_active_bit_position::
get_highest_active_bit_position::
	ld    a, l			;; [1] 4
	ld    l, #0			;; [2] 7
.L2:					;;
	srl	a				;; [2] 8
	ret z				;; [1] 11/5
	inc   l				;; [1] 4
	jr .L2				;; [3] 12