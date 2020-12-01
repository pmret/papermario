.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024146C_91F9DC
/* 91F9DC 8024146C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 91F9E0 80241470 AFBF0010 */  sw        $ra, 0x10($sp)
/* 91F9E4 80241474 8C82000C */  lw        $v0, 0xc($a0)
/* 91F9E8 80241478 0C0B1EAF */  jal       get_variable
/* 91F9EC 8024147C 8C450000 */   lw       $a1, ($v0)
/* 91F9F0 80241480 0040182D */  daddu     $v1, $v0, $zero
/* 91F9F4 80241484 10600012 */  beqz      $v1, .L802414D0
/* 91F9F8 80241488 0000202D */   daddu    $a0, $zero, $zero
/* 91F9FC 8024148C 8C620000 */  lw        $v0, ($v1)
/* 91FA00 80241490 5040000A */  beql      $v0, $zero, .L802414BC
/* 91FA04 80241494 00041080 */   sll      $v0, $a0, 2
/* 91FA08 80241498 3C058025 */  lui       $a1, %hi(D_80248480)
/* 91FA0C 8024149C 24A58480 */  addiu     $a1, $a1, %lo(D_80248480)
.L802414A0:
/* 91FA10 802414A0 24630004 */  addiu     $v1, $v1, 4
/* 91FA14 802414A4 24840001 */  addiu     $a0, $a0, 1
/* 91FA18 802414A8 ACA20000 */  sw        $v0, ($a1)
/* 91FA1C 802414AC 8C620000 */  lw        $v0, ($v1)
/* 91FA20 802414B0 1440FFFB */  bnez      $v0, .L802414A0
/* 91FA24 802414B4 24A50004 */   addiu    $a1, $a1, 4
/* 91FA28 802414B8 00041080 */  sll       $v0, $a0, 2
.L802414BC:
/* 91FA2C 802414BC 3C018025 */  lui       $at, %hi(D_80248480)
/* 91FA30 802414C0 00220821 */  addu      $at, $at, $v0
/* 91FA34 802414C4 AC208480 */  sw        $zero, %lo(D_80248480)($at)
/* 91FA38 802414C8 0809053E */  j         .L802414F8
/* 91FA3C 802414CC 00000000 */   nop      
.L802414D0:
/* 91FA40 802414D0 3C038025 */  lui       $v1, %hi(D_80248480)
/* 91FA44 802414D4 24638480 */  addiu     $v1, $v1, %lo(D_80248480)
/* 91FA48 802414D8 0060282D */  daddu     $a1, $v1, $zero
.L802414DC:
/* 91FA4C 802414DC 24820010 */  addiu     $v0, $a0, 0x10
/* 91FA50 802414E0 AC620000 */  sw        $v0, ($v1)
/* 91FA54 802414E4 24630004 */  addiu     $v1, $v1, 4
/* 91FA58 802414E8 24840001 */  addiu     $a0, $a0, 1
/* 91FA5C 802414EC 28820070 */  slti      $v0, $a0, 0x70
/* 91FA60 802414F0 1440FFFA */  bnez      $v0, .L802414DC
/* 91FA64 802414F4 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802414F8:
/* 91FA68 802414F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 91FA6C 802414FC 24020002 */  addiu     $v0, $zero, 2
/* 91FA70 80241500 03E00008 */  jr        $ra
/* 91FA74 80241504 27BD0018 */   addiu    $sp, $sp, 0x18
/* 91FA78 80241508 00000000 */  nop       
/* 91FA7C 8024150C 00000000 */  nop       
