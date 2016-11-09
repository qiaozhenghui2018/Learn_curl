	.file	"arg.c"
	.section	.rodata
.LC0:
	.string	"para %d is %s\n"
	.text
	.globl	debug
	.type	debug, @function
debug:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$240, %rsp
	movq	%rsi, -168(%rbp)
	movq	%rdx, -160(%rbp)
	movq	%rcx, -152(%rbp)
	movq	%r8, -144(%rbp)
	movq	%r9, -136(%rbp)
	testb	%al, %al
	je	.L2
	movaps	%xmm0, -128(%rbp)
	movaps	%xmm1, -112(%rbp)
	movaps	%xmm2, -96(%rbp)
	movaps	%xmm3, -80(%rbp)
	movaps	%xmm4, -64(%rbp)
	movaps	%xmm5, -48(%rbp)
	movaps	%xmm6, -32(%rbp)
	movaps	%xmm7, -16(%rbp)
.L2:
	movb	%dil, -228(%rbp)
	movl	$0, -180(%rbp)
	movq	$0, -192(%rbp)
	movl	$8, -216(%rbp)
	movl	$48, -212(%rbp)
	leaq	16(%rbp), %rax
	movq	%rax, -208(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, -200(%rbp)
.L5:
	movl	-216(%rbp), %eax
	cmpl	$48, %eax
	jnb	.L3
	movq	-200(%rbp), %rax
	movl	-216(%rbp), %edx
	movl	%edx, %edx
	addq	%rdx, %rax
	movl	-216(%rbp), %edx
	addl	$8, %edx
	movl	%edx, -216(%rbp)
	jmp	.L4
.L3:
	movq	-208(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	%rdx, -208(%rbp)
.L4:
	movq	(%rax), %rax
	movq	%rax, -192(%rbp)
	movl	-180(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -180(%rbp)
	movq	-192(%rbp), %rdx
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L5
	.cfi_endproc
.LFE0:
	.size	debug, .-debug
	.section	.rodata
.LC1:
	.string	"qiao"
.LC2:
	.string	"test"
.LC3:
	.string	"arg"
.LC4:
	.string	"hui"
.LC5:
	.string	"zheng"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$.LC1, %eax
	movsbl	%al, %eax
	movl	$.LC2, %r8d
	movl	$.LC3, %ecx
	movl	$.LC4, %edx
	movl	$.LC5, %esi
	movl	%eax, %edi
	movl	$0, %eax
	call	debug
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 5.3.1 20160406 (Red Hat 5.3.1-6)"
	.section	.note.GNU-stack,"",@progbits
