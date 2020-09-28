.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContPakMgrInit
/* 3AAB0 8005F6B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3AAB4 8005F6B4 3C048009 */  lui       $a0, 0x8009
/* 3AAB8 8005F6B8 24843CD0 */  addiu     $a0, $a0, 0x3cd0
/* 3AABC 8005F6BC AFBF0010 */  sw        $ra, 0x10($sp)
/* 3AAC0 8005F6C0 0C0180FC */  jal       nuSiCallBackAdd
/* 3AAC4 8005F6C4 00000000 */   nop      
/* 3AAC8 8005F6C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3AACC 8005F6CC 03E00008 */  jr        $ra
/* 3AAD0 8005F6D0 27BD0018 */   addiu    $sp, $sp, 0x18
