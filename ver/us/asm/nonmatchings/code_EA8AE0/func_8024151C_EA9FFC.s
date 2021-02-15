.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024151C_EA9FFC
/* EA9FFC 8024151C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EAA000 80241520 AFB00010 */  sw        $s0, 0x10($sp)
/* EAA004 80241524 0080802D */  daddu     $s0, $a0, $zero
/* EAA008 80241528 AFBF0018 */  sw        $ra, 0x18($sp)
/* EAA00C 8024152C AFB10014 */  sw        $s1, 0x14($sp)
/* EAA010 80241530 8E02000C */  lw        $v0, 0xc($s0)
/* EAA014 80241534 8C510000 */  lw        $s1, ($v0)
/* EAA018 80241538 0C0B53A3 */  jal       func_802D4E8C
/* EAA01C 8024153C 0220282D */   daddu    $a1, $s1, $zero
/* EAA020 80241540 3C03FFF0 */  lui       $v1, 0xfff0
/* EAA024 80241544 3463FFFF */  ori       $v1, $v1, 0xffff
/* EAA028 80241548 0200202D */  daddu     $a0, $s0, $zero
/* EAA02C 8024154C 00431024 */  and       $v0, $v0, $v1
/* EAA030 80241550 00021140 */  sll       $v0, $v0, 5
/* EAA034 80241554 3C068009 */  lui       $a2, %hi(D_8008D2C0)
/* EAA038 80241558 00C23021 */  addu      $a2, $a2, $v0
/* EAA03C 8024155C 8CC6D2C0 */  lw        $a2, %lo(D_8008D2C0)($a2)
/* EAA040 80241560 0C0B551A */  jal       func_802D5468
/* EAA044 80241564 0220282D */   daddu    $a1, $s1, $zero
/* EAA048 80241568 8FBF0018 */  lw        $ra, 0x18($sp)
/* EAA04C 8024156C 8FB10014 */  lw        $s1, 0x14($sp)
/* EAA050 80241570 8FB00010 */  lw        $s0, 0x10($sp)
/* EAA054 80241574 24020002 */  addiu     $v0, $zero, 2
/* EAA058 80241578 03E00008 */  jr        $ra
/* EAA05C 8024157C 27BD0020 */   addiu    $sp, $sp, 0x20
