.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240ED8_D06608
/* D06608 80240ED8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D0660C 80240EDC AFBF0010 */  sw        $ra, 0x10($sp)
/* D06610 80240EE0 0C00EABB */  jal       get_npc_unsafe
/* D06614 80240EE4 8C84014C */   lw       $a0, 0x14c($a0)
/* D06618 80240EE8 8FBF0010 */  lw        $ra, 0x10($sp)
/* D0661C 80240EEC 0000102D */  daddu     $v0, $zero, $zero
/* D06620 80240EF0 03E00008 */  jr        $ra
/* D06624 80240EF4 27BD0018 */   addiu    $sp, $sp, 0x18
