.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D0C_B4547C
/* B4547C 80240D0C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B45480 80240D10 AFB10014 */  sw        $s1, 0x14($sp)
/* B45484 80240D14 0080882D */  daddu     $s1, $a0, $zero
/* B45488 80240D18 AFBF0018 */  sw        $ra, 0x18($sp)
/* B4548C 80240D1C AFB00010 */  sw        $s0, 0x10($sp)
/* B45490 80240D20 8E2400AC */  lw        $a0, 0xac($s1)
/* B45494 80240D24 0C04417A */  jal       get_entity_by_index
/* B45498 80240D28 00A0802D */   daddu    $s0, $a1, $zero
/* B4549C 80240D2C 12000003 */  beqz      $s0, .L80240D3C
/* B454A0 80240D30 0040182D */   daddu    $v1, $v0, $zero
/* B454A4 80240D34 2402FFE2 */  addiu     $v0, $zero, -0x1e
/* B454A8 80240D38 AE220070 */  sw        $v0, 0x70($s1)
.L80240D3C:
/* B454AC 80240D3C C6200070 */  lwc1      $f0, 0x70($s1)
/* B454B0 80240D40 46800020 */  cvt.s.w   $f0, $f0
/* B454B4 80240D44 E4600060 */  swc1      $f0, 0x60($v1)
/* B454B8 80240D48 C6200070 */  lwc1      $f0, 0x70($s1)
/* B454BC 80240D4C 46800020 */  cvt.s.w   $f0, $f0
/* B454C0 80240D50 E4600068 */  swc1      $f0, 0x68($v1)
/* B454C4 80240D54 8E230070 */  lw        $v1, 0x70($s1)
/* B454C8 80240D58 24630001 */  addiu     $v1, $v1, 1
/* B454CC 80240D5C 38620001 */  xori      $v0, $v1, 1
/* B454D0 80240D60 2C420001 */  sltiu     $v0, $v0, 1
/* B454D4 80240D64 AE230070 */  sw        $v1, 0x70($s1)
/* B454D8 80240D68 8FBF0018 */  lw        $ra, 0x18($sp)
/* B454DC 80240D6C 8FB10014 */  lw        $s1, 0x14($sp)
/* B454E0 80240D70 8FB00010 */  lw        $s0, 0x10($sp)
/* B454E4 80240D74 00021040 */  sll       $v0, $v0, 1
/* B454E8 80240D78 03E00008 */  jr        $ra
/* B454EC 80240D7C 27BD0020 */   addiu    $sp, $sp, 0x20
