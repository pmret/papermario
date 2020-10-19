.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407B4
/* CF8324 802407B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF8328 802407B8 AFB00010 */  sw        $s0, 0x10($sp)
/* CF832C 802407BC 0080802D */  daddu     $s0, $a0, $zero
/* CF8330 802407C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* CF8334 802407C4 AFB10014 */  sw        $s1, 0x14($sp)
/* CF8338 802407C8 8E02000C */  lw        $v0, 0xc($s0)
/* CF833C 802407CC 8C510000 */  lw        $s1, ($v0)
/* CF8340 802407D0 0C0B1EAF */  jal       get_variable
/* CF8344 802407D4 0220282D */   daddu    $a1, $s1, $zero
/* CF8348 802407D8 3C03FFF0 */  lui       $v1, 0xfff0
/* CF834C 802407DC 3463FFFF */  ori       $v1, $v1, 0xffff
/* CF8350 802407E0 0200202D */  daddu     $a0, $s0, $zero
/* CF8354 802407E4 00431024 */  and       $v0, $v0, $v1
/* CF8358 802407E8 00021140 */  sll       $v0, $v0, 5
/* CF835C 802407EC 3C068008 */  lui       $a2, %hi(gItemTable)
/* CF8360 802407F0 00C23021 */  addu      $a2, $a2, $v0
/* CF8364 802407F4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* CF8368 802407F8 0C0B2026 */  jal       set_variable
/* CF836C 802407FC 0220282D */   daddu    $a1, $s1, $zero
/* CF8370 80240800 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF8374 80240804 8FB10014 */  lw        $s1, 0x14($sp)
/* CF8378 80240808 8FB00010 */  lw        $s0, 0x10($sp)
/* CF837C 8024080C 24020002 */  addiu     $v0, $zero, 2
/* CF8380 80240810 03E00008 */  jr        $ra
/* CF8384 80240814 27BD0020 */   addiu    $sp, $sp, 0x20
