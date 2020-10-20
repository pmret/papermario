.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240ADC
/* B2101C 80240ADC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B21020 80240AE0 AFB00010 */  sw        $s0, 0x10($sp)
/* B21024 80240AE4 0080802D */  daddu     $s0, $a0, $zero
/* B21028 80240AE8 AFBF0014 */  sw        $ra, 0x14($sp)
/* B2102C 80240AEC 0C00EABB */  jal       get_npc_unsafe
/* B21030 80240AF0 8E04008C */   lw       $a0, 0x8c($s0)
/* B21034 80240AF4 0040282D */  daddu     $a1, $v0, $zero
/* B21038 80240AF8 8E040094 */  lw        $a0, 0x94($s0)
/* B2103C 80240AFC 8CA30028 */  lw        $v1, 0x28($a1)
/* B21040 80240B00 ACA40028 */  sw        $a0, 0x28($a1)
/* B21044 80240B04 8FBF0014 */  lw        $ra, 0x14($sp)
/* B21048 80240B08 8FB00010 */  lw        $s0, 0x10($sp)
/* B2104C 80240B0C 24020002 */  addiu     $v0, $zero, 2
/* B21050 80240B10 3C018024 */  lui       $at, 0x8024
/* B21054 80240B14 AC237CB4 */  sw        $v1, 0x7cb4($at)
/* B21058 80240B18 03E00008 */  jr        $ra
/* B2105C 80240B1C 27BD0018 */   addiu    $sp, $sp, 0x18
