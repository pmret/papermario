.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A58D0
/* 41A660 802A58D0 3C03800E */  lui   $v1, 0x800e
/* 41A664 802A58D4 2463C070 */  addiu $v1, $v1, -0x3f90
/* 41A668 802A58D8 8C620004 */  lw    $v0, 4($v1)
/* 41A66C 802A58DC 8C6500DC */  lw    $a1, 0xdc($v1)
/* 41A670 802A58E0 30420004 */  andi  $v0, $v0, 4
/* 41A674 802A58E4 14400007 */  bnez  $v0, .L802A5904
/* 41A678 802A58E8 00000000 */   nop   
/* 41A67C 802A58EC 10A00005 */  beqz  $a1, .L802A5904
/* 41A680 802A58F0 3C030020 */   lui   $v1, 0x20
/* 41A684 802A58F4 8CA20000 */  lw    $v0, ($a1)
/* 41A688 802A58F8 00431024 */  and   $v0, $v0, $v1
/* 41A68C 802A58FC 10400003 */  beqz  $v0, .L802A590C
/* 41A690 802A5900 00000000 */   nop   
.L802A5904:
/* 41A694 802A5904 03E00008 */  jr    $ra
/* 41A698 802A5908 0000102D */   daddu $v0, $zero, $zero

.L802A590C:
/* 41A69C 802A590C 80A20216 */  lb    $v0, 0x216($a1)
/* 41A6A0 802A5910 80A30210 */  lb    $v1, 0x210($a1)
/* 41A6A4 802A5914 3842000D */  xori  $v0, $v0, 0xd
/* 41A6A8 802A5918 2C440001 */  sltiu $a0, $v0, 1
/* 41A6AC 802A591C 24020009 */  addiu $v0, $zero, 9
/* 41A6B0 802A5920 50620001 */  beql  $v1, $v0, .L802A5928
/* 41A6B4 802A5924 0000202D */   daddu $a0, $zero, $zero
.L802A5928:
/* 41A6B8 802A5928 2402000A */  addiu $v0, $zero, 0xa
/* 41A6BC 802A592C 50620001 */  beql  $v1, $v0, .L802A5934
/* 41A6C0 802A5930 0000202D */   daddu $a0, $zero, $zero
.L802A5934:
/* 41A6C4 802A5934 24020006 */  addiu $v0, $zero, 6
/* 41A6C8 802A5938 50620001 */  beql  $v1, $v0, .L802A5940
/* 41A6CC 802A593C 24040001 */   addiu $a0, $zero, 1
.L802A5940:
/* 41A6D0 802A5940 24020003 */  addiu $v0, $zero, 3
/* 41A6D4 802A5944 50620001 */  beql  $v1, $v0, .L802A594C
/* 41A6D8 802A5948 24040001 */   addiu $a0, $zero, 1
.L802A594C:
/* 41A6DC 802A594C 24020005 */  addiu $v0, $zero, 5
/* 41A6E0 802A5950 50620001 */  beql  $v1, $v0, .L802A5958
/* 41A6E4 802A5954 24040001 */   addiu $a0, $zero, 1
.L802A5958:
/* 41A6E8 802A5958 24020007 */  addiu $v0, $zero, 7
/* 41A6EC 802A595C 50620001 */  beql  $v1, $v0, .L802A5964
/* 41A6F0 802A5960 24040001 */   addiu $a0, $zero, 1
.L802A5964:
/* 41A6F4 802A5964 24020008 */  addiu $v0, $zero, 8
/* 41A6F8 802A5968 50620001 */  beql  $v1, $v0, .L802A5970
/* 41A6FC 802A596C 24040001 */   addiu $a0, $zero, 1
.L802A5970:
/* 41A700 802A5970 80A30214 */  lb    $v1, 0x214($a1)
/* 41A704 802A5974 2402000C */  addiu $v0, $zero, 0xc
/* 41A708 802A5978 50620001 */  beql  $v1, $v0, .L802A5980
/* 41A70C 802A597C 24040001 */   addiu $a0, $zero, 1
.L802A5980:
/* 41A710 802A5980 03E00008 */  jr    $ra
/* 41A714 802A5984 38820001 */   xori  $v0, $a0, 1

