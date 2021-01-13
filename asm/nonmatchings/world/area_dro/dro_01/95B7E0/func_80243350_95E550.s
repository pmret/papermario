.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243350_95E550
/* 95E550 80243350 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 95E554 80243354 AFB10014 */  sw        $s1, 0x14($sp)
/* 95E558 80243358 0080882D */  daddu     $s1, $a0, $zero
/* 95E55C 8024335C AFBF0018 */  sw        $ra, 0x18($sp)
/* 95E560 80243360 AFB00010 */  sw        $s0, 0x10($sp)
/* 95E564 80243364 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 95E568 80243368 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 95E56C 8024336C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 95E570 80243370 8E30000C */  lw        $s0, 0xc($s1)
/* 95E574 80243374 8E050000 */  lw        $a1, ($s0)
/* 95E578 80243378 0C0B1EAF */  jal       get_variable
/* 95E57C 8024337C 26100004 */   addiu    $s0, $s0, 4
/* 95E580 80243380 8E050000 */  lw        $a1, ($s0)
/* 95E584 80243384 26100004 */  addiu     $s0, $s0, 4
/* 95E588 80243388 4482C000 */  mtc1      $v0, $f24
/* 95E58C 8024338C 00000000 */  nop
/* 95E590 80243390 4680C620 */  cvt.s.w   $f24, $f24
/* 95E594 80243394 0C0B1EAF */  jal       get_variable
/* 95E598 80243398 0220202D */   daddu    $a0, $s1, $zero
/* 95E59C 8024339C 8E050000 */  lw        $a1, ($s0)
/* 95E5A0 802433A0 26100004 */  addiu     $s0, $s0, 4
/* 95E5A4 802433A4 4482B000 */  mtc1      $v0, $f22
/* 95E5A8 802433A8 00000000 */  nop
/* 95E5AC 802433AC 4680B5A0 */  cvt.s.w   $f22, $f22
/* 95E5B0 802433B0 0C0B1EAF */  jal       get_variable
/* 95E5B4 802433B4 0220202D */   daddu    $a0, $s1, $zero
/* 95E5B8 802433B8 8E050000 */  lw        $a1, ($s0)
/* 95E5BC 802433BC 4482A000 */  mtc1      $v0, $f20
/* 95E5C0 802433C0 00000000 */  nop
/* 95E5C4 802433C4 4680A520 */  cvt.s.w   $f20, $f20
/* 95E5C8 802433C8 0C0B1EAF */  jal       get_variable
/* 95E5CC 802433CC 0220202D */   daddu    $a0, $s1, $zero
/* 95E5D0 802433D0 44820000 */  mtc1      $v0, $f0
/* 95E5D4 802433D4 00000000 */  nop
/* 95E5D8 802433D8 46800020 */  cvt.s.w   $f0, $f0
/* 95E5DC 802433DC 46160001 */  sub.s     $f0, $f0, $f22
/* 95E5E0 802433E0 4618A501 */  sub.s     $f20, $f20, $f24
/* 95E5E4 802433E4 46140003 */  div.s     $f0, $f0, $f20
/* 95E5E8 802433E8 46180602 */  mul.s     $f24, $f0, $f24
/* 95E5EC 802433EC 00000000 */  nop
/* 95E5F0 802433F0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 95E5F4 802433F4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 95E5F8 802433F8 C4420028 */  lwc1      $f2, 0x28($v0)
/* 95E5FC 802433FC 46020002 */  mul.s     $f0, $f0, $f2
/* 95E600 80243400 00000000 */  nop
/* 95E604 80243404 4618B581 */  sub.s     $f22, $f22, $f24
/* 95E608 80243408 46160000 */  add.s     $f0, $f0, $f22
/* 95E60C 8024340C C4420030 */  lwc1      $f2, 0x30($v0)
/* 95E610 80243410 4600103C */  c.lt.s    $f2, $f0
/* 95E614 80243414 00000000 */  nop
/* 95E618 80243418 45030005 */  bc1tl     .L80243430
/* 95E61C 8024341C AE200084 */   sw       $zero, 0x84($s1)
/* 95E620 80243420 24020001 */  addiu     $v0, $zero, 1
/* 95E624 80243424 AE220084 */  sw        $v0, 0x84($s1)
/* 95E628 80243428 08090D0D */  j         .L80243434
/* 95E62C 8024342C 0000102D */   daddu    $v0, $zero, $zero
.L80243430:
/* 95E630 80243430 24020002 */  addiu     $v0, $zero, 2
.L80243434:
/* 95E634 80243434 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95E638 80243438 8FB10014 */  lw        $s1, 0x14($sp)
/* 95E63C 8024343C 8FB00010 */  lw        $s0, 0x10($sp)
/* 95E640 80243440 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 95E644 80243444 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 95E648 80243448 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 95E64C 8024344C 03E00008 */  jr        $ra
/* 95E650 80243450 27BD0038 */   addiu    $sp, $sp, 0x38
/* 95E654 80243454 00000000 */  nop
/* 95E658 80243458 00000000 */  nop
/* 95E65C 8024345C 00000000 */  nop
