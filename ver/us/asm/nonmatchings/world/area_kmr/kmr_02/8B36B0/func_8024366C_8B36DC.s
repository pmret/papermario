.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024366C_8B36DC
/* 8B36DC 8024366C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B36E0 80243670 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B36E4 80243674 0080882D */  daddu     $s1, $a0, $zero
/* 8B36E8 80243678 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B36EC 8024367C AFB00010 */  sw        $s0, 0x10($sp)
/* 8B36F0 80243680 8E30000C */  lw        $s0, 0xc($s1)
/* 8B36F4 80243684 8E050000 */  lw        $a1, ($s0)
/* 8B36F8 80243688 0C0B1EAF */  jal       evt_get_variable
/* 8B36FC 8024368C 26100004 */   addiu    $s0, $s0, 4
/* 8B3700 80243690 0220202D */  daddu     $a0, $s1, $zero
/* 8B3704 80243694 8E050000 */  lw        $a1, ($s0)
/* 8B3708 80243698 0C0B1EAF */  jal       evt_get_variable
/* 8B370C 8024369C 0040802D */   daddu    $s0, $v0, $zero
/* 8B3710 802436A0 0200202D */  daddu     $a0, $s0, $zero
/* 8B3714 802436A4 00021080 */  sll       $v0, $v0, 2
/* 8B3718 802436A8 3C108025 */  lui       $s0, %hi(D_8025578C_8C57FC)
/* 8B371C 802436AC 02028021 */  addu      $s0, $s0, $v0
/* 8B3720 802436B0 0C00FB3A */  jal       get_enemy
/* 8B3724 802436B4 8E10578C */   lw       $s0, %lo(D_8025578C_8C57FC)($s0)
/* 8B3728 802436B8 0040302D */  daddu     $a2, $v0, $zero
/* 8B372C 802436BC 0000282D */  daddu     $a1, $zero, $zero
.L802436C0:
/* 8B3730 802436C0 8E040000 */  lw        $a0, ($s0)
/* 8B3734 802436C4 00051080 */  sll       $v0, $a1, 2
/* 8B3738 802436C8 8CC300D0 */  lw        $v1, 0xd0($a2)
/* 8B373C 802436CC 24A50001 */  addiu     $a1, $a1, 1
/* 8B3740 802436D0 00431021 */  addu      $v0, $v0, $v1
/* 8B3744 802436D4 AC440000 */  sw        $a0, ($v0)
/* 8B3748 802436D8 28A2000E */  slti      $v0, $a1, 0xe
/* 8B374C 802436DC 1440FFF8 */  bnez      $v0, .L802436C0
/* 8B3750 802436E0 26100004 */   addiu    $s0, $s0, 4
/* 8B3754 802436E4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B3758 802436E8 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B375C 802436EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B3760 802436F0 24020002 */  addiu     $v0, $zero, 2
/* 8B3764 802436F4 03E00008 */  jr        $ra
/* 8B3768 802436F8 27BD0020 */   addiu    $sp, $sp, 0x20
