.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B4C_84371C
/* 84371C 80240B4C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 843720 80240B50 AFB00010 */  sw        $s0, 0x10($sp)
/* 843724 80240B54 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 843728 80240B58 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 84372C 80240B5C AFBF0018 */  sw        $ra, 0x18($sp)
/* 843730 80240B60 AFB10014 */  sw        $s1, 0x14($sp)
/* 843734 80240B64 960302C0 */  lhu       $v1, 0x2c0($s0)
/* 843738 80240B68 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* 84373C 80240B6C 10400003 */  beqz      $v0, .L80240B7C
/* 843740 80240B70 0080882D */   daddu    $s1, $a0, $zero
/* 843744 80240B74 24620001 */  addiu     $v0, $v1, 1
/* 843748 80240B78 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80240B7C:
/* 84374C 80240B7C 3C05F5DE */  lui       $a1, 0xf5de
/* 843750 80240B80 34A502E0 */  ori       $a1, $a1, 0x2e0
/* 843754 80240B84 0C0B1EAF */  jal       get_variable
/* 843758 80240B88 0000202D */   daddu    $a0, $zero, $zero
/* 84375C 80240B8C 3C038024 */  lui       $v1, %hi(D_8024404C_846C1C)
/* 843760 80240B90 00621821 */  addu      $v1, $v1, $v0
/* 843764 80240B94 9063404C */  lbu       $v1, %lo(D_8024404C_846C1C)($v1)
/* 843768 80240B98 8E220084 */  lw        $v0, 0x84($s1)
/* 84376C 80240B9C 54430006 */  bnel      $v0, $v1, .L80240BB8
/* 843770 80240BA0 AE200084 */   sw       $zero, 0x84($s1)
/* 843774 80240BA4 24020001 */  addiu     $v0, $zero, 1
/* 843778 80240BA8 AE220084 */  sw        $v0, 0x84($s1)
/* 84377C 80240BAC 960202C2 */  lhu       $v0, 0x2c2($s0)
/* 843780 80240BB0 24420001 */  addiu     $v0, $v0, 1
/* 843784 80240BB4 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80240BB8:
/* 843788 80240BB8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 84378C 80240BBC 8FB10014 */  lw        $s1, 0x14($sp)
/* 843790 80240BC0 8FB00010 */  lw        $s0, 0x10($sp)
/* 843794 80240BC4 24020002 */  addiu     $v0, $zero, 2
/* 843798 80240BC8 03E00008 */  jr        $ra
/* 84379C 80240BCC 27BD0020 */   addiu    $sp, $sp, 0x20
