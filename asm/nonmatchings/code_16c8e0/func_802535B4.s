.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802535B4
/* 181E94 802535B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 181E98 802535B8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 181E9C 802535BC 8C82000C */  lw        $v0, 0xc($a0)
/* 181EA0 802535C0 0C0B1EAF */  jal       get_variable
/* 181EA4 802535C4 8C450000 */   lw       $a1, ($v0)
/* 181EA8 802535C8 10400005 */  beqz      $v0, .L802535E0
/* 181EAC 802535CC 00000000 */   nop      
/* 181EB0 802535D0 0C03A6CC */  jal       decrement_status_menu_disabled
/* 181EB4 802535D4 00000000 */   nop      
/* 181EB8 802535D8 08094D7A */  j         .L802535E8
/* 181EBC 802535DC 00000000 */   nop      
.L802535E0:
/* 181EC0 802535E0 0C03A6D5 */  jal       increment_status_menu_disabled
/* 181EC4 802535E4 00000000 */   nop      
.L802535E8:
/* 181EC8 802535E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 181ECC 802535EC 24020002 */  addiu     $v0, $zero, 2
/* 181ED0 802535F0 03E00008 */  jr        $ra
/* 181ED4 802535F4 27BD0018 */   addiu    $sp, $sp, 0x18
