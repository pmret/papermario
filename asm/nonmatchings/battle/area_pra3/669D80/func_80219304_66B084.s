.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219304_66B084
/* 66B084 80219304 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 66B088 80219308 AFBF0010 */  sw        $ra, 0x10($sp)
/* 66B08C 8021930C 0C09A75B */  jal       get_actor
/* 66B090 80219310 8C840148 */   lw       $a0, 0x148($a0)
/* 66B094 80219314 8C440090 */  lw        $a0, 0x90($v0)
/* 66B098 80219318 8C830014 */  lw        $v1, 0x14($a0)
/* 66B09C 8021931C 10600004 */  beqz      $v1, .L80219330
/* 66B0A0 80219320 AC800000 */   sw       $zero, ($a0)
/* 66B0A4 80219324 8C620000 */  lw        $v0, ($v1)
/* 66B0A8 80219328 34420010 */  ori       $v0, $v0, 0x10
/* 66B0AC 8021932C AC620000 */  sw        $v0, ($v1)
.L80219330:
/* 66B0B0 80219330 8C830018 */  lw        $v1, 0x18($a0)
/* 66B0B4 80219334 10600004 */  beqz      $v1, .L80219348
/* 66B0B8 80219338 00000000 */   nop
/* 66B0BC 8021933C 8C620000 */  lw        $v0, ($v1)
/* 66B0C0 80219340 34420010 */  ori       $v0, $v0, 0x10
/* 66B0C4 80219344 AC620000 */  sw        $v0, ($v1)
.L80219348:
/* 66B0C8 80219348 8FBF0010 */  lw        $ra, 0x10($sp)
/* 66B0CC 8021934C 24020002 */  addiu     $v0, $zero, 2
/* 66B0D0 80219350 03E00008 */  jr        $ra
/* 66B0D4 80219354 27BD0018 */   addiu    $sp, $sp, 0x18
