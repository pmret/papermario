.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241038_889C08
/* 889C08 80241038 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 889C0C 8024103C AFBF0010 */  sw        $ra, 0x10($sp)
/* 889C10 80241040 8C82000C */  lw        $v0, 0xc($a0)
/* 889C14 80241044 0C0B1EAF */  jal       get_variable
/* 889C18 80241048 8C450000 */   lw       $a1, ($v0)
/* 889C1C 8024104C 0C03AC5A */  jal       func_800EB168
/* 889C20 80241050 0040202D */   daddu    $a0, $v0, $zero
/* 889C24 80241054 8FBF0010 */  lw        $ra, 0x10($sp)
/* 889C28 80241058 24020002 */  addiu     $v0, $zero, 2
/* 889C2C 8024105C 03E00008 */  jr        $ra
/* 889C30 80241060 27BD0018 */   addiu    $sp, $sp, 0x18
