.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242804
/* 9C7BE4 80242804 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C7BE8 80242808 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9C7BEC 8024280C AFB00010 */  sw        $s0, 0x10($sp)
/* 9C7BF0 80242810 8C82000C */  lw        $v0, 0xc($a0)
/* 9C7BF4 80242814 0C0B1EAF */  jal       get_variable
/* 9C7BF8 80242818 8C450000 */   lw       $a1, ($v0)
/* 9C7BFC 8024281C 3C038025 */  lui       $v1, 0x8025
/* 9C7C00 80242820 24630810 */  addiu     $v1, $v1, 0x810
/* 9C7C04 80242824 00028040 */  sll       $s0, $v0, 1
/* 9C7C08 80242828 02038021 */  addu      $s0, $s0, $v1
/* 9C7C0C 8024282C 0C015612 */  jal       func_80055848
/* 9C7C10 80242830 86040000 */   lh       $a0, ($s0)
/* 9C7C14 80242834 240505DC */  addiu     $a1, $zero, 0x5dc
/* 9C7C18 80242838 86040000 */  lh        $a0, ($s0)
/* 9C7C1C 8024283C 0C01559B */  jal       func_8005566C
/* 9C7C20 80242840 2406007F */   addiu    $a2, $zero, 0x7f
/* 9C7C24 80242844 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9C7C28 80242848 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C7C2C 8024284C 24020002 */  addiu     $v0, $zero, 2
/* 9C7C30 80242850 03E00008 */  jr        $ra
/* 9C7C34 80242854 27BD0018 */   addiu    $sp, $sp, 0x18
