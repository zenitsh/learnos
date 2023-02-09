	.section .entry
	.global _start
_start:
	lla sp, stack
	j main

	.section .stack
stack:
