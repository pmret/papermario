.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetBattleFlagBits
/* 19B61C 8026CD3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19B620 8026CD40 AFBF0014 */  sw        $ra, 0x14($sp)
/* 19B624 8026CD44 AFB00010 */  sw        $s0, 0x10($sp)
/* 19B628 8026CD48 8C82000C */  lw        $v0, 0xc($a0)
/* 19B62C 8026CD4C 8C450004 */  lw        $a1, 4($v0)
/* 19B630 8026CD50 0C0B1EAF */  jal       get_variable
/* 19B634 8026CD54 8C500000 */   lw       $s0, ($v0)
/* 19B638 8026CD58 10400007 */  beqz      $v0, .L8026CD78
/* 19B63C 8026CD5C 00102027 */   nor      $a0, $zero, $s0
/* 19B640 8026CD60 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 19B644 8026CD64 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 19B648 8026CD68 8C620000 */  lw        $v0, ($v1)
/* 19B64C 8026CD6C 00501025 */  or        $v0, $v0, $s0
/* 19B650 8026CD70 0809B363 */  j         .L8026CD8C
/* 19B654 8026CD74 AC620000 */   sw       $v0, ($v1)
.L8026CD78:
/* 19B658 8026CD78 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 19B65C 8026CD7C 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 19B660 8026CD80 8C430000 */  lw        $v1, ($v0)
/* 19B664 8026CD84 00641824 */  and       $v1, $v1, $a0
/* 19B668 8026CD88 AC430000 */  sw        $v1, ($v0)
.L8026CD8C:
/* 19B66C 8026CD8C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 19B670 8026CD90 8FB00010 */  lw        $s0, 0x10($sp)
/* 19B674 8026CD94 24020002 */  addiu     $v0, $zero, 2
/* 19B678 8026CD98 03E00008 */  jr        $ra
/* 19B67C 8026CD9C 27BD0018 */   addiu    $sp, $sp, 0x18
