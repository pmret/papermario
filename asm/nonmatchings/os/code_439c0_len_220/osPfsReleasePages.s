.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPfsReleasePages
/* 43B6C 8006876C 8FA90010 */  lw        $t1, 0x10($sp)
/* 43B70 80068770 00071200 */  sll       $v0, $a3, 8
/* 43B74 80068774 30C600FF */  andi      $a2, $a2, 0xff
/* 43B78 80068778 00461825 */  or        $v1, $v0, $a2
/* 43B7C 8006877C 24080003 */  addiu     $t0, $zero, 3
/* 43B80 80068780 30E700FF */  andi      $a3, $a3, 0xff
/* 43B84 80068784 00601021 */  addu      $v0, $v1, $zero
.L80068788:
/* 43B88 80068788 304300FF */  andi      $v1, $v0, 0xff
/* 43B8C 8006878C 00031840 */  sll       $v1, $v1, 1
/* 43B90 80068790 00651821 */  addu      $v1, $v1, $a1
/* 43B94 80068794 94630000 */  lhu       $v1, ($v1)
/* 43B98 80068798 304200FF */  andi      $v0, $v0, 0xff
/* 43B9C 8006879C 00021040 */  sll       $v0, $v0, 1
/* 43BA0 800687A0 00A21021 */  addu      $v0, $a1, $v0
/* 43BA4 800687A4 A4480000 */  sh        $t0, ($v0)
/* 43BA8 800687A8 8C820060 */  lw        $v0, 0x60($a0)
/* 43BAC 800687AC 3066FFFF */  andi      $a2, $v1, 0xffff
/* 43BB0 800687B0 00C2102A */  slt       $v0, $a2, $v0
/* 43BB4 800687B4 54400005 */  bnel      $v0, $zero, .L800687CC
/* 43BB8 800687B8 A5230000 */   sh       $v1, ($t1)
/* 43BBC 800687BC 00061202 */  srl       $v0, $a2, 8
/* 43BC0 800687C0 1047FFF1 */  beq       $v0, $a3, .L80068788
/* 43BC4 800687C4 00601021 */   addu     $v0, $v1, $zero
/* 43BC8 800687C8 A5230000 */  sh        $v1, ($t1)
.L800687CC:
/* 43BCC 800687CC 03E00008 */  jr        $ra
/* 43BD0 800687D0 00001021 */   addu     $v0, $zero, $zero
/* 43BD4 800687D4 00000000 */  nop       
/* 43BD8 800687D8 00000000 */  nop       
/* 43BDC 800687DC 00000000 */  nop       
