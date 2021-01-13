.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241274_D6FC24
/* D6FC24 80241274 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D6FC28 80241278 AFBF0010 */  sw        $ra, 0x10($sp)
/* D6FC2C 8024127C 8C82000C */  lw        $v0, 0xc($a0)
/* D6FC30 80241280 0C0B1EAF */  jal       get_variable
/* D6FC34 80241284 8C450000 */   lw       $a1, ($v0)
/* D6FC38 80241288 0040182D */  daddu     $v1, $v0, $zero
/* D6FC3C 8024128C 10600012 */  beqz      $v1, .L802412D8
/* D6FC40 80241290 0000202D */   daddu    $a0, $zero, $zero
/* D6FC44 80241294 8C620000 */  lw        $v0, ($v1)
/* D6FC48 80241298 5040000A */  beql      $v0, $zero, .L802412C4
/* D6FC4C 8024129C 00041080 */   sll      $v0, $a0, 2
/* D6FC50 802412A0 3C058024 */  lui       $a1, %hi(D_80247BB8)
/* D6FC54 802412A4 24A57BB8 */  addiu     $a1, $a1, %lo(D_80247BB8)
.L802412A8:
/* D6FC58 802412A8 24630004 */  addiu     $v1, $v1, 4
/* D6FC5C 802412AC 24840001 */  addiu     $a0, $a0, 1
/* D6FC60 802412B0 ACA20000 */  sw        $v0, ($a1)
/* D6FC64 802412B4 8C620000 */  lw        $v0, ($v1)
/* D6FC68 802412B8 1440FFFB */  bnez      $v0, .L802412A8
/* D6FC6C 802412BC 24A50004 */   addiu    $a1, $a1, 4
/* D6FC70 802412C0 00041080 */  sll       $v0, $a0, 2
.L802412C4:
/* D6FC74 802412C4 3C018024 */  lui       $at, %hi(D_80247BB8)
/* D6FC78 802412C8 00220821 */  addu      $at, $at, $v0
/* D6FC7C 802412CC AC207BB8 */  sw        $zero, %lo(D_80247BB8)($at)
/* D6FC80 802412D0 080904C0 */  j         .L80241300
/* D6FC84 802412D4 00000000 */   nop
.L802412D8:
/* D6FC88 802412D8 3C038024 */  lui       $v1, %hi(D_80247BB8)
/* D6FC8C 802412DC 24637BB8 */  addiu     $v1, $v1, %lo(D_80247BB8)
/* D6FC90 802412E0 0060282D */  daddu     $a1, $v1, $zero
.L802412E4:
/* D6FC94 802412E4 24820080 */  addiu     $v0, $a0, 0x80
/* D6FC98 802412E8 AC620000 */  sw        $v0, ($v1)
/* D6FC9C 802412EC 24630004 */  addiu     $v1, $v1, 4
/* D6FCA0 802412F0 24840001 */  addiu     $a0, $a0, 1
/* D6FCA4 802412F4 2882005B */  slti      $v0, $a0, 0x5b
/* D6FCA8 802412F8 1440FFFA */  bnez      $v0, .L802412E4
/* D6FCAC 802412FC ACA0016C */   sw       $zero, 0x16c($a1)
.L80241300:
/* D6FCB0 80241300 8FBF0010 */  lw        $ra, 0x10($sp)
/* D6FCB4 80241304 24020002 */  addiu     $v0, $zero, 2
/* D6FCB8 80241308 03E00008 */  jr        $ra
/* D6FCBC 8024130C 27BD0018 */   addiu    $sp, $sp, 0x18
