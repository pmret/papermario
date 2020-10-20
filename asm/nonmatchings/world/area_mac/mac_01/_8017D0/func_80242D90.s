.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D90
/* 803610 80242D90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 803614 80242D94 AFB10014 */  sw        $s1, 0x14($sp)
/* 803618 80242D98 0080882D */  daddu     $s1, $a0, $zero
/* 80361C 80242D9C AFB00010 */  sw        $s0, 0x10($sp)
/* 803620 80242DA0 00A0802D */  daddu     $s0, $a1, $zero
/* 803624 80242DA4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 803628 80242DA8 0C00EABB */  jal       get_npc_unsafe
/* 80362C 80242DAC 2404FFFC */   addiu    $a0, $zero, -4
/* 803630 80242DB0 12000003 */  beqz      $s0, .L80242DC0
/* 803634 80242DB4 0040182D */   daddu    $v1, $v0, $zero
/* 803638 80242DB8 2402003C */  addiu     $v0, $zero, 0x3c
/* 80363C 80242DBC AE220070 */  sw        $v0, 0x70($s1)
.L80242DC0:
/* 803640 80242DC0 C462000C */  lwc1      $f2, 0xc($v1)
/* 803644 80242DC4 3C0141F0 */  lui       $at, 0x41f0
/* 803648 80242DC8 44810000 */  mtc1      $at, $f0
/* 80364C 80242DCC 00000000 */  nop       
/* 803650 80242DD0 46001000 */  add.s     $f0, $f2, $f0
/* 803654 80242DD4 3C0143B4 */  lui       $at, 0x43b4
/* 803658 80242DD8 44811000 */  mtc1      $at, $f2
/* 80365C 80242DDC 00000000 */  nop       
/* 803660 80242DE0 4600103E */  c.le.s    $f2, $f0
/* 803664 80242DE4 00000000 */  nop       
/* 803668 80242DE8 45000003 */  bc1f      .L80242DF8
/* 80366C 80242DEC E460000C */   swc1     $f0, 0xc($v1)
/* 803670 80242DF0 46020001 */  sub.s     $f0, $f0, $f2
/* 803674 80242DF4 E460000C */  swc1      $f0, 0xc($v1)
.L80242DF8:
/* 803678 80242DF8 8E230070 */  lw        $v1, 0x70($s1)
/* 80367C 80242DFC 2463FFFF */  addiu     $v1, $v1, -1
/* 803680 80242E00 000317C3 */  sra       $v0, $v1, 0x1f
/* 803684 80242E04 AE230070 */  sw        $v1, 0x70($s1)
/* 803688 80242E08 8FBF0018 */  lw        $ra, 0x18($sp)
/* 80368C 80242E0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 803690 80242E10 8FB00010 */  lw        $s0, 0x10($sp)
/* 803694 80242E14 30420002 */  andi      $v0, $v0, 2
/* 803698 80242E18 03E00008 */  jr        $ra
/* 80369C 80242E1C 27BD0020 */   addiu    $sp, $sp, 0x20
