.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B50_BD0740
/* BD0740 80241B50 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD0744 80241B54 AFBF0010 */  sw        $ra, 0x10($sp)
/* BD0748 80241B58 0C00EABB */  jal       get_npc_unsafe
/* BD074C 80241B5C 8C84014C */   lw       $a0, 0x14c($a0)
/* BD0750 80241B60 0040182D */  daddu     $v1, $v0, $zero
/* BD0754 80241B64 240400B4 */  addiu     $a0, $zero, 0xb4
/* BD0758 80241B68 A06400AC */  sb        $a0, 0xac($v1)
/* BD075C 80241B6C 24040016 */  addiu     $a0, $zero, 0x16
/* BD0760 80241B70 A06400AA */  sb        $a0, 0xaa($v1)
/* BD0764 80241B74 8FBF0010 */  lw        $ra, 0x10($sp)
/* BD0768 80241B78 24020002 */  addiu     $v0, $zero, 2
/* BD076C 80241B7C 03E00008 */  jr        $ra
/* BD0770 80241B80 27BD0018 */   addiu    $sp, $sp, 0x18
/* BD0774 80241B84 00000000 */  nop
/* BD0778 80241B88 00000000 */  nop
/* BD077C 80241B8C 00000000 */  nop
