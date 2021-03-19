.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8029D4E8
.double 0.7999999999999999

.section .text

glabel func_8025DBD0
/* 18C4B0 8025DBD0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 18C4B4 8025DBD4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 18C4B8 8025DBD8 0080882D */  daddu     $s1, $a0, $zero
/* 18C4BC 8025DBDC AFBF0028 */  sw        $ra, 0x28($sp)
/* 18C4C0 8025DBE0 AFB30024 */  sw        $s3, 0x24($sp)
/* 18C4C4 8025DBE4 AFB20020 */  sw        $s2, 0x20($sp)
/* 18C4C8 8025DBE8 AFB00018 */  sw        $s0, 0x18($sp)
/* 18C4CC 8025DBEC 8E3000C0 */  lw        $s0, 0xc0($s1)
/* 18C4D0 8025DBF0 00A0982D */  daddu     $s3, $a1, $zero
/* 18C4D4 8025DBF4 02139021 */  addu      $s2, $s0, $s3
/* 18C4D8 8025DBF8 824308BC */  lb        $v1, 0x8bc($s2)
/* 18C4DC 8025DBFC 10600005 */  beqz      $v1, .L8025DC14
/* 18C4E0 8025DC00 24020001 */   addiu    $v0, $zero, 1
/* 18C4E4 8025DC04 1062001B */  beq       $v1, $v0, .L8025DC74
/* 18C4E8 8025DC08 00131080 */   sll      $v0, $s3, 2
/* 18C4EC 8025DC0C 08097749 */  j         .L8025DD24
/* 18C4F0 8025DC10 00000000 */   nop
.L8025DC14:
/* 18C4F4 8025DC14 00131080 */  sll       $v0, $s3, 2
/* 18C4F8 8025DC18 244208B0 */  addiu     $v0, $v0, 0x8b0
/* 18C4FC 8025DC1C 3C013F99 */  lui       $at, 0x3f99
/* 18C500 8025DC20 3421999A */  ori       $at, $at, 0x999a
/* 18C504 8025DC24 44810000 */  mtc1      $at, $f0
/* 18C508 8025DC28 02021021 */  addu      $v0, $s0, $v0
/* 18C50C 8025DC2C AFA20014 */  sw        $v0, 0x14($sp)
/* 18C510 8025DC30 E7A00010 */  swc1      $f0, 0x10($sp)
/* 18C514 8025DC34 8E250058 */  lw        $a1, 0x58($s1)
/* 18C518 8025DC38 8E26005C */  lw        $a2, 0x5c($s1)
/* 18C51C 8025DC3C 8E270060 */  lw        $a3, 0x60($s1)
/* 18C520 8025DC40 0C01C3AC */  jal       func_80070EB0
/* 18C524 8025DC44 24040002 */   addiu    $a0, $zero, 2
/* 18C528 8025DC48 24020001 */  addiu     $v0, $zero, 1
/* 18C52C 8025DC4C A24208BC */  sb        $v0, 0x8bc($s2)
/* 18C530 8025DC50 00131100 */  sll       $v0, $s3, 4
/* 18C534 8025DC54 02021021 */  addu      $v0, $s0, $v0
/* 18C538 8025DC58 24030096 */  addiu     $v1, $zero, 0x96
/* 18C53C 8025DC5C A44308C6 */  sh        $v1, 0x8c6($v0)
/* 18C540 8025DC60 A44308C8 */  sh        $v1, 0x8c8($v0)
/* 18C544 8025DC64 240300FF */  addiu     $v1, $zero, 0xff
/* 18C548 8025DC68 A44308CA */  sh        $v1, 0x8ca($v0)
/* 18C54C 8025DC6C A44008CC */  sh        $zero, 0x8cc($v0)
/* 18C550 8025DC70 00131080 */  sll       $v0, $s3, 2
.L8025DC74:
/* 18C554 8025DC74 02021021 */  addu      $v0, $s0, $v0
/* 18C558 8025DC78 8C4508B0 */  lw        $a1, 0x8b0($v0)
/* 18C55C 8025DC7C C6200058 */  lwc1      $f0, 0x58($s1)
/* 18C560 8025DC80 8CA3000C */  lw        $v1, 0xc($a1)
/* 18C564 8025DC84 00132100 */  sll       $a0, $s3, 4
/* 18C568 8025DC88 E4600004 */  swc1      $f0, 4($v1)
/* 18C56C 8025DC8C C620005C */  lwc1      $f0, 0x5c($s1)
/* 18C570 8025DC90 02042021 */  addu      $a0, $s0, $a0
/* 18C574 8025DC94 E4600008 */  swc1      $f0, 8($v1)
/* 18C578 8025DC98 848208CC */  lh        $v0, 0x8cc($a0)
/* 18C57C 8025DC9C C6200060 */  lwc1      $f0, 0x60($s1)
/* 18C580 8025DCA0 44821000 */  mtc1      $v0, $f2
/* 18C584 8025DCA4 00000000 */  nop
/* 18C588 8025DCA8 468010A0 */  cvt.s.w   $f2, $f2
/* 18C58C 8025DCAC 46020000 */  add.s     $f0, $f0, $f2
/* 18C590 8025DCB0 E460000C */  swc1      $f0, 0xc($v1)
/* 18C594 8025DCB4 848208C6 */  lh        $v0, 0x8c6($a0)
/* 18C598 8025DCB8 3C0142C8 */  lui       $at, 0x42c8
/* 18C59C 8025DCBC 44810000 */  mtc1      $at, $f0
/* 18C5A0 8025DCC0 44822000 */  mtc1      $v0, $f4
/* 18C5A4 8025DCC4 00000000 */  nop
/* 18C5A8 8025DCC8 46802120 */  cvt.s.w   $f4, $f4
/* 18C5AC 8025DCCC 8CA2000C */  lw        $v0, 0xc($a1)
/* 18C5B0 8025DCD0 46002103 */  div.s     $f4, $f4, $f0
/* 18C5B4 8025DCD4 E444001C */  swc1      $f4, 0x1c($v0)
/* 18C5B8 8025DCD8 848208C8 */  lh        $v0, 0x8c8($a0)
/* 18C5BC 8025DCDC 3C01802A */  lui       $at, %hi(D_8029D4E8)
/* 18C5C0 8025DCE0 D422D4E8 */  ldc1      $f2, %lo(D_8029D4E8)($at)
/* 18C5C4 8025DCE4 44822000 */  mtc1      $v0, $f4
/* 18C5C8 8025DCE8 00000000 */  nop
/* 18C5CC 8025DCEC 46802120 */  cvt.s.w   $f4, $f4
/* 18C5D0 8025DCF0 46002103 */  div.s     $f4, $f4, $f0
/* 18C5D4 8025DCF4 46002021 */  cvt.d.s   $f0, $f4
/* 18C5D8 8025DCF8 46220002 */  mul.d     $f0, $f0, $f2
/* 18C5DC 8025DCFC 00000000 */  nop
/* 18C5E0 8025DD00 8CA2000C */  lw        $v0, 0xc($a1)
/* 18C5E4 8025DD04 46200020 */  cvt.s.d   $f0, $f0
/* 18C5E8 8025DD08 E4400020 */  swc1      $f0, 0x20($v0)
/* 18C5EC 8025DD0C 8CA3000C */  lw        $v1, 0xc($a1)
/* 18C5F0 8025DD10 848208CA */  lh        $v0, 0x8ca($a0)
/* 18C5F4 8025DD14 AC620028 */  sw        $v0, 0x28($v1)
/* 18C5F8 8025DD18 8CA2000C */  lw        $v0, 0xc($a1)
/* 18C5FC 8025DD1C C6200064 */  lwc1      $f0, 0x64($s1)
/* 18C600 8025DD20 E4400064 */  swc1      $f0, 0x64($v0)
.L8025DD24:
/* 18C604 8025DD24 8FBF0028 */  lw        $ra, 0x28($sp)
/* 18C608 8025DD28 8FB30024 */  lw        $s3, 0x24($sp)
/* 18C60C 8025DD2C 8FB20020 */  lw        $s2, 0x20($sp)
/* 18C610 8025DD30 8FB1001C */  lw        $s1, 0x1c($sp)
/* 18C614 8025DD34 8FB00018 */  lw        $s0, 0x18($sp)
/* 18C618 8025DD38 03E00008 */  jr        $ra
/* 18C61C 8025DD3C 27BD0030 */   addiu    $sp, $sp, 0x30
