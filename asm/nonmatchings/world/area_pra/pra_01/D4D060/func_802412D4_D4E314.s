.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412D4_D4E314
/* D4E314 802412D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D4E318 802412D8 AFBF0010 */  sw        $ra, 0x10($sp)
/* D4E31C 802412DC 8C82000C */  lw        $v0, 0xc($a0)
/* D4E320 802412E0 0C0B1EAF */  jal       get_variable
/* D4E324 802412E4 8C450000 */   lw       $a1, ($v0)
/* D4E328 802412E8 0040182D */  daddu     $v1, $v0, $zero
/* D4E32C 802412EC 10600012 */  beqz      $v1, .L80241338
/* D4E330 802412F0 0000202D */   daddu    $a0, $zero, $zero
/* D4E334 802412F4 8C620000 */  lw        $v0, ($v1)
/* D4E338 802412F8 5040000A */  beql      $v0, $zero, .L80241324
/* D4E33C 802412FC 00041080 */   sll      $v0, $a0, 2
/* D4E340 80241300 3C058024 */  lui       $a1, 0x8024
/* D4E344 80241304 24A53178 */  addiu     $a1, $a1, 0x3178
.L80241308:
/* D4E348 80241308 24630004 */  addiu     $v1, $v1, 4
/* D4E34C 8024130C 24840001 */  addiu     $a0, $a0, 1
/* D4E350 80241310 ACA20000 */  sw        $v0, ($a1)
/* D4E354 80241314 8C620000 */  lw        $v0, ($v1)
/* D4E358 80241318 1440FFFB */  bnez      $v0, .L80241308
/* D4E35C 8024131C 24A50004 */   addiu    $a1, $a1, 4
/* D4E360 80241320 00041080 */  sll       $v0, $a0, 2
.L80241324:
/* D4E364 80241324 3C018024 */  lui       $at, 0x8024
/* D4E368 80241328 00220821 */  addu      $at, $at, $v0
/* D4E36C 8024132C AC203178 */  sw        $zero, 0x3178($at)
/* D4E370 80241330 080904D8 */  j         .L80241360
/* D4E374 80241334 00000000 */   nop      
.L80241338:
/* D4E378 80241338 3C038024 */  lui       $v1, 0x8024
/* D4E37C 8024133C 24633178 */  addiu     $v1, $v1, 0x3178
/* D4E380 80241340 0060282D */  daddu     $a1, $v1, $zero
.L80241344:
/* D4E384 80241344 24820080 */  addiu     $v0, $a0, 0x80
/* D4E388 80241348 AC620000 */  sw        $v0, ($v1)
/* D4E38C 8024134C 24630004 */  addiu     $v1, $v1, 4
/* D4E390 80241350 24840001 */  addiu     $a0, $a0, 1
/* D4E394 80241354 2882005B */  slti      $v0, $a0, 0x5b
/* D4E398 80241358 1440FFFA */  bnez      $v0, .L80241344
/* D4E39C 8024135C ACA0016C */   sw       $zero, 0x16c($a1)
.L80241360:
/* D4E3A0 80241360 8FBF0010 */  lw        $ra, 0x10($sp)
/* D4E3A4 80241364 24020002 */  addiu     $v0, $zero, 2
/* D4E3A8 80241368 03E00008 */  jr        $ra
/* D4E3AC 8024136C 27BD0018 */   addiu    $sp, $sp, 0x18
