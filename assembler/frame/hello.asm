
a.out：     文件格式 elf64-x86-64


Disassembly of section .init:

00000000004003e0 <_init>:
  4003e0:	48 83 ec 08          	sub    $0x8,%rsp
  4003e4:	48 8b 05 0d 0c 20 00 	mov    0x200c0d(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  4003eb:	48 85 c0             	test   %rax,%rax
  4003ee:	74 05                	je     4003f5 <_init+0x15>
  4003f0:	e8 3b 00 00 00       	callq  400430 <__gmon_start__@plt>
  4003f5:	48 83 c4 08          	add    $0x8,%rsp
  4003f9:	c3                   	retq   

Disassembly of section .plt:

0000000000400400 <printf@plt-0x10>:
  400400:	ff 35 02 0c 20 00    	pushq  0x200c02(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400406:	ff 25 04 0c 20 00    	jmpq   *0x200c04(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40040c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400410 <printf@plt>:
  400410:	ff 25 02 0c 20 00    	jmpq   *0x200c02(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400416:	68 00 00 00 00       	pushq  $0x0
  40041b:	e9 e0 ff ff ff       	jmpq   400400 <_init+0x20>

0000000000400420 <__libc_start_main@plt>:
  400420:	ff 25 fa 0b 20 00    	jmpq   *0x200bfa(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400426:	68 01 00 00 00       	pushq  $0x1
  40042b:	e9 d0 ff ff ff       	jmpq   400400 <_init+0x20>

0000000000400430 <__gmon_start__@plt>:
  400430:	ff 25 f2 0b 20 00    	jmpq   *0x200bf2(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400436:	68 02 00 00 00       	pushq  $0x2
  40043b:	e9 c0 ff ff ff       	jmpq   400400 <_init+0x20>

Disassembly of section .text:

0000000000400440 <_start>:
  400440:	31 ed                	xor    %ebp,%ebp
  400442:	49 89 d1             	mov    %rdx,%r9
  400445:	5e                   	pop    %rsi
  400446:	48 89 e2             	mov    %rsp,%rdx
  400449:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40044d:	50                   	push   %rax
  40044e:	54                   	push   %rsp
  40044f:	49 c7 c0 10 06 40 00 	mov    $0x400610,%r8
  400456:	48 c7 c1 a0 05 40 00 	mov    $0x4005a0,%rcx
  40045d:	48 c7 c7 63 05 40 00 	mov    $0x400563,%rdi
  400464:	e8 b7 ff ff ff       	callq  400420 <__libc_start_main@plt>
  400469:	f4                   	hlt    
  40046a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400470 <deregister_tm_clones>:
  400470:	b8 67 10 60 00       	mov    $0x601067,%eax
  400475:	55                   	push   %rbp
  400476:	48 2d 60 10 60 00    	sub    $0x601060,%rax
  40047c:	48 83 f8 0e          	cmp    $0xe,%rax
  400480:	48 89 e5             	mov    %rsp,%rbp
  400483:	77 02                	ja     400487 <deregister_tm_clones+0x17>
  400485:	5d                   	pop    %rbp
  400486:	c3                   	retq   
  400487:	b8 00 00 00 00       	mov    $0x0,%eax
  40048c:	48 85 c0             	test   %rax,%rax
  40048f:	74 f4                	je     400485 <deregister_tm_clones+0x15>
  400491:	5d                   	pop    %rbp
  400492:	bf 60 10 60 00       	mov    $0x601060,%edi
  400497:	ff e0                	jmpq   *%rax
  400499:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004004a0 <register_tm_clones>:
  4004a0:	b8 60 10 60 00       	mov    $0x601060,%eax
  4004a5:	55                   	push   %rbp
  4004a6:	48 2d 60 10 60 00    	sub    $0x601060,%rax
  4004ac:	48 c1 f8 03          	sar    $0x3,%rax
  4004b0:	48 89 e5             	mov    %rsp,%rbp
  4004b3:	48 89 c2             	mov    %rax,%rdx
  4004b6:	48 c1 ea 3f          	shr    $0x3f,%rdx
  4004ba:	48 01 d0             	add    %rdx,%rax
  4004bd:	48 d1 f8             	sar    %rax
  4004c0:	75 02                	jne    4004c4 <register_tm_clones+0x24>
  4004c2:	5d                   	pop    %rbp
  4004c3:	c3                   	retq   
  4004c4:	ba 00 00 00 00       	mov    $0x0,%edx
  4004c9:	48 85 d2             	test   %rdx,%rdx
  4004cc:	74 f4                	je     4004c2 <register_tm_clones+0x22>
  4004ce:	5d                   	pop    %rbp
  4004cf:	48 89 c6             	mov    %rax,%rsi
  4004d2:	bf 60 10 60 00       	mov    $0x601060,%edi
  4004d7:	ff e2                	jmpq   *%rdx
  4004d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004004e0 <__do_global_dtors_aux>:
  4004e0:	80 3d 79 0b 20 00 00 	cmpb   $0x0,0x200b79(%rip)        # 601060 <__TMC_END__>
  4004e7:	75 11                	jne    4004fa <__do_global_dtors_aux+0x1a>
  4004e9:	55                   	push   %rbp
  4004ea:	48 89 e5             	mov    %rsp,%rbp
  4004ed:	e8 7e ff ff ff       	callq  400470 <deregister_tm_clones>
  4004f2:	5d                   	pop    %rbp
  4004f3:	c6 05 66 0b 20 00 01 	movb   $0x1,0x200b66(%rip)        # 601060 <__TMC_END__>
  4004fa:	f3 c3                	repz retq 
  4004fc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400500 <frame_dummy>:
  400500:	48 83 3d 18 09 20 00 	cmpq   $0x0,0x200918(%rip)        # 600e20 <__JCR_END__>
  400507:	00 
  400508:	74 1e                	je     400528 <frame_dummy+0x28>
  40050a:	b8 00 00 00 00       	mov    $0x0,%eax
  40050f:	48 85 c0             	test   %rax,%rax
  400512:	74 14                	je     400528 <frame_dummy+0x28>
  400514:	55                   	push   %rbp
  400515:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  40051a:	48 89 e5             	mov    %rsp,%rbp
  40051d:	ff d0                	callq  *%rax
  40051f:	5d                   	pop    %rbp
  400520:	e9 7b ff ff ff       	jmpq   4004a0 <register_tm_clones>
  400525:	0f 1f 00             	nopl   (%rax)
  400528:	e9 73 ff ff ff       	jmpq   4004a0 <register_tm_clones>

000000000040052d <helloworld>:
  40052d:	55                   	push   %rbp
  40052e:	48 89 e5             	mov    %rsp,%rbp
  400531:	48 89 e8             	mov    %rbp,%rax
  400534:	48 89 c6             	mov    %rax,%rsi
  400537:	bf 30 06 40 00       	mov    $0x400630,%edi
  40053c:	b8 00 00 00 00       	mov    $0x0,%eax
  400541:	e8 ca fe ff ff       	callq  400410 <printf@plt>
  400546:	48 8b 45 00          	mov    0x0(%rbp),%rax
  40054a:	48 89 c6             	mov    %rax,%rsi
  40054d:	bf 3b 06 40 00       	mov    $0x40063b,%edi
  400552:	b8 00 00 00 00       	mov    $0x0,%eax
  400557:	e8 b4 fe ff ff       	callq  400410 <printf@plt>
  40055c:	b8 00 00 00 00       	mov    $0x0,%eax
  400561:	5d                   	pop    %rbp
  400562:	c3                   	retq   

0000000000400563 <main>:
  400563:	55                   	push   %rbp
  400564:	48 89 e5             	mov    %rsp,%rbp
  400567:	48 83 ec 10          	sub    $0x10,%rsp
  40056b:	89 7d fc             	mov    %edi,-0x4(%rbp)
  40056e:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  400572:	48 8b 15 cf 0a 20 00 	mov    0x200acf(%rip),%rdx        # 601048 <T1+0x8>
  400579:	b8 00 00 00 00       	mov    $0x0,%eax
  40057e:	ff d2                	callq  *%rdx
  400580:	48 8b 15 d1 0a 20 00 	mov    0x200ad1(%rip),%rdx        # 601058 <T2+0x8>
  400587:	b8 00 00 00 00       	mov    $0x0,%eax
  40058c:	ff d2                	callq  *%rdx
  40058e:	b8 03 00 00 00       	mov    $0x3,%eax
  400593:	c9                   	leaveq 
  400594:	c3                   	retq   
  400595:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40059c:	00 00 00 
  40059f:	90                   	nop

00000000004005a0 <__libc_csu_init>:
  4005a0:	41 57                	push   %r15
  4005a2:	41 89 ff             	mov    %edi,%r15d
  4005a5:	41 56                	push   %r14
  4005a7:	49 89 f6             	mov    %rsi,%r14
  4005aa:	41 55                	push   %r13
  4005ac:	49 89 d5             	mov    %rdx,%r13
  4005af:	41 54                	push   %r12
  4005b1:	4c 8d 25 58 08 20 00 	lea    0x200858(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  4005b8:	55                   	push   %rbp
  4005b9:	48 8d 2d 58 08 20 00 	lea    0x200858(%rip),%rbp        # 600e18 <__init_array_end>
  4005c0:	53                   	push   %rbx
  4005c1:	4c 29 e5             	sub    %r12,%rbp
  4005c4:	31 db                	xor    %ebx,%ebx
  4005c6:	48 c1 fd 03          	sar    $0x3,%rbp
  4005ca:	48 83 ec 08          	sub    $0x8,%rsp
  4005ce:	e8 0d fe ff ff       	callq  4003e0 <_init>
  4005d3:	48 85 ed             	test   %rbp,%rbp
  4005d6:	74 1e                	je     4005f6 <__libc_csu_init+0x56>
  4005d8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4005df:	00 
  4005e0:	4c 89 ea             	mov    %r13,%rdx
  4005e3:	4c 89 f6             	mov    %r14,%rsi
  4005e6:	44 89 ff             	mov    %r15d,%edi
  4005e9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4005ed:	48 83 c3 01          	add    $0x1,%rbx
  4005f1:	48 39 eb             	cmp    %rbp,%rbx
  4005f4:	75 ea                	jne    4005e0 <__libc_csu_init+0x40>
  4005f6:	48 83 c4 08          	add    $0x8,%rsp
  4005fa:	5b                   	pop    %rbx
  4005fb:	5d                   	pop    %rbp
  4005fc:	41 5c                	pop    %r12
  4005fe:	41 5d                	pop    %r13
  400600:	41 5e                	pop    %r14
  400602:	41 5f                	pop    %r15
  400604:	c3                   	retq   
  400605:	90                   	nop
  400606:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40060d:	00 00 00 

0000000000400610 <__libc_csu_fini>:
  400610:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400614 <_fini>:
  400614:	48 83 ec 08          	sub    $0x8,%rsp
  400618:	48 83 c4 08          	add    $0x8,%rsp
  40061c:	c3                   	retq   
