.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800557A0
/* 30BA0 800557A0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30BA4 800557A4 AFA40010 */  sw        $a0, 0x10($sp)
/* 30BA8 800557A8 27A40010 */  addiu     $a0, $sp, 0x10
/* 30BAC 800557AC 0000282D */  daddu     $a1, $zero, $zero
/* 30BB0 800557B0 AFBF0030 */  sw        $ra, 0x30($sp)
/* 30BB4 800557B4 AFA00014 */  sw        $zero, 0x14($sp)
/* 30BB8 800557B8 AFA00018 */  sw        $zero, 0x18($sp)
/* 30BBC 800557BC AFA0001C */  sw        $zero, 0x1c($sp)
/* 30BC0 800557C0 AFA00020 */  sw        $zero, 0x20($sp)
/* 30BC4 800557C4 0C01365A */  jal       func_8004D968
/* 30BC8 800557C8 AFA00024 */   sw       $zero, 0x24($sp)
/* 30BCC 800557CC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30BD0 800557D0 03E00008 */  jr        $ra
/* 30BD4 800557D4 27BD0038 */   addiu    $sp, $sp, 0x38
