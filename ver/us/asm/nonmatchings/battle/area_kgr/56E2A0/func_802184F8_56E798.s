.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802184F8_56E798
/* 56E798 802184F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 56E79C 802184FC 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 56E7A0 80218500 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 56E7A4 80218504 2406FFFF */  addiu     $a2, $zero, -1
/* 56E7A8 80218508 AFBF0010 */  sw        $ra, 0x10($sp)
/* 56E7AC 8021850C 806200AE */  lb        $v0, 0xae($v1)
/* 56E7B0 80218510 10460007 */  beq       $v0, $a2, .L80218530
/* 56E7B4 80218514 8C85000C */   lw       $a1, 0xc($a0)
/* 56E7B8 80218518 806200AF */  lb        $v0, 0xaf($v1)
/* 56E7BC 8021851C 10460004 */  beq       $v0, $a2, .L80218530
/* 56E7C0 80218520 00000000 */   nop
/* 56E7C4 80218524 806200B0 */  lb        $v0, 0xb0($v1)
/* 56E7C8 80218528 14460004 */  bne       $v0, $a2, .L8021853C
/* 56E7CC 8021852C 00000000 */   nop
.L80218530:
/* 56E7D0 80218530 8CA50000 */  lw        $a1, ($a1)
/* 56E7D4 80218534 08086150 */  j         .L80218540
/* 56E7D8 80218538 0000302D */   daddu    $a2, $zero, $zero
.L8021853C:
/* 56E7DC 8021853C 8CA50000 */  lw        $a1, ($a1)
.L80218540:
/* 56E7E0 80218540 0C0B2026 */  jal       set_variable
/* 56E7E4 80218544 00000000 */   nop
/* 56E7E8 80218548 8FBF0010 */  lw        $ra, 0x10($sp)
/* 56E7EC 8021854C 24020002 */  addiu     $v0, $zero, 2
/* 56E7F0 80218550 03E00008 */  jr        $ra
/* 56E7F4 80218554 27BD0018 */   addiu    $sp, $sp, 0x18
/* 56E7F8 80218558 00000000 */  nop
/* 56E7FC 8021855C 00000000 */  nop
