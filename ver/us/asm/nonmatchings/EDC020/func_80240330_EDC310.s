.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240330_EDC310
/* EDC310 80240330 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDC314 80240334 AFB00010 */  sw        $s0, 0x10($sp)
/* EDC318 80240338 0080802D */  daddu     $s0, $a0, $zero
/* EDC31C 8024033C AFBF0018 */  sw        $ra, 0x18($sp)
/* EDC320 80240340 AFB10014 */  sw        $s1, 0x14($sp)
/* EDC324 80240344 8E02000C */  lw        $v0, 0xc($s0)
/* EDC328 80240348 8C510000 */  lw        $s1, ($v0)
/* EDC32C 8024034C 0C0B53A3 */  jal       dead_get_variable
/* EDC330 80240350 0220282D */   daddu    $a1, $s1, $zero
/* EDC334 80240354 3C03FFF0 */  lui       $v1, 0xfff0
/* EDC338 80240358 3463FFFF */  ori       $v1, $v1, 0xffff
/* EDC33C 8024035C 0200202D */  daddu     $a0, $s0, $zero
/* EDC340 80240360 00431024 */  and       $v0, $v0, $v1
/* EDC344 80240364 00021140 */  sll       $v0, $v0, 5
/* EDC348 80240368 3C068009 */  lui       $a2, %hi(dead_gItemTable)
/* EDC34C 8024036C 00C23021 */  addu      $a2, $a2, $v0
/* EDC350 80240370 8CC6D2C0 */  lw        $a2, %lo(dead_gItemTable)($a2)
/* EDC354 80240374 0C0B551A */  jal       dead_set_variable
/* EDC358 80240378 0220282D */   daddu    $a1, $s1, $zero
/* EDC35C 8024037C 8FBF0018 */  lw        $ra, 0x18($sp)
/* EDC360 80240380 8FB10014 */  lw        $s1, 0x14($sp)
/* EDC364 80240384 8FB00010 */  lw        $s0, 0x10($sp)
/* EDC368 80240388 24020002 */  addiu     $v0, $zero, 2
/* EDC36C 8024038C 03E00008 */  jr        $ra
/* EDC370 80240390 27BD0020 */   addiu    $sp, $sp, 0x20
