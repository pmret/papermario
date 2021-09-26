.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_32_StarSpiritEffectFunc4
/* D86FDC 802405DC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D86FE0 802405E0 AFB00010 */  sw        $s0, 0x10($sp)
/* D86FE4 802405E4 0080802D */  daddu     $s0, $a0, $zero
/* D86FE8 802405E8 AFBF0014 */  sw        $ra, 0x14($sp)
/* D86FEC 802405EC 8E02000C */  lw        $v0, 0xc($s0)
/* D86FF0 802405F0 0C0B1EAF */  jal       evt_get_variable
/* D86FF4 802405F4 8C450000 */   lw       $a1, ($v0)
/* D86FF8 802405F8 8E030084 */  lw        $v1, 0x84($s0)
/* D86FFC 802405FC 8FBF0014 */  lw        $ra, 0x14($sp)
/* D87000 80240600 8463004E */  lh        $v1, 0x4e($v1)
/* D87004 80240604 8FB00010 */  lw        $s0, 0x10($sp)
/* D87008 80240608 00621826 */  xor       $v1, $v1, $v0
/* D8700C 8024060C 2C630001 */  sltiu     $v1, $v1, 1
/* D87010 80240610 00031040 */  sll       $v0, $v1, 1
/* D87014 80240614 03E00008 */  jr        $ra
/* D87018 80240618 27BD0018 */   addiu    $sp, $sp, 0x18
