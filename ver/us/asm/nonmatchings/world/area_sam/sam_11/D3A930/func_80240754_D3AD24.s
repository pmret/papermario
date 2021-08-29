.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240754_D3AD24
/* D3AD24 80240754 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3AD28 80240758 AFB10014 */  sw        $s1, 0x14($sp)
/* D3AD2C 8024075C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* D3AD30 80240760 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* D3AD34 80240764 AFB00010 */  sw        $s0, 0x10($sp)
/* D3AD38 80240768 0040802D */  daddu     $s0, $v0, $zero
/* D3AD3C 8024076C AFBF0018 */  sw        $ra, 0x18($sp)
/* D3AD40 80240770 86030018 */  lh        $v1, 0x18($s0)
/* D3AD44 80240774 24020181 */  addiu     $v0, $zero, 0x181
/* D3AD48 80240778 14620006 */  bne       $v1, $v0, .L80240794
/* D3AD4C 8024077C 0080882D */   daddu    $s1, $a0, $zero
/* D3AD50 80240780 3C05FD05 */  lui       $a1, 0xfd05
/* D3AD54 80240784 34A50F87 */  ori       $a1, $a1, 0xf87
/* D3AD58 80240788 0C0B2026 */  jal       evt_set_variable
/* D3AD5C 8024078C 0000302D */   daddu    $a2, $zero, $zero
/* D3AD60 80240790 86030018 */  lh        $v1, 0x18($s0)
.L80240794:
/* D3AD64 80240794 24020096 */  addiu     $v0, $zero, 0x96
/* D3AD68 80240798 14620005 */  bne       $v1, $v0, .L802407B0
/* D3AD6C 8024079C 0220202D */   daddu    $a0, $s1, $zero
/* D3AD70 802407A0 3C05FD05 */  lui       $a1, 0xfd05
/* D3AD74 802407A4 34A50F87 */  ori       $a1, $a1, 0xf87
/* D3AD78 802407A8 0C0B2026 */  jal       evt_set_variable
/* D3AD7C 802407AC 24060001 */   addiu    $a2, $zero, 1
.L802407B0:
/* D3AD80 802407B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* D3AD84 802407B4 8FB10014 */  lw        $s1, 0x14($sp)
/* D3AD88 802407B8 8FB00010 */  lw        $s0, 0x10($sp)
/* D3AD8C 802407BC 0000102D */  daddu     $v0, $zero, $zero
/* D3AD90 802407C0 03E00008 */  jr        $ra
/* D3AD94 802407C4 27BD0020 */   addiu    $sp, $sp, 0x20
/* D3AD98 802407C8 00000000 */  nop
/* D3AD9C 802407CC 00000000 */  nop
