.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E555C
/* 106DDC 802E555C 3C02802F */  lui       $v0, 0x802f
/* 106DE0 802E5560 8C42B3C0 */  lw        $v0, -0x4c40($v0)
/* 106DE4 802E5564 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106DE8 802E5568 1040000C */  beqz      $v0, .L802E559C
/* 106DEC 802E556C AFBF0010 */   sw       $ra, 0x10($sp)
/* 106DF0 802E5570 0C043F5A */  jal       func_8010FD68
/* 106DF4 802E5574 00000000 */   nop      
/* 106DF8 802E5578 0C009C22 */  jal       func_80027088
/* 106DFC 802E557C 0000202D */   daddu    $a0, $zero, $zero
/* 106E00 802E5580 3C02800A */  lui       $v0, 0x800a
/* 106E04 802E5584 2442A650 */  addiu     $v0, $v0, -0x59b0
/* 106E08 802E5588 8C430000 */  lw        $v1, ($v0)
/* 106E0C 802E558C 2404FFBF */  addiu     $a0, $zero, -0x41
/* 106E10 802E5590 00641824 */  and       $v1, $v1, $a0
/* 106E14 802E5594 0C038069 */  jal       enable_player_input
/* 106E18 802E5598 AC430000 */   sw       $v1, ($v0)
.L802E559C:
/* 106E1C 802E559C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 106E20 802E55A0 03E00008 */  jr        $ra
/* 106E24 802E55A4 27BD0018 */   addiu    $sp, $sp, 0x18
