.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel remove_status_icon_boost_partner
/* 232DC 80047EDC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 232E0 80047EE0 00041040 */  sll       $v0, $a0, 1
/* 232E4 80047EE4 00441021 */  addu      $v0, $v0, $a0
/* 232E8 80047EE8 00021080 */  sll       $v0, $v0, 2
/* 232EC 80047EEC 00441023 */  subu      $v0, $v0, $a0
/* 232F0 80047EF0 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 232F4 80047EF4 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 232F8 80047EF8 00021100 */  sll       $v0, $v0, 4
/* 232FC 80047EFC AFBF0010 */  sw        $ra, 0x10($sp)
/* 23300 80047F00 00621821 */  addu      $v1, $v1, $v0
/* 23304 80047F04 80620090 */  lb        $v0, 0x90($v1)
/* 23308 80047F08 10400004 */  beqz      $v0, .L80047F1C
/* 2330C 80047F0C 00000000 */   nop
/* 23310 80047F10 8C640094 */  lw        $a0, 0x94($v1)
/* 23314 80047F14 0C05123D */  jal       hud_element_free
/* 23318 80047F18 A0600090 */   sb       $zero, 0x90($v1)
.L80047F1C:
/* 2331C 80047F1C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 23320 80047F20 03E00008 */  jr        $ra
/* 23324 80047F24 27BD0018 */   addiu    $sp, $sp, 0x18
