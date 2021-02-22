.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80268224
/* 196B04 80268224 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 196B08 80268228 AFB00010 */  sw        $s0, 0x10($sp)
/* 196B0C 8026822C 0080802D */  daddu     $s0, $a0, $zero
/* 196B10 80268230 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 196B14 80268234 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 196B18 80268238 3C030008 */  lui       $v1, 8
/* 196B1C 8026823C 00431024 */  and       $v0, $v0, $v1
/* 196B20 80268240 14400006 */  bnez      $v0, .L8026825C
/* 196B24 80268244 AFBF0014 */   sw       $ra, 0x14($sp)
/* 196B28 80268248 0C03A752 */  jal       is_ability_active
/* 196B2C 8026824C 0000202D */   daddu    $a0, $zero, $zero
/* 196B30 80268250 00021840 */  sll       $v1, $v0, 1
/* 196B34 80268254 00621821 */  addu      $v1, $v1, $v0
/* 196B38 80268258 02038023 */  subu      $s0, $s0, $v1
.L8026825C:
/* 196B3C 8026825C 06020001 */  bltzl     $s0, .L80268264
/* 196B40 80268260 0000802D */   daddu    $s0, $zero, $zero
.L80268264:
/* 196B44 80268264 2A020008 */  slti      $v0, $s0, 8
/* 196B48 80268268 50400001 */  beql      $v0, $zero, .L80268270
/* 196B4C 8026826C 24100007 */   addiu    $s0, $zero, 7
.L80268270:
/* 196B50 80268270 0200102D */  daddu     $v0, $s0, $zero
/* 196B54 80268274 8FBF0014 */  lw        $ra, 0x14($sp)
/* 196B58 80268278 8FB00010 */  lw        $s0, 0x10($sp)
/* 196B5C 8026827C 03E00008 */  jr        $ra
/* 196B60 80268280 27BD0018 */   addiu    $sp, $sp, 0x18
