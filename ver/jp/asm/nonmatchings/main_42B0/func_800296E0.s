.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800296E0
/* 4AE0 800296E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4AE4 800296E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4AE8 800296E8 0C019188 */  jal       func_80064620
/* 4AEC 800296EC 24060040 */   addiu    $a2, $zero, 0x40
/* 4AF0 800296F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4AF4 800296F4 03E00008 */  jr        $ra
/* 4AF8 800296F8 27BD0018 */   addiu    $sp, $sp, 0x18
