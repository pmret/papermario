.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241238_D4E278
/* D4E278 80241238 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D4E27C 8024123C AFBF0010 */  sw        $ra, 0x10($sp)
/* D4E280 80241240 8C82000C */  lw        $v0, 0xc($a0)
/* D4E284 80241244 0C0B1EAF */  jal       get_variable
/* D4E288 80241248 8C450000 */   lw       $a1, ($v0)
/* D4E28C 8024124C 0040182D */  daddu     $v1, $v0, $zero
/* D4E290 80241250 10600012 */  beqz      $v1, .L8024129C
/* D4E294 80241254 0000202D */   daddu    $a0, $zero, $zero
/* D4E298 80241258 8C620000 */  lw        $v0, ($v1)
/* D4E29C 8024125C 5040000A */  beql      $v0, $zero, .L80241288
/* D4E2A0 80241260 00041080 */   sll      $v0, $a0, 2
/* D4E2A4 80241264 3C058024 */  lui       $a1, %hi(D_80242FB0)
/* D4E2A8 80241268 24A52FB0 */  addiu     $a1, $a1, %lo(D_80242FB0)
.L8024126C:
/* D4E2AC 8024126C 24630004 */  addiu     $v1, $v1, 4
/* D4E2B0 80241270 24840001 */  addiu     $a0, $a0, 1
/* D4E2B4 80241274 ACA20000 */  sw        $v0, ($a1)
/* D4E2B8 80241278 8C620000 */  lw        $v0, ($v1)
/* D4E2BC 8024127C 1440FFFB */  bnez      $v0, .L8024126C
/* D4E2C0 80241280 24A50004 */   addiu    $a1, $a1, 4
/* D4E2C4 80241284 00041080 */  sll       $v0, $a0, 2
.L80241288:
/* D4E2C8 80241288 3C018024 */  lui       $at, %hi(D_80242FB0)
/* D4E2CC 8024128C 00220821 */  addu      $at, $at, $v0
/* D4E2D0 80241290 AC202FB0 */  sw        $zero, %lo(D_80242FB0)($at)
/* D4E2D4 80241294 080904B1 */  j         .L802412C4
/* D4E2D8 80241298 00000000 */   nop      
.L8024129C:
/* D4E2DC 8024129C 3C038024 */  lui       $v1, %hi(D_80242FB0)
/* D4E2E0 802412A0 24632FB0 */  addiu     $v1, $v1, %lo(D_80242FB0)
/* D4E2E4 802412A4 0060282D */  daddu     $a1, $v1, $zero
.L802412A8:
/* D4E2E8 802412A8 24820010 */  addiu     $v0, $a0, 0x10
/* D4E2EC 802412AC AC620000 */  sw        $v0, ($v1)
/* D4E2F0 802412B0 24630004 */  addiu     $v1, $v1, 4
/* D4E2F4 802412B4 24840001 */  addiu     $a0, $a0, 1
/* D4E2F8 802412B8 28820070 */  slti      $v0, $a0, 0x70
/* D4E2FC 802412BC 1440FFFA */  bnez      $v0, .L802412A8
/* D4E300 802412C0 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802412C4:
/* D4E304 802412C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* D4E308 802412C8 24020002 */  addiu     $v0, $zero, 2
/* D4E30C 802412CC 03E00008 */  jr        $ra
/* D4E310 802412D0 27BD0018 */   addiu    $sp, $sp, 0x18
