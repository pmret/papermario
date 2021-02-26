.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004B09C
/* 2649C 8004B09C 8CA20000 */  lw        $v0, ($a1)
/* 264A0 8004B0A0 AC850004 */  sw        $a1, 4($a0)
/* 264A4 8004B0A4 AC820000 */  sw        $v0, ($a0)
/* 264A8 8004B0A8 8CA20000 */  lw        $v0, ($a1)
/* 264AC 8004B0AC 54400001 */  bnel      $v0, $zero, .L8004B0B4
/* 264B0 8004B0B0 AC440004 */   sw       $a0, 4($v0)
.L8004B0B4:
/* 264B4 8004B0B4 03E00008 */  jr        $ra
/* 264B8 8004B0B8 ACA40000 */   sw       $a0, ($a1)
