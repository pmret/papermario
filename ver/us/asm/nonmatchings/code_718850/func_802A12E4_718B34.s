.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12E4_718B34
/* 718B34 802A12E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 718B38 802A12E8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 718B3C 802A12EC 0C04417A */  jal       get_entity_by_index
/* 718B40 802A12F0 8C8400AC */   lw       $a0, 0xac($a0)
/* 718B44 802A12F4 0040182D */  daddu     $v1, $v0, $zero
/* 718B48 802A12F8 8C640000 */  lw        $a0, ($v1)
/* 718B4C 802A12FC 3C052000 */  lui       $a1, 0x2000
/* 718B50 802A1300 00852025 */  or        $a0, $a0, $a1
/* 718B54 802A1304 AC640000 */  sw        $a0, ($v1)
/* 718B58 802A1308 8FBF0010 */  lw        $ra, 0x10($sp)
/* 718B5C 802A130C 24020002 */  addiu     $v0, $zero, 2
/* 718B60 802A1310 03E00008 */  jr        $ra
/* 718B64 802A1314 27BD0018 */   addiu    $sp, $sp, 0x18
