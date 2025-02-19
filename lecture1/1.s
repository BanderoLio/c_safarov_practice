	.text
	.file	"1.c"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpl	$3, -8(%rbp)
	jge	.LBB0_2
# %bb.1:
	movl	$-1, -4(%rbp)
	jmp	.LBB0_3
.LBB0_2:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdi
	callq	atof@PLT
	movsd	%xmm0, -24(%rbp)                # 8-byte Spill
	movq	-16(%rbp), %rax
	movq	16(%rax), %rdi
	callq	atof@PLT
	movaps	%xmm0, %xmm1
	movsd	-24(%rbp), %xmm0                # 8-byte Reload
                                        # xmm0 = mem[0],zero
	callq	pow@PLT
	leaq	.L.str(%rip), %rdi
	movb	$1, %al
	callq	printf@PLT
.LBB0_3:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%lf"
	.size	.L.str, 4

	.ident	"clang version 18.1.8"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
	.addrsig_sym pow
	.addrsig_sym atof
