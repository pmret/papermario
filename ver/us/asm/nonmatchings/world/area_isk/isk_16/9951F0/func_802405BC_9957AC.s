.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405BC_9957AC
/* 9957AC 802405BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9957B0 802405C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 9957B4 802405C4 0080802D */  daddu     $s0, $a0, $zero
/* 9957B8 802405C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9957BC 802405CC 8E02000C */  lw        $v0, 0xc($s0)
/* 9957C0 802405D0 0C0B1EAF */  jal       evt_get_variable
/* 9957C4 802405D4 8C450000 */   lw       $a1, ($v0)
/* 9957C8 802405D8 8E030084 */  lw        $v1, 0x84($s0)
/* 9957CC 802405DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9957D0 802405E0 8463004E */  lh        $v1, 0x4e($v1)
/* 9957D4 802405E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9957D8 802405E8 00621826 */  xor       $v1, $v1, $v0
/* 9957DC 802405EC 2C630001 */  sltiu     $v1, $v1, 1
/* 9957E0 802405F0 00031040 */  sll       $v0, $v1, 1
/* 9957E4 802405F4 03E00008 */  jr        $ra
/* 9957E8 802405F8 27BD0018 */   addiu    $sp, $sp, 0x18
