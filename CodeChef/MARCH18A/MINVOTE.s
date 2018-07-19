	.file	"MINVOTE.cpp"
	.text
	.p2align 4,,15
	.globl	__Z3cmpRK3datS1_
	.def	__Z3cmpRK3datS1_;	.scl	2;	.type	32;	.endef
__Z3cmpRK3datS1_:
LFB7738:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$1, %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	4(%ecx), %esi
	cmpl	%esi, 4(%edx)
	movl	(%edx), %ebx
	jl	L2
	jle	L7
L3:
	xorl	%eax, %eax
L2:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
L7:
	.cfi_restore_state
	cmpl	(%ecx), %ebx
	jnb	L3
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE7738:
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB8326:
	.cfi_startproc
	movl	$__ZStL8__ioinit, %ecx
	jmp	__ZNSt8ios_base4InitD1Ev
	.cfi_endproc
LFE8326:
	.section .rdata,"dr"
LC0:
	.ascii "%d%c\0"
	.text
	.p2align 4,,15
	.def	_printf.constprop.17;	.scl	3;	.type	32;	.endef
_printf.constprop.17:
LFB8332:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	leal	36(%esp), %eax
	movl	$LC0, (%esp)
	movl	%eax, 4(%esp)
	call	___mingw_vprintf
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE8332:
	.p2align 4,,15
	.def	__ZSt13__adjust_heapIP3datiS0_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_T0_SB_T1_T2_.constprop.10;	.scl	3;	.type	32;	.endef
__ZSt13__adjust_heapIP3datiS0_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_T0_SB_T1_T2_.constprop.10:
LFB8339:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%eax, %ebp
	movl	%ecx, %eax
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	leal	-1(%eax), %edi
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	%edi, %eax
	subl	$76, %esp
	.cfi_def_cfa_offset 96
	shrl	$31, %eax
	addl	%edi, %eax
	movl	%edx, 32(%esp)
	movl	32(%esp), %edi
	movl	%ecx, 36(%esp)
	movl	96(%esp), %edx
	sarl	%eax
	movl	100(%esp), %ecx
	movl	104(%esp), %ebx
	movl	108(%esp), %esi
	cmpl	%eax, %edi
	movl	%eax, 28(%esp)
	movl	%edx, 40(%esp)
	movl	%ecx, 44(%esp)
	movl	%ebx, 48(%esp)
	movl	%esi, 52(%esp)
	jge	L12
	.p2align 4,,10
L19:
	leal	1(%edi), %ebx
	leal	(%ebx,%ebx), %eax
	sall	$5, %ebx
	addl	%ebp, %ebx
	leal	268435455(%eax), %edx
	movl	(%ebx), %ecx
	movl	4(%ebx), %esi
	sall	$4, %edx
	addl	%ebp, %edx
	movl	%ecx, 16(%esp)
	movl	%esi, 12(%esp)
	movl	(%edx), %ecx
	movl	%ecx, %esi
	movl	%ecx, 20(%esp)
	movl	4(%edx), %ecx
	cmpl	%ecx, 12(%esp)
	leal	-1(%eax), %edx
	jl	L13
	jg	L14
	cmpl	%esi, 16(%esp)
	jb	L13
	.p2align 4,,10
L14:
	cmpl	%ecx, 12(%esp)
	movl	%eax, 24(%esp)
	jl	L16
	jg	L17
	movl	20(%esp), %ecx
	cmpl	%ecx, 16(%esp)
	jnb	L17
L16:
	sall	$4, %edx
	leal	0(%ebp,%edx), %ebx
L17:
	movl	(%ebx), %edx
	sall	$4, %edi
	addl	%ebp, %edi
	cmpl	28(%esp), %eax
	movl	%edx, (%edi)
	movl	4(%ebx), %edx
	movl	%edx, 4(%edi)
	movl	8(%ebx), %edx
	movl	%edx, 8(%edi)
	movl	12(%ebx), %edx
	movl	%edx, 12(%edi)
	movl	%eax, %edi
	jl	L19
	testb	$1, 36(%esp)
	jne	L20
L25:
	movl	36(%esp), %ecx
	subl	$2, %ecx
	movl	%ecx, %eax
	shrl	$31, %eax
	addl	%ecx, %eax
	sarl	%eax
	cmpl	24(%esp), %eax
	je	L30
L20:
	movl	40(%esp), %eax
	movl	32(%esp), %esi
	cmpl	%esi, 24(%esp)
	movl	%eax, 56(%esp)
	movl	44(%esp), %eax
	movl	%eax, 60(%esp)
	movl	48(%esp), %eax
	movl	%eax, 64(%esp)
	movl	52(%esp), %eax
	movl	%eax, 68(%esp)
	jg	L31
L21:
	movl	56(%esp), %eax
	movl	%eax, (%ebx)
	movl	60(%esp), %eax
	movl	%eax, 4(%ebx)
	movl	64(%esp), %eax
	movl	%eax, 8(%ebx)
	movl	68(%esp), %eax
	movl	%eax, 12(%ebx)
	addl	$76, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
L13:
	.cfi_restore_state
	movl	%edx, %eax
	jmp	L14
	.p2align 4,,10
L30:
	movl	24(%esp), %eax
	leal	2(%eax,%eax), %edx
	leal	268435455(%edx), %eax
	sall	$4, %eax
	addl	%ebp, %eax
	movl	(%eax), %ecx
	movl	%ecx, (%ebx)
	movl	4(%eax), %ecx
	movl	%ecx, 4(%ebx)
	movl	8(%eax), %ecx
	movl	%ecx, 8(%ebx)
	movl	12(%eax), %eax
	movl	%eax, 12(%ebx)
	leal	-1(%edx), %eax
	movl	%eax, %ebx
	movl	%eax, 24(%esp)
	sall	$4, %ebx
	addl	%ebp, %ebx
	jmp	L20
	.p2align 4,,10
L31:
	movl	24(%esp), %edx
	movl	%esi, %ecx
	leal	56(%esp), %edi
	movl	%edx, %eax
	subl	$1, %eax
	movl	%eax, %esi
	shrl	$31, %esi
	addl	%eax, %esi
	sarl	%esi
	.p2align 4,,10
L23:
	movl	%esi, %ebx
	movl	%edi, 4(%esp)
	movl	%ecx, 16(%esp)
	sall	$4, %ebx
	movl	%edx, 12(%esp)
	addl	%ebp, %ebx
	movl	%ebx, (%esp)
	call	__Z3cmpRK3datS1_
	testb	%al, %al
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	jne	L22
	movl	%edx, %ebx
	sall	$4, %ebx
	addl	%ebp, %ebx
	jmp	L21
	.p2align 4,,10
L22:
	sall	$4, %edx
	leal	0(%ebp,%edx), %eax
	movl	(%ebx), %edx
	movl	%edx, (%eax)
	movl	4(%ebx), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebx), %edx
	movl	%edx, 8(%eax)
	movl	12(%ebx), %edx
	movl	%edx, 12(%eax)
	leal	-1(%esi), %edx
	movl	%edx, %eax
	shrl	$31, %eax
	addl	%edx, %eax
	sarl	%eax
	cmpl	%esi, %ecx
	jge	L21
	movl	%esi, %edx
	movl	%eax, %esi
	jmp	L23
L12:
	testb	$1, 36(%esp)
	jne	L24
	movl	%edi, %ebx
	movl	%edi, 24(%esp)
	sall	$4, %ebx
	addl	%ebp, %ebx
	jmp	L25
L24:
	movl	%ebx, 64(%esp)
	movl	32(%esp), %ebx
	movl	%edx, 56(%esp)
	movl	%ecx, 60(%esp)
	movl	%esi, 68(%esp)
	sall	$4, %ebx
	addl	%ebp, %ebx
	jmp	L21
	.cfi_endproc
LFE8339:
	.section	.text$_ZSt13__adjust_heapIP3datiS0_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_T0_SB_T1_T2_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__ZSt13__adjust_heapIP3datiS0_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_T0_SB_T1_T2_
	.def	__ZSt13__adjust_heapIP3datiS0_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_T0_SB_T1_T2_;	.scl	2;	.type	32;	.endef
