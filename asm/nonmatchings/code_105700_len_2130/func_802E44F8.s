.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E44F8
/* 105D78 802E44F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 105D7C 802E44FC AFBF0010 */  sw        $ra, 0x10($sp)
/* 105D80 802E4500 0C03805E */  jal       disable_player_input
/* 105D84 802E4504 00000000 */   nop      
/* 105D88 802E4508 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 105D8C 802E450C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 105D90 802E4510 8C430000 */  lw        $v1, ($v0)
/* 105D94 802E4514 3C040080 */  lui       $a0, 0x80
/* 105D98 802E4518 AC400054 */  sw        $zero, 0x54($v0)
/* 105D9C 802E451C 00641825 */  or        $v1, $v1, $a0
/* 105DA0 802E4520 24040008 */  addiu     $a0, $zero, 8
/* 105DA4 802E4524 0C039769 */  jal       set_action_state
/* 105DA8 802E4528 AC430000 */   sw       $v1, ($v0)
/* 105DAC 802E452C 0C038C1B */  jal       gravity_use_fall_parms
/* 105DB0 802E4530 00000000 */   nop      
/* 105DB4 802E4534 8FBF0010 */  lw        $ra, 0x10($sp)
/* 105DB8 802E4538 03E00008 */  jr        $ra
/* 105DBC 802E453C 27BD0018 */   addiu    $sp, $sp, 0x18
