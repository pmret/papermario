.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409E0_86F4E0
/* 86F4E0 802409E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 86F4E4 802409E4 3C048024 */  lui       $a0, %hi(D_80242EBC_8719BC)
/* 86F4E8 802409E8 24842EBC */  addiu     $a0, $a0, %lo(D_80242EBC_8719BC)
/* 86F4EC 802409EC AFBF0018 */  sw        $ra, 0x18($sp)
/* 86F4F0 802409F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 86F4F4 802409F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 86F4F8 802409F8 8C830000 */  lw        $v1, ($a0)
/* 86F4FC 802409FC 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 86F500 80240A00 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 86F504 80240A04 28620003 */  slti      $v0, $v1, 3
/* 86F508 80240A08 50400007 */  beql      $v0, $zero, .L80240A28
/* 86F50C 80240A0C 24020003 */   addiu    $v0, $zero, 3
/* 86F510 80240A10 1C60000C */  bgtz      $v1, .L80240A44
/* 86F514 80240A14 24620001 */   addiu    $v0, $v1, 1
/* 86F518 80240A18 10600007 */  beqz      $v1, .L80240A38
/* 86F51C 80240A1C 0000102D */   daddu    $v0, $zero, $zero
/* 86F520 80240A20 080902AD */  j         .L80240AB4
/* 86F524 80240A24 00000000 */   nop
.L80240A28:
/* 86F528 80240A28 10620008 */  beq       $v1, $v0, .L80240A4C
/* 86F52C 80240A2C 0000102D */   daddu    $v0, $zero, $zero
/* 86F530 80240A30 080902AD */  j         .L80240AB4
/* 86F534 80240A34 00000000 */   nop
.L80240A38:
/* 86F538 80240A38 24020001 */  addiu     $v0, $zero, 1
/* 86F53C 80240A3C 080902AC */  j         .L80240AB0
/* 86F540 80240A40 AC820000 */   sw       $v0, ($a0)
.L80240A44:
/* 86F544 80240A44 080902AC */  j         .L80240AB0
/* 86F548 80240A48 AC820000 */   sw       $v0, ($a0)
.L80240A4C:
/* 86F54C 80240A4C 3C108011 */  lui       $s0, %hi(wPartnerNpc)
/* 86F550 80240A50 2610C930 */  addiu     $s0, $s0, %lo(wPartnerNpc)
/* 86F554 80240A54 0C03BD17 */  jal       clear_partner_move_history
/* 86F558 80240A58 8E040000 */   lw       $a0, ($s0)
/* 86F55C 80240A5C C6200028 */  lwc1      $f0, 0x28($s1)
/* 86F560 80240A60 C6220030 */  lwc1      $f2, 0x30($s1)
/* 86F564 80240A64 4600010D */  trunc.w.s $f4, $f0
/* 86F568 80240A68 44042000 */  mfc1      $a0, $f4
/* 86F56C 80240A6C 4600110D */  trunc.w.s $f4, $f2
/* 86F570 80240A70 44052000 */  mfc1      $a1, $f4
/* 86F574 80240A74 0C03BCF0 */  jal       func_800EF3C0
/* 86F578 80240A78 00000000 */   nop
/* 86F57C 80240A7C 0C03BCF5 */  jal       func_800EF3D4
/* 86F580 80240A80 0000202D */   daddu    $a0, $zero, $zero
/* 86F584 80240A84 8E030000 */  lw        $v1, ($s0)
/* 86F588 80240A88 3C014387 */  lui       $at, 0x4387
/* 86F58C 80240A8C 44810000 */  mtc1      $at, $f0
/* 86F590 80240A90 3C014334 */  lui       $at, 0x4334
/* 86F594 80240A94 44811000 */  mtc1      $at, $f2
/* 86F598 80240A98 24020002 */  addiu     $v0, $zero, 2
/* 86F59C 80240A9C E460000C */  swc1      $f0, 0xc($v1)
/* 86F5A0 80240AA0 E6200080 */  swc1      $f0, 0x80($s1)
/* 86F5A4 80240AA4 E6200084 */  swc1      $f0, 0x84($s1)
/* 86F5A8 80240AA8 080902AD */  j         .L80240AB4
/* 86F5AC 80240AAC E62200A8 */   swc1     $f2, 0xa8($s1)
.L80240AB0:
/* 86F5B0 80240AB0 0000102D */  daddu     $v0, $zero, $zero
.L80240AB4:
/* 86F5B4 80240AB4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 86F5B8 80240AB8 8FB10014 */  lw        $s1, 0x14($sp)
/* 86F5BC 80240ABC 8FB00010 */  lw        $s0, 0x10($sp)
/* 86F5C0 80240AC0 03E00008 */  jr        $ra
/* 86F5C4 80240AC4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 86F5C8 80240AC8 00000000 */  nop
/* 86F5CC 80240ACC 00000000 */  nop
