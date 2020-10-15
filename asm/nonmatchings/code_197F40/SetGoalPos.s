.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetGoalPos
/* 198DF0 8026A510 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 198DF4 8026A514 AFB20018 */  sw        $s2, 0x18($sp)
/* 198DF8 8026A518 0080902D */  daddu     $s2, $a0, $zero
/* 198DFC 8026A51C AFBF001C */  sw        $ra, 0x1c($sp)
/* 198E00 8026A520 AFB10014 */  sw        $s1, 0x14($sp)
/* 198E04 8026A524 AFB00010 */  sw        $s0, 0x10($sp)
/* 198E08 8026A528 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 198E0C 8026A52C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 198E10 8026A530 8E50000C */  lw        $s0, 0xc($s2)
/* 198E14 8026A534 8E050000 */  lw        $a1, ($s0)
/* 198E18 8026A538 0C0B1EAF */  jal       get_variable
/* 198E1C 8026A53C 26100004 */   addiu    $s0, $s0, 4
/* 198E20 8026A540 0040202D */  daddu     $a0, $v0, $zero
/* 198E24 8026A544 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 198E28 8026A548 14820002 */  bne       $a0, $v0, .L8026A554
/* 198E2C 8026A54C 00000000 */   nop      
/* 198E30 8026A550 8E440148 */  lw        $a0, 0x148($s2)
.L8026A554:
/* 198E34 8026A554 0C09A75B */  jal       get_actor
/* 198E38 8026A558 00000000 */   nop      
/* 198E3C 8026A55C 3C03FF43 */  lui       $v1, 0xff43
/* 198E40 8026A560 34639EB2 */  ori       $v1, $v1, 0x9eb2
/* 198E44 8026A564 8E050000 */  lw        $a1, ($s0)
/* 198E48 8026A568 14A30004 */  bne       $a1, $v1, .L8026A57C
/* 198E4C 8026A56C 2451000C */   addiu    $s1, $v0, 0xc
/* 198E50 8026A570 C4560018 */  lwc1      $f22, 0x18($v0)
/* 198E54 8026A574 0809A965 */  j         .L8026A594
/* 198E58 8026A578 26100004 */   addiu    $s0, $s0, 4
.L8026A57C:
/* 198E5C 8026A57C 0C0B1EAF */  jal       get_variable
/* 198E60 8026A580 0240202D */   daddu    $a0, $s2, $zero
/* 198E64 8026A584 4482B000 */  mtc1      $v0, $f22
/* 198E68 8026A588 00000000 */  nop       
/* 198E6C 8026A58C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 198E70 8026A590 26100004 */  addiu     $s0, $s0, 4
.L8026A594:
/* 198E74 8026A594 3C02FF43 */  lui       $v0, 0xff43
/* 198E78 8026A598 8E050000 */  lw        $a1, ($s0)
/* 198E7C 8026A59C 34429EB2 */  ori       $v0, $v0, 0x9eb2
/* 198E80 8026A5A0 14A20004 */  bne       $a1, $v0, .L8026A5B4
/* 198E84 8026A5A4 3C02FF43 */   lui      $v0, 0xff43
/* 198E88 8026A5A8 C6340010 */  lwc1      $f20, 0x10($s1)
/* 198E8C 8026A5AC 0809A973 */  j         .L8026A5CC
/* 198E90 8026A5B0 00000000 */   nop      
.L8026A5B4:
/* 198E94 8026A5B4 0C0B1EAF */  jal       get_variable
/* 198E98 8026A5B8 0240202D */   daddu    $a0, $s2, $zero
/* 198E9C 8026A5BC 4482A000 */  mtc1      $v0, $f20
/* 198EA0 8026A5C0 00000000 */  nop       
/* 198EA4 8026A5C4 4680A520 */  cvt.s.w   $f20, $f20
/* 198EA8 8026A5C8 3C02FF43 */  lui       $v0, 0xff43
.L8026A5CC:
/* 198EAC 8026A5CC 8E050004 */  lw        $a1, 4($s0)
/* 198EB0 8026A5D0 34429EB2 */  ori       $v0, $v0, 0x9eb2
/* 198EB4 8026A5D4 14A20004 */  bne       $a1, $v0, .L8026A5E8
/* 198EB8 8026A5D8 00000000 */   nop      
/* 198EBC 8026A5DC C6200014 */  lwc1      $f0, 0x14($s1)
/* 198EC0 8026A5E0 0809A980 */  j         .L8026A600
/* 198EC4 8026A5E4 E636000C */   swc1     $f22, 0xc($s1)
.L8026A5E8:
/* 198EC8 8026A5E8 0C0B1EAF */  jal       get_variable
/* 198ECC 8026A5EC 0240202D */   daddu    $a0, $s2, $zero
/* 198ED0 8026A5F0 44820000 */  mtc1      $v0, $f0
/* 198ED4 8026A5F4 00000000 */  nop       
/* 198ED8 8026A5F8 46800020 */  cvt.s.w   $f0, $f0
/* 198EDC 8026A5FC E636000C */  swc1      $f22, 0xc($s1)
.L8026A600:
/* 198EE0 8026A600 E6340010 */  swc1      $f20, 0x10($s1)
/* 198EE4 8026A604 E6200014 */  swc1      $f0, 0x14($s1)
/* 198EE8 8026A608 8FBF001C */  lw        $ra, 0x1c($sp)
/* 198EEC 8026A60C 8FB20018 */  lw        $s2, 0x18($sp)
/* 198EF0 8026A610 8FB10014 */  lw        $s1, 0x14($sp)
/* 198EF4 8026A614 8FB00010 */  lw        $s0, 0x10($sp)
/* 198EF8 8026A618 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 198EFC 8026A61C D7B40020 */  ldc1      $f20, 0x20($sp)
/* 198F00 8026A620 24020002 */  addiu     $v0, $zero, 2
/* 198F04 8026A624 03E00008 */  jr        $ra
/* 198F08 8026A628 27BD0030 */   addiu    $sp, $sp, 0x30
