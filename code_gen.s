main:
	lw $t0, -4($fp)
	lw $t1, -8($fp)
	add $t0, $t0, $t1
	sw $t0, -12($fp)
	lw $t1, -12($fp)
	move $a0, $t1
	li $v0, 1
	syscall
	lw $t1, -12($fp)
	li $v0, 5
	syscall
	sw $v0, $16($fp)
	li $v0, 5
	syscall
	sw $v0, $20($fp)
	lw $t2, -16($fp)
	move $a0, $t2
	li $v0, 1
	syscall
	lw $t2, -20($fp)
	move $a0, $t2
	li $v0, 1
	syscall
	lw $t2, -16($fp)
	lw $t3, -20($fp)
	add $t2, $t2, $t3
	lw $t3, -20($fp)
	mul $t2, $t2, $t3
	sw $t2, -24($fp)
	lw $t3, -24($fp)
	move $a0, $t3
	li $v0, 1
	syscall
	lw $t3, -16($fp)
	lw $t4, -20($fp)
	lw $t5, -16($fp)
	lw $t6, -20($fp)
	li $t7, $1
	div $t6, $t6, $1
	mul $t5, $t5, $t6
	sub $t4, $t4, $t5
	add $t3, $t3, $t4
	sw $t3, -24($fp)
	lw $t4, -24($fp)
	move $a0, $t4
	li $v0, 1
	syscall
	lw $t4, -16($fp)
	lw $t5, -20($fp)
	lgt $t6, $t4, $t5
	lw $t5, -16($fp)
	lw $t8, -20($fp)
	sub $t5, $t5, $t8
	sw $t5, -24($fp)
	lw $t8, -24($fp)
	move $a0, $t8
	li $v0, 1
	syscall
	lw $t8, -20($fp)
	lw $t9, -16($fp)
	sub $t8, $t8, $t9
	sw $t8, -24($fp)
	lw $t9, -24($fp)
	move $a0, $t9
	li $v0, 1
	syscall
	li $t9, $10
	sw $10, -28($fp)
	lw $t9, -28($fp)
	li $t9, $0
	lgt $t9, $t9, $0
	lw $t9, -28($fp)
	li $t9, $1
	sub $t9, $t9, $1
	sw $t9, -28($fp)
	lw $t9, -28($fp)
	move $a0, $t9
	li $v0, 1
	syscall
	li $t9, $1
	li $t9, $5
	li $t9, $6
	li $t9, $10
	li $t9, $1
	li $t9, $6
	sw $idArray, -24($fp)
	lw $t9, -68($fp)
	move $a0, $t9
	li $v0, 1
	syscall
	lw $t9, -16($fp)
	lw $t9, -20($fp)
	sw $idFunction, -24($fp)
	lw $t9, -24($fp)
	move $a0, $t9
	li $v0, 1
	syscall
	li $t9, $0
