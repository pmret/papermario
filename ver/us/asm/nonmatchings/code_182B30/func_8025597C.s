.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025597C
/* 18425C 8025597C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 184260 80255980 0080282D */  daddu     $a1, $a0, $zero
/* 184264 80255984 AFBF0010 */  sw        $ra, 0x10($sp)
/* 184268 80255988 0C09542F */  jal       func_802550BC
/* 18426C 8025598C 24040001 */   addiu    $a0, $zero, 1
/* 184270 80255990 8FBF0010 */  lw        $ra, 0x10($sp)
/* 184274 80255994 03E00008 */  jr        $ra
/* 184278 80255998 27BD0018 */   addiu    $sp, $sp, 0x18
