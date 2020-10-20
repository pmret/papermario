.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B7C
/* D3B14C 80240B7C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3B150 80240B80 AFBF0010 */  sw        $ra, 0x10($sp)
/* D3B154 80240B84 0C00EABB */  jal       get_npc_unsafe
/* D3B158 80240B88 8C84014C */   lw       $a0, 0x14c($a0)
/* D3B15C 80240B8C 8FBF0010 */  lw        $ra, 0x10($sp)
/* D3B160 80240B90 0000102D */  daddu     $v0, $zero, $zero
/* D3B164 80240B94 03E00008 */  jr        $ra
/* D3B168 80240B98 27BD0018 */   addiu    $sp, $sp, 0x18
