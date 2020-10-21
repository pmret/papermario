.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024239C_C5CADC
/* C5CADC 8024239C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C5CAE0 802423A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* C5CAE4 802423A4 8C82000C */  lw        $v0, 0xc($a0)
/* C5CAE8 802423A8 0C0B1EAF */  jal       get_variable
/* C5CAEC 802423AC 8C450000 */   lw       $a1, ($v0)
/* C5CAF0 802423B0 0040182D */  daddu     $v1, $v0, $zero
/* C5CAF4 802423B4 10600012 */  beqz      $v1, .L80242400
/* C5CAF8 802423B8 0000202D */   daddu    $a0, $zero, $zero
/* C5CAFC 802423BC 8C620000 */  lw        $v0, ($v1)
/* C5CB00 802423C0 5040000A */  beql      $v0, $zero, .L802423EC
/* C5CB04 802423C4 00041080 */   sll      $v0, $a0, 2
/* C5CB08 802423C8 3C058024 */  lui       $a1, 0x8024
/* C5CB0C 802423CC 24A565D0 */  addiu     $a1, $a1, 0x65d0
.L802423D0:
/* C5CB10 802423D0 24630004 */  addiu     $v1, $v1, 4
/* C5CB14 802423D4 24840001 */  addiu     $a0, $a0, 1
/* C5CB18 802423D8 ACA20000 */  sw        $v0, ($a1)
/* C5CB1C 802423DC 8C620000 */  lw        $v0, ($v1)
/* C5CB20 802423E0 1440FFFB */  bnez      $v0, .L802423D0
/* C5CB24 802423E4 24A50004 */   addiu    $a1, $a1, 4
/* C5CB28 802423E8 00041080 */  sll       $v0, $a0, 2
.L802423EC:
/* C5CB2C 802423EC 3C018024 */  lui       $at, 0x8024
/* C5CB30 802423F0 00220821 */  addu      $at, $at, $v0
/* C5CB34 802423F4 AC2065D0 */  sw        $zero, 0x65d0($at)
/* C5CB38 802423F8 0809090A */  j         .L80242428
/* C5CB3C 802423FC 00000000 */   nop      
.L80242400:
/* C5CB40 80242400 3C038024 */  lui       $v1, 0x8024
/* C5CB44 80242404 246365D0 */  addiu     $v1, $v1, 0x65d0
/* C5CB48 80242408 0060282D */  daddu     $a1, $v1, $zero
.L8024240C:
/* C5CB4C 8024240C 24820010 */  addiu     $v0, $a0, 0x10
/* C5CB50 80242410 AC620000 */  sw        $v0, ($v1)
/* C5CB54 80242414 24630004 */  addiu     $v1, $v1, 4
/* C5CB58 80242418 24840001 */  addiu     $a0, $a0, 1
/* C5CB5C 8024241C 28820070 */  slti      $v0, $a0, 0x70
/* C5CB60 80242420 1440FFFA */  bnez      $v0, .L8024240C
/* C5CB64 80242424 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80242428:
/* C5CB68 80242428 8FBF0010 */  lw        $ra, 0x10($sp)
/* C5CB6C 8024242C 24020002 */  addiu     $v0, $zero, 2
/* C5CB70 80242430 03E00008 */  jr        $ra
/* C5CB74 80242434 27BD0018 */   addiu    $sp, $sp, 0x18
