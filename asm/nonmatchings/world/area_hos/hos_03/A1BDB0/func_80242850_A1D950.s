.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242850_A1D950
/* A1D950 80242850 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1D954 80242854 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1D958 80242858 0C00EABB */  jal       get_npc_unsafe
/* A1D95C 8024285C 8C84014C */   lw       $a0, 0x14c($a0)
/* A1D960 80242860 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1D964 80242864 0000102D */  daddu     $v0, $zero, $zero
/* A1D968 80242868 03E00008 */  jr        $ra
/* A1D96C 8024286C 27BD0018 */   addiu    $sp, $sp, 0x18
