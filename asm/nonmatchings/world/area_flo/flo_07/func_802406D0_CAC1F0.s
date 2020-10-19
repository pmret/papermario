.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406D0_CAC8C0
/* CAC8C0 802406D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CAC8C4 802406D4 AFB00010 */  sw        $s0, 0x10($sp)
/* CAC8C8 802406D8 0080802D */  daddu     $s0, $a0, $zero
/* CAC8CC 802406DC AFBF0018 */  sw        $ra, 0x18($sp)
/* CAC8D0 802406E0 AFB10014 */  sw        $s1, 0x14($sp)
/* CAC8D4 802406E4 8E02000C */  lw        $v0, 0xc($s0)
/* CAC8D8 802406E8 8C510000 */  lw        $s1, ($v0)
/* CAC8DC 802406EC 0C0B1EAF */  jal       get_variable
/* CAC8E0 802406F0 0220282D */   daddu    $a1, $s1, $zero
/* CAC8E4 802406F4 3C03FFF0 */  lui       $v1, 0xfff0
/* CAC8E8 802406F8 3463FFFF */  ori       $v1, $v1, 0xffff
/* CAC8EC 802406FC 0200202D */  daddu     $a0, $s0, $zero
/* CAC8F0 80240700 00431024 */  and       $v0, $v0, $v1
/* CAC8F4 80240704 00021140 */  sll       $v0, $v0, 5
/* CAC8F8 80240708 3C068008 */  lui       $a2, %hi(gItemTable)
/* CAC8FC 8024070C 00C23021 */  addu      $a2, $a2, $v0
/* CAC900 80240710 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* CAC904 80240714 0C0B2026 */  jal       set_variable
/* CAC908 80240718 0220282D */   daddu    $a1, $s1, $zero
/* CAC90C 8024071C 8FBF0018 */  lw        $ra, 0x18($sp)
/* CAC910 80240720 8FB10014 */  lw        $s1, 0x14($sp)
/* CAC914 80240724 8FB00010 */  lw        $s0, 0x10($sp)
/* CAC918 80240728 24020002 */  addiu     $v0, $zero, 2
/* CAC91C 8024072C 03E00008 */  jr        $ra
/* CAC920 80240730 27BD0020 */   addiu    $sp, $sp, 0x20
/* CAC924 80240734 00000000 */  nop       
/* CAC928 80240738 00000000 */  nop       
/* CAC92C 8024073C 00000000 */  nop       
