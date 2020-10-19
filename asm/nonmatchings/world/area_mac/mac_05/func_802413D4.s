.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413D4
/* 853544 802413D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 853548 802413D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 85354C 802413DC 0080802D */  daddu     $s0, $a0, $zero
/* 853550 802413E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 853554 802413E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 853558 802413E8 8E02000C */  lw        $v0, 0xc($s0)
/* 85355C 802413EC 8C510000 */  lw        $s1, ($v0)
/* 853560 802413F0 0C0B1EAF */  jal       get_variable
/* 853564 802413F4 0220282D */   daddu    $a1, $s1, $zero
/* 853568 802413F8 3C03FFF0 */  lui       $v1, 0xfff0
/* 85356C 802413FC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 853570 80241400 0200202D */  daddu     $a0, $s0, $zero
/* 853574 80241404 00431024 */  and       $v0, $v0, $v1
/* 853578 80241408 00021140 */  sll       $v0, $v0, 5
/* 85357C 8024140C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 853580 80241410 00C23021 */  addu      $a2, $a2, $v0
/* 853584 80241414 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 853588 80241418 0C0B2026 */  jal       set_variable
/* 85358C 8024141C 0220282D */   daddu    $a1, $s1, $zero
/* 853590 80241420 8FBF0018 */  lw        $ra, 0x18($sp)
/* 853594 80241424 8FB10014 */  lw        $s1, 0x14($sp)
/* 853598 80241428 8FB00010 */  lw        $s0, 0x10($sp)
/* 85359C 8024142C 24020002 */  addiu     $v0, $zero, 2
/* 8535A0 80241430 03E00008 */  jr        $ra
/* 8535A4 80241434 27BD0020 */   addiu    $sp, $sp, 0x20
