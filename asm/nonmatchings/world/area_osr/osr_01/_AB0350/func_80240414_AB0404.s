.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240414_AB0404
/* AB0404 80240414 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AB0408 80240418 AFB00010 */  sw        $s0, 0x10($sp)
/* AB040C 8024041C 0080802D */  daddu     $s0, $a0, $zero
/* AB0410 80240420 AFBF0018 */  sw        $ra, 0x18($sp)
/* AB0414 80240424 AFB10014 */  sw        $s1, 0x14($sp)
/* AB0418 80240428 8E02000C */  lw        $v0, 0xc($s0)
/* AB041C 8024042C 8C510000 */  lw        $s1, ($v0)
/* AB0420 80240430 0C0B1EAF */  jal       get_variable
/* AB0424 80240434 0220282D */   daddu    $a1, $s1, $zero
/* AB0428 80240438 3C03FFF0 */  lui       $v1, 0xfff0
/* AB042C 8024043C 3463FFFF */  ori       $v1, $v1, 0xffff
/* AB0430 80240440 0200202D */  daddu     $a0, $s0, $zero
/* AB0434 80240444 00431024 */  and       $v0, $v0, $v1
/* AB0438 80240448 00021140 */  sll       $v0, $v0, 5
/* AB043C 8024044C 3C068008 */  lui       $a2, %hi(gItemTable)
/* AB0440 80240450 00C23021 */  addu      $a2, $a2, $v0
/* AB0444 80240454 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* AB0448 80240458 0C0B2026 */  jal       set_variable
/* AB044C 8024045C 0220282D */   daddu    $a1, $s1, $zero
/* AB0450 80240460 8FBF0018 */  lw        $ra, 0x18($sp)
/* AB0454 80240464 8FB10014 */  lw        $s1, 0x14($sp)
/* AB0458 80240468 8FB00010 */  lw        $s0, 0x10($sp)
/* AB045C 8024046C 24020002 */  addiu     $v0, $zero, 2
/* AB0460 80240470 03E00008 */  jr        $ra
/* AB0464 80240474 27BD0020 */   addiu    $sp, $sp, 0x20
