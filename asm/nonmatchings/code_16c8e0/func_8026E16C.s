.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026E16C
/* 19CA4C 8026E16C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19CA50 8026E170 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19CA54 8026E174 8C82000C */  lw        $v0, 0xc($a0)
/* 19CA58 8026E178 0C0B1EAF */  jal       get_variable
/* 19CA5C 8026E17C 8C450000 */   lw       $a1, ($v0)
/* 19CA60 8026E180 0C090464 */  jal       func_80241190
/* 19CA64 8026E184 0040202D */   daddu    $a0, $v0, $zero
/* 19CA68 8026E188 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19CA6C 8026E18C 24020002 */  addiu     $v0, $zero, 2
/* 19CA70 8026E190 03E00008 */  jr        $ra
/* 19CA74 8026E194 27BD0018 */   addiu    $sp, $sp, 0x18
