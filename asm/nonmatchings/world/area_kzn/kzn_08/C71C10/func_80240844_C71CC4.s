.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240844_C71CC4
/* C71CC4 80240844 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C71CC8 80240848 AFB00010 */  sw        $s0, 0x10($sp)
/* C71CCC 8024084C 0080802D */  daddu     $s0, $a0, $zero
/* C71CD0 80240850 AFBF0018 */  sw        $ra, 0x18($sp)
/* C71CD4 80240854 AFB10014 */  sw        $s1, 0x14($sp)
/* C71CD8 80240858 8E02000C */  lw        $v0, 0xc($s0)
/* C71CDC 8024085C 8C510000 */  lw        $s1, ($v0)
/* C71CE0 80240860 0C0B1EAF */  jal       get_variable
/* C71CE4 80240864 0220282D */   daddu    $a1, $s1, $zero
/* C71CE8 80240868 3C03FFF0 */  lui       $v1, 0xfff0
/* C71CEC 8024086C 3463FFFF */  ori       $v1, $v1, 0xffff
/* C71CF0 80240870 0200202D */  daddu     $a0, $s0, $zero
/* C71CF4 80240874 00431024 */  and       $v0, $v0, $v1
/* C71CF8 80240878 00021140 */  sll       $v0, $v0, 5
/* C71CFC 8024087C 3C068008 */  lui       $a2, %hi(gItemTable)
/* C71D00 80240880 00C23021 */  addu      $a2, $a2, $v0
/* C71D04 80240884 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* C71D08 80240888 0C0B2026 */  jal       set_variable
/* C71D0C 8024088C 0220282D */   daddu    $a1, $s1, $zero
/* C71D10 80240890 8FBF0018 */  lw        $ra, 0x18($sp)
/* C71D14 80240894 8FB10014 */  lw        $s1, 0x14($sp)
/* C71D18 80240898 8FB00010 */  lw        $s0, 0x10($sp)
/* C71D1C 8024089C 24020002 */  addiu     $v0, $zero, 2
/* C71D20 802408A0 03E00008 */  jr        $ra
/* C71D24 802408A4 27BD0020 */   addiu    $sp, $sp, 0x20
