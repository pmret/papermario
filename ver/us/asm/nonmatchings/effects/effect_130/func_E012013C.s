.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E012013C
/* 40B52C E012013C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 40B530 E0120140 AFBF0020 */  sw        $ra, 0x20($sp)
/* 40B534 E0120144 AFB3001C */  sw        $s3, 0x1c($sp)
/* 40B538 E0120148 AFB20018 */  sw        $s2, 0x18($sp)
/* 40B53C E012014C AFB10014 */  sw        $s1, 0x14($sp)
/* 40B540 E0120150 AFB00010 */  sw        $s0, 0x10($sp)
/* 40B544 E0120154 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 40B548 E0120158 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 40B54C E012015C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 40B550 E0120160 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 40B554 E0120164 8C830000 */  lw        $v1, ($a0)
/* 40B558 E0120168 8C85000C */  lw        $a1, 0xc($a0)
/* 40B55C E012016C 30620010 */  andi      $v0, $v1, 0x10
/* 40B560 E0120170 10400005 */  beqz      $v0, .LE0120188
/* 40B564 E0120174 2402FFEF */   addiu    $v0, $zero, -0x11
/* 40B568 E0120178 00621024 */  and       $v0, $v1, $v0
/* 40B56C E012017C AC820000 */  sw        $v0, ($a0)
/* 40B570 E0120180 24020010 */  addiu     $v0, $zero, 0x10
/* 40B574 E0120184 ACA20010 */  sw        $v0, 0x10($a1)
.LE0120188:
/* 40B578 E0120188 8CA30010 */  lw        $v1, 0x10($a1)
/* 40B57C E012018C 286203E8 */  slti      $v0, $v1, 0x3e8
/* 40B580 E0120190 10400002 */  beqz      $v0, .LE012019C
/* 40B584 E0120194 2462FFFF */   addiu    $v0, $v1, -1
/* 40B588 E0120198 ACA20010 */  sw        $v0, 0x10($a1)
.LE012019C:
/* 40B58C E012019C 3C030004 */  lui       $v1, 4
/* 40B590 E01201A0 8CA20014 */  lw        $v0, 0x14($a1)
/* 40B594 E01201A4 3463F1A0 */  ori       $v1, $v1, 0xf1a0
/* 40B598 E01201A8 24420001 */  addiu     $v0, $v0, 1
/* 40B59C E01201AC 0062182A */  slt       $v1, $v1, $v0
/* 40B5A0 E01201B0 10600003 */  beqz      $v1, .LE01201C0
/* 40B5A4 E01201B4 ACA20014 */   sw       $v0, 0x14($a1)
/* 40B5A8 E01201B8 24020100 */  addiu     $v0, $zero, 0x100
/* 40B5AC E01201BC ACA20014 */  sw        $v0, 0x14($a1)
.LE01201C0:
/* 40B5B0 E01201C0 8CA20010 */  lw        $v0, 0x10($a1)
/* 40B5B4 E01201C4 04410005 */  bgez      $v0, .LE01201DC
/* 40B5B8 E01201C8 28420010 */   slti     $v0, $v0, 0x10
/* 40B5BC E01201CC 0C080128 */  jal       func_E02004A0
/* 40B5C0 E01201D0 00000000 */   nop
/* 40B5C4 E01201D4 080480DC */  j         .LE0120370
/* 40B5C8 E01201D8 00000000 */   nop
.LE01201DC:
/* 40B5CC E01201DC 10400006 */  beqz      $v0, .LE01201F8
/* 40B5D0 E01201E0 8CB30014 */   lw       $s3, 0x14($a1)
/* 40B5D4 E01201E4 8CA20038 */  lw        $v0, 0x38($a1)
/* 40B5D8 E01201E8 2442FFF0 */  addiu     $v0, $v0, -0x10
/* 40B5DC E01201EC 04410002 */  bgez      $v0, .LE01201F8
/* 40B5E0 E01201F0 ACA20038 */   sw       $v0, 0x38($a1)
/* 40B5E4 E01201F4 ACA00038 */  sw        $zero, 0x38($a1)
.LE01201F8:
/* 40B5E8 E01201F8 8CA2003C */  lw        $v0, 0x3c($a1)
/* 40B5EC E01201FC 04410003 */  bgez      $v0, .LE012020C
/* 40B5F0 E0120200 28420100 */   slti     $v0, $v0, 0x100
/* 40B5F4 E0120204 08048086 */  j         .LE0120218
/* 40B5F8 E0120208 ACA0003C */   sw       $zero, 0x3c($a1)
.LE012020C:
/* 40B5FC E012020C 14400002 */  bnez      $v0, .LE0120218
/* 40B600 E0120210 240200FF */   addiu    $v0, $zero, 0xff
/* 40B604 E0120214 ACA2003C */  sw        $v0, 0x3c($a1)
.LE0120218:
/* 40B608 E0120218 8CA30038 */  lw        $v1, 0x38($a1)
/* 40B60C E012021C 8CA4003C */  lw        $a0, 0x3c($a1)
/* 40B610 E0120220 0083102A */  slt       $v0, $a0, $v1
/* 40B614 E0120224 10400004 */  beqz      $v0, .LE0120238
/* 40B618 E0120228 2462FFF8 */   addiu    $v0, $v1, -8
/* 40B61C E012022C ACA20038 */  sw        $v0, 0x38($a1)
/* 40B620 E0120230 08048094 */  j         .LE0120250
/* 40B624 E0120234 0044102A */   slt      $v0, $v0, $a0
.LE0120238:
/* 40B628 E0120238 0064102A */  slt       $v0, $v1, $a0
/* 40B62C E012023C 10400006 */  beqz      $v0, .LE0120258
/* 40B630 E0120240 24620008 */   addiu    $v0, $v1, 8
/* 40B634 E0120244 8CA4003C */  lw        $a0, 0x3c($a1)
/* 40B638 E0120248 ACA20038 */  sw        $v0, 0x38($a1)
/* 40B63C E012024C 0082102A */  slt       $v0, $a0, $v0
.LE0120250:
/* 40B640 E0120250 54400001 */  bnel      $v0, $zero, .LE0120258
/* 40B644 E0120254 ACA40038 */   sw       $a0, 0x38($a1)
.LE0120258:
/* 40B648 E0120258 0000882D */  daddu     $s1, $zero, $zero
/* 40B64C E012025C 00A0802D */  daddu     $s0, $a1, $zero
/* 40B650 E0120260 00139040 */  sll       $s2, $s3, 1
/* 40B654 E0120264 3C013FD0 */  lui       $at, 0x3fd0
/* 40B658 E0120268 4481D800 */  mtc1      $at, $f27
/* 40B65C E012026C 4480D000 */  mtc1      $zero, $f26
/* 40B660 E0120270 3C01E012 */  lui       $at, %hi(D_E01207A0)
/* 40B664 E0120274 D43807A0 */  ldc1      $f24, %lo(D_E01207A0)($at)
/* 40B668 E0120278 3C014380 */  lui       $at, 0x4380
/* 40B66C E012027C 4481B000 */  mtc1      $at, $f22
.LE0120280:
/* 40B670 E0120280 44926000 */  mtc1      $s2, $f12
/* 40B674 E0120284 00000000 */  nop
/* 40B678 E0120288 0C080140 */  jal       func_E0200500
/* 40B67C E012028C 46806320 */   cvt.s.w  $f12, $f12
/* 40B680 E0120290 44936000 */  mtc1      $s3, $f12
/* 40B684 E0120294 00000000 */  nop
/* 40B688 E0120298 46806320 */  cvt.s.w   $f12, $f12
/* 40B68C E012029C 46006321 */  cvt.d.s   $f12, $f12
/* 40B690 E01202A0 463A6302 */  mul.d     $f12, $f12, $f26
/* 40B694 E01202A4 00000000 */  nop
/* 40B698 E01202A8 02310018 */  mult      $s1, $s1
/* 40B69C E01202AC 00001812 */  mflo      $v1
/* 40B6A0 E01202B0 00031080 */  sll       $v0, $v1, 2
/* 40B6A4 E01202B4 00431021 */  addu      $v0, $v0, $v1
/* 40B6A8 E01202B8 00021080 */  sll       $v0, $v0, 2
/* 40B6AC E01202BC 44821000 */  mtc1      $v0, $f2
/* 40B6B0 E01202C0 00000000 */  nop
/* 40B6B4 E01202C4 468010A1 */  cvt.d.w   $f2, $f2
/* 40B6B8 E01202C8 46226300 */  add.d     $f12, $f12, $f2
/* 40B6BC E01202CC 46000506 */  mov.s     $f20, $f0
/* 40B6C0 E01202D0 0C080140 */  jal       func_E0200500
/* 40B6C4 E01202D4 46206320 */   cvt.s.d  $f12, $f12
/* 40B6C8 E01202D8 4600A521 */  cvt.d.s   $f20, $f20
/* 40B6CC E01202DC 4638A502 */  mul.d     $f20, $f20, $f24
/* 40B6D0 E01202E0 00000000 */  nop
/* 40B6D4 E01202E4 3C01E012 */  lui       $at, %hi(D_E01207A8)
/* 40B6D8 E01202E8 D42207A8 */  ldc1      $f2, %lo(D_E01207A8)($at)
/* 40B6DC E01202EC 4622A500 */  add.d     $f20, $f20, $f2
/* 40B6E0 E01202F0 3C014010 */  lui       $at, 0x4010
/* 40B6E4 E01202F4 44811800 */  mtc1      $at, $f3
/* 40B6E8 E01202F8 44801000 */  mtc1      $zero, $f2
/* 40B6EC E01202FC 00000000 */  nop
/* 40B6F0 E0120300 4622A502 */  mul.d     $f20, $f20, $f2
/* 40B6F4 E0120304 00000000 */  nop
/* 40B6F8 E0120308 46000021 */  cvt.d.s   $f0, $f0
/* 40B6FC E012030C 4620A502 */  mul.d     $f20, $f20, $f0
/* 40B700 E0120310 00000000 */  nop
/* 40B704 E0120314 C6000020 */  lwc1      $f0, 0x20($s0)
/* 40B708 E0120318 46000021 */  cvt.d.s   $f0, $f0
/* 40B70C E012031C 46340001 */  sub.d     $f0, $f0, $f20
/* 40B710 E0120320 44801000 */  mtc1      $zero, $f2
/* 40B714 E0120324 46200020 */  cvt.s.d   $f0, $f0
/* 40B718 E0120328 4602003C */  c.lt.s    $f0, $f2
/* 40B71C E012032C 00000000 */  nop
/* 40B720 E0120330 45000003 */  bc1f      .LE0120340
/* 40B724 E0120334 E6000020 */   swc1     $f0, 0x20($s0)
/* 40B728 E0120338 46160000 */  add.s     $f0, $f0, $f22
/* 40B72C E012033C E6000020 */  swc1      $f0, 0x20($s0)
.LE0120340:
/* 40B730 E0120340 C6000020 */  lwc1      $f0, 0x20($s0)
/* 40B734 E0120344 4600B03C */  c.lt.s    $f22, $f0
/* 40B738 E0120348 00000000 */  nop
/* 40B73C E012034C 45020004 */  bc1fl     .LE0120360
/* 40B740 E0120350 26100004 */   addiu    $s0, $s0, 4
/* 40B744 E0120354 46160001 */  sub.s     $f0, $f0, $f22
/* 40B748 E0120358 E6000020 */  swc1      $f0, 0x20($s0)
/* 40B74C E012035C 26100004 */  addiu     $s0, $s0, 4
.LE0120360:
/* 40B750 E0120360 26310001 */  addiu     $s1, $s1, 1
/* 40B754 E0120364 2A220005 */  slti      $v0, $s1, 5
/* 40B758 E0120368 1440FFC5 */  bnez      $v0, .LE0120280
/* 40B75C E012036C 26520014 */   addiu    $s2, $s2, 0x14
.LE0120370:
/* 40B760 E0120370 8FBF0020 */  lw        $ra, 0x20($sp)
/* 40B764 E0120374 8FB3001C */  lw        $s3, 0x1c($sp)
/* 40B768 E0120378 8FB20018 */  lw        $s2, 0x18($sp)
/* 40B76C E012037C 8FB10014 */  lw        $s1, 0x14($sp)
/* 40B770 E0120380 8FB00010 */  lw        $s0, 0x10($sp)
/* 40B774 E0120384 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 40B778 E0120388 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 40B77C E012038C D7B60030 */  ldc1      $f22, 0x30($sp)
/* 40B780 E0120390 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 40B784 E0120394 03E00008 */  jr        $ra
/* 40B788 E0120398 27BD0048 */   addiu    $sp, $sp, 0x48
