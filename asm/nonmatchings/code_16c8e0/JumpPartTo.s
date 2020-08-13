.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel JumpPartTo
/* 1A8DC4 8027A4E4 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 1A8DC8 8027A4E8 AFB30024 */  sw    $s3, 0x24($sp)
/* 1A8DCC 8027A4EC 0080982D */  daddu $s3, $a0, $zero
/* 1A8DD0 8027A4F0 AFBF0028 */  sw    $ra, 0x28($sp)
/* 1A8DD4 8027A4F4 AFB20020 */  sw    $s2, 0x20($sp)
/* 1A8DD8 8027A4F8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 1A8DDC 8027A4FC AFB00018 */  sw    $s0, 0x18($sp)
/* 1A8DE0 8027A500 F7BE0058 */  sdc1  $f30, 0x58($sp)
/* 1A8DE4 8027A504 F7BC0050 */  sdc1  $f28, 0x50($sp)
/* 1A8DE8 8027A508 F7BA0048 */  sdc1  $f26, 0x48($sp)
/* 1A8DEC 8027A50C F7B80040 */  sdc1  $f24, 0x40($sp)
/* 1A8DF0 8027A510 F7B60038 */  sdc1  $f22, 0x38($sp)
/* 1A8DF4 8027A514 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 1A8DF8 8027A518 8E72000C */  lw    $s2, 0xc($s3)
/* 1A8DFC 8027A51C 54A00001 */  bnezl $a1, .L8027A524
/* 1A8E00 8027A520 AE600070 */   sw    $zero, 0x70($s3)
.L8027A524:
/* 1A8E04 8027A524 8E620070 */  lw    $v0, 0x70($s3)
/* 1A8E08 8027A528 14400093 */  bnez  $v0, .L8027A778
/* 1A8E0C 8027A52C 00000000 */   nop   
/* 1A8E10 8027A530 8E450000 */  lw    $a1, ($s2)
/* 1A8E14 8027A534 26520004 */  addiu $s2, $s2, 4
/* 1A8E18 8027A538 0C0B1EAF */  jal   get_variable
/* 1A8E1C 8027A53C 0260202D */   daddu $a0, $s3, $zero
/* 1A8E20 8027A540 0040802D */  daddu $s0, $v0, $zero
/* 1A8E24 8027A544 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1A8E28 8027A548 16020002 */  bne   $s0, $v0, .L8027A554
/* 1A8E2C 8027A54C 00000000 */   nop   
/* 1A8E30 8027A550 8E700148 */  lw    $s0, 0x148($s3)
.L8027A554:
/* 1A8E34 8027A554 8E450000 */  lw    $a1, ($s2)
/* 1A8E38 8027A558 26520004 */  addiu $s2, $s2, 4
/* 1A8E3C 8027A55C 0C0B1EAF */  jal   get_variable
/* 1A8E40 8027A560 0260202D */   daddu $a0, $s3, $zero
/* 1A8E44 8027A564 0200202D */  daddu $a0, $s0, $zero
/* 1A8E48 8027A568 0C09A75B */  jal   get_actor
/* 1A8E4C 8027A56C 0040882D */   daddu $s1, $v0, $zero
/* 1A8E50 8027A570 0040802D */  daddu $s0, $v0, $zero
/* 1A8E54 8027A574 0200202D */  daddu $a0, $s0, $zero
/* 1A8E58 8027A578 0C099117 */  jal   get_actor_part
/* 1A8E5C 8027A57C 0220282D */   daddu $a1, $s1, $zero
/* 1A8E60 8027A580 0040882D */  daddu $s1, $v0, $zero
/* 1A8E64 8027A584 AE700074 */  sw    $s0, 0x74($s3)
/* 1A8E68 8027A588 AE710078 */  sw    $s1, 0x78($s3)
/* 1A8E6C 8027A58C 8E450000 */  lw    $a1, ($s2)
/* 1A8E70 8027A590 26520004 */  addiu $s2, $s2, 4
/* 1A8E74 8027A594 8E300010 */  lw    $s0, 0x10($s1)
/* 1A8E78 8027A598 0C0B1EAF */  jal   get_variable
/* 1A8E7C 8027A59C 0260202D */   daddu $a0, $s3, $zero
/* 1A8E80 8027A5A0 4482E000 */  mtc1  $v0, $f28
/* 1A8E84 8027A5A4 00000000 */  nop   
/* 1A8E88 8027A5A8 4680E720 */  cvt.s.w $f28, $f28
/* 1A8E8C 8027A5AC 8E450000 */  lw    $a1, ($s2)
/* 1A8E90 8027A5B0 26520004 */  addiu $s2, $s2, 4
/* 1A8E94 8027A5B4 0C0B1EAF */  jal   get_variable
/* 1A8E98 8027A5B8 0260202D */   daddu $a0, $s3, $zero
/* 1A8E9C 8027A5BC 4482F000 */  mtc1  $v0, $f30
/* 1A8EA0 8027A5C0 00000000 */  nop   
/* 1A8EA4 8027A5C4 4680F7A0 */  cvt.s.w $f30, $f30
/* 1A8EA8 8027A5C8 8E450000 */  lw    $a1, ($s2)
/* 1A8EAC 8027A5CC 26520004 */  addiu $s2, $s2, 4
/* 1A8EB0 8027A5D0 0C0B1EAF */  jal   get_variable
/* 1A8EB4 8027A5D4 0260202D */   daddu $a0, $s3, $zero
/* 1A8EB8 8027A5D8 44820000 */  mtc1  $v0, $f0
/* 1A8EBC 8027A5DC 00000000 */  nop   
/* 1A8EC0 8027A5E0 46800020 */  cvt.s.w $f0, $f0
/* 1A8EC4 8027A5E4 E61C000C */  swc1  $f28, 0xc($s0)
/* 1A8EC8 8027A5E8 E61E0010 */  swc1  $f30, 0x10($s0)
/* 1A8ECC 8027A5EC E6000014 */  swc1  $f0, 0x14($s0)
/* 1A8ED0 8027A5F0 8E450000 */  lw    $a1, ($s2)
/* 1A8ED4 8027A5F4 26520004 */  addiu $s2, $s2, 4
/* 1A8ED8 8027A5F8 0C0B1EAF */  jal   get_variable
/* 1A8EDC 8027A5FC 0260202D */   daddu $a0, $s3, $zero
/* 1A8EE0 8027A600 A6020038 */  sh    $v0, 0x38($s0)
/* 1A8EE4 8027A604 8E450000 */  lw    $a1, ($s2)
/* 1A8EE8 8027A608 0C0B1EAF */  jal   get_variable
/* 1A8EEC 8027A60C 0260202D */   daddu $a0, $s3, $zero
/* 1A8EF0 8027A610 AE62007C */  sw    $v0, 0x7c($s3)
/* 1A8EF4 8027A614 C620002C */  lwc1  $f0, 0x2c($s1)
/* 1A8EF8 8027A618 C618000C */  lwc1  $f24, 0xc($s0)
/* 1A8EFC 8027A61C C61A0014 */  lwc1  $f26, 0x14($s0)
/* 1A8F00 8027A620 C6160010 */  lwc1  $f22, 0x10($s0)
/* 1A8F04 8027A624 E6000000 */  swc1  $f0, ($s0)
/* 1A8F08 8027A628 46000706 */  mov.s $f28, $f0
/* 1A8F0C 8027A62C 4406C000 */  mfc1  $a2, $f24
/* 1A8F10 8027A630 4407D000 */  mfc1  $a3, $f26
/* 1A8F14 8027A634 C6200030 */  lwc1  $f0, 0x30($s1)
/* 1A8F18 8027A638 4600E306 */  mov.s $f12, $f28
/* 1A8F1C 8027A63C E6000004 */  swc1  $f0, 4($s0)
/* 1A8F20 8027A640 C6340034 */  lwc1  $f20, 0x34($s1)
/* 1A8F24 8027A644 46000786 */  mov.s $f30, $f0
/* 1A8F28 8027A648 4600A386 */  mov.s $f14, $f20
/* 1A8F2C 8027A64C 0C00A720 */  jal   atan2
/* 1A8F30 8027A650 E6140008 */   swc1  $f20, 8($s0)
/* 1A8F34 8027A654 4600E306 */  mov.s $f12, $f28
/* 1A8F38 8027A658 4600A386 */  mov.s $f14, $f20
/* 1A8F3C 8027A65C 4406C000 */  mfc1  $a2, $f24
/* 1A8F40 8027A660 4407D000 */  mfc1  $a3, $f26
/* 1A8F44 8027A664 461EB781 */  sub.s $f30, $f22, $f30
/* 1A8F48 8027A668 0C00A7B5 */  jal   dist2D
/* 1A8F4C 8027A66C E6000030 */   swc1  $f0, 0x30($s0)
/* 1A8F50 8027A670 86020038 */  lh    $v0, 0x38($s0)
/* 1A8F54 8027A674 46000106 */  mov.s $f4, $f0
/* 1A8F58 8027A678 14400012 */  bnez  $v0, .L8027A6C4
/* 1A8F5C 8027A67C E6040034 */   swc1  $f4, 0x34($s0)
/* 1A8F60 8027A680 C6000028 */  lwc1  $f0, 0x28($s0)
/* 1A8F64 8027A684 C6020028 */  lwc1  $f2, 0x28($s0)
/* 1A8F68 8027A688 46002003 */  div.s $f0, $f4, $f0
/* 1A8F6C 8027A68C 4600028D */  trunc.w.s $f10, $f0
/* 1A8F70 8027A690 44035000 */  mfc1  $v1, $f10
/* 1A8F74 8027A694 00000000 */  nop   
/* 1A8F78 8027A698 00031400 */  sll   $v0, $v1, 0x10
/* 1A8F7C 8027A69C 00021403 */  sra   $v0, $v0, 0x10
/* 1A8F80 8027A6A0 44820000 */  mtc1  $v0, $f0
/* 1A8F84 8027A6A4 00000000 */  nop   
/* 1A8F88 8027A6A8 46800020 */  cvt.s.w $f0, $f0
/* 1A8F8C 8027A6AC 46020002 */  mul.s $f0, $f0, $f2
/* 1A8F90 8027A6B0 00000000 */  nop   
/* 1A8F94 8027A6B4 46002086 */  mov.s $f2, $f4
/* 1A8F98 8027A6B8 A6030038 */  sh    $v1, 0x38($s0)
/* 1A8F9C 8027A6BC 0809E9BE */  j     .L8027A6F8
/* 1A8FA0 8027A6C0 46001201 */   sub.s $f8, $f2, $f0

