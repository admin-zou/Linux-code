
10_23:     file format elf32-i386


Disassembly of section .init:

080482d8 <_init>:
 80482d8:	55                   	push   %ebp
 80482d9:	89 e5                	mov    %esp,%ebp
 80482db:	53                   	push   %ebx
 80482dc:	83 ec 04             	sub    $0x4,%esp
 80482df:	e8 00 00 00 00       	call   80482e4 <_init+0xc>
 80482e4:	5b                   	pop    %ebx
 80482e5:	81 c3 e4 13 00 00    	add    $0x13e4,%ebx
 80482eb:	8b 93 fc ff ff ff    	mov    -0x4(%ebx),%edx
 80482f1:	85 d2                	test   %edx,%edx
 80482f3:	74 05                	je     80482fa <_init+0x22>
 80482f5:	e8 1e 00 00 00       	call   8048318 <__gmon_start__@plt>
 80482fa:	e8 f1 00 00 00       	call   80483f0 <frame_dummy>
 80482ff:	e8 ec 01 00 00       	call   80484f0 <__do_global_ctors_aux>
 8048304:	58                   	pop    %eax
 8048305:	5b                   	pop    %ebx
 8048306:	c9                   	leave  
 8048307:	c3                   	ret    

Disassembly of section .plt:

08048308 <__gmon_start__@plt-0x10>:
 8048308:	ff 35 cc 96 04 08    	pushl  0x80496cc
 804830e:	ff 25 d0 96 04 08    	jmp    *0x80496d0
 8048314:	00 00                	add    %al,(%eax)
	...

08048318 <__gmon_start__@plt>:
 8048318:	ff 25 d4 96 04 08    	jmp    *0x80496d4
 804831e:	68 00 00 00 00       	push   $0x0
 8048323:	e9 e0 ff ff ff       	jmp    8048308 <_init+0x30>

08048328 <putchar@plt>:
 8048328:	ff 25 d8 96 04 08    	jmp    *0x80496d8
 804832e:	68 08 00 00 00       	push   $0x8
 8048333:	e9 d0 ff ff ff       	jmp    8048308 <_init+0x30>

08048338 <__libc_start_main@plt>:
 8048338:	ff 25 dc 96 04 08    	jmp    *0x80496dc
 804833e:	68 10 00 00 00       	push   $0x10
 8048343:	e9 c0 ff ff ff       	jmp    8048308 <_init+0x30>

08048348 <__isoc99_scanf@plt>:
 8048348:	ff 25 e0 96 04 08    	jmp    *0x80496e0
 804834e:	68 18 00 00 00       	push   $0x18
 8048353:	e9 b0 ff ff ff       	jmp    8048308 <_init+0x30>

Disassembly of section .text:

08048360 <_start>:
 8048360:	31 ed                	xor    %ebp,%ebp
 8048362:	5e                   	pop    %esi
 8048363:	89 e1                	mov    %esp,%ecx
 8048365:	83 e4 f0             	and    $0xfffffff0,%esp
 8048368:	50                   	push   %eax
 8048369:	54                   	push   %esp
 804836a:	52                   	push   %edx
 804836b:	68 80 84 04 08       	push   $0x8048480
 8048370:	68 90 84 04 08       	push   $0x8048490
 8048375:	51                   	push   %ecx
 8048376:	56                   	push   %esi
 8048377:	68 43 84 04 08       	push   $0x8048443
 804837c:	e8 b7 ff ff ff       	call   8048338 <__libc_start_main@plt>
 8048381:	f4                   	hlt    
 8048382:	90                   	nop
 8048383:	90                   	nop
 8048384:	90                   	nop
 8048385:	90                   	nop
 8048386:	90                   	nop
 8048387:	90                   	nop
 8048388:	90                   	nop
 8048389:	90                   	nop
 804838a:	90                   	nop
 804838b:	90                   	nop
 804838c:	90                   	nop
 804838d:	90                   	nop
 804838e:	90                   	nop
 804838f:	90                   	nop

