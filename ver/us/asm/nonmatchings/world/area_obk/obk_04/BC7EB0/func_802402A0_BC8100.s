.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402A0_BC8100
/* BC8100 802402A0 24020001 */  addiu     $v0, $zero, 1
/* BC8104 802402A4 1082000B */  beq       $a0, $v0, .L802402D4
/* BC8108 802402A8 2403000C */   addiu    $v1, $zero, 0xc
/* BC810C 802402AC 28820002 */  slti      $v0, $a0, 2
/* BC8110 802402B0 1440000E */  bnez      $v0, .L802402EC
/* BC8114 802402B4 0060102D */   daddu    $v0, $v1, $zero
/* BC8118 802402B8 24020002 */  addiu     $v0, $zero, 2
/* BC811C 802402BC 10820007 */  beq       $a0, $v0, .L802402DC
/* BC8120 802402C0 24020003 */   addiu    $v0, $zero, 3
/* BC8124 802402C4 10820007 */  beq       $a0, $v0, .L802402E4
/* BC8128 802402C8 0060102D */   daddu    $v0, $v1, $zero
/* BC812C 802402CC 080900BB */  j         .L802402EC
/* BC8130 802402D0 00000000 */   nop
.L802402D4:
/* BC8134 802402D4 080900BA */  j         .L802402E8
/* BC8138 802402D8 24030064 */   addiu    $v1, $zero, 0x64
.L802402DC:
/* BC813C 802402DC 080900BA */  j         .L802402E8
/* BC8140 802402E0 2403000D */   addiu    $v1, $zero, 0xd
.L802402E4:
/* BC8144 802402E4 2403000E */  addiu     $v1, $zero, 0xe
.L802402E8:
/* BC8148 802402E8 0060102D */  daddu     $v0, $v1, $zero
.L802402EC:
/* BC814C 802402EC 03E00008 */  jr        $ra
/* BC8150 802402F0 00000000 */   nop