.L8027A6C4:
/* 1A8FA4 8027A6C4 44821000 */  mtc1  $v0, $f2
/* 1A8FA8 8027A6C8 00000000 */  nop   
/* 1A8FAC 8027A6CC 468010A0 */  cvt.s.w $f2, $f2
/* 1A8FB0 8027A6D0 86020038 */  lh    $v0, 0x38($s0)
/* 1A8FB4 8027A6D4 46022083 */  div.s $f2, $f4, $f2
/* 1A8FB8 8027A6D8 44820000 */  mtc1  $v0, $f0
/* 1A8FBC 8027A6DC 00000000 */  nop   
/* 1A8FC0 8027A6E0 46800020 */  cvt.s.w $f0, $f0
/* 1A8FC4 8027A6E4 46020002 */  mul.s $f0, $f0, $f2
/* 1A8FC8 8027A6E8 00000000 */  nop   
/* 1A8FCC 8027A6EC C6040034 */  lwc1  $f4, 0x34($s0)
/* 1A8FD0 8027A6F0 E6020028 */  swc1  $f2, 0x28($s0)
/* 1A8FD4 8027A6F4 46002201 */  sub.s $f8, $f4, $f0
.L8027A6F8:
/* 1A8FD8 8027A6F8 86020038 */  lh    $v0, 0x38($s0)
/* 1A8FDC 8027A6FC C6020024 */  lwc1  $f2, 0x24($s0)
/* 1A8FE0 8027A700 44823000 */  mtc1  $v0, $f6
/* 1A8FE4 8027A704 00000000 */  nop   
/* 1A8FE8 8027A708 468031A0 */  cvt.s.w $f6, $f6
/* 1A8FEC 8027A70C 46061082 */  mul.s $f2, $f2, $f6
/* 1A8FF0 8027A710 00000000 */  nop   
/* 1A8FF4 8027A714 3C013F00 */  lui   $at, 0x3f00
/* 1A8FF8 8027A718 44810000 */  mtc1  $at, $f0
/* 1A8FFC 8027A71C 00000000 */  nop   
/* 1A9000 8027A720 46001082 */  mul.s $f2, $f2, $f0
/* 1A9004 8027A724 00000000 */  nop   
/* 1A9008 8027A728 C6040028 */  lwc1  $f4, 0x28($s0)
/* 1A900C 8027A72C 46003006 */  mov.s $f0, $f6
/* 1A9010 8027A730 46004003 */  div.s $f0, $f8, $f0
/* 1A9014 8027A734 46002100 */  add.s $f4, $f4, $f0
/* 1A9018 8027A738 4606F183 */  div.s $f6, $f30, $f6
/* 1A901C 8027A73C 46061080 */  add.s $f2, $f2, $f6
/* 1A9020 8027A740 E6040028 */  swc1  $f4, 0x28($s0)
/* 1A9024 8027A744 E602002C */  swc1  $f2, 0x2c($s0)
/* 1A9028 8027A748 8E2200B4 */  lw    $v0, 0xb4($s1)
/* 1A902C 8027A74C 10400009 */  beqz  $v0, .L8027A774
/* 1A9030 8027A750 24020001 */   addiu $v0, $zero, 1
/* 1A9034 8027A754 C6200034 */  lwc1  $f0, 0x34($s1)
/* 1A9038 8027A758 E7A00010 */  swc1  $f0, 0x10($sp)
/* 1A903C 8027A75C 8E2400B4 */  lw    $a0, 0xb4($s1)
/* 1A9040 8027A760 8E26002C */  lw    $a2, 0x2c($s1)
/* 1A9044 8027A764 8E270030 */  lw    $a3, 0x30($s1)
/* 1A9048 8027A768 0C052757 */  jal   play_sound_at_position
/* 1A904C 8027A76C 0000282D */   daddu $a1, $zero, $zero
/* 1A9050 8027A770 24020001 */  addiu $v0, $zero, 1
.L8027A774:
/* 1A9054 8027A774 AE620070 */  sw    $v0, 0x70($s3)
.L8027A778:
/* 1A9058 8027A778 8E710078 */  lw    $s1, 0x78($s3)
/* 1A905C 8027A77C 8E300010 */  lw    $s0, 0x10($s1)
/* 1A9060 8027A780 C6040004 */  lwc1  $f4, 4($s0)
/* 1A9064 8027A784 C600002C */  lwc1  $f0, 0x2c($s0)
/* 1A9068 8027A788 8E050028 */  lw    $a1, 0x28($s0)
/* 1A906C 8027A78C 46002100 */  add.s $f4, $f4, $f0
/* 1A9070 8027A790 C6020024 */  lwc1  $f2, 0x24($s0)
/* 1A9074 8027A794 8E060030 */  lw    $a2, 0x30($s0)
/* 1A9078 8027A798 46020001 */  sub.s $f0, $f0, $f2
/* 1A907C 8027A79C 0200202D */  daddu $a0, $s0, $zero
/* 1A9080 8027A7A0 E6040004 */  swc1  $f4, 4($s0)
/* 1A9084 8027A7A4 0C099070 */  jal   add_xz_vec3f_copy1
/* 1A9088 8027A7A8 E600002C */   swc1  $f0, 0x2c($s0)
/* 1A908C 8027A7AC C6000000 */  lwc1  $f0, ($s0)
/* 1A9090 8027A7B0 E620002C */  swc1  $f0, 0x2c($s1)
/* 1A9094 8027A7B4 C6000004 */  lwc1  $f0, 4($s0)
/* 1A9098 8027A7B8 E6200030 */  swc1  $f0, 0x30($s1)
/* 1A909C 8027A7BC C6000008 */  lwc1  $f0, 8($s0)
/* 1A90A0 8027A7C0 E6200034 */  swc1  $f0, 0x34($s1)
/* 1A90A4 8027A7C4 96020038 */  lhu   $v0, 0x38($s0)
/* 1A90A8 8027A7C8 2442FFFF */  addiu $v0, $v0, -1
/* 1A90AC 8027A7CC A6020038 */  sh    $v0, 0x38($s0)
/* 1A90B0 8027A7D0 00021400 */  sll   $v0, $v0, 0x10
/* 1A90B4 8027A7D4 1C400012 */  bgtz  $v0, .L8027A820
/* 1A90B8 8027A7D8 0000102D */   daddu $v0, $zero, $zero
/* 1A90BC 8027A7DC 8E62007C */  lw    $v0, 0x7c($s3)
/* 1A90C0 8027A7E0 10400008 */  beqz  $v0, .L8027A804
/* 1A90C4 8027A7E4 00000000 */   nop   
/* 1A90C8 8027A7E8 C6000030 */  lwc1  $f0, 0x30($s0)
/* 1A90CC 8027A7EC E7A00010 */  swc1  $f0, 0x10($sp)
/* 1A90D0 8027A7F0 8E05000C */  lw    $a1, 0xc($s0)
/* 1A90D4 8027A7F4 8E060010 */  lw    $a2, 0x10($s0)
/* 1A90D8 8027A7F8 8E070014 */  lw    $a3, 0x14($s0)
/* 1A90DC 8027A7FC 0C0990BC */  jal   play_movement_dust_effects
/* 1A90E0 8027A800 24040002 */   addiu $a0, $zero, 2
.L8027A804:
/* 1A90E4 8027A804 C600000C */  lwc1  $f0, 0xc($s0)
/* 1A90E8 8027A808 E620002C */  swc1  $f0, 0x2c($s1)
/* 1A90EC 8027A80C C6000010 */  lwc1  $f0, 0x10($s0)
/* 1A90F0 8027A810 E6200030 */  swc1  $f0, 0x30($s1)
/* 1A90F4 8027A814 C6000014 */  lwc1  $f0, 0x14($s0)
/* 1A90F8 8027A818 24020001 */  addiu $v0, $zero, 1
/* 1A90FC 8027A81C E6200034 */  swc1  $f0, 0x34($s1)
.L8027A820:
/* 1A9100 8027A820 8FBF0028 */  lw    $ra, 0x28($sp)
/* 1A9104 8027A824 8FB30024 */  lw    $s3, 0x24($sp)
/* 1A9108 8027A828 8FB20020 */  lw    $s2, 0x20($sp)
/* 1A910C 8027A82C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 1A9110 8027A830 8FB00018 */  lw    $s0, 0x18($sp)
/* 1A9114 8027A834 D7BE0058 */  ldc1  $f30, 0x58($sp)
/* 1A9118 8027A838 D7BC0050 */  ldc1  $f28, 0x50($sp)
/* 1A911C 8027A83C D7BA0048 */  ldc1  $f26, 0x48($sp)
/* 1A9120 8027A840 D7B80040 */  ldc1  $f24, 0x40($sp)
/* 1A9124 8027A844 D7B60038 */  ldc1  $f22, 0x38($sp)
/* 1A9128 8027A848 D7B40030 */  ldc1  $f20, 0x30($sp)
/* 1A912C 8027A84C 03E00008 */  jr    $ra
/* 1A9130 8027A850 27BD0060 */   addiu $sp, $sp, 0x60