08048390 <__do_global_dtors_aux>:
 8048390:	55                   	push   %ebp
 8048391:	89 e5                	mov    %esp,%ebp
 8048393:	53                   	push   %ebx
 8048394:	8d 64 24 fc          	lea    -0x4(%esp),%esp
 8048398:	80 3d e8 96 04 08 00 	cmpb   $0x0,0x80496e8
 804839f:	75 3e                	jne    80483df <__do_global_dtors_aux+0x4f>
 80483a1:	bb f4 95 04 08       	mov    $0x80495f4,%ebx
 80483a6:	a1 ec 96 04 08       	mov    0x80496ec,%eax
 80483ab:	81 eb f0 95 04 08    	sub    $0x80495f0,%ebx
 80483b1:	c1 fb 02             	sar    $0x2,%ebx
 80483b4:	83 eb 01             	sub    $0x1,%ebx
 80483b7:	39 d8                	cmp    %ebx,%eax
 80483b9:	73 1d                	jae    80483d8 <__do_global_dtors_aux+0x48>
 80483bb:	90                   	nop
 80483bc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 80483c0:	83 c0 01             	add    $0x1,%eax
 80483c3:	a3 ec 96 04 08       	mov    %eax,0x80496ec
 80483c8:	ff 14 85 f0 95 04 08 	call   *0x80495f0(,%eax,4)
 80483cf:	a1 ec 96 04 08       	mov    0x80496ec,%eax
 80483d4:	39 d8                	cmp    %ebx,%eax
 80483d6:	72 e8                	jb     80483c0 <__do_global_dtors_aux+0x30>
 80483d8:	c6 05 e8 96 04 08 01 	movb   $0x1,0x80496e8
 80483df:	8d 64 24 04          	lea    0x4(%esp),%esp
 80483e3:	5b                   	pop    %ebx
 80483e4:	5d                   	pop    %ebp
 80483e5:	c3                   	ret    
 80483e6:	8d 76 00             	lea    0x0(%esi),%esi
 80483e9:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

080483f0 <frame_dummy>:
 80483f0:	55                   	push   %ebp
 80483f1:	89 e5                	mov    %esp,%ebp
 80483f3:	8d 64 24 e8          	lea    -0x18(%esp),%esp
 80483f7:	a1 f8 95 04 08       	mov    0x80495f8,%eax
 80483fc:	85 c0                	test   %eax,%eax
 80483fe:	74 12                	je     8048412 <frame_dummy+0x22>
 8048400:	b8 00 00 00 00       	mov    $0x0,%eax
 8048405:	85 c0                	test   %eax,%eax
 8048407:	74 09                	je     8048412 <frame_dummy+0x22>
 8048409:	c7 04 24 f8 95 04 08 	movl   $0x80495f8,(%esp)
 8048410:	ff d0                	call   *%eax
 8048412:	c9                   	leave  
 8048413:	c3                   	ret    

08048414 <rfact>:
 8048414:	55                   	push   %ebp
 8048415:	89 e5                	mov    %esp,%ebp
 8048417:	83 ec 28             	sub    $0x28,%esp
 804841a:	83 7d 08 01          	cmpl   $0x1,0x8(%ebp)
 804841e:	7f 09                	jg     8048429 <rfact+0x15>
 8048420:	c7 45 f4 01 00 00 00 	movl   $0x1,-0xc(%ebp)
 8048427:	eb 15                	jmp    804843e <rfact+0x2a>
 8048429:	8b 45 08             	mov    0x8(%ebp),%eax
 804842c:	83 e8 01             	sub    $0x1,%eax
 804842f:	89 04 24             	mov    %eax,(%esp)
 8048432:	e8 dd ff ff ff       	call   8048414 <rfact>
 8048437:	0f af 45 08          	imul   0x8(%ebp),%eax
 804843b:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804843e:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8048441:	c9                   	leave  
 8048442:	c3                   	ret    

08048443 <main>:
 8048443:	55                   	push   %ebp
 8048444:	89 e5                	mov    %esp,%ebp
 8048446:	83 e4 f0             	and    $0xfffffff0,%esp
 8048449:	83 ec 20             	sub    $0x20,%esp
 804844c:	b8 44 85 04 08       	mov    $0x8048544,%eax
 8048451:	8d 54 24 1c          	lea    0x1c(%esp),%edx
 8048455:	89 54 24 04          	mov    %edx,0x4(%esp)
 8048459:	89 04 24             	mov    %eax,(%esp)
 804845c:	e8 e7 fe ff ff       	call   8048348 <__isoc99_scanf@plt>
 8048461:	8b 44 24 1c          	mov    0x1c(%esp),%eax
 8048465:	89 04 24             	mov    %eax,(%esp)
 8048468:	e8 a7 ff ff ff       	call   8048414 <rfact>
 804846d:	c7 04 24 0a 00 00 00 	movl   $0xa,(%esp)
 8048474:	e8 af fe ff ff       	call   8048328 <putchar@plt>
 8048479:	c9                   	leave  
 804847a:	c3                   	ret    
 804847b:	90                   	nop
 804847c:	90                   	nop
 804847d:	90                   	nop
 804847e:	90                   	nop
 804847f:	90                   	nop

