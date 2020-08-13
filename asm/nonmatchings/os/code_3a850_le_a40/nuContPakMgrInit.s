.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuContPakMgrInit
/* 03AAB0 8005F6B0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03AAB4 8005F6B4 3C048009 */  lui   $a0, 0x8009
/* 03AAB8 8005F6B8 24843CD0 */  addiu $a0, $a0, 0x3cd0
/* 03AABC 8005F6BC AFBF0010 */  sw    $ra, 0x10($sp)
/* 03AAC0 8005F6C0 0C0180FC */  jal   nuSiCallBackAdd
/* 03AAC4 8005F6C4 00000000 */   nop   
/* 03AAC8 8005F6C8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03AACC 8005F6CC 03E00008 */  jr    $ra
/* 03AAD0 8005F6D0 27BD0018 */   addiu $sp, $sp, 0x18

