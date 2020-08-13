.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetCamPerspective
/* 0EF1D8 802CA828 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0EF1DC 802CA82C AFB10014 */  sw    $s1, 0x14($sp)
/* 0EF1E0 802CA830 0080882D */  daddu $s1, $a0, $zero
/* 0EF1E4 802CA834 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0EF1E8 802CA838 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0EF1EC 802CA83C AFB20018 */  sw    $s2, 0x18($sp)
/* 0EF1F0 802CA840 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EF1F4 802CA844 F7B40028 */  sdc1  $f20, 0x28($sp)
/* 0EF1F8 802CA848 8E30000C */  lw    $s0, 0xc($s1)
/* 0EF1FC 802CA84C 8E050000 */  lw    $a1, ($s0)
/* 0EF200 802CA850 0C0B1EAF */  jal   get_variable
/* 0EF204 802CA854 26100004 */   addiu $s0, $s0, 4
/* 0EF208 802CA858 8E050000 */  lw    $a1, ($s0)
/* 0EF20C 802CA85C 26100004 */  addiu $s0, $s0, 4
/* 0EF210 802CA860 0220202D */  daddu $a0, $s1, $zero
/* 0EF214 802CA864 0C0B1EAF */  jal   get_variable
/* 0EF218 802CA868 0040902D */   daddu $s2, $v0, $zero
/* 0EF21C 802CA86C 8E050000 */  lw    $a1, ($s0)
/* 0EF220 802CA870 26100004 */  addiu $s0, $s0, 4
/* 0EF224 802CA874 0220202D */  daddu $a0, $s1, $zero
/* 0EF228 802CA878 0C0B210B */  jal   get_float_variable
/* 0EF22C 802CA87C 0040982D */   daddu $s3, $v0, $zero
/* 0EF230 802CA880 8E050000 */  lw    $a1, ($s0)
/* 0EF234 802CA884 26100004 */  addiu $s0, $s0, 4
/* 0EF238 802CA888 0220202D */  daddu $a0, $s1, $zero
/* 0EF23C 802CA88C 0C0B1EAF */  jal   get_variable
/* 0EF240 802CA890 46000506 */   mov.s $f20, $f0
/* 0EF244 802CA894 0220202D */  daddu $a0, $s1, $zero
/* 0EF248 802CA898 8E050000 */  lw    $a1, ($s0)
/* 0EF24C 802CA89C 0C0B1EAF */  jal   get_variable
/* 0EF250 802CA8A0 0040802D */   daddu $s0, $v0, $zero
/* 0EF254 802CA8A4 3C05800B */  lui   $a1, 0x800b
/* 0EF258 802CA8A8 24A51D80 */  addiu $a1, $a1, 0x1d80
/* 0EF25C 802CA8AC 00121880 */  sll   $v1, $s2, 2
/* 0EF260 802CA8B0 00721821 */  addu  $v1, $v1, $s2
/* 0EF264 802CA8B4 00031880 */  sll   $v1, $v1, 2
/* 0EF268 802CA8B8 00721823 */  subu  $v1, $v1, $s2
/* 0EF26C 802CA8BC 000320C0 */  sll   $a0, $v1, 3
/* 0EF270 802CA8C0 00641821 */  addu  $v1, $v1, $a0
/* 0EF274 802CA8C4 000318C0 */  sll   $v1, $v1, 3
/* 0EF278 802CA8C8 00651821 */  addu  $v1, $v1, $a1
/* 0EF27C 802CA8CC 24040001 */  addiu $a0, $zero, 1
/* 0EF280 802CA8D0 A4620014 */  sh    $v0, 0x14($v1)
/* 0EF284 802CA8D4 A4730004 */  sh    $s3, 4($v1)
/* 0EF288 802CA8D8 A4640006 */  sh    $a0, 6($v1)
/* 0EF28C 802CA8DC A4640008 */  sh    $a0, 8($v1)
/* 0EF290 802CA8E0 E4740018 */  swc1  $f20, 0x18($v1)
/* 0EF294 802CA8E4 A4700012 */  sh    $s0, 0x12($v1)
/* 0EF298 802CA8E8 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0EF29C 802CA8EC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0EF2A0 802CA8F0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EF2A4 802CA8F4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EF2A8 802CA8F8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EF2AC 802CA8FC D7B40028 */  ldc1  $f20, 0x28($sp)
/* 0EF2B0 802CA900 24020002 */  addiu $v0, $zero, 2
/* 0EF2B4 802CA904 03E00008 */  jr    $ra
/* 0EF2B8 802CA908 27BD0030 */   addiu $sp, $sp, 0x30

