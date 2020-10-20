.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241510_E13C70
/* E13C70 80241510 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E13C74 80241514 AFB00010 */  sw        $s0, 0x10($sp)
/* E13C78 80241518 0080802D */  daddu     $s0, $a0, $zero
/* E13C7C 8024151C 3C038011 */  lui       $v1, %hi(gPlayerData)
/* E13C80 80241520 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* E13C84 80241524 10A00005 */  beqz      $a1, .L8024153C
/* E13C88 80241528 AFBF0014 */   sw       $ra, 0x14($sp)
/* E13C8C 8024152C 9462032E */  lhu       $v0, 0x32e($v1)
/* E13C90 80241530 24420001 */  addiu     $v0, $v0, 1
/* E13C94 80241534 A462032E */  sh        $v0, 0x32e($v1)
/* E13C98 80241538 AE000070 */  sw        $zero, 0x70($s0)
.L8024153C:
/* E13C9C 8024153C 0C03A830 */  jal       add_coins
/* E13CA0 80241540 2404FFFF */   addiu    $a0, $zero, -1
/* E13CA4 80241544 0C05272D */  jal       play_sound
/* E13CA8 80241548 24040211 */   addiu    $a0, $zero, 0x211
/* E13CAC 8024154C 8E030070 */  lw        $v1, 0x70($s0)
/* E13CB0 80241550 24630001 */  addiu     $v1, $v1, 1
/* E13CB4 80241554 3862000A */  xori      $v0, $v1, 0xa
/* E13CB8 80241558 2C420001 */  sltiu     $v0, $v0, 1
/* E13CBC 8024155C AE030070 */  sw        $v1, 0x70($s0)
/* E13CC0 80241560 8FBF0014 */  lw        $ra, 0x14($sp)
/* E13CC4 80241564 8FB00010 */  lw        $s0, 0x10($sp)
/* E13CC8 80241568 00021040 */  sll       $v0, $v0, 1
/* E13CCC 8024156C 03E00008 */  jr        $ra
/* E13CD0 80241570 27BD0018 */   addiu    $sp, $sp, 0x18
