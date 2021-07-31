.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242730_EA3030
/* EA3030 80242730 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA3034 80242734 AFB00010 */  sw        $s0, 0x10($sp)
/* EA3038 80242738 0080802D */  daddu     $s0, $a0, $zero
/* EA303C 8024273C AFBF0018 */  sw        $ra, 0x18($sp)
/* EA3040 80242740 AFB10014 */  sw        $s1, 0x14($sp)
/* EA3044 80242744 8E02000C */  lw        $v0, 0xc($s0)
/* EA3048 80242748 8C510000 */  lw        $s1, ($v0)
/* EA304C 8024274C 0C0B53A3 */  jal       dead_get_variable
/* EA3050 80242750 0220282D */   daddu    $a1, $s1, $zero
/* EA3054 80242754 3C03FFF0 */  lui       $v1, 0xfff0
/* EA3058 80242758 3463FFFF */  ori       $v1, $v1, 0xffff
/* EA305C 8024275C 0200202D */  daddu     $a0, $s0, $zero
/* EA3060 80242760 00431024 */  and       $v0, $v0, $v1
/* EA3064 80242764 00021140 */  sll       $v0, $v0, 5
/* EA3068 80242768 3C068009 */  lui       $a2, %hi(dead_gItemTable)
/* EA306C 8024276C 00C23021 */  addu      $a2, $a2, $v0
/* EA3070 80242770 8CC6D2C0 */  lw        $a2, %lo(dead_gItemTable)($a2)
/* EA3074 80242774 0C0B551A */  jal       dead_set_variable
/* EA3078 80242778 0220282D */   daddu    $a1, $s1, $zero
/* EA307C 8024277C 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA3080 80242780 8FB10014 */  lw        $s1, 0x14($sp)
/* EA3084 80242784 8FB00010 */  lw        $s0, 0x10($sp)
/* EA3088 80242788 24020002 */  addiu     $v0, $zero, 2
/* EA308C 8024278C 03E00008 */  jr        $ra
/* EA3090 80242790 27BD0020 */   addiu    $sp, $sp, 0x20