__ZSt13__adjust_heapIP3datiS0_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_T0_SB_T1_T2_:
LFB8304:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$76, %esp
	.cfi_def_cfa_offset 96
	movl	104(%esp), %edi
	movl	108(%esp), %edx
	movl	112(%esp), %esi
	movl	116(%esp), %eax
	movl	120(%esp), %ecx
	movl	96(%esp), %ebp
	leal	-1(%edi), %ebx
	movl	%edx, 32(%esp)
	movl	%esi, 36(%esp)
	movl	%eax, 40(%esp)
	movl	%ebx, %edi
	movl	%ecx, 44(%esp)
	shrl	$31, %edi
	addl	%ebx, %edi
	sarl	%edi
	cmpl	%edi, 100(%esp)
	movl	%edi, 28(%esp)
	jge	L33
	movl	100(%esp), %edi
	.p2align 4,,10
L35:
	leal	1(%edi), %ebx
	leal	(%ebx,%ebx), %esi
	sall	$5, %ebx
	addl	%ebp, %ebx
	leal	268435455(%esi), %eax
	movl	%ebx, (%esp)
	sall	$4, %eax
	addl	%ebp, %eax
	movl	%eax, 4(%esp)
	call	*124(%esp)
	testb	%al, %al
	je	L34
	subl	$1, %esi
	movl	%esi, %ebx
	sall	$4, %ebx
	addl	%ebp, %ebx
L34:
	movl	(%ebx), %eax
	sall	$4, %edi
	addl	%ebp, %edi
	cmpl	28(%esp), %esi
	movl	%eax, (%edi)
	movl	4(%ebx), %eax
	movl	%eax, 4(%edi)
	movl	8(%ebx), %eax
	movl	%eax, 8(%edi)
	movl	12(%ebx), %eax
	movl	%eax, 12(%edi)
	movl	%esi, %edi
	jl	L35
	testb	$1, 104(%esp)
	jne	L36
L41:
	movl	104(%esp), %eax
	leal	-2(%eax), %ecx
	movl	%ecx, %eax
	shrl	$31, %eax
	addl	%ecx, %eax
	sarl	%eax
	cmpl	%esi, %eax
	je	L49
L36:
	movl	32(%esp), %eax
	cmpl	100(%esp), %esi
	movl	%eax, 48(%esp)
	movl	36(%esp), %eax
	movl	%eax, 52(%esp)
	movl	40(%esp), %eax
	movl	%eax, 56(%esp)
	movl	44(%esp), %eax
	movl	%eax, 60(%esp)
	jg	L50
L37:
	movl	48(%esp), %eax
	movl	%eax, (%ebx)
	movl	52(%esp), %eax
	movl	%eax, 4(%ebx)
	movl	56(%esp), %eax
	movl	%eax, 8(%ebx)
	movl	60(%esp), %eax
	movl	%eax, 12(%ebx)
	addl	$76, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
L49:
	.cfi_restore_state
	leal	2(%esi,%esi), %esi
	leal	268435455(%esi), %eax
	subl	$1, %esi
	sall	$4, %eax
	addl	%ebp, %eax
	movl	(%eax), %ecx
	movl	%ecx, (%ebx)
	movl	4(%eax), %ecx
	movl	%ecx, 4(%ebx)
	movl	8(%eax), %ecx
	movl	%ecx, 8(%ebx)
	movl	12(%eax), %eax
	movl	%eax, 12(%ebx)
	movl	%esi, %ebx
	sall	$4, %ebx
	addl	%ebp, %ebx
	jmp	L36
	.p2align 4,,10
L50:
	leal	-1(%esi), %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	addl	%eax, %ecx
	sarl	%ecx
	movl	%ecx, %edi
	movl	100(%esp), %ecx
	.p2align 4,,10
L39:
	movl	%edi, %ebx
	leal	48(%esp), %eax
	movl	%ecx, 28(%esp)
	sall	$4, %ebx
	sall	$4, %esi
	addl	%ebp, %ebx
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	*124(%esp)
	testb	%al, %al
	movl	28(%esp), %ecx
	jne	L38
	leal	0(%ebp,%esi), %ebx
	jmp	L37
	.p2align 4,,10
L38:
	movl	(%ebx), %eax
	addl	%ebp, %esi
	movl	%eax, (%esi)
	movl	4(%ebx), %eax
	movl	%eax, 4(%esi)
	movl	8(%ebx), %eax
	movl	%eax, 8(%esi)
	movl	12(%ebx), %eax
	movl	%eax, 12(%esi)
	leal	-1(%edi), %esi
	movl	%esi, %eax
	shrl	$31, %eax
	addl	%esi, %eax
	sarl	%eax
	cmpl	%edi, %ecx
	jge	L37
	movl	%edi, %esi
	movl	%eax, %edi
	jmp	L39
L33:
	testb	$1, 104(%esp)
	jne	L40
	movl	100(%esp), %ebx
	movl	100(%esp), %esi
	sall	$4, %ebx
	addl	%ebp, %ebx
	jmp	L41
L40:
	movl	100(%esp), %ebx
	movl	%edx, 48(%esp)
	movl	%esi, 52(%esp)
	movl	%eax, 56(%esp)
	movl	%ecx, 60(%esp)
	sall	$4, %ebx
	addl	%ebp, %ebx
	jmp	L37
	.cfi_endproc
LFE8304:
	.text
	.p2align 4,,15
	.def	__ZSt16__introsort_loopIP3datiN9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_SA_T0_T1_.constprop.5;	.scl	3;	.type	32;	.endef
__ZSt16__introsort_loopIP3datiN9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_SA_T0_T1_.constprop.5:
LFB8344:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%edx, %ebp
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	%eax, %ebp
	subl	$92, %esp
	.cfi_def_cfa_offset 112
	cmpl	$271, %ebp
	movl	%eax, 44(%esp)
	movl	%edx, 52(%esp)
	movl	%ecx, 56(%esp)
	jle	L51
	testl	%ecx, %ecx
	je	L78
	addl	$32, %eax
	movl	%eax, 60(%esp)
L54:
	movl	44(%esp), %ecx
	sarl	$5, %ebp
	subl	$1, 56(%esp)
	sall	$4, %ebp
	movl	%ecx, %eax
	movl	16(%ecx), %edi
	addl	%ebp, %eax
	movl	20(%ecx), %ecx
	movl	4(%eax), %edx
	movl	(%eax), %ebp
	cmpl	%edx, %ecx
	jg	L58
	jl	L79
	cmpl	%ebp, %edi
	jnb	L58
L79:
	movl	52(%esp), %ebx
	movl	-16(%ebx), %esi
	movl	-12(%ebx), %ebx
	cmpl	%ebx, %edx
	jle	L95
L60:
	cmpl	%ebx, %ecx
	jg	L82
	jl	L81
	cmpl	%esi, %edi
	jb	L81
L82:
	movl	44(%esp), %edi
	movl	16(%edi), %ebx
	movl	(%edi), %eax
	movl	4(%edi), %edx
	movl	8(%edi), %ecx
	movl	%ebx, (%edi)
	movl	20(%edi), %ebx
	movl	%eax, 16(%edi)
	movl	%edx, 20(%edi)
	movl	%ebx, 4(%edi)
	movl	24(%edi), %ebx
	movl	%ecx, 24(%edi)
	movl	%ebx, 8(%edi)
	movl	28(%edi), %ebx
	movl	%ebx, 12(%edi)
L94:
	movl	52(%esp), %eax
	movl	-16(%eax), %edi
	movl	-12(%eax), %eax
	movl	%edi, 48(%esp)
	movl	%eax, 40(%esp)
L62:
	movl	44(%esp), %eax
	movl	60(%esp), %edx
	movl	(%eax), %edi
	movl	4(%eax), %ecx
	movl	52(%esp), %eax
	jmp	L65
	.p2align 4,,10
L97:
	cmpl	%edi, 48(%esp)
	ja	L87
	.p2align 4,,10
L72:
	cmpl	%ebx, %eax
	jbe	L96
	.p2align 4,,10
L76:
	movl	(%eax), %ebx
	movl	-8(%edx), %ecx
	movl	%ebx, -16(%edx)
	movl	4(%eax), %ebx
	movl	%ebx, -12(%edx)
	movl	8(%eax), %ebx
	movl	%ebx, -8(%edx)
	movl	12(%eax), %ebx
	movl	%ebx, -4(%edx)
	movl	%esi, 4(%eax)
	movl	44(%esp), %esi
	movl	%ebp, (%eax)
	movl	%ecx, 8(%eax)
	movl	(%esi), %edi
	movl	4(%esi), %ecx
	movl	-16(%eax), %esi
	movl	%esi, 48(%esp)
	movl	-12(%eax), %esi
	movl	%esi, 40(%esp)
