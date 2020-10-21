.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D7C_B2D1EC
/* B2D1EC 80240D7C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B2D1F0 80240D80 AFB3003C */  sw        $s3, 0x3c($sp)
/* B2D1F4 80240D84 0080982D */  daddu     $s3, $a0, $zero
/* B2D1F8 80240D88 AFBF0040 */  sw        $ra, 0x40($sp)
/* B2D1FC 80240D8C AFB20038 */  sw        $s2, 0x38($sp)
/* B2D200 80240D90 AFB10034 */  sw        $s1, 0x34($sp)
/* B2D204 80240D94 AFB00030 */  sw        $s0, 0x30($sp)
/* B2D208 80240D98 8E720148 */  lw        $s2, 0x148($s3)
/* B2D20C 80240D9C 00A0882D */  daddu     $s1, $a1, $zero
/* B2D210 80240DA0 86440008 */  lh        $a0, 8($s2)
/* B2D214 80240DA4 0C00EABB */  jal       get_npc_unsafe
/* B2D218 80240DA8 00C0802D */   daddu    $s0, $a2, $zero
/* B2D21C 80240DAC 0200202D */  daddu     $a0, $s0, $zero
/* B2D220 80240DB0 0240282D */  daddu     $a1, $s2, $zero
/* B2D224 80240DB4 24030001 */  addiu     $v1, $zero, 1
/* B2D228 80240DB8 AFA30010 */  sw        $v1, 0x10($sp)
/* B2D22C 80240DBC 8E260024 */  lw        $a2, 0x24($s1)
/* B2D230 80240DC0 8E270028 */  lw        $a3, 0x28($s1)
/* B2D234 80240DC4 0C01242D */  jal       func_800490B4
/* B2D238 80240DC8 0040802D */   daddu    $s0, $v0, $zero
/* B2D23C 80240DCC 1440001E */  bnez      $v0, .L80240E48
/* B2D240 80240DD0 0200202D */   daddu    $a0, $s0, $zero
/* B2D244 80240DD4 24040002 */  addiu     $a0, $zero, 2
/* B2D248 80240DD8 0200282D */  daddu     $a1, $s0, $zero
/* B2D24C 80240DDC 0000302D */  daddu     $a2, $zero, $zero
/* B2D250 80240DE0 860300A8 */  lh        $v1, 0xa8($s0)
/* B2D254 80240DE4 3C013F80 */  lui       $at, 0x3f80
/* B2D258 80240DE8 44810000 */  mtc1      $at, $f0
/* B2D25C 80240DEC 3C014000 */  lui       $at, 0x4000
/* B2D260 80240DF0 44811000 */  mtc1      $at, $f2
/* B2D264 80240DF4 3C01C1A0 */  lui       $at, 0xc1a0
/* B2D268 80240DF8 44812000 */  mtc1      $at, $f4
/* B2D26C 80240DFC 2402000F */  addiu     $v0, $zero, 0xf
/* B2D270 80240E00 AFA2001C */  sw        $v0, 0x1c($sp)
/* B2D274 80240E04 44833000 */  mtc1      $v1, $f6
/* B2D278 80240E08 00000000 */  nop       
/* B2D27C 80240E0C 468031A0 */  cvt.s.w   $f6, $f6
/* B2D280 80240E10 44073000 */  mfc1      $a3, $f6
/* B2D284 80240E14 27A20028 */  addiu     $v0, $sp, 0x28
/* B2D288 80240E18 AFA20020 */  sw        $v0, 0x20($sp)
/* B2D28C 80240E1C E7A00010 */  swc1      $f0, 0x10($sp)
/* B2D290 80240E20 E7A20014 */  swc1      $f2, 0x14($sp)
/* B2D294 80240E24 0C01BFA4 */  jal       fx_emote
/* B2D298 80240E28 E7A40018 */   swc1     $f4, 0x18($sp)
/* B2D29C 80240E2C 8E4200CC */  lw        $v0, 0xcc($s2)
/* B2D2A0 80240E30 8C430000 */  lw        $v1, ($v0)
/* B2D2A4 80240E34 24020019 */  addiu     $v0, $zero, 0x19
/* B2D2A8 80240E38 A602008E */  sh        $v0, 0x8e($s0)
/* B2D2AC 80240E3C 2402000E */  addiu     $v0, $zero, 0xe
/* B2D2B0 80240E40 0809039F */  j         .L80240E7C
/* B2D2B4 80240E44 AE030028 */   sw       $v1, 0x28($s0)
.L80240E48:
/* B2D2B8 80240E48 0C00F598 */  jal       func_8003D660
/* B2D2BC 80240E4C 24050001 */   addiu    $a1, $zero, 1
/* B2D2C0 80240E50 8E050018 */  lw        $a1, 0x18($s0)
/* B2D2C4 80240E54 8E06000C */  lw        $a2, 0xc($s0)
/* B2D2C8 80240E58 0C00EA95 */  jal       npc_move_heading
/* B2D2CC 80240E5C 0200202D */   daddu    $a0, $s0, $zero
/* B2D2D0 80240E60 8602008E */  lh        $v0, 0x8e($s0)
/* B2D2D4 80240E64 9603008E */  lhu       $v1, 0x8e($s0)
/* B2D2D8 80240E68 18400003 */  blez      $v0, .L80240E78
/* B2D2DC 80240E6C 2462FFFF */   addiu    $v0, $v1, -1
/* B2D2E0 80240E70 080903A0 */  j         .L80240E80
/* B2D2E4 80240E74 A602008E */   sh       $v0, 0x8e($s0)
.L80240E78:
/* B2D2E8 80240E78 2402000C */  addiu     $v0, $zero, 0xc
.L80240E7C:
/* B2D2EC 80240E7C AE620070 */  sw        $v0, 0x70($s3)
.L80240E80:
/* B2D2F0 80240E80 8FBF0040 */  lw        $ra, 0x40($sp)
/* B2D2F4 80240E84 8FB3003C */  lw        $s3, 0x3c($sp)
/* B2D2F8 80240E88 8FB20038 */  lw        $s2, 0x38($sp)
/* B2D2FC 80240E8C 8FB10034 */  lw        $s1, 0x34($sp)
/* B2D300 80240E90 8FB00030 */  lw        $s0, 0x30($sp)
/* B2D304 80240E94 03E00008 */  jr        $ra
/* B2D308 80240E98 27BD0048 */   addiu    $sp, $sp, 0x48
