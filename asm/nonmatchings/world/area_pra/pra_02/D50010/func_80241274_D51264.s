.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241274_D51264
/* D51264 80241274 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D51268 80241278 AFBF0010 */  sw        $ra, 0x10($sp)
/* D5126C 8024127C 8C82000C */  lw        $v0, 0xc($a0)
/* D51270 80241280 0C0B1EAF */  jal       get_variable
/* D51274 80241284 8C450000 */   lw       $a1, ($v0)
/* D51278 80241288 0040182D */  daddu     $v1, $v0, $zero
/* D5127C 8024128C 10600012 */  beqz      $v1, .L802412D8
/* D51280 80241290 0000202D */   daddu    $a0, $zero, $zero
/* D51284 80241294 8C620000 */  lw        $v0, ($v1)
/* D51288 80241298 5040000A */  beql      $v0, $zero, .L802412C4
/* D5128C 8024129C 00041080 */   sll      $v0, $a0, 2
/* D51290 802412A0 3C058024 */  lui       $a1, 0x8024
/* D51294 802412A4 24A53E88 */  addiu     $a1, $a1, 0x3e88
.L802412A8:
/* D51298 802412A8 24630004 */  addiu     $v1, $v1, 4
/* D5129C 802412AC 24840001 */  addiu     $a0, $a0, 1
/* D512A0 802412B0 ACA20000 */  sw        $v0, ($a1)
/* D512A4 802412B4 8C620000 */  lw        $v0, ($v1)
/* D512A8 802412B8 1440FFFB */  bnez      $v0, .L802412A8
/* D512AC 802412BC 24A50004 */   addiu    $a1, $a1, 4
/* D512B0 802412C0 00041080 */  sll       $v0, $a0, 2
.L802412C4:
/* D512B4 802412C4 3C018024 */  lui       $at, 0x8024
/* D512B8 802412C8 00220821 */  addu      $at, $at, $v0
/* D512BC 802412CC AC203E88 */  sw        $zero, 0x3e88($at)
/* D512C0 802412D0 080904C0 */  j         .L80241300
/* D512C4 802412D4 00000000 */   nop      
.L802412D8:
/* D512C8 802412D8 3C038024 */  lui       $v1, 0x8024
/* D512CC 802412DC 24633E88 */  addiu     $v1, $v1, 0x3e88
/* D512D0 802412E0 0060282D */  daddu     $a1, $v1, $zero
.L802412E4:
/* D512D4 802412E4 24820080 */  addiu     $v0, $a0, 0x80
/* D512D8 802412E8 AC620000 */  sw        $v0, ($v1)
/* D512DC 802412EC 24630004 */  addiu     $v1, $v1, 4
/* D512E0 802412F0 24840001 */  addiu     $a0, $a0, 1
/* D512E4 802412F4 2882005B */  slti      $v0, $a0, 0x5b
/* D512E8 802412F8 1440FFFA */  bnez      $v0, .L802412E4
/* D512EC 802412FC ACA0016C */   sw       $zero, 0x16c($a1)
.L80241300:
/* D512F0 80241300 8FBF0010 */  lw        $ra, 0x10($sp)
/* D512F4 80241304 24020002 */  addiu     $v0, $zero, 2
/* D512F8 80241308 03E00008 */  jr        $ra
/* D512FC 8024130C 27BD0018 */   addiu    $sp, $sp, 0x18
