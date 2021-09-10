.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411D8_D59A68
/* D59A68 802411D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D59A6C 802411DC AFBF0010 */  sw        $ra, 0x10($sp)
/* D59A70 802411E0 8C82000C */  lw        $v0, 0xc($a0)
/* D59A74 802411E4 0C0B1EAF */  jal       evt_get_variable
/* D59A78 802411E8 8C450000 */   lw       $a1, ($v0)
/* D59A7C 802411EC 0040182D */  daddu     $v1, $v0, $zero
/* D59A80 802411F0 10600012 */  beqz      $v1, .L8024123C
/* D59A84 802411F4 0000202D */   daddu    $a0, $zero, $zero
/* D59A88 802411F8 8C620000 */  lw        $v0, ($v1)
/* D59A8C 802411FC 5040000A */  beql      $v0, $zero, .L80241228
/* D59A90 80241200 00041080 */   sll      $v0, $a0, 2
/* D59A94 80241204 3C058024 */  lui       $a1, %hi(flo_18_shakeTree)
/* D59A98 80241208 24A56A20 */  addiu     $a1, $a1, %lo(flo_18_shakeTree)
.L8024120C:
/* D59A9C 8024120C 24630004 */  addiu     $v1, $v1, 4
/* D59AA0 80241210 24840001 */  addiu     $a0, $a0, 1
/* D59AA4 80241214 ACA20000 */  sw        $v0, ($a1)
/* D59AA8 80241218 8C620000 */  lw        $v0, ($v1)
/* D59AAC 8024121C 1440FFFB */  bnez      $v0, .L8024120C
/* D59AB0 80241220 24A50004 */   addiu    $a1, $a1, 4
/* D59AB4 80241224 00041080 */  sll       $v0, $a0, 2
.L80241228:
/* D59AB8 80241228 3C018024 */  lui       $at, %hi(flo_18_shakeTree)
/* D59ABC 8024122C 00220821 */  addu      $at, $at, $v0
/* D59AC0 80241230 AC206A20 */  sw        $zero, %lo(flo_18_shakeTree)($at)
/* D59AC4 80241234 08090499 */  j         .L80241264
/* D59AC8 80241238 00000000 */   nop
.L8024123C:
/* D59ACC 8024123C 3C038024 */  lui       $v1, %hi(flo_18_shakeTree)
/* D59AD0 80241240 24636A20 */  addiu     $v1, $v1, %lo(flo_18_shakeTree)
/* D59AD4 80241244 0060282D */  daddu     $a1, $v1, $zero
.L80241248:
/* D59AD8 80241248 24820010 */  addiu     $v0, $a0, 0x10
/* D59ADC 8024124C AC620000 */  sw        $v0, ($v1)
/* D59AE0 80241250 24630004 */  addiu     $v1, $v1, 4
/* D59AE4 80241254 24840001 */  addiu     $a0, $a0, 1
/* D59AE8 80241258 28820070 */  slti      $v0, $a0, 0x70
/* D59AEC 8024125C 1440FFFA */  bnez      $v0, .L80241248
/* D59AF0 80241260 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80241264:
/* D59AF4 80241264 8FBF0010 */  lw        $ra, 0x10($sp)
/* D59AF8 80241268 24020002 */  addiu     $v0, $zero, 2
/* D59AFC 8024126C 03E00008 */  jr        $ra
/* D59B00 80241270 27BD0018 */   addiu    $sp, $sp, 0x18
