.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DDC_852F4C
/* 852F4C 80240DDC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 852F50 80240DE0 AFB3003C */  sw        $s3, 0x3c($sp)
/* 852F54 80240DE4 0080982D */  daddu     $s3, $a0, $zero
/* 852F58 80240DE8 AFBF0040 */  sw        $ra, 0x40($sp)
/* 852F5C 80240DEC AFB20038 */  sw        $s2, 0x38($sp)
/* 852F60 80240DF0 AFB10034 */  sw        $s1, 0x34($sp)
/* 852F64 80240DF4 AFB00030 */  sw        $s0, 0x30($sp)
/* 852F68 80240DF8 8E720148 */  lw        $s2, 0x148($s3)
/* 852F6C 80240DFC 00A0882D */  daddu     $s1, $a1, $zero
/* 852F70 80240E00 86440008 */  lh        $a0, 8($s2)
/* 852F74 80240E04 0C00EABB */  jal       get_npc_unsafe
/* 852F78 80240E08 00C0802D */   daddu    $s0, $a2, $zero
/* 852F7C 80240E0C 0200202D */  daddu     $a0, $s0, $zero
/* 852F80 80240E10 0240282D */  daddu     $a1, $s2, $zero
/* 852F84 80240E14 24030001 */  addiu     $v1, $zero, 1
/* 852F88 80240E18 AFA30010 */  sw        $v1, 0x10($sp)
/* 852F8C 80240E1C 8E260024 */  lw        $a2, 0x24($s1)
/* 852F90 80240E20 8E270028 */  lw        $a3, 0x28($s1)
/* 852F94 80240E24 0C01242D */  jal       func_800490B4
/* 852F98 80240E28 0040802D */   daddu    $s0, $v0, $zero
/* 852F9C 80240E2C 1440001E */  bnez      $v0, .L80240EA8
/* 852FA0 80240E30 0200202D */   daddu    $a0, $s0, $zero
/* 852FA4 80240E34 24040002 */  addiu     $a0, $zero, 2
/* 852FA8 80240E38 0200282D */  daddu     $a1, $s0, $zero
/* 852FAC 80240E3C 0000302D */  daddu     $a2, $zero, $zero
/* 852FB0 80240E40 860300A8 */  lh        $v1, 0xa8($s0)
/* 852FB4 80240E44 3C013F80 */  lui       $at, 0x3f80
/* 852FB8 80240E48 44810000 */  mtc1      $at, $f0
/* 852FBC 80240E4C 3C014000 */  lui       $at, 0x4000
/* 852FC0 80240E50 44811000 */  mtc1      $at, $f2
/* 852FC4 80240E54 3C01C1A0 */  lui       $at, 0xc1a0
/* 852FC8 80240E58 44812000 */  mtc1      $at, $f4
/* 852FCC 80240E5C 2402000F */  addiu     $v0, $zero, 0xf
/* 852FD0 80240E60 AFA2001C */  sw        $v0, 0x1c($sp)
/* 852FD4 80240E64 44833000 */  mtc1      $v1, $f6
/* 852FD8 80240E68 00000000 */  nop
/* 852FDC 80240E6C 468031A0 */  cvt.s.w   $f6, $f6
/* 852FE0 80240E70 44073000 */  mfc1      $a3, $f6
/* 852FE4 80240E74 27A20028 */  addiu     $v0, $sp, 0x28
/* 852FE8 80240E78 AFA20020 */  sw        $v0, 0x20($sp)
/* 852FEC 80240E7C E7A00010 */  swc1      $f0, 0x10($sp)
/* 852FF0 80240E80 E7A20014 */  swc1      $f2, 0x14($sp)
/* 852FF4 80240E84 0C01BFA4 */  jal       fx_emote
/* 852FF8 80240E88 E7A40018 */   swc1     $f4, 0x18($sp)
/* 852FFC 80240E8C 8E4200CC */  lw        $v0, 0xcc($s2)
/* 853000 80240E90 8C430000 */  lw        $v1, ($v0)
/* 853004 80240E94 24020019 */  addiu     $v0, $zero, 0x19
/* 853008 80240E98 A602008E */  sh        $v0, 0x8e($s0)
/* 85300C 80240E9C 2402000E */  addiu     $v0, $zero, 0xe
/* 853010 80240EA0 080903B7 */  j         .L80240EDC
/* 853014 80240EA4 AE030028 */   sw       $v1, 0x28($s0)
.L80240EA8:
/* 853018 80240EA8 0C00F598 */  jal       func_8003D660
/* 85301C 80240EAC 24050001 */   addiu    $a1, $zero, 1
/* 853020 80240EB0 8E050018 */  lw        $a1, 0x18($s0)
/* 853024 80240EB4 8E06000C */  lw        $a2, 0xc($s0)
/* 853028 80240EB8 0C00EA95 */  jal       npc_move_heading
/* 85302C 80240EBC 0200202D */   daddu    $a0, $s0, $zero
/* 853030 80240EC0 8602008E */  lh        $v0, 0x8e($s0)
/* 853034 80240EC4 9603008E */  lhu       $v1, 0x8e($s0)
/* 853038 80240EC8 18400003 */  blez      $v0, .L80240ED8
/* 85303C 80240ECC 2462FFFF */   addiu    $v0, $v1, -1
/* 853040 80240ED0 080903B8 */  j         .L80240EE0
/* 853044 80240ED4 A602008E */   sh       $v0, 0x8e($s0)
.L80240ED8:
/* 853048 80240ED8 2402000C */  addiu     $v0, $zero, 0xc
.L80240EDC:
/* 85304C 80240EDC AE620070 */  sw        $v0, 0x70($s3)
.L80240EE0:
/* 853050 80240EE0 8FBF0040 */  lw        $ra, 0x40($sp)
/* 853054 80240EE4 8FB3003C */  lw        $s3, 0x3c($sp)
/* 853058 80240EE8 8FB20038 */  lw        $s2, 0x38($sp)
/* 85305C 80240EEC 8FB10034 */  lw        $s1, 0x34($sp)
/* 853060 80240EF0 8FB00030 */  lw        $s0, 0x30($sp)
/* 853064 80240EF4 03E00008 */  jr        $ra
/* 853068 80240EF8 27BD0048 */   addiu    $sp, $sp, 0x48
