
10_20:     file format elf32-i386


Disassembly of section .init:

08048294 <_init>:
 8048294:	55                   	push   %ebp
 8048295:	89 e5                	mov    %esp,%ebp
 8048297:	53                   	push   %ebx
 8048298:	83 ec 04             	sub    $0x4,%esp
 804829b:	e8 00 00 00 00       	call   80482a0 <_init+0xc>
 80482a0:	5b                   	pop    %ebx
 80482a1:	81 c3 f4 13 00 00    	add    $0x13f4,%ebx
 80482a7:	8b 93 fc ff ff ff    	mov    -0x4(%ebx),%edx
 80482ad:	85 d2                	test   %edx,%edx
 80482af:	74 05                	je     80482b6 <_init+0x22>
 80482b1:	e8 1e 00 00 00       	call   80482d4 <__gmon_start__@plt>
 80482b6:	e8 e5 00 00 00       	call   80483a0 <frame_dummy>
 80482bb:	e8 e0 01 00 00       	call   80484a0 <__do_global_ctors_aux>
 80482c0:	58                   	pop    %eax
 80482c1:	5b                   	pop    %ebx
 80482c2:	c9                   	leave  
 80482c3:	c3                   	ret    

Disassembly of section .plt:

080482c4 <__gmon_start__@plt-0x10>:
 80482c4:	ff 35 98 96 04 08    	pushl  0x8049698
 80482ca:	ff 25 9c 96 04 08    	jmp    *0x804969c
 80482d0:	00 00                	add    %al,(%eax)
	...

080482d4 <__gmon_start__@plt>:
 80482d4:	ff 25 a0 96 04 08    	jmp    *0x80496a0
 80482da:	68 00 00 00 00       	push   $0x0
 80482df:	e9 e0 ff ff ff       	jmp    80482c4 <_init+0x30>

080482e4 <__libc_start_main@plt>:
 80482e4:	ff 25 a4 96 04 08    	jmp    *0x80496a4
 80482ea:	68 08 00 00 00       	push   $0x8
 80482ef:	e9 d0 ff ff ff       	jmp    80482c4 <_init+0x30>

080482f4 <printf@plt>:
 80482f4:	ff 25 a8 96 04 08    	jmp    *0x80496a8
 80482fa:	68 10 00 00 00       	push   $0x10
 80482ff:	e9 c0 ff ff ff       	jmp    80482c4 <_init+0x30>

Disassembly of section .text:

08048310 <_start>:
 8048310:	31 ed                	xor    %ebp,%ebp
 8048312:	5e                   	pop    %esi
 8048313:	89 e1                	mov    %esp,%ecx
 8048315:	83 e4 f0             	and    $0xfffffff0,%esp
 8048318:	50                   	push   %eax
 8048319:	54                   	push   %esp
 804831a:	52                   	push   %edx
 804831b:	68 30 84 04 08       	push   $0x8048430
 8048320:	68 40 84 04 08       	push   $0x8048440
 8048325:	51                   	push   %ecx
 8048326:	56                   	push   %esi
 8048327:	68 d6 83 04 08       	push   $0x80483d6
 804832c:	e8 b3 ff ff ff       	call   80482e4 <__libc_start_main@plt>
 8048331:	f4                   	hlt    
 8048332:	90                   	nop
 8048333:	90                   	nop
 8048334:	90                   	nop
 8048335:	90                   	nop
 8048336:	90                   	nop
 8048337:	90                   	nop
 8048338:	90                   	nop
 8048339:	90                   	nop
 804833a:	90                   	nop
 804833b:	90                   	nop
 804833c:	90                   	nop
 804833d:	90                   	nop
 804833e:	90                   	nop
 804833f:	90                   	nop

