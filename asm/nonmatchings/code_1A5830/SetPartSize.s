.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPartSize
/* 1AC250 8027D970 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1AC254 8027D974 AFB20018 */  sw        $s2, 0x18($sp)
/* 1AC258 8027D978 0080902D */  daddu     $s2, $a0, $zero
/* 1AC25C 8027D97C AFBF0024 */  sw        $ra, 0x24($sp)
/* 1AC260 8027D980 AFB40020 */  sw        $s4, 0x20($sp)
/* 1AC264 8027D984 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1AC268 8027D988 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AC26C 8027D98C AFB00010 */  sw        $s0, 0x10($sp)
/* 1AC270 8027D990 8E50000C */  lw        $s0, 0xc($s2)
/* 1AC274 8027D994 8E050000 */  lw        $a1, ($s0)
/* 1AC278 8027D998 0C0B1EAF */  jal       get_variable
/* 1AC27C 8027D99C 26100004 */   addiu    $s0, $s0, 4
/* 1AC280 8027D9A0 0040882D */  daddu     $s1, $v0, $zero
/* 1AC284 8027D9A4 8E050000 */  lw        $a1, ($s0)
/* 1AC288 8027D9A8 26100004 */  addiu     $s0, $s0, 4
/* 1AC28C 8027D9AC 0C0B1EAF */  jal       get_variable
/* 1AC290 8027D9B0 0240202D */   daddu    $a0, $s2, $zero
/* 1AC294 8027D9B4 8E050000 */  lw        $a1, ($s0)
/* 1AC298 8027D9B8 26100004 */  addiu     $s0, $s0, 4
/* 1AC29C 8027D9BC 0240202D */  daddu     $a0, $s2, $zero
/* 1AC2A0 8027D9C0 0C0B1EAF */  jal       get_variable
/* 1AC2A4 8027D9C4 0040A02D */   daddu    $s4, $v0, $zero
/* 1AC2A8 8027D9C8 0240202D */  daddu     $a0, $s2, $zero
/* 1AC2AC 8027D9CC 8E050000 */  lw        $a1, ($s0)
/* 1AC2B0 8027D9D0 0C0B1EAF */  jal       get_variable
/* 1AC2B4 8027D9D4 0040802D */   daddu    $s0, $v0, $zero
/* 1AC2B8 8027D9D8 0040982D */  daddu     $s3, $v0, $zero
/* 1AC2BC 8027D9DC 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AC2C0 8027D9E0 16220002 */  bne       $s1, $v0, .L8027D9EC
/* 1AC2C4 8027D9E4 00000000 */   nop      
/* 1AC2C8 8027D9E8 8E510148 */  lw        $s1, 0x148($s2)
.L8027D9EC:
/* 1AC2CC 8027D9EC 0C09A75B */  jal       get_actor
/* 1AC2D0 8027D9F0 0220202D */   daddu    $a0, $s1, $zero
/* 1AC2D4 8027D9F4 0040202D */  daddu     $a0, $v0, $zero
/* 1AC2D8 8027D9F8 0C099117 */  jal       get_actor_part
/* 1AC2DC 8027D9FC 0280282D */   daddu    $a1, $s4, $zero
/* 1AC2E0 8027DA00 3C03F119 */  lui       $v1, 0xf119
/* 1AC2E4 8027DA04 34634D80 */  ori       $v1, $v1, 0x4d80
/* 1AC2E8 8027DA08 12030002 */  beq       $s0, $v1, .L8027DA14
/* 1AC2EC 8027DA0C 0040202D */   daddu    $a0, $v0, $zero
/* 1AC2F0 8027DA10 A0900073 */  sb        $s0, 0x73($a0)
.L8027DA14:
/* 1AC2F4 8027DA14 56630001 */  bnel      $s3, $v1, .L8027DA1C
/* 1AC2F8 8027DA18 A0930072 */   sb       $s3, 0x72($a0)
.L8027DA1C:
/* 1AC2FC 8027DA1C 90830072 */  lbu       $v1, 0x72($a0)
/* 1AC300 8027DA20 3C014038 */  lui       $at, 0x4038
/* 1AC304 8027DA24 44811800 */  mtc1      $at, $f3
/* 1AC308 8027DA28 44801000 */  mtc1      $zero, $f2
/* 1AC30C 8027DA2C 44830000 */  mtc1      $v1, $f0
/* 1AC310 8027DA30 00000000 */  nop       
/* 1AC314 8027DA34 46800021 */  cvt.d.w   $f0, $f0
/* 1AC318 8027DA38 46220003 */  div.d     $f0, $f0, $f2
/* 1AC31C 8027DA3C 46200020 */  cvt.s.d   $f0, $f0
/* 1AC320 8027DA40 E48000A0 */  swc1      $f0, 0xa0($a0)
/* 1AC324 8027DA44 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1AC328 8027DA48 8FB40020 */  lw        $s4, 0x20($sp)
/* 1AC32C 8027DA4C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1AC330 8027DA50 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AC334 8027DA54 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AC338 8027DA58 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AC33C 8027DA5C 24020002 */  addiu     $v0, $zero, 2
/* 1AC340 8027DA60 03E00008 */  jr        $ra
/* 1AC344 8027DA64 27BD0028 */   addiu    $sp, $sp, 0x28
