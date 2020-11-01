.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240448_C77128
/* C77128 80240448 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* C7712C 8024044C 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* C77130 80240450 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C77134 80240454 AFBF0010 */  sw        $ra, 0x10($sp)
/* C77138 80240458 00021100 */  sll       $v0, $v0, 4
/* C7713C 8024045C 3C048009 */  lui       $a0, 0x8009
/* C77140 80240460 00822021 */  addu      $a0, $a0, $v0
/* C77144 80240464 8C84EF20 */  lw        $a0, -0x10e0($a0)
/* C77148 80240468 0C0496CF */  jal       set_message_string
/* C7714C 8024046C 0000282D */   daddu    $a1, $zero, $zero
/* C77150 80240470 8FBF0010 */  lw        $ra, 0x10($sp)
/* C77154 80240474 24020002 */  addiu     $v0, $zero, 2
/* C77158 80240478 03E00008 */  jr        $ra
/* C7715C 8024047C 27BD0018 */   addiu    $sp, $sp, 0x18
