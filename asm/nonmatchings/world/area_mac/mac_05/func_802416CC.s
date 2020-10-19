.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416CC
/* 85383C 802416CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 853840 802416D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 853844 802416D4 0C00EABB */  jal       get_npc_unsafe
/* 853848 802416D8 8C84014C */   lw       $a0, 0x14c($a0)
/* 85384C 802416DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 853850 802416E0 0000102D */  daddu     $v0, $zero, $zero
/* 853854 802416E4 03E00008 */  jr        $ra
/* 853858 802416E8 27BD0018 */   addiu    $sp, $sp, 0x18
