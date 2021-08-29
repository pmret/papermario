.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408C8_EA93A8
/* EA93A8 802408C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA93AC 802408CC AFB00010 */  sw        $s0, 0x10($sp)
/* EA93B0 802408D0 0080802D */  daddu     $s0, $a0, $zero
/* EA93B4 802408D4 AFBF0014 */  sw        $ra, 0x14($sp)
/* EA93B8 802408D8 8E02000C */  lw        $v0, 0xc($s0)
/* EA93BC 802408DC 0C0B53A3 */  jal       dead_evt_get_variable
/* EA93C0 802408E0 8C450000 */   lw       $a1, ($v0)
/* EA93C4 802408E4 8E030084 */  lw        $v1, 0x84($s0)
/* EA93C8 802408E8 8FBF0014 */  lw        $ra, 0x14($sp)
/* EA93CC 802408EC 8463004E */  lh        $v1, 0x4e($v1)
/* EA93D0 802408F0 8FB00010 */  lw        $s0, 0x10($sp)
/* EA93D4 802408F4 00621826 */  xor       $v1, $v1, $v0
/* EA93D8 802408F8 2C630001 */  sltiu     $v1, $v1, 1
/* EA93DC 802408FC 00031040 */  sll       $v0, $v1, 1
/* EA93E0 80240900 03E00008 */  jr        $ra
/* EA93E4 80240904 27BD0018 */   addiu    $sp, $sp, 0x18