L70:
	addl	$16, %edx
L65:
	movl	-12(%edx), %esi
	leal	-16(%edx), %ebx
	movl	-16(%edx), %ebp
	movl	%ebx, 36(%esp)
	cmpl	%ecx, %esi
	jl	L70
	jg	L84
	cmpl	%edi, %ebp
	jb	L70
L84:
	subl	$16, %eax
	cmpl	%ecx, 40(%esp)
	jl	L72
	jle	L97
	.p2align 4,,10
L87:
	subl	$16, %eax
	cmpl	%ecx, 4(%eax)
	jg	L87
	jl	L72
	cmpl	%edi, (%eax)
	ja	L87
	cmpl	%ebx, %eax
	ja	L76
L96:
	movl	112(%esp), %eax
	movl	56(%esp), %ecx
	movl	%ebx, %ebp
	movl	52(%esp), %edx
	movl	%eax, (%esp)
	movl	%ebx, %eax
	call	__ZSt16__introsort_loopIP3datiN9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_SA_T0_T1_.constprop.5
	subl	44(%esp), %ebp
	cmpl	$271, %ebp
	jle	L51
	movl	56(%esp), %eax
	movl	%ebx, 52(%esp)
	testl	%eax, %eax
	jne	L54
L53:
	sarl	$4, %ebp
	leal	-2(%ebp), %edi
	movl	%ebp, 40(%esp)
	sarl	%edi
	movl	%edi, %ebx
	sall	$4, %ebx
	addl	44(%esp), %ebx
	jmp	L56
L98:
	subl	$1, %edi
