.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004DC80
/* 29080 8004DC80 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 29084 8004DC84 AFA40010 */  sw        $a0, 0x10($sp)
/* 29088 8004DC88 27A40010 */  addiu     $a0, $sp, 0x10
/* 2908C 8004DC8C 0000282D */  daddu     $a1, $zero, $zero
/* 29090 8004DC90 AFBF0030 */  sw        $ra, 0x30($sp)
/* 29094 8004DC94 AFA00014 */  sw        $zero, 0x14($sp)
/* 29098 8004DC98 AFA00018 */  sw        $zero, 0x18($sp)
/* 2909C 8004DC9C AFA0001C */  sw        $zero, 0x1c($sp)
/* 290A0 8004DCA0 AFA00020 */  sw        $zero, 0x20($sp)
/* 290A4 8004DCA4 0C01372E */  jal       func_8004DCB8
/* 290A8 8004DCA8 AFA00024 */   sw       $zero, 0x24($sp)
/* 290AC 8004DCAC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 290B0 8004DCB0 03E00008 */  jr        $ra
/* 290B4 8004DCB4 27BD0038 */   addiu    $sp, $sp, 0x38
