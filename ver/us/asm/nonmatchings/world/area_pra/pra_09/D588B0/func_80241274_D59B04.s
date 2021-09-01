.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241274_D59B04
/* D59B04 80241274 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D59B08 80241278 AFBF0010 */  sw        $ra, 0x10($sp)
/* D59B0C 8024127C 8C82000C */  lw        $v0, 0xc($a0)
/* D59B10 80241280 0C0B1EAF */  jal       evt_get_variable
/* D59B14 80241284 8C450000 */   lw       $a1, ($v0)
/* D59B18 80241288 0040182D */  daddu     $v1, $v0, $zero
/* D59B1C 8024128C 10600012 */  beqz      $v1, .L802412D8
/* D59B20 80241290 0000202D */   daddu    $a0, $zero, $zero
/* D59B24 80241294 8C620000 */  lw        $v0, ($v1)
/* D59B28 80241298 5040000A */  beql      $v0, $zero, .L802412C4
/* D59B2C 8024129C 00041080 */   sll      $v0, $a0, 2
/* D59B30 802412A0 3C058024 */  lui       $a1, %hi(D_80246BE8)
/* D59B34 802412A4 24A56BE8 */  addiu     $a1, $a1, %lo(D_80246BE8)
.L802412A8:
/* D59B38 802412A8 24630004 */  addiu     $v1, $v1, 4
/* D59B3C 802412AC 24840001 */  addiu     $a0, $a0, 1
/* D59B40 802412B0 ACA20000 */  sw        $v0, ($a1)
/* D59B44 802412B4 8C620000 */  lw        $v0, ($v1)
/* D59B48 802412B8 1440FFFB */  bnez      $v0, .L802412A8
/* D59B4C 802412BC 24A50004 */   addiu    $a1, $a1, 4
/* D59B50 802412C0 00041080 */  sll       $v0, $a0, 2
.L802412C4:
/* D59B54 802412C4 3C018024 */  lui       $at, %hi(D_80246BE8)
/* D59B58 802412C8 00220821 */  addu      $at, $at, $v0
/* D59B5C 802412CC AC206BE8 */  sw        $zero, %lo(D_80246BE8)($at)
/* D59B60 802412D0 080904C0 */  j         .L80241300
/* D59B64 802412D4 00000000 */   nop
.L802412D8:
/* D59B68 802412D8 3C038024 */  lui       $v1, %hi(D_80246BE8)
/* D59B6C 802412DC 24636BE8 */  addiu     $v1, $v1, %lo(D_80246BE8)
/* D59B70 802412E0 0060282D */  daddu     $a1, $v1, $zero
.L802412E4:
/* D59B74 802412E4 24820080 */  addiu     $v0, $a0, 0x80
/* D59B78 802412E8 AC620000 */  sw        $v0, ($v1)
/* D59B7C 802412EC 24630004 */  addiu     $v1, $v1, 4
/* D59B80 802412F0 24840001 */  addiu     $a0, $a0, 1
/* D59B84 802412F4 2882005B */  slti      $v0, $a0, 0x5b
/* D59B88 802412F8 1440FFFA */  bnez      $v0, .L802412E4
/* D59B8C 802412FC ACA0016C */   sw       $zero, 0x16c($a1)
.L80241300:
/* D59B90 80241300 8FBF0010 */  lw        $ra, 0x10($sp)
/* D59B94 80241304 24020002 */  addiu     $v0, $zero, 2
/* D59B98 80241308 03E00008 */  jr        $ra
/* D59B9C 8024130C 27BD0018 */   addiu    $sp, $sp, 0x18
