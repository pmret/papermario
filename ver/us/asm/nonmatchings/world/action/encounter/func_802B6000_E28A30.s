.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6000_E28A30
/* E28A30 802B6000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E28A34 802B6004 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* E28A38 802B6008 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* E28A3C 802B600C AFBF0010 */  sw        $ra, 0x10($sp)
/* E28A40 802B6010 8C640000 */  lw        $a0, ($v1)
/* E28A44 802B6014 0481000B */  bgez      $a0, .L802B6044
/* E28A48 802B6018 0060282D */   daddu    $a1, $v1, $zero
/* E28A4C 802B601C 3C027FF7 */  lui       $v0, 0x7ff7
/* E28A50 802B6020 3442FFF1 */  ori       $v0, $v0, 0xfff1
/* E28A54 802B6024 00821024 */  and       $v0, $a0, $v0
/* E28A58 802B6028 AC620000 */  sw        $v0, ($v1)
/* E28A5C 802B602C A06000B6 */  sb        $zero, 0xb6($v1)
/* E28A60 802B6030 A4600008 */  sh        $zero, 8($v1)
/* E28A64 802B6034 A46000C0 */  sh        $zero, 0xc0($v1)
/* E28A68 802B6038 A46000C2 */  sh        $zero, 0xc2($v1)
/* E28A6C 802B603C AC600054 */  sw        $zero, 0x54($v1)
/* E28A70 802B6040 AC60008C */  sw        $zero, 0x8c($v1)
.L802B6044:
/* E28A74 802B6044 8CA20004 */  lw        $v0, 4($a1)
/* E28A78 802B6048 3C030040 */  lui       $v1, 0x40
/* E28A7C 802B604C 00431024 */  and       $v0, $v0, $v1
/* E28A80 802B6050 1040000F */  beqz      $v0, .L802B6090
/* E28A84 802B6054 00000000 */   nop
/* E28A88 802B6058 3C028011 */  lui       $v0, %hi(gPartnerActionStatus)
/* E28A8C 802B605C 2442EBB0 */  addiu     $v0, $v0, %lo(gPartnerActionStatus)
/* E28A90 802B6060 80430003 */  lb        $v1, 3($v0)
/* E28A94 802B6064 24020008 */  addiu     $v0, $zero, 8
/* E28A98 802B6068 14620005 */  bne       $v1, $v0, .L802B6080
/* E28A9C 802B606C 24020007 */   addiu    $v0, $zero, 7
/* E28AA0 802B6070 0C0AF440 */  jal       func_802BD100_317020
/* E28AA4 802B6074 00000000 */   nop
/* E28AA8 802B6078 080AD824 */  j         .L802B6090
/* E28AAC 802B607C 00000000 */   nop
.L802B6080:
/* E28AB0 802B6080 14620003 */  bne       $v1, $v0, .L802B6090
/* E28AB4 802B6084 00000000 */   nop
/* E28AB8 802B6088 0C0AF440 */  jal       func_802BD100_317020
/* E28ABC 802B608C 00000000 */   nop
.L802B6090:
/* E28AC0 802B6090 8FBF0010 */  lw        $ra, 0x10($sp)
/* E28AC4 802B6094 03E00008 */  jr        $ra
/* E28AC8 802B6098 27BD0018 */   addiu    $sp, $sp, 0x18