08048340 <__do_global_dtors_aux>:
 8048340:	55                   	push   %ebp
 8048341:	89 e5                	mov    %esp,%ebp
 8048343:	53                   	push   %ebx
 8048344:	8d 64 24 fc          	lea    -0x4(%esp),%esp
 8048348:	80 3d b0 96 04 08 00 	cmpb   $0x0,0x80496b0
 804834f:	75 3e                	jne    804838f <__do_global_dtors_aux+0x4f>
 8048351:	bb c0 95 04 08       	mov    $0x80495c0,%ebx
 8048356:	a1 b4 96 04 08       	mov    0x80496b4,%eax
 804835b:	81 eb bc 95 04 08    	sub    $0x80495bc,%ebx
 8048361:	c1 fb 02             	sar    $0x2,%ebx
 8048364:	83 eb 01             	sub    $0x1,%ebx
 8048367:	39 d8                	cmp    %ebx,%eax
 8048369:	73 1d                	jae    8048388 <__do_global_dtors_aux+0x48>
 804836b:	90                   	nop
 804836c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8048370:	83 c0 01             	add    $0x1,%eax
 8048373:	a3 b4 96 04 08       	mov    %eax,0x80496b4
 8048378:	ff 14 85 bc 95 04 08 	call   *0x80495bc(,%eax,4)
 804837f:	a1 b4 96 04 08       	mov    0x80496b4,%eax
 8048384:	39 d8                	cmp    %ebx,%eax
 8048386:	72 e8                	jb     8048370 <__do_global_dtors_aux+0x30>
 8048388:	c6 05 b0 96 04 08 01 	movb   $0x1,0x80496b0
 804838f:	8d 64 24 04          	lea    0x4(%esp),%esp
 8048393:	5b                   	pop    %ebx
 8048394:	5d                   	pop    %ebp
 8048395:	c3                   	ret    
 8048396:	8d 76 00             	lea    0x0(%esi),%esi
 8048399:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

080483a0 <frame_dummy>:
 80483a0:	55                   	push   %ebp
 80483a1:	89 e5                	mov    %esp,%ebp
 80483a3:	8d 64 24 e8          	lea    -0x18(%esp),%esp
 80483a7:	a1 c4 95 04 08       	mov    0x80495c4,%eax
 80483ac:	85 c0                	test   %eax,%eax
 80483ae:	74 12                	je     80483c2 <frame_dummy+0x22>
 80483b0:	b8 00 00 00 00       	mov    $0x0,%eax
 80483b5:	85 c0                	test   %eax,%eax
 80483b7:	74 09                	je     80483c2 <frame_dummy+0x22>
 80483b9:	c7 04 24 c4 95 04 08 	movl   $0x80495c4,(%esp)
 80483c0:	ff d0                	call   *%eax
 80483c2:	c9                   	leave  
 80483c3:	c3                   	ret    

080483c4 <stack_test>:
 80483c4:	55                   	push   %ebp
 80483c5:	89 e5                	mov    %esp,%ebp
 80483c7:	83 ec 10             	sub    $0x10,%esp
 80483ca:	c7 45 fc 33 33 00 00 	movl   $0x3333,-0x4(%ebp)
 80483d1:	8b 45 fc             	mov    -0x4(%ebp),%eax
 80483d4:	c9                   	leave  
 80483d5:	c3                   	ret    

080483d6 <main>:
 80483d6:	55                   	push   %ebp
 80483d7:	89 e5                	mov    %esp,%ebp
 80483d9:	83 e4 f0             	and    $0xfffffff0,%esp
 80483dc:	83 ec 20             	sub    $0x20,%esp
 80483df:	c7 44 24 14 11 11 00 	movl   $0x1111,0x14(%esp)
 80483e6:	00 
 80483e7:	c7 44 24 18 22 22 00 	movl   $0x2222,0x18(%esp)
 80483ee:	00 
 80483ef:	8b 44 24 18          	mov    0x18(%esp),%eax
 80483f3:	89 44 24 04          	mov    %eax,0x4(%esp)
 80483f7:	8b 44 24 14          	mov    0x14(%esp),%eax
 80483fb:	89 04 24             	mov    %eax,(%esp)
 80483fe:	e8 c1 ff ff ff       	call   80483c4 <stack_test>
 8048403:	89 44 24 1c          	mov    %eax,0x1c(%esp)
 8048407:	b8 f4 84 04 08       	mov    $0x80484f4,%eax
 804840c:	8b 54 24 1c          	mov    0x1c(%esp),%edx
 8048410:	89 54 24 04          	mov    %edx,0x4(%esp)
 8048414:	89 04 24             	mov    %eax,(%esp)
 8048417:	e8 d8 fe ff ff       	call   80482f4 <printf@plt>
 804841c:	b8 00 00 00 00       	mov    $0x0,%eax
 8048421:	c9                   	leave  
 8048422:	c3                   	ret    
 8048423:	90                   	nop
 8048424:	90                   	nop
 8048425:	90                   	nop
 8048426:	90                   	nop
 8048427:	90                   	nop
 8048428:	90                   	nop
 8048429:	90                   	nop
 804842a:	90                   	nop
 804842b:	90                   	nop
 804842c:	90                   	nop
 804842d:	90                   	nop
 804842e:	90                   	nop
 804842f:	90                   	nop

