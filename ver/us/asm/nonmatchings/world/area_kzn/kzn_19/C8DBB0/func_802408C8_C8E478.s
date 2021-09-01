.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408C8_C8E478
/* C8E478 802408C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C8E47C 802408CC AFB00010 */  sw        $s0, 0x10($sp)
/* C8E480 802408D0 0080802D */  daddu     $s0, $a0, $zero
/* C8E484 802408D4 AFBF0014 */  sw        $ra, 0x14($sp)
/* C8E488 802408D8 8E02000C */  lw        $v0, 0xc($s0)
/* C8E48C 802408DC 0C0B1EAF */  jal       evt_get_variable
/* C8E490 802408E0 8C450000 */   lw       $a1, ($v0)
/* C8E494 802408E4 8E030084 */  lw        $v1, 0x84($s0)
/* C8E498 802408E8 8FBF0014 */  lw        $ra, 0x14($sp)
/* C8E49C 802408EC 8463004E */  lh        $v1, 0x4e($v1)
/* C8E4A0 802408F0 8FB00010 */  lw        $s0, 0x10($sp)
/* C8E4A4 802408F4 00621826 */  xor       $v1, $v1, $v0
/* C8E4A8 802408F8 2C630001 */  sltiu     $v1, $v1, 1
/* C8E4AC 802408FC 00031040 */  sll       $v0, $v1, 1
/* C8E4B0 80240900 03E00008 */  jr        $ra
/* C8E4B4 80240904 27BD0018 */   addiu    $sp, $sp, 0x18