08048480 <__libc_csu_fini>:
 8048480:	55                   	push   %ebp
 8048481:	89 e5                	mov    %esp,%ebp
 8048483:	5d                   	pop    %ebp
 8048484:	c3                   	ret    
 8048485:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%eax,%eax,1)
 804848c:	00 00 00 00 

08048490 <__libc_csu_init>:
 8048490:	55                   	push   %ebp
 8048491:	89 e5                	mov    %esp,%ebp
 8048493:	57                   	push   %edi
 8048494:	56                   	push   %esi
 8048495:	53                   	push   %ebx
 8048496:	e8 4f 00 00 00       	call   80484ea <__i686.get_pc_thunk.bx>
 804849b:	81 c3 2d 12 00 00    	add    $0x122d,%ebx
 80484a1:	83 ec 1c             	sub    $0x1c,%esp
 80484a4:	e8 2f fe ff ff       	call   80482d8 <_init>
 80484a9:	8d bb 20 ff ff ff    	lea    -0xe0(%ebx),%edi
 80484af:	8d 83 20 ff ff ff    	lea    -0xe0(%ebx),%eax
 80484b5:	29 c7                	sub    %eax,%edi
 80484b7:	c1 ff 02             	sar    $0x2,%edi
 80484ba:	85 ff                	test   %edi,%edi
 80484bc:	74 24                	je     80484e2 <__libc_csu_init+0x52>
 80484be:	31 f6                	xor    %esi,%esi
 80484c0:	8b 45 10             	mov    0x10(%ebp),%eax
 80484c3:	89 44 24 08          	mov    %eax,0x8(%esp)
 80484c7:	8b 45 0c             	mov    0xc(%ebp),%eax
 80484ca:	89 44 24 04          	mov    %eax,0x4(%esp)
 80484ce:	8b 45 08             	mov    0x8(%ebp),%eax
 80484d1:	89 04 24             	mov    %eax,(%esp)
 80484d4:	ff 94 b3 20 ff ff ff 	call   *-0xe0(%ebx,%esi,4)
 80484db:	83 c6 01             	add    $0x1,%esi
 80484de:	39 fe                	cmp    %edi,%esi
 80484e0:	72 de                	jb     80484c0 <__libc_csu_init+0x30>
 80484e2:	83 c4 1c             	add    $0x1c,%esp
 80484e5:	5b                   	pop    %ebx
 80484e6:	5e                   	pop    %esi
 80484e7:	5f                   	pop    %edi
 80484e8:	5d                   	pop    %ebp
 80484e9:	c3                   	ret    

080484ea <__i686.get_pc_thunk.bx>:
 80484ea:	8b 1c 24             	mov    (%esp),%ebx
 80484ed:	c3                   	ret    
 80484ee:	90                   	nop
 80484ef:	90                   	nop

080484f0 <__do_global_ctors_aux>:
 80484f0:	55                   	push   %ebp
 80484f1:	89 e5                	mov    %esp,%ebp
 80484f3:	53                   	push   %ebx
 80484f4:	8d 64 24 fc          	lea    -0x4(%esp),%esp
 80484f8:	a1 e8 95 04 08       	mov    0x80495e8,%eax
 80484fd:	83 f8 ff             	cmp    $0xffffffff,%eax
 8048500:	74 12                	je     8048514 <__do_global_ctors_aux+0x24>
 8048502:	bb e8 95 04 08       	mov    $0x80495e8,%ebx
 8048507:	90                   	nop
 8048508:	8d 5b fc             	lea    -0x4(%ebx),%ebx
 804850b:	ff d0                	call   *%eax
 804850d:	8b 03                	mov    (%ebx),%eax
 804850f:	83 f8 ff             	cmp    $0xffffffff,%eax
 8048512:	75 f4                	jne    8048508 <__do_global_ctors_aux+0x18>
 8048514:	8d 64 24 04          	lea    0x4(%esp),%esp
 8048518:	5b                   	pop    %ebx
 8048519:	5d                   	pop    %ebp
 804851a:	c3                   	ret    
 804851b:	90                   	nop

Disassembly of section .fini:

0804851c <_fini>:
 804851c:	55                   	push   %ebp
 804851d:	89 e5                	mov    %esp,%ebp
 804851f:	53                   	push   %ebx
 8048520:	83 ec 04             	sub    $0x4,%esp
 8048523:	e8 00 00 00 00       	call   8048528 <_fini+0xc>
 8048528:	5b                   	pop    %ebx
 8048529:	81 c3 a0 11 00 00    	add    $0x11a0,%ebx
 804852f:	e8 5c fe ff ff       	call   8048390 <__do_global_dtors_aux>
 8048534:	59                   	pop    %ecx
 8048535:	5b                   	pop    %ebx
 8048536:	c9                   	leave  
 8048537:	c3                   	ret    
