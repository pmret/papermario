.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024095C_97BF8C
/* 97BF8C 8024095C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 97BF90 80240960 3C048024 */  lui       $a0, %hi(D_80242288)
/* 97BF94 80240964 24842288 */  addiu     $a0, $a0, %lo(D_80242288)
/* 97BF98 80240968 AFBF0018 */  sw        $ra, 0x18($sp)
/* 97BF9C 8024096C AFB10014 */  sw        $s1, 0x14($sp)
/* 97BFA0 80240970 AFB00010 */  sw        $s0, 0x10($sp)
/* 97BFA4 80240974 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 97BFA8 80240978 8C830000 */  lw        $v1, ($a0)
/* 97BFAC 8024097C 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 97BFB0 80240980 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 97BFB4 80240984 28620003 */  slti      $v0, $v1, 3
/* 97BFB8 80240988 50400007 */  beql      $v0, $zero, .L802409A8
/* 97BFBC 8024098C 24020003 */   addiu    $v0, $zero, 3
/* 97BFC0 80240990 1C60000C */  bgtz      $v1, .L802409C4
/* 97BFC4 80240994 24620001 */   addiu    $v0, $v1, 1
/* 97BFC8 80240998 10600007 */  beqz      $v1, .L802409B8
/* 97BFCC 8024099C 0000102D */   daddu    $v0, $zero, $zero
/* 97BFD0 802409A0 08090295 */  j         .L80240A54
/* 97BFD4 802409A4 00000000 */   nop      
.L802409A8:
/* 97BFD8 802409A8 10620008 */  beq       $v1, $v0, .L802409CC
/* 97BFDC 802409AC 0000102D */   daddu    $v0, $zero, $zero
/* 97BFE0 802409B0 08090295 */  j         .L80240A54
/* 97BFE4 802409B4 00000000 */   nop      
.L802409B8:
/* 97BFE8 802409B8 24020001 */  addiu     $v0, $zero, 1
/* 97BFEC 802409BC 08090294 */  j         .L80240A50
/* 97BFF0 802409C0 AC820000 */   sw       $v0, ($a0)
.L802409C4:
/* 97BFF4 802409C4 08090294 */  j         .L80240A50
/* 97BFF8 802409C8 AC820000 */   sw       $v0, ($a0)
.L802409CC:
/* 97BFFC 802409CC C6200028 */  lwc1      $f0, 0x28($s1)
/* 97C000 802409D0 3C0141F0 */  lui       $at, 0x41f0
/* 97C004 802409D4 44811000 */  mtc1      $at, $f2
/* 97C008 802409D8 3C108011 */  lui       $s0, %hi(D_8010C930)
/* 97C00C 802409DC 2610C930 */  addiu     $s0, $s0, %lo(D_8010C930)
/* 97C010 802409E0 46020001 */  sub.s     $f0, $f0, $f2
/* 97C014 802409E4 8E040000 */  lw        $a0, ($s0)
/* 97C018 802409E8 E4800038 */  swc1      $f0, 0x38($a0)
/* 97C01C 802409EC C6200030 */  lwc1      $f0, 0x30($s1)
/* 97C020 802409F0 46020000 */  add.s     $f0, $f0, $f2
/* 97C024 802409F4 0C03BD17 */  jal       clear_partner_move_history
/* 97C028 802409F8 E4800040 */   swc1     $f0, 0x40($a0)
/* 97C02C 802409FC C6200028 */  lwc1      $f0, 0x28($s1)
/* 97C030 80240A00 C6220030 */  lwc1      $f2, 0x30($s1)
/* 97C034 80240A04 4600010D */  trunc.w.s $f4, $f0
/* 97C038 80240A08 44042000 */  mfc1      $a0, $f4
/* 97C03C 80240A0C 4600110D */  trunc.w.s $f4, $f2
/* 97C040 80240A10 44052000 */  mfc1      $a1, $f4
/* 97C044 80240A14 0C03BCF0 */  jal       func_800EF3C0
/* 97C048 80240A18 00000000 */   nop      
/* 97C04C 80240A1C 0C03BCF5 */  jal       func_800EF3D4
/* 97C050 80240A20 0000202D */   daddu    $a0, $zero, $zero
/* 97C054 80240A24 3C0142B4 */  lui       $at, 0x42b4
/* 97C058 80240A28 4481A000 */  mtc1      $at, $f20
/* 97C05C 80240A2C 8E040000 */  lw        $a0, ($s0)
/* 97C060 80240A30 4405A000 */  mfc1      $a1, $f20
/* 97C064 80240A34 0C00ECD0 */  jal       set_npc_yaw
/* 97C068 80240A38 00000000 */   nop      
/* 97C06C 80240A3C 24020002 */  addiu     $v0, $zero, 2
/* 97C070 80240A40 E6340080 */  swc1      $f20, 0x80($s1)
/* 97C074 80240A44 E6340084 */  swc1      $f20, 0x84($s1)
/* 97C078 80240A48 08090295 */  j         .L80240A54
/* 97C07C 80240A4C AE2000A8 */   sw       $zero, 0xa8($s1)
.L80240A50:
/* 97C080 80240A50 0000102D */  daddu     $v0, $zero, $zero
.L80240A54:
/* 97C084 80240A54 8FBF0018 */  lw        $ra, 0x18($sp)
/* 97C088 80240A58 8FB10014 */  lw        $s1, 0x14($sp)
/* 97C08C 80240A5C 8FB00010 */  lw        $s0, 0x10($sp)
/* 97C090 80240A60 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 97C094 80240A64 03E00008 */  jr        $ra
/* 97C098 80240A68 27BD0028 */   addiu    $sp, $sp, 0x28
/* 97C09C 80240A6C 00000000 */  nop       