/* 0EF2BC 802CA90C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EF2C0 802CA910 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EF2C4 802CA914 0080882D */  daddu $s1, $a0, $zero
/* 0EF2C8 802CA918 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EF2CC 802CA91C AFB00010 */  sw    $s0, 0x10($sp)
/* 0EF2D0 802CA920 8E30000C */  lw    $s0, 0xc($s1)
/* 0EF2D4 802CA924 8E050000 */  lw    $a1, ($s0)
/* 0EF2D8 802CA928 0C0B1EAF */  jal   get_variable
/* 0EF2DC 802CA92C 26100004 */   addiu $s0, $s0, 4
/* 0EF2E0 802CA930 0220202D */  daddu $a0, $s1, $zero
/* 0EF2E4 802CA934 8E050000 */  lw    $a1, ($s0)
/* 0EF2E8 802CA938 0C0B1EAF */  jal   get_variable
/* 0EF2EC 802CA93C 0040802D */   daddu $s0, $v0, $zero
/* 0EF2F0 802CA940 3C05800B */  lui   $a1, 0x800b
/* 0EF2F4 802CA944 24A51D80 */  addiu $a1, $a1, 0x1d80
/* 0EF2F8 802CA948 00101880 */  sll   $v1, $s0, 2
/* 0EF2FC 802CA94C 00701821 */  addu  $v1, $v1, $s0
/* 0EF300 802CA950 00031880 */  sll   $v1, $v1, 2
/* 0EF304 802CA954 00701823 */  subu  $v1, $v1, $s0
/* 0EF308 802CA958 000320C0 */  sll   $a0, $v1, 3
/* 0EF30C 802CA95C 00641821 */  addu  $v1, $v1, $a0
/* 0EF310 802CA960 000318C0 */  sll   $v1, $v1, 3
/* 0EF314 802CA964 00651821 */  addu  $v1, $v1, $a1
/* 0EF318 802CA968 A4620004 */  sh    $v0, 4($v1)
/* 0EF31C 802CA96C A4600006 */  sh    $zero, 6($v1)
/* 0EF320 802CA970 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EF324 802CA974 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EF328 802CA978 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EF32C 802CA97C 24020002 */  addiu $v0, $zero, 2
/* 0EF330 802CA980 03E00008 */  jr    $ra
/* 0EF334 802CA984 27BD0020 */   addiu $sp, $sp, 0x20

