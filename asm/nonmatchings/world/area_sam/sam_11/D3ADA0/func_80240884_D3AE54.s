.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240884_D3AE54
/* D3AE54 80240884 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3AE58 80240888 AFB00010 */  sw        $s0, 0x10($sp)
/* D3AE5C 8024088C 0080802D */  daddu     $s0, $a0, $zero
/* D3AE60 80240890 AFBF0018 */  sw        $ra, 0x18($sp)
/* D3AE64 80240894 AFB10014 */  sw        $s1, 0x14($sp)
/* D3AE68 80240898 8E02000C */  lw        $v0, 0xc($s0)
/* D3AE6C 8024089C 8C510000 */  lw        $s1, ($v0)
/* D3AE70 802408A0 0C0B1EAF */  jal       get_variable
/* D3AE74 802408A4 0220282D */   daddu    $a1, $s1, $zero
/* D3AE78 802408A8 3C03FFF0 */  lui       $v1, 0xfff0
/* D3AE7C 802408AC 3463FFFF */  ori       $v1, $v1, 0xffff
/* D3AE80 802408B0 0200202D */  daddu     $a0, $s0, $zero
/* D3AE84 802408B4 00431024 */  and       $v0, $v0, $v1
/* D3AE88 802408B8 00021140 */  sll       $v0, $v0, 5
/* D3AE8C 802408BC 3C068008 */  lui       $a2, %hi(gItemTable)
/* D3AE90 802408C0 00C23021 */  addu      $a2, $a2, $v0
/* D3AE94 802408C4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* D3AE98 802408C8 0C0B2026 */  jal       set_variable
/* D3AE9C 802408CC 0220282D */   daddu    $a1, $s1, $zero
/* D3AEA0 802408D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* D3AEA4 802408D4 8FB10014 */  lw        $s1, 0x14($sp)
/* D3AEA8 802408D8 8FB00010 */  lw        $s0, 0x10($sp)
/* D3AEAC 802408DC 24020002 */  addiu     $v0, $zero, 2
/* D3AEB0 802408E0 03E00008 */  jr        $ra
/* D3AEB4 802408E4 27BD0020 */   addiu    $sp, $sp, 0x20
