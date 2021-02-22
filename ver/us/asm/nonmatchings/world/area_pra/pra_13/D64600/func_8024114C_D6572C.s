.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024114C_D6572C
/* D6572C 8024114C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D65730 80241150 AFBF0010 */  sw        $ra, 0x10($sp)
/* D65734 80241154 10A00003 */  beqz      $a1, .L80241164
/* D65738 80241158 8C86000C */   lw       $a2, 0xc($a0)
/* D6573C 8024115C 3C018024 */  lui       $at, %hi(D_802422CC_D668AC)
/* D65740 80241160 AC2022CC */  sw        $zero, %lo(D_802422CC_D668AC)($at)
.L80241164:
/* D65744 80241164 3C038024 */  lui       $v1, %hi(D_802422CC_D668AC)
/* D65748 80241168 246322CC */  addiu     $v1, $v1, %lo(D_802422CC_D668AC)
/* D6574C 8024116C 8C620000 */  lw        $v0, ($v1)
/* D65750 80241170 54400003 */  bnel      $v0, $zero, .L80241180
/* D65754 80241174 AC600000 */   sw       $zero, ($v1)
/* D65758 80241178 08090465 */  j         .L80241194
/* D6575C 8024117C 0000102D */   daddu    $v0, $zero, $zero
.L80241180:
/* D65760 80241180 8CC50000 */  lw        $a1, ($a2)
/* D65764 80241184 3C068024 */  lui       $a2, %hi(D_802422D0_D668B0)
/* D65768 80241188 0C0B2026 */  jal       set_variable
/* D6576C 8024118C 8CC622D0 */   lw       $a2, %lo(D_802422D0_D668B0)($a2)
/* D65770 80241190 24020002 */  addiu     $v0, $zero, 2
.L80241194:
/* D65774 80241194 8FBF0010 */  lw        $ra, 0x10($sp)
/* D65778 80241198 03E00008 */  jr        $ra
/* D6577C 8024119C 27BD0018 */   addiu    $sp, $sp, 0x18
