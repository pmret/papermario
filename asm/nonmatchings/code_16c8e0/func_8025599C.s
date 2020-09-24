.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025599C
/* 18427C 8025599C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 184280 802559A0 0080282D */  daddu     $a1, $a0, $zero
/* 184284 802559A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 184288 802559A8 0C0954BB */  jal       func_802552EC
/* 18428C 802559AC 24040001 */   addiu    $a0, $zero, 1
/* 184290 802559B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 184294 802559B4 03E00008 */  jr        $ra
/* 184298 802559B8 27BD0018 */   addiu    $sp, $sp, 0x18
