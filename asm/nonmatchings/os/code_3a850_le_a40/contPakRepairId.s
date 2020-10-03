.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel contPakRepairId
/* 3ACFC 8005F8FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3AD00 8005F900 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3AD04 8005F904 8C82000C */  lw        $v0, 0xc($a0)
/* 3AD08 8005F908 0C01A518 */  jal       osPfsRepairId
/* 3AD0C 8005F90C 8C440000 */   lw       $a0, ($v0)
/* 3AD10 8005F910 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3AD14 8005F914 03E00008 */  jr        $ra
/* 3AD18 8005F918 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3AD1C 8005F91C 00000000 */  nop       
