.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8028236C
/* 7E31EC 8028236C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E31F0 80282370 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7E31F4 80282374 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E31F8 80282378 8C82000C */  lw        $v0, 0xc($a0)
/* 7E31FC 8028237C 8C450000 */  lw        $a1, ($v0)
/* 7E3200 80282380 0C0B1EAF */  jal       evt_get_variable
/* 7E3204 80282384 8C900074 */   lw       $s0, 0x74($a0)
/* 7E3208 80282388 00021080 */  sll       $v0, $v0, 2
/* 7E320C 8028238C 02028021 */  addu      $s0, $s0, $v0
/* 7E3210 80282390 0C0B1059 */  jal       does_script_exist
/* 7E3214 80282394 8E04004C */   lw       $a0, 0x4c($s0)
/* 7E3218 80282398 2C420001 */  sltiu     $v0, $v0, 1
/* 7E321C 8028239C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7E3220 802823A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E3224 802823A4 00021040 */  sll       $v0, $v0, 1
/* 7E3228 802823A8 03E00008 */  jr        $ra
/* 7E322C 802823AC 27BD0018 */   addiu    $sp, $sp, 0x18
