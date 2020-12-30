.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218E34_6BC9C4
/* 6BC9C4 80218E34 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6BC9C8 80218E38 AFBF0024 */  sw        $ra, 0x24($sp)
/* 6BC9CC 80218E3C AFB20020 */  sw        $s2, 0x20($sp)
/* 6BC9D0 80218E40 AFB1001C */  sw        $s1, 0x1c($sp)
/* 6BC9D4 80218E44 AFB00018 */  sw        $s0, 0x18($sp)
/* 6BC9D8 80218E48 8C840148 */  lw        $a0, 0x148($a0)
/* 6BC9DC 80218E4C 0C09A75B */  jal       get_actor
/* 6BC9E0 80218E50 00A0802D */   daddu    $s0, $a1, $zero
/* 6BC9E4 80218E54 0040882D */  daddu     $s1, $v0, $zero
/* 6BC9E8 80218E58 12000007 */  beqz      $s0, .L80218E78
/* 6BC9EC 80218E5C 2632000C */   addiu    $s2, $s1, 0xc
/* 6BC9F0 80218E60 C6200144 */  lwc1      $f0, 0x144($s1)
/* 6BC9F4 80218E64 C6220148 */  lwc1      $f2, 0x148($s1)
/* 6BC9F8 80218E68 C624014C */  lwc1      $f4, 0x14c($s1)
/* 6BC9FC 80218E6C E620000C */  swc1      $f0, 0xc($s1)
/* 6BCA00 80218E70 E6220010 */  swc1      $f2, 0x10($s1)
/* 6BCA04 80218E74 E6240014 */  swc1      $f4, 0x14($s1)
.L80218E78:
/* 6BCA08 80218E78 8E25004C */  lw        $a1, 0x4c($s1)
/* 6BCA0C 80218E7C 8E260054 */  lw        $a2, 0x54($s1)
/* 6BCA10 80218E80 0C09904A */  jal       add_xz_vec3f
/* 6BCA14 80218E84 0240202D */   daddu    $a0, $s2, $zero
/* 6BCA18 80218E88 C622004C */  lwc1      $f2, 0x4c($s1)
/* 6BCA1C 80218E8C 3C014080 */  lui       $at, 0x4080
/* 6BCA20 80218E90 44810000 */  mtc1      $at, $f0
/* 6BCA24 80218E94 00000000 */  nop       
/* 6BCA28 80218E98 4600103C */  c.lt.s    $f2, $f0
/* 6BCA2C 80218E9C 00000000 */  nop       
/* 6BCA30 80218EA0 45000007 */  bc1f      .L80218EC0
/* 6BCA34 80218EA4 0000202D */   daddu    $a0, $zero, $zero
/* 6BCA38 80218EA8 C6200054 */  lwc1      $f0, 0x54($s1)
/* 6BCA3C 80218EAC E7A00010 */  swc1      $f0, 0x10($sp)
/* 6BCA40 80218EB0 8E25000C */  lw        $a1, 0xc($s1)
/* 6BCA44 80218EB4 8E260010 */  lw        $a2, 0x10($s1)
/* 6BCA48 80218EB8 080863B6 */  j         .L80218ED8
/* 6BCA4C 80218EBC 8E270014 */   lw       $a3, 0x14($s1)
.L80218EC0:
/* 6BCA50 80218EC0 C6200054 */  lwc1      $f0, 0x54($s1)
/* 6BCA54 80218EC4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6BCA58 80218EC8 8E25000C */  lw        $a1, 0xc($s1)
/* 6BCA5C 80218ECC 8E260010 */  lw        $a2, 0x10($s1)
/* 6BCA60 80218ED0 8E270014 */  lw        $a3, 0x14($s1)
/* 6BCA64 80218ED4 24040001 */  addiu     $a0, $zero, 1
.L80218ED8:
/* 6BCA68 80218ED8 0C0990BC */  jal       play_movement_dust_effects
/* 6BCA6C 80218EDC 00000000 */   nop      
/* 6BCA70 80218EE0 C6400040 */  lwc1      $f0, 0x40($s2)
/* 6BCA74 80218EE4 3C013FF8 */  lui       $at, 0x3ff8
/* 6BCA78 80218EE8 44811800 */  mtc1      $at, $f3
/* 6BCA7C 80218EEC 44801000 */  mtc1      $zero, $f2
/* 6BCA80 80218EF0 46000021 */  cvt.d.s   $f0, $f0
/* 6BCA84 80218EF4 46220003 */  div.d     $f0, $f0, $f2
/* 6BCA88 80218EF8 C6420000 */  lwc1      $f2, ($s2)
/* 6BCA8C 80218EFC 46200020 */  cvt.s.d   $f0, $f0
/* 6BCA90 80218F00 E6400040 */  swc1      $f0, 0x40($s2)
/* 6BCA94 80218F04 E6220144 */  swc1      $f2, 0x144($s1)
/* 6BCA98 80218F08 C6400004 */  lwc1      $f0, 4($s2)
/* 6BCA9C 80218F0C E6200148 */  swc1      $f0, 0x148($s1)
/* 6BCAA0 80218F10 C6400008 */  lwc1      $f0, 8($s2)
/* 6BCAA4 80218F14 E620014C */  swc1      $f0, 0x14c($s1)
/* 6BCAA8 80218F18 C6400040 */  lwc1      $f0, 0x40($s2)
/* 6BCAAC 80218F1C 3C013FF0 */  lui       $at, 0x3ff0
/* 6BCAB0 80218F20 44811800 */  mtc1      $at, $f3
/* 6BCAB4 80218F24 44801000 */  mtc1      $zero, $f2
/* 6BCAB8 80218F28 46000021 */  cvt.d.s   $f0, $f0
/* 6BCABC 80218F2C 4622003C */  c.lt.d    $f0, $f2
/* 6BCAC0 80218F30 00000000 */  nop       
/* 6BCAC4 80218F34 45010002 */  bc1t      .L80218F40
/* 6BCAC8 80218F38 24020002 */   addiu    $v0, $zero, 2
/* 6BCACC 80218F3C 0000102D */  daddu     $v0, $zero, $zero
.L80218F40:
/* 6BCAD0 80218F40 8FBF0024 */  lw        $ra, 0x24($sp)
/* 6BCAD4 80218F44 8FB20020 */  lw        $s2, 0x20($sp)
/* 6BCAD8 80218F48 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6BCADC 80218F4C 8FB00018 */  lw        $s0, 0x18($sp)
/* 6BCAE0 80218F50 03E00008 */  jr        $ra
/* 6BCAE4 80218F54 27BD0028 */   addiu    $sp, $sp, 0x28
