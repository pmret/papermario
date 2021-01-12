.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E5800
/* 107080 802E5800 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 107084 802E5804 AFBF0010 */  sw        $ra, 0x10($sp)
/* 107088 802E5808 0C0B95E3 */  jal       func_802E578C
/* 10708C 802E580C 00000000 */   nop
/* 107090 802E5810 8FBF0010 */  lw        $ra, 0x10($sp)
/* 107094 802E5814 03E00008 */  jr        $ra
/* 107098 802E5818 27BD0018 */   addiu    $sp, $sp, 0x18
