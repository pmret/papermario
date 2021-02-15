.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243100_A2D340
/* A2D340 80243100 3C078025 */  lui       $a3, %hi(D_8024AA20_A34C60)
/* A2D344 80243104 8CE7AA20 */  lw        $a3, %lo(D_8024AA20_A34C60)($a3)
/* A2D348 80243108 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A2D34C 8024310C AFBF0020 */  sw        $ra, 0x20($sp)
/* A2D350 80243110 94E20044 */  lhu       $v0, 0x44($a3)
/* A2D354 80243114 00022400 */  sll       $a0, $v0, 0x10
/* A2D358 80243118 94E20046 */  lhu       $v0, 0x46($a3)
/* A2D35C 8024311C 8CE30000 */  lw        $v1, ($a3)
/* A2D360 80243120 1060000D */  beqz      $v1, .L80243158
/* A2D364 80243124 00022C00 */   sll      $a1, $v0, 0x10
/* A2D368 80243128 240200FF */  addiu     $v0, $zero, 0xff
/* A2D36C 8024312C AFA20010 */  sw        $v0, 0x10($sp)
/* A2D370 80243130 24020080 */  addiu     $v0, $zero, 0x80
/* A2D374 80243134 AFA20014 */  sw        $v0, 0x14($sp)
/* A2D378 80243138 AFA20018 */  sw        $v0, 0x18($sp)
/* A2D37C 8024313C 24020010 */  addiu     $v0, $zero, 0x10
/* A2D380 80243140 00442007 */  srav      $a0, $a0, $v0
/* A2D384 80243144 AFA2001C */  sw        $v0, 0x1c($sp)
/* A2D388 80243148 8CE6001C */  lw        $a2, 0x1c($a3)
/* A2D38C 8024314C 8CE70020 */  lw        $a3, 0x20($a3)
/* A2D390 80243150 0C090C59 */  jal       func_80243164_A2D3A4
/* A2D394 80243154 00452807 */   srav     $a1, $a1, $v0
.L80243158:
/* A2D398 80243158 8FBF0020 */  lw        $ra, 0x20($sp)
/* A2D39C 8024315C 03E00008 */  jr        $ra
/* A2D3A0 80243160 27BD0028 */   addiu    $sp, $sp, 0x28
