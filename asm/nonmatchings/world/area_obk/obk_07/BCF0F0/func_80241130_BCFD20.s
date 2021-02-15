.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241130_BCFD20
/* BCFD20 80241130 0000302D */  daddu     $a2, $zero, $zero
/* BCFD24 80241134 3C058024 */  lui       $a1, %hi(D_80243090_BD1C80)
/* BCFD28 80241138 24A53090 */  addiu     $a1, $a1, %lo(D_80243090_BD1C80)
.L8024113C:
/* BCFD2C 8024113C 8CA30000 */  lw        $v1, ($a1)
/* BCFD30 80241140 50600006 */  beql      $v1, $zero, .L8024115C
/* BCFD34 80241144 2406FFFF */   addiu    $a2, $zero, -1
/* BCFD38 80241148 8C820084 */  lw        $v0, 0x84($a0)
/* BCFD3C 8024114C 10620003 */  beq       $v1, $v0, .L8024115C
/* BCFD40 80241150 24A50004 */   addiu    $a1, $a1, 4
/* BCFD44 80241154 0809044F */  j         .L8024113C
/* BCFD48 80241158 24C60001 */   addiu    $a2, $a2, 1
.L8024115C:
/* BCFD4C 8024115C AC860084 */  sw        $a2, 0x84($a0)
/* BCFD50 80241160 03E00008 */  jr        $ra
/* BCFD54 80241164 24020002 */   addiu    $v0, $zero, 2
