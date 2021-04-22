.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSpTaskStartGo
/* 4101C 80065C1C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41020 80065C20 AFBF0010 */  sw        $ra, 0x10($sp)
.L80065C24:
/* 41024 80065C24 0C01B1B0 */  jal       osSpDeviceBusy
/* 41028 80065C28 00000000 */   nop
/* 4102C 80065C2C 1440FFFD */  bnez      $v0, .L80065C24
/* 41030 80065C30 00000000 */   nop
/* 41034 80065C34 0C01B1BC */  jal       osSpSetStatus
/* 41038 80065C38 24040125 */   addiu    $a0, $zero, 0x125
/* 4103C 80065C3C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 41040 80065C40 03E00008 */  jr        $ra
/* 41044 80065C44 27BD0018 */   addiu    $sp, $sp, 0x18
/* 41048 80065C48 00000000 */  nop
/* 4104C 80065C4C 00000000 */  nop
