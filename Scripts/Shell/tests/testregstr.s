	.file	"testregstr.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	getbitgroupcount
	.type	getbitgroupcount, @function
getbitgroupcount:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	stdout(%rip), %rax
	movl	-4(%rbp), %edx
	movl	%edx, %ecx
	leaq	.LC0(%rip), %rdx
	movl	$0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	getbitgroupcount, .-getbitgroupcount
	.globl	reverseBool
	.type	reverseBool, @function
reverseBool:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	cmpl	$1, -4(%rbp)
	je	.L4
	cmpl	$0, -4(%rbp)
	jne	.L5
.L4:
	movl	-4(%rbp), %eax
	xorl	$1, %eax
	jmp	.L6
.L5:
	movl	-4(%rbp), %eax
.L6:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	reverseBool, .-reverseBool
	.section	.rodata
.LC1:
	.string	"Hello World"
.LC2:
	.string	"\n"
.LC3:
	.string	"\r\b\f\t''\"\"\\\n"
	.align 8
.LC4:
	.string	"'qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM foo\007\bc\033\033\f\n\r\t\013\\\0255\377 \001 \0255   \343\201\202  \343\201\202'"
.LC5:
	.string	"\007\bcd\033\fghikjklm\nopq\rs\t\013wyz"
.LC6:
	.string	"test"
.LC7:
	.string	"%s.index = %d\n"
.LC8:
	.string	"%s.len = %d\n"
.LC9:
	.string	"%s.malloced = %d\n"
.LC10:
	.string	"%s.string = %s\n"
.LC11:
	.string	"test.escaped"
.LC12:
	.string	"test.json"
