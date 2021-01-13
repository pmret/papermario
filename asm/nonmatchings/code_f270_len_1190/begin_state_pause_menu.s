.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel begin_state_pause_menu
/* FD40 80034940 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FD44 80034944 AFBF0010 */  sw        $ra, 0x10($sp)
/* FD48 80034948 3C01800A */  lui       $at, %hi(D_800A0921)
/* FD4C 8003494C A0200921 */  sb        $zero, %lo(D_800A0921)($at)
/* FD50 80034950 3C01800A */  lui       $at, %hi(D_800A0922)
/* FD54 80034954 A4200922 */  sh        $zero, %lo(D_800A0922)($at)
/* FD58 80034958 0C03805E */  jal       disable_player_input
/* FD5C 8003495C 00000000 */   nop
/* FD60 80034960 0C009C22 */  jal       func_80027088
/* FD64 80034964 24040003 */   addiu    $a0, $zero, 3
/* FD68 80034968 0C051FB1 */  jal       func_80147EC4
/* FD6C 8003496C 24040002 */   addiu    $a0, $zero, 2
/* FD70 80034970 8FBF0010 */  lw        $ra, 0x10($sp)
/* FD74 80034974 03E00008 */  jr        $ra
/* FD78 80034978 27BD0018 */   addiu    $sp, $sp, 0x18
