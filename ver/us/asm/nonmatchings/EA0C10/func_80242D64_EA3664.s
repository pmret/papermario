.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D64_EA3664
/* EA3664 80242D64 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA3668 80242D68 AFB00010 */  sw        $s0, 0x10($sp)
/* EA366C 80242D6C 0080802D */  daddu     $s0, $a0, $zero
/* EA3670 80242D70 AFBF0014 */  sw        $ra, 0x14($sp)
/* EA3674 80242D74 0C00F92F */  jal       dead_get_npc_unsafe
/* EA3678 80242D78 8E04008C */   lw       $a0, 0x8c($s0)
/* EA367C 80242D7C 0040282D */  daddu     $a1, $v0, $zero
/* EA3680 80242D80 8E040094 */  lw        $a0, 0x94($s0)
/* EA3684 80242D84 8CA30028 */  lw        $v1, 0x28($a1)
/* EA3688 80242D88 ACA40028 */  sw        $a0, 0x28($a1)
/* EA368C 80242D8C 8FBF0014 */  lw        $ra, 0x14($sp)
/* EA3690 80242D90 8FB00010 */  lw        $s0, 0x10($sp)
/* EA3694 80242D94 24020002 */  addiu     $v0, $zero, 2
/* EA3698 80242D98 3C018024 */  lui       $at, %hi(D_80246894)
/* EA369C 80242D9C AC236894 */  sw        $v1, %lo(D_80246894)($at)
/* EA36A0 80242DA0 03E00008 */  jr        $ra
/* EA36A4 80242DA4 27BD0018 */   addiu    $sp, $sp, 0x18
