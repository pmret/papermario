.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219304_624EA4
/* 624EA4 80219304 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 624EA8 80219308 AFBF0010 */  sw        $ra, 0x10($sp)
/* 624EAC 8021930C 0C09A75B */  jal       get_actor
/* 624EB0 80219310 8C840148 */   lw       $a0, 0x148($a0)
/* 624EB4 80219314 8C440090 */  lw        $a0, 0x90($v0)
/* 624EB8 80219318 8C830014 */  lw        $v1, 0x14($a0)
/* 624EBC 8021931C 10600004 */  beqz      $v1, .L80219330
/* 624EC0 80219320 AC800000 */   sw       $zero, ($a0)
/* 624EC4 80219324 8C620000 */  lw        $v0, ($v1)
/* 624EC8 80219328 34420010 */  ori       $v0, $v0, 0x10
/* 624ECC 8021932C AC620000 */  sw        $v0, ($v1)
.L80219330:
/* 624ED0 80219330 8C830018 */  lw        $v1, 0x18($a0)
/* 624ED4 80219334 10600004 */  beqz      $v1, .L80219348
/* 624ED8 80219338 00000000 */   nop      
/* 624EDC 8021933C 8C620000 */  lw        $v0, ($v1)
/* 624EE0 80219340 34420010 */  ori       $v0, $v0, 0x10
/* 624EE4 80219344 AC620000 */  sw        $v0, ($v1)
.L80219348:
/* 624EE8 80219348 8FBF0010 */  lw        $ra, 0x10($sp)
/* 624EEC 8021934C 24020002 */  addiu     $v0, $zero, 2
/* 624EF0 80219350 03E00008 */  jr        $ra
/* 624EF4 80219354 27BD0018 */   addiu    $sp, $sp, 0x18
