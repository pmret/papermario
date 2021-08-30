.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218930_59F010
/* 59F010 80218930 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 59F014 80218934 AFB10014 */  sw        $s1, 0x14($sp)
/* 59F018 80218938 0080882D */  daddu     $s1, $a0, $zero
/* 59F01C 8021893C AFBF0028 */  sw        $ra, 0x28($sp)
/* 59F020 80218940 AFB50024 */  sw        $s5, 0x24($sp)
/* 59F024 80218944 AFB40020 */  sw        $s4, 0x20($sp)
/* 59F028 80218948 AFB3001C */  sw        $s3, 0x1c($sp)
/* 59F02C 8021894C AFB20018 */  sw        $s2, 0x18($sp)
/* 59F030 80218950 AFB00010 */  sw        $s0, 0x10($sp)
/* 59F034 80218954 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 59F038 80218958 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 59F03C 8021895C 8E30000C */  lw        $s0, 0xc($s1)
/* 59F040 80218960 8E050000 */  lw        $a1, ($s0)
/* 59F044 80218964 0C0B1EAF */  jal       evt_get_variable
/* 59F048 80218968 26100004 */   addiu    $s0, $s0, 4
/* 59F04C 8021896C 8E050000 */  lw        $a1, ($s0)
/* 59F050 80218970 26100004 */  addiu     $s0, $s0, 4
/* 59F054 80218974 8C54000C */  lw        $s4, 0xc($v0)
/* 59F058 80218978 0C0B1EAF */  jal       evt_get_variable
/* 59F05C 8021897C 0220202D */   daddu    $a0, $s1, $zero
/* 59F060 80218980 8E050000 */  lw        $a1, ($s0)
/* 59F064 80218984 26100004 */  addiu     $s0, $s0, 4
/* 59F068 80218988 0220202D */  daddu     $a0, $s1, $zero
/* 59F06C 8021898C 0C0B1EAF */  jal       evt_get_variable
/* 59F070 80218990 0040A82D */   daddu    $s5, $v0, $zero
/* 59F074 80218994 8E050000 */  lw        $a1, ($s0)
/* 59F078 80218998 26100004 */  addiu     $s0, $s0, 4
/* 59F07C 8021899C 0220202D */  daddu     $a0, $s1, $zero
/* 59F080 802189A0 0C0B1EAF */  jal       evt_get_variable
/* 59F084 802189A4 0040902D */   daddu    $s2, $v0, $zero
/* 59F088 802189A8 8E050000 */  lw        $a1, ($s0)
/* 59F08C 802189AC 26100004 */  addiu     $s0, $s0, 4
/* 59F090 802189B0 4482B000 */  mtc1      $v0, $f22
/* 59F094 802189B4 00000000 */  nop
/* 59F098 802189B8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 59F09C 802189BC 0C0B1EAF */  jal       evt_get_variable
/* 59F0A0 802189C0 0220202D */   daddu    $a0, $s1, $zero
/* 59F0A4 802189C4 8E050000 */  lw        $a1, ($s0)
/* 59F0A8 802189C8 26100004 */  addiu     $s0, $s0, 4
/* 59F0AC 802189CC 0220202D */  daddu     $a0, $s1, $zero
/* 59F0B0 802189D0 0C0B1EAF */  jal       evt_get_variable
/* 59F0B4 802189D4 0040982D */   daddu    $s3, $v0, $zero
/* 59F0B8 802189D8 0220202D */  daddu     $a0, $s1, $zero
/* 59F0BC 802189DC 8E050000 */  lw        $a1, ($s0)
/* 59F0C0 802189E0 0C0B1EAF */  jal       evt_get_variable
/* 59F0C4 802189E4 0040882D */   daddu    $s1, $v0, $zero
/* 59F0C8 802189E8 4600B306 */  mov.s     $f12, $f22
/* 59F0CC 802189EC 0C00A8D4 */  jal       cos_deg
/* 59F0D0 802189F0 0040802D */   daddu    $s0, $v0, $zero
/* 59F0D4 802189F4 4493A000 */  mtc1      $s3, $f20
/* 59F0D8 802189F8 00000000 */  nop
/* 59F0DC 802189FC 4680A520 */  cvt.s.w   $f20, $f20
/* 59F0E0 80218A00 46140002 */  mul.s     $f0, $f0, $f20
/* 59F0E4 80218A04 00000000 */  nop
/* 59F0E8 80218A08 44951000 */  mtc1      $s5, $f2
/* 59F0EC 80218A0C 00000000 */  nop
/* 59F0F0 80218A10 468010A0 */  cvt.s.w   $f2, $f2
/* 59F0F4 80218A14 46001081 */  sub.s     $f2, $f2, $f0
/* 59F0F8 80218A18 4600B306 */  mov.s     $f12, $f22
/* 59F0FC 80218A1C 0C00A8BB */  jal       sin_deg
/* 59F100 80218A20 E6820004 */   swc1     $f2, 4($s4)
/* 59F104 80218A24 46140002 */  mul.s     $f0, $f0, $f20
/* 59F108 80218A28 00000000 */  nop
/* 59F10C 80218A2C 3C013C23 */  lui       $at, 0x3c23
/* 59F110 80218A30 3421D70A */  ori       $at, $at, 0xd70a
/* 59F114 80218A34 44811000 */  mtc1      $at, $f2
/* 59F118 80218A38 44902000 */  mtc1      $s0, $f4
/* 59F11C 80218A3C 00000000 */  nop
/* 59F120 80218A40 46802120 */  cvt.s.w   $f4, $f4
/* 59F124 80218A44 46022102 */  mul.s     $f4, $f4, $f2
/* 59F128 80218A48 00000000 */  nop
/* 59F12C 80218A4C 02519021 */  addu      $s2, $s2, $s1
/* 59F130 80218A50 44921000 */  mtc1      $s2, $f2
/* 59F134 80218A54 00000000 */  nop
/* 59F138 80218A58 468010A0 */  cvt.s.w   $f2, $f2
/* 59F13C 80218A5C 46001081 */  sub.s     $f2, $f2, $f0
/* 59F140 80218A60 E6840010 */  swc1      $f4, 0x10($s4)
/* 59F144 80218A64 E6820008 */  swc1      $f2, 8($s4)
/* 59F148 80218A68 8FBF0028 */  lw        $ra, 0x28($sp)
/* 59F14C 80218A6C 8FB50024 */  lw        $s5, 0x24($sp)
/* 59F150 80218A70 8FB40020 */  lw        $s4, 0x20($sp)
/* 59F154 80218A74 8FB3001C */  lw        $s3, 0x1c($sp)
/* 59F158 80218A78 8FB20018 */  lw        $s2, 0x18($sp)
/* 59F15C 80218A7C 8FB10014 */  lw        $s1, 0x14($sp)
/* 59F160 80218A80 8FB00010 */  lw        $s0, 0x10($sp)
/* 59F164 80218A84 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 59F168 80218A88 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 59F16C 80218A8C 24020002 */  addiu     $v0, $zero, 2
/* 59F170 80218A90 03E00008 */  jr        $ra
/* 59F174 80218A94 27BD0040 */   addiu    $sp, $sp, 0x40
