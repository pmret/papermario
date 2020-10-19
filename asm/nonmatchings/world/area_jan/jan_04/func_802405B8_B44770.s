.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405B8_B44D28
/* B44D28 802405B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B44D2C 802405BC AFB00010 */  sw        $s0, 0x10($sp)
/* B44D30 802405C0 0080802D */  daddu     $s0, $a0, $zero
/* B44D34 802405C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* B44D38 802405C8 8E02000C */  lw        $v0, 0xc($s0)
/* B44D3C 802405CC 0C0B1EAF */  jal       get_variable
/* B44D40 802405D0 8C450000 */   lw       $a1, ($v0)
/* B44D44 802405D4 00021140 */  sll       $v0, $v0, 5
/* B44D48 802405D8 AE000084 */  sw        $zero, 0x84($s0)
/* B44D4C 802405DC 3C018008 */  lui       $at, 0x8008
/* B44D50 802405E0 00220821 */  addu      $at, $at, $v0
/* B44D54 802405E4 942278F8 */  lhu       $v0, 0x78f8($at)
/* B44D58 802405E8 30420040 */  andi      $v0, $v0, 0x40
/* B44D5C 802405EC 10400002 */  beqz      $v0, .L802405F8
/* B44D60 802405F0 24020001 */   addiu    $v0, $zero, 1
/* B44D64 802405F4 AE020084 */  sw        $v0, 0x84($s0)
.L802405F8:
/* B44D68 802405F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* B44D6C 802405FC 8FB00010 */  lw        $s0, 0x10($sp)
/* B44D70 80240600 24020002 */  addiu     $v0, $zero, 2
/* B44D74 80240604 03E00008 */  jr        $ra
/* B44D78 80240608 27BD0018 */   addiu    $sp, $sp, 0x18
/* B44D7C 8024060C 00000000 */  nop       
