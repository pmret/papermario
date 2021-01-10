.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1378_716FD8
/* 716FD8 802A1378 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 716FDC 802A137C AFB00010 */  sw        $s0, 0x10($sp)
/* 716FE0 802A1380 0080802D */  daddu     $s0, $a0, $zero
/* 716FE4 802A1384 10A00003 */  beqz      $a1, .L802A1394
/* 716FE8 802A1388 AFBF0014 */   sw       $ra, 0x14($sp)
/* 716FEC 802A138C 24020014 */  addiu     $v0, $zero, 0x14
/* 716FF0 802A1390 AE020070 */  sw        $v0, 0x70($s0)
.L802A1394:
/* 716FF4 802A1394 0000202D */  daddu     $a0, $zero, $zero
/* 716FF8 802A1398 0080282D */  daddu     $a1, $a0, $zero
/* 716FFC 802A139C 8E020070 */  lw        $v0, 0x70($s0)
/* 717000 802A13A0 0080302D */  daddu     $a2, $a0, $zero
/* 717004 802A13A4 00023880 */  sll       $a3, $v0, 2
/* 717008 802A13A8 00E23821 */  addu      $a3, $a3, $v0
/* 71700C 802A13AC 00073840 */  sll       $a3, $a3, 1
/* 717010 802A13B0 0C046F97 */  jal       set_background_color_blend
/* 717014 802A13B4 30E700FE */   andi     $a3, $a3, 0xfe
/* 717018 802A13B8 8E020070 */  lw        $v0, 0x70($s0)
/* 71701C 802A13BC 2442FFFF */  addiu     $v0, $v0, -1
/* 717020 802A13C0 10400003 */  beqz      $v0, .L802A13D0
/* 717024 802A13C4 AE020070 */   sw       $v0, 0x70($s0)
/* 717028 802A13C8 080A84FA */  j         .L802A13E8
/* 71702C 802A13CC 0000102D */   daddu    $v0, $zero, $zero
.L802A13D0:
/* 717030 802A13D0 0000202D */  daddu     $a0, $zero, $zero
/* 717034 802A13D4 0080282D */  daddu     $a1, $a0, $zero
/* 717038 802A13D8 0080302D */  daddu     $a2, $a0, $zero
/* 71703C 802A13DC 0C046F97 */  jal       set_background_color_blend
/* 717040 802A13E0 0080382D */   daddu    $a3, $a0, $zero
/* 717044 802A13E4 24020002 */  addiu     $v0, $zero, 2
.L802A13E8:
/* 717048 802A13E8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 71704C 802A13EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 717050 802A13F0 03E00008 */  jr        $ra
/* 717054 802A13F4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 717058 802A13F8 00000000 */  nop       
/* 71705C 802A13FC 00000000 */  nop       
