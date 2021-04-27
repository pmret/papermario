.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024113C_B98D3C
/* B98D3C 8024113C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B98D40 80241140 AFBF0010 */  sw        $ra, 0x10($sp)
/* B98D44 80241144 8C82000C */  lw        $v0, 0xc($a0)
/* B98D48 80241148 0C0B1EAF */  jal       get_variable
/* B98D4C 8024114C 8C450000 */   lw       $a1, ($v0)
/* B98D50 80241150 0040182D */  daddu     $v1, $v0, $zero
/* B98D54 80241154 10600012 */  beqz      $v1, .L802411A0
/* B98D58 80241158 0000202D */   daddu    $a0, $zero, $zero
/* B98D5C 8024115C 8C620000 */  lw        $v0, ($v1)
/* B98D60 80241160 5040000A */  beql      $v0, $zero, .L8024118C
/* B98D64 80241164 00041080 */   sll      $v0, $a0, 2
/* B98D68 80241168 3C058024 */  lui       $a1, %hi(dro_01_SomeMatrixOperation)
/* B98D6C 8024116C 24A53880 */  addiu     $a1, $a1, %lo(dro_01_SomeMatrixOperation)
.L80241170:
/* B98D70 80241170 24630004 */  addiu     $v1, $v1, 4
/* B98D74 80241174 24840001 */  addiu     $a0, $a0, 1
/* B98D78 80241178 ACA20000 */  sw        $v0, ($a1)
/* B98D7C 8024117C 8C620000 */  lw        $v0, ($v1)
/* B98D80 80241180 1440FFFB */  bnez      $v0, .L80241170
/* B98D84 80241184 24A50004 */   addiu    $a1, $a1, 4
/* B98D88 80241188 00041080 */  sll       $v0, $a0, 2
.L8024118C:
/* B98D8C 8024118C 3C018024 */  lui       $at, %hi(dro_01_SomeMatrixOperation)
/* B98D90 80241190 00220821 */  addu      $at, $at, $v0
/* B98D94 80241194 AC203880 */  sw        $zero, %lo(dro_01_SomeMatrixOperation)($at)
/* B98D98 80241198 08090472 */  j         .L802411C8
/* B98D9C 8024119C 00000000 */   nop
.L802411A0:
/* B98DA0 802411A0 3C038024 */  lui       $v1, %hi(dro_01_SomeMatrixOperation)
/* B98DA4 802411A4 24633880 */  addiu     $v1, $v1, %lo(dro_01_SomeMatrixOperation)
/* B98DA8 802411A8 0060282D */  daddu     $a1, $v1, $zero
.L802411AC:
/* B98DAC 802411AC 24820010 */  addiu     $v0, $a0, 0x10
/* B98DB0 802411B0 AC620000 */  sw        $v0, ($v1)
/* B98DB4 802411B4 24630004 */  addiu     $v1, $v1, 4
/* B98DB8 802411B8 24840001 */  addiu     $a0, $a0, 1
/* B98DBC 802411BC 28820070 */  slti      $v0, $a0, 0x70
/* B98DC0 802411C0 1440FFFA */  bnez      $v0, .L802411AC
/* B98DC4 802411C4 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802411C8:
/* B98DC8 802411C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* B98DCC 802411CC 24020002 */  addiu     $v0, $zero, 2
/* B98DD0 802411D0 03E00008 */  jr        $ra
/* B98DD4 802411D4 27BD0018 */   addiu    $sp, $sp, 0x18
/* B98DD8 802411D8 00000000 */  nop
/* B98DDC 802411DC 00000000 */  nop
