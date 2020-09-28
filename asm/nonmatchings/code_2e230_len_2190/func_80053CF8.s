.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053CF8
/* 2F0F8 80053CF8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 2F0FC 80053CFC AFB20028 */  sw        $s2, 0x28($sp)
/* 2F100 80053D00 3C12800A */  lui       $s2, 0x800a
/* 2F104 80053D04 8E52A5C0 */  lw        $s2, -0x5a40($s2)
/* 2F108 80053D08 AFB60038 */  sw        $s6, 0x38($sp)
/* 2F10C 80053D0C 0080B02D */  daddu     $s6, $a0, $zero
/* 2F110 80053D10 AFB3002C */  sw        $s3, 0x2c($sp)
/* 2F114 80053D14 00C0982D */  daddu     $s3, $a2, $zero
/* 2F118 80053D18 AFBF0044 */  sw        $ra, 0x44($sp)
/* 2F11C 80053D1C AFBE0040 */  sw        $fp, 0x40($sp)
/* 2F120 80053D20 AFB7003C */  sw        $s7, 0x3c($sp)
/* 2F124 80053D24 AFB50034 */  sw        $s5, 0x34($sp)
/* 2F128 80053D28 AFB40030 */  sw        $s4, 0x30($sp)
/* 2F12C 80053D2C AFB10024 */  sw        $s1, 0x24($sp)
/* 2F130 80053D30 AFB00020 */  sw        $s0, 0x20($sp)
/* 2F134 80053D34 AFA5004C */  sw        $a1, 0x4c($sp)
/* 2F138 80053D38 8E420030 */  lw        $v0, 0x30($s2)
/* 2F13C 80053D3C 02C2102B */  sltu      $v0, $s6, $v0
/* 2F140 80053D40 10400038 */  beqz      $v0, .L80053E24
/* 2F144 80053D44 00A0B82D */   daddu    $s7, $a1, $zero
/* 2F148 80053D48 24050010 */  addiu     $a1, $zero, 0x10
/* 2F14C 80053D4C 8E43002C */  lw        $v1, 0x2c($s2)
/* 2F150 80053D50 001610C0 */  sll       $v0, $s6, 3
/* 2F154 80053D54 0062A021 */  addu      $s4, $v1, $v0
/* 2F158 80053D58 96840000 */  lhu       $a0, ($s4)
/* 2F15C 80053D5C 0C01511F */  jal       al_CopyFileTableEntry
/* 2F160 80053D60 03A53021 */   addu     $a2, $sp, $a1
/* 2F164 80053D64 14400030 */  bnez      $v0, .L80053E28
/* 2F168 80053D68 00000000 */   nop      
/* 2F16C 80053D6C 0C0136CA */  jal       func_8004DB28
/* 2F170 80053D70 0260202D */   daddu    $a0, $s3, $zero
/* 2F174 80053D74 1440002C */  bnez      $v0, .L80053E28
/* 2F178 80053D78 240200C9 */   addiu    $v0, $zero, 0xc9
/* 2F17C 80053D7C 3C0200FF */  lui       $v0, 0xff
/* 2F180 80053D80 3442FFFF */  ori       $v0, $v0, 0xffff
/* 2F184 80053D84 02E0282D */  daddu     $a1, $s7, $zero
/* 2F188 80053D88 0000802D */  daddu     $s0, $zero, $zero
/* 2F18C 80053D8C 3C1500FF */  lui       $s5, 0xff
/* 2F190 80053D90 36B5FFFF */  ori       $s5, $s5, 0xffff
/* 2F194 80053D94 241E0030 */  addiu     $fp, $zero, 0x30
/* 2F198 80053D98 0280882D */  daddu     $s1, $s4, $zero
/* 2F19C 80053D9C 8FA60014 */  lw        $a2, 0x14($sp)
/* 2F1A0 80053DA0 8FA40010 */  lw        $a0, 0x10($sp)
/* 2F1A4 80053DA4 0C015380 */  jal       al_DmaCopy
/* 2F1A8 80053DA8 00C23024 */   and      $a2, $a2, $v0
.L80053DAC:
/* 2F1AC 80053DAC 96220002 */  lhu       $v0, 2($s1)
/* 2F1B0 80053DB0 50400012 */  beql      $v0, $zero, .L80053DFC
/* 2F1B4 80053DB4 26100001 */   addiu    $s0, $s0, 1
/* 2F1B8 80053DB8 8E440020 */  lw        $a0, 0x20($s2)
/* 2F1BC 80053DBC 000210C0 */  sll       $v0, $v0, 3
/* 2F1C0 80053DC0 00822021 */  addu      $a0, $a0, $v0
/* 2F1C4 80053DC4 8C820000 */  lw        $v0, ($a0)
/* 2F1C8 80053DC8 8E43001C */  lw        $v1, 0x1c($s2)
/* 2F1CC 80053DCC 00551024 */  and       $v0, $v0, $s5
/* 2F1D0 80053DD0 00431821 */  addu      $v1, $v0, $v1
/* 2F1D4 80053DD4 AFA30018 */  sw        $v1, 0x18($sp)
/* 2F1D8 80053DD8 8C820004 */  lw        $v0, 4($a0)
/* 2F1DC 80053DDC AFA2001C */  sw        $v0, 0x1c($sp)
/* 2F1E0 80053DE0 00021602 */  srl       $v0, $v0, 0x18
/* 2F1E4 80053DE4 545E0005 */  bnel      $v0, $fp, .L80053DFC
/* 2F1E8 80053DE8 26100001 */   addiu    $s0, $s0, 1
/* 2F1EC 80053DEC 0060202D */  daddu     $a0, $v1, $zero
/* 2F1F0 80053DF0 0C015313 */  jal       func_80054C4C
/* 2F1F4 80053DF4 0200282D */   daddu    $a1, $s0, $zero
/* 2F1F8 80053DF8 26100001 */  addiu     $s0, $s0, 1
.L80053DFC:
/* 2F1FC 80053DFC 2A020003 */  slti      $v0, $s0, 3
/* 2F200 80053E00 1440FFEA */  bnez      $v0, .L80053DAC
/* 2F204 80053E04 26310002 */   addiu    $s1, $s1, 2
/* 2F208 80053E08 96820000 */  lhu       $v0, ($s4)
/* 2F20C 80053E0C AE760028 */  sw        $s6, 0x28($s3)
/* 2F210 80053E10 8FA7004C */  lw        $a3, 0x4c($sp)
/* 2F214 80053E14 AE670064 */  sw        $a3, 0x64($s3)
/* 2F218 80053E18 AE620024 */  sw        $v0, 0x24($s3)
/* 2F21C 80053E1C 08014F8A */  j         .L80053E28
/* 2F220 80053E20 8EE20008 */   lw       $v0, 8($s7)
.L80053E24:
/* 2F224 80053E24 24020097 */  addiu     $v0, $zero, 0x97
.L80053E28:
/* 2F228 80053E28 8FBF0044 */  lw        $ra, 0x44($sp)
/* 2F22C 80053E2C 8FBE0040 */  lw        $fp, 0x40($sp)
/* 2F230 80053E30 8FB7003C */  lw        $s7, 0x3c($sp)
/* 2F234 80053E34 8FB60038 */  lw        $s6, 0x38($sp)
/* 2F238 80053E38 8FB50034 */  lw        $s5, 0x34($sp)
/* 2F23C 80053E3C 8FB40030 */  lw        $s4, 0x30($sp)
/* 2F240 80053E40 8FB3002C */  lw        $s3, 0x2c($sp)
/* 2F244 80053E44 8FB20028 */  lw        $s2, 0x28($sp)
/* 2F248 80053E48 8FB10024 */  lw        $s1, 0x24($sp)
/* 2F24C 80053E4C 8FB00020 */  lw        $s0, 0x20($sp)
/* 2F250 80053E50 03E00008 */  jr        $ra
/* 2F254 80053E54 27BD0048 */   addiu    $sp, $sp, 0x48
