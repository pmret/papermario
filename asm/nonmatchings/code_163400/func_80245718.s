.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80245718
/* 165F78 80245718 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 165F7C 8024571C 0080402D */  daddu     $t0, $a0, $zero
/* 165F80 80245720 00A0482D */  daddu     $t1, $a1, $zero
/* 165F84 80245724 00C0502D */  daddu     $t2, $a2, $zero
/* 165F88 80245728 0100282D */  daddu     $a1, $t0, $zero
/* 165F8C 8024572C 8FA20038 */  lw        $v0, 0x38($sp)
/* 165F90 80245730 8FA3003C */  lw        $v1, 0x3c($sp)
/* 165F94 80245734 8FA40040 */  lw        $a0, 0x40($sp)
/* 165F98 80245738 0120302D */  daddu     $a2, $t1, $zero
/* 165F9C 8024573C AFA70010 */  sw        $a3, 0x10($sp)
/* 165FA0 80245740 0140382D */  daddu     $a3, $t2, $zero
/* 165FA4 80245744 AFBF0020 */  sw        $ra, 0x20($sp)
/* 165FA8 80245748 AFA4001C */  sw        $a0, 0x1c($sp)
/* 165FAC 8024574C 24040001 */  addiu     $a0, $zero, 1
/* 165FB0 80245750 AFA20014 */  sw        $v0, 0x14($sp)
/* 165FB4 80245754 0C091513 */  jal       func_8024544C
/* 165FB8 80245758 AFA30018 */   sw       $v1, 0x18($sp)
/* 165FBC 8024575C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 165FC0 80245760 03E00008 */  jr        $ra
/* 165FC4 80245764 27BD0028 */   addiu    $sp, $sp, 0x28
