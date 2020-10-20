.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024080C
/* 8433DC 8024080C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8433E0 80240810 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8433E4 80240814 0C00EABB */  jal       get_npc_unsafe
/* 8433E8 80240818 8C84014C */   lw       $a0, 0x14c($a0)
/* 8433EC 8024081C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8433F0 80240820 0000102D */  daddu     $v0, $zero, $zero
/* 8433F4 80240824 03E00008 */  jr        $ra
/* 8433F8 80240828 27BD0018 */   addiu    $sp, $sp, 0x18
