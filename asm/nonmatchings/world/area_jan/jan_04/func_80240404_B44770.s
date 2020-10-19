.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240404_B44B74
/* B44B74 80240404 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B44B78 80240408 AFB00010 */  sw        $s0, 0x10($sp)
/* B44B7C 8024040C 0080802D */  daddu     $s0, $a0, $zero
/* B44B80 80240410 AFBF0018 */  sw        $ra, 0x18($sp)
/* B44B84 80240414 AFB10014 */  sw        $s1, 0x14($sp)
/* B44B88 80240418 8E02000C */  lw        $v0, 0xc($s0)
/* B44B8C 8024041C 8C510000 */  lw        $s1, ($v0)
/* B44B90 80240420 0C0B1EAF */  jal       get_variable
/* B44B94 80240424 0220282D */   daddu    $a1, $s1, $zero
/* B44B98 80240428 3C03FFF0 */  lui       $v1, 0xfff0
/* B44B9C 8024042C 3463FFFF */  ori       $v1, $v1, 0xffff
/* B44BA0 80240430 0200202D */  daddu     $a0, $s0, $zero
/* B44BA4 80240434 00431024 */  and       $v0, $v0, $v1
/* B44BA8 80240438 00021140 */  sll       $v0, $v0, 5
/* B44BAC 8024043C 3C068008 */  lui       $a2, %hi(gItemTable)
/* B44BB0 80240440 00C23021 */  addu      $a2, $a2, $v0
/* B44BB4 80240444 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* B44BB8 80240448 0C0B2026 */  jal       set_variable
/* B44BBC 8024044C 0220282D */   daddu    $a1, $s1, $zero
/* B44BC0 80240450 8FBF0018 */  lw        $ra, 0x18($sp)
/* B44BC4 80240454 8FB10014 */  lw        $s1, 0x14($sp)
/* B44BC8 80240458 8FB00010 */  lw        $s0, 0x10($sp)
/* B44BCC 8024045C 24020002 */  addiu     $v0, $zero, 2
/* B44BD0 80240460 03E00008 */  jr        $ra
/* B44BD4 80240464 27BD0020 */   addiu    $sp, $sp, 0x20
