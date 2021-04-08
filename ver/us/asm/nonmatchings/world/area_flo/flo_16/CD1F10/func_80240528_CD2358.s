.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_16_UnkFunc19
/* CD2358 80240528 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* CD235C 8024052C 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* CD2360 80240530 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CD2364 80240534 AFBF0010 */  sw        $ra, 0x10($sp)
/* CD2368 80240538 00021100 */  sll       $v0, $v0, 4
/* CD236C 8024053C 3C048009 */  lui       $a0, %hi(D_8008EF20)
/* CD2370 80240540 00822021 */  addu      $a0, $a0, $v0
/* CD2374 80240544 8C84EF20 */  lw        $a0, %lo(D_8008EF20)($a0)
/* CD2378 80240548 0C0496CF */  jal       set_message_string
/* CD237C 8024054C 0000282D */   daddu    $a1, $zero, $zero
/* CD2380 80240550 8FBF0010 */  lw        $ra, 0x10($sp)
/* CD2384 80240554 24020002 */  addiu     $v0, $zero, 2
/* CD2388 80240558 03E00008 */  jr        $ra
/* CD238C 8024055C 27BD0018 */   addiu    $sp, $sp, 0x18
