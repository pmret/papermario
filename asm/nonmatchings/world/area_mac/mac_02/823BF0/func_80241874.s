.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241874
/* 824B34 80241874 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 824B38 80241878 AFB00010 */  sw        $s0, 0x10($sp)
/* 824B3C 8024187C 0080802D */  daddu     $s0, $a0, $zero
/* 824B40 80241880 AFBF0018 */  sw        $ra, 0x18($sp)
/* 824B44 80241884 AFB10014 */  sw        $s1, 0x14($sp)
/* 824B48 80241888 8E02000C */  lw        $v0, 0xc($s0)
/* 824B4C 8024188C 8C510000 */  lw        $s1, ($v0)
/* 824B50 80241890 0C0B1EAF */  jal       get_variable
/* 824B54 80241894 0220282D */   daddu    $a1, $s1, $zero
/* 824B58 80241898 3C03FFF0 */  lui       $v1, 0xfff0
/* 824B5C 8024189C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 824B60 802418A0 0200202D */  daddu     $a0, $s0, $zero
/* 824B64 802418A4 00431024 */  and       $v0, $v0, $v1
/* 824B68 802418A8 00021140 */  sll       $v0, $v0, 5
/* 824B6C 802418AC 3C068008 */  lui       $a2, %hi(gItemTable)
/* 824B70 802418B0 00C23021 */  addu      $a2, $a2, $v0
/* 824B74 802418B4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 824B78 802418B8 0C0B2026 */  jal       set_variable
/* 824B7C 802418BC 0220282D */   daddu    $a1, $s1, $zero
/* 824B80 802418C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 824B84 802418C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 824B88 802418C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 824B8C 802418CC 24020002 */  addiu     $v0, $zero, 2
/* 824B90 802418D0 03E00008 */  jr        $ra
/* 824B94 802418D4 27BD0020 */   addiu    $sp, $sp, 0x20
