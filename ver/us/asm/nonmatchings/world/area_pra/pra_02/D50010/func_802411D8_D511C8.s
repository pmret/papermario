.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411D8_D511C8
/* D511C8 802411D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D511CC 802411DC AFBF0010 */  sw        $ra, 0x10($sp)
/* D511D0 802411E0 8C82000C */  lw        $v0, 0xc($a0)
/* D511D4 802411E4 0C0B1EAF */  jal       evt_get_variable
/* D511D8 802411E8 8C450000 */   lw       $a1, ($v0)
/* D511DC 802411EC 0040182D */  daddu     $v1, $v0, $zero
/* D511E0 802411F0 10600012 */  beqz      $v1, .L8024123C
/* D511E4 802411F4 0000202D */   daddu    $a0, $zero, $zero
/* D511E8 802411F8 8C620000 */  lw        $v0, ($v1)
/* D511EC 802411FC 5040000A */  beql      $v0, $zero, .L80241228
/* D511F0 80241200 00041080 */   sll      $v0, $a0, 2
/* D511F4 80241204 3C058024 */  lui       $a1, %hi(func_80243CC0_A2DF00)
/* D511F8 80241208 24A53CC0 */  addiu     $a1, $a1, %lo(func_80243CC0_A2DF00)
.L8024120C:
/* D511FC 8024120C 24630004 */  addiu     $v1, $v1, 4
/* D51200 80241210 24840001 */  addiu     $a0, $a0, 1
/* D51204 80241214 ACA20000 */  sw        $v0, ($a1)
/* D51208 80241218 8C620000 */  lw        $v0, ($v1)
/* D5120C 8024121C 1440FFFB */  bnez      $v0, .L8024120C
/* D51210 80241220 24A50004 */   addiu    $a1, $a1, 4
/* D51214 80241224 00041080 */  sll       $v0, $a0, 2
.L80241228:
/* D51218 80241228 3C018024 */  lui       $at, %hi(func_80243CC0_A2DF00)
/* D5121C 8024122C 00220821 */  addu      $at, $at, $v0
/* D51220 80241230 AC203CC0 */  sw        $zero, %lo(func_80243CC0_A2DF00)($at)
/* D51224 80241234 08090499 */  j         .L80241264
/* D51228 80241238 00000000 */   nop
.L8024123C:
/* D5122C 8024123C 3C038024 */  lui       $v1, %hi(func_80243CC0_A2DF00)
/* D51230 80241240 24633CC0 */  addiu     $v1, $v1, %lo(func_80243CC0_A2DF00)
/* D51234 80241244 0060282D */  daddu     $a1, $v1, $zero
.L80241248:
/* D51238 80241248 24820010 */  addiu     $v0, $a0, 0x10
/* D5123C 8024124C AC620000 */  sw        $v0, ($v1)
/* D51240 80241250 24630004 */  addiu     $v1, $v1, 4
/* D51244 80241254 24840001 */  addiu     $a0, $a0, 1
/* D51248 80241258 28820070 */  slti      $v0, $a0, 0x70
/* D5124C 8024125C 1440FFFA */  bnez      $v0, .L80241248
/* D51250 80241260 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80241264:
/* D51254 80241264 8FBF0010 */  lw        $ra, 0x10($sp)
/* D51258 80241268 24020002 */  addiu     $v0, $zero, 2
/* D5125C 8024126C 03E00008 */  jr        $ra
/* D51260 80241270 27BD0018 */   addiu    $sp, $sp, 0x18
