.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802CA1B8
/* 0EEB68 802CA1B8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EEB6C 802CA1BC 000410C0 */  sll   $v0, $a0, 3
/* 0EEB70 802CA1C0 00441023 */  subu  $v0, $v0, $a0
/* 0EEB74 802CA1C4 3C03800E */  lui   $v1, 0x800e
/* 0EEB78 802CA1C8 8C6391D4 */  lw    $v1, -0x6e2c($v1)
/* 0EEB7C 802CA1CC 00021080 */  sll   $v0, $v0, 2
/* 0EEB80 802CA1D0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EEB84 802CA1D4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EEB88 802CA1D8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EEB8C 802CA1DC 00628021 */  addu  $s0, $v1, $v0
/* 0EEB90 802CA1E0 86040004 */  lh    $a0, 4($s0)
/* 0EEB94 802CA1E4 04800003 */  bltz  $a0, .L802CA1F4
/* 0EEB98 802CA1E8 00A0882D */   daddu $s1, $a1, $zero
/* 0EEB9C 802CA1EC 0C0B286E */  jal   func_802CA1B8
/* 0EEBA0 802CA1F0 00000000 */   nop   
.L802CA1F4:
/* 0EEBA4 802CA1F4 86040006 */  lh    $a0, 6($s0)
/* 0EEBA8 802CA1F8 04800003 */  bltz  $a0, .L802CA208
/* 0EEBAC 802CA1FC 00000000 */   nop   
/* 0EEBB0 802CA200 0C0B286E */  jal   func_802CA1B8
/* 0EEBB4 802CA204 0220282D */   daddu $a1, $s1, $zero
.L802CA208:
/* 0EEBB8 802CA208 12200006 */  beqz  $s1, .L802CA224
/* 0EEBBC 802CA20C 3C030001 */   lui   $v1, 1
/* 0EEBC0 802CA210 24020001 */  addiu $v0, $zero, 1
/* 0EEBC4 802CA214 12220006 */  beq   $s1, $v0, .L802CA230
/* 0EEBC8 802CA218 3C03FFFE */   lui   $v1, 0xfffe
/* 0EEBCC 802CA21C 080B2890 */  j     .L802CA240
/* 0EEBD0 802CA220 00000000 */   nop   

.L802CA224:
/* 0EEBD4 802CA224 8E020000 */  lw    $v0, ($s0)
/* 0EEBD8 802CA228 080B288F */  j     .L802CA23C
/* 0EEBDC 802CA22C 00431025 */   or    $v0, $v0, $v1

.L802CA230:
/* 0EEBE0 802CA230 8E020000 */  lw    $v0, ($s0)
/* 0EEBE4 802CA234 3463FFFF */  ori   $v1, $v1, 0xffff
/* 0EEBE8 802CA238 00431024 */  and   $v0, $v0, $v1
.L802CA23C:
/* 0EEBEC 802CA23C AE020000 */  sw    $v0, ($s0)
.L802CA240:
/* 0EEBF0 802CA240 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EEBF4 802CA244 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EEBF8 802CA248 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EEBFC 802CA24C 03E00008 */  jr    $ra
/* 0EEC00 802CA250 27BD0020 */   addiu $sp, $sp, 0x20

/* 0EEC04 802CA254 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EEC08 802CA258 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EEC0C 802CA25C 0080882D */  daddu $s1, $a0, $zero
/* 0EEC10 802CA260 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EEC14 802CA264 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EEC18 802CA268 8E30000C */  lw    $s0, 0xc($s1)
/* 0EEC1C 802CA26C 8E050000 */  lw    $a1, ($s0)
/* 0EEC20 802CA270 0C0B1EAF */  jal   get_variable
/* 0EEC24 802CA274 26100004 */   addiu $s0, $s0, 4
/* 0EEC28 802CA278 0220202D */  daddu $a0, $s1, $zero
/* 0EEC2C 802CA27C 8E050000 */  lw    $a1, ($s0)
/* 0EEC30 802CA280 0C0B1EAF */  jal   get_variable
/* 0EEC34 802CA284 0040802D */   daddu $s0, $v0, $zero
/* 0EEC38 802CA288 001018C0 */  sll   $v1, $s0, 3
/* 0EEC3C 802CA28C 00701823 */  subu  $v1, $v1, $s0
/* 0EEC40 802CA290 3C04800E */  lui   $a0, 0x800e
/* 0EEC44 802CA294 8C8491D4 */  lw    $a0, -0x6e2c($a0)
/* 0EEC48 802CA298 00031880 */  sll   $v1, $v1, 2
/* 0EEC4C 802CA29C 00838821 */  addu  $s1, $a0, $v1
/* 0EEC50 802CA2A0 86240006 */  lh    $a0, 6($s1)
/* 0EEC54 802CA2A4 04800003 */  bltz  $a0, .L802CA2B4
/* 0EEC58 802CA2A8 0040802D */   daddu $s0, $v0, $zero
/* 0EEC5C 802CA2AC 0C0B286E */  jal   func_802CA1B8
/* 0EEC60 802CA2B0 0200282D */   daddu $a1, $s0, $zero
.L802CA2B4:
/* 0EEC64 802CA2B4 12000006 */  beqz  $s0, .L802CA2D0
/* 0EEC68 802CA2B8 3C030001 */   lui   $v1, 1
/* 0EEC6C 802CA2BC 24020001 */  addiu $v0, $zero, 1
/* 0EEC70 802CA2C0 12020006 */  beq   $s0, $v0, .L802CA2DC
/* 0EEC74 802CA2C4 3C03FFFE */   lui   $v1, 0xfffe
/* 0EEC78 802CA2C8 080B28BB */  j     .L802CA2EC
/* 0EEC7C 802CA2CC 00000000 */   nop   

.L802CA2D0:
/* 0EEC80 802CA2D0 8E220000 */  lw    $v0, ($s1)
/* 0EEC84 802CA2D4 080B28BA */  j     .L802CA2E8
/* 0EEC88 802CA2D8 00431025 */   or    $v0, $v0, $v1

.L802CA2DC:
/* 0EEC8C 802CA2DC 8E220000 */  lw    $v0, ($s1)
/* 0EEC90 802CA2E0 3463FFFF */  ori   $v1, $v1, 0xffff
/* 0EEC94 802CA2E4 00431024 */  and   $v0, $v0, $v1
.L802CA2E8:
/* 0EEC98 802CA2E8 AE220000 */  sw    $v0, ($s1)
.L802CA2EC:
/* 0EEC9C 802CA2EC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EECA0 802CA2F0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EECA4 802CA2F4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EECA8 802CA2F8 24020002 */  addiu $v0, $zero, 2
/* 0EECAC 802CA2FC 03E00008 */  jr    $ra
/* 0EECB0 802CA300 27BD0020 */   addiu $sp, $sp, 0x20

