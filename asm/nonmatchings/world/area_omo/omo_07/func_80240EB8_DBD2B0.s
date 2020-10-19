.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB8_DBE168
/* DBE168 80240EB8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DBE16C 80240EBC AFB3003C */  sw        $s3, 0x3c($sp)
/* DBE170 80240EC0 0080982D */  daddu     $s3, $a0, $zero
/* DBE174 80240EC4 AFBF0040 */  sw        $ra, 0x40($sp)
/* DBE178 80240EC8 AFB20038 */  sw        $s2, 0x38($sp)
/* DBE17C 80240ECC AFB10034 */  sw        $s1, 0x34($sp)
/* DBE180 80240ED0 AFB00030 */  sw        $s0, 0x30($sp)
/* DBE184 80240ED4 8E720148 */  lw        $s2, 0x148($s3)
/* DBE188 80240ED8 00A0882D */  daddu     $s1, $a1, $zero
/* DBE18C 80240EDC 86440008 */  lh        $a0, 8($s2)
/* DBE190 80240EE0 0C00EABB */  jal       get_npc_unsafe
/* DBE194 80240EE4 00C0802D */   daddu    $s0, $a2, $zero
/* DBE198 80240EE8 0200202D */  daddu     $a0, $s0, $zero
/* DBE19C 80240EEC 0240282D */  daddu     $a1, $s2, $zero
/* DBE1A0 80240EF0 24030001 */  addiu     $v1, $zero, 1
/* DBE1A4 80240EF4 AFA30010 */  sw        $v1, 0x10($sp)
/* DBE1A8 80240EF8 8E260024 */  lw        $a2, 0x24($s1)
/* DBE1AC 80240EFC 8E270028 */  lw        $a3, 0x28($s1)
/* DBE1B0 80240F00 0C01242D */  jal       func_800490B4
/* DBE1B4 80240F04 0040802D */   daddu    $s0, $v0, $zero
/* DBE1B8 80240F08 1440001E */  bnez      $v0, .L80240F84
/* DBE1BC 80240F0C 0200202D */   daddu    $a0, $s0, $zero
/* DBE1C0 80240F10 24040002 */  addiu     $a0, $zero, 2
/* DBE1C4 80240F14 0200282D */  daddu     $a1, $s0, $zero
/* DBE1C8 80240F18 0000302D */  daddu     $a2, $zero, $zero
/* DBE1CC 80240F1C 860300A8 */  lh        $v1, 0xa8($s0)
/* DBE1D0 80240F20 3C013F80 */  lui       $at, 0x3f80
/* DBE1D4 80240F24 44810000 */  mtc1      $at, $f0
/* DBE1D8 80240F28 3C014000 */  lui       $at, 0x4000
/* DBE1DC 80240F2C 44811000 */  mtc1      $at, $f2
/* DBE1E0 80240F30 3C01C1A0 */  lui       $at, 0xc1a0
/* DBE1E4 80240F34 44812000 */  mtc1      $at, $f4
/* DBE1E8 80240F38 2402000F */  addiu     $v0, $zero, 0xf
/* DBE1EC 80240F3C AFA2001C */  sw        $v0, 0x1c($sp)
/* DBE1F0 80240F40 44833000 */  mtc1      $v1, $f6
/* DBE1F4 80240F44 00000000 */  nop       
/* DBE1F8 80240F48 468031A0 */  cvt.s.w   $f6, $f6
/* DBE1FC 80240F4C 44073000 */  mfc1      $a3, $f6
/* DBE200 80240F50 27A20028 */  addiu     $v0, $sp, 0x28
/* DBE204 80240F54 AFA20020 */  sw        $v0, 0x20($sp)
/* DBE208 80240F58 E7A00010 */  swc1      $f0, 0x10($sp)
/* DBE20C 80240F5C E7A20014 */  swc1      $f2, 0x14($sp)
/* DBE210 80240F60 0C01BFA4 */  jal       fx_emote
/* DBE214 80240F64 E7A40018 */   swc1     $f4, 0x18($sp)
/* DBE218 80240F68 8E4200CC */  lw        $v0, 0xcc($s2)
/* DBE21C 80240F6C 8C430000 */  lw        $v1, ($v0)
/* DBE220 80240F70 24020019 */  addiu     $v0, $zero, 0x19
/* DBE224 80240F74 A602008E */  sh        $v0, 0x8e($s0)
/* DBE228 80240F78 2402000E */  addiu     $v0, $zero, 0xe
/* DBE22C 80240F7C 080903EE */  j         .L80240FB8
/* DBE230 80240F80 AE030028 */   sw       $v1, 0x28($s0)
.L80240F84:
/* DBE234 80240F84 0C00F598 */  jal       func_8003D660
/* DBE238 80240F88 24050001 */   addiu    $a1, $zero, 1
/* DBE23C 80240F8C 8E050018 */  lw        $a1, 0x18($s0)
/* DBE240 80240F90 8E06000C */  lw        $a2, 0xc($s0)
/* DBE244 80240F94 0C00EA95 */  jal       npc_move_heading
/* DBE248 80240F98 0200202D */   daddu    $a0, $s0, $zero
/* DBE24C 80240F9C 8602008E */  lh        $v0, 0x8e($s0)
/* DBE250 80240FA0 9603008E */  lhu       $v1, 0x8e($s0)
/* DBE254 80240FA4 18400003 */  blez      $v0, .L80240FB4
/* DBE258 80240FA8 2462FFFF */   addiu    $v0, $v1, -1
/* DBE25C 80240FAC 080903EF */  j         .L80240FBC
/* DBE260 80240FB0 A602008E */   sh       $v0, 0x8e($s0)
.L80240FB4:
/* DBE264 80240FB4 2402000C */  addiu     $v0, $zero, 0xc
.L80240FB8:
/* DBE268 80240FB8 AE620070 */  sw        $v0, 0x70($s3)
.L80240FBC:
/* DBE26C 80240FBC 8FBF0040 */  lw        $ra, 0x40($sp)
/* DBE270 80240FC0 8FB3003C */  lw        $s3, 0x3c($sp)
/* DBE274 80240FC4 8FB20038 */  lw        $s2, 0x38($sp)
/* DBE278 80240FC8 8FB10034 */  lw        $s1, 0x34($sp)
/* DBE27C 80240FCC 8FB00030 */  lw        $s0, 0x30($sp)
/* DBE280 80240FD0 03E00008 */  jr        $ra
/* DBE284 80240FD4 27BD0048 */   addiu    $sp, $sp, 0x48
