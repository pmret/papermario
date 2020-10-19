.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024062C
/* 897C0C 8024062C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 897C10 80240630 AFBF0010 */  sw        $ra, 0x10($sp)
/* 897C14 80240634 8C82000C */  lw        $v0, 0xc($a0)
/* 897C18 80240638 0C0B1EAF */  jal       get_variable
/* 897C1C 8024063C 8C450000 */   lw       $a1, ($v0)
/* 897C20 80240640 0C0B95A4 */  jal       func_802E5690
/* 897C24 80240644 0040202D */   daddu    $a0, $v0, $zero
/* 897C28 80240648 8FBF0010 */  lw        $ra, 0x10($sp)
/* 897C2C 8024064C 24020002 */  addiu     $v0, $zero, 2
/* 897C30 80240650 03E00008 */  jr        $ra
/* 897C34 80240654 27BD0018 */   addiu    $sp, $sp, 0x18
