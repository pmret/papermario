.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240118_D36408
/* D36408 80240118 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3640C 8024011C AFB00010 */  sw        $s0, 0x10($sp)
/* D36410 80240120 0080802D */  daddu     $s0, $a0, $zero
/* D36414 80240124 AFBF0014 */  sw        $ra, 0x14($sp)
/* D36418 80240128 8E02000C */  lw        $v0, 0xc($s0)
/* D3641C 8024012C 0C0B1EAF */  jal       get_variable
/* D36420 80240130 8C450000 */   lw       $a1, ($v0)
/* D36424 80240134 0C04C3D6 */  jal       get_item_entity
/* D36428 80240138 0040202D */   daddu    $a0, $v0, $zero
/* D3642C 8024013C 84430018 */  lh        $v1, 0x18($v0)
/* D36430 80240140 AE030084 */  sw        $v1, 0x84($s0)
/* D36434 80240144 8FBF0014 */  lw        $ra, 0x14($sp)
/* D36438 80240148 8FB00010 */  lw        $s0, 0x10($sp)
/* D3643C 8024014C 24020002 */  addiu     $v0, $zero, 2
/* D36440 80240150 03E00008 */  jr        $ra
/* D36444 80240154 27BD0018 */   addiu    $sp, $sp, 0x18
