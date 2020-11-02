.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240448_D300C8
/* D300C8 80240448 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* D300CC 8024044C 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* D300D0 80240450 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D300D4 80240454 AFBF0010 */  sw        $ra, 0x10($sp)
/* D300D8 80240458 00021100 */  sll       $v0, $v0, 4
/* D300DC 8024045C 3C048009 */  lui       $a0, 0x8009
/* D300E0 80240460 00822021 */  addu      $a0, $a0, $v0
/* D300E4 80240464 8C84EF20 */  lw        $a0, -0x10e0($a0)
/* D300E8 80240468 0C0496CF */  jal       set_message_string
/* D300EC 8024046C 0000282D */   daddu    $a1, $zero, $zero
/* D300F0 80240470 8FBF0010 */  lw        $ra, 0x10($sp)
/* D300F4 80240474 24020002 */  addiu     $v0, $zero, 2
/* D300F8 80240478 03E00008 */  jr        $ra
/* D300FC 8024047C 27BD0018 */   addiu    $sp, $sp, 0x18
