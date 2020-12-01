.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411D8_D6FB88
/* D6FB88 802411D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D6FB8C 802411DC AFBF0010 */  sw        $ra, 0x10($sp)
/* D6FB90 802411E0 8C82000C */  lw        $v0, 0xc($a0)
/* D6FB94 802411E4 0C0B1EAF */  jal       get_variable
/* D6FB98 802411E8 8C450000 */   lw       $a1, ($v0)
/* D6FB9C 802411EC 0040182D */  daddu     $v1, $v0, $zero
/* D6FBA0 802411F0 10600012 */  beqz      $v1, .L8024123C
/* D6FBA4 802411F4 0000202D */   daddu    $a0, $zero, $zero
/* D6FBA8 802411F8 8C620000 */  lw        $v0, ($v1)
/* D6FBAC 802411FC 5040000A */  beql      $v0, $zero, .L80241228
/* D6FBB0 80241200 00041080 */   sll      $v0, $a0, 2
/* D6FBB4 80241204 3C058024 */  lui       $a1, %hi(D_802479F0)
/* D6FBB8 80241208 24A579F0 */  addiu     $a1, $a1, %lo(D_802479F0)
.L8024120C:
/* D6FBBC 8024120C 24630004 */  addiu     $v1, $v1, 4
/* D6FBC0 80241210 24840001 */  addiu     $a0, $a0, 1
/* D6FBC4 80241214 ACA20000 */  sw        $v0, ($a1)
/* D6FBC8 80241218 8C620000 */  lw        $v0, ($v1)
/* D6FBCC 8024121C 1440FFFB */  bnez      $v0, .L8024120C
/* D6FBD0 80241220 24A50004 */   addiu    $a1, $a1, 4
/* D6FBD4 80241224 00041080 */  sll       $v0, $a0, 2
.L80241228:
/* D6FBD8 80241228 3C018024 */  lui       $at, %hi(D_802479F0)
/* D6FBDC 8024122C 00220821 */  addu      $at, $at, $v0
/* D6FBE0 80241230 AC2079F0 */  sw        $zero, %lo(D_802479F0)($at)
/* D6FBE4 80241234 08090499 */  j         .L80241264
/* D6FBE8 80241238 00000000 */   nop      
.L8024123C:
/* D6FBEC 8024123C 3C038024 */  lui       $v1, %hi(D_802479F0)
/* D6FBF0 80241240 246379F0 */  addiu     $v1, $v1, %lo(D_802479F0)
/* D6FBF4 80241244 0060282D */  daddu     $a1, $v1, $zero
.L80241248:
/* D6FBF8 80241248 24820010 */  addiu     $v0, $a0, 0x10
/* D6FBFC 8024124C AC620000 */  sw        $v0, ($v1)
/* D6FC00 80241250 24630004 */  addiu     $v1, $v1, 4
/* D6FC04 80241254 24840001 */  addiu     $a0, $a0, 1
/* D6FC08 80241258 28820070 */  slti      $v0, $a0, 0x70
/* D6FC0C 8024125C 1440FFFA */  bnez      $v0, .L80241248
/* D6FC10 80241260 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80241264:
/* D6FC14 80241264 8FBF0010 */  lw        $ra, 0x10($sp)
/* D6FC18 80241268 24020002 */  addiu     $v0, $zero, 2
/* D6FC1C 8024126C 03E00008 */  jr        $ra
/* D6FC20 80241270 27BD0018 */   addiu    $sp, $sp, 0x18
