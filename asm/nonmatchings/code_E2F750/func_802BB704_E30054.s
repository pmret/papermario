.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB704_E30054
/* E30054 802BB704 8C860040 */  lw        $a2, 0x40($a0)
/* E30058 802BB708 90C20002 */  lbu       $v0, 2($a2)
/* E3005C 802BB70C 2442FFFF */  addiu     $v0, $v0, -1
/* E30060 802BB710 A0C20002 */  sb        $v0, 2($a2)
/* E30064 802BB714 00021600 */  sll       $v0, $v0, 0x18
/* E30068 802BB718 1C400012 */  bgtz      $v0, .L802BB764
/* E3006C 802BB71C 240200FF */   addiu    $v0, $zero, 0xff
/* E30070 802BB720 80C40001 */  lb        $a0, 1($a2)
/* E30074 802BB724 3C05802C */  lui       $a1, %hi(D_802BCA30)
/* E30078 802BB728 24A5CA30 */  addiu     $a1, $a1, %lo(D_802BCA30)
/* E3007C 802BB72C 3C03802C */  lui       $v1, %hi(D_802BCA30)
/* E30080 802BB730 00641821 */  addu      $v1, $v1, $a0
/* E30084 802BB734 9063CA30 */  lbu       $v1, %lo(D_802BCA30)($v1)
/* E30088 802BB738 50620001 */  beql      $v1, $v0, .L802BB740
/* E3008C 802BB73C 0000202D */   daddu    $a0, $zero, $zero
.L802BB740:
/* E30090 802BB740 00851021 */  addu      $v0, $a0, $a1
/* E30094 802BB744 90420000 */  lbu       $v0, ($v0)
/* E30098 802BB748 24840001 */  addiu     $a0, $a0, 1
/* E3009C 802BB74C A0C20003 */  sb        $v0, 3($a2)
/* E300A0 802BB750 00851021 */  addu      $v0, $a0, $a1
/* E300A4 802BB754 90420000 */  lbu       $v0, ($v0)
/* E300A8 802BB758 24840001 */  addiu     $a0, $a0, 1
/* E300AC 802BB75C A0C40001 */  sb        $a0, 1($a2)
/* E300B0 802BB760 A0C20002 */  sb        $v0, 2($a2)
.L802BB764:
/* E300B4 802BB764 03E00008 */  jr        $ra
/* E300B8 802BB768 00000000 */   nop      
