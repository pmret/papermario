.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BD8_DDD408
/* DDD408 80240BD8 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* DDD40C 80240BDC 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* DDD410 80240BE0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DDD414 80240BE4 AFBF0010 */  sw        $ra, 0x10($sp)
/* DDD418 80240BE8 00021100 */  sll       $v0, $v0, 4
/* DDD41C 80240BEC 3C048009 */  lui       $a0, 0x8009
/* DDD420 80240BF0 00822021 */  addu      $a0, $a0, $v0
/* DDD424 80240BF4 8C84EF20 */  lw        $a0, -0x10e0($a0)
/* DDD428 80240BF8 0C0496CF */  jal       set_message_string
/* DDD42C 80240BFC 0000282D */   daddu    $a1, $zero, $zero
/* DDD430 80240C00 8FBF0010 */  lw        $ra, 0x10($sp)
/* DDD434 80240C04 24020002 */  addiu     $v0, $zero, 2
/* DDD438 80240C08 03E00008 */  jr        $ra
/* DDD43C 80240C0C 27BD0018 */   addiu    $sp, $sp, 0x18
