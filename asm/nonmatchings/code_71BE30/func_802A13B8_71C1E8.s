.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A13B8_71C1E8
/* 71C1E8 802A13B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 71C1EC 802A13BC AFB00010 */  sw        $s0, 0x10($sp)
/* 71C1F0 802A13C0 0080802D */  daddu     $s0, $a0, $zero
/* 71C1F4 802A13C4 10A00003 */  beqz      $a1, .L802A13D4
/* 71C1F8 802A13C8 AFBF0014 */   sw       $ra, 0x14($sp)
/* 71C1FC 802A13CC 24020014 */  addiu     $v0, $zero, 0x14
/* 71C200 802A13D0 AE020070 */  sw        $v0, 0x70($s0)
.L802A13D4:
/* 71C204 802A13D4 0000202D */  daddu     $a0, $zero, $zero
/* 71C208 802A13D8 0080282D */  daddu     $a1, $a0, $zero
/* 71C20C 802A13DC 8E020070 */  lw        $v0, 0x70($s0)
/* 71C210 802A13E0 0080302D */  daddu     $a2, $a0, $zero
/* 71C214 802A13E4 00023880 */  sll       $a3, $v0, 2
/* 71C218 802A13E8 00E23821 */  addu      $a3, $a3, $v0
/* 71C21C 802A13EC 00073840 */  sll       $a3, $a3, 1
/* 71C220 802A13F0 0C046F97 */  jal       set_background_color_blend
/* 71C224 802A13F4 30E700FE */   andi     $a3, $a3, 0xfe
/* 71C228 802A13F8 8E020070 */  lw        $v0, 0x70($s0)
/* 71C22C 802A13FC 2442FFFF */  addiu     $v0, $v0, -1
/* 71C230 802A1400 10400003 */  beqz      $v0, .L802A1410
/* 71C234 802A1404 AE020070 */   sw       $v0, 0x70($s0)
/* 71C238 802A1408 080A850A */  j         .L802A1428
/* 71C23C 802A140C 0000102D */   daddu    $v0, $zero, $zero
.L802A1410:
/* 71C240 802A1410 0000202D */  daddu     $a0, $zero, $zero
/* 71C244 802A1414 0080282D */  daddu     $a1, $a0, $zero
/* 71C248 802A1418 0080302D */  daddu     $a2, $a0, $zero
/* 71C24C 802A141C 0C046F97 */  jal       set_background_color_blend
/* 71C250 802A1420 0080382D */   daddu    $a3, $a0, $zero
/* 71C254 802A1424 24020002 */  addiu     $v0, $zero, 2
.L802A1428:
/* 71C258 802A1428 8FBF0014 */  lw        $ra, 0x14($sp)
/* 71C25C 802A142C 8FB00010 */  lw        $s0, 0x10($sp)
/* 71C260 802A1430 03E00008 */  jr        $ra
/* 71C264 802A1434 27BD0018 */   addiu    $sp, $sp, 0x18
/* 71C268 802A1438 00000000 */  nop
/* 71C26C 802A143C 00000000 */  nop
