.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021837C_4B156C
/* 4B156C 8021837C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4B1570 80218380 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4B1574 80218384 8C82000C */  lw        $v0, 0xc($a0)
/* 4B1578 80218388 0C0B1EAF */  jal       get_variable
/* 4B157C 8021838C 8C450000 */   lw       $a1, ($v0)
/* 4B1580 80218390 0C09A75B */  jal       get_actor
/* 4B1584 80218394 0040202D */   daddu    $a0, $v0, $zero
/* 4B1588 80218398 C4440018 */  lwc1      $f4, 0x18($v0)
/* 4B158C 8021839C 3C014170 */  lui       $at, 0x4170
/* 4B1590 802183A0 44810000 */  mtc1      $at, $f0
/* 4B1594 802183A4 C4420054 */  lwc1      $f2, 0x54($v0)
/* 4B1598 802183A8 46002101 */  sub.s     $f4, $f4, $f0
/* 4B159C 802183AC E7A20010 */  swc1      $f2, 0x10($sp)
/* 4B15A0 802183B0 8C46001C */  lw        $a2, 0x1c($v0)
/* 4B15A4 802183B4 8C470020 */  lw        $a3, 0x20($v0)
/* 4B15A8 802183B8 44052000 */  mfc1      $a1, $f4
/* 4B15AC 802183BC 0C0990BC */  jal       play_movement_dust_effects
/* 4B15B0 802183C0 24040002 */   addiu    $a0, $zero, 2
/* 4B15B4 802183C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4B15B8 802183C8 24020002 */  addiu     $v0, $zero, 2
/* 4B15BC 802183CC 03E00008 */  jr        $ra
/* 4B15C0 802183D0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4B15C4 802183D4 00000000 */  nop
/* 4B15C8 802183D8 00000000 */  nop
/* 4B15CC 802183DC 00000000 */  nop
