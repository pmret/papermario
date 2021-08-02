.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003AA6C
/* 15E6C 8003AA6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 15E70 8003AA70 AFB00010 */  sw        $s0, 0x10($sp)
/* 15E74 8003AA74 0080802D */  daddu     $s0, $a0, $zero
/* 15E78 8003AA78 AFBF0014 */  sw        $ra, 0x14($sp)
/* 15E7C 8003AA7C 8E030000 */  lw        $v1, ($s0)
/* 15E80 8003AA80 3C020010 */  lui       $v0, 0x10
/* 15E84 8003AA84 00621024 */  and       $v0, $v1, $v0
/* 15E88 8003AA88 10400007 */  beqz      $v0, .L8003AAA8
/* 15E8C 8003AA8C 3C02FFEF */   lui      $v0, 0xffef
/* 15E90 8003AA90 3442FFFF */  ori       $v0, $v0, 0xffff
/* 15E94 8003AA94 8E040020 */  lw        $a0, 0x20($s0)
/* 15E98 8003AA98 00621024 */  and       $v0, $v1, $v0
/* 15E9C 8003AA9C 0C00AB3B */  jal       dead_rand_int
/* 15EA0 8003AAA0 AE020000 */   sw       $v0, ($s0)
/* 15EA4 8003AAA4 AE000020 */  sw        $zero, 0x20($s0)
.L8003AAA8:
/* 15EA8 8003AAA8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 15EAC 8003AAAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 15EB0 8003AAB0 03E00008 */  jr        $ra
/* 15EB4 8003AAB4 27BD0018 */   addiu    $sp, $sp, 0x18
