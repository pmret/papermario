.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242E78_C006F8
/* C006F8 80242E78 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C006FC 80242E7C AFB3003C */  sw        $s3, 0x3c($sp)
/* C00700 80242E80 0080982D */  daddu     $s3, $a0, $zero
/* C00704 80242E84 AFBF0040 */  sw        $ra, 0x40($sp)
/* C00708 80242E88 AFB20038 */  sw        $s2, 0x38($sp)
/* C0070C 80242E8C AFB10034 */  sw        $s1, 0x34($sp)
/* C00710 80242E90 AFB00030 */  sw        $s0, 0x30($sp)
/* C00714 80242E94 8E720148 */  lw        $s2, 0x148($s3)
/* C00718 80242E98 00A0882D */  daddu     $s1, $a1, $zero
/* C0071C 80242E9C 86440008 */  lh        $a0, 8($s2)
/* C00720 80242EA0 0C00EABB */  jal       get_npc_unsafe
/* C00724 80242EA4 00C0802D */   daddu    $s0, $a2, $zero
/* C00728 80242EA8 0200202D */  daddu     $a0, $s0, $zero
/* C0072C 80242EAC 0240282D */  daddu     $a1, $s2, $zero
/* C00730 80242EB0 24030001 */  addiu     $v1, $zero, 1
/* C00734 80242EB4 AFA30010 */  sw        $v1, 0x10($sp)
/* C00738 80242EB8 8E260024 */  lw        $a2, 0x24($s1)
/* C0073C 80242EBC 8E270028 */  lw        $a3, 0x28($s1)
/* C00740 80242EC0 0C01242D */  jal       func_800490B4
/* C00744 80242EC4 0040802D */   daddu    $s0, $v0, $zero
/* C00748 80242EC8 1440001E */  bnez      $v0, .L80242F44
/* C0074C 80242ECC 0200202D */   daddu    $a0, $s0, $zero
/* C00750 80242ED0 24040002 */  addiu     $a0, $zero, 2
/* C00754 80242ED4 0200282D */  daddu     $a1, $s0, $zero
/* C00758 80242ED8 0000302D */  daddu     $a2, $zero, $zero
/* C0075C 80242EDC 860300A8 */  lh        $v1, 0xa8($s0)
/* C00760 80242EE0 3C013F80 */  lui       $at, 0x3f80
/* C00764 80242EE4 44810000 */  mtc1      $at, $f0
/* C00768 80242EE8 3C014000 */  lui       $at, 0x4000
/* C0076C 80242EEC 44811000 */  mtc1      $at, $f2
/* C00770 80242EF0 3C01C1A0 */  lui       $at, 0xc1a0
/* C00774 80242EF4 44812000 */  mtc1      $at, $f4
/* C00778 80242EF8 2402000F */  addiu     $v0, $zero, 0xf
/* C0077C 80242EFC AFA2001C */  sw        $v0, 0x1c($sp)
/* C00780 80242F00 44833000 */  mtc1      $v1, $f6
/* C00784 80242F04 00000000 */  nop
/* C00788 80242F08 468031A0 */  cvt.s.w   $f6, $f6
/* C0078C 80242F0C 44073000 */  mfc1      $a3, $f6
/* C00790 80242F10 27A20028 */  addiu     $v0, $sp, 0x28
/* C00794 80242F14 AFA20020 */  sw        $v0, 0x20($sp)
/* C00798 80242F18 E7A00010 */  swc1      $f0, 0x10($sp)
/* C0079C 80242F1C E7A20014 */  swc1      $f2, 0x14($sp)
/* C007A0 80242F20 0C01BFA4 */  jal       fx_emote
/* C007A4 80242F24 E7A40018 */   swc1     $f4, 0x18($sp)
/* C007A8 80242F28 8E4200CC */  lw        $v0, 0xcc($s2)
/* C007AC 80242F2C 8C430000 */  lw        $v1, ($v0)
/* C007B0 80242F30 24020019 */  addiu     $v0, $zero, 0x19
/* C007B4 80242F34 A602008E */  sh        $v0, 0x8e($s0)
/* C007B8 80242F38 2402000E */  addiu     $v0, $zero, 0xe
/* C007BC 80242F3C 08090BDE */  j         .L80242F78
/* C007C0 80242F40 AE030028 */   sw       $v1, 0x28($s0)
.L80242F44:
/* C007C4 80242F44 0C00F598 */  jal       func_8003D660
/* C007C8 80242F48 24050001 */   addiu    $a1, $zero, 1
/* C007CC 80242F4C 8E050018 */  lw        $a1, 0x18($s0)
/* C007D0 80242F50 8E06000C */  lw        $a2, 0xc($s0)
/* C007D4 80242F54 0C00EA95 */  jal       npc_move_heading
/* C007D8 80242F58 0200202D */   daddu    $a0, $s0, $zero
/* C007DC 80242F5C 8602008E */  lh        $v0, 0x8e($s0)
/* C007E0 80242F60 9603008E */  lhu       $v1, 0x8e($s0)
/* C007E4 80242F64 18400003 */  blez      $v0, .L80242F74
/* C007E8 80242F68 2462FFFF */   addiu    $v0, $v1, -1
/* C007EC 80242F6C 08090BDF */  j         .L80242F7C
/* C007F0 80242F70 A602008E */   sh       $v0, 0x8e($s0)
.L80242F74:
/* C007F4 80242F74 2402000C */  addiu     $v0, $zero, 0xc
.L80242F78:
/* C007F8 80242F78 AE620070 */  sw        $v0, 0x70($s3)
.L80242F7C:
/* C007FC 80242F7C 8FBF0040 */  lw        $ra, 0x40($sp)
/* C00800 80242F80 8FB3003C */  lw        $s3, 0x3c($sp)
/* C00804 80242F84 8FB20038 */  lw        $s2, 0x38($sp)
/* C00808 80242F88 8FB10034 */  lw        $s1, 0x34($sp)
/* C0080C 80242F8C 8FB00030 */  lw        $s0, 0x30($sp)
/* C00810 80242F90 03E00008 */  jr        $ra
/* C00814 80242F94 27BD0048 */   addiu    $sp, $sp, 0x48
