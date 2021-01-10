.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A14D4_71DC44
/* 71DC44 802A14D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 71DC48 802A14D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 71DC4C 802A14DC 0080802D */  daddu     $s0, $a0, $zero
/* 71DC50 802A14E0 10A00003 */  beqz      $a1, .L802A14F0
/* 71DC54 802A14E4 AFBF0014 */   sw       $ra, 0x14($sp)
/* 71DC58 802A14E8 2402000A */  addiu     $v0, $zero, 0xa
/* 71DC5C 802A14EC AE020070 */  sw        $v0, 0x70($s0)
.L802A14F0:
/* 71DC60 802A14F0 0000202D */  daddu     $a0, $zero, $zero
/* 71DC64 802A14F4 0080282D */  daddu     $a1, $a0, $zero
/* 71DC68 802A14F8 8E070070 */  lw        $a3, 0x70($s0)
/* 71DC6C 802A14FC 0080302D */  daddu     $a2, $a0, $zero
/* 71DC70 802A1500 00073900 */  sll       $a3, $a3, 4
/* 71DC74 802A1504 0C046F97 */  jal       set_background_color_blend
/* 71DC78 802A1508 30E700F0 */   andi     $a3, $a3, 0xf0
/* 71DC7C 802A150C 8E020070 */  lw        $v0, 0x70($s0)
/* 71DC80 802A1510 2442FFFF */  addiu     $v0, $v0, -1
/* 71DC84 802A1514 10400003 */  beqz      $v0, .L802A1524
/* 71DC88 802A1518 AE020070 */   sw       $v0, 0x70($s0)
/* 71DC8C 802A151C 080A854F */  j         .L802A153C
/* 71DC90 802A1520 0000102D */   daddu    $v0, $zero, $zero
.L802A1524:
/* 71DC94 802A1524 0000202D */  daddu     $a0, $zero, $zero
/* 71DC98 802A1528 0080282D */  daddu     $a1, $a0, $zero
/* 71DC9C 802A152C 0080302D */  daddu     $a2, $a0, $zero
/* 71DCA0 802A1530 0C046F97 */  jal       set_background_color_blend
/* 71DCA4 802A1534 0080382D */   daddu    $a3, $a0, $zero
/* 71DCA8 802A1538 24020002 */  addiu     $v0, $zero, 2
.L802A153C:
/* 71DCAC 802A153C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 71DCB0 802A1540 8FB00010 */  lw        $s0, 0x10($sp)
/* 71DCB4 802A1544 03E00008 */  jr        $ra
/* 71DCB8 802A1548 27BD0018 */   addiu    $sp, $sp, 0x18
/* 71DCBC 802A154C 00000000 */  nop       
