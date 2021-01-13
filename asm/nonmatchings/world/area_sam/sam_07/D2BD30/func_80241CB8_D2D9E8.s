.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CB8_D2D9E8
/* D2D9E8 80241CB8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D2D9EC 80241CBC AFB40040 */  sw        $s4, 0x40($sp)
/* D2D9F0 80241CC0 0080A02D */  daddu     $s4, $a0, $zero
/* D2D9F4 80241CC4 AFBF0044 */  sw        $ra, 0x44($sp)
/* D2D9F8 80241CC8 AFB3003C */  sw        $s3, 0x3c($sp)
/* D2D9FC 80241CCC AFB20038 */  sw        $s2, 0x38($sp)
/* D2DA00 80241CD0 AFB10034 */  sw        $s1, 0x34($sp)
/* D2DA04 80241CD4 AFB00030 */  sw        $s0, 0x30($sp)
/* D2DA08 80241CD8 8E910148 */  lw        $s1, 0x148($s4)
/* D2DA0C 80241CDC 00A0902D */  daddu     $s2, $a1, $zero
/* D2DA10 80241CE0 86240008 */  lh        $a0, 8($s1)
/* D2DA14 80241CE4 0C00EABB */  jal       get_npc_unsafe
/* D2DA18 80241CE8 00C0982D */   daddu    $s3, $a2, $zero
/* D2DA1C 80241CEC 0040802D */  daddu     $s0, $v0, $zero
/* D2DA20 80241CF0 9602008E */  lhu       $v0, 0x8e($s0)
/* D2DA24 80241CF4 2442FFFF */  addiu     $v0, $v0, -1
/* D2DA28 80241CF8 A602008E */  sh        $v0, 0x8e($s0)
/* D2DA2C 80241CFC 00021400 */  sll       $v0, $v0, 0x10
/* D2DA30 80241D00 14400020 */  bnez      $v0, .L80241D84
/* D2DA34 80241D04 0260202D */   daddu    $a0, $s3, $zero
/* D2DA38 80241D08 AFA00010 */  sw        $zero, 0x10($sp)
/* D2DA3C 80241D0C 8E46000C */  lw        $a2, 0xc($s2)
/* D2DA40 80241D10 8E470010 */  lw        $a3, 0x10($s2)
/* D2DA44 80241D14 0C01242D */  jal       func_800490B4
/* D2DA48 80241D18 0220282D */   daddu    $a1, $s1, $zero
/* D2DA4C 80241D1C 54400018 */  bnel      $v0, $zero, .L80241D80
/* D2DA50 80241D20 A600008E */   sh       $zero, 0x8e($s0)
/* D2DA54 80241D24 24040002 */  addiu     $a0, $zero, 2
/* D2DA58 80241D28 0200282D */  daddu     $a1, $s0, $zero
/* D2DA5C 80241D2C 0000302D */  daddu     $a2, $zero, $zero
/* D2DA60 80241D30 860300A8 */  lh        $v1, 0xa8($s0)
/* D2DA64 80241D34 3C013F80 */  lui       $at, 0x3f80
/* D2DA68 80241D38 44810000 */  mtc1      $at, $f0
/* D2DA6C 80241D3C 3C014000 */  lui       $at, 0x4000
/* D2DA70 80241D40 44811000 */  mtc1      $at, $f2
/* D2DA74 80241D44 3C01C1A0 */  lui       $at, 0xc1a0
/* D2DA78 80241D48 44812000 */  mtc1      $at, $f4
/* D2DA7C 80241D4C 2402000F */  addiu     $v0, $zero, 0xf
/* D2DA80 80241D50 AFA2001C */  sw        $v0, 0x1c($sp)
/* D2DA84 80241D54 44833000 */  mtc1      $v1, $f6
/* D2DA88 80241D58 00000000 */  nop
/* D2DA8C 80241D5C 468031A0 */  cvt.s.w   $f6, $f6
/* D2DA90 80241D60 44073000 */  mfc1      $a3, $f6
/* D2DA94 80241D64 27A20028 */  addiu     $v0, $sp, 0x28
/* D2DA98 80241D68 AFA20020 */  sw        $v0, 0x20($sp)
/* D2DA9C 80241D6C E7A00010 */  swc1      $f0, 0x10($sp)
/* D2DAA0 80241D70 E7A20014 */  swc1      $f2, 0x14($sp)
/* D2DAA4 80241D74 0C01BFA4 */  jal       fx_emote
/* D2DAA8 80241D78 E7A40018 */   swc1     $f4, 0x18($sp)
/* D2DAAC 80241D7C A600008E */  sh        $zero, 0x8e($s0)
.L80241D80:
/* D2DAB0 80241D80 AE800070 */  sw        $zero, 0x70($s4)
.L80241D84:
/* D2DAB4 80241D84 8FBF0044 */  lw        $ra, 0x44($sp)
/* D2DAB8 80241D88 8FB40040 */  lw        $s4, 0x40($sp)
/* D2DABC 80241D8C 8FB3003C */  lw        $s3, 0x3c($sp)
/* D2DAC0 80241D90 8FB20038 */  lw        $s2, 0x38($sp)
/* D2DAC4 80241D94 8FB10034 */  lw        $s1, 0x34($sp)
/* D2DAC8 80241D98 8FB00030 */  lw        $s0, 0x30($sp)
/* D2DACC 80241D9C 03E00008 */  jr        $ra
/* D2DAD0 80241DA0 27BD0048 */   addiu    $sp, $sp, 0x48
