.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FFC_9D901C
/* 9D901C 80241FFC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9D9020 80242000 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D9024 80242004 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 9D9028 80242008 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 9D902C 8024200C AFBF0018 */  sw        $ra, 0x18($sp)
/* 9D9030 80242010 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D9034 80242014 960302C0 */  lhu       $v1, 0x2c0($s0)
/* 9D9038 80242018 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* 9D903C 8024201C 10400003 */  beqz      $v0, .L8024202C
/* 9D9040 80242020 0080882D */   daddu    $s1, $a0, $zero
/* 9D9044 80242024 24620001 */  addiu     $v0, $v1, 1
/* 9D9048 80242028 A60202C0 */  sh        $v0, 0x2c0($s0)
.L8024202C:
/* 9D904C 8024202C 3C05F5DE */  lui       $a1, 0xf5de
/* 9D9050 80242030 34A502E0 */  ori       $a1, $a1, 0x2e0
/* 9D9054 80242034 0C0B1EAF */  jal       get_variable
/* 9D9058 80242038 0000202D */   daddu    $a0, $zero, $zero
/* 9D905C 8024203C 3C038024 */  lui       $v1, %hi(D_8024712C_9DE14C)
/* 9D9060 80242040 00621821 */  addu      $v1, $v1, $v0
/* 9D9064 80242044 9063712C */  lbu       $v1, %lo(D_8024712C_9DE14C)($v1)
/* 9D9068 80242048 8E220084 */  lw        $v0, 0x84($s1)
/* 9D906C 8024204C 54430006 */  bnel      $v0, $v1, .L80242068
/* 9D9070 80242050 AE200084 */   sw       $zero, 0x84($s1)
/* 9D9074 80242054 24020001 */  addiu     $v0, $zero, 1
/* 9D9078 80242058 AE220084 */  sw        $v0, 0x84($s1)
/* 9D907C 8024205C 960202C2 */  lhu       $v0, 0x2c2($s0)
/* 9D9080 80242060 24420001 */  addiu     $v0, $v0, 1
/* 9D9084 80242064 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80242068:
/* 9D9088 80242068 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9D908C 8024206C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D9090 80242070 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D9094 80242074 24020002 */  addiu     $v0, $zero, 2
/* 9D9098 80242078 03E00008 */  jr        $ra
/* 9D909C 8024207C 27BD0020 */   addiu    $sp, $sp, 0x20