.LC13:
	.string	"test.c_define"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$240, %rsp
	movl	$1, %edi
	call	malloc@PLT
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movl	$1, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, -16(%rbp)
	movl	$1, %edi
	call	malloc@PLT
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movl	$1, -72(%rbp)
	movl	$0, -76(%rbp)
	movl	$0, -80(%rbp)
	movl	$1, %edi
	call	malloc@PLT
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movl	$1, -48(%rbp)
	movl	$0, -52(%rbp)
	movl	$0, -56(%rbp)
	movl	$1, %edi
	call	malloc@PLT
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movl	$1, -24(%rbp)
	movl	$0, -28(%rbp)
	movl	$0, -32(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, -152(%rbp)
	movl	$11, -200(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L8
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L8:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$35, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L9
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L9:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$100, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L10
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L10:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L11
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L11:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L12
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L12:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$105, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L13
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L13:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L14
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L14:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L15
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L15:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$32, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	$0, -224(%rbp)
	jmp	.L16
.L95:
	movl	-224(%rbp), %eax
	movslq	%eax, %rdx
	movq	-152(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -156(%rbp)
	movl	-224(%rbp), %eax
	movslq	%eax, %rdx
	movq	-152(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -225(%rbp)
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -96(%rbp)
	movl	-8(%rbp), %eax
	movl	-8(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L17
	movq	-96(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L17:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	movq	-96(%rbp), %rdx
	movl	-16(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-156(%rbp), %edx
	movb	%dl, (%rax)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -12(%rbp)
	movl	-156(%rbp), %eax
	movl	%eax, %edi
	call	isalnum@PLT
	testl	%eax, %eax
	je	.L18
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L19
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L19:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-156(%rbp), %edx
	movb	%dl, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	jmp	.L20
.L18:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L21
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L21:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$95, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
.L20:
	cmpl	$7, -156(%rbp)
	jne	.L22
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L23
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L23:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L24
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L24:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$97, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L25
.L22:
	cmpl	$8, -156(%rbp)
	jne	.L26
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L27
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L27:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L28
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L28:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L29
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L29:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L30
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L30:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L25
.L26:
	cmpl	$99, -156(%rbp)
	jne	.L31
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L32
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L32:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L33
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L33:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$99, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L25
.L31:
	cmpl	$27, -156(%rbp)
	jne	.L34
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L35
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L35:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L36
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L36:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L25
.L34:
	cmpl	$27, -156(%rbp)
	jne	.L37
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L38
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L38:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L39
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L39:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$69, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L25
.L37:
	cmpl	$12, -156(%rbp)
	jne	.L40
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L41
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L41:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L42
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L42:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L43
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L43:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L44
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L44:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L25
.L40:
	cmpl	$10, -156(%rbp)
	jne	.L45
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L46
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L46:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L47
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L47:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L48
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L48:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L49
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L49:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L25
.L45:
	cmpl	$13, -156(%rbp)
	jne	.L50
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L51
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L51:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L52
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L52:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L53
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L53:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L54
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L54:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L25
.L50:
	cmpl	$9, -156(%rbp)
	jne	.L55
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L56
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L56:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L57
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L57:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L58
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L58:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L59
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L59:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L25
.L55:
	cmpl	$11, -156(%rbp)
	jne	.L60
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L61
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L61:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L62
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L62:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$118, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L25
.L60:
	cmpl	$92, -156(%rbp)
	jne	.L63
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L64
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L64:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L65
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L65:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L66
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L66:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L67
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L67:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L25
.L63:
	cmpl	$39, -156(%rbp)
	jne	.L68
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L69
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L69:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L70
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L70:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L71
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L71:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L72
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L72:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L25
.L68:
	cmpl	$34, -156(%rbp)
	jne	.L73
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L74
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L74:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L75
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L75:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L76
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L76:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L77
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L77:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L25
.L73:
	cmpl	$63, -156(%rbp)
	jne	.L78
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L79
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L79:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L80
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L80:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$63, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L25
.L78:
	cmpl	$31, -156(%rbp)
	jle	.L81
	cmpl	$126, -156(%rbp)
	jg	.L81
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L82
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L82:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-156(%rbp), %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L83
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L83:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-156(%rbp), %edx
	movb	%dl, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L25
.L81:
	cmpl	$47, -156(%rbp)
	jle	.L84
	cmpl	$57, -156(%rbp)
	jg	.L84
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L85
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L85:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L86
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L86:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-156(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L87
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L87:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-156(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L88
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L88:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-156(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L25
.L84:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L89
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L89:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-156(%rbp), %eax
	sarl	$3, %eax
	testl	%eax, %eax
	je	.L90
	movl	-156(%rbp), %eax
	sarl	$6, %eax
	testl	%eax, %eax
	je	.L91
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L92
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L92:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-156(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L91:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L93
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L93:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-156(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L90:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L94
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L94:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-156(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L25:
	addl	$1, -224(%rbp)
.L16:
	movl	-224(%rbp), %eax
	cmpl	%eax, -200(%rbp)
	ja	.L95
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L96
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L96:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$10, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -96(%rbp)
	movl	-8(%rbp), %eax
	movl	-8(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L97
	movq	-96(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L97:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	movq	-96(%rbp), %rdx
	movl	-16(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$33, (%rax)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -12(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -144(%rbp)
	movl	$1, -196(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L98
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L98:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$35, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L99
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L99:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$100, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L100
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L100:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L101
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L101:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L102
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L102:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$105, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L103
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L103:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L104
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L104:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L105
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L105:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$32, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	$0, -220(%rbp)
	jmp	.L106
.L185:
	movl	-220(%rbp), %eax
	movslq	%eax, %rdx
	movq	-144(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -160(%rbp)
	movl	-220(%rbp), %eax
	movslq	%eax, %rdx
	movq	-144(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -226(%rbp)
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -96(%rbp)
	movl	-8(%rbp), %eax
	movl	-8(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L107
	movq	-96(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L107:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	movq	-96(%rbp), %rdx
	movl	-16(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-160(%rbp), %edx
	movb	%dl, (%rax)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -12(%rbp)
	movl	-160(%rbp), %eax
	movl	%eax, %edi
	call	isalnum@PLT
	testl	%eax, %eax
	je	.L108
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L109
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L109:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-160(%rbp), %edx
	movb	%dl, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	jmp	.L110
.L108:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L111
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L111:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$95, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
.L110:
	cmpl	$7, -160(%rbp)
	jne	.L112
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L113
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L113:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L114
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L114:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$97, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L115
.L112:
	cmpl	$8, -160(%rbp)
	jne	.L116
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L117
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L117:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L118
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L118:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L119
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L119:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L120
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L120:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L115
.L116:
	cmpl	$99, -160(%rbp)
	jne	.L121
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L122
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L122:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L123
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L123:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$99, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L115
.L121:
	cmpl	$27, -160(%rbp)
	jne	.L124
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L125
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L125:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L126
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L126:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L115
.L124:
	cmpl	$27, -160(%rbp)
	jne	.L127
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L128
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L128:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L129
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L129:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$69, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L115
.L127:
	cmpl	$12, -160(%rbp)
	jne	.L130
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L131
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L131:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L132
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L132:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L133
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L133:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L134
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L134:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L115
.L130:
	cmpl	$10, -160(%rbp)
	jne	.L135
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L136
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L136:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L137
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L137:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L138
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L138:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L139
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L139:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L115
.L135:
	cmpl	$13, -160(%rbp)
	jne	.L140
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L141
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L141:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L142
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L142:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L143
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L143:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L144
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L144:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L115
.L140:
	cmpl	$9, -160(%rbp)
	jne	.L145
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L146
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L146:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L147
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L147:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L148
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L148:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L149
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L149:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L115
.L145:
	cmpl	$11, -160(%rbp)
	jne	.L150
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L151
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L151:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L152
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L152:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$118, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L115
.L150:
	cmpl	$92, -160(%rbp)
	jne	.L153
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L154
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L154:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L155
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L155:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L156
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L156:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L157
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L157:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L115
.L153:
	cmpl	$39, -160(%rbp)
	jne	.L158
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L159
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L159:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L160
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L160:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L161
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L161:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L162
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L162:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L115
.L158:
	cmpl	$34, -160(%rbp)
	jne	.L163
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L164
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L164:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L165
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L165:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L166
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L166:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L167
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L167:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L115
.L163:
	cmpl	$63, -160(%rbp)
	jne	.L168
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L169
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L169:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L170
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L170:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$63, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L115
.L168:
	cmpl	$31, -160(%rbp)
	jle	.L171
	cmpl	$126, -160(%rbp)
	jg	.L171
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L172
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L172:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-160(%rbp), %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L173
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L173:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-160(%rbp), %edx
	movb	%dl, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L115
.L171:
	cmpl	$47, -160(%rbp)
	jle	.L174
	cmpl	$57, -160(%rbp)
	jg	.L174
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L175
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L175:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L176
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L176:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-160(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L177
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L177:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-160(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L178
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L178:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-160(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L115
.L174:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L179
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L179:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-160(%rbp), %eax
	sarl	$3, %eax
	testl	%eax, %eax
	je	.L180
	movl	-160(%rbp), %eax
	sarl	$6, %eax
	testl	%eax, %eax
	je	.L181
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L182
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L182:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-160(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L181:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L183
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L183:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-160(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L180:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L184
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L184:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-160(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L115:
	addl	$1, -220(%rbp)
.L106:
	movl	-220(%rbp), %eax
	cmpl	%eax, -196(%rbp)
	ja	.L185
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L186
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L186:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$10, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	$123456, %edi
	call	getbitgroupcount
	cltq
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -136(%rbp)
	movq	-136(%rbp), %rax
	movl	$123456, %edx
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	movq	-136(%rbp), %rax
	movq	%rax, -128(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -192(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L187
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L187:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$35, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L188
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L188:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$100, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L189
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L189:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L190
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L190:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L191
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L191:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$105, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L192
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L192:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L193
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L193:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L194
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L194:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$32, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	$0, -216(%rbp)
	jmp	.L195
.L274:
	movl	-216(%rbp), %eax
	movslq	%eax, %rdx
	movq	-128(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -164(%rbp)
	movl	-216(%rbp), %eax
	movslq	%eax, %rdx
	movq	-128(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -227(%rbp)
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -96(%rbp)
	movl	-8(%rbp), %eax
	movl	-8(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L196
	movq	-96(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L196:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	movq	-96(%rbp), %rdx
	movl	-16(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-164(%rbp), %edx
	movb	%dl, (%rax)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -12(%rbp)
	movl	-164(%rbp), %eax
	movl	%eax, %edi
	call	isalnum@PLT
	testl	%eax, %eax
	je	.L197
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L198
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L198:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-164(%rbp), %edx
	movb	%dl, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	jmp	.L199
.L197:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L200
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L200:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$95, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
.L199:
	cmpl	$7, -164(%rbp)
	jne	.L201
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L202
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L202:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L203
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L203:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$97, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L204
.L201:
	cmpl	$8, -164(%rbp)
	jne	.L205
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L206
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L206:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L207
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L207:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L208
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L208:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L209
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L209:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L204
.L205:
	cmpl	$99, -164(%rbp)
	jne	.L210
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L211
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L211:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L212
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L212:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$99, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L204
.L210:
	cmpl	$27, -164(%rbp)
	jne	.L213
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L214
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L214:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L215
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L215:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L204
.L213:
	cmpl	$27, -164(%rbp)
	jne	.L216
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L217
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L217:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L218
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L218:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$69, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L204
.L216:
	cmpl	$12, -164(%rbp)
	jne	.L219
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L220
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L220:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L221
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L221:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L222
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L222:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L223
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L223:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L204
.L219:
	cmpl	$10, -164(%rbp)
	jne	.L224
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L225
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L225:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L226
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L226:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L227
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L227:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L228
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L228:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L204
.L224:
	cmpl	$13, -164(%rbp)
	jne	.L229
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L230
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L230:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L231
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L231:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L232
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L232:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L233
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L233:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L204
.L229:
	cmpl	$9, -164(%rbp)
	jne	.L234
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L235
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L235:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L236
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L236:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L237
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L237:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L238
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L238:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L204
.L234:
	cmpl	$11, -164(%rbp)
	jne	.L239
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L240
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L240:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L241
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L241:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$118, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L204
.L239:
	cmpl	$92, -164(%rbp)
	jne	.L242
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L243
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L243:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L244
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L244:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L245
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L245:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L246
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L246:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L204
.L242:
	cmpl	$39, -164(%rbp)
	jne	.L247
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L248
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L248:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L249
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L249:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L250
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L250:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L251
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L251:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L204
.L247:
	cmpl	$34, -164(%rbp)
	jne	.L252
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L253
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L253:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L254
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L254:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L255
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L255:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L256
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L256:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L204
.L252:
	cmpl	$63, -164(%rbp)
	jne	.L257
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L258
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L258:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L259
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L259:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$63, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L204
.L257:
	cmpl	$31, -164(%rbp)
	jle	.L260
	cmpl	$126, -164(%rbp)
	jg	.L260
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L261
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L261:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-164(%rbp), %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L262
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L262:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-164(%rbp), %edx
	movb	%dl, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L204
.L260:
	cmpl	$47, -164(%rbp)
	jle	.L263
	cmpl	$57, -164(%rbp)
	jg	.L263
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L264
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L264:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L265
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L265:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-164(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L266
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L266:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-164(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L267
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L267:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-164(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L204
.L263:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L268
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L268:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-164(%rbp), %eax
	sarl	$3, %eax
	testl	%eax, %eax
	je	.L269
	movl	-164(%rbp), %eax
	sarl	$6, %eax
	testl	%eax, %eax
	je	.L270
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L271
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L271:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-164(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L270:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L272
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L272:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-164(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L269:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L273
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L273:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-164(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L204:
	addl	$1, -216(%rbp)
.L195:
	movl	-216(%rbp), %eax
	cmpl	%eax, -192(%rbp)
	ja	.L274
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L275
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L275:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$10, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, -120(%rbp)
	movl	$10, -188(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L276
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L276:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$35, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L277
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L277:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$100, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L278
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L278:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L279
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L279:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L280
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L280:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$105, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L281
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L281:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L282
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L282:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L283
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L283:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$32, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	$0, -212(%rbp)
	jmp	.L284
.L363:
	movl	-212(%rbp), %eax
	movslq	%eax, %rdx
	movq	-120(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -168(%rbp)
	movl	-212(%rbp), %eax
	movslq	%eax, %rdx
	movq	-120(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -228(%rbp)
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -96(%rbp)
	movl	-8(%rbp), %eax
	movl	-8(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L285
	movq	-96(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L285:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	movq	-96(%rbp), %rdx
	movl	-16(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-168(%rbp), %edx
	movb	%dl, (%rax)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -12(%rbp)
	movl	-168(%rbp), %eax
	movl	%eax, %edi
	call	isalnum@PLT
	testl	%eax, %eax
	je	.L286
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L287
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L287:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-168(%rbp), %edx
	movb	%dl, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	jmp	.L288
.L286:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L289
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L289:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$95, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
.L288:
	cmpl	$7, -168(%rbp)
	jne	.L290
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L291
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L291:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L292
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L292:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$97, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L293
.L290:
	cmpl	$8, -168(%rbp)
	jne	.L294
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L295
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L295:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L296
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L296:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L297
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L297:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L298
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L298:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L293
.L294:
	cmpl	$99, -168(%rbp)
	jne	.L299
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L300
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L300:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L301
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L301:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$99, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L293
.L299:
	cmpl	$27, -168(%rbp)
	jne	.L302
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L303
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L303:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L304
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L304:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L293
.L302:
	cmpl	$27, -168(%rbp)
	jne	.L305
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L306
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L306:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L307
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L307:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$69, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L293
.L305:
	cmpl	$12, -168(%rbp)
	jne	.L308
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L309
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L309:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L310
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L310:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L311
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L311:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L312
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L312:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L293
.L308:
	cmpl	$10, -168(%rbp)
	jne	.L313
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L314
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L314:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L315
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L315:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L316
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L316:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L317
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L317:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L293
.L313:
	cmpl	$13, -168(%rbp)
	jne	.L318
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L319
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L319:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L320
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L320:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L321
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L321:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L322
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L322:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L293
.L318:
	cmpl	$9, -168(%rbp)
	jne	.L323
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L324
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L324:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L325
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L325:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L326
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L326:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L327
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L327:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L293
.L323:
	cmpl	$11, -168(%rbp)
	jne	.L328
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L329
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L329:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L330
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L330:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$118, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L293
.L328:
	cmpl	$92, -168(%rbp)
	jne	.L331
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L332
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L332:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L333
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L333:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L334
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L334:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L335
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L335:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L293
.L331:
	cmpl	$39, -168(%rbp)
	jne	.L336
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L337
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L337:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L338
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L338:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L339
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L339:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L340
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L340:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L293
.L336:
	cmpl	$34, -168(%rbp)
	jne	.L341
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L342
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L342:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L343
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L343:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L344
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L344:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L345
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L345:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L293
.L341:
	cmpl	$63, -168(%rbp)
	jne	.L346
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L347
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L347:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L348
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L348:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$63, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L293
.L346:
	cmpl	$31, -168(%rbp)
	jle	.L349
	cmpl	$126, -168(%rbp)
	jg	.L349
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L350
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L350:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-168(%rbp), %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L351
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L351:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-168(%rbp), %edx
	movb	%dl, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L293
.L349:
	cmpl	$47, -168(%rbp)
	jle	.L352
	cmpl	$57, -168(%rbp)
	jg	.L352
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L353
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L353:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L354
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L354:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-168(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L355
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L355:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-168(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L356
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L356:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-168(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L293
.L352:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L357
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L357:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-168(%rbp), %eax
	sarl	$3, %eax
	testl	%eax, %eax
	je	.L358
	movl	-168(%rbp), %eax
	sarl	$6, %eax
	testl	%eax, %eax
	je	.L359
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L360
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L360:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-168(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L359:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L361
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L361:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-168(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L358:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L362
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L362:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-168(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L293:
	addl	$1, -212(%rbp)
.L284:
	movl	-212(%rbp), %eax
	cmpl	%eax, -188(%rbp)
	ja	.L363
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L364
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L364:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$10, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	leaq	.LC4(%rip), %rax
	movq	%rax, -112(%rbp)
	movl	$88, -184(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L365
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L365:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$35, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L366
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L366:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$100, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L367
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L367:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L368
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L368:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L369
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L369:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$105, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L370
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L370:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L371
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L371:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L372
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L372:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$32, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	$0, -208(%rbp)
	jmp	.L373
.L452:
	movl	-208(%rbp), %eax
	movslq	%eax, %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -172(%rbp)
	movl	-208(%rbp), %eax
	movslq	%eax, %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -229(%rbp)
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -96(%rbp)
	movl	-8(%rbp), %eax
	movl	-8(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L374
	movq	-96(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L374:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	movq	-96(%rbp), %rdx
	movl	-16(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-172(%rbp), %edx
	movb	%dl, (%rax)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -12(%rbp)
	movl	-172(%rbp), %eax
	movl	%eax, %edi
	call	isalnum@PLT
	testl	%eax, %eax
	je	.L375
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L376
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L376:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-172(%rbp), %edx
	movb	%dl, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	jmp	.L377
.L375:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L378
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L378:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$95, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
.L377:
	cmpl	$7, -172(%rbp)
	jne	.L379
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L380
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L380:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L381
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L381:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$97, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L382
.L379:
	cmpl	$8, -172(%rbp)
	jne	.L383
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L384
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L384:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L385
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L385:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L386
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L386:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L387
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L387:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L382
.L383:
	cmpl	$99, -172(%rbp)
	jne	.L388
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L389
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L389:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L390
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L390:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$99, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L382
.L388:
	cmpl	$27, -172(%rbp)
	jne	.L391
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L392
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L392:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L393
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L393:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L382
.L391:
	cmpl	$27, -172(%rbp)
	jne	.L394
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L395
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L395:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L396
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L396:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$69, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L382
.L394:
	cmpl	$12, -172(%rbp)
	jne	.L397
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L398
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L398:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L399
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L399:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L400
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L400:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L401
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L401:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L382
.L397:
	cmpl	$10, -172(%rbp)
	jne	.L402
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L403
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L403:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L404
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L404:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L405
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L405:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L406
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L406:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L382
.L402:
	cmpl	$13, -172(%rbp)
	jne	.L407
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L408
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L408:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L409
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L409:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L410
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L410:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L411
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L411:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L382
.L407:
	cmpl	$9, -172(%rbp)
	jne	.L412
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L413
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L413:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L414
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L414:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L415
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L415:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L416
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L416:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L382
.L412:
	cmpl	$11, -172(%rbp)
	jne	.L417
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L418
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L418:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L419
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L419:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$118, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L382
.L417:
	cmpl	$92, -172(%rbp)
	jne	.L420
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L421
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L421:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L422
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L422:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L423
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L423:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L424
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L424:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L382
.L420:
	cmpl	$39, -172(%rbp)
	jne	.L425
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L426
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L426:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L427
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L427:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L428
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L428:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L429
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L429:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L382
.L425:
	cmpl	$34, -172(%rbp)
	jne	.L430
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L431
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L431:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L432
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L432:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L433
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L433:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L434
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L434:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L382
.L430:
	cmpl	$63, -172(%rbp)
	jne	.L435
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L436
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L436:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L437
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L437:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$63, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L382
.L435:
	cmpl	$31, -172(%rbp)
	jle	.L438
	cmpl	$126, -172(%rbp)
	jg	.L438
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L439
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L439:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-172(%rbp), %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L440
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L440:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-172(%rbp), %edx
	movb	%dl, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L382
.L438:
	cmpl	$47, -172(%rbp)
	jle	.L441
	cmpl	$57, -172(%rbp)
	jg	.L441
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L442
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L442:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L443
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L443:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-172(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L444
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L444:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-172(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L445
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L445:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-172(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L382
.L441:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L446
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L446:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-172(%rbp), %eax
	sarl	$3, %eax
	testl	%eax, %eax
	je	.L447
	movl	-172(%rbp), %eax
	sarl	$6, %eax
	testl	%eax, %eax
	je	.L448
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L449
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L449:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-172(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L448:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L450
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L450:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-172(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L447:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L451
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L451:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-172(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L382:
	addl	$1, -208(%rbp)
.L373:
	movl	-208(%rbp), %eax
	cmpl	%eax, -184(%rbp)
	ja	.L452
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L453
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L453:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$10, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	leaq	.LC5(%rip), %rax
	movq	%rax, -104(%rbp)
	movl	$25, -180(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L454
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L454:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$35, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L455
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L455:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$100, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L456
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L456:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L457
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L457:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L458
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L458:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$105, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L459
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L459:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L460
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L460:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L461
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L461:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$32, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	$0, -204(%rbp)
	jmp	.L462
.L541:
	movl	-204(%rbp), %eax
	movslq	%eax, %rdx
	movq	-104(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -176(%rbp)
	movl	-204(%rbp), %eax
	movslq	%eax, %rdx
	movq	-104(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -230(%rbp)
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -96(%rbp)
	movl	-8(%rbp), %eax
	movl	-8(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L463
	movq	-96(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L463:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	movq	-96(%rbp), %rdx
	movl	-16(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-176(%rbp), %edx
	movb	%dl, (%rax)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -12(%rbp)
	movl	-176(%rbp), %eax
	movl	%eax, %edi
	call	isalnum@PLT
	testl	%eax, %eax
	je	.L464
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L465
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L465:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-176(%rbp), %edx
	movb	%dl, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	jmp	.L466
.L464:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L467
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L467:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$95, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
.L466:
	cmpl	$7, -176(%rbp)
	jne	.L468
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L469
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L469:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L470
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L470:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$97, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L471
.L468:
	cmpl	$8, -176(%rbp)
	jne	.L472
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L473
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L473:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L474
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L474:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L475
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L475:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L476
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L476:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$98, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L471
.L472:
	cmpl	$99, -176(%rbp)
	jne	.L477
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L478
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L478:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L479
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L479:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$99, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L471
.L477:
	cmpl	$27, -176(%rbp)
	jne	.L480
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L481
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L481:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L482
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L482:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$101, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L471
.L480:
	cmpl	$27, -176(%rbp)
	jne	.L483
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L484
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L484:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L485
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L485:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$69, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L471
.L483:
	cmpl	$12, -176(%rbp)
	jne	.L486
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L487
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L487:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L488
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L488:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L489
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L489:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L490
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L490:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$102, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L471
.L486:
	cmpl	$10, -176(%rbp)
	jne	.L491
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L492
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L492:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L493
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L493:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L494
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L494:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L495
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L495:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L471
.L491:
	cmpl	$13, -176(%rbp)
	jne	.L496
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L497
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L497:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L498
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L498:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L499
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L499:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L500
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L500:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$114, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L471
.L496:
	cmpl	$9, -176(%rbp)
	jne	.L501
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L502
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L502:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L503
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L503:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L504
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L504:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L505
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L505:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$116, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L471
.L501:
	cmpl	$11, -176(%rbp)
	jne	.L506
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L507
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L507:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L508
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L508:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$118, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L471
.L506:
	cmpl	$92, -176(%rbp)
	jne	.L509
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L510
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L510:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L511
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L511:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L512
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L512:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L513
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L513:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L471
.L509:
	cmpl	$39, -176(%rbp)
	jne	.L514
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L515
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L515:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L516
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L516:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L517
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L517:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L518
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L518:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$39, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L471
.L514:
	cmpl	$34, -176(%rbp)
	jne	.L519
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L520
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L520:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L521
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L521:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L522
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L522:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L523
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L523:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$34, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L471
.L519:
	cmpl	$63, -176(%rbp)
	jne	.L524
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L525
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L525:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L526
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L526:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$63, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L471
.L524:
	cmpl	$31, -176(%rbp)
	jle	.L527
	cmpl	$126, -176(%rbp)
	jg	.L527
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L528
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L528:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-176(%rbp), %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movl	-48(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L529
	movq	-64(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L529:
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	-176(%rbp), %edx
	movb	%dl, (%rax)
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -52(%rbp)
	jmp	.L471
.L527:
	cmpl	$47, -176(%rbp)
	jle	.L530
	cmpl	$57, -176(%rbp)
	jg	.L530
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L531
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L531:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L532
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L532:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-176(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L533
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L533:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-176(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L534
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L534:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-176(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	jmp	.L471
.L530:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L535
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L535:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$92, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
	movl	-176(%rbp), %eax
	sarl	$3, %eax
	testl	%eax, %eax
	je	.L536
	movl	-176(%rbp), %eax
	sarl	$6, %eax
	testl	%eax, %eax
	je	.L537
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L538
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L538:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-176(%rbp), %eax
	sarl	$6, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L537:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L539
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L539:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-176(%rbp), %eax
	sarl	$3, %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L536:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
	movl	-72(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L540
	movq	-88(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L540:
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-176(%rbp), %eax
	andl	$7, %eax
	leal	48(%rax), %ecx
	movq	-88(%rbp), %rdx
	movl	-80(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -76(%rbp)
.L471:
	addl	$1, -204(%rbp)
.L462:
	movl	-204(%rbp), %eax
	cmpl	%eax, -180(%rbp)
	ja	.L541
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jge	.L542
	movq	-40(%rbp), %rdx
	movl	-24(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
.L542:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	movq	-40(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movb	$10, (%rax)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -28(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC6(%rip), %rsi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC6(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-8(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC6(%rip), %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-96(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC6(%rip), %rsi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-80(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC11(%rip), %rsi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-76(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC11(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-72(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC11(%rip), %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-88(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC11(%rip), %rsi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-56(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC12(%rip), %rsi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-52(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC12(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-48(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC12(%rip), %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-64(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rsi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-32(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC13(%rip), %rsi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC13(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC13(%rip), %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-40(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC13(%rip), %rsi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	-96(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, -16(%rbp)
	movl	-72(%rbp), %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, -72(%rbp)
	movl	$0, -76(%rbp)
	movl	$0, -80(%rbp)
	movl	-48(%rbp), %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, -48(%rbp)
	movl	$0, -52(%rbp)
	movl	$0, -56(%rbp)
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, -24(%rbp)
	movl	$0, -28(%rbp)
	movl	$0, -32(%rbp)
	movl	$-1, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
