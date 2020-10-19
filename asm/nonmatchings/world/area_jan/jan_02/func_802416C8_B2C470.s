.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416C8_B2DB38
/* B2DB38 802416C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2DB3C 802416CC AFB00010 */  sw        $s0, 0x10($sp)
/* B2DB40 802416D0 0080802D */  daddu     $s0, $a0, $zero
/* B2DB44 802416D4 AFBF0018 */  sw        $ra, 0x18($sp)
/* B2DB48 802416D8 AFB10014 */  sw        $s1, 0x14($sp)
/* B2DB4C 802416DC 8E02000C */  lw        $v0, 0xc($s0)
/* B2DB50 802416E0 8C510000 */  lw        $s1, ($v0)
/* B2DB54 802416E4 0C0B1EAF */  jal       get_variable
/* B2DB58 802416E8 0220282D */   daddu    $a1, $s1, $zero
/* B2DB5C 802416EC 3C03FFF0 */  lui       $v1, 0xfff0
/* B2DB60 802416F0 3463FFFF */  ori       $v1, $v1, 0xffff
/* B2DB64 802416F4 0200202D */  daddu     $a0, $s0, $zero
/* B2DB68 802416F8 00431024 */  and       $v0, $v0, $v1
/* B2DB6C 802416FC 00021140 */  sll       $v0, $v0, 5
/* B2DB70 80241700 3C068008 */  lui       $a2, %hi(gItemTable)
/* B2DB74 80241704 00C23021 */  addu      $a2, $a2, $v0
/* B2DB78 80241708 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* B2DB7C 8024170C 0C0B2026 */  jal       set_variable
/* B2DB80 80241710 0220282D */   daddu    $a1, $s1, $zero
/* B2DB84 80241714 8FBF0018 */  lw        $ra, 0x18($sp)
/* B2DB88 80241718 8FB10014 */  lw        $s1, 0x14($sp)
/* B2DB8C 8024171C 8FB00010 */  lw        $s0, 0x10($sp)
/* B2DB90 80241720 24020002 */  addiu     $v0, $zero, 2
/* B2DB94 80241724 03E00008 */  jr        $ra
/* B2DB98 80241728 27BD0020 */   addiu    $sp, $sp, 0x20
