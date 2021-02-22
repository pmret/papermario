.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C0E8
/* 174E8 8003C0E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 174EC 8003C0EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 174F0 8003C0F0 0C00F07F */  jal       func_8003C1FC
/* 174F4 8003C0F4 00000000 */   nop
/* 174F8 8003C0F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 174FC 8003C0FC 03E00008 */  jr        $ra
/* 17500 8003C100 27BD0018 */   addiu    $sp, $sp, 0x18
