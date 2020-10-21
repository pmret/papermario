.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024073C_8B07AC
/* 8B07AC 8024073C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B07B0 80240740 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B07B4 80240744 0C00EABB */  jal       get_npc_unsafe
/* 8B07B8 80240748 8C84014C */   lw       $a0, 0x14c($a0)
/* 8B07BC 8024074C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B07C0 80240750 0000102D */  daddu     $v0, $zero, $zero
/* 8B07C4 80240754 03E00008 */  jr        $ra
/* 8B07C8 80240758 27BD0018 */   addiu    $sp, $sp, 0x18
