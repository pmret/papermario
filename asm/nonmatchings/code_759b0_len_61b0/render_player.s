.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel render_player
/* 7A5E8 800E1138 3C028007 */  lui       $v0, 0x8007
/* 7A5EC 800E113C 8C42419C */  lw        $v0, 0x419c($v0)
/* 7A5F0 800E1140 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7A5F4 800E1144 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7A5F8 800E1148 80420078 */  lb        $v0, 0x78($v0)
/* 7A5FC 800E114C 14400003 */  bnez      $v0, .L800E115C
/* 7A600 800E1150 00000000 */   nop      
/* 7A604 800E1154 0C03845A */  jal       render_player_model
/* 7A608 800E1158 00000000 */   nop      
.L800E115C:
/* 7A60C 800E115C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7A610 800E1160 03E00008 */  jr        $ra
/* 7A614 800E1164 27BD0018 */   addiu    $sp, $sp, 0x18
