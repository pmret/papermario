.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EBC_7EDBCC
/* 7EDBCC 80242EBC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 7EDBD0 80242EC0 AFB3003C */  sw        $s3, 0x3c($sp)
/* 7EDBD4 80242EC4 0080982D */  daddu     $s3, $a0, $zero
/* 7EDBD8 80242EC8 AFBF0040 */  sw        $ra, 0x40($sp)
/* 7EDBDC 80242ECC AFB20038 */  sw        $s2, 0x38($sp)
/* 7EDBE0 80242ED0 AFB10034 */  sw        $s1, 0x34($sp)
/* 7EDBE4 80242ED4 AFB00030 */  sw        $s0, 0x30($sp)
/* 7EDBE8 80242ED8 8E720148 */  lw        $s2, 0x148($s3)
/* 7EDBEC 80242EDC 00A0882D */  daddu     $s1, $a1, $zero
/* 7EDBF0 80242EE0 86440008 */  lh        $a0, 8($s2)
/* 7EDBF4 80242EE4 0C00EABB */  jal       get_npc_unsafe
/* 7EDBF8 80242EE8 00C0802D */   daddu    $s0, $a2, $zero
/* 7EDBFC 80242EEC 0200202D */  daddu     $a0, $s0, $zero
/* 7EDC00 80242EF0 0240282D */  daddu     $a1, $s2, $zero
/* 7EDC04 80242EF4 24030001 */  addiu     $v1, $zero, 1
/* 7EDC08 80242EF8 AFA30010 */  sw        $v1, 0x10($sp)
/* 7EDC0C 80242EFC 8E260024 */  lw        $a2, 0x24($s1)
/* 7EDC10 80242F00 8E270028 */  lw        $a3, 0x28($s1)
/* 7EDC14 80242F04 0C01242D */  jal       func_800490B4
/* 7EDC18 80242F08 0040802D */   daddu    $s0, $v0, $zero
/* 7EDC1C 80242F0C 1440001E */  bnez      $v0, .L80242F88
/* 7EDC20 80242F10 0200202D */   daddu    $a0, $s0, $zero
/* 7EDC24 80242F14 24040002 */  addiu     $a0, $zero, 2
/* 7EDC28 80242F18 0200282D */  daddu     $a1, $s0, $zero
/* 7EDC2C 80242F1C 0000302D */  daddu     $a2, $zero, $zero
/* 7EDC30 80242F20 860300A8 */  lh        $v1, 0xa8($s0)
/* 7EDC34 80242F24 3C013F80 */  lui       $at, 0x3f80
/* 7EDC38 80242F28 44810000 */  mtc1      $at, $f0
/* 7EDC3C 80242F2C 3C014000 */  lui       $at, 0x4000
/* 7EDC40 80242F30 44811000 */  mtc1      $at, $f2
/* 7EDC44 80242F34 3C01C1A0 */  lui       $at, 0xc1a0
/* 7EDC48 80242F38 44812000 */  mtc1      $at, $f4
/* 7EDC4C 80242F3C 2402000F */  addiu     $v0, $zero, 0xf
/* 7EDC50 80242F40 AFA2001C */  sw        $v0, 0x1c($sp)
/* 7EDC54 80242F44 44833000 */  mtc1      $v1, $f6
/* 7EDC58 80242F48 00000000 */  nop
/* 7EDC5C 80242F4C 468031A0 */  cvt.s.w   $f6, $f6
/* 7EDC60 80242F50 44073000 */  mfc1      $a3, $f6
/* 7EDC64 80242F54 27A20028 */  addiu     $v0, $sp, 0x28
/* 7EDC68 80242F58 AFA20020 */  sw        $v0, 0x20($sp)
/* 7EDC6C 80242F5C E7A00010 */  swc1      $f0, 0x10($sp)
/* 7EDC70 80242F60 E7A20014 */  swc1      $f2, 0x14($sp)
/* 7EDC74 80242F64 0C01BFA4 */  jal       fx_emote
/* 7EDC78 80242F68 E7A40018 */   swc1     $f4, 0x18($sp)
/* 7EDC7C 80242F6C 8E4200CC */  lw        $v0, 0xcc($s2)
/* 7EDC80 80242F70 8C430000 */  lw        $v1, ($v0)
/* 7EDC84 80242F74 24020019 */  addiu     $v0, $zero, 0x19
/* 7EDC88 80242F78 A602008E */  sh        $v0, 0x8e($s0)
/* 7EDC8C 80242F7C 2402000E */  addiu     $v0, $zero, 0xe
/* 7EDC90 80242F80 08090BEF */  j         .L80242FBC
/* 7EDC94 80242F84 AE030028 */   sw       $v1, 0x28($s0)
.L80242F88:
/* 7EDC98 80242F88 0C00F598 */  jal       func_8003D660
/* 7EDC9C 80242F8C 24050001 */   addiu    $a1, $zero, 1
/* 7EDCA0 80242F90 8E050018 */  lw        $a1, 0x18($s0)
/* 7EDCA4 80242F94 8E06000C */  lw        $a2, 0xc($s0)
/* 7EDCA8 80242F98 0C00EA95 */  jal       npc_move_heading
/* 7EDCAC 80242F9C 0200202D */   daddu    $a0, $s0, $zero
/* 7EDCB0 80242FA0 8602008E */  lh        $v0, 0x8e($s0)
/* 7EDCB4 80242FA4 9603008E */  lhu       $v1, 0x8e($s0)
/* 7EDCB8 80242FA8 18400003 */  blez      $v0, .L80242FB8
/* 7EDCBC 80242FAC 2462FFFF */   addiu    $v0, $v1, -1
/* 7EDCC0 80242FB0 08090BF0 */  j         .L80242FC0
/* 7EDCC4 80242FB4 A602008E */   sh       $v0, 0x8e($s0)
.L80242FB8:
/* 7EDCC8 80242FB8 2402000C */  addiu     $v0, $zero, 0xc
.L80242FBC:
/* 7EDCCC 80242FBC AE620070 */  sw        $v0, 0x70($s3)
.L80242FC0:
/* 7EDCD0 80242FC0 8FBF0040 */  lw        $ra, 0x40($sp)
/* 7EDCD4 80242FC4 8FB3003C */  lw        $s3, 0x3c($sp)
/* 7EDCD8 80242FC8 8FB20038 */  lw        $s2, 0x38($sp)
/* 7EDCDC 80242FCC 8FB10034 */  lw        $s1, 0x34($sp)
/* 7EDCE0 80242FD0 8FB00030 */  lw        $s0, 0x30($sp)
/* 7EDCE4 80242FD4 03E00008 */  jr        $ra
/* 7EDCE8 80242FD8 27BD0048 */   addiu    $sp, $sp, 0x48
