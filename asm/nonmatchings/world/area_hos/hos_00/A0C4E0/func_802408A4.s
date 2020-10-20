.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408A4
/* A0C594 802408A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A0C598 802408A8 AFB00010 */  sw        $s0, 0x10($sp)
/* A0C59C 802408AC 0080802D */  daddu     $s0, $a0, $zero
/* A0C5A0 802408B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A0C5A4 802408B4 AFB10014 */  sw        $s1, 0x14($sp)
/* A0C5A8 802408B8 8E02000C */  lw        $v0, 0xc($s0)
/* A0C5AC 802408BC 8C510000 */  lw        $s1, ($v0)
/* A0C5B0 802408C0 0C0B1EAF */  jal       get_variable
/* A0C5B4 802408C4 0220282D */   daddu    $a1, $s1, $zero
/* A0C5B8 802408C8 3C03FFF0 */  lui       $v1, 0xfff0
/* A0C5BC 802408CC 3463FFFF */  ori       $v1, $v1, 0xffff
/* A0C5C0 802408D0 0200202D */  daddu     $a0, $s0, $zero
/* A0C5C4 802408D4 00431024 */  and       $v0, $v0, $v1
/* A0C5C8 802408D8 00021140 */  sll       $v0, $v0, 5
/* A0C5CC 802408DC 3C068008 */  lui       $a2, %hi(gItemTable)
/* A0C5D0 802408E0 00C23021 */  addu      $a2, $a2, $v0
/* A0C5D4 802408E4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* A0C5D8 802408E8 0C0B2026 */  jal       set_variable
/* A0C5DC 802408EC 0220282D */   daddu    $a1, $s1, $zero
/* A0C5E0 802408F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A0C5E4 802408F4 8FB10014 */  lw        $s1, 0x14($sp)
/* A0C5E8 802408F8 8FB00010 */  lw        $s0, 0x10($sp)
/* A0C5EC 802408FC 24020002 */  addiu     $v0, $zero, 2
/* A0C5F0 80240900 03E00008 */  jr        $ra
/* A0C5F4 80240904 27BD0020 */   addiu    $sp, $sp, 0x20
