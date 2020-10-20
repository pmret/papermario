.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B8C
/* AF84DC 80240B8C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AF84E0 80240B90 AFB00010 */  sw        $s0, 0x10($sp)
/* AF84E4 80240B94 0080802D */  daddu     $s0, $a0, $zero
/* AF84E8 80240B98 AFBF0018 */  sw        $ra, 0x18($sp)
/* AF84EC 80240B9C AFB10014 */  sw        $s1, 0x14($sp)
/* AF84F0 80240BA0 8E02000C */  lw        $v0, 0xc($s0)
/* AF84F4 80240BA4 8C510000 */  lw        $s1, ($v0)
/* AF84F8 80240BA8 0C0B1EAF */  jal       get_variable
/* AF84FC 80240BAC 0220282D */   daddu    $a1, $s1, $zero
/* AF8500 80240BB0 0200202D */  daddu     $a0, $s0, $zero
/* AF8504 80240BB4 00021140 */  sll       $v0, $v0, 5
/* AF8508 80240BB8 3C068008 */  lui       $a2, %hi(gItemTable)
/* AF850C 80240BBC 00C23021 */  addu      $a2, $a2, $v0
/* AF8510 80240BC0 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* AF8514 80240BC4 0C0B2026 */  jal       set_variable
/* AF8518 80240BC8 0220282D */   daddu    $a1, $s1, $zero
/* AF851C 80240BCC 8FBF0018 */  lw        $ra, 0x18($sp)
/* AF8520 80240BD0 8FB10014 */  lw        $s1, 0x14($sp)
/* AF8524 80240BD4 8FB00010 */  lw        $s0, 0x10($sp)
/* AF8528 80240BD8 24020002 */  addiu     $v0, $zero, 2
/* AF852C 80240BDC 03E00008 */  jr        $ra
/* AF8530 80240BE0 27BD0020 */   addiu    $sp, $sp, 0x20
