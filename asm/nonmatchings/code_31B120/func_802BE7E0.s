.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE7E0
/* 31C800 802BE7E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31C804 802BE7E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 31C808 802BE7E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 31C80C 802BE7EC 10A00003 */  beqz      $a1, .L802BE7FC
/* 31C810 802BE7F0 8C90014C */   lw       $s0, 0x14c($a0)
/* 31C814 802BE7F4 0C03BA65 */  jal       func_800EE994
/* 31C818 802BE7F8 0200202D */   daddu    $a0, $s0, $zero
.L802BE7FC:
/* 31C81C 802BE7FC 0C03BA6E */  jal       func_800EE9B8
/* 31C820 802BE800 0200202D */   daddu    $a0, $s0, $zero
/* 31C824 802BE804 8FBF0014 */  lw        $ra, 0x14($sp)
/* 31C828 802BE808 8FB00010 */  lw        $s0, 0x10($sp)
/* 31C82C 802BE80C 0002102B */  sltu      $v0, $zero, $v0
/* 31C830 802BE810 03E00008 */  jr        $ra
/* 31C834 802BE814 27BD0018 */   addiu    $sp, $sp, 0x18
