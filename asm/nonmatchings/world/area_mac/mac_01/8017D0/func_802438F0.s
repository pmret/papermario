.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802438F0
/* 804170 802438F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 804174 802438F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 804178 802438F8 8C82000C */  lw        $v0, 0xc($a0)
/* 80417C 802438FC 0C0B1EAF */  jal       get_variable
/* 804180 80243900 8C450000 */   lw       $a1, ($v0)
/* 804184 80243904 0C0B1059 */  jal       does_script_exist
/* 804188 80243908 0040202D */   daddu    $a0, $v0, $zero
/* 80418C 8024390C 2C420001 */  sltiu     $v0, $v0, 1
/* 804190 80243910 8FBF0010 */  lw        $ra, 0x10($sp)
/* 804194 80243914 00021040 */  sll       $v0, $v0, 1
/* 804198 80243918 03E00008 */  jr        $ra
/* 80419C 8024391C 27BD0018 */   addiu    $sp, $sp, 0x18
