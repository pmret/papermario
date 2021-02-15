.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F2C_95C12C
/* 95C12C 80240F2C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 95C130 80240F30 AFB3003C */  sw        $s3, 0x3c($sp)
/* 95C134 80240F34 0080982D */  daddu     $s3, $a0, $zero
/* 95C138 80240F38 AFBF0040 */  sw        $ra, 0x40($sp)
/* 95C13C 80240F3C AFB20038 */  sw        $s2, 0x38($sp)
/* 95C140 80240F40 AFB10034 */  sw        $s1, 0x34($sp)
/* 95C144 80240F44 AFB00030 */  sw        $s0, 0x30($sp)
/* 95C148 80240F48 8E720148 */  lw        $s2, 0x148($s3)
/* 95C14C 80240F4C 00A0882D */  daddu     $s1, $a1, $zero
/* 95C150 80240F50 86440008 */  lh        $a0, 8($s2)
/* 95C154 80240F54 0C00EABB */  jal       get_npc_unsafe
/* 95C158 80240F58 00C0802D */   daddu    $s0, $a2, $zero
/* 95C15C 80240F5C 0200202D */  daddu     $a0, $s0, $zero
/* 95C160 80240F60 0240282D */  daddu     $a1, $s2, $zero
/* 95C164 80240F64 24030001 */  addiu     $v1, $zero, 1
/* 95C168 80240F68 AFA30010 */  sw        $v1, 0x10($sp)
/* 95C16C 80240F6C 8E260024 */  lw        $a2, 0x24($s1)
/* 95C170 80240F70 8E270028 */  lw        $a3, 0x28($s1)
/* 95C174 80240F74 0C01242D */  jal       func_800490B4
/* 95C178 80240F78 0040802D */   daddu    $s0, $v0, $zero
/* 95C17C 80240F7C 1440001E */  bnez      $v0, .L80240FF8
/* 95C180 80240F80 0200202D */   daddu    $a0, $s0, $zero
/* 95C184 80240F84 24040002 */  addiu     $a0, $zero, 2
/* 95C188 80240F88 0200282D */  daddu     $a1, $s0, $zero
/* 95C18C 80240F8C 0000302D */  daddu     $a2, $zero, $zero
/* 95C190 80240F90 860300A8 */  lh        $v1, 0xa8($s0)
/* 95C194 80240F94 3C013F80 */  lui       $at, 0x3f80
/* 95C198 80240F98 44810000 */  mtc1      $at, $f0
/* 95C19C 80240F9C 3C014000 */  lui       $at, 0x4000
/* 95C1A0 80240FA0 44811000 */  mtc1      $at, $f2
/* 95C1A4 80240FA4 3C01C1A0 */  lui       $at, 0xc1a0
/* 95C1A8 80240FA8 44812000 */  mtc1      $at, $f4
/* 95C1AC 80240FAC 2402000F */  addiu     $v0, $zero, 0xf
/* 95C1B0 80240FB0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 95C1B4 80240FB4 44833000 */  mtc1      $v1, $f6
/* 95C1B8 80240FB8 00000000 */  nop
/* 95C1BC 80240FBC 468031A0 */  cvt.s.w   $f6, $f6
/* 95C1C0 80240FC0 44073000 */  mfc1      $a3, $f6
/* 95C1C4 80240FC4 27A20028 */  addiu     $v0, $sp, 0x28
/* 95C1C8 80240FC8 AFA20020 */  sw        $v0, 0x20($sp)
/* 95C1CC 80240FCC E7A00010 */  swc1      $f0, 0x10($sp)
/* 95C1D0 80240FD0 E7A20014 */  swc1      $f2, 0x14($sp)
/* 95C1D4 80240FD4 0C01BFA4 */  jal       fx_emote
/* 95C1D8 80240FD8 E7A40018 */   swc1     $f4, 0x18($sp)
/* 95C1DC 80240FDC 8E4200CC */  lw        $v0, 0xcc($s2)
/* 95C1E0 80240FE0 8C430000 */  lw        $v1, ($v0)
/* 95C1E4 80240FE4 24020019 */  addiu     $v0, $zero, 0x19
/* 95C1E8 80240FE8 A602008E */  sh        $v0, 0x8e($s0)
/* 95C1EC 80240FEC 2402000E */  addiu     $v0, $zero, 0xe
/* 95C1F0 80240FF0 0809040B */  j         .L8024102C
/* 95C1F4 80240FF4 AE030028 */   sw       $v1, 0x28($s0)
.L80240FF8:
/* 95C1F8 80240FF8 0C00F598 */  jal       func_8003D660
/* 95C1FC 80240FFC 24050001 */   addiu    $a1, $zero, 1
/* 95C200 80241000 8E050018 */  lw        $a1, 0x18($s0)
/* 95C204 80241004 8E06000C */  lw        $a2, 0xc($s0)
/* 95C208 80241008 0C00EA95 */  jal       npc_move_heading
/* 95C20C 8024100C 0200202D */   daddu    $a0, $s0, $zero
/* 95C210 80241010 8602008E */  lh        $v0, 0x8e($s0)
/* 95C214 80241014 9603008E */  lhu       $v1, 0x8e($s0)
/* 95C218 80241018 18400003 */  blez      $v0, .L80241028
/* 95C21C 8024101C 2462FFFF */   addiu    $v0, $v1, -1
/* 95C220 80241020 0809040C */  j         .L80241030
/* 95C224 80241024 A602008E */   sh       $v0, 0x8e($s0)
.L80241028:
/* 95C228 80241028 2402000C */  addiu     $v0, $zero, 0xc
.L8024102C:
/* 95C22C 8024102C AE620070 */  sw        $v0, 0x70($s3)
.L80241030:
/* 95C230 80241030 8FBF0040 */  lw        $ra, 0x40($sp)
/* 95C234 80241034 8FB3003C */  lw        $s3, 0x3c($sp)
/* 95C238 80241038 8FB20038 */  lw        $s2, 0x38($sp)
/* 95C23C 8024103C 8FB10034 */  lw        $s1, 0x34($sp)
/* 95C240 80241040 8FB00030 */  lw        $s0, 0x30($sp)
/* 95C244 80241044 03E00008 */  jr        $ra
/* 95C248 80241048 27BD0048 */   addiu    $sp, $sp, 0x48
