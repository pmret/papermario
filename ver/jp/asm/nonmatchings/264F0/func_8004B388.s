.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004B388
/* 26788 8004B388 90830164 */  lbu       $v1, 0x164($a0)
/* 2678C 8004B38C 90820163 */  lbu       $v0, 0x163($a0)
/* 26790 8004B390 8FA90010 */  lw        $t1, 0x10($sp)
/* 26794 8004B394 00621023 */  subu      $v0, $v1, $v0
/* 26798 8004B398 04420001 */  bltzl     $v0, .L8004B3A0
/* 2679C 8004B39C 24420010 */   addiu    $v0, $v0, 0x10
.L8004B3A0:
/* 267A0 8004B3A0 28420010 */  slti      $v0, $v0, 0x10
/* 267A4 8004B3A4 10400012 */  beqz      $v0, .L8004B3F0
/* 267A8 8004B3A8 0060402D */   daddu    $t0, $v1, $zero
/* 267AC 8004B3AC 00081880 */  sll       $v1, $t0, 2
/* 267B0 8004B3B0 00681821 */  addu      $v1, $v1, $t0
/* 267B4 8004B3B4 25080001 */  addiu     $t0, $t0, 1
/* 267B8 8004B3B8 00031840 */  sll       $v1, $v1, 1
/* 267BC 8004B3BC 00831821 */  addu      $v1, $a0, $v1
/* 267C0 8004B3C0 30A2BFFF */  andi      $v0, $a1, 0xbfff
/* 267C4 8004B3C4 A46200C2 */  sh        $v0, 0xc2($v1)
/* 267C8 8004B3C8 00051402 */  srl       $v0, $a1, 0x10
/* 267CC 8004B3CC 304203FF */  andi      $v0, $v0, 0x3ff
/* 267D0 8004B3D0 A46200C4 */  sh        $v0, 0xc4($v1)
/* 267D4 8004B3D4 2D020010 */  sltiu     $v0, $t0, 0x10
/* 267D8 8004B3D8 A46600C6 */  sh        $a2, 0xc6($v1)
/* 267DC 8004B3DC A46700C8 */  sh        $a3, 0xc8($v1)
/* 267E0 8004B3E0 14400002 */  bnez      $v0, .L8004B3EC
/* 267E4 8004B3E4 A06900CA */   sb       $t1, 0xca($v1)
/* 267E8 8004B3E8 0000402D */  daddu     $t0, $zero, $zero
.L8004B3EC:
/* 267EC 8004B3EC A0880164 */  sb        $t0, 0x164($a0)
.L8004B3F0:
/* 267F0 8004B3F0 03E00008 */  jr        $ra
/* 267F4 8004B3F4 00000000 */   nop
