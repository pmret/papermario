.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DE4_CF49B4
/* CF49B4 80241DE4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF49B8 80241DE8 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF49BC 80241DEC 8C82000C */  lw        $v0, 0xc($a0)
/* CF49C0 80241DF0 0C0B1EAF */  jal       get_variable
/* CF49C4 80241DF4 8C450000 */   lw       $a1, ($v0)
/* CF49C8 80241DF8 0040182D */  daddu     $v1, $v0, $zero
/* CF49CC 80241DFC 10600012 */  beqz      $v1, .L80241E48
/* CF49D0 80241E00 0000202D */   daddu    $a0, $zero, $zero
/* CF49D4 80241E04 8C620000 */  lw        $v0, ($v1)
/* CF49D8 80241E08 5040000A */  beql      $v0, $zero, .L80241E34
/* CF49DC 80241E0C 00041080 */   sll      $v0, $a0, 2
/* CF49E0 80241E10 3C058024 */  lui       $a1, %hi(D_80244FA0_8F0DC0)
/* CF49E4 80241E14 24A54FA0 */  addiu     $a1, $a1, %lo(D_80244FA0_8F0DC0)
.L80241E18:
/* CF49E8 80241E18 24630004 */  addiu     $v1, $v1, 4
/* CF49EC 80241E1C 24840001 */  addiu     $a0, $a0, 1
/* CF49F0 80241E20 ACA20000 */  sw        $v0, ($a1)
/* CF49F4 80241E24 8C620000 */  lw        $v0, ($v1)
/* CF49F8 80241E28 1440FFFB */  bnez      $v0, .L80241E18
/* CF49FC 80241E2C 24A50004 */   addiu    $a1, $a1, 4
/* CF4A00 80241E30 00041080 */  sll       $v0, $a0, 2
.L80241E34:
/* CF4A04 80241E34 3C018024 */  lui       $at, %hi(D_80244FA0_8F0DC0)
/* CF4A08 80241E38 00220821 */  addu      $at, $at, $v0
/* CF4A0C 80241E3C AC204FA0 */  sw        $zero, %lo(D_80244FA0_8F0DC0)($at)
/* CF4A10 80241E40 0809079C */  j         .L80241E70
/* CF4A14 80241E44 00000000 */   nop
.L80241E48:
/* CF4A18 80241E48 3C038024 */  lui       $v1, %hi(D_80244FA0_8F0DC0)
/* CF4A1C 80241E4C 24634FA0 */  addiu     $v1, $v1, %lo(D_80244FA0_8F0DC0)
/* CF4A20 80241E50 0060282D */  daddu     $a1, $v1, $zero
.L80241E54:
/* CF4A24 80241E54 24820080 */  addiu     $v0, $a0, 0x80
/* CF4A28 80241E58 AC620000 */  sw        $v0, ($v1)
/* CF4A2C 80241E5C 24630004 */  addiu     $v1, $v1, 4
/* CF4A30 80241E60 24840001 */  addiu     $a0, $a0, 1
/* CF4A34 80241E64 2882005B */  slti      $v0, $a0, 0x5b
/* CF4A38 80241E68 1440FFFA */  bnez      $v0, .L80241E54
/* CF4A3C 80241E6C ACA0016C */   sw       $zero, 0x16c($a1)
.L80241E70:
/* CF4A40 80241E70 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF4A44 80241E74 24020002 */  addiu     $v0, $zero, 2
/* CF4A48 80241E78 03E00008 */  jr        $ra
/* CF4A4C 80241E7C 27BD0018 */   addiu    $sp, $sp, 0x18
