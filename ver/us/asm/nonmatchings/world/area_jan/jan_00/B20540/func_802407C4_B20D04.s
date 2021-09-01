.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407C4_B20D04
/* B20D04 802407C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B20D08 802407C8 AFBF0010 */  sw        $ra, 0x10($sp)
/* B20D0C 802407CC 8C82000C */  lw        $v0, 0xc($a0)
/* B20D10 802407D0 0C0B1EAF */  jal       evt_get_variable
/* B20D14 802407D4 8C450000 */   lw       $a1, ($v0)
/* B20D18 802407D8 0040182D */  daddu     $v1, $v0, $zero
/* B20D1C 802407DC 10600012 */  beqz      $v1, .L80240828
/* B20D20 802407E0 0000202D */   daddu    $a0, $zero, $zero
/* B20D24 802407E4 8C620000 */  lw        $v0, ($v1)
/* B20D28 802407E8 5040000A */  beql      $v0, $zero, .L80240814
/* B20D2C 802407EC 00041080 */   sll      $v0, $a0, 2
/* B20D30 802407F0 3C058024 */  lui       $a1, %hi(D_80247AF0_CCB300)
/* B20D34 802407F4 24A57AF0 */  addiu     $a1, $a1, %lo(D_80247AF0_CCB300)
.L802407F8:
/* B20D38 802407F8 24630004 */  addiu     $v1, $v1, 4
/* B20D3C 802407FC 24840001 */  addiu     $a0, $a0, 1
/* B20D40 80240800 ACA20000 */  sw        $v0, ($a1)
/* B20D44 80240804 8C620000 */  lw        $v0, ($v1)
/* B20D48 80240808 1440FFFB */  bnez      $v0, .L802407F8
/* B20D4C 8024080C 24A50004 */   addiu    $a1, $a1, 4
/* B20D50 80240810 00041080 */  sll       $v0, $a0, 2
.L80240814:
/* B20D54 80240814 3C018024 */  lui       $at, %hi(D_80247AF0_CCB300)
/* B20D58 80240818 00220821 */  addu      $at, $at, $v0
/* B20D5C 8024081C AC207AF0 */  sw        $zero, %lo(D_80247AF0_CCB300)($at)
/* B20D60 80240820 08090214 */  j         .L80240850
/* B20D64 80240824 00000000 */   nop
.L80240828:
/* B20D68 80240828 3C038024 */  lui       $v1, %hi(D_80247AF0_CCB300)
/* B20D6C 8024082C 24637AF0 */  addiu     $v1, $v1, %lo(D_80247AF0_CCB300)
/* B20D70 80240830 0060282D */  daddu     $a1, $v1, $zero
.L80240834:
/* B20D74 80240834 24820010 */  addiu     $v0, $a0, 0x10
/* B20D78 80240838 AC620000 */  sw        $v0, ($v1)
/* B20D7C 8024083C 24630004 */  addiu     $v1, $v1, 4
/* B20D80 80240840 24840001 */  addiu     $a0, $a0, 1
/* B20D84 80240844 28820070 */  slti      $v0, $a0, 0x70
/* B20D88 80240848 1440FFFA */  bnez      $v0, .L80240834
/* B20D8C 8024084C ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80240850:
/* B20D90 80240850 8FBF0010 */  lw        $ra, 0x10($sp)
/* B20D94 80240854 24020002 */  addiu     $v0, $zero, 2
/* B20D98 80240858 03E00008 */  jr        $ra
/* B20D9C 8024085C 27BD0018 */   addiu    $sp, $sp, 0x18
