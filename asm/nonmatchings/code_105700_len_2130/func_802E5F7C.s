.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E5F7C
/* 1077FC 802E5F7C 8C830040 */  lw        $v1, 0x40($a0)
/* 107800 802E5F80 3C020A00 */  lui       $v0, 0xa00
/* 107804 802E5F84 24420800 */  addiu     $v0, $v0, 0x800
/* 107808 802E5F88 AC620128 */  sw        $v0, 0x128($v1)
/* 10780C 802E5F8C 3C020A00 */  lui       $v0, 0xa00
/* 107810 802E5F90 24420750 */  addiu     $v0, $v0, 0x750
/* 107814 802E5F94 AC62012C */  sw        $v0, 0x12c($v1)
/* 107818 802E5F98 3C02802E */  lui       $v0, %hi(D_802E586C)
/* 10781C 802E5F9C 2442586C */  addiu     $v0, $v0, %lo(D_802E586C)
/* 107820 802E5FA0 03E00008 */  jr        $ra
/* 107824 802E5FA4 AC82003C */   sw       $v0, 0x3c($a0)
/* 107828 802E5FA8 00000000 */  nop       
/* 10782C 802E5FAC 00000000 */  nop       
