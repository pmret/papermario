.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409DC_7EB6EC
/* 7EB6EC 802409DC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EB6F0 802409E0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EB6F4 802409E4 0C00EABB */  jal       get_npc_unsafe
/* 7EB6F8 802409E8 8C84014C */   lw       $a0, 0x14c($a0)
/* 7EB6FC 802409EC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EB700 802409F0 0000102D */  daddu     $v0, $zero, $zero
/* 7EB704 802409F4 03E00008 */  jr        $ra
/* 7EB708 802409F8 27BD0018 */   addiu    $sp, $sp, 0x18
