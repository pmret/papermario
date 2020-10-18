.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDBBC
/* 317ADC 802BDBBC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 317AE0 802BDBC0 AFB10014 */  sw        $s1, 0x14($sp)
/* 317AE4 802BDBC4 0080882D */  daddu     $s1, $a0, $zero
/* 317AE8 802BDBC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 317AEC 802BDBCC 3C108011 */  lui       $s0, %hi(D_8010EBB0)
/* 317AF0 802BDBD0 2610EBB0 */  addiu     $s0, $s0, %lo(D_8010EBB0)
/* 317AF4 802BDBD4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 317AF8 802BDBD8 AFB20018 */  sw        $s2, 0x18($sp)
/* 317AFC 802BDBDC 82020000 */  lb        $v0, ($s0)
/* 317B00 802BDBE0 1040000D */  beqz      $v0, .L802BDC18
/* 317B04 802BDBE4 0200902D */   daddu    $s2, $s0, $zero
/* 317B08 802BDBE8 0C009C22 */  jal       func_80027088
/* 317B0C 802BDBEC 0000202D */   daddu    $a0, $zero, $zero
/* 317B10 802BDBF0 0C038069 */  jal       enable_player_input
/* 317B14 802BDBF4 00000000 */   nop      
/* 317B18 802BDBF8 0C0B4312 */  jal       CancelMessageAndBlock
/* 317B1C 802BDBFC 00000000 */   nop      
/* 317B20 802BDC00 0C03BD17 */  jal       clear_partner_move_history
/* 317B24 802BDC04 0220202D */   daddu    $a0, $s1, $zero
/* 317B28 802BDC08 0220202D */  daddu     $a0, $s1, $zero
/* 317B2C 802BDC0C A2000000 */  sb        $zero, ($s0)
/* 317B30 802BDC10 0C00EB6B */  jal       disable_npc_blur
/* 317B34 802BDC14 A2000003 */   sb       $zero, 3($s0)
.L802BDC18:
/* 317B38 802BDC18 24020001 */  addiu     $v0, $zero, 1
/* 317B3C 802BDC1C A2420003 */  sb        $v0, 3($s2)
/* 317B40 802BDC20 8FBF001C */  lw        $ra, 0x1c($sp)
/* 317B44 802BDC24 8FB20018 */  lw        $s2, 0x18($sp)
/* 317B48 802BDC28 8FB10014 */  lw        $s1, 0x14($sp)
/* 317B4C 802BDC2C 8FB00010 */  lw        $s0, 0x10($sp)
/* 317B50 802BDC30 03E00008 */  jr        $ra
/* 317B54 802BDC34 27BD0020 */   addiu    $sp, $sp, 0x20
/* 317B58 802BDC38 00000000 */  nop       
/* 317B5C 802BDC3C 00000000 */  nop       
