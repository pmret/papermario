.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E54CC
/* 106D4C 802E54CC 3C028011 */  lui       $v0, %hi(gPlayerData+0x1C)
/* 106D50 802E54D0 9042F2AC */  lbu       $v0, %lo(gPlayerData+0x1C)($v0)
/* 106D54 802E54D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106D58 802E54D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 106D5C 802E54DC 0080802D */  daddu     $s0, $a0, $zero
/* 106D60 802E54E0 14400018 */  bnez      $v0, .L802E5544
/* 106D64 802E54E4 AFBF0014 */   sw       $ra, 0x14($sp)
/* 106D68 802E54E8 3C04F840 */  lui       $a0, 0xf840
/* 106D6C 802E54EC 0C05152F */  jal       get_global_flag
/* 106D70 802E54F0 34845BE0 */   ori      $a0, $a0, 0x5be0
/* 106D74 802E54F4 14400013 */  bnez      $v0, .L802E5544
/* 106D78 802E54F8 3C04001D */   lui      $a0, 0x1d
/* 106D7C 802E54FC 34840001 */  ori       $a0, $a0, 1
/* 106D80 802E5500 3C05802F */  lui       $a1, %hi(D_802EB3C0)
/* 106D84 802E5504 24A5B3C0 */  addiu     $a1, $a1, %lo(D_802EB3C0)
/* 106D88 802E5508 0C049640 */  jal       load_string
/* 106D8C 802E550C ACA00000 */   sw       $zero, ($a1)
/* 106D90 802E5510 0C009C22 */  jal       func_80027088
/* 106D94 802E5514 24040001 */   addiu    $a0, $zero, 1
/* 106D98 802E5518 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 106D9C 802E551C 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 106DA0 802E5520 8C620000 */  lw        $v0, ($v1)
/* 106DA4 802E5524 34420040 */  ori       $v0, $v0, 0x40
/* 106DA8 802E5528 0C03805E */  jal       disable_player_input
/* 106DAC 802E552C AC620000 */   sw       $v0, ($v1)
/* 106DB0 802E5530 3C04F840 */  lui       $a0, 0xf840
/* 106DB4 802E5534 0C051514 */  jal       set_global_flag
/* 106DB8 802E5538 34845BE0 */   ori      $a0, $a0, 0x5be0
/* 106DBC 802E553C 080B9553 */  j         .L802E554C
/* 106DC0 802E5540 00000000 */   nop      
.L802E5544:
/* 106DC4 802E5544 0C043F5A */  jal       func_8010FD68
/* 106DC8 802E5548 0200202D */   daddu    $a0, $s0, $zero
.L802E554C:
/* 106DCC 802E554C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 106DD0 802E5550 8FB00010 */  lw        $s0, 0x10($sp)
/* 106DD4 802E5554 03E00008 */  jr        $ra
/* 106DD8 802E5558 27BD0018 */   addiu    $sp, $sp, 0x18