L56:
	movl	4(%ebx), %ecx
	movl	12(%ebx), %eax
	subl	$16, %ebx
	movl	24(%ebx), %edx
	movl	16(%ebx), %esi
	movl	112(%esp), %ebp
	movl	%ecx, 68(%esp)
	movl	%eax, 76(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 12(%esp)
	movl	40(%esp), %ecx
	movl	44(%esp), %eax
	movl	%edx, 72(%esp)
	movl	%edx, 8(%esp)
	movl	%edi, %edx
	movl	%esi, 64(%esp)
	movl	%ebp, 16(%esp)
	movl	%esi, (%esp)
	call	__ZSt13__adjust_heapIP3datiS0_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_T0_SB_T1_T2_.constprop.10
	testl	%edi, %edi
	jne	L98
	movl	36(%esp), %ebx
	movl	44(%esp), %esi
L57:
	movl	(%esi), %edi
	subl	$16, %ebx
	movl	(%ebx), %ebp
	movl	12(%ebx), %eax
	movl	4(%ebx), %ecx
	movl	8(%ebx), %edx
	movl	%edi, (%ebx)
	movl	4(%esi), %edi
	movl	%eax, 36(%esp)
	movl	%eax, 76(%esp)
	movl	112(%esp), %eax
	movl	%ebp, 64(%esp)
	movl	%edi, 4(%ebx)
	movl	8(%esi), %edi
	movl	%ecx, 68(%esp)
	movl	%edx, 72(%esp)
	movl	%edi, 8(%ebx)
	movl	12(%esi), %edi
	movl	%edi, 12(%ebx)
	movl	%eax, 28(%esp)
	movl	%ebx, %edi
	movl	36(%esp), %eax
	subl	%esi, %edi
	movl	%ebp, 12(%esp)
	movl	%ecx, 16(%esp)
	movl	%edx, 20(%esp)
	movl	$0, 4(%esp)
	movl	%esi, (%esp)
	movl	%eax, 24(%esp)
	movl	%edi, %eax
	sarl	$4, %eax
	movl	%eax, 8(%esp)
	call	__ZSt13__adjust_heapIP3datiS0_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_T0_SB_T1_T2_
	cmpl	$31, %edi
	jg	L57
L51:
	addl	$92, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
L58:
	.cfi_restore_state
	movl	52(%esp), %ebx
	movl	-16(%ebx), %esi
	movl	-12(%ebx), %ebx
	cmpl	%ebx, %ecx
	jle	L99
L66:
	cmpl	%ebx, %edx
	jg	L68
	jl	L81
	cmpl	%esi, %ebp
	jnb	L68
L81:
	movl	52(%esp), %ecx
	movl	44(%esp), %edi
	movl	-16(%ecx), %edx
	movl	(%edi), %eax
	movl	%edx, (%edi)
	movl	-12(%ecx), %edx
	movl	%eax, %esi
	movl	%eax, 48(%esp)
	movl	4(%edi), %eax
	movl	%edx, 4(%edi)
	movl	-8(%ecx), %edx
	movl	%eax, %ebx
	movl	%eax, 40(%esp)
	movl	8(%edi), %eax
	movl	%edx, 8(%edi)
	movl	-4(%ecx), %edx
	movl	%edx, 12(%edi)
	movl	%esi, -16(%ecx)
	movl	%ebx, -12(%ecx)
	movl	%eax, -8(%ecx)
	jmp	L62
L95:
	jl	L68
	cmpl	%esi, %ebp
	jnb	L60
L68:
	movl	44(%esp), %edi
	movl	(%eax), %esi
	movl	(%edi), %ecx
	movl	%esi, (%edi)
	movl	4(%eax), %esi
	movl	4(%edi), %ebx
	movl	8(%edi), %edx
	movl	%esi, 4(%edi)
	movl	8(%eax), %esi
	movl	%esi, 8(%edi)
	movl	12(%eax), %esi
	movl	%esi, 12(%edi)
	movl	%ecx, (%eax)
	movl	%ebx, 4(%eax)
	movl	%edx, 8(%eax)
	jmp	L94
L99:
	jl	L82
	cmpl	%esi, %edi
	jnb	L66
	jmp	L82
L78:
	movl	%edx, 36(%esp)
	jmp	L53
	.cfi_endproc
LFE8344:
	.align 2
	.p2align 4,,15
	.globl	__ZN6FastIO5solveEv
	.def	__ZN6FastIO5solveEv;	.scl	2;	.type	32;	.endef
__ZN6FastIO5solveEv:
LFB7740:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA7740
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$156, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	__imp___iob, %eax
	movl	__imp___iob, %edi
	movl	4(%eax), %eax
	movl	%eax, -80(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%edi)
	movl	%edi, %eax
	jns	L310
	jmp	L318
	.p2align 4,,10
L319:
	cmpl	$-1, %ebx
	je	L100
	movl	__imp___iob, %eax
	movl	__imp___iob, %edi
	movl	4(%eax), %eax
	movl	%eax, -80(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%edi)
	movl	%edi, %eax
	js	L106
L310:
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	%edx, (%edi)
	movzbl	(%eax), %ebx
L102:
	leal	-48(%ebx), %eax
	cmpl	$9, %eax
	setbe	%dl
	cmpl	$45, %ebx
	sete	%cl
	orb	%cl, %dl
	je	L319
	cmpl	$45, %ebx
	movl	%edx, %esi
	je	L320
	xorl	%esi, %esi
L108:
	xorl	%edi, %edi
	cmpl	$9, %eax
	ja	L111
L321:
	movl	__imp___iob, %eax
	movl	__imp___iob, %ecx
	movl	4(%eax), %eax
	movl	%eax, -80(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%ecx)
	js	L112
	movl	(%ecx), %eax
	leal	1(%eax), %edx
	movl	%edx, (%ecx)
	movzbl	(%eax), %eax
L113:
	leal	0(,%edi,8), %edx
	leal	(%edx,%edi,2), %edx
	leal	-48(%ebx,%edx), %edi
	movl	%eax, %ebx
	leal	-48(%eax), %eax
	cmpl	$9, %eax
	jbe	L321
L111:
	movl	%esi, %eax
	testb	%al, %al
	je	L322
	movl	%edi, %eax
	negl	%edi
	notl	%eax
	movl	%eax, -132(%ebp)
L115:
	testl	%edi, %edi
	je	L100
L232:
	movl	__imp___iob, %eax
	movl	__imp___iob, %edi
	movl	%esp, -136(%ebp)
	movl	4(%eax), %eax
	movl	%eax, -80(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%edi)
	movl	%edi, %eax
	js	L323
L311:
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	%edx, (%edi)
	movzbl	(%eax), %eax
L117:
	leal	-48(%eax), %ecx
	cmpl	$9, %ecx
	setbe	%dl
	cmpl	$45, %eax
	sete	%bl
	orb	%bl, %dl
	jne	L120
	cmpl	$-1, %eax
	je	L121
	movl	__imp___iob, %eax
	movl	__imp___iob, %edi
	movl	4(%eax), %eax
	movl	%eax, -80(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%edi)
	movl	%edi, %eax
	jns	L311
	movl	%edi, (%esp)
	call	__filbuf
	jmp	L117
L318:
	movl	%edi, (%esp)
	call	__filbuf
	cmpl	$-1, %eax
	movl	%eax, %ebx
	jne	L102
L100:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
L106:
	.cfi_restore_state
	movl	%edi, (%esp)
	call	__filbuf
	movl	%eax, %ebx
	jmp	L102
L320:
	movl	__imp___iob, %eax
	movl	__imp___iob, %edi
	movl	4(%eax), %eax
	movl	%eax, -80(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%edi)
	js	L109
	movl	(%edi), %eax
	leal	1(%eax), %edx
	movl	%edx, (%edi)
	movzbl	(%eax), %ebx
	leal	-48(%ebx), %eax
	jmp	L108
L112:
	movl	%ecx, (%esp)
	call	__filbuf
	jmp	L113
	.p2align 4,,10
L121:
	movl	$48, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	movl	$0, -128(%ebp)
	movl	$0, -104(%ebp)
	leal	19(%esp), %eax
	movl	$20, -108(%ebp)
	movl	$80, -100(%ebp)
	movl	$0, -88(%ebp)
	movl	$62, -112(%ebp)
	andl	$-8, %eax
	movl	%eax, -124(%ebp)
L132:
	movl	-112(%ebp), %ecx
	shrl	$4, %ecx
	sall	$4, %ecx
	movl	%ecx, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	19(%esp), %edx
	shrl	$3, %edx
	leal	0(,%edx,8), %eax
	movl	%eax, -120(%ebp)
	movl	%ecx, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	19(%esp), %eax
	andl	$-8, %eax
	movl	%eax, -112(%ebp)
	movl	-100(%ebp), %eax
	leal	16(%eax), %ecx
	movl	%ecx, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	19(%esp), %eax
	andl	$-8, %eax
	movl	%eax, -96(%ebp)
	movl	%ecx, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	19(%esp), %eax
	andl	$-8, %eax
	movl	%eax, -100(%ebp)
	movl	-108(%ebp), %eax
	addl	$18, %eax
	shrl	$4, %eax
	sall	$4, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	12(%esp), %eax
	movl	%eax, -108(%ebp)
	movl	-124(%ebp), %eax
	movl	(%eax), %ecx
	movl	4(%eax), %ebx
	movl	%ecx, 0(,%edx,8)
	movl	%ebx, 4(,%edx,8)
L236:
	movl	-96(%ebp), %ebx
	movl	-128(%ebp), %eax
	addl	%ebx, %eax
	movl	%eax, %edi
	movl	%eax, -80(%ebp)
	cmpl	%ebx, %edi
	je	L119
	movl	-128(%ebp), %edi
	movl	$__Z3cmpRK3datS1_, (%esp)
	movl	$31, %ecx
	movl	-96(%ebp), %ebx
	movl	-80(%ebp), %edx
	movl	%edi, %eax
	sarl	$4, %eax
	bsrl	%eax, %eax
	xorl	$31, %eax
	subl	%eax, %ecx
	movl	%ebx, %eax
	addl	%ecx, %ecx
LEHB0:
	call	__ZSt16__introsort_loopIP3datiN9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_SA_T0_T1_.constprop.5
	cmpl	$271, %edi
	jle	L154
	leal	256(%ebx), %edi
	leal	32(%ebx), %esi
	movl	$16, %ebx
	movl	%edi, -84(%ebp)
	jmp	L160
L325:
	jl	L249
	cmpl	(%edi), %ecx
	jnb	L155
L249:
	movl	-8(%esi), %edi
	movl	%edx, -116(%ebp)
	movl	$16, %edx
	movl	%ecx, -92(%ebp)
	movl	%ebx, 8(%esp)
	subl	%ebx, %edx
	movl	-96(%ebp), %ecx
	addl	%edx, %eax
	addl	$16, %ebx
	movl	%eax, (%esp)
	addl	$16, %esi
	movl	%ecx, 4(%esp)
	call	_memmove
	movl	-96(%ebp), %eax
	movl	-92(%ebp), %ecx
	cmpl	$256, %ebx
	movl	-116(%ebp), %edx
	movl	%ecx, (%eax)
	movl	%edi, 8(%eax)
	movl	%edx, 4(%eax)
	je	L324
L160:
	movl	-96(%ebp), %edi
	movl	-12(%esi), %edx
	leal	-16(%esi), %eax
	movl	-16(%esi), %ecx
	cmpl	4(%edi), %edx
	jle	L325
L155:
	movl	-16(%esi), %eax
	movl	%eax, -48(%ebp)
	movl	-12(%esi), %eax
	movl	%eax, -44(%ebp)
	movl	-8(%esi), %eax
	movl	%eax, -40(%ebp)
	movl	-4(%esi), %eax
	movl	%eax, -36(%ebp)
	movl	-96(%ebp), %eax
	leal	-16(%eax,%ebx), %edi
	jmp	L159
	.p2align 4,,10
L326:
	movl	(%edi), %eax
	subl	$16, %edi
	movl	%eax, 32(%edi)
	movl	20(%edi), %eax
	movl	%eax, 36(%edi)
	movl	24(%edi), %eax
	movl	%eax, 40(%edi)
	movl	28(%edi), %eax
	movl	%eax, 44(%edi)
L159:
	leal	-48(%ebp), %eax
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	__Z3cmpRK3datS1_
	testb	%al, %al
	jne	L326
	movl	-48(%ebp), %eax
	addl	$16, %ebx
	addl	$16, %esi
	cmpl	$256, %ebx
	movl	%eax, 16(%edi)
	movl	-44(%ebp), %eax
	movl	%eax, 20(%edi)
	movl	-40(%ebp), %eax
	movl	%eax, 24(%edi)
	movl	-36(%ebp), %eax
	movl	%eax, 28(%edi)
	jne	L160
L324:
	movl	-84(%ebp), %edi
	cmpl	%edi, -80(%ebp)
	je	L119
	leal	-48(%ebp), %ebx
L163:
	movl	(%edi), %eax
	leal	-16(%edi), %esi
	movl	%eax, -48(%ebp)
	movl	4(%edi), %eax
	movl	%eax, -44(%ebp)
	movl	8(%edi), %eax
	movl	%eax, -40(%ebp)
	movl	12(%edi), %eax
	movl	%eax, -36(%ebp)
	jmp	L162
	.p2align 4,,10
L327:
	movl	(%esi), %eax
	subl	$16, %esi
	movl	%eax, 32(%esi)
	movl	20(%esi), %eax
	movl	%eax, 36(%esi)
	movl	24(%esi), %eax
	movl	%eax, 40(%esi)
	movl	28(%esi), %eax
	movl	%eax, 44(%esi)
L162:
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__Z3cmpRK3datS1_
	testb	%al, %al
	jne	L327
	movl	-48(%ebp), %eax
	addl	$16, %edi
	cmpl	%edi, -80(%ebp)
	movl	%eax, 16(%esi)
	movl	-44(%ebp), %eax
	movl	%eax, 20(%esi)
	movl	-40(%ebp), %eax
	movl	%eax, 24(%esi)
	movl	-36(%ebp), %eax
	movl	%eax, 28(%esi)
	jne	L163
L119:
	movl	-104(%ebp), %ebx
	addl	$1, %ebx
	cmpl	$536870911, %ebx
	ja	L328
L152:
	leal	0(,%ebx,4), %eax
	movl	%eax, -140(%ebp)
	movl	%eax, (%esp)
	call	__Znaj
LEHE0:
	cmpl	$-1, -88(%ebp)
	movl	%eax, %esi
	je	L329
	movl	-88(%ebp), %edi
	movl	$0, 4(%esp)
	movl	%esi, (%esp)
	leal	4(,%edi,4), %eax
	movl	%eax, 8(%esp)
	call	_memset
	movl	%edi, %eax
	movl	-108(%ebp), %ecx
	leal	-1(%edi), %edi
	testl	%edi, %edi
	movl	%edi, -104(%ebp)
	movl	$0, (%ecx)
	jle	L173
	subl	$2, %eax
	movl	%eax, -144(%ebp)
	movl	%eax, -84(%ebp)
L186:
	movl	-84(%ebp), %eax
	cmpl	$-1, %edi
	movl	%eax, -116(%ebp)
	je	L175
	movl	-120(%ebp), %ecx
	movl	(%ecx,%eax,8), %edx
	movl	4(%ecx,%eax,8), %eax
	movl	%eax, %ecx
	movl	%eax, -80(%ebp)
	movl	%edi, %eax
	sall	$4, %eax
	addl	-96(%ebp), %eax
	movl	%edx, -92(%ebp)
	cmpl	%ecx, 4(%eax)
	jl	L175
	jg	L177
	cmpl	%edx, (%eax)
	jb	L175
L177:
	movl	%edi, %ecx
	sall	$4, %ecx
	addl	-96(%ebp), %ecx
	.p2align 4,,10
L179:
	movl	8(%ecx), %eax
	subl	$1, %edi
	addl	$1, %eax
	cmpl	%ebx, %eax
	jnb	L182
	.p2align 4,,10
L281:
	movl	%eax, %edx
	addl	$1, (%esi,%eax,4)
	negl	%edx
	andl	%eax, %edx
	addl	%edx, %eax
	cmpl	%ebx, %eax
	jb	L281
L182:
	cmpl	$-1, %edi
	je	L175
	subl	$16, %ecx
	movl	-80(%ebp), %eax
	cmpl	%eax, 4(%ecx)
	jge	L330
L175:
	movl	-84(%ebp), %eax
	xorl	%ecx, %ecx
	addl	$1, %eax
	.p2align 4,,10
L184:
	leal	-1(%eax), %edx
	addl	(%esi,%eax,4), %ecx
	andl	%edx, %eax
	jne	L184
	movl	-84(%ebp), %eax
	movl	-108(%ebp), %edx
	movl	%ecx, 4(%edx,%eax,4)
	movl	-116(%ebp), %ecx
	subl	$1, %eax
	movl	%eax, -84(%ebp)
	testl	%ecx, %ecx
	jg	L186
	movl	-104(%ebp), %edi
	movl	-124(%ebp), %eax
	movl	-144(%ebp), %ecx
	movl	4(%eax,%edi,8), %edx
	movl	(%eax,%edi,8), %eax
	movl	-112(%ebp), %edi
	testl	%ecx, %ecx
	movl	%eax, (%edi)
	movl	%edx, 4(%edi)
	js	L237
L187:
	movl	-88(%ebp), %edi
	movl	-112(%ebp), %eax
	movl	%esi, -80(%ebp)
	movl	%ebx, %esi
	movl	-112(%ebp), %ebx
	movl	-4(%eax,%edi,8), %edx
	movl	-8(%eax,%edi,8), %eax
	movl	-124(%ebp), %edi
L193:
	addl	(%edi,%ecx,8), %eax
	adcl	4(%edi,%ecx,8), %edx
	movl	%eax, (%ebx,%ecx,8)
	movl	%edx, 4(%ebx,%ecx,8)
	subl	$1, %ecx
	cmpl	$-1, %ecx
	jne	L193
	movl	%esi, %ebx
	movl	-80(%ebp), %esi
L192:
	movl	-104(%ebp), %edx
	testl	%edx, %edx
	js	L188
L237:
	movl	-104(%ebp), %ecx
	movl	-100(%ebp), %edi
	movl	%ebx, -80(%ebp)
	movl	%esi, -84(%ebp)
	movl	-124(%ebp), %ebx
	movl	-112(%ebp), %esi
	movl	%ecx, %eax
	sall	$4, %eax
	addl	%eax, %edi
L189:
	movl	(%ebx,%ecx,8), %eax
	addl	(%esi,%ecx,8), %eax
	movl	4(%ebx,%ecx,8), %edx
	adcl	4(%esi,%ecx,8), %edx
	subl	$16, %edi
	movl	%ecx, 24(%edi)
	subl	$1, %ecx
	movl	%eax, 16(%edi)
	movl	%edx, 20(%edi)
	cmpl	$-1, %ecx
	jne	L189
	movl	-80(%ebp), %ebx
	movl	-84(%ebp), %esi
L188:
	movl	-100(%ebp), %edi
	movl	-128(%ebp), %eax
	addl	%edi, %eax
	cmpl	%eax, %edi
	movl	%eax, -80(%ebp)
	je	L191
	movl	-128(%ebp), %edi
	movl	$31, %ecx
	movl	$__Z3cmpRK3datS1_, (%esp)
	movl	-80(%ebp), %edx
	movl	%edi, %eax
	sarl	$4, %eax
	bsrl	%eax, %eax
	xorl	$31, %eax
	subl	%eax, %ecx
	movl	-100(%ebp), %eax
	addl	%ecx, %ecx
LEHB1:
	call	__ZSt16__introsort_loopIP3datiN9__gnu_cxx5__ops15_Iter_comp_iterIPFbRKS0_S6_EEEEvT_SA_T0_T1_.constprop.5
	cmpl	$271, %edi
	jle	L195
	movl	-100(%ebp), %eax
	movl	%ebx, -92(%ebp)
	movl	%esi, -96(%ebp)
	leal	256(%eax), %edi
	addl	$32, %eax
	movl	%eax, %ebx
	movl	%edi, -84(%ebp)
	movl	$16, %edi
	movl	%edi, %esi
	jmp	L201
L332:
	jl	L252
	cmpl	(%edi), %ecx
	jnb	L196
L252:
	movl	-8(%ebx), %edi
	movl	%edx, -120(%ebp)
	movl	$16, %edx
	movl	%ecx, -116(%ebp)
	movl	%esi, 8(%esp)
	subl	%esi, %edx
	movl	-100(%ebp), %ecx
	addl	%edx, %eax
	addl	$16, %esi
	movl	%eax, (%esp)
	addl	$16, %ebx
	movl	%ecx, 4(%esp)
	call	_memmove
	movl	-100(%ebp), %eax
	movl	-116(%ebp), %ecx
	cmpl	$256, %esi
	movl	-120(%ebp), %edx
	movl	%ecx, (%eax)
	movl	%edi, 8(%eax)
	movl	%edx, 4(%eax)
	je	L331
L201:
	movl	-100(%ebp), %edi
	movl	-12(%ebx), %edx
	leal	-16(%ebx), %eax
	movl	-16(%ebx), %ecx
	cmpl	4(%edi), %edx
	jle	L332
L196:
	movl	-16(%ebx), %eax
	movl	%eax, -64(%ebp)
	movl	-12(%ebx), %eax
	movl	%eax, -60(%ebp)
	movl	-8(%ebx), %eax
	movl	%eax, -56(%ebp)
	movl	-4(%ebx), %eax
	movl	%eax, -52(%ebp)
	movl	-100(%ebp), %eax
	leal	-16(%eax,%esi), %edi
	jmp	L200
	.p2align 4,,10
L333:
	movl	(%edi), %eax
	subl	$16, %edi
	movl	%eax, 32(%edi)
	movl	20(%edi), %eax
	movl	%eax, 36(%edi)
	movl	24(%edi), %eax
	movl	%eax, 40(%edi)
	movl	28(%edi), %eax
	movl	%eax, 44(%edi)
L200:
	leal	-64(%ebp), %eax
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	__Z3cmpRK3datS1_
	testb	%al, %al
	jne	L333
	movl	-64(%ebp), %eax
	addl	$16, %esi
	addl	$16, %ebx
	cmpl	$256, %esi
	movl	%eax, 16(%edi)
	movl	-60(%ebp), %eax
	movl	%eax, 20(%edi)
	movl	-56(%ebp), %eax
	movl	%eax, 24(%edi)
	movl	-52(%ebp), %eax
	movl	%eax, 28(%edi)
	jne	L201
L331:
	movl	-84(%ebp), %eax
	cmpl	%eax, -80(%ebp)
	movl	-92(%ebp), %ebx
	movl	-96(%ebp), %esi
	je	L191
	movl	%ebx, -84(%ebp)
	movl	%eax, %edi
L204:
	movl	(%edi), %eax
	leal	-16(%edi), %ebx
	movl	%eax, -64(%ebp)
	movl	4(%edi), %eax
	movl	%eax, -60(%ebp)
	movl	8(%edi), %eax
	movl	%eax, -56(%ebp)
	movl	12(%edi), %eax
	movl	%eax, -52(%ebp)
	jmp	L203
	.p2align 4,,10
L334:
	movl	(%ebx), %eax
	subl	$16, %ebx
	movl	%eax, 32(%ebx)
	movl	20(%ebx), %eax
	movl	%eax, 36(%ebx)
	movl	24(%ebx), %eax
	movl	%eax, 40(%ebx)
	movl	28(%ebx), %eax
	movl	%eax, 44(%ebx)
L203:
	leal	-64(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z3cmpRK3datS1_
	testb	%al, %al
	jne	L334
	movl	-64(%ebp), %eax
	addl	$16, %edi
	cmpl	%edi, -80(%ebp)
	movl	%eax, 16(%ebx)
	movl	-60(%ebp), %eax
	movl	%eax, 20(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, 24(%ebx)
	movl	-52(%ebp), %eax
	movl	%eax, 28(%ebx)
	jne	L204
	movl	-84(%ebp), %ebx
L191:
	movl	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	__Znaj
LEHE1:
	cmpl	$-1, -88(%ebp)
	movl	%eax, %edi
	je	L312
	movl	-88(%ebp), %eax
	movl	$0, 4(%esp)
	movl	%edi, (%esp)
	leal	4(,%eax,4), %eax
	movl	%eax, 8(%esp)
	call	_memset
	movl	-104(%ebp), %eax
	testl	%eax, %eax
	jle	L213
	movl	-88(%ebp), %eax
	movl	%esi, -120(%ebp)
	movl	$1, -92(%ebp)
	subl	$1, %eax
	movl	%eax, -116(%ebp)
	movl	-104(%ebp), %eax
	movl	%eax, %esi
L228:
	movl	-92(%ebp), %eax
	cmpl	$-1, %esi
	movl	%eax, -96(%ebp)
	je	L217
	movl	-112(%ebp), %ecx
	movl	(%ecx,%eax,8), %edx
	movl	4(%ecx,%eax,8), %eax
	movl	%eax, %ecx
	movl	%eax, -80(%ebp)
	movl	%esi, %eax
	sall	$4, %eax
	addl	-100(%ebp), %eax
	movl	%edx, -84(%ebp)
	cmpl	%ecx, 4(%eax)
	jl	L217
	jg	L219
	cmpl	%edx, (%eax)
	jb	L217
L219:
	movl	%esi, %ecx
	sall	$4, %ecx
	addl	-100(%ebp), %ecx
	.p2align 4,,10
L221:
	movl	-88(%ebp), %eax
	subl	8(%ecx), %eax
	subl	$1, %esi
	cmpl	%ebx, %eax
	jnb	L224
	.p2align 4,,10
L282:
	movl	%eax, %edx
	addl	$1, (%edi,%eax,4)
	negl	%edx
	andl	%eax, %edx
	addl	%edx, %eax
	cmpl	%ebx, %eax
	jb	L282
L224:
	cmpl	$-1, %esi
	je	L217
	subl	$16, %ecx
	movl	-80(%ebp), %eax
	cmpl	%eax, 4(%ecx)
	jge	L335
L217:
	movl	-116(%ebp), %eax
	xorl	%ecx, %ecx
	testl	%eax, %eax
	je	L226
	.p2align 4,,10
L227:
	leal	-1(%eax), %edx
	addl	(%edi,%eax,4), %ecx
	andl	%edx, %eax
	jne	L227
L226:
	movl	-92(%ebp), %eax
	movl	-108(%ebp), %edx
	subl	$1, -116(%ebp)
	addl	%ecx, -4(%edx,%eax,4)
	addl	$1, %eax
	movl	-96(%ebp), %ecx
	cmpl	%ecx, -104(%ebp)
	movl	%eax, -92(%ebp)
	jg	L228
	movl	-120(%ebp), %esi
L213:
	movl	-88(%ebp), %eax
	testl	%eax, %eax
	jle	L312
	xorl	%ebx, %ebx
	movl	%esi, -80(%ebp)
	movl	%edi, -84(%ebp)
	movl	%ebx, %esi
	movl	-108(%ebp), %ebx
	movl	%eax, %edi
L231:
	xorl	%eax, %eax
	cmpl	-104(%ebp), %esi
	setne	%al
	subl	$1, %eax
	andl	$-22, %eax
	addl	$32, %eax
	movl	%eax, 8(%esp)
	movl	(%ebx,%esi,4), %eax
	addl	$1, %esi
	movl	$LC0, (%esp)
	movl	%eax, 4(%esp)
	call	_printf.constprop.17
	cmpl	%esi, %edi
	jne	L231
	movl	-80(%ebp), %esi
	movl	-84(%ebp), %edi
L312:
	movl	%edi, (%esp)
	call	__ZdaPv
	movl	%esi, (%esp)
	call	__ZdaPv
	subl	$1, -132(%ebp)
	movl	-136(%ebp), %esp
	movl	-132(%ebp), %eax
	cmpl	$-1, %eax
	jne	L232
	jmp	L100
	.p2align 4,,10
L330:
	jg	L179
	movl	-92(%ebp), %eax
	cmpl	%eax, (%ecx)
	jb	L175
	jmp	L179
	.p2align 4,,10
L335:
	jg	L221
	movl	-84(%ebp), %eax
	cmpl	%eax, (%ecx)
	jb	L217
	jmp	L221
L120:
	cmpl	$45, %eax
	je	L336
	xorl	%edx, %edx
L124:
	xorl	%ebx, %ebx
	movl	%edx, %esi
	jmp	L126
L337:
	movl	(%edi), %eax
	leal	1(%eax), %edx
	movl	%edx, (%edi)
	movzbl	(%eax), %eax
L129:
	leal	-48(%eax), %ecx
L126:
	cmpl	$9, %ecx
	ja	L127
	leal	0(,%ebx,8), %edx
	movl	__imp___iob, %edi
	leal	(%edx,%ebx,2), %edx
	leal	-48(%eax,%edx), %ebx
	movl	__imp___iob, %eax
	movl	4(%eax), %eax
	movl	%eax, -80(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%edi)
	jns	L337
	movl	%edi, (%esp)
	call	__filbuf
	jmp	L129
L127:
	movl	%esi, %edx
	testb	%dl, %dl
	je	L338
	movl	%ebx, %eax
	negl	%eax
	movl	%eax, %edi
	movl	%eax, -88(%ebp)
	movl	$5, %eax
	subl	%ebx, %eax
	movl	%edi, -104(%ebp)
	movl	%eax, %ebx
	leal	0(,%eax,8), %edx
	sall	$2, %eax
	movl	%eax, -108(%ebp)
	movl	%edi, %eax
	sall	$4, %ebx
	sall	$4, %eax
	movl	%ebx, -100(%ebp)
	movl	%eax, -128(%ebp)
L131:
	leal	22(%edx), %eax
	movl	%eax, -112(%ebp)
	shrl	$4, %eax
	sall	$4, %eax
	call	___chkstk_ms
	movl	-88(%ebp), %ebx
	subl	%eax, %esp
	leal	19(%esp), %eax
	shrl	$3, %eax
	movl	%eax, -116(%ebp)
	sall	$3, %eax
	testl	%ebx, %ebx
	movl	%eax, -92(%ebp)
	movl	%eax, -124(%ebp)
	jle	L132
	xorl	%edi, %edi
L148:
	movl	-92(%ebp), %eax
	movl	__imp___iob, %ebx
	movl	$0, (%eax,%edi,8)
	movl	$0, 4(%eax,%edi,8)
	movl	__imp___iob, %eax
	movl	4(%eax), %eax
	movl	%eax, -80(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%ebx)
	js	L133
	movl	(%ebx), %eax
	leal	1(%eax), %edx
	movl	%edx, (%ebx)
	movzbl	(%eax), %esi
	.p2align 4,,10
L134:
	leal	-48(%esi), %eax
	cmpl	$9, %eax
	setbe	%dl
	cmpl	$45, %esi
	sete	%cl
	orb	%cl, %dl
	jne	L137
	cmpl	$-1, %esi
	je	L136
	movl	__imp___iob, %eax
	movl	__imp___iob, %ecx
	movl	4(%eax), %eax
	movl	%eax, -80(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%ecx)
	js	L139
	movl	(%ecx), %eax
	leal	1(%eax), %edx
	movl	%edx, (%ecx)
	movzbl	(%eax), %esi
	jmp	L134
	.p2align 4,,10
L139:
	movl	%ecx, (%esp)
	call	__filbuf
	movl	%eax, %esi
	jmp	L134
L144:
	cmpb	$0, -96(%ebp)
	je	L136
	movl	%ecx, %eax
	movl	%ebx, %edx
	movl	-92(%ebp), %ebx
	negl	%eax
	adcl	$0, %edx
	negl	%edx
	movl	%eax, (%ebx,%edi,8)
	movl	%edx, 4(%ebx,%edi,8)
L136:
	addl	$1, %edi
	cmpl	-88(%ebp), %edi
	jne	L148
L341:
	movl	-112(%ebp), %edx
	shrl	$4, %edx
	sall	$4, %edx
	movl	%edx, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	movl	%edx, %eax
	leal	19(%esp), %ecx
	shrl	$3, %ecx
	leal	0(,%ecx,8), %esi
	movl	%esi, -120(%ebp)
	call	___chkstk_ms
	subl	%eax, %esp
	leal	19(%esp), %eax
	andl	$-8, %eax
	movl	%eax, -112(%ebp)
	movl	-100(%ebp), %eax
	leal	16(%eax), %edx
	movl	%edx, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	movl	%edx, %eax
	leal	19(%esp), %edi
	andl	$-8, %edi
	movl	%edi, -96(%ebp)
	call	___chkstk_ms
	subl	%eax, %esp
	leal	19(%esp), %eax
	andl	$-8, %eax
	movl	%eax, -100(%ebp)
	movl	-108(%ebp), %eax
	addl	$18, %eax
	shrl	$4, %eax
	sall	$4, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	cmpl	$1, -88(%ebp)
	leal	12(%esp), %eax
	movl	%eax, -108(%ebp)
	movl	-116(%ebp), %eax
	movl	4(,%eax,8), %edx
	movl	0(,%eax,8), %eax
	movl	%edx, 4(,%ecx,8)
	movl	%eax, 0(,%ecx,8)
	je	L234
	movl	%edi, -80(%ebp)
	movl	-88(%ebp), %ebx
	movl	%esi, %edi
	movl	-92(%ebp), %esi
	movl	$1, %ecx
L149:
	addl	(%esi,%ecx,8), %eax
	adcl	4(%esi,%ecx,8), %edx
	movl	%eax, (%edi,%ecx,8)
	movl	%edx, 4(%edi,%ecx,8)
	addl	$1, %ecx
	cmpl	%ebx, %ecx
	jl	L149
	movl	%edi, %esi
	movl	-80(%ebp), %edi
L234:
	xorl	%ecx, %ecx
	movl	%esi, %ebx
	movl	%edi, %edx
L150:
	movl	-92(%ebp), %edi
	movl	%ecx, %eax
	sall	$4, %eax
	movl	%ecx, 8(%edx,%eax)
	movl	(%edi,%ecx,8), %esi
	addl	(%ebx,%ecx,8), %esi
	movl	4(%edi,%ecx,8), %edi
	adcl	4(%ebx,%ecx,8), %edi
	addl	$1, %ecx
	cmpl	-88(%ebp), %ecx
	movl	%esi, (%edx,%eax)
	movl	%edi, 4(%edx,%eax)
	jl	L150
	jmp	L236
L137:
	cmpl	$45, %esi
	movb	%dl, -96(%ebp)
	je	L339
	movb	$0, -96(%ebp)
L141:
	xorl	%ecx, %ecx
	xorl	%ebx, %ebx
	movl	%ecx, -80(%ebp)
	movl	%ebx, -76(%ebp)
	jmp	L143
	.p2align 4,,10
L340:
	movl	(%ecx), %eax
	leal	1(%eax), %edx
	movl	%edx, (%ecx)
	movzbl	(%eax), %esi
L146:
	leal	-48(%esi), %eax
L143:
	cmpl	$9, %eax
	movl	-80(%ebp), %ecx
	movl	-76(%ebp), %ebx
	ja	L144
	movl	%ecx, %eax
	movl	%ebx, %edx
	shldl	$1, %eax, %edx
	shldl	$3, %ecx, %ebx
	addl	%eax, %eax
	sall	$3, %ecx
	addl	%ecx, %eax
	movl	%esi, %ecx
	adcl	%ebx, %edx
	movl	%esi, %ebx
	sarl	$31, %ebx
	addl	%eax, %ecx
	movl	-92(%ebp), %eax
	adcl	%edx, %ebx
	addl	$-48, %ecx
	adcl	$-1, %ebx
	movl	%ecx, -80(%ebp)
	movl	%ecx, (%eax,%edi,8)
	movl	%ebx, 4(%eax,%edi,8)
	movl	__imp___iob, %eax
	movl	__imp___iob, %ecx
	movl	%ebx, -76(%ebp)
	movl	4(%eax), %eax
	movl	%eax, -84(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%ecx)
	jns	L340
	movl	%ecx, (%esp)
	call	__filbuf
	movl	%eax, %esi
	jmp	L146
L133:
	movl	%ebx, (%esp)
	call	__filbuf
	cmpl	$-1, %eax
	movl	%eax, %esi
	jne	L134
	addl	$1, %edi
	cmpl	-88(%ebp), %edi
	jne	L148
	jmp	L341
	.p2align 4,,10
L339:
	movl	__imp___iob, %eax
	movl	__imp___iob, %ebx
	movl	4(%eax), %eax
	movl	%eax, -80(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%ebx)
	js	L142
	movl	(%ebx), %eax
	leal	1(%eax), %edx
	movl	%edx, (%ebx)
	movzbl	(%eax), %esi
	leal	-48(%esi), %eax
	jmp	L141
L195:
	movl	-100(%ebp), %edi
	movl	%edi, %eax
	addl	$16, %eax
	cmpl	%eax, -80(%ebp)
	je	L191
	movl	%edi, %eax
	leal	32(%edi), %edi
	movl	%ebx, -116(%ebp)
	movl	%esi, -120(%ebp)
	movl	$16, -84(%ebp)
	movl	%eax, %esi
	movl	%edi, %ebx
	jmp	L211
L343:
	jl	L253
	cmpl	(%esi), %ecx
	jnb	L205
L253:
	movl	-8(%ebx), %eax
	movl	%eax, -96(%ebp)
	movl	-84(%ebp), %eax
	sarl	$4, %eax
	testl	%eax, %eax
	je	L207
	movl	-84(%ebp), %eax
	movl	%ecx, -124(%ebp)
	movl	$16, %ecx
	movl	%edx, -128(%ebp)
	movl	%esi, 4(%esp)
	subl	%eax, %ecx
	movl	%eax, 8(%esp)
	movl	%ecx, %eax
	addl	%edi, %eax
	movl	%eax, (%esp)
	call	_memmove
	movl	-128(%ebp), %edx
	movl	-124(%ebp), %ecx
L207:
	addl	$16, %ebx
	addl	$16, -84(%ebp)
	movl	-92(%ebp), %edi
	cmpl	%edi, -80(%ebp)
	movl	-96(%ebp), %eax
	movl	%ecx, (%esi)
	movl	%edx, 4(%esi)
	movl	%eax, 8(%esi)
	je	L342
L211:
	movl	-12(%ebx), %edx
	cmpl	4(%esi), %edx
	leal	-16(%ebx), %edi
	movl	%ebx, -92(%ebp)
	movl	-16(%ebx), %ecx
	jle	L343
L205:
	movl	-16(%ebx), %eax
	leal	-32(%ebx), %edi
	movl	%eax, -64(%ebp)
	movl	-12(%ebx), %eax
	movl	%eax, -60(%ebp)
	movl	-8(%ebx), %eax
	movl	%eax, -56(%ebp)
	movl	-4(%ebx), %eax
	movl	%eax, -52(%ebp)
	jmp	L210
	.p2align 4,,10
L344:
	movl	(%edi), %eax
	subl	$16, %edi
	movl	%eax, 32(%edi)
	movl	20(%edi), %eax
	movl	%eax, 36(%edi)
	movl	24(%edi), %eax
	movl	%eax, 40(%edi)
	movl	28(%edi), %eax
	movl	%eax, 44(%edi)
L210:
	leal	-64(%ebp), %eax
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	__Z3cmpRK3datS1_
	testb	%al, %al
	jne	L344
	movl	-64(%ebp), %eax
	addl	$16, %ebx
	addl	$16, -84(%ebp)
	movl	%eax, 16(%edi)
	movl	-60(%ebp), %eax
	movl	%eax, 20(%edi)
	movl	-56(%ebp), %eax
	movl	%eax, 24(%edi)
	movl	-52(%ebp), %eax
	movl	%eax, 28(%edi)
	movl	-92(%ebp), %edi
	cmpl	%edi, -80(%ebp)
	jne	L211
L342:
	movl	-116(%ebp), %ebx
	movl	-120(%ebp), %esi
	jmp	L191
L154:
	movl	-96(%ebp), %edi
	movl	%edi, %eax
	addl	$16, %eax
	cmpl	%eax, -80(%ebp)
	je	L119
	leal	32(%edi), %esi
	movl	$16, -92(%ebp)
	leal	-48(%ebp), %edi
	jmp	L170
L345:
	jl	L250
	cmpl	(%eax), %ecx
	jnb	L164
L250:
	movl	-8(%esi), %eax
	movl	%eax, -116(%ebp)
	movl	-92(%ebp), %eax
	sarl	$4, %eax
	testl	%eax, %eax
	je	L166
	movl	-92(%ebp), %eax
	movl	%edx, -144(%ebp)
	movl	%ecx, -140(%ebp)
	movl	%eax, 8(%esp)
	movl	-96(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	$16, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	addl	%ebx, %eax
	movl	%eax, (%esp)
	call	_memmove
	movl	-144(%ebp), %edx
	movl	-140(%ebp), %ecx
L166:
	movl	-96(%ebp), %eax
	movl	-116(%ebp), %ebx
	movl	%ecx, (%eax)
	movl	%edx, 4(%eax)
	movl	%ebx, 8(%eax)
L167:
	addl	$16, %esi
	addl	$16, -92(%ebp)
	movl	-84(%ebp), %ebx
	cmpl	%ebx, -80(%ebp)
	je	L119
L170:
	movl	-96(%ebp), %eax
	movl	-12(%esi), %edx
	leal	-16(%esi), %ebx
	movl	%esi, -84(%ebp)
	movl	-16(%esi), %ecx
	cmpl	4(%eax), %edx
	jle	L345
L164:
	movl	-16(%esi), %eax
	leal	-32(%esi), %ebx
	movl	%eax, -48(%ebp)
	movl	-12(%esi), %eax
	movl	%eax, -44(%ebp)
	movl	-8(%esi), %eax
	movl	%eax, -40(%ebp)
	movl	-4(%esi), %eax
	movl	%eax, -36(%ebp)
	jmp	L169
	.p2align 4,,10
L346:
	movl	(%ebx), %eax
	subl	$16, %ebx
	movl	%eax, 32(%ebx)
	movl	20(%ebx), %eax
	movl	%eax, 36(%ebx)
	movl	24(%ebx), %eax
	movl	%eax, 40(%ebx)
	movl	28(%ebx), %eax
	movl	%eax, 44(%ebx)
L169:
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	__Z3cmpRK3datS1_
	testb	%al, %al
	jne	L346
	movl	-48(%ebp), %eax
	movl	%eax, 16(%ebx)
	movl	-44(%ebp), %eax
	movl	%eax, 20(%ebx)
	movl	-40(%ebp), %eax
	movl	%eax, 24(%ebx)
	movl	-36(%ebp), %eax
	movl	%eax, 28(%ebx)
	jmp	L167
L142:
	movl	%ebx, (%esp)
	call	__filbuf
	movl	%eax, %esi
	leal	-48(%eax), %eax
	jmp	L141
L323:
	movl	%edi, (%esp)
	call	__filbuf
	cmpl	$-1, %eax
	jne	L117
	movl	$48, %edx
	movl	%edx, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	19(%esp), %ecx
	shrl	$3, %ecx
	leal	0(,%ecx,8), %eax
	movl	%eax, -124(%ebp)
	movl	%edx, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	19(%esp), %ebx
	shrl	$3, %ebx
	leal	0(,%ebx,8), %eax
	movl	%eax, -120(%ebp)
	movl	%edx, %eax
	call	___chkstk_ms
	movl	$96, %edx
	subl	%eax, %esp
	leal	19(%esp), %eax
	andl	$-8, %eax
	movl	%eax, -112(%ebp)
	movl	%edx, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	19(%esp), %eax
	andl	$-8, %eax
	movl	%eax, -96(%ebp)
	movl	%edx, %eax
	call	___chkstk_ms
	movl	4(,%ecx,8), %edx
	subl	%eax, %esp
	movl	$0, -104(%ebp)
	movl	$0, -128(%ebp)
	leal	19(%esp), %eax
	movl	$0, -88(%ebp)
	movl	%edx, 4(,%ebx,8)
	andl	$-8, %eax
	movl	%eax, -100(%ebp)
	movl	0(,%ecx,8), %eax
	movl	%eax, 0(,%ebx,8)
	movl	-104(%ebp), %ebx
	leal	-48(%ebp), %eax
	movl	%eax, -108(%ebp)
	addl	$1, %ebx
	cmpl	$536870911, %ebx
	jbe	L152
L328:
LEHB2:
	call	___cxa_throw_bad_array_new_length
	.p2align 4,,10
L336:
	movl	__imp___iob, %eax
	movl	__imp___iob, %edi
	movl	4(%eax), %eax
	movl	%eax, -80(%ebp)
	subl	$1, %eax
	testl	%eax, %eax
	movl	%eax, 4(%edi)
	js	L125
	movl	(%edi), %eax
	leal	1(%eax), %ecx
	movl	%ecx, (%edi)
	movzbl	(%eax), %eax
	leal	-48(%eax), %ecx
	jmp	L124
L329:
	movl	-108(%ebp), %eax
	movl	-112(%ebp), %edi
	movl	$0, (%eax)
	movl	-124(%ebp), %eax
	movl	-12(%eax), %edx
	movl	-16(%eax), %eax
	movl	$-2, -104(%ebp)
	movl	%eax, (%edi)
	movl	%edx, 4(%edi)
	jmp	L188
L322:
	leal	-1(%edi), %eax
	movl	%eax, -132(%ebp)
	jmp	L115
L109:
	movl	%edi, (%esp)
	call	__filbuf
	movl	%eax, %ebx
	leal	-48(%eax), %eax
	jmp	L108
L338:
	leal	5(%ebx), %eax
	movl	%ebx, -104(%ebp)
	movl	%ebx, -88(%ebp)
	movl	%eax, %edi
	leal	0(,%eax,8), %edx
	sall	$2, %eax
	sall	$4, %edi
	movl	%eax, -108(%ebp)
	movl	%edi, -100(%ebp)
	subl	$80, %edi
	movl	%edi, -128(%ebp)
	jmp	L131
L173:
	movl	-124(%ebp), %eax
	movl	-88(%ebp), %ecx
	movl	4(%eax,%edi,8), %edx
	movl	(%eax,%edi,8), %eax
	subl	$2, %ecx
	movl	-112(%ebp), %edi
	movl	%eax, (%edi)
	movl	%edx, 4(%edi)
	jns	L187
	jmp	L192
L248:
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	__ZdaPv
	movl	%ebx, (%esp)
	call	__Unwind_Resume
LEHE2:
L125:
	movb	%dl, -80(%ebp)
	movl	%edi, (%esp)
	call	__filbuf
	movzbl	-80(%ebp), %edx
	leal	-48(%eax), %ecx
	jmp	L124
	.cfi_endproc
LFE7740:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA7740:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE7740-LLSDACSB7740
LLSDACSB7740:
	.uleb128 LEHB0-LFB7740
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB7740
	.uleb128 LEHE1-LEHB1
	.uleb128 L248-LFB7740
	.uleb128 0
	.uleb128 LEHB2-LFB7740
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE7740:
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB7739:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	leal	15(%esp), %ecx
	call	__ZN6FastIO5solveEv
	xorl	%eax, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE7739:
	.p2align 4,,15
	.def	__GLOBAL__sub_I__Z3cmpRK3datS1_;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z3cmpRK3datS1_:
LFB8327:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE8327:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z3cmpRK3datS1_
.lcomm __ZStL8__ioinit,1,1
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	___mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	__filbuf;	.scl	2;	.type	32;	.endef
	.def	_memmove;	.scl	2;	.type	32;	.endef
	.def	__Znaj;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	__ZdaPv;	.scl	2;	.type	32;	.endef
	.def	___cxa_throw_bad_array_new_length;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
