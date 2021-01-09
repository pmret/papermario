.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F8C_DE341C
/* DE341C 80240F8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DE3420 80240F90 AFBF0010 */  sw        $ra, 0x10($sp)
/* DE3424 80240F94 8C82000C */  lw        $v0, 0xc($a0)
/* DE3428 80240F98 0C0B1EAF */  jal       get_variable
/* DE342C 80240F9C 8C450000 */   lw       $a1, ($v0)
/* DE3430 80240FA0 0040182D */  daddu     $v1, $v0, $zero
/* DE3434 80240FA4 10600012 */  beqz      $v1, .L80240FF0
/* DE3438 80240FA8 0000202D */   daddu    $a0, $zero, $zero
/* DE343C 80240FAC 8C620000 */  lw        $v0, ($v1)
/* DE3440 80240FB0 5040000A */  beql      $v0, $zero, .L80240FDC
/* DE3444 80240FB4 00041080 */   sll      $v0, $a0, 2
/* DE3448 80240FB8 3C058024 */  lui       $a1, %hi(func_80243220_DC04D0)
/* DE344C 80240FBC 24A53220 */  addiu     $a1, $a1, %lo(func_80243220_DC04D0)
.L80240FC0:
/* DE3450 80240FC0 24630004 */  addiu     $v1, $v1, 4
/* DE3454 80240FC4 24840001 */  addiu     $a0, $a0, 1
/* DE3458 80240FC8 ACA20000 */  sw        $v0, ($a1)
/* DE345C 80240FCC 8C620000 */  lw        $v0, ($v1)
/* DE3460 80240FD0 1440FFFB */  bnez      $v0, .L80240FC0
/* DE3464 80240FD4 24A50004 */   addiu    $a1, $a1, 4
/* DE3468 80240FD8 00041080 */  sll       $v0, $a0, 2
.L80240FDC:
/* DE346C 80240FDC 3C018024 */  lui       $at, %hi(func_80243220_DC04D0)
/* DE3470 80240FE0 00220821 */  addu      $at, $at, $v0
/* DE3474 80240FE4 AC203220 */  sw        $zero, %lo(func_80243220_DC04D0)($at)
/* DE3478 80240FE8 08090406 */  j         .L80241018
/* DE347C 80240FEC 00000000 */   nop      
.L80240FF0:
/* DE3480 80240FF0 3C038024 */  lui       $v1, %hi(func_80243220_DC04D0)
/* DE3484 80240FF4 24633220 */  addiu     $v1, $v1, %lo(func_80243220_DC04D0)
/* DE3488 80240FF8 0060282D */  daddu     $a1, $v1, $zero
.L80240FFC:
/* DE348C 80240FFC 24820080 */  addiu     $v0, $a0, 0x80
/* DE3490 80241000 AC620000 */  sw        $v0, ($v1)
/* DE3494 80241004 24630004 */  addiu     $v1, $v1, 4
/* DE3498 80241008 24840001 */  addiu     $a0, $a0, 1
/* DE349C 8024100C 2882005B */  slti      $v0, $a0, 0x5b
/* DE34A0 80241010 1440FFFA */  bnez      $v0, .L80240FFC
/* DE34A4 80241014 ACA0016C */   sw       $zero, 0x16c($a1)
.L80241018:
/* DE34A8 80241018 8FBF0010 */  lw        $ra, 0x10($sp)
/* DE34AC 8024101C 24020002 */  addiu     $v0, $zero, 2
/* DE34B0 80241020 03E00008 */  jr        $ra
/* DE34B4 80241024 27BD0018 */   addiu    $sp, $sp, 0x18
