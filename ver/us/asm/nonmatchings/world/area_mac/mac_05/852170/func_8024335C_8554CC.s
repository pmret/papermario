.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024335C_8554CC
/* 8554CC 8024335C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8554D0 80243360 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8554D4 80243364 0C052B50 */  jal       func_8014AD40
/* 8554D8 80243368 00000000 */   nop
/* 8554DC 8024336C 2C420001 */  sltiu     $v0, $v0, 1
/* 8554E0 80243370 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8554E4 80243374 00021040 */  sll       $v0, $v0, 1
/* 8554E8 80243378 03E00008 */  jr        $ra
/* 8554EC 8024337C 27BD0018 */   addiu    $sp, $sp, 0x18
