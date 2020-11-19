.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_badges_try_remove
/* 13A5F0 802472B0 3C068011 */  lui       $a2, %hi(gPlayerData+0x208)
/* 13A5F4 802472B4 24C6F498 */  addiu     $a2, $a2, %lo(gPlayerData+0x208)
/* 13A5F8 802472B8 00C0182D */  daddu     $v1, $a2, $zero
/* 13A5FC 802472BC 00042400 */  sll       $a0, $a0, 0x10
/* 13A600 802472C0 00042403 */  sra       $a0, $a0, 0x10
/* 13A604 802472C4 24027FFF */  addiu     $v0, $zero, 0x7fff
/* 13A608 802472C8 14820005 */  bne       $a0, $v0, .L802472E0
/* 13A60C 802472CC 0000382D */   daddu    $a3, $zero, $zero
/* 13A610 802472D0 03E00008 */  jr        $ra
/* 13A614 802472D4 00E0102D */   daddu    $v0, $a3, $zero
.L802472D8:
/* 13A618 802472D8 08091CC5 */  j         .L80247314
/* 13A61C 802472DC 24070001 */   addiu    $a3, $zero, 1
.L802472E0:
/* 13A620 802472E0 0000282D */  daddu     $a1, $zero, $zero
.L802472E4:
/* 13A624 802472E4 84620000 */  lh        $v0, ($v1)
/* 13A628 802472E8 5082FFFB */  beql      $a0, $v0, .L802472D8
/* 13A62C 802472EC 0060302D */   daddu    $a2, $v1, $zero
/* 13A630 802472F0 24A50001 */  addiu     $a1, $a1, 1
/* 13A634 802472F4 28A20040 */  slti      $v0, $a1, 0x40
/* 13A638 802472F8 1440FFFA */  bnez      $v0, .L802472E4
/* 13A63C 802472FC 24630002 */   addiu    $v1, $v1, 2
/* 13A640 80247300 08091CC6 */  j         .L80247318
/* 13A644 80247304 28A2003F */   slti     $v0, $a1, 0x3f
.L80247308:
/* 13A648 80247308 94620002 */  lhu       $v0, 2($v1)
/* 13A64C 8024730C A4620000 */  sh        $v0, ($v1)
/* 13A650 80247310 24630002 */  addiu     $v1, $v1, 2
.L80247314:
/* 13A654 80247314 28A2003F */  slti      $v0, $a1, 0x3f
.L80247318:
/* 13A658 80247318 5440FFFB */  bnel      $v0, $zero, .L80247308
/* 13A65C 8024731C 24A50001 */   addiu    $a1, $a1, 1
/* 13A660 80247320 A4600000 */  sh        $zero, ($v1)
/* 13A664 80247324 84C20000 */  lh        $v0, ($a2)
/* 13A668 80247328 50400001 */  beql      $v0, $zero, .L80247330
/* 13A66C 8024732C 24070002 */   addiu    $a3, $zero, 2
.L80247330:
/* 13A670 80247330 03E00008 */  jr        $ra
/* 13A674 80247334 00E0102D */   daddu    $v0, $a3, $zero
