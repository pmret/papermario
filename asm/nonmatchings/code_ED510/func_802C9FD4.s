.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C9FD4
/* EE984 802C9FD4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE988 802C9FD8 AFB00010 */  sw        $s0, 0x10($sp)
/* EE98C 802C9FDC 0080802D */  daddu     $s0, $a0, $zero
/* EE990 802C9FE0 AFB10014 */  sw        $s1, 0x14($sp)
/* EE994 802C9FE4 00A0882D */  daddu     $s1, $a1, $zero
/* EE998 802C9FE8 AFB20018 */  sw        $s2, 0x18($sp)
/* EE99C 802C9FEC 3C04802E */  lui       $a0, 0x802e
/* EE9A0 802C9FF0 2484ADA4 */  addiu     $a0, $a0, -0x525c
/* EE9A4 802C9FF4 2402FFFF */  addiu     $v0, $zero, -1
/* EE9A8 802C9FF8 AFBF001C */  sw        $ra, 0x1c($sp)
/* EE9AC 802C9FFC 8C830000 */  lw        $v1, ($a0)
/* EE9B0 802CA000 3C05802E */  lui       $a1, 0x802e
/* EE9B4 802CA004 8CA5ADA0 */  lw        $a1, -0x5260($a1)
/* EE9B8 802CA008 14620018 */  bne       $v1, $v0, .L802CA06C
/* EE9BC 802CA00C 00C0902D */   daddu    $s2, $a2, $zero
/* EE9C0 802CA010 0C016AFA */  jal       get_current_map_header
/* EE9C4 802CA014 00000000 */   nop      
/* EE9C8 802CA018 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* EE9CC 802CA01C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* EE9D0 802CA020 8463008E */  lh        $v1, 0x8e($v1)
/* EE9D4 802CA024 8C420014 */  lw        $v0, 0x14($v0)
/* EE9D8 802CA028 00031900 */  sll       $v1, $v1, 4
/* EE9DC 802CA02C 00431021 */  addu      $v0, $v0, $v1
/* EE9E0 802CA030 C4400000 */  lwc1      $f0, ($v0)
/* EE9E4 802CA034 E6000000 */  swc1      $f0, ($s0)
/* EE9E8 802CA038 C4400004 */  lwc1      $f0, 4($v0)
/* EE9EC 802CA03C E6200000 */  swc1      $f0, ($s1)
/* EE9F0 802CA040 C4400008 */  lwc1      $f0, 8($v0)
/* EE9F4 802CA044 2402FFFF */  addiu     $v0, $zero, -1
/* EE9F8 802CA048 080B2825 */  j         .L802CA094
/* EE9FC 802CA04C E6400000 */   swc1     $f0, ($s2)
.L802CA050:
/* EEA00 802CA050 C4A00004 */  lwc1      $f0, 4($a1)
/* EEA04 802CA054 E6000000 */  swc1      $f0, ($s0)
/* EEA08 802CA058 C4A00008 */  lwc1      $f0, 8($a1)
/* EEA0C 802CA05C E6200000 */  swc1      $f0, ($s1)
/* EEA10 802CA060 C4A0000C */  lwc1      $f0, 0xc($a1)
/* EEA14 802CA064 080B2825 */  j         .L802CA094
/* EEA18 802CA068 E6400000 */   swc1     $f0, ($s2)
.L802CA06C:
/* EEA1C 802CA06C 2406FFFF */  addiu     $a2, $zero, -1
/* EEA20 802CA070 0080182D */  daddu     $v1, $a0, $zero
.L802CA074:
/* EEA24 802CA074 8CA40000 */  lw        $a0, ($a1)
/* EEA28 802CA078 10860006 */  beq       $a0, $a2, .L802CA094
/* EEA2C 802CA07C 0000102D */   daddu    $v0, $zero, $zero
/* EEA30 802CA080 8C620000 */  lw        $v0, ($v1)
/* EEA34 802CA084 1082FFF2 */  beq       $a0, $v0, .L802CA050
/* EEA38 802CA088 24020001 */   addiu    $v0, $zero, 1
/* EEA3C 802CA08C 080B281D */  j         .L802CA074
/* EEA40 802CA090 24A50010 */   addiu    $a1, $a1, 0x10
.L802CA094:
/* EEA44 802CA094 8FBF001C */  lw        $ra, 0x1c($sp)
/* EEA48 802CA098 8FB20018 */  lw        $s2, 0x18($sp)
/* EEA4C 802CA09C 8FB10014 */  lw        $s1, 0x14($sp)
/* EEA50 802CA0A0 8FB00010 */  lw        $s0, 0x10($sp)
/* EEA54 802CA0A4 03E00008 */  jr        $ra
/* EEA58 802CA0A8 27BD0020 */   addiu    $sp, $sp, 0x20
