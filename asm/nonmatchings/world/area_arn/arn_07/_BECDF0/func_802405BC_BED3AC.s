.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405BC_BED3AC
/* BED3AC 802405BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BED3B0 802405C0 AFB00010 */  sw        $s0, 0x10($sp)
/* BED3B4 802405C4 0080802D */  daddu     $s0, $a0, $zero
/* BED3B8 802405C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* BED3BC 802405CC 8E02000C */  lw        $v0, 0xc($s0)
/* BED3C0 802405D0 0C0B1EAF */  jal       get_variable
/* BED3C4 802405D4 8C450000 */   lw       $a1, ($v0)
/* BED3C8 802405D8 8E030084 */  lw        $v1, 0x84($s0)
/* BED3CC 802405DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* BED3D0 802405E0 8463004E */  lh        $v1, 0x4e($v1)
/* BED3D4 802405E4 8FB00010 */  lw        $s0, 0x10($sp)
/* BED3D8 802405E8 00621826 */  xor       $v1, $v1, $v0
/* BED3DC 802405EC 2C630001 */  sltiu     $v1, $v1, 1
/* BED3E0 802405F0 00031040 */  sll       $v0, $v1, 1
/* BED3E4 802405F4 03E00008 */  jr        $ra
/* BED3E8 802405F8 27BD0018 */   addiu    $sp, $sp, 0x18
