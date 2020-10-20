.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024151C
/* C8F0CC 8024151C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C8F0D0 80241520 AFB00010 */  sw        $s0, 0x10($sp)
/* C8F0D4 80241524 0080802D */  daddu     $s0, $a0, $zero
/* C8F0D8 80241528 AFBF0018 */  sw        $ra, 0x18($sp)
/* C8F0DC 8024152C AFB10014 */  sw        $s1, 0x14($sp)
/* C8F0E0 80241530 8E02000C */  lw        $v0, 0xc($s0)
/* C8F0E4 80241534 8C510000 */  lw        $s1, ($v0)
/* C8F0E8 80241538 0C0B1EAF */  jal       get_variable
/* C8F0EC 8024153C 0220282D */   daddu    $a1, $s1, $zero
/* C8F0F0 80241540 3C03FFF0 */  lui       $v1, 0xfff0
/* C8F0F4 80241544 3463FFFF */  ori       $v1, $v1, 0xffff
/* C8F0F8 80241548 0200202D */  daddu     $a0, $s0, $zero
/* C8F0FC 8024154C 00431024 */  and       $v0, $v0, $v1
/* C8F100 80241550 00021140 */  sll       $v0, $v0, 5
/* C8F104 80241554 3C068008 */  lui       $a2, %hi(gItemTable)
/* C8F108 80241558 00C23021 */  addu      $a2, $a2, $v0
/* C8F10C 8024155C 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* C8F110 80241560 0C0B2026 */  jal       set_variable
/* C8F114 80241564 0220282D */   daddu    $a1, $s1, $zero
/* C8F118 80241568 8FBF0018 */  lw        $ra, 0x18($sp)
/* C8F11C 8024156C 8FB10014 */  lw        $s1, 0x14($sp)
/* C8F120 80241570 8FB00010 */  lw        $s0, 0x10($sp)
/* C8F124 80241574 24020002 */  addiu     $v0, $zero, 2
/* C8F128 80241578 03E00008 */  jr        $ra
/* C8F12C 8024157C 27BD0020 */   addiu    $sp, $sp, 0x20
