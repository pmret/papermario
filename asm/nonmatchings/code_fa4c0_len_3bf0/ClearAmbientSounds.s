.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ClearAmbientSounds
/* FAA98 802D60E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FAA9C 802D60EC AFBF0010 */  sw        $ra, 0x10($sp)
/* FAAA0 802D60F0 8C82000C */  lw        $v0, 0xc($a0)
/* FAAA4 802D60F4 0C0B1EAF */  jal       get_variable
/* FAAA8 802D60F8 8C450000 */   lw       $a1, ($v0)
/* FAAAC 802D60FC 2404FFFF */  addiu     $a0, $zero, -1
/* FAAB0 802D6100 0C051CDA */  jal       play_ambient_sounds
/* FAAB4 802D6104 0040282D */   daddu    $a1, $v0, $zero
/* FAAB8 802D6108 0002102B */  sltu      $v0, $zero, $v0
/* FAABC 802D610C 8FBF0010 */  lw        $ra, 0x10($sp)
/* FAAC0 802D6110 00021040 */  sll       $v0, $v0, 1
/* FAAC4 802D6114 03E00008 */  jr        $ra
/* FAAC8 802D6118 27BD0018 */   addiu    $sp, $sp, 0x18
