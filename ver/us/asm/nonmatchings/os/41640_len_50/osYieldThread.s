.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osYieldThread
/* 41640 80066240 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41644 80066244 AFBF0014 */  sw        $ra, 0x14($sp)
/* 41648 80066248 0C01ACD8 */  jal       __osDisableInt
/* 4164C 8006624C AFB00010 */   sw       $s0, 0x10($sp)
/* 41650 80066250 3C038009 */  lui       $v1, %hi(__osRunningThread)
/* 41654 80066254 8C634660 */  lw        $v1, %lo(__osRunningThread)($v1)
/* 41658 80066258 3C048009 */  lui       $a0, %hi(__osRunQueue)
/* 4165C 8006625C 24844658 */  addiu     $a0, $a0, %lo(__osRunQueue)
/* 41660 80066260 24050002 */  addiu     $a1, $zero, 2
/* 41664 80066264 00408021 */  addu      $s0, $v0, $zero
/* 41668 80066268 0C01AC1B */  jal       __osEnqueueAndYield
/* 4166C 8006626C A4650010 */   sh       $a1, 0x10($v1)
/* 41670 80066270 0C01ACF4 */  jal       __osRestoreInt
/* 41674 80066274 02002021 */   addu     $a0, $s0, $zero
/* 41678 80066278 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4167C 8006627C 8FB00010 */  lw        $s0, 0x10($sp)
/* 41680 80066280 03E00008 */  jr        $ra
/* 41684 80066284 27BD0018 */   addiu    $sp, $sp, 0x18
/* 41688 80066288 00000000 */  nop
/* 4168C 8006628C 00000000 */  nop
