.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241944_7EC654
/* 7EC654 80241944 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EC658 80241948 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EC65C 8024194C 8C82000C */  lw        $v0, 0xc($a0)
/* 7EC660 80241950 0C0B1EAF */  jal       get_variable
/* 7EC664 80241954 8C450000 */   lw       $a1, ($v0)
/* 7EC668 80241958 3C018025 */  lui       $at, 0x8025
/* 7EC66C 8024195C AC2283EC */  sw        $v0, -0x7c14($at)
/* 7EC670 80241960 24020002 */  addiu     $v0, $zero, 2
/* 7EC674 80241964 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EC678 80241968 24030001 */  addiu     $v1, $zero, 1
/* 7EC67C 8024196C 3C018025 */  lui       $at, 0x8025
/* 7EC680 80241970 AC2383E8 */  sw        $v1, -0x7c18($at)
/* 7EC684 80241974 03E00008 */  jr        $ra
/* 7EC688 80241978 27BD0018 */   addiu    $sp, $sp, 0x18
