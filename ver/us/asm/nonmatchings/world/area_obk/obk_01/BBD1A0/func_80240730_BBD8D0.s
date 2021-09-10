.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240730_BBD8D0
/* BBD8D0 80240730 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BBD8D4 80240734 AFB00010 */  sw        $s0, 0x10($sp)
/* BBD8D8 80240738 0080802D */  daddu     $s0, $a0, $zero
/* BBD8DC 8024073C AFBF0014 */  sw        $ra, 0x14($sp)
/* BBD8E0 80240740 10A00005 */  beqz      $a1, .L80240758
/* BBD8E4 80240744 8E02000C */   lw       $v0, 0xc($s0)
/* BBD8E8 80240748 0C0B1EAF */  jal       evt_get_variable
/* BBD8EC 8024074C 8C450000 */   lw       $a1, ($v0)
/* BBD8F0 80240750 8C420000 */  lw        $v0, ($v0)
/* BBD8F4 80240754 AE020074 */  sw        $v0, 0x74($s0)
.L80240758:
/* BBD8F8 80240758 8E040074 */  lw        $a0, 0x74($s0)
/* BBD8FC 8024075C 8C830000 */  lw        $v1, ($a0)
/* BBD900 80240760 30620004 */  andi      $v0, $v1, 4
/* BBD904 80240764 14400003 */  bnez      $v0, .L80240774
/* BBD908 80240768 2402FFFD */   addiu    $v0, $zero, -3
/* BBD90C 8024076C 080901E0 */  j         .L80240780
/* BBD910 80240770 0000102D */   daddu    $v0, $zero, $zero
.L80240774:
/* BBD914 80240774 00621024 */  and       $v0, $v1, $v0
/* BBD918 80240778 AC820000 */  sw        $v0, ($a0)
/* BBD91C 8024077C 24020002 */  addiu     $v0, $zero, 2
.L80240780:
/* BBD920 80240780 8FBF0014 */  lw        $ra, 0x14($sp)
/* BBD924 80240784 8FB00010 */  lw        $s0, 0x10($sp)
/* BBD928 80240788 03E00008 */  jr        $ra
/* BBD92C 8024078C 27BD0018 */   addiu    $sp, $sp, 0x18
