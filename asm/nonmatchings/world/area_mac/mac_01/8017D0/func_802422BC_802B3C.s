.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422BC_802B3C
/* 802B3C 802422BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 802B40 802422C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 802B44 802422C4 0C00EABB */  jal       get_npc_unsafe
/* 802B48 802422C8 8C84014C */   lw       $a0, 0x14c($a0)
/* 802B4C 802422CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 802B50 802422D0 0000102D */  daddu     $v0, $zero, $zero
/* 802B54 802422D4 03E00008 */  jr        $ra
/* 802B58 802422D8 27BD0018 */   addiu    $sp, $sp, 0x18
