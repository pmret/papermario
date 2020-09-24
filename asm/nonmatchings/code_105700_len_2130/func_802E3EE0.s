.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E3EE0
/* 105760 802E3EE0 9082000B */  lbu       $v0, 0xb($a0)
/* 105764 802E3EE4 2C4200FF */  sltiu     $v0, $v0, 0xff
/* 105768 802E3EE8 10400006 */  beqz      $v0, .L802E3F04
/* 10576C 802E3EEC 2483000B */   addiu    $v1, $a0, 0xb
/* 105770 802E3EF0 9084000B */  lbu       $a0, 0xb($a0)
/* 105774 802E3EF4 14800002 */  bnez      $a0, .L802E3F00
/* 105778 802E3EF8 24820020 */   addiu    $v0, $a0, 0x20
/* 10577C 802E3EFC 2482001F */  addiu     $v0, $a0, 0x1f
.L802E3F00:
/* 105780 802E3F00 A0620000 */  sb        $v0, ($v1)
.L802E3F04:
/* 105784 802E3F04 03E00008 */  jr        $ra
/* 105788 802E3F08 00000000 */   nop      