/* 0EF338 802CA988 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0EF33C 802CA98C AFB20018 */  sw    $s2, 0x18($sp)
/* 0EF340 802CA990 0080902D */  daddu $s2, $a0, $zero
/* 0EF344 802CA994 AFBF0028 */  sw    $ra, 0x28($sp)
/* 0EF348 802CA998 AFB50024 */  sw    $s5, 0x24($sp)
/* 0EF34C 802CA99C AFB40020 */  sw    $s4, 0x20($sp)
/* 0EF350 802CA9A0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0EF354 802CA9A4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EF358 802CA9A8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EF35C 802CA9AC 8E50000C */  lw    $s0, 0xc($s2)
/* 0EF360 802CA9B0 8E050000 */  lw    $a1, ($s0)
/* 0EF364 802CA9B4 0C0B1EAF */  jal   get_variable
/* 0EF368 802CA9B8 26100004 */   addiu $s0, $s0, 4
/* 0EF36C 802CA9BC 8E140000 */  lw    $s4, ($s0)
/* 0EF370 802CA9C0 26100004 */  addiu $s0, $s0, 4
/* 0EF374 802CA9C4 8E150000 */  lw    $s5, ($s0)
/* 0EF378 802CA9C8 26100004 */  addiu $s0, $s0, 4
/* 0EF37C 802CA9CC 3C04800B */  lui   $a0, 0x800b
/* 0EF380 802CA9D0 24841D80 */  addiu $a0, $a0, 0x1d80
/* 0EF384 802CA9D4 00021880 */  sll   $v1, $v0, 2
/* 0EF388 802CA9D8 00621821 */  addu  $v1, $v1, $v0
/* 0EF38C 802CA9DC 00031880 */  sll   $v1, $v1, 2
/* 0EF390 802CA9E0 00621823 */  subu  $v1, $v1, $v0
/* 0EF394 802CA9E4 000310C0 */  sll   $v0, $v1, 3
/* 0EF398 802CA9E8 00621821 */  addu  $v1, $v1, $v0
/* 0EF39C 802CA9EC 000318C0 */  sll   $v1, $v1, 3
/* 0EF3A0 802CA9F0 00648821 */  addu  $s1, $v1, $a0
/* 0EF3A4 802CA9F4 C62C0094 */  lwc1  $f12, 0x94($s1)
/* 0EF3A8 802CA9F8 8E130000 */  lw    $s3, ($s0)
/* 0EF3AC 802CA9FC 8E100004 */  lw    $s0, 4($s0)
/* 0EF3B0 802CAA00 24020002 */  addiu $v0, $zero, 2
/* 0EF3B4 802CAA04 A6220004 */  sh    $v0, 4($s1)
/* 0EF3B8 802CAA08 0C00A6B1 */  jal   round
/* 0EF3BC 802CAA0C A6200006 */   sh    $zero, 6($s1)
/* 0EF3C0 802CAA10 C6220048 */  lwc1  $f2, 0x48($s1)
/* 0EF3C4 802CAA14 C620003C */  lwc1  $f0, 0x3c($s1)
/* 0EF3C8 802CAA18 46001081 */  sub.s $f2, $f2, $f0
/* 0EF3CC 802CAA1C 46021082 */  mul.s $f2, $f2, $f2
/* 0EF3D0 802CAA20 00000000 */  nop   
/* 0EF3D4 802CAA24 C624004C */  lwc1  $f4, 0x4c($s1)
/* 0EF3D8 802CAA28 C6200040 */  lwc1  $f0, 0x40($s1)
/* 0EF3DC 802CAA2C 46002101 */  sub.s $f4, $f4, $f0
/* 0EF3E0 802CAA30 46042102 */  mul.s $f4, $f4, $f4
/* 0EF3E4 802CAA34 00000000 */  nop   
/* 0EF3E8 802CAA38 C6260050 */  lwc1  $f6, 0x50($s1)
/* 0EF3EC 802CAA3C C6200044 */  lwc1  $f0, 0x44($s1)
/* 0EF3F0 802CAA40 46003181 */  sub.s $f6, $f6, $f0
/* 0EF3F4 802CAA44 46063182 */  mul.s $f6, $f6, $f6
/* 0EF3F8 802CAA48 00000000 */  nop   
/* 0EF3FC 802CAA4C C6200090 */  lwc1  $f0, 0x90($s1)
/* 0EF400 802CAA50 46041080 */  add.s $f2, $f2, $f4
/* 0EF404 802CAA54 00021023 */  negu  $v0, $v0
/* 0EF408 802CAA58 A622001C */  sh    $v0, 0x1c($s1)
/* 0EF40C 802CAA5C 46000007 */  neg.s $f0, $f0
/* 0EF410 802CAA60 46061300 */  add.s $f12, $f2, $f6
/* 0EF414 802CAA64 4600020D */  trunc.w.s $f8, $f0
/* 0EF418 802CAA68 44024000 */  mfc1  $v0, $f8
/* 0EF41C 802CAA6C 46006004 */  sqrt.s $f0, $f12
/* 0EF420 802CAA70 46000032 */  c.eq.s $f0, $f0
/* 0EF424 802CAA74 00000000 */  nop   
/* 0EF428 802CAA78 45010003 */  bc1t  .L802CAA88
/* 0EF42C 802CAA7C A622001E */   sh    $v0, 0x1e($s1)
/* 0EF430 802CAA80 0C0187BC */  jal   sqrtf
/* 0EF434 802CAA84 00000000 */   nop   
.L802CAA88:
/* 0EF438 802CAA88 0C00A6B1 */  jal   round
/* 0EF43C 802CAA8C 46000306 */   mov.s $f12, $f0
/* 0EF440 802CAA90 0240202D */  daddu $a0, $s2, $zero
/* 0EF444 802CAA94 8626001C */  lh    $a2, 0x1c($s1)
/* 0EF448 802CAA98 C6200048 */  lwc1  $f0, 0x48($s1)
/* 0EF44C 802CAA9C C622004C */  lwc1  $f2, 0x4c($s1)
/* 0EF450 802CAAA0 C6240050 */  lwc1  $f4, 0x50($s1)
/* 0EF454 802CAAA4 0280282D */  daddu $a1, $s4, $zero
/* 0EF458 802CAAA8 A6220020 */  sh    $v0, 0x20($s1)
/* 0EF45C 802CAAAC A6200022 */  sh    $zero, 0x22($s1)
/* 0EF460 802CAAB0 E6200054 */  swc1  $f0, 0x54($s1)
/* 0EF464 802CAAB4 E6220058 */  swc1  $f2, 0x58($s1)
/* 0EF468 802CAAB8 0C0B2026 */  jal   set_variable
/* 0EF46C 802CAABC E624005C */   swc1  $f4, 0x5c($s1)
/* 0EF470 802CAAC0 0240202D */  daddu $a0, $s2, $zero
/* 0EF474 802CAAC4 8626001E */  lh    $a2, 0x1e($s1)
/* 0EF478 802CAAC8 0C0B2026 */  jal   set_variable
/* 0EF47C 802CAACC 02A0282D */   daddu $a1, $s5, $zero
/* 0EF480 802CAAD0 0240202D */  daddu $a0, $s2, $zero
/* 0EF484 802CAAD4 86260020 */  lh    $a2, 0x20($s1)
/* 0EF488 802CAAD8 0C0B2026 */  jal   set_variable
/* 0EF48C 802CAADC 0260282D */   daddu $a1, $s3, $zero
/* 0EF490 802CAAE0 0240202D */  daddu $a0, $s2, $zero
/* 0EF494 802CAAE4 86260022 */  lh    $a2, 0x22($s1)
/* 0EF498 802CAAE8 0C0B2026 */  jal   set_variable
/* 0EF49C 802CAAEC 0200282D */   daddu $a1, $s0, $zero
/* 0EF4A0 802CAAF0 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0EF4A4 802CAAF4 8FB50024 */  lw    $s5, 0x24($sp)
/* 0EF4A8 802CAAF8 8FB40020 */  lw    $s4, 0x20($sp)
/* 0EF4AC 802CAAFC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0EF4B0 802CAB00 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EF4B4 802CAB04 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EF4B8 802CAB08 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EF4BC 802CAB0C 24020002 */  addiu $v0, $zero, 2
/* 0EF4C0 802CAB10 03E00008 */  jr    $ra
/* 0EF4C4 802CAB14 27BD0030 */   addiu $sp, $sp, 0x30

