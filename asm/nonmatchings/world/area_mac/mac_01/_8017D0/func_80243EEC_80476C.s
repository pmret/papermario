.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243EEC_80476C
/* 80476C 80243EEC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 804770 80243EF0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 804774 80243EF4 0080882D */  daddu     $s1, $a0, $zero
/* 804778 80243EF8 AFBF0034 */  sw        $ra, 0x34($sp)
/* 80477C 80243EFC AFB60030 */  sw        $s6, 0x30($sp)
/* 804780 80243F00 AFB5002C */  sw        $s5, 0x2c($sp)
/* 804784 80243F04 AFB40028 */  sw        $s4, 0x28($sp)
/* 804788 80243F08 AFB30024 */  sw        $s3, 0x24($sp)
/* 80478C 80243F0C AFB20020 */  sw        $s2, 0x20($sp)
/* 804790 80243F10 AFB00018 */  sw        $s0, 0x18($sp)
/* 804794 80243F14 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 804798 80243F18 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 80479C 80243F1C 8E30000C */  lw        $s0, 0xc($s1)
/* 8047A0 80243F20 8E160000 */  lw        $s6, ($s0)
/* 8047A4 80243F24 26100004 */  addiu     $s0, $s0, 4
/* 8047A8 80243F28 0C0B1EAF */  jal       get_variable
/* 8047AC 80243F2C 02C0282D */   daddu    $a1, $s6, $zero
/* 8047B0 80243F30 44820000 */  mtc1      $v0, $f0
/* 8047B4 80243F34 00000000 */  nop       
/* 8047B8 80243F38 46800020 */  cvt.s.w   $f0, $f0
/* 8047BC 80243F3C E7A00010 */  swc1      $f0, 0x10($sp)
/* 8047C0 80243F40 8E140000 */  lw        $s4, ($s0)
/* 8047C4 80243F44 26100004 */  addiu     $s0, $s0, 4
/* 8047C8 80243F48 0220202D */  daddu     $a0, $s1, $zero
/* 8047CC 80243F4C 0C0B1EAF */  jal       get_variable
/* 8047D0 80243F50 0280282D */   daddu    $a1, $s4, $zero
/* 8047D4 80243F54 0220202D */  daddu     $a0, $s1, $zero
/* 8047D8 80243F58 8E150000 */  lw        $s5, ($s0)
/* 8047DC 80243F5C 4482B000 */  mtc1      $v0, $f22
/* 8047E0 80243F60 00000000 */  nop       
/* 8047E4 80243F64 4680B5A0 */  cvt.s.w   $f22, $f22
/* 8047E8 80243F68 0C0B1EAF */  jal       get_variable
/* 8047EC 80243F6C 02A0282D */   daddu    $a1, $s5, $zero
/* 8047F0 80243F70 2404FFFC */  addiu     $a0, $zero, -4
/* 8047F4 80243F74 44820000 */  mtc1      $v0, $f0
/* 8047F8 80243F78 00000000 */  nop       
/* 8047FC 80243F7C 46800020 */  cvt.s.w   $f0, $f0
/* 804800 80243F80 0C00EABB */  jal       get_npc_unsafe
/* 804804 80243F84 E7A00014 */   swc1     $f0, 0x14($sp)
/* 804808 80243F88 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 80480C 80243F8C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 804810 80243F90 3C014334 */  lui       $at, 0x4334
/* 804814 80243F94 44816000 */  mtc1      $at, $f12
/* 804818 80243F98 00041880 */  sll       $v1, $a0, 2
/* 80481C 80243F9C 00641821 */  addu      $v1, $v1, $a0
/* 804820 80243FA0 00031880 */  sll       $v1, $v1, 2
/* 804824 80243FA4 00641823 */  subu      $v1, $v1, $a0
/* 804828 80243FA8 000320C0 */  sll       $a0, $v1, 3
/* 80482C 80243FAC 00641821 */  addu      $v1, $v1, $a0
/* 804830 80243FB0 000318C0 */  sll       $v1, $v1, 3
/* 804834 80243FB4 3C01800B */  lui       $at, 0x800b
/* 804838 80243FB8 00230821 */  addu      $at, $at, $v1
/* 80483C 80243FBC C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 804840 80243FC0 460C0300 */  add.s     $f12, $f0, $f12
/* 804844 80243FC4 0C00A6C9 */  jal       clamp_angle
/* 804848 80243FC8 0040982D */   daddu    $s3, $v0, $zero
/* 80484C 80243FCC 27B00010 */  addiu     $s0, $sp, 0x10
/* 804850 80243FD0 0200202D */  daddu     $a0, $s0, $zero
/* 804854 80243FD4 27B20014 */  addiu     $s2, $sp, 0x14
/* 804858 80243FD8 0240282D */  daddu     $a1, $s2, $zero
/* 80485C 80243FDC 3C064170 */  lui       $a2, 0x4170
/* 804860 80243FE0 8E67000C */  lw        $a3, 0xc($s3)
/* 804864 80243FE4 0C00A7E7 */  jal       add_vec2D_polar
/* 804868 80243FE8 46000506 */   mov.s    $f20, $f0
/* 80486C 80243FEC 0200202D */  daddu     $a0, $s0, $zero
/* 804870 80243FF0 3C064120 */  lui       $a2, 0x4120
/* 804874 80243FF4 4407A000 */  mfc1      $a3, $f20
/* 804878 80243FF8 0C00A7E7 */  jal       add_vec2D_polar
/* 80487C 80243FFC 0240282D */   daddu    $a1, $s2, $zero
/* 804880 80244000 0220202D */  daddu     $a0, $s1, $zero
/* 804884 80244004 C7A00010 */  lwc1      $f0, 0x10($sp)
/* 804888 80244008 4600008D */  trunc.w.s $f2, $f0
/* 80488C 8024400C 44061000 */  mfc1      $a2, $f2
/* 804890 80244010 0C0B2026 */  jal       set_variable
/* 804894 80244014 02C0282D */   daddu    $a1, $s6, $zero
/* 804898 80244018 0220202D */  daddu     $a0, $s1, $zero
/* 80489C 8024401C 4600B08D */  trunc.w.s $f2, $f22
/* 8048A0 80244020 44061000 */  mfc1      $a2, $f2
/* 8048A4 80244024 0C0B2026 */  jal       set_variable
/* 8048A8 80244028 0280282D */   daddu    $a1, $s4, $zero
/* 8048AC 8024402C 0220202D */  daddu     $a0, $s1, $zero
/* 8048B0 80244030 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 8048B4 80244034 4600008D */  trunc.w.s $f2, $f0
/* 8048B8 80244038 44061000 */  mfc1      $a2, $f2
/* 8048BC 8024403C 0C0B2026 */  jal       set_variable
/* 8048C0 80244040 02A0282D */   daddu    $a1, $s5, $zero
/* 8048C4 80244044 8FBF0034 */  lw        $ra, 0x34($sp)
/* 8048C8 80244048 8FB60030 */  lw        $s6, 0x30($sp)
/* 8048CC 8024404C 8FB5002C */  lw        $s5, 0x2c($sp)
/* 8048D0 80244050 8FB40028 */  lw        $s4, 0x28($sp)
/* 8048D4 80244054 8FB30024 */  lw        $s3, 0x24($sp)
/* 8048D8 80244058 8FB20020 */  lw        $s2, 0x20($sp)
/* 8048DC 8024405C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8048E0 80244060 8FB00018 */  lw        $s0, 0x18($sp)
/* 8048E4 80244064 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 8048E8 80244068 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 8048EC 8024406C 24020002 */  addiu     $v0, $zero, 2
/* 8048F0 80244070 03E00008 */  jr        $ra
/* 8048F4 80244074 27BD0048 */   addiu    $sp, $sp, 0x48
