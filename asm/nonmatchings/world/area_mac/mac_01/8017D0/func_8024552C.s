.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024552C
/* 805DAC 8024552C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 805DB0 80245530 AFBF0010 */  sw        $ra, 0x10($sp)
/* 805DB4 80245534 0C03BCE9 */  jal       func_800EF3A4
/* 805DB8 80245538 00000000 */   nop      
/* 805DBC 8024553C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 805DC0 80245540 24020002 */  addiu     $v0, $zero, 2
/* 805DC4 80245544 03E00008 */  jr        $ra
/* 805DC8 80245548 27BD0018 */   addiu    $sp, $sp, 0x18
/* 805DCC 8024554C 00000000 */  nop       
