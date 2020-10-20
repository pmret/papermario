.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412E4_DE3774
/* DE3774 802412E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DE3778 802412E8 AFB00010 */  sw        $s0, 0x10($sp)
/* DE377C 802412EC 0080802D */  daddu     $s0, $a0, $zero
/* DE3780 802412F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* DE3784 802412F4 AFB10014 */  sw        $s1, 0x14($sp)
/* DE3788 802412F8 8E02000C */  lw        $v0, 0xc($s0)
/* DE378C 802412FC 8C510000 */  lw        $s1, ($v0)
/* DE3790 80241300 0C0B1EAF */  jal       get_variable
/* DE3794 80241304 0220282D */   daddu    $a1, $s1, $zero
/* DE3798 80241308 3C03FFF0 */  lui       $v1, 0xfff0
/* DE379C 8024130C 3463FFFF */  ori       $v1, $v1, 0xffff
/* DE37A0 80241310 0200202D */  daddu     $a0, $s0, $zero
/* DE37A4 80241314 00431024 */  and       $v0, $v0, $v1
/* DE37A8 80241318 00021140 */  sll       $v0, $v0, 5
/* DE37AC 8024131C 3C068008 */  lui       $a2, %hi(gItemTable)
/* DE37B0 80241320 00C23021 */  addu      $a2, $a2, $v0
/* DE37B4 80241324 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* DE37B8 80241328 0C0B2026 */  jal       set_variable
/* DE37BC 8024132C 0220282D */   daddu    $a1, $s1, $zero
/* DE37C0 80241330 8FBF0018 */  lw        $ra, 0x18($sp)
/* DE37C4 80241334 8FB10014 */  lw        $s1, 0x14($sp)
/* DE37C8 80241338 8FB00010 */  lw        $s0, 0x10($sp)
/* DE37CC 8024133C 24020002 */  addiu     $v0, $zero, 2
/* DE37D0 80241340 03E00008 */  jr        $ra
/* DE37D4 80241344 27BD0020 */   addiu    $sp, $sp, 0x20
