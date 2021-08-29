.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405BC_DE8D2C
/* DE8D2C 802405BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DE8D30 802405C0 AFB00010 */  sw        $s0, 0x10($sp)
/* DE8D34 802405C4 0080802D */  daddu     $s0, $a0, $zero
/* DE8D38 802405C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* DE8D3C 802405CC 8E02000C */  lw        $v0, 0xc($s0)
/* DE8D40 802405D0 0C0B1EAF */  jal       evt_get_variable
/* DE8D44 802405D4 8C450000 */   lw       $a1, ($v0)
/* DE8D48 802405D8 8E030084 */  lw        $v1, 0x84($s0)
/* DE8D4C 802405DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* DE8D50 802405E0 8463004E */  lh        $v1, 0x4e($v1)
/* DE8D54 802405E4 8FB00010 */  lw        $s0, 0x10($sp)
/* DE8D58 802405E8 00621826 */  xor       $v1, $v1, $v0
/* DE8D5C 802405EC 2C630001 */  sltiu     $v1, $v1, 1
/* DE8D60 802405F0 00031040 */  sll       $v0, $v1, 1
/* DE8D64 802405F4 03E00008 */  jr        $ra
/* DE8D68 802405F8 27BD0018 */   addiu    $sp, $sp, 0x18