08048430 <__libc_csu_fini>:
 8048430:	55                   	push   %ebp
 8048431:	89 e5                	mov    %esp,%ebp
 8048433:	5d                   	pop    %ebp
 8048434:	c3                   	ret    
 8048435:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%eax,%eax,1)
 804843c:	00 00 00 00 

08048440 <__libc_csu_init>:
 8048440:	55                   	push   %ebp
 8048441:	89 e5                	mov    %esp,%ebp
 8048443:	57                   	push   %edi
 8048444:	56                   	push   %esi
 8048445:	53                   	push   %ebx
 8048446:	e8 4f 00 00 00       	call   804849a <__i686.get_pc_thunk.bx>
 804844b:	81 c3 49 12 00 00    	add    $0x1249,%ebx
 8048451:	83 ec 1c             	sub    $0x1c,%esp
 8048454:	e8 3b fe ff ff       	call   8048294 <_init>
 8048459:	8d bb 20 ff ff ff    	lea    -0xe0(%ebx),%edi
 804845f:	8d 83 20 ff ff ff    	lea    -0xe0(%ebx),%eax
 8048465:	29 c7                	sub    %eax,%edi
 8048467:	c1 ff 02             	sar    $0x2,%edi
 804846a:	85 ff                	test   %edi,%edi
 804846c:	74 24                	je     8048492 <__libc_csu_init+0x52>
 804846e:	31 f6                	xor    %esi,%esi
 8048470:	8b 45 10             	mov    0x10(%ebp),%eax
 8048473:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048477:	8b 45 0c             	mov    0xc(%ebp),%eax
 804847a:	89 44 24 04          	mov    %eax,0x4(%esp)
 804847e:	8b 45 08             	mov    0x8(%ebp),%eax
 8048481:	89 04 24             	mov    %eax,(%esp)
 8048484:	ff 94 b3 20 ff ff ff 	call   *-0xe0(%ebx,%esi,4)
 804848b:	83 c6 01             	add    $0x1,%esi
 804848e:	39 fe                	cmp    %edi,%esi
 8048490:	72 de                	jb     8048470 <__libc_csu_init+0x30>
 8048492:	83 c4 1c             	add    $0x1c,%esp
 8048495:	5b                   	pop    %ebx
 8048496:	5e                   	pop    %esi
 8048497:	5f                   	pop    %edi
 8048498:	5d                   	pop    %ebp
 8048499:	c3                   	ret    

0804849a <__i686.get_pc_thunk.bx>:
 804849a:	8b 1c 24             	mov    (%esp),%ebx
 804849d:	c3                   	ret    
 804849e:	90                   	nop
 804849f:	90                   	nop

080484a0 <__do_global_ctors_aux>:
 80484a0:	55                   	push   %ebp
 80484a1:	89 e5                	mov    %esp,%ebp
 80484a3:	53                   	push   %ebx
 80484a4:	8d 64 24 fc          	lea    -0x4(%esp),%esp
 80484a8:	a1 b4 95 04 08       	mov    0x80495b4,%eax
 80484ad:	83 f8 ff             	cmp    $0xffffffff,%eax
 80484b0:	74 12                	je     80484c4 <__do_global_ctors_aux+0x24>
 80484b2:	bb b4 95 04 08       	mov    $0x80495b4,%ebx
 80484b7:	90                   	nop
 80484b8:	8d 5b fc             	lea    -0x4(%ebx),%ebx
 80484bb:	ff d0                	call   *%eax
 80484bd:	8b 03                	mov    (%ebx),%eax
 80484bf:	83 f8 ff             	cmp    $0xffffffff,%eax
 80484c2:	75 f4                	jne    80484b8 <__do_global_ctors_aux+0x18>
 80484c4:	8d 64 24 04          	lea    0x4(%esp),%esp
 80484c8:	5b                   	pop    %ebx
 80484c9:	5d                   	pop    %ebp
 80484ca:	c3                   	ret    
 80484cb:	90                   	nop

Disassembly of section .fini:

080484cc <_fini>:
 80484cc:	55                   	push   %ebp
 80484cd:	89 e5                	mov    %esp,%ebp
 80484cf:	53                   	push   %ebx
 80484d0:	83 ec 04             	sub    $0x4,%esp
 80484d3:	e8 00 00 00 00       	call   80484d8 <_fini+0xc>
 80484d8:	5b                   	pop    %ebx
 80484d9:	81 c3 bc 11 00 00    	add    $0x11bc,%ebx
 80484df:	e8 5c fe ff ff       	call   8048340 <__do_global_dtors_aux>
 80484e4:	59                   	pop    %ecx
 80484e5:	5b                   	pop    %ebx
 80484e6:	c9                   	leave  
 80484e7:	c3                   	ret    
