.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240568_AF7EB8
/* AF7EB8 80240568 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF7EBC 8024056C AFBF0010 */  sw        $ra, 0x10($sp)
/* AF7EC0 80240570 8C82000C */  lw        $v0, 0xc($a0)
/* AF7EC4 80240574 0C0B1EAF */  jal       evt_get_variable
/* AF7EC8 80240578 8C450000 */   lw       $a1, ($v0)
/* AF7ECC 8024057C 0040182D */  daddu     $v1, $v0, $zero
/* AF7ED0 80240580 10600012 */  beqz      $v1, .L802405CC
/* AF7ED4 80240584 0000202D */   daddu    $a0, $zero, $zero
/* AF7ED8 80240588 8C620000 */  lw        $v0, ($v1)
/* AF7EDC 8024058C 5040000A */  beql      $v0, $zero, .L802405B8
/* AF7EE0 80240590 00041080 */   sll      $v0, $a0, 2
/* AF7EE4 80240594 3C058024 */  lui       $a1, %hi(D_802461F0)
/* AF7EE8 80240598 24A561F0 */  addiu     $a1, $a1, %lo(D_802461F0)
.L8024059C:
/* AF7EEC 8024059C 24630004 */  addiu     $v1, $v1, 4
/* AF7EF0 802405A0 24840001 */  addiu     $a0, $a0, 1
/* AF7EF4 802405A4 ACA20000 */  sw        $v0, ($a1)
/* AF7EF8 802405A8 8C620000 */  lw        $v0, ($v1)
/* AF7EFC 802405AC 1440FFFB */  bnez      $v0, .L8024059C
/* AF7F00 802405B0 24A50004 */   addiu    $a1, $a1, 4
/* AF7F04 802405B4 00041080 */  sll       $v0, $a0, 2
.L802405B8:
/* AF7F08 802405B8 3C018024 */  lui       $at, %hi(D_802461F0)
/* AF7F0C 802405BC 00220821 */  addu      $at, $at, $v0
/* AF7F10 802405C0 AC2061F0 */  sw        $zero, %lo(D_802461F0)($at)
/* AF7F14 802405C4 0809017D */  j         .L802405F4
/* AF7F18 802405C8 00000000 */   nop
.L802405CC:
/* AF7F1C 802405CC 3C038024 */  lui       $v1, %hi(D_802461F0)
/* AF7F20 802405D0 246361F0 */  addiu     $v1, $v1, %lo(D_802461F0)
/* AF7F24 802405D4 0060282D */  daddu     $a1, $v1, $zero
.L802405D8:
/* AF7F28 802405D8 24820010 */  addiu     $v0, $a0, 0x10
/* AF7F2C 802405DC AC620000 */  sw        $v0, ($v1)
/* AF7F30 802405E0 24630004 */  addiu     $v1, $v1, 4
/* AF7F34 802405E4 24840001 */  addiu     $a0, $a0, 1
/* AF7F38 802405E8 28820070 */  slti      $v0, $a0, 0x70
/* AF7F3C 802405EC 1440FFFA */  bnez      $v0, .L802405D8
/* AF7F40 802405F0 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802405F4:
/* AF7F44 802405F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF7F48 802405F8 24020002 */  addiu     $v0, $zero, 2
/* AF7F4C 802405FC 03E00008 */  jr        $ra
/* AF7F50 80240600 27BD0018 */   addiu    $sp, $sp, 0x18
