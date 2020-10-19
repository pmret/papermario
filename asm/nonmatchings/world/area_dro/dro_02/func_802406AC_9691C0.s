.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406AC_96986C
/* 96986C 802406AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 969870 802406B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 969874 802406B4 0C00EABB */  jal       get_npc_unsafe
/* 969878 802406B8 8C84014C */   lw       $a0, 0x14c($a0)
/* 96987C 802406BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 969880 802406C0 0000102D */  daddu     $v0, $zero, $zero
/* 969884 802406C4 03E00008 */  jr        $ra
/* 969888 802406C8 27BD0018 */   addiu    $sp, $sp, 0x18
