.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A7C_8B0AEC
/* 8B0AEC 80240A7C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B0AF0 80240A80 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B0AF4 80240A84 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 8B0AF8 80240A88 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 8B0AFC 80240A8C AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B0B00 80240A90 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B0B04 80240A94 960302C0 */  lhu       $v1, 0x2c0($s0)
/* 8B0B08 80240A98 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* 8B0B0C 80240A9C 10400003 */  beqz      $v0, .L80240AAC
/* 8B0B10 80240AA0 0080882D */   daddu    $s1, $a0, $zero
/* 8B0B14 80240AA4 24620001 */  addiu     $v0, $v1, 1
/* 8B0B18 80240AA8 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80240AAC:
/* 8B0B1C 80240AAC 3C05F5DE */  lui       $a1, 0xf5de
/* 8B0B20 80240AB0 34A502E0 */  ori       $a1, $a1, 0x2e0
/* 8B0B24 80240AB4 0C0B1EAF */  jal       get_variable
/* 8B0B28 80240AB8 0000202D */   daddu    $a0, $zero, $zero
/* 8B0B2C 80240ABC 3C038024 */  lui       $v1, %hi(D_80245634)
/* 8B0B30 80240AC0 00621821 */  addu      $v1, $v1, $v0
/* 8B0B34 80240AC4 90635634 */  lbu       $v1, %lo(D_80245634)($v1)
/* 8B0B38 80240AC8 8E220084 */  lw        $v0, 0x84($s1)
/* 8B0B3C 80240ACC 54430006 */  bnel      $v0, $v1, .L80240AE8
/* 8B0B40 80240AD0 AE200084 */   sw       $zero, 0x84($s1)
/* 8B0B44 80240AD4 24020001 */  addiu     $v0, $zero, 1
/* 8B0B48 80240AD8 AE220084 */  sw        $v0, 0x84($s1)
/* 8B0B4C 80240ADC 960202C2 */  lhu       $v0, 0x2c2($s0)
/* 8B0B50 80240AE0 24420001 */  addiu     $v0, $v0, 1
/* 8B0B54 80240AE4 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80240AE8:
/* 8B0B58 80240AE8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B0B5C 80240AEC 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B0B60 80240AF0 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B0B64 80240AF4 24020002 */  addiu     $v0, $zero, 2
/* 8B0B68 80240AF8 03E00008 */  jr        $ra
/* 8B0B6C 80240AFC 27BD0020 */   addiu    $sp, $sp, 0x20
