.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242260_C62F70
/* C62F70 80242260 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C62F74 80242264 AFB40040 */  sw        $s4, 0x40($sp)
/* C62F78 80242268 0080A02D */  daddu     $s4, $a0, $zero
/* C62F7C 8024226C AFBF0044 */  sw        $ra, 0x44($sp)
/* C62F80 80242270 AFB3003C */  sw        $s3, 0x3c($sp)
/* C62F84 80242274 AFB20038 */  sw        $s2, 0x38($sp)
/* C62F88 80242278 AFB10034 */  sw        $s1, 0x34($sp)
/* C62F8C 8024227C AFB00030 */  sw        $s0, 0x30($sp)
/* C62F90 80242280 8E910148 */  lw        $s1, 0x148($s4)
/* C62F94 80242284 00A0902D */  daddu     $s2, $a1, $zero
/* C62F98 80242288 86240008 */  lh        $a0, 8($s1)
/* C62F9C 8024228C 0C00EABB */  jal       get_npc_unsafe
/* C62FA0 80242290 00C0982D */   daddu    $s3, $a2, $zero
/* C62FA4 80242294 0040802D */  daddu     $s0, $v0, $zero
/* C62FA8 80242298 9602008E */  lhu       $v0, 0x8e($s0)
/* C62FAC 8024229C 2442FFFF */  addiu     $v0, $v0, -1
/* C62FB0 802422A0 A602008E */  sh        $v0, 0x8e($s0)
/* C62FB4 802422A4 00021400 */  sll       $v0, $v0, 0x10
/* C62FB8 802422A8 14400020 */  bnez      $v0, .L8024232C
/* C62FBC 802422AC 0260202D */   daddu    $a0, $s3, $zero
/* C62FC0 802422B0 AFA00010 */  sw        $zero, 0x10($sp)
/* C62FC4 802422B4 8E46000C */  lw        $a2, 0xc($s2)
/* C62FC8 802422B8 8E470010 */  lw        $a3, 0x10($s2)
/* C62FCC 802422BC 0C01242D */  jal       func_800490B4
/* C62FD0 802422C0 0220282D */   daddu    $a1, $s1, $zero
/* C62FD4 802422C4 54400018 */  bnel      $v0, $zero, .L80242328
/* C62FD8 802422C8 A600008E */   sh       $zero, 0x8e($s0)
/* C62FDC 802422CC 24040002 */  addiu     $a0, $zero, 2
/* C62FE0 802422D0 0200282D */  daddu     $a1, $s0, $zero
/* C62FE4 802422D4 0000302D */  daddu     $a2, $zero, $zero
/* C62FE8 802422D8 860300A8 */  lh        $v1, 0xa8($s0)
/* C62FEC 802422DC 3C013F80 */  lui       $at, 0x3f80
/* C62FF0 802422E0 44810000 */  mtc1      $at, $f0
/* C62FF4 802422E4 3C014000 */  lui       $at, 0x4000
/* C62FF8 802422E8 44811000 */  mtc1      $at, $f2
/* C62FFC 802422EC 3C01C1A0 */  lui       $at, 0xc1a0
/* C63000 802422F0 44812000 */  mtc1      $at, $f4
/* C63004 802422F4 2402000F */  addiu     $v0, $zero, 0xf
/* C63008 802422F8 AFA2001C */  sw        $v0, 0x1c($sp)
/* C6300C 802422FC 44833000 */  mtc1      $v1, $f6
/* C63010 80242300 00000000 */  nop
/* C63014 80242304 468031A0 */  cvt.s.w   $f6, $f6
/* C63018 80242308 44073000 */  mfc1      $a3, $f6
/* C6301C 8024230C 27A20028 */  addiu     $v0, $sp, 0x28
/* C63020 80242310 AFA20020 */  sw        $v0, 0x20($sp)
/* C63024 80242314 E7A00010 */  swc1      $f0, 0x10($sp)
/* C63028 80242318 E7A20014 */  swc1      $f2, 0x14($sp)
/* C6302C 8024231C 0C01BFA4 */  jal       fx_emote
/* C63030 80242320 E7A40018 */   swc1     $f4, 0x18($sp)
/* C63034 80242324 A600008E */  sh        $zero, 0x8e($s0)
.L80242328:
/* C63038 80242328 AE800070 */  sw        $zero, 0x70($s4)
.L8024232C:
/* C6303C 8024232C 8FBF0044 */  lw        $ra, 0x44($sp)
/* C63040 80242330 8FB40040 */  lw        $s4, 0x40($sp)
/* C63044 80242334 8FB3003C */  lw        $s3, 0x3c($sp)
/* C63048 80242338 8FB20038 */  lw        $s2, 0x38($sp)
/* C6304C 8024233C 8FB10034 */  lw        $s1, 0x34($sp)
/* C63050 80242340 8FB00030 */  lw        $s0, 0x30($sp)
/* C63054 80242344 03E00008 */  jr        $ra
/* C63058 80242348 27BD0048 */   addiu    $sp, $sp, 0x48
