.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EB2A4
/* 84754 800EB2A4 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 84758 800EB2A8 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 8475C 800EB2AC 1064000C */  beq       $v1, $a0, .L800EB2E0
/* 84760 800EB2B0 24020001 */   addiu    $v0, $zero, 1
/* 84764 800EB2B4 3C018011 */  lui       $at, %hi(D_8010CFE0)
/* 84768 800EB2B8 AC22CFE0 */  sw        $v0, %lo(D_8010CFE0)($at)
/* 8476C 800EB2BC 3C018011 */  lui       $at, %hi(D_8010CFE4)
/* 84770 800EB2C0 AC24CFE4 */  sw        $a0, %lo(D_8010CFE4)($at)
/* 84774 800EB2C4 10600008 */  beqz      $v1, .L800EB2E8
/* 84778 800EB2C8 00000000 */   nop
/* 8477C 800EB2CC 10800009 */  beqz      $a0, .L800EB2F4
/* 84780 800EB2D0 24020005 */   addiu    $v0, $zero, 5
/* 84784 800EB2D4 24020003 */  addiu     $v0, $zero, 3
/* 84788 800EB2D8 3C018011 */  lui       $at, %hi(D_8010CFE8)
/* 8478C 800EB2DC AC22CFE8 */  sw        $v0, %lo(D_8010CFE8)($at)
.L800EB2E0:
/* 84790 800EB2E0 03E00008 */  jr        $ra
/* 84794 800EB2E4 00000000 */   nop
.L800EB2E8:
/* 84798 800EB2E8 14800006 */  bnez      $a0, .L800EB304
/* 8479C 800EB2EC 24020007 */   addiu    $v0, $zero, 7
/* 847A0 800EB2F0 24020005 */  addiu     $v0, $zero, 5
.L800EB2F4:
/* 847A4 800EB2F4 3C018011 */  lui       $at, %hi(D_8010CFE8)
/* 847A8 800EB2F8 AC22CFE8 */  sw        $v0, %lo(D_8010CFE8)($at)
/* 847AC 800EB2FC 03E00008 */  jr        $ra
/* 847B0 800EB300 00000000 */   nop
.L800EB304:
/* 847B4 800EB304 3C018011 */  lui       $at, %hi(D_8010CFE8)
/* 847B8 800EB308 AC22CFE8 */  sw        $v0, %lo(D_8010CFE8)($at)
/* 847BC 800EB30C 03E00008 */  jr        $ra
/* 847C0 800EB310 00000000 */   nop
